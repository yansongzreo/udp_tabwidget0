#include "trdp_recv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QDebug>
#include <QDateTime>
#include <iostream>

char gBuffer[1000];

quint32 IPV4StringToInteger(const QString& ip){
    QStringList ips = ip.split(".");
    if(ips.size() == 4){
        return ips.at(3).toInt()
                | ips.at(2).toInt() << 8
                | ips.at(1).toInt() << 16
                | ips.at(0).toInt() << 24;
    }
    return 0;
}
trdp_recv::trdp_recv()//设置IP 设置comid 设置组播地址 trdp初始化
{
    //专门给心跳准备的。如果不是心跳可以根据实际情况更改。在这里状态上传 705所0024H消息可以定义成心跳消息
    //705所0025H消息可以定义成周期消息，它有一个开关，控制消息里面有一个开关，开关打开就开始上报，开关关闭就不上报
    udpSocket = new QUdpSocket(this);
    sizeLen = 0;
    heartbeatcount = 0;
    heartbeatcountpre = 0;
    heartbeatcheck_timer = new QTimer(this);
    connect(heartbeatcheck_timer, SIGNAL(timeout()), this, SLOT(doHeartbeatcheckSlot()));
}

trdp_recv::~trdp_recv()//释放占用的端口 释放trdp
{

}

