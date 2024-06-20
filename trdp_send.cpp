#include "trdp_send.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QDebug>

#include <iostream>


/***********************************************************************************************************************
* DEFINITIONS
*/
#define APP_VERSION     "1.4"

#define DATA_MAX        1432u

#define PD_COMID        0u
//#define PD_COMID_CYCLE  1000000u             /* in us (1000000 = 1 sec) */

/* We use dynamic memory    */
#define RESERVED_MEMORY  160000u





/* Print a sensible usage message */
void sendusage(const char *appName)
{
    printf("Usage of %s\n", appName);
    printf("This tool receives PD messages from an ED.\n"
        "Arguments are:\n"
        "-o <own IP address> (default: default interface)\n"
        "-m <multicast group IP> (default: none)\n"
        "-c <comId> (default 0)\n"
        "-v print version and quit\n"
    );
}
quint32 trdp_send::IPV4StringToInteger(const QString& ip){
    QStringList ips = ip.split(".");
    if(ips.size() == 4){
        return ips.at(3).toInt()
                | ips.at(2).toInt() << 8
                | ips.at(1).toInt() << 16
                | ips.at(0).toInt() << 24;
    }
    return 0;
}
trdp_send::trdp_send()
{
    sendseq = 0;
    udpSocket = new QUdpSocket(this);



}
trdp_send::~trdp_send()//释放占用的端口 释放trdp
{

}

void trdp_send::startRun()
{
    qDebug()<<"startRun";
    start();
}
void trdp_send::stopRun()
{
    qDebug()<<"stopRun";

    quit();
    qDebug()<<excelid<<" recv stopRun:"<<m_bRun;
}
//set data
void trdp_send::setSendData(QStringList datalist)
{
    datavallist2 = datalist;
    qDebug()<<"datalist.size():"<<datalist.size() ;
}

