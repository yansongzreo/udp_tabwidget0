#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <iostream>
#include <vector>
#include <QLabel>
#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDir>
#include <QDebug>


#include <iostream>
using namespace std;

// [0] include QXlsx headers
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string sFielPath = "config.ini";
    tCConfigOperator.SetFilePath(sFielPath);
    string sEroor = "";

    tCConfigOperator.GetConfigAllName( confignamelist,sEroor);



    /*headcolnum  headrownum  byteoffset_col datatype_col bitoffset_col ���պͷ���һ��*/
    headcolnum = 0;
    headrownum = 2;

    byteoffset_col = 0;//��0��
    datatype_col = 2;//��2��
    bitoffset_col = 1;//��1��
    data_attribute_col = 3;//��3��

  

    //m_qTableWidget = new QTableWidget;
    //QWidget *widget = new QWidget();

    initrtrdpUI();

}

void MainWindow::getkey_val(HeadCheck_RECV& head,string configname)
{
    string sEroor = "";
    string sName = "";
    string sValue = "";
    string key = "head1";
    tCConfigOperator.GetConfigValue(configname, key, sValue, sEroor);
    head.head1 = (unsigned char)atoi(sValue.c_str());

    key = "head2";
    tCConfigOperator.GetConfigValue(configname, key, sValue, sEroor);
    head.head2 = (unsigned char)atoi(sValue.c_str());

    key = "cmd";
    tCConfigOperator.GetConfigValue(configname, key, sValue, sEroor);
    head.cmd = (unsigned short)atoi(sValue.c_str());

    key = "len";
    tCConfigOperator.GetConfigValue(configname, key, sValue, sEroor);
    head.len = (unsigned short)atoi(sValue.c_str());

    //cout<< "getkey_val:"<<head.head1<<" "<<head.head2<<" "<<head.cmd<<" "<< head.len<<endl;

    //return sValue;
}
void MainWindow::convert_structhead_to_intvec(HeadCheck_RECV &headcheck,QVector<int>& headcheck_int)
{
    headcheck_int.push_back((int)headcheck.head1);
    headcheck_int.push_back((int)headcheck.head2);
    headcheck_int.push_back((int)headcheck.cmd);
    headcheck_int.push_back((int)headcheck.len);
    qDebug()<<"convert_structhead_to_intvec "<<headcheck_int[0]<<" "<<headcheck_int[1]<<" "<<headcheck_int[2]<<" "<<headcheck_int[3];
}
void MainWindow::initrtrdpUI()
{
   //connect(this, SIGNAL(connUpperSignal(QString,QString,int)),this, SLOT(conntoFuncSlot(QString,QString,int)));//�ռ� ������־
   this->setWindowTitle("door-controller");

   occ_recv_0_statusHeart  = new MyExcelWidget();
   occ_recv_0_statusHeart->xlsxFileName = "occ_recv_0_statusHeart.xlsx";
   occ_recv_0_statusHeart->sendflag = false;
   occ_recv_0_statusHeart->excelid = 0;//0 �� "occ_recv_0"һ��
   getkey_val(occ_recv_0_statusHeart->headcheck_main,"occ_recv_0_statusHeart");
   convert_structhead_to_intvec(occ_recv_0_statusHeart->headcheck_main,occ_recv_0_statusHeart->headcheck_main_int);


   occ_send_1_startendCtl = new MyExcelWidget();
   occ_send_1_startendCtl->xlsxFileName = "occ_send_1_startendCtl.xlsx";
   occ_send_1_startendCtl->sendflag = true;
   occ_send_1_startendCtl->excelid = 1;//1 �� "occ_send_1"һ��
   getkey_val(occ_send_1_startendCtl->headcheck_main,"occ_send_1_startendCtl");
convert_structhead_to_intvec(occ_send_1_startendCtl->headcheck_main,occ_send_1_startendCtl->headcheck_main_int);

   //��ʼ�����
   occ_send_2_doorCtl = new MyExcelWidget();
   occ_send_2_doorCtl->xlsxFileName = "occ_send_2_doorCtl.xlsx";
   occ_send_2_doorCtl->sendflag = true;
   occ_send_2_doorCtl->excelid = 2;//1 �� "occ_send_2"һ��
   getkey_val(occ_send_2_doorCtl->headcheck_main,"occ_send_2_doorCtl");
  convert_structhead_to_intvec(occ_send_2_doorCtl->headcheck_main,occ_send_2_doorCtl->headcheck_main_int);

   occ_recv_3_doorparam  = new MyExcelWidget();
   occ_recv_3_doorparam->xlsxFileName = "occ_recv_3_doorparam.xlsx";
   occ_recv_3_doorparam->sendflag = false;
   occ_recv_3_doorparam->excelid = 3;//0 �� "occ_recv_0"һ��
   getkey_val(occ_recv_3_doorparam->headcheck_main,"occ_recv_3_doorparam");
    convert_structhead_to_intvec(occ_recv_3_doorparam->headcheck_main,occ_recv_3_doorparam->headcheck_main_int);

   occ_send_4_cylinderPosCtl = new MyExcelWidget();
   occ_send_4_cylinderPosCtl->xlsxFileName = "occ_send_4_cylinderPosCtl.xlsx";
   occ_send_4_cylinderPosCtl->sendflag = true;
   occ_send_4_cylinderPosCtl->excelid = 4;//1 �� "occ_send_1"һ��
   getkey_val(occ_send_4_cylinderPosCtl->headcheck_main,"occ_send_4_cylinderPosCtl");
   convert_structhead_to_intvec(occ_send_4_cylinderPosCtl->headcheck_main,occ_send_4_cylinderPosCtl->headcheck_main_int);

   occ_send_5_errorClear = new MyExcelWidget();
   occ_send_5_errorClear->xlsxFileName = "occ_send_5_errorClear.xlsx";
   occ_send_5_errorClear->sendflag = true;
   occ_send_5_errorClear->excelid = 5;//1 �� "occ_send_1"һ��
   getkey_val(occ_send_5_errorClear->headcheck_main,"occ_send_5_errorClear");
   convert_structhead_to_intvec(occ_send_5_errorClear->headcheck_main,occ_send_5_errorClear->headcheck_main_int);

   init_excel_UI(occ_recv_0_statusHeart);
   init_excel_UI(occ_send_1_startendCtl);
   init_excel_UI(occ_send_2_doorCtl);
   init_excel_UI(occ_recv_3_doorparam);
   init_excel_UI(occ_send_4_cylinderPosCtl);
   init_excel_UI(occ_send_5_errorClear);

    initrtrdpswitchUI();

    centralWidget()->setLayout(hcentrallayout00);
}
/*b0-7�źϸ�,����������*/
bool MainWindow::checkbitoffsetstyle(QString&  tmp)
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