void trdp_recv::startRun()
{
    qDebug()<<"startRun";

    start();
}
void trdp_recv::stopRun()
{
    heartbeatcheck_timer->stop();

    quit();
    qDebug()<<excelid<<" recv stopRun:"<<m_bRun;

    for(int i = 0;i<datavallist.size();i++)
    {
        datavallist[i] = "";
    }
    emit  refreshTabwidgetSignal(datavallist,excelid);
}
//心跳丢失问题，如果心跳丢失报错；在mainwindow中把心跳丢失故障自行处理
//周期状态丢失，报错；在mainwindow中把周期状态丢失故障自行处理
void trdp_recv::doHeartbeatcheckSlot()
{
    if(heartbeatcountpre == heartbeatcount)
    {
        qDebug()<<"have heartbeaterror";
        emit heartbeatErrorSignal(excelid,1);
    }
    heartbeatcountpre = heartbeatcount;
}
void trdp_recv::setParseVec(QVector<QString>byteoffsettmp,QVector<QString>datatypetmp,QVector<QString>bitoffsettmp,QVector<QString>attributetmp)
{
    datavalvec.clear();//重新设置数据，原先数据清0
    datavallist.clear();//重新设置数据，原先数据清0

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
    //qDebug()<<"datavalvec.size():"<<byteoffset.size() ;
    //qDebug()<<"datavalvec.size():"<<byteoffset.size() ;
    if(byteoffset.size() != bitoffset.size() || byteoffset.size() != datatype.size() || bitoffset.size() == 0 || byteoffset.size() == 0  || datatype.size() == 0)
    {
        emit connUpperSignal(dstipst,excelid,11);
        return;
    }
    datavalvec.resize(byteoffset.size());
    datavallist.reserve(byteoffset.size());
    //qDebug()<<"datavallist size"<<datavallist.size();

}
void trdp_recv::setTRDPParam(QString owniptmp,QString dstiptmp,QString porttmp,QString cycletimetmp)
{
    ownipst = owniptmp;
    dstipst = dstiptmp;
    portst = porttmp;
    cycletimest = cycletimetmp;
    qDebug()<<owniptmp<<" "<<dstiptmp<<" "<<portst<<" "<<cycletimetmp;
    ownIP = IPV4StringToInteger(owniptmp);
    dstIP = IPV4StringToInteger(dstiptmp);
    qDebug()<<ownIP<<" "<<dstIP<<" ";
    listenport = portst.toInt();
    cycletime = cycletimetmp.toInt();
    heartbeatcheck_timer->setInterval(cycletime/1000*5);//setInterval 单位是ms;心跳检测在5个定时周期检测一次，5个周期没变化就报错
    heartbeatcheck_timer->start();//开始接收数据，并开始检测心跳是否丢失
    //有了port 才知道监听哪个端口  setudp
    udpSocket->bind(QHostAddress(ownIP),listenport);//绑定IP地址和端口号
    connect(udpSocket, &QIODevice::readyRead,this, &trdp_recv::processPendingDatagrams);


}
void trdp_recv::processPendingDatagrams()
{
    //只管收
    mutex.lock();
    while (udpSocket->hasPendingDatagrams())
    {
        sizeLen = udpSocket->pendingDatagramSize();
        heartbeatcount++;
        datagram.resize(sizeLen);
        udpSocket->readDatagram(datagram.data(),datagram.size());

        qDebug()<<sizeLen;
        qDebug()<<datagram;
        qDebug()<<"processPendingDatagrams; heartbeatcount "<<heartbeatcount;
        //processDatagram(datagram.data(),sizeLen);
    }
    mutex.unlock();

}
bool trdp_recv::checkbitoffsetstyle(QString&  tmp)
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
bool trdp_recv::parse_recv(int len)
{
    /*qDebug()<<"parse_recv, len"<<len;
    qDebug()<<"guzhangwei byte7"<<(uchar)gBuffer[7];
    qDebug()<<"guzhangwei byte8"<<(uchar)gBuffer[8];//相机雷达 故障
    qDebug()<<"guzhangwei byte9"<<(uchar)gBuffer[9];*/
    bool result = true;
    int  datapos =  0;
    int bitpos = 0;
    //datavalvec.clear();
    //qDebug()<<"datavalvec.size():"<<datavalvec.size() ;
    datavallist.clear();
    for(int i = 0;i<datavalvec.size();i++)
    {
    datavalvec[i] = 0;
    }
    if(datavalvec.size() > 0)
    {
        int i = 0;
        for(i = 0;i<datavalvec.size();i++)
        {
            if(datatype[i].toInt()  == 1 || datatype[i].toInt() == 8 || datatype[i].toInt()  == 16 || datatype[i].toInt()  == 32)
            {
                //qDebug()<<"parse_recv000";
                if(byteoffset[i].toInt() >= 0 && byteoffset[i].toInt() < len)
                {
                    //qDebug()<<"parse_recv111";

                    if(datatype[i].toInt() == 8)
                    {
                        //qDebug()<<"parse_recv222";
                        datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()];
                        datavallist.push_back(QString::number(datavalvec[i]));
                        //qDebug()<<byteoffset[i].toInt()<<" "<<datavalvec[i] ;
                    }
                    //ConvertBigEndian2  是否有大小端问题
                    if(datatype[i].toInt() == 16)//大小端  高位在前还是低位在前  默认高在前 低在后
                    {
                        //qDebug()<<"parse_recv222";
                        //大端：高在前：
                        /*{
                            datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()]*256 + (uchar)gBuffer[byteoffset[i].toUInt()+1];//大小端：默认高位在前？？
                        }*/

                        //小端：低在前：
                        {
                            datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()] + (uchar)gBuffer[byteoffset[i].toUInt()+1]*256;//大小端：默认高位在前？？
                        }

                        datavallist.push_back(QString::number(datavalvec[i]));
                        //qDebug()<<byteoffset[i].toInt()<<" "<<datavalvec[i] ;
                    }
                    if(datatype[i].toInt() == 32)//大小端  高位在前还是低位在前     默认高在前 低在后
                    {
                        //qDebug()<<"parse_recv222";
                        //大端：高在前：
                        /*{
                        datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()]*256*256*256 + (uchar)gBuffer[byteoffset[i].toUInt()+1]*256*256  + (uchar)gBuffer[byteoffset[i].toUInt()+2]*256 + (uchar)gBuffer[byteoffset[i].toUInt()+3];//大小端：默认高位在前？？
                        datavallist.push_back(QString::number(datavalvec[i]));
                        }*/
                        //小端：低在前：
                        {
                        datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()] + (uchar)gBuffer[byteoffset[i].toUInt()+1]*256  + (uchar)gBuffer[byteoffset[i].toUInt()+2]*256*256 + (uchar)gBuffer[byteoffset[i].toUInt()+3]*256*256*256;//大小端：默认高位在前？？
                        datavallist.push_back(QString::number(datavalvec[i]));
                        }
                        //qDebug()<<byteoffset[i].toInt()<<" "<<datavalvec[i] ;
                    }
                    if(datatype[i].toInt() ==  1)
                    {
                        if(!checkbitoffsetstyle(bitoffset[i]))
                        {
                            emit connUpperSignal(dstipst,excelid,15);
                            result = false;
                            break;
                        }
                        else
                        {
                            datavalvec[i] = (((uchar)gBuffer[byteoffset[i].toUInt()] >> bitoffset[i].right(1).toInt()) & 1) ;
                            datavallist.push_back(QString::number(datavalvec[i]));
                            //qDebug()<<datavalvec[i]<< " "<<bitoffset[i]<<" "<<byteoffset[i];
                        }
                    }
                }
                else
                {
                    emit connUpperSignal(dstipst,excelid,14);
                    result = false;
                    break;
                }


            }
            else
            {
                emit connUpperSignal(dstipst,excelid,14);
                result = false;
                break;
            }
        }
        qDebug()<<"size "<< i << "  "<<datavalvec.size();
        if(i == datavalvec.size() && datavalvec.size() == datavallist.size())
        {
            //heartbeatcount =  (uchar)datavallist[0].toUInt()*256*256*256 + (uchar)datavallist[1].toUInt()*256*256 + (uchar)datavallist[2].toUInt()*256 + (uchar)datavallist[3].toUInt();
            qDebug()<<"refreshTabwidgetSlot; heartbeatcount "<<heartbeatcount;
            if(checkRecvdataAdd(gBuffer,datavalvec,sizeLen))//校验和ok  刷新界面
            {
                emit  refreshTabwidgetSignal(datavallist,excelid);
            }
            else//校验fail  推送日志
            {
                qDebug()<<"checkRecvdataAdd error";
                emit heartbeatErrorSignal(excelid,2);
            }

        }
    }
    else
    {
        result =false;
    }
    return result;
}
//input
//校验和是最后一个数据 ，是两个字节，所以最后两个字节保留
//打印结果是-1，答案解析char 类型占一个字节的空间，因此 unsigned char 的取值范围是 0~255，signed char 的取值范围则是 -128~127。十进制的 255 即二进制的 11111111，signed char 第一位为符号位，因此其值转换为十进制后是 -1。
int trdp_recv::addsum(unsigned char *sendbuffer, unsigned int size,int checknum)
{
    unsigned int realbufsum = 0;
    if(size > 1)
    {
        unsigned int sum = 0;
        for(unsigned int i = 0;i < (size - checknum) ;i++)//0-6
        {
            //qDebug()<< i<< ":"<< *sendbuffer;
            printf("%d:recv HEX:   %02hhx\n", i,(uchar)*sendbuffer);
            unsigned int temp = (unsigned int)*sendbuffer;
            sum = sum + temp;
            printf("%d:recv ,HEX:   %02hhx,temp:%d,sum: %d\n", i,(uchar)*sendbuffer,temp,sum);
            sendbuffer++;
        }
        realbufsum = sum;

    }
    qDebug()<< "addsum:"<< realbufsum;
    return realbufsum;

}
//buffer 接收到的纯字符，从udp获取的; size buffer的长度
//recvint 处理完的，给人看填到表格里的数据  //校验的是和
bool trdp_recv::checkRecvdataAdd(unsigned char* buffer,QVector<uint>recvint,int size)
{

    //addsum
    bool checkresult = false;
    int lastdata = 0;
    if(attribute.last() == "A")
    {
        lastdata = recvint.last();

        int realalldaysum = addsum(buffer, size,2);
        qDebug()<<"checkRecvdataAdd"<<lastdata<<" "<<realalldaysum;
        if(realalldaysum  == lastdata)
        {
            checkresult = true;
            qDebug()<<"checkRecvdatacheckRecvdata okokokokok";
        }
    }
    return checkresult;

}
//校验的是帧头，检查的是前4个字节，对象是前3个对象
bool trdp_recv::checkRecvdataHead(unsigned char* buffer,QVector<uint>recvint,int len)
{

    bool result0 = false;
    bool result1 = false;
    bool result2 = false;
    bool result3 = false;

    memcpy(&datafromudp,buffer, sizeof(HeadCheck_RECV2));
    datafromudp.len = (datafromudp.len & 0xff00 >> 8 ) + (datafromudp.len & 0x00ff << 8 );
    if(datavalvec.size() > 0)
    {
        qDebug()<<"0: "<<attribute[0] << (int)datafromudp.head1 << headcheck_send_int[0];
        qDebug()<<"1: "<<attribute[1] << (int)datafromudp.head2 << headcheck_send_int[1];
        qDebug()<<"2: "<<attribute[2] << (int)datafromudp.cmd << headcheck_send_int[2];
        qDebug()<<"3: "<<attribute[3] << (int)datafromudp.len << headcheck_send_int[3];
        if(attribute[0] == "H" && (((int)datafromudp.head1) == headcheck_send_int[0]))
        {
            result0 = true;
        }
        if(attribute[1] == "H" && (((int)datafromudp.head2) == headcheck_send_int[1]))
        {
            result1 = true;
        }
        if(attribute[2] == "H" && (((int)datafromudp.cmd) == headcheck_send_int[2]))
        {
            result2 = true;
        }
        if(attribute[3] == "H" && (((int)datafromudp.len) == headcheck_send_int[3]))
        {
            result3 = true;
        }
    }
//qDebug()<<result0<<" "<<result1<<" "<<result2<<" "<<result3;
    return result0&result1&result2&result3;

}