void trdp_send::setParseVec(QVector<QString>byteoffsettmp,QVector<QString>datatypetmp,QVector<QString>bitoffsettmp,QVector<QString>attributetmp)
{
    datavalvec.clear();
    datavallist2.clear();

    byteoffset.clear();
    datatype.clear();
    bitoffset.clear();
    attribute.clear();

    //qDebug()<<"datavalvec.size():"<<byteoffsettmp.size() ;
    //qDebug()<<"datavalvec.size():"<<datatypetmp.size() ;
    byteoffset =  byteoffsettmp;
    datatype =  datatypetmp;
    bitoffset = bitoffsettmp;
    attribute = attributetmp;
    qDebug()<<"datavalvec.size():"<<byteoffset.size() ;
    qDebug()<<"byteoffset.size():"<<byteoffset.size() ;
    qDebug()<<"bitoffset.size():"<<bitoffset.size() ;

    if(byteoffset.size() != bitoffset.size() || byteoffset.size() != datatype.size() || bitoffset.size() == 0 || byteoffset.size() == 0  || datatype.size() == 0)
    {
        emit senderrorSignal(dstipst,portst,11);
        return;
    }
    datavalvec.resize(byteoffset.size());
    datavallist2.reserve(byteoffset.size());
    //qDebug()<<"datavallist size"<<datavallist.size();

}
void trdp_send::setTRDPParam(QString owniptmp,QString dstiptmp,QString porttmp,QString cycletimetmp)
{
    ownipst = owniptmp;
    dstipst = dstiptmp;
    portst = porttmp;
    cycletimest = cycletimetmp;
    qDebug()<<owniptmp<<" "<<dstiptmp<<" "<<porttmp<<" "<<cycletimetmp;
    ownIP = IPV4StringToInteger(owniptmp);
    dstIP = IPV4StringToInteger(dstiptmp);
    qDebug()<<ownIP<<" "<<dstIP<<" ";
    port = porttmp.toInt();
    cycletime = cycletimetmp.toInt();
}
bool trdp_send::checkbitoffsetstyle(QString&  tmp)
{
    bool result = false;
    if(tmp.size() == 2)
    {
        if(tmp.startsWith("b"))
        {
            if(tmp.right(1).toInt() >=  0 && tmp.right(1).toInt() < 8)
            {
                //qDebug()<<tmp.at(0)<<"  "<<tmp.at(1)<<"  "<<tmp.size();
                //tmp = tmp.right(1);
                result = true;
            }
        }

    }
    return result;
}
//input
//校验和是最后一个数据 ，是两个字节，所以最后两个字节保留
void trdp_send::addsum(unsigned char *sendbuffer, unsigned int size,int checknum)
{
    if(size > 1)
    {
        unsigned short sum = 0;
        for(unsigned int i = 0;i < (size - checknum) ;i++)//0-6
        {
            //qDebug()<< i<< ":"<< *sendbuffer;
            sum = sum + (unsigned short)*sendbuffer;
            sendbuffer++;
        }
        *sendbuffer = sum & 0x00ff;
        sendbuffer++;
        *sendbuffer = (sum & 0xff00) >> 8;
        //qDebug()<<"addsumaddsumaddsumaddsumaddsumaddsumaddsumaddsumaddsum";
        //qDebug()<< excelid<< ":"<< sum;
    }

}
bool trdp_send::prepare_send_data(unsigned char *sendbuffer, unsigned int& sendbuffersize)
{
    /*qDebug()<<"parse_recv, len"<<len;
    qDebug()<<"guzhangwei byte7"<<(uchar)gsendBuffer[7];
    qDebug()<<"guzhangwei byte8"<<(uchar)gsendBuffer[8];//相机雷达 故障
    qDebug()<<"guzhangwei byte9"<<(uchar)gsendBuffer[9];*/
    //qDebug()<<"prepare_send_data";
    bool result = true;
    int  datapos =  0;
    int bitpos = 0;
    memset(sendbuffer, 0, sendbuffersize);
    int reallenth = 0;
    //datavalvec.clear();
    //qDebug()<<"datavalvec.size():"<<datavalvec.size() ;
    //int ;
    if(datavalvec.size() > 0)
    {
        int i = 0;
        for(i = 0;i<datavalvec.size();i++)
        {
            if(datatype[i].toInt()  == 1 || datatype[i].toInt() == 8 || datatype[i].toInt()  == 16 || datatype[i].toInt()  == 32)
            {
                //qDebug()<<"parse_recv000";
                if(byteoffset[i].toInt() >= 0 && byteoffset[i].toInt() < sendbuffersize)
                {
                    //qDebug()<<"parse_recv111";

                    if(datatype[i].toInt() == 8)
                    {
                        //qDebug()<<"parse_recv222";
                        //qDebug()<<byteoffset[i].toInt()<<" "<<datavallist2[i] ;
                        uchar tmp = (uchar)datavallist2[i].toUShort();
                        *sendbuffer = tmp;

                        sendbuffer++;
                        reallenth++;
                        //datavalvec[i] =  datavallist.at;
                        //datavallist.push_back(QString::number(datavalvec[i]));

                    }
                    //ConvertBigEndian2  是否有大小端问题
                    if(datatype[i].toInt() == 16)//大小端  高位在前还是低位在前
                    {
                        //qDebug()<<"parse_recv333";
                        //qDebug()<<byteoffset[i].toInt()<<" "<<datavallist2[i] ;
                        //big endin 默认高在前 低在后
                        /*{
                        uint tmp = (uint)datavallist2[i].toUInt();
                        *sendbuffer  = (uchar)((tmp & 0xff00) >> 8);
                        sendbuffer++;
                        reallenth++;
                        *sendbuffer  = (uchar)(tmp & 0x00ff);
                        sendbuffer++;
                        reallenth++;
                        }*/

                        //little endin 低在前 高在后
                        {
                            uint tmp = (uint)datavallist2[i].toUInt();
                            //qDebug()<<"tmp "<<tmp;
                            *sendbuffer  = (uchar)(tmp & 0x00ff);
                            //qDebug()<<*sendbuffer;
                            sendbuffer++;
                            reallenth++;

                            *sendbuffer  = (uchar)((tmp & 0xff00) >> 8);
                            //qDebug()<<*sendbuffer;
                            sendbuffer++;
                            reallenth++;


                        }

                    }
                    if(datatype[i].toInt() == 32)//大小端  高位在前还是低位在前  默认高在前 低在后
                    {
                        //big endin 默认高在前 低在后
                        /*{
                        uint tmp = (uint)datavallist2[i].toUInt();
                        *sendbuffer  = (uchar)((tmp & 0xff000000) >> 24);
                        sendbuffer++;
                        reallenth++;
                        *sendbuffer  = (uchar)((tmp & 0x00ff0000) >> 16);
                        sendbuffer++;
                        reallenth++;
                        *sendbuffer  = (uchar)((tmp & 0xff00) >> 8);
                        sendbuffer++;
                        reallenth++;
                        *sendbuffer  = (uchar)(tmp & 0xff);
                        sendbuffer++;
                        reallenth++;
                        }*/
                        //little endin 低在前 高在后
                        {
                            uint tmp = (uint)datavallist2[i].toUInt();

                            *sendbuffer  = (uchar)(tmp & 0xff);
                            sendbuffer++;
                            reallenth++;

                            *sendbuffer  = (uchar)((tmp & 0xff00) >> 8);
                            sendbuffer++;
                            reallenth++;

                            *sendbuffer  = (uchar)((tmp & 0x00ff0000) >> 16);
                            sendbuffer++;
                            reallenth++;

                            *sendbuffer  = (uchar)((tmp & 0xff000000) >> 24);
                            sendbuffer++;
                            reallenth++;
                        }

                    }
                    if(datatype[i].toInt() ==  1)
                    {

                        if(!checkbitoffsetstyle(bitoffset[i]))
                        {
                            emit senderrorSignal(dstipst,portst,15);
                            sendbuffersize = 0;
                            result = false;
                            break;
                        }
                        else
                        {
                            if(datavallist2[i].toUInt() == 0 || datavallist2[i].toUInt() == 1)
                            {
                                if(bitoffset[i].right(1).toInt() == 0)
                                {
                                    uchar tmp = datavallist2[i].toUInt() << bitoffset[i].right(1).toInt();//1 to 0x02
                                    *sendbuffer = *sendbuffer | tmp;
                                    sendbuffer++;
                                    reallenth++;
                                }
                                else
                                {
                                    uchar tmp = datavallist2[i].toUInt() << bitoffset[i].right(1).toInt();//1 to 0x02
                                    *sendbuffer = *sendbuffer | tmp;
                                }

                            }
                            else
                            {
                                emit senderrorSignal(dstipst,portst,16);
                            }

                        }
                    }
                }
                else
                {
                    emit senderrorSignal(dstipst,portst,14);
                    sendbuffersize = 0;
                    result = false;
                    break;
                }

            }
            else
            {
                emit senderrorSignal(dstipst,portst,14);
                sendbuffersize = 0;
                result = false;
                break;
            }
        }
        qDebug()<<"size "<< i << "  "<<datavalvec.size()<<" "<<reallenth <<" "<<datavallist2.size();
        if(i == datavalvec.size() && datavalvec.size() == datavallist2.size())
        {

            sendseq++;
            qDebug()<<"goto send seq"<<sendseq;
            sendbuffersize = reallenth;
            //emit  refreshTabwidgetSignal(datavallist);
            //printf  debug
        }
        else
        {
            sendbuffersize = 0;
            result = false;
        }
    }
    else
    {
        sendbuffersize = 0;
        result = false;
    }

    return result;
}
void trdp_send::checkdataAndSend(unsigned char*outputBuffer, unsigned int outputBufferSize,int step)
{

    //addsum
    if(attribute.last() == "A")
    {
        addsum(outputBuffer, outputBufferSize,2);
    }

    //printf send data .每10个数据打印一行
    for(int i = 0;i < step;i++)//0 1 2
    {
        printf("send HEX:   %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx\n",
            (uchar)outputBuffer[i*10+0],(uchar)outputBuffer[i*10+1], (uchar)outputBuffer[i*10+2], (uchar)outputBuffer[i*10+3],(uchar)outputBuffer[i*10+4],
            (uchar)outputBuffer[i*10+5], (uchar)outputBuffer[i*10+6], (uchar)outputBuffer[i*10+7], (uchar)outputBuffer[i*10+8],(uchar)outputBuffer[i*10+9]);


    }
    //printf send data .10组数据以外的数
    for(int k = 0;k < (outputBufferSize % 10);k++)//0 1 2
    {
        printf("send HEX:   %02hhx\n",(uchar)outputBuffer[step*10+k]);

    }

    const char* ch12 = reinterpret_cast<const char*>(outputBuffer);
    //dstIP is  quint32 type;
    this->udpSocket->writeDatagram(ch12, outputBufferSize,QHostAddress(dstIP), port);
}