void MainWindow::init_excel_UI(MyExcelWidget* excelwidget)
{
    // load new xlsx using new document
    // get xlsx file name
   //QString xlsxFileName = "occ-startend-ctl.xlsx";
    qDebug() << excelwidget->xlsxFileName;

    // tried to load xlsx using temporary document
    QXlsx::Document xlsxTmp( excelwidget->xlsxFileName );
    if ( !xlsxTmp.isLoadPackage() )
    {
        qDebug() << "Failed to load" << excelwidget->xlsxFileName;
        //return (-1); // failed to load
    }
    QXlsx::Document xlsxDoc( excelwidget->xlsxFileName );
    xlsxDoc.isLoadPackage();

    int sheetIndexNumber = 0;
    int maxRow = -1;
    int maxCol = -1;
    //QVector< QVector<QString> > cellValues;

    foreach( QString curretnSheetName, xlsxDoc.sheetNames())
    {
        QXlsx::AbstractSheet* currentSheet = xlsxDoc.sheet( curretnSheetName );
        if ( NULL == currentSheet )
            continue;

        // get full cells of sheet

        currentSheet->workbook()->setActiveSheet( sheetIndexNumber );
        Worksheet* wsheet = (Worksheet*) currentSheet->workbook()->activeSheet();
        if ( NULL == wsheet )
            continue;

        QString strSheetName = wsheet->sheetName(); // sheet name

        // display sheet name
        std::cout
                << std::string( strSheetName.toLocal8Bit() )
                << std::endl;

        QVector<CellLocation> clList = wsheet->getFullCells( &maxRow, &maxCol );


        for (int rc = 0; rc < maxRow; rc++)
        {
            QVector<QString> tempValue;
            for (int cc = 0; cc < maxCol; cc++)
            {
                tempValue.push_back(QString(""));
            }
            excelwidget->cellValues_recv.push_back(tempValue);
        }

        for ( int ic = 0; ic < clList.size(); ++ic )
         {
            // cell location
            CellLocation cl = clList.at(ic);

            int row = cl.row - 1;
            int col = cl.col - 1;

            QSharedPointer<Cell> ptrCell = cl.cell; // cell pointer

            // value of cell
            QVariant var = cl.cell.data()->value();
            QString str = var.toString();

            excelwidget->cellValues_recv[row][col] = str;
        }

        //fort::table fortTable;



        //std::cout << fortTable.to_string() << std::endl; // display forttable row

        sheetIndexNumber++;
    }

    std::cout <<"maxRow,maxCol"<< maxRow<<" "<<maxCol<< std::endl;
    excelwidget->hlayout0 = new QHBoxLayout;

    excelwidget->hlayout1 = new QHBoxLayout;
    excelwidget->hlayout2 = new QHBoxLayout;

    if(excelwidget->sendflag)
    {
        excelwidget->m_trdp_send = new trdp_send();
        excelwidget->m_trdp_send->excelid = excelwidget->excelid;

       //memcpy(&excelwidget->m_trdp_send->head_struct, &excelwidget->headcheck_main, sizeof(HeadCheck_RECV));
       excelwidget->m_trdp_send->headcheck_send_int = excelwidget->headcheck_main_int;
    }
    else
    {
        excelwidget->m_trdp_recv = new trdp_recv();
        excelwidget->m_trdp_recv->excelid = excelwidget->excelid;
        // memcpy(&excelwidget->m_trdp_recv->head_struct, &excelwidget->headcheck_main, sizeof(HeadCheck_RECV));
        excelwidget->m_trdp_recv->headcheck_send_int = excelwidget->headcheck_main_int;

        connect(excelwidget->m_trdp_recv, SIGNAL(heartbeatErrorSignal(int,int)),this, SLOT(onheartbeatErrorSlot(int,int)));//�ռ� ������־
        connect(excelwidget->m_trdp_recv, SIGNAL(refreshTabwidgetSignal(QStringList,int)),this, SLOT(refreshTabwidgetSlot(QStringList,int)));//ˢ��recv excel


    }

    //init hlayout0  ownip dstip comid cycletime
    excelwidget->owniplb = new QLabel("ownip:");
    excelwidget->dstiplb = new QLabel("dstip:");
    excelwidget->portlb = new QLabel("port:");
    excelwidget->cycletimelb = new QLabel("cycletime(us):");



    excelwidget->ownipedit = new QLineEdit("192.168.100.201");
    excelwidget->dstipedit = new QLineEdit("192.168.100.202");
    excelwidget->portedit = new QLineEdit("7000");
    excelwidget->cycletimeedit = new QLineEdit("1000000");

    excelwidget->hlayout0->addWidget(excelwidget->owniplb);
    excelwidget->hlayout0->addWidget(excelwidget->ownipedit);

    excelwidget->hlayout0->addWidget(excelwidget->dstiplb);
    excelwidget->hlayout0->addWidget(excelwidget->dstipedit);

    excelwidget->hlayout0->addWidget(excelwidget->portlb);
    excelwidget->hlayout0->addWidget(excelwidget->portedit);

    excelwidget->hlayout0->addWidget(excelwidget->cycletimelb);
    excelwidget->hlayout0->addWidget(excelwidget->cycletimeedit);

    //init hlayout1  m_qTableWidget ����һ��TableWidget�����������
    excelwidget->m_qTableWidget = new QTableWidget;
    excelwidget->hlayout1->addWidget(excelwidget->m_qTableWidget);
    excelwidget->m_qTableWidget->setRowCount(maxRow);
    excelwidget->m_qTableWidget->setColumnCount(maxCol+1);

    //QStringList header;
    //header << "����" << "��ֵ";
    //m_qTableWidget->setHorizontalHeaderLabels(header);
    for (int rc = 0; rc < maxRow; rc++)//���п�ʼ
    {
        std::cout <<"��n�У�"<< rc << std::endl; // display forttable row
        for (int cc = 0; cc < maxCol; cc++)//���п�ʼ
        {
            QString strTemp = excelwidget->cellValues_recv[rc][cc];
           QTableWidgetItem *newtabtmp = new QTableWidgetItem(excelwidget->cellValues_recv[rc][cc]);
            excelwidget->m_qTableWidget->setItem(rc, cc, newtabtmp);
            excelwidget->m_qTableWidget->resizeRowToContents(rc);

            if(rc >= headrownum && cc >= headcolnum)//��2�� ��0�� ��ʼ
            {

                if(cc == byteoffset_col)//�ֽ�ƫ�Ʒǿ�
                {

                    if(excelwidget->cellValues_recv[rc][cc] ==  "")
                    {
                        errmsg.setWindowTitle(tr("excel�����⣺"));
                        errmsg.setText(tr("�ֽ�ƫ����һ��������Ϊ��"));
                        errmsg.show();
                    }
                    excelwidget->byteoffset.push_back(excelwidget->cellValues_recv[rc][cc]);//����Ϊ �� �����Ǵ�
                }
                if(cc == datatype_col)//���ݴ�С�ǿ�
                {
                    if(excelwidget->cellValues_recv[rc][cc] ==  "")
                    {
                        qDebug()<<excelwidget->excelid <<" rc "<<rc<<" cc"<<cc;
                        errmsg.setWindowTitle(tr("Э��excel������:"));
                        errmsg.setText(tr("���ݴ�С��һ��������Ϊ��"));
                        errmsg.show();
                    }

                    excelwidget->datatype.push_back(excelwidget->cellValues_recv[rc][cc]);
                }
                if(cc == bitoffset_col)//λƫ�ƿ��Կգ�����Ҫ����b0-7
                {   if(excelwidget->cellValues_recv[rc][cc] !=  "")
                    {
                        if(!checkbitoffsetstyle(excelwidget->cellValues_recv[rc][cc]))
                        {
                            errmsg.setWindowTitle(tr("Э��excel������:"));
                            errmsg.setText(tr("λƫ����һ�в�����b0-b7�ĸ�ʽ"));
                            errmsg.show();
                        }
                    }

                    excelwidget->bitoffset.push_back(excelwidget->cellValues_recv[rc][cc]);
                }
                if(cc == data_attribute_col)//�������ʿ��Կգ�����Ҫ����b0-7
                {   if(excelwidget->cellValues_recv[rc][cc] ==  "")
                    {
                        errmsg.setWindowTitle(tr("Э��excel������:"));
                        errmsg.setText(QString::number(excelwidget->excelid) + tr(":�������ʸ�ʽ������"));

                        errmsg.show();
                    }

                    excelwidget->data_attribute.push_back(excelwidget->cellValues_recv[rc][cc]);
                }
            }
            //fortTable << std::string( strTemp.toLocal8Bit() ); // display value
        }
        //fortTable << fort::endr; // change to new row
    }
    //qDebug()<<" byteoffset2:"<<byteoffset2.size()<<"  datatype2:"<<datatype2.size() <<" bitoffset2:"<<bitoffset2.size();

    excelwidget->m_qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //m_qTableWidget->verticalHeader()->setVisible(false);//������ߴ�ֱ

    //init hlayout2  m_qStartPushButton m_qStopPushButton
    excelwidget->m_qStartPushButton = new QPushButton(tr("��ʼ"));
    excelwidget->m_qStartPushButton->setStyleSheet("background-color: rgb(0, 255, 127);");
   //m_trdp_recv = tcmsrecv::instance();
    connect(excelwidget->m_qStartPushButton, SIGNAL(clicked()), this, SLOT(recvProcstart()));

    excelwidget->m_qStopPushButton = new QPushButton(tr("ֹͣ"));
    excelwidget->m_qStopPushButton->setStyleSheet("background-color: rgb(200, 80, 80);");
    connect(excelwidget->m_qStopPushButton, SIGNAL(clicked()), this, SLOT(recvProcstop()));

    excelwidget->hlayout2->addWidget(excelwidget->m_qStartPushButton);
    excelwidget->hlayout2->addWidget(excelwidget->m_qStopPushButton);

    //init trdprecv1 trdprecvlayout
    excelwidget->trdprecvlayout = new QGridLayout;//vlayout
    excelwidget->trdprecvlayout->addLayout(excelwidget->hlayout0, 0, 0);
    excelwidget->trdprecvlayout->addLayout(excelwidget->hlayout1, 1, 0);
    excelwidget->trdprecvlayout->addLayout(excelwidget->hlayout2, 2, 0);



    if(excelwidget->sendflag) //���ͳ�ʼ�����������ļ���ȡ ����ʼ���������Լ���
    {
        for (int rc = 0; rc < maxRow; rc++)
         {
             if(rc >= headrownum)//��2�� ��0�� ��ʼ
             {   
                 if(excelwidget->data_attribute[rc - headrownum] == "H")
                 {
                     excelwidget->datavallist.push_back(QString::number(excelwidget->headcheck_main_int[rc - headrownum]));//���ʹ��� �����ȳ�ʼ��Ϊ0
                 }
                 else
                 {
                     excelwidget->datavallist.push_back(QString::number(0));//���ʹ��� �����ȳ�ʼ��Ϊ0
                 }

             }

         }

         connect(this, SIGNAL(refreshTabwidgetSignal2(QStringList,int)),this, SLOT(refreshTabwidgetSlot2(QStringList,int)));//�����ȳ�ʼ��Ϊ0����ˢ�µ���ͬ�ķ��ʹ���
         emit refreshTabwidgetSignal2(excelwidget->datavallist,excelwidget->excelid);


        connect(excelwidget->m_qTableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(changecellSlot(int,int)));//ok
    }

}



