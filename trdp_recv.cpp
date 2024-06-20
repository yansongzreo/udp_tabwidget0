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
trdp_recv::trdp_recv()//����IP ����comid �����鲥��ַ trdp��ʼ��
{
    //ר�Ÿ�����׼���ġ���������������Ը���ʵ��������ġ�������״̬�ϴ� 705��0024H��Ϣ���Զ����������Ϣ
    //705��0025H��Ϣ���Զ����������Ϣ������һ�����أ�������Ϣ������һ�����أ����ش򿪾Ϳ�ʼ�ϱ������عرվͲ��ϱ�
    udpSocket = new QUdpSocket(this);
    sizeLen = 0;
    heartbeatcount = 0;
    heartbeatcountpre = 0;
    heartbeatcheck_timer = new QTimer(this);
    connect(heartbeatcheck_timer, SIGNAL(timeout()), this, SLOT(doHeartbeatcheckSlot()));
}

trdp_recv::~trdp_recv()//�ͷ�ռ�õĶ˿� �ͷ�trdp
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
//������ʧ���⣬���������ʧ������mainwindow�а�������ʧ�������д���
//����״̬��ʧ��������mainwindow�а�����״̬��ʧ�������д���
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
    datavalvec.clear();//�����������ݣ�ԭ��������0
    datavallist.clear();//�����������ݣ�ԭ��������0

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
    heartbeatcheck_timer->setInterval(cycletime/1000*5);//setInterval ��λ��ms;���������5����ʱ���ڼ��һ�Σ�5������û�仯�ͱ���
    heartbeatcheck_timer->start();//��ʼ�������ݣ�����ʼ��������Ƿ�ʧ
    //����port ��֪�������ĸ��˿�  setudp
    udpSocket->bind(QHostAddress(ownIP),listenport);//��IP��ַ�Ͷ˿ں�
    connect(udpSocket, &QIODevice::readyRead,this, &trdp_recv::processPendingDatagrams);


}
void trdp_recv::processPendingDatagrams()
{
    //ֻ����
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
    qDebug()<<"guzhangwei byte8"<<(uchar)gBuffer[8];//����״� ����
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
                    //ConvertBigEndian2  �Ƿ��д�С������
                    if(datatype[i].toInt() == 16)//��С��  ��λ��ǰ���ǵ�λ��ǰ  Ĭ�ϸ���ǰ ���ں�
                    {
                        //qDebug()<<"parse_recv222";
                        //��ˣ�����ǰ��
                        /*{
                            datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()]*256 + (uchar)gBuffer[byteoffset[i].toUInt()+1];//��С�ˣ�Ĭ�ϸ�λ��ǰ����
                        }*/

                        //С�ˣ�����ǰ��
                        {
                            datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()] + (uchar)gBuffer[byteoffset[i].toUInt()+1]*256;//��С�ˣ�Ĭ�ϸ�λ��ǰ����
                        }

                        datavallist.push_back(QString::number(datavalvec[i]));
                        //qDebug()<<byteoffset[i].toInt()<<" "<<datavalvec[i] ;
                    }
                    if(datatype[i].toInt() == 32)//��С��  ��λ��ǰ���ǵ�λ��ǰ     Ĭ�ϸ���ǰ ���ں�
                    {
                        //qDebug()<<"parse_recv222";
                        //��ˣ�����ǰ��
                        /*{
                        datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()]*256*256*256 + (uchar)gBuffer[byteoffset[i].toUInt()+1]*256*256  + (uchar)gBuffer[byteoffset[i].toUInt()+2]*256 + (uchar)gBuffer[byteoffset[i].toUInt()+3];//��С�ˣ�Ĭ�ϸ�λ��ǰ����
                        datavallist.push_back(QString::number(datavalvec[i]));
                        }*/
                        //С�ˣ�����ǰ��
                        {
                        datavalvec[i] =  (uchar)gBuffer[byteoffset[i].toUInt()] + (uchar)gBuffer[byteoffset[i].toUInt()+1]*256  + (uchar)gBuffer[byteoffset[i].toUInt()+2]*256*256 + (uchar)gBuffer[byteoffset[i].toUInt()+3]*256*256*256;//��С�ˣ�Ĭ�ϸ�λ��ǰ����
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
            if(checkRecvdataAdd(gBuffer,datavalvec,sizeLen))//У���ok  ˢ�½���
            {
                emit  refreshTabwidgetSignal(datavallist,excelid);
            }
            else//У��fail  ������־
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
//У��������һ������ ���������ֽڣ�������������ֽڱ���
//��ӡ�����-1���𰸽���char ����ռһ���ֽڵĿռ䣬��� unsigned char ��ȡֵ��Χ�� 0~255��signed char ��ȡֵ��Χ���� -128~127��ʮ���Ƶ� 255 �������Ƶ� 11111111��signed char ��һλΪ����λ�������ֵת��Ϊʮ���ƺ��� -1��
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
//buffer ���յ��Ĵ��ַ�����udp��ȡ��; size buffer�ĳ���
//recvint ������ģ����˿������������  //У����Ǻ�
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
//У�����֡ͷ��������ǰ4���ֽڣ�������ǰ3������
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

             //У��֡ͷ
             if(checkRecvdataHead(gBuffer,datavalvec,sizeLen))//У���ok  ˢ�½���
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
