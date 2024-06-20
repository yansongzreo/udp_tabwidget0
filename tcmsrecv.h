#ifndef TCMSRECV_H
#define TCMSRECV_H
#include <QObject>

class tcmsrecv:public QObject
{
    Q_OBJECT
public:
    static tcmsrecv *instance();
    explicit tcmsrecv(QObject *parent = 0);
    ~tcmsrecv();

    //bool IsConn();
public slots:
    void recvProc();
/*signals:
    void recvHostSignal(BYTE *pRecvbuf, DWORD buflen);
    void disconnSignal(int);
    void connSignal(int);
    void connectedSignal(int);

private slots:
    void readdataSlot();
    void connectedSlot();
    void disconnectedSlot();


public slots:
    void conntoFuncSlot(QString strip,int port);
    void disconnFuncSlot();
    void send2FuncSlot(BYTE *pSendbuf,DWORD sendlen);

private:
    //QTcpSocket *m_pSkt;
    //ConnState m_connState;

    int m_sktType;
    int m_iNo;*/
};
#endif // TCMSRECV_H