void trdp_send::run()
{
    //printf("start run\n");
    qDebug()<<"start run";

    unsigned char                   *outputBuffer;
    unsigned char                   exampleData[DATA_MAX]   = "Hello World";
    unsigned int                  outputBufferSize        = 1432u;


    int ch;

    outputBuffer = exampleData;

    if (dstIP == 0)
    {
        fprintf(stderr, "No destination address given!\n");
        //usage(sendusage[0]);
        return;
    }

    qDebug()<<"init no err,to receive while";
    /*
       Enter the main processing loop.
     */

    while (m_bRun && cycletime)//cycletime = 0 ,break while;cycletime > 0, 循环发
    { 
        prepare_send_data(outputBuffer,outputBufferSize);
        //std::cout<<outputBuffer[0]<<std::endl;


        unsigned int step = outputBufferSize / 10; //36 : 36/10 = 3;100/10=10
        printf("%02hhx\n",(uchar)outputBuffer[0]);
        //printf("aaaa %d\n",outputBufferSize);
        //printf("bbbb %d\n",step);
        if(outputBufferSize > 0 ) //checksum
        {
            checkdataAndSend(outputBuffer,outputBufferSize,step);


        }

        usleep(cycletime);
    }
    //
    if(cycletime == 0)//cycletime = 0代表只发一次，不循环发
    {
        prepare_send_data(outputBuffer,outputBufferSize);
        unsigned int step = outputBufferSize / 10; //36 : 36/10 = 3;100/10=10
        printf("%02hhx\n",(uchar)outputBuffer[0]);
        printf("aaaa %d\n",outputBufferSize);
        //printf("bbbb %d\n",step);
        if(outputBufferSize > 0)
        {
            checkdataAndSend(outputBuffer,outputBufferSize,step);

        }
    }

    //m_bRun = false;
    qDebug()<<"end run";
    //stopRun();
    //return;
}

