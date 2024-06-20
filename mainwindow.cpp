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



    /*headcolnum  headrownum  byteoffset_col datatype_col bitoffset_col 接收和发送一样*/
    headcolnum = 0;
    headrownum = 2;

    byteoffset_col = 0;//第0列
    datatype_col = 2;//第2列
    bitoffset_col = 1;//第1列
    data_attribute_col = 3;//第3列

  

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
   //connect(this, SIGNAL(connUpperSignal(QString,QString,int)),this, SLOT(conntoFuncSlot(QString,QString,int)));//收集 错误日志
   this->setWindowTitle("door-controller");

   occ_recv_0_statusHeart  = new MyExcelWidget();
   occ_recv_0_statusHeart->xlsxFileName = "occ_recv_0_statusHeart.xlsx";
   occ_recv_0_statusHeart->sendflag = false;
   occ_recv_0_statusHeart->excelid = 0;//0 与 "occ_recv_0"一致
   getkey_val(occ_recv_0_statusHeart->headcheck_main,"occ_recv_0_statusHeart");
   convert_structhead_to_intvec(occ_recv_0_statusHeart->headcheck_main,occ_recv_0_statusHeart->headcheck_main_int);


   occ_send_1_startendCtl = new MyExcelWidget();
   occ_send_1_startendCtl->xlsxFileName = "occ_send_1_startendCtl.xlsx";
   occ_send_1_startendCtl->sendflag = true;
   occ_send_1_startendCtl->excelid = 1;//1 与 "occ_send_1"一致
   getkey_val(occ_send_1_startendCtl->headcheck_main,"occ_send_1_startendCtl");