void trdp_recv::run()
{
    //printf("start run\n");
    qDebug()<<"start run";

    printf("excelid :%d\n", excelid);
    printf("dstIP :%d\n", dstIP);
    printf("ownIP :%d\n", ownIP);
    /*    Open a session  */

    qDebug()<<"start recv whilie";
    while (m_bRun)
    {
        qDebug()<<" recv while,config head:" << headcheck_send_int[0] << " "<<headcheck_send_int[1]<<" "<<headcheck_send_int[2]<<" "<<headcheck_send_int[3];
        qDebug()<<" recv while,size:" << sizeLen;
        sleep(1);
         mutex.lock();
         gBuffer = (unsigned char*)datagram.data();
         if(gBuffer != NULL && sizeLen > 0) //checksum
         {

             //校验帧头
             if(checkRecvdataHead(gBuffer,datavalvec,sizeLen))//校验和ok  刷新界面
             {
                 //emit  refreshTabwidgetSignal(datavallist,excelid);
                 qDebug()<<"checkRecvdataHead error:may be not my head";
                 int step = sizeLen / 10;
                 for(int i = 0;i<step;i++)//0 1 2
                 {
                     printf("recv HEX:   %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx\n",
                         (uchar)gBuffer[i*10+0],(uchar)gBuffer[i*10+1], (uchar)gBuffer[i*10+2], (uchar)gBuffer[i*10+3],(uchar)gBuffer[i*10+4],
                         (uchar)gBuffer[i*10+5], (uchar)gBuffer[i*10+6], (uchar)gBuffer[i*10+7], (uchar)gBuffer[i*10+8],(uchar)gBuffer[i*10+9]);


                 }
                 for(int k = 0;k < (sizeLen % 10);k++)//0 1 2
                 {
                     printf("recv HEX:   %02hhx\n",(uchar)gBuffer[step*10+k]);

                 }


                 parse_recv(sizeLen);
             }
             else
             {
                 qDebug()<<"checkRecvdataHead error:may be not my head";
             }



         }
       mutex.unlock();



    }

    /*
    *    We always clean up behind us!
    */
    printf("end trdp recv0\n");

    return;
}