//errid = 1������ʧ���⣬���������ʧ������mainwindow�а�������ʧ�������д���
//errid = 1��״̬��ʧ��������mainwindow�а�����״̬��ʧ�������д���
//errid = 2 ��������Э��У��ʧ��(֡ͷʧ�ܻ���֡βУ��ʧ��)
//excel_0  0/1/2��Ӧ���Ǳ��
void MainWindow::onheartbeatErrorSlot(int excelid,int errid)
{
    if(errid == 1)
    {
        errmsg.setWindowTitle(tr("705-�ŷ����⣺"));
        errmsg.setText( "excel_"+QString::number(excelid,10) + tr(":������ʧ��״̬������ʧ"));
        errmsg.show();
    }
    if(errid == 2)
    {
        errmsg.setWindowTitle(tr("705-�ŷ����⣺"));
        errmsg.setText( "excel_"+QString::number(excelid,10) + tr(":У���������֡ͷ��֡β"));
        errmsg.show();
    }
}

//only for recv_excel;ʵʱˢ�½���
void MainWindow::refreshTabwidgetSlot(QStringList datavallst,int excelid)
{
    qDebug()<<"00000000000000000refreshTabwidgetSlot1111111111111111111111";
    //���ձ������������
    if(excelid == occ_recv_0_statusHeart->excelid)
    {
        for (int i = 0; i < datavallst.size(); i++)
        {
            //std::cout <<"��n�У�"<< rc << std::endl; // display forttable row
            //for (int cc = 0; cc < 100; cc++)
            {
                QString strTemp ;
                if(occ_recv_0_statusHeart->m_trdp_recv->m_bRun == false)
                {
                    strTemp  = "";
                }
                else
                {
                    strTemp = datavallst[i];
                }
                //QString strTemp = datavallst[i];

                int  coltmp  =  occ_recv_0_statusHeart->m_qTableWidget->columnCount() -  1;
                occ_recv_0_statusHeart->m_qTableWidget->setItem(i + headrownum, coltmp, new QTableWidgetItem(strTemp));

                //fortTable << std::string( strTemp.toLocal8Bit() ); // display value
            }
            //fortTable << fort::endr; // change to new row
        }
    }
    if(excelid == occ_recv_3_doorparam->excelid)
    {
        for (int i = 0; i < datavallst.size(); i++)
        {
            //std::cout <<"��n�У�"<< rc << std::endl; // display forttable row
            //for (int cc = 0; cc < 100; cc++)
            {
                QString strTemp ;
                if(occ_recv_3_doorparam->m_trdp_recv->m_bRun == false)
                {
                    strTemp  = "";
                }
                else
                {
                    strTemp = datavallst[i];
                }
                //QString strTemp = datavallst[i];

                int  coltmp  =  occ_recv_3_doorparam->m_qTableWidget->columnCount() -  1;
                occ_recv_3_doorparam->m_qTableWidget->setItem(i + headrownum, coltmp, new QTableWidgetItem(strTemp));

                //fortTable << std::string( strTemp.toLocal8Bit() ); // display value
            }
            //fortTable << fort::endr; // change to new row
        }
    }

}
//only for send_excel;�ֶ�ˢ�·��ʹ���,��ʼ����ʱ����
 void MainWindow::refreshTabwidgetSlot2(QStringList datavallst,int excelid)
{
    qDebug()<<"refreshTabwidgetSlot2";
    //���ͱ������������
    if(excelid == occ_send_1_startendCtl->excelid)
    {
        for (int i = 0; i < datavallst.size(); i++)
        {

            {
                QString strTemp = datavallst[i];

                int  coltmp  =  occ_send_1_startendCtl->m_qTableWidget->columnCount() -  1;
                occ_send_1_startendCtl->m_qTableWidget->setItem(i + headrownum, coltmp, new QTableWidgetItem(strTemp));

            }
            //fortTable << fort::endr; // change to new row
        }
    }
    if(excelid == occ_send_2_doorCtl->excelid)
    {
        for (int i = 0; i < datavallst.size(); i++)
        {

            {
                QString strTemp = datavallst[i];

                int  coltmp  =  occ_send_2_doorCtl->m_qTableWidget->columnCount() -  1;
                occ_send_2_doorCtl->m_qTableWidget->setItem(i + headrownum, coltmp, new QTableWidgetItem(strTemp));

            }
            //fortTable << fort::endr; // change to new row
        }
    }
    if(excelid == occ_send_4_cylinderPosCtl->excelid)
    {
        for (int i = 0; i < datavallst.size(); i++)
        {

            {
                QString strTemp = datavallst[i];

                int  coltmp  =  occ_send_4_cylinderPosCtl->m_qTableWidget->columnCount() -  1;
                occ_send_4_cylinderPosCtl->m_qTableWidget->setItem(i + headrownum, coltmp, new QTableWidgetItem(strTemp));

            }
            //fortTable << fort::endr; // change to new row
        }
    }
    if(excelid == occ_send_5_errorClear->excelid)
    {
        for (int i = 0; i < datavallst.size(); i++)
        {

            {
                QString strTemp = datavallst[i];

                int  coltmp  =  occ_send_5_errorClear->m_qTableWidget->columnCount() -  1;
                occ_send_5_errorClear->m_qTableWidget->setItem(i + headrownum, coltmp, new QTableWidgetItem(strTemp));

            }
            //fortTable << fort::endr; // change to new row
        }
    }

}
/*trdp ʧ��*/
 /*excel ����������������һ�µ�����*/
