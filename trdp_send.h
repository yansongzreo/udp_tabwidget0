#ifndef TRDP_SEND_H
#define TRDP_SEND_H
#include <QObject>
#include <QThread>
#include <QVector>
#include <QUdpSocket>
typedef struct tagHeadCheck_send{
unsigned char head1;
unsigned char head2;
unsigned short cmd;
unsigned short len;
}HeadCheck_SEND;
class trdp_send : public QThread
{
    Q_OBJECT
public:
    trdp_send();
    ~trdp_send();
     void startRun();
    void stopRun();
     void setRun(bool bflag){m_bRun = bflag;}
     void setTRDPParam(QString,QString,QString,QString);
     void setParseVec(QVector<QString>,QVector<QString>,QVector<QString>,QVector<QString>);

     void setSendData(QStringList);//发送数据变化（数据值变化）更新这个QStringList
     int excelid;
     QVector<int> headcheck_send_int;

 signals:
     void senderrorSignal(QString strip,QString port,int errid);
     //void sendconnUpperSignal(QString strip,QString port,int errid);
     //void refreshTabwidgetSignal(QStringList);
 protected:
     void run();

 public slots:
     //void recvProc();
 private:
     bool m_bRun;
     QString ownipst;
     QString dstipst;
     QString portst;
     QString cycletimest;
     uint          port;
     uint  ownIP ;
     uint  dstIP ;
     uint cycletime;
     QVector<QString> byteoffset;
     QVector<QString> datatype;
     QVector<QString> bitoffset;
     QVector<QString> attribute;

     QVector<uchar> datavalvec;
     QStringList datavallist2;
     bool prepare_send_data(unsigned char *, unsigned int&);
     //bool parse_recv(int len);
     bool checkbitoffsetstyle(QString&  tmp);
     quint32 IPV4StringToInteger(const QString& ip);
     int sendseq;

     QUdpSocket *udpSocket;
     void addsum(unsigned char *, unsigned int,int);


     void checkdataAndSend(unsigned char*, unsigned int,int);


};

#endif // TRDP_SEND_H
