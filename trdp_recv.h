#ifndef TRDP_RECV_H
#define TRDP_RECV_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QTimer>
#include <QUdpSocket>
#include <QMutex>

typedef struct tagHeadCheck2{
unsigned char head1;
unsigned char head2;
unsigned short cmd;
unsigned short len;
}HeadCheck_RECV2;

class trdp_recv : public QThread
{
    Q_OBJECT
public:
    //explicit trdp_recv(QObject *parent = nullptr);
    trdp_recv();
   ~trdp_recv();
    void startRun();
   void stopRun();
    void setRun(bool bflag){m_bRun = bflag;}
    void setTRDPParam(QString,QString,QString,QString);
    void setParseVec(QVector<QString>,QVector<QString>,QVector<QString>,QVector<QString>);
    bool m_bRun;
    int excelid;
    QVector<int> headcheck_send_int;
    //HeadCheck_RECV head_struct;
signals:
    void connUpperSignal(QString strip,int excelid,int errid);
    void refreshTabwidgetSignal(QStringList,int);
    void heartbeatErrorSignal(int,int);

protected:
    void run();

private slots:
    void doHeartbeatcheckSlot();
    void processPendingDatagrams();

private:
    QTimer* heartbeatcheck_timer;

    QString ownipst;
    QString dstipst;
    QString portst;
    QString cycletimest;
    uint          listenport;
    uint  ownIP ;
    uint  dstIP ;
    uint cycletime;
    QVector<QString> byteoffset;
    QVector<QString> datatype;
    QVector<QString> bitoffset;
    QVector<QString> attribute;
    QVector<uint> datavalvec;
    HeadCheck_RECV2 datafromudp;

    QStringList datavallist;
    long heartbeatcount;
    long heartbeatcountpre;
    bool parse_recv(int len);
    bool checkbitoffsetstyle(QString&  tmp);

    QUdpSocket *udpSocket;

    QByteArray datagram;
    QMutex mutex;
    int sizeLen;
    void processDatagram(char * datagram,int len);
    unsigned char* gBuffer;
    int addsum( unsigned char *, unsigned int,int);
    bool checkRecvdataAdd(unsigned char* buffer,QVector<uint>recvint,int size);
    bool checkRecvdataHead(unsigned char* buffer,QVector<uint>recvint,int size);

};


#endif // TRDP_RECV_H