/*void MainWindow::conntoFuncSlot(QString strip, QString comid,int errid)
{
    qDebug()<<strip<<comid<<" "<<errid;
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 1)//1-9 TRDP error
    {


        errmsg.setWindowTitle(tr("TRDP FAIL"));
        errmsg.setText(tr("udp-serv Init FAIL"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text() && errid == 1)
    {

        errmsg.setWindowTitle(tr("TRDP FAIL"));
        errmsg.setText(tr("udp-occ Init FAIL"));
        errmsg.show();
    }
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 11)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-serv Э������"));
        errmsg.setText(tr("����ƫ�ƻ���������������bitƫ����������"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 11)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-occ Э������"));
        errmsg.setText(tr("����ƫ�ƻ���������������bitƫ����������"));
        errmsg.show();
    }

    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 12)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-serv Э��excel�����⣺"));
        errmsg.setText(tr("�ֽ�ƫ����һ��������Ϊ��"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 12)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-occ Э��excel������"));
        errmsg.setText(tr("�ֽ�ƫ����һ��������Ϊ��"));
        errmsg.show();
    }

    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 13)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-serv Э��excel�����⣺"));
        errmsg.setText(tr("���ݴ�С��һ��������Ϊ��"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 13)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-occ Э��excel������"));
        errmsg.setText(tr("���ݴ�С��һ��������Ϊ��"));
        errmsg.show();
    }
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 14)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-serv Э��excel�����⣺"));
        errmsg.setText(tr("���ݴ�С�в���1/8/16/32�ֽ�"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 14)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-occ Э��excel������"));
        errmsg.setText(tr("���ݴ�С�в���1/8/16/32�ֽ� "));
        errmsg.show();
    }
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 15)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-serv Э��excel�����⣺"));
        errmsg.setText(tr("bitλƫ�Ʋ�����b0-b7��ʽ"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 15)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-occ Э��excel������"));
        errmsg.setText(tr("bitλƫ�Ʋ�����b0-b7��ʽ"));
        errmsg.show();
    }
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 16)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-serv ���һ�������⣺"));
        errmsg.setText(tr("��������"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 16)//11-19Э��error
    {
        errmsg.setWindowTitle(tr("udp-occ ���һ�������⣺"));
        errmsg.setText(tr("����"));
        errmsg.show();
    }
}*/

