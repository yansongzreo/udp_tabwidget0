#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QMetaType>
#include "trdp_recv.h"
#include "trdp_send.h"
#include "cfg.h"
#pragma execution_character_set("utf-8")
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class trdp_recv;
class trdp_send;
typedef struct tagHeadCheck{
unsigned char head1;
unsigned char head2;
unsigned short cmd;
unsigned short len;
}HeadCheck_RECV;

class MyExcelWidget : public QObject
{
    Q_OBJECT
public:
    QString xlsxFileName;
    bool sendflag;
    int excelid;


    QVector< QVector<QString> > cellValues_recv;
    QHBoxLayout *hlayout0;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;

    QLabel* owniplb;
    QLabel* dstiplb;
    QLabel* portlb;
    QLabel* cycletimelb;

    QLineEdit* ownipedit;
    QLineEdit* dstipedit;
    QLineEdit* portedit;
    QLineEdit* cycletimeedit;

    QTableWidget *m_qTableWidget;
    QPushButton *m_qStartPushButton;
    QPushButton *m_qStopPushButton;

    QVector<QString> byteoffset;//��0��-�ֽڱ���

    QVector<QString> datatype;//��2��-�������� 8 16 32

    QVector<QString> bitoffset;//��1�� -bit λƫ�ơ�705��λ��Ŀǰû����bitλ����

    QVector<QString> data_attribute;//��3�� ��������  H S F A



    //trdp_recv_1
    QGridLayout *trdprecvlayout;

    trdp_send* m_trdp_send;
    trdp_recv* m_trdp_recv;

  QStringList datavallist;
    HeadCheck_RECV headcheck_main;
    QVector<int> headcheck_main_int;



};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void readExcel(QString path);

    QWidget *tabfatherwidget;
    QTabWidget *tabWidget_2;
    QWidget *tab21; //
    QWidget *tab22;
    QWidget *tab23;//���һ����񴰿�
    QWidget *tab24;//���һ����񴰿�
    QWidget *tab25;//���һ����񴰿�
    QWidget *tab26;//���һ����񴰿�
    //trdp_recv* m_trdp_recv;

    void initrtrdpswitchUI();

    //void init_tids_ccu_UI();
    //void init_occ_1_UI();
    //void init_occ_2_UI();

    void init_excel_UI(MyExcelWidget* excelwidget);

    QHBoxLayout *hcentrallayout00;


      QMessageBox errmsg;

      //QVector< QVector<QString> > cellValues_recv1;
      //QVector< QVector<QString> > cellValues_recv2;
      int headcolnum;//�����水�п� ��ͷ�� ����Щ �� ����Ч ��
      int headrownum;//�����水�п� ��ͷ�� ����Щ �� ����Ч ��
      int byteoffset_col;//��0��

      int datatype_col;//��2��

      int bitoffset_col;

     int data_attribute_col;//��������


      bool checkbitoffsetstyle(QString& tmp);

      void initrtrdpUI();

      MyExcelWidget *occ_recv_0_statusHeart;//
      MyExcelWidget *occ_send_1_startendCtl;//
      MyExcelWidget *occ_send_2_doorCtl;//��excel�������һ��
      MyExcelWidget *occ_recv_3_doorparam;//��excel�������һ��
      MyExcelWidget *occ_send_4_cylinderPosCtl;//��excel�������һ��
      MyExcelWidget *occ_send_5_errorClear;//��excel�������һ��

      CConfigOperator tCConfigOperator;
      vector<string> confignamelist;//
      void getkey_val(HeadCheck_RECV& key,string configname);
      void convert_structhead_to_intvec(HeadCheck_RECV &headcheck,QVector<int>& headcheck_int);
private slots:
    void recvProcstart();
    void recvProcstop();
    //void conntoFuncSlot(QString strip, QString comid,int errid);

    void refreshTabwidgetSlot(QStringList,int); //refreshTabwidgetSlot �� refreshTabwidgetSlot2����refreshTabwidgetSlot  ʵʱˢ��recv
    void refreshTabwidgetSlot2(QStringList,int);//refreshTabwidgetSlot2 �ֶ�ˢ��send ���ڣ���send���ڸ���ֵ
    void onheartbeatErrorSlot(int,int);
    //void on_tab22_clicked();
    //void on_tabWidget_2_currentChanged(int index);
   //void  changeitemSlot();
   void changecellSlot(int,int);
   // on_m_qTableWidget_2_itemSelectionChanged();
    //void on_m_qTableWidget_2_cellChanged(int row, int column);
signals:
    //void connUpperSignal(QString strip,QString port,int errid);
    void refreshTabwidgetSignal2(QStringList,int);

};
#endif // MAINWINDOW_H