convert_structhead_to_intvec(occ_send_1_startendCtl->headcheck_main,occ_send_1_startendCtl->headcheck_main_int);

   //初始化表格
   occ_send_2_doorCtl = new MyExcelWidget();
   occ_send_2_doorCtl->xlsxFileName = "occ_send_2_doorCtl.xlsx";
   occ_send_2_doorCtl->sendflag = true;
   occ_send_2_doorCtl->excelid = 2;//1 与 "occ_send_2"一致
   getkey_val(occ_send_2_doorCtl->headcheck_main,"occ_send_2_doorCtl");
  convert_structhead_to_intvec(occ_send_2_doorCtl->headcheck_main,occ_send_2_doorCtl->headcheck_main_int);

   occ_recv_3_doorparam  = new MyExcelWidget();
   occ_recv_3_doorparam->xlsxFileName = "occ_recv_3_doorparam.xlsx";
   occ_recv_3_doorparam->sendflag = false;
   occ_recv_3_doorparam->excelid = 3;//0 与 "occ_recv_0"一致
   getkey_val(occ_recv_3_doorparam->headcheck_main,"occ_recv_3_doorparam");
    convert_structhead_to_intvec(occ_recv_3_doorparam->headcheck_main,occ_recv_3_doorparam->headcheck_main_int);

   occ_send_4_cylinderPosCtl = new MyExcelWidget();
   occ_send_4_cylinderPosCtl->xlsxFileName = "occ_send_4_cylinderPosCtl.xlsx";
   occ_send_4_cylinderPosCtl->sendflag = true;
   occ_send_4_cylinderPosCtl->excelid = 4;//1 与 "occ_send_1"一致
   getkey_val(occ_send_4_cylinderPosCtl->headcheck_main,"occ_send_4_cylinderPosCtl");
   convert_structhead_to_intvec(occ_send_4_cylinderPosCtl->headcheck_main,occ_send_4_cylinderPosCtl->headcheck_main_int);

   occ_send_5_errorClear = new MyExcelWidget();
   occ_send_5_errorClear->xlsxFileName = "occ_send_5_errorClear.xlsx";
   occ_send_5_errorClear->sendflag = true;
   occ_send_5_errorClear->excelid = 5;//1 与 "occ_send_1"一致
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
/*b0-7才合格,其他都不行*/
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

        connect(excelwidget->m_trdp_recv, SIGNAL(heartbeatErrorSignal(int,int)),this, SLOT(onheartbeatErrorSlot(int,int)));//收集 错误日志
        connect(excelwidget->m_trdp_recv, SIGNAL(refreshTabwidgetSignal(QStringList,int)),this, SLOT(refreshTabwidgetSlot(QStringList,int)));//刷新recv excel


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

    //init hlayout1  m_qTableWidget 创建一个TableWidget，并填充内容
    excelwidget->m_qTableWidget = new QTableWidget;
    excelwidget->hlayout1->addWidget(excelwidget->m_qTableWidget);
    excelwidget->m_qTableWidget->setRowCount(maxRow);
    excelwidget->m_qTableWidget->setColumnCount(maxCol+1);

    //QStringList header;
    //header << "参数" << "数值";
    //m_qTableWidget->setHorizontalHeaderLabels(header);
    for (int rc = 0; rc < maxRow; rc++)//从行开始
    {
        std::cout <<"第n行："<< rc << std::endl; // display forttable row
        for (int cc = 0; cc < maxCol; cc++)//从列开始
        {
            QString strTemp = excelwidget->cellValues_recv[rc][cc];
           QTableWidgetItem *newtabtmp = new QTableWidgetItem(excelwidget->cellValues_recv[rc][cc]);
            excelwidget->m_qTableWidget->setItem(rc, cc, newtabtmp);
            excelwidget->m_qTableWidget->resizeRowToContents(rc);

            if(rc >= headrownum && cc >= headcolnum)//第2行 第0列 开始
            {

                if(cc == byteoffset_col)//字节偏移非空
                {

                    if(excelwidget->cellValues_recv[rc][cc] ==  "")
                    {
                        errmsg.setWindowTitle(tr("excel有问题："));
                        errmsg.setText(tr("字节偏移这一列有内容为空"));
                        errmsg.show();
                    }
                    excelwidget->byteoffset.push_back(excelwidget->cellValues_recv[rc][cc]);//可能为 空 可能是错
                }
                if(cc == datatype_col)//数据大小非空
                {
                    if(excelwidget->cellValues_recv[rc][cc] ==  "")
                    {
                        qDebug()<<excelwidget->excelid <<" rc "<<rc<<" cc"<<cc;
                        errmsg.setWindowTitle(tr("协议excel有问题:"));
                        errmsg.setText(tr("数据大小这一列有内容为空"));
                        errmsg.show();
                    }

                    excelwidget->datatype.push_back(excelwidget->cellValues_recv[rc][cc]);
                }
                if(cc == bitoffset_col)//位偏移可以空，但是要满足b0-7
                {   if(excelwidget->cellValues_recv[rc][cc] !=  "")
                    {
                        if(!checkbitoffsetstyle(excelwidget->cellValues_recv[rc][cc]))
                        {
                            errmsg.setWindowTitle(tr("协议excel有问题:"));
                            errmsg.setText(tr("位偏移这一列不满足b0-b7的格式"));
                            errmsg.show();
                        }
                    }

                    excelwidget->bitoffset.push_back(excelwidget->cellValues_recv[rc][cc]);
                }
                if(cc == data_attribute_col)//变量性质可以空，但是要满足b0-7
                {   if(excelwidget->cellValues_recv[rc][cc] ==  "")
                    {
                        errmsg.setWindowTitle(tr("协议excel有问题:"));
                        errmsg.setText(QString::number(excelwidget->excelid) + tr(":变量性质格式有问题"));

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

    //m_qTableWidget->verticalHeader()->setVisible(false);//隐藏左边垂直

    //init hlayout2  m_qStartPushButton m_qStopPushButton
    excelwidget->m_qStartPushButton = new QPushButton(tr("开始"));
    excelwidget->m_qStartPushButton->setStyleSheet("background-color: rgb(0, 255, 127);");
   //m_trdp_recv = tcmsrecv::instance();
    connect(excelwidget->m_qStartPushButton, SIGNAL(clicked()), this, SLOT(recvProcstart()));

    excelwidget->m_qStopPushButton = new QPushButton(tr("停止"));
    excelwidget->m_qStopPushButton->setStyleSheet("background-color: rgb(200, 80, 80);");
    connect(excelwidget->m_qStopPushButton, SIGNAL(clicked()), this, SLOT(recvProcstop()));

    excelwidget->hlayout2->addWidget(excelwidget->m_qStartPushButton);
    excelwidget->hlayout2->addWidget(excelwidget->m_qStopPushButton);

    //init trdprecv1 trdprecvlayout
    excelwidget->trdprecvlayout = new QGridLayout;//vlayout
    excelwidget->trdprecvlayout->addLayout(excelwidget->hlayout0, 0, 0);
    excelwidget->trdprecvlayout->addLayout(excelwidget->hlayout1, 1, 0);
    excelwidget->trdprecvlayout->addLayout(excelwidget->hlayout2, 2, 0);



    if(excelwidget->sendflag) //发送初始化，把配置文件读取 并初始化，其他自己改
    {
        for (int rc = 0; rc < maxRow; rc++)
         {
             if(rc >= headrownum)//第2行 第0列 开始
             {   
                 if(excelwidget->data_attribute[rc - headrownum] == "H")
                 {
                     excelwidget->datavallist.push_back(QString::number(excelwidget->headcheck_main_int[rc - headrownum]));//发送窗口 可以先初始化为0
                 }
                 else
                 {
                     excelwidget->datavallist.push_back(QString::number(0));//发送窗口 可以先初始化为0
                 }

             }

         }

         connect(this, SIGNAL(refreshTabwidgetSignal2(QStringList,int)),this, SLOT(refreshTabwidgetSlot2(QStringList,int)));//可以先初始化为0，并刷新到不同的发送窗口
         emit refreshTabwidgetSignal2(excelwidget->datavallist,excelwidget->excelid);


        connect(excelwidget->m_qTableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(changecellSlot(int,int)));//ok
    }

}



//errid = 1心跳丢失问题，如果心跳丢失报错；在mainwindow中把心跳丢失故障自行处理
//errid = 1期状态丢失，报错；在mainwindow中把周期状态丢失故障自行处理
//errid = 2 接收数据协议校验失败(帧头失败或者帧尾校验失败)
//excel_0  0/1/2对应得是表号
void MainWindow::onheartbeatErrorSlot(int excelid,int errid)
{
    if(errid == 1)
    {
        errmsg.setWindowTitle(tr("705-伺服问题："));
        errmsg.setText( "excel_"+QString::number(excelid,10) + tr(":心跳丢失、状态反馈丢失"));
        errmsg.show();
    }
    if(errid == 2)
    {
        errmsg.setWindowTitle(tr("705-伺服问题："));
        errmsg.setText( "excel_"+QString::number(excelid,10) + tr(":校验出错、请检查帧头和帧尾"));
        errmsg.show();
    }
}

//only for recv_excel;实时刷新接收
void MainWindow::refreshTabwidgetSlot(QStringList datavallst,int excelid)
{
    qDebug()<<"00000000000000000refreshTabwidgetSlot1111111111111111111111";
    //接收表格才有这个功能
    if(excelid == occ_recv_0_statusHeart->excelid)
    {
        for (int i = 0; i < datavallst.size(); i++)
        {
            //std::cout <<"第n行："<< rc << std::endl; // display forttable row
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
            //std::cout <<"第n行："<< rc << std::endl; // display forttable row
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
//only for send_excel;手动刷新发送窗口,初始化的时候用
 void MainWindow::refreshTabwidgetSlot2(QStringList datavallst,int excelid)
{
    qDebug()<<"refreshTabwidgetSlot2";
    //发送表格才有这个功能
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
/*trdp 失败*/
 /*excel 表格与我们软件规则不一致的问题*/
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
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 11)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-serv 协议问题"));
        errmsg.setText(tr("数据偏移或数据类型数量或bit偏移列有问题"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 11)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-occ 协议问题"));
        errmsg.setText(tr("数据偏移或数据类型数量或bit偏移列有问题"));
        errmsg.show();
    }

    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 12)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-serv 协议excel有问题："));
        errmsg.setText(tr("字节偏移这一列有内容为空"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 12)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-occ 协议excel有问题"));
        errmsg.setText(tr("字节偏移这一列有内容为空"));
        errmsg.show();
    }

    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 13)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-serv 协议excel有问题："));
        errmsg.setText(tr("数据大小这一列有内容为空"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 13)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-occ 协议excel有问题"));
        errmsg.setText(tr("数据大小这一列有内容为空"));
        errmsg.show();
    }
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 14)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-serv 协议excel有问题："));
        errmsg.setText(tr("数据大小有不是1/8/16/32字节"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 14)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-occ 协议excel有问题"));
        errmsg.setText(tr("数据大小有不是1/8/16/32字节 "));
        errmsg.show();
    }
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 15)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-serv 协议excel有问题："));
        errmsg.setText(tr("bit位偏移不满足b0-b7格式"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 15)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-occ 协议excel有问题"));
        errmsg.setText(tr("bit位偏移不满足b0-b7格式"));
        errmsg.show();
    }
    if(strip == dstipedit->text() && comid == comidedit->text()  && errid == 16)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-serv 最后一列有问题："));
        errmsg.setText(tr("参数超范"));
        errmsg.show();
    }
    if(strip == dstipedit_2->text() && comid == portedit_2->text()  && errid == 16)//11-19协议error
    {
        errmsg.setWindowTitle(tr("udp-occ 最后一列有问题："));
        errmsg.setText(tr("参数"));
        errmsg.show();
    }
}*/

void MainWindow::initrtrdpswitchUI()
{

    //tabWidget_2 加载tab21 tab22
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
    //send_id、recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab21), QApplication::translate("MainWindow", "recv_0", 0));

    tab22 = new QWidget();
    tab22->setObjectName(QStringLiteral("tab22"));
    tab22->setLayout(occ_send_1_startendCtl->trdprecvlayout);
    //tabWidget_2->addTab(tab22, QString());
    tabWidget_2->insertTab(1, tab22,QString());
    //send_id、recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab22), QApplication::translate("MainWindow", "send_1", 0));

    //添加UI
    tab23 = new QWidget();
    tab23->setObjectName(QStringLiteral("tab23"));
    tab23->setLayout(occ_send_2_doorCtl->trdprecvlayout);

    tabWidget_2->insertTab(2, tab23,QString());//2 与occ_send_2_doorCtl中id一致
    //send_id、recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab23), QApplication::translate("MainWindow", "send_2", 0));//2 与occ_send_2_doorCtl中id一致

    tab24 = new QWidget();
    tab24->setObjectName(QStringLiteral("tab24"));
    tab24->setLayout(occ_recv_3_doorparam->trdprecvlayout);
    tabWidget_2->insertTab(3, tab24,QString());
    //send_id、recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab24), QApplication::translate("MainWindow", "recv_3", 0));

    tab25 = new QWidget();
    tab25->setObjectName(QStringLiteral("tab25"));
    tab25->setLayout(occ_send_4_cylinderPosCtl->trdprecvlayout);
    tabWidget_2->insertTab(4, tab25,QString());
    //send_id、recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab25), QApplication::translate("MainWindow", "send_4", 0));

    tab26 = new QWidget();
    tab26->setObjectName(QStringLiteral("tab26"));
    tab26->setLayout(occ_send_5_errorClear->trdprecvlayout);
    tabWidget_2->insertTab(5, tab26,QString());
    //send_id、recv_id
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab26), QApplication::translate("MainWindow", "send_5", 0));


     qDebug()<<tabWidget_2->size()<<tabWidget_2->currentIndex();
    //把centralWidget  加载 centrallayout，centrallayout 加载 tabWidget_2
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
    //根据自己定的表格而定 tabWidget_2->currentIndex() =  occ_send_1_startendCtl = send id
    //一般是发送表格才有有这个功能
    if(tabWidget_2->currentIndex() == 1)//当前标签页id是1 表示更改了id为1的表格
    {
        if(columnseq == (occ_send_1_startendCtl->m_qTableWidget-> columnCount() -  1))//是否是最后一列
        {
            if(rowseq >= headrownum)
            {
                occ_send_1_startendCtl->datavallist[rowseq - headrownum] = occ_send_1_startendCtl->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_1_startendCtl->m_trdp_send->setSendData(occ_send_1_startendCtl->datavallist);
            }
        }
    }
    //发送表格。并且当前页是发送，改了才有这个功能
    if(tabWidget_2->currentIndex() == 2)//当前标签页id是2 表示更改了id为2的表格
    {
        if(columnseq == (occ_send_2_doorCtl->m_qTableWidget-> columnCount() -  1))//是否是最后一列
        {
            if(rowseq >= headrownum)
            {
                occ_send_2_doorCtl->datavallist[rowseq - headrownum] = occ_send_2_doorCtl->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_2_doorCtl->m_trdp_send->setSendData(occ_send_2_doorCtl->datavallist);
            }
        }
    }

    if(tabWidget_2->currentIndex() == 4)//当前标签页id是1 表示更改了id为1的表格
    {
        if(columnseq == (occ_send_4_cylinderPosCtl->m_qTableWidget-> columnCount() -  1))//是否是最后一列
        {
            if(rowseq >= headrownum)
            {
                occ_send_4_cylinderPosCtl->datavallist[rowseq - headrownum] = occ_send_4_cylinderPosCtl->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_4_cylinderPosCtl->m_trdp_send->setSendData(occ_send_4_cylinderPosCtl->datavallist);
            }
        }
    }
    if(tabWidget_2->currentIndex() == 5)//当前标签页id是1 表示更改了id为1的表格
    {
        if(columnseq == (occ_send_5_errorClear->m_qTableWidget-> columnCount() -  1))//是否是最后一列
        {
            if(rowseq >= headrownum)
            {
                occ_send_5_errorClear->datavallist[rowseq - headrownum] = occ_send_5_errorClear->m_qTableWidget->item(rowseq,columnseq)->text();
                occ_send_5_errorClear->m_trdp_send->setSendData(occ_send_5_errorClear->datavallist);
            }
        }
    }
    //有其他的发送表格 根据 tabWidget_2->currentIndex()  找到occ_send_id  (currentIndex 与 id对应)

}
void MainWindow::recvProcstart()
{

    //setParam(QString ownip,QString dstip,QString comid,QString cycletime)
    if(tabWidget_2->currentIndex() == 0)//根据自己定的表格而定
    {
        qDebug()<<"set udp-recv";
        occ_recv_0_statusHeart->m_qStartPushButton->setDisabled(true);

        occ_recv_0_statusHeart->m_trdp_recv->setTRDPParam(occ_recv_0_statusHeart->ownipedit->text(),occ_recv_0_statusHeart->dstipedit->text(),occ_recv_0_statusHeart->portedit->text(),occ_recv_0_statusHeart->cycletimeedit->text());
        occ_recv_0_statusHeart->m_trdp_recv->setParseVec(occ_recv_0_statusHeart->byteoffset,occ_recv_0_statusHeart->datatype,occ_recv_0_statusHeart->bitoffset,occ_recv_0_statusHeart->data_attribute);
        occ_recv_0_statusHeart->m_trdp_recv->setRun(true);//上位机某个EXCEL/功能 开始接收
        occ_recv_0_statusHeart->m_trdp_recv->startRun();
    }
    if(tabWidget_2->currentIndex() == 1)
    {
        qDebug()<<"set udp-send";
        occ_send_1_startendCtl->m_qStartPushButton->setDisabled(true);
        occ_send_1_startendCtl->m_trdp_send->setTRDPParam(occ_send_1_startendCtl->ownipedit->text(),occ_send_1_startendCtl->dstipedit->text(),occ_send_1_startendCtl->portedit->text(),occ_send_1_startendCtl->cycletimeedit->text());

        occ_send_1_startendCtl->m_trdp_send->setParseVec(occ_send_1_startendCtl->byteoffset,occ_send_1_startendCtl->datatype,occ_send_1_startendCtl->bitoffset,occ_send_1_startendCtl->data_attribute);
        occ_send_1_startendCtl->m_trdp_send->setSendData(occ_send_1_startendCtl->datavallist);
        occ_send_1_startendCtl->m_trdp_send->setRun(true);//上位机某个EXCEL/功能 开始发送
        occ_send_1_startendCtl->m_trdp_send->startRun();
    }
    if(tabWidget_2->currentIndex() == 2)
    {
        qDebug()<<"set udp-send";
        occ_send_2_doorCtl->m_qStartPushButton->setDisabled(true);
        occ_send_2_doorCtl->m_trdp_send->setTRDPParam(occ_send_2_doorCtl->ownipedit->text(),occ_send_2_doorCtl->dstipedit->text(),occ_send_2_doorCtl->portedit->text(),occ_send_2_doorCtl->cycletimeedit->text());

        occ_send_2_doorCtl->m_trdp_send->setParseVec(occ_send_2_doorCtl->byteoffset,occ_send_2_doorCtl->datatype,occ_send_2_doorCtl->bitoffset,occ_send_2_doorCtl->data_attribute);
        occ_send_2_doorCtl->m_trdp_send->setSendData(occ_send_2_doorCtl->datavallist);
        occ_send_2_doorCtl->m_trdp_send->setRun(true);//上位机某个EXCEL/功能 开始发送
        occ_send_2_doorCtl->m_trdp_send->startRun();
    }
    if(tabWidget_2->currentIndex() == 3)//根据自己定的表格而定
    {
        qDebug()<<"set udp-recv";
        occ_recv_3_doorparam->m_qStartPushButton->setDisabled(true);

        occ_recv_3_doorparam->m_trdp_recv->setTRDPParam(occ_recv_3_doorparam->ownipedit->text(),occ_recv_3_doorparam->dstipedit->text(),occ_recv_3_doorparam->portedit->text(),occ_recv_3_doorparam->cycletimeedit->text());
        occ_recv_3_doorparam->m_trdp_recv->setParseVec(occ_recv_3_doorparam->byteoffset,occ_recv_3_doorparam->datatype,occ_recv_3_doorparam->bitoffset,occ_recv_3_doorparam->data_attribute);
        occ_recv_3_doorparam->m_trdp_recv->setRun(true);//上位机某个EXCEL/功能 开始接收
        occ_recv_3_doorparam->m_trdp_recv->startRun();
    }

    if(tabWidget_2->currentIndex() == 4)
    {
        qDebug()<<"set udp-send";
        occ_send_4_cylinderPosCtl->m_qStartPushButton->setDisabled(true);
        occ_send_4_cylinderPosCtl->m_trdp_send->setTRDPParam(occ_send_4_cylinderPosCtl->ownipedit->text(),occ_send_4_cylinderPosCtl->dstipedit->text(),occ_send_4_cylinderPosCtl->portedit->text(),occ_send_4_cylinderPosCtl->cycletimeedit->text());

        occ_send_4_cylinderPosCtl->m_trdp_send->setParseVec(occ_send_4_cylinderPosCtl->byteoffset,occ_send_4_cylinderPosCtl->datatype,occ_send_4_cylinderPosCtl->bitoffset,occ_send_4_cylinderPosCtl->data_attribute);
        occ_send_4_cylinderPosCtl->m_trdp_send->setSendData(occ_send_4_cylinderPosCtl->datavallist);
        occ_send_4_cylinderPosCtl->m_trdp_send->setRun(true);//上位机某个EXCEL/功能 开始发送
        occ_send_4_cylinderPosCtl->m_trdp_send->startRun();
    }
    if(tabWidget_2->currentIndex() == 5)
    {
        qDebug()<<"set udp-send";
        occ_send_5_errorClear->m_qStartPushButton->setDisabled(true);
        occ_send_5_errorClear->m_trdp_send->setTRDPParam(occ_send_5_errorClear->ownipedit->text(),occ_send_5_errorClear->dstipedit->text(),occ_send_5_errorClear->portedit->text(),occ_send_5_errorClear->cycletimeedit->text());

        occ_send_5_errorClear->m_trdp_send->setParseVec(occ_send_5_errorClear->byteoffset,occ_send_5_errorClear->datatype,occ_send_5_errorClear->bitoffset,occ_send_5_errorClear->data_attribute);
        occ_send_5_errorClear->m_trdp_send->setSendData(occ_send_5_errorClear->datavallist);
        occ_send_5_errorClear->m_trdp_send->setRun(true);//上位机某个EXCEL/功能 开始发送
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