void MainWindow::initrtrdpswitchUI()
{

    //tabWidget_2 ����tab21 tab22
    //tabfatherwidget = new QWidget(this);
    //widget->setLayout(vlayout);
    tabWidget_2 = new QTabWidget(this);
    tabWidget_2->setTabsClosable(true);
    tabWidget_2->setMovable(true);

    tab21 = new QWidget();
    tab21->setObjectName(QStringLiteral("tab21"));
    tab21->setLayout(occ_recv_0_statusHeart->trdprecvlayout);
    //tabWidget_2->addTab(tab21, QString());
    tabWidget_2->insertTab(0, tab21,QString());
    //send_id��recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab21), QApplication::translate("MainWindow", "recv_0", 0));

    tab22 = new QWidget();
    tab22->setObjectName(QStringLiteral("tab22"));
    tab22->setLayout(occ_send_1_startendCtl->trdprecvlayout);
    //tabWidget_2->addTab(tab22, QString());
    tabWidget_2->insertTab(1, tab22,QString());
    //send_id��recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab22), QApplication::translate("MainWindow", "send_1", 0));

    //���UI
    tab23 = new QWidget();
    tab23->setObjectName(QStringLiteral("tab23"));
    tab23->setLayout(occ_send_2_doorCtl->trdprecvlayout);

    tabWidget_2->insertTab(2, tab23,QString());//2 ��occ_send_2_doorCtl��idһ��
    //send_id��recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab23), QApplication::translate("MainWindow", "send_2", 0));//2 ��occ_send_2_doorCtl��idһ��

    tab24 = new QWidget();
    tab24->setObjectName(QStringLiteral("tab24"));
    tab24->setLayout(occ_recv_3_doorparam->trdprecvlayout);
    tabWidget_2->insertTab(3, tab24,QString());
    //send_id��recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab24), QApplication::translate("MainWindow", "recv_3", 0));

    tab25 = new QWidget();
    tab25->setObjectName(QStringLiteral("tab25"));
    tab25->setLayout(occ_send_4_cylinderPosCtl->trdprecvlayout);
    tabWidget_2->insertTab(4, tab25,QString());
    //send_id��recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab25), QApplication::translate("MainWindow", "send_4", 0));

    tab26 = new QWidget();
    tab26->setObjectName(QStringLiteral("tab26"));
    tab26->setLayout(occ_send_5_errorClear->trdprecvlayout);
    tabWidget_2->insertTab(5, tab26,QString());
    //send_id��recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab26), QApplication::translate("MainWindow", "send_5", 0));


     qDebug()<<tabWidget_2->size()<<tabWidget_2->currentIndex();
    //��centralWidget  ���� centrallayout��centrallayout ���� tabWidget_2
    hcentrallayout00 = new QHBoxLayout;
    hcentrallayout00->addWidget(tabWidget_2);

     //qDebug()<<"trdp1 or trdp2:"<<tabWidget_2->currentIndex();
    /*m_pVLayout2       = new QVBoxLayout(this);
    m_pVLayout2->addWidget(m_qTableWidget);
    ui->tab21->setLayout(m_pVLayout2);
    ui->tab22->setLayout(m_pVLayout2);*/
}
/*void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    qDebug()<<"trdp1 or trdp2:"<<index;
    switch (index) {

    case 1:
       // tab21->setDisabled(true);
        tabWidget_2->setTabEnabled(0,false);
        break;
    }
}*/
void  MainWindow::changecellSlot(int rowseq, int columnseq)
{
    qDebug()<<"change tab222222 "<<rowseq<<" "<<columnseq;
    //�����Լ����ı����� tabWidget_2->currentIndex() =  occ_send_1_startendCtl = send id
    //һ���Ƿ��ͱ��������������
    if(tabWidget_2->currentIndex() == 1)//��ǰ��ǩҳid��1 ��ʾ������idΪ1�ı��
    {
        if(columnseq == (occ_send_1_startendCtl->m_qTableWidget-> columnCount() -  1))//�Ƿ������һ��
        {
            if(rowseq >= headrownum)
            {
                occ_send_1_startendCtl->datavallist[rowseq - headrownum] = occ_send_1_startendCtl->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_1_startendCtl->m_trdp_send->setSendData(occ_send_1_startendCtl->datavallist);
            }
        }
    }
    //���ͱ�񡣲��ҵ�ǰҳ�Ƿ��ͣ����˲����������
    if(tabWidget_2->currentIndex() == 2)//��ǰ��ǩҳid��2 ��ʾ������idΪ2�ı��
    {
        if(columnseq == (occ_send_2_doorCtl->m_qTableWidget-> columnCount() -  1))//�Ƿ������һ��
        {
            if(rowseq >= headrownum)
            {
                occ_send_2_doorCtl->datavallist[rowseq - headrownum] = occ_send_2_doorCtl->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_2_doorCtl->m_trdp_send->setSendData(occ_send_2_doorCtl->datavallist);
            }
        }
    }

    if(tabWidget_2->currentIndex() == 4)//��ǰ��ǩҳid��1 ��ʾ������idΪ1�ı��
    {
        if(columnseq == (occ_send_4_cylinderPosCtl->m_qTableWidget-> columnCount() -  1))//�Ƿ������һ��
        {
            if(rowseq >= headrownum)
            {
                occ_send_4_cylinderPosCtl->datavallist[rowseq - headrownum] = occ_send_4_cylinderPosCtl->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_4_cylinderPosCtl->m_trdp_send->setSendData(occ_send_4_cylinderPosCtl->datavallist);
            }
        }
    }
    if(tabWidget_2->currentIndex() == 5)//��ǰ��ǩҳid��1 ��ʾ������idΪ1�ı��
    {
        if(columnseq == (occ_send_5_errorClear->m_qTableWidget-> columnCount() -  1))//�Ƿ������һ��
        {
            if(rowseq >= headrownum)
            {
                occ_send_5_errorClear->datavallist[rowseq - headrownum] = occ_send_5_errorClear->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_5_errorClear->m_trdp_send->setSendData(occ_send_5_errorClear->datavallist);
            }
        }
    }
    //�������ķ��ͱ�� ���� tabWidget_2->currentIndex()  �ҵ�occ_send_id  (currentIndex �� id��Ӧ)

}
void MainWindow::recvProcstart()
{

    //setParam(QString ownip,QString dstip,QString comid,QString cycletime)
    if(tabWidget_2->currentIndex() == 0)//�����Լ����ı�����
    {
        qDebug()<<"set udp-recv";
        occ_recv_0_statusHeart->m_qStartPushButton->setDisabled(true);

        occ_recv_0_statusHeart->m_trdp_recv->setTRDPParam(occ_recv_0_statusHeart->ownipedit->text(),occ_recv_0_statusHeart->dstipedit->text(),occ_recv_0_statusHeart->portedit->text(),occ_recv_0_statusHeart->cycletimeedit->text());
        occ_recv_0_statusHeart->m_trdp_recv->setParseVec(occ_recv_0_statusHeart->byteoffset,occ_recv_0_statusHeart->datatype,occ_recv_0_statusHeart->bitoffset,occ_recv_0_statusHeart->data_attribute);
        occ_recv_0_statusHeart->m_trdp_recv->setRun(true);//��λ��ĳ��EXCEL/���� ��ʼ����
        occ_recv_0_statusHeart->m_trdp_recv->startRun();
    }
    if(tabWidget_2->currentIndex() == 1)
    {
        qDebug()<<"set udp-send";
        occ_send_1_startendCtl->m_qStartPushButton->setDisabled(true);
        occ_send_1_startendCtl->m_trdp_send->setTRDPParam(occ_send_1_startendCtl->ownipedit->text(),occ_send_1_startendCtl->dstipedit->text(),occ_send_1_startendCtl->portedit->text(),occ_send_1_startendCtl->cycletimeedit->text());

        occ_send_1_startendCtl->m_trdp_send->setParseVec(occ_send_1_startendCtl->byteoffset,occ_send_1_startendCtl->datatype,occ_send_1_startendCtl->bitoffset,occ_send_1_startendCtl->data_attribute);
        occ_send_1_startendCtl->m_trdp_send->setSendData(occ_send_1_startendCtl->datavallist);
        occ_send_1_startendCtl->m_trdp_send->setRun(true);//��λ��ĳ��EXCEL/���� ��ʼ����
        occ_send_1_startendCtl->m_trdp_send->startRun();
    }
    if(tabWidget_2->currentIndex() == 2)
    {
        qDebug()<<"set udp-send";
        occ_send_2_doorCtl->m_qStartPushButton->setDisabled(true);
        occ_send_2_doorCtl->m_trdp_send->setTRDPParam(occ_send_2_doorCtl->ownipedit->text(),occ_send_2_doorCtl->dstipedit->text(),occ_send_2_doorCtl->portedit->text(),occ_send_2_doorCtl->cycletimeedit->text());

        occ_send_2_doorCtl->m_trdp_send->setParseVec(occ_send_2_doorCtl->byteoffset,occ_send_2_doorCtl->datatype,occ_send_2_doorCtl->bitoffset,occ_send_2_doorCtl->data_attribute);
        occ_send_2_doorCtl->m_trdp_send->setSendData(occ_send_2_doorCtl->datavallist);
        occ_send_2_doorCtl->m_trdp_send->setRun(true);//��λ��ĳ��EXCEL/���� ��ʼ����
        occ_send_2_doorCtl->m_trdp_send->startRun();
    }
    if(tabWidget_2->currentIndex() == 3)//�����Լ����ı�����
    {
        qDebug()<<"set udp-recv";
        occ_recv_3_doorparam->m_qStartPushButton->setDisabled(true);

        occ_recv_3_doorparam->m_trdp_recv->setTRDPParam(occ_recv_3_doorparam->ownipedit->text(),occ_recv_3_doorparam->dstipedit->text(),occ_recv_3_doorparam->portedit->text(),occ_recv_3_doorparam->cycletimeedit->text());
        occ_recv_3_doorparam->m_trdp_recv->setParseVec(occ_recv_3_doorparam->byteoffset,occ_recv_3_doorparam->datatype,occ_recv_3_doorparam->bitoffset,occ_recv_3_doorparam->data_attribute);
        occ_recv_3_doorparam->m_trdp_recv->setRun(true);//��λ��ĳ��EXCEL/���� ��ʼ����
        occ_recv_3_doorparam->m_trdp_recv->startRun();
    }

    if(tabWidget_2->currentIndex() == 4)
    {
        qDebug()<<"set udp-send";
        occ_send_4_cylinderPosCtl->m_qStartPushButton->setDisabled(true);
        occ_send_4_cylinderPosCtl->m_trdp_send->setTRDPParam(occ_send_4_cylinderPosCtl->ownipedit->text(),occ_send_4_cylinderPosCtl->dstipedit->text(),occ_send_4_cylinderPosCtl->portedit->text(),occ_send_4_cylinderPosCtl->cycletimeedit->text());

        occ_send_4_cylinderPosCtl->m_trdp_send->setParseVec(occ_send_4_cylinderPosCtl->byteoffset,occ_send_4_cylinderPosCtl->datatype,occ_send_4_cylinderPosCtl->bitoffset,occ_send_4_cylinderPosCtl->data_attribute);
        occ_send_4_cylinderPosCtl->m_trdp_send->setSendData(occ_send_4_cylinderPosCtl->datavallist);
        occ_send_4_cylinderPosCtl->m_trdp_send->setRun(true);//��λ��ĳ��EXCEL/���� ��ʼ����
        occ_send_4_cylinderPosCtl->m_trdp_send->startRun();
    }
    if(tabWidget_2->currentIndex() == 5)
    {
        qDebug()<<"set udp-send";
        occ_send_5_errorClear->m_qStartPushButton->setDisabled(true);
        occ_send_5_errorClear->m_trdp_send->setTRDPParam(occ_send_5_errorClear->ownipedit->text(),occ_send_5_errorClear->dstipedit->text(),occ_send_5_errorClear->portedit->text(),occ_send_5_errorClear->cycletimeedit->text());

        occ_send_5_errorClear->m_trdp_send->setParseVec(occ_send_5_errorClear->byteoffset,occ_send_5_errorClear->datatype,occ_send_5_errorClear->bitoffset,occ_send_5_errorClear->data_attribute);
        occ_send_5_errorClear->m_trdp_send->setSendData(occ_send_5_errorClear->datavallist);
        occ_send_5_errorClear->m_trdp_send->setRun(true);//��λ��ĳ��EXCEL/���� ��ʼ����
        occ_send_5_errorClear->m_trdp_send->startRun();
    }

}
void MainWindow::recvProcstop()
{
    if(tabWidget_2->currentIndex() == 0)
    {
        qDebug()<<"recvProcstop index"<<tabWidget_2->currentIndex();
        occ_recv_0_statusHeart->m_qStartPushButton->setDisabled(false);
        occ_recv_0_statusHeart->m_trdp_recv->setRun(false);
        occ_recv_0_statusHeart->m_trdp_recv->stopRun();
    }
    if(tabWidget_2->currentIndex() == 1)
    {
        qDebug()<<"recvProcstop index"<<tabWidget_2->currentIndex();
        occ_send_1_startendCtl->m_qStartPushButton->setDisabled(false);
        occ_send_1_startendCtl->m_trdp_send->setRun(false);
        occ_send_1_startendCtl->m_trdp_send->stopRun();
    }

    if(tabWidget_2->currentIndex() == 2)
    {
        qDebug()<<"recvProcstop index"<<tabWidget_2->currentIndex();
        occ_send_2_doorCtl->m_qStartPushButton->setDisabled(false);
        occ_send_2_doorCtl->m_trdp_send->setRun(false);
        occ_send_2_doorCtl->m_trdp_send->stopRun();
    }
    if(tabWidget_2->currentIndex() == 3)
    {
        qDebug()<<"recvProcstop index"<<tabWidget_2->currentIndex();
        occ_recv_3_doorparam->m_qStartPushButton->setDisabled(false);
        occ_recv_3_doorparam->m_trdp_recv->setRun(false);
        occ_recv_3_doorparam->m_trdp_recv->stopRun();
    }
    if(tabWidget_2->currentIndex() == 4)
    {
        qDebug()<<"recvProcstop index"<<tabWidget_2->currentIndex();
        occ_send_4_cylinderPosCtl->m_qStartPushButton->setDisabled(false);
        occ_send_4_cylinderPosCtl->m_trdp_send->setRun(false);
        occ_send_4_cylinderPosCtl->m_trdp_send->stopRun();
    }
    if(tabWidget_2->currentIndex() == 5)
    {
        qDebug()<<"recvProcstop index"<<tabWidget_2->currentIndex();
        occ_send_5_errorClear->m_qStartPushButton->setDisabled(false);
        occ_send_5_errorClear->m_trdp_send->setRun(false);
        occ_send_5_errorClear->m_trdp_send->stopRun();
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}
