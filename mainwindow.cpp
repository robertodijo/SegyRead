#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "csegy.h"
#include "util.h"
#include <QString>
#include <QFileDialog>
#include <QTextBrowser>
#include <QPushButton>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //打开一个SEGY文件
    connect(ui->actionImport, SIGNAL(triggered(bool)), this, SLOT(OnImport()));
    connect(ui->btnShowBinary, SIGNAL(clicked(bool)), this, SLOT(OnBtnShowBinary()));
    connect(ui->btnShowAscii, SIGNAL(clicked(bool)), this, SLOT(OnBtnShowAscii()));







    //显示卷头信息和文字头信息


    //ui->txtVolumHeader->setText(s.m_volHead);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OnImport()
{

    QString filepath = QFileDialog::getOpenFileName(
                this,
                "Select a .sgy or .segy file!"
                );

    if ( filepath.length()>0 )
    {

        ui->edtFilePath->setText(filepath);

    }
    //QString 型转换成 Char型
    char* ch_filepath;
    ch_filepath = qstr2char(filepath);



    //实例化CSegy类对象，头文件中声明了类成员
    m_segy.OpenFile(ch_filepath);    //打开segy文件并读3200卷头、400文字头以及扫描数据




}

void MainWindow::OnBtnShowBinary()
{


    m_txtheader = m_segy.GetVolumeHead();
    QString str_binary;
    str_binary.sprintf(
                "数据道数是:%d\n采样间隔是:%d\n采样点数是：%d\n数据格式:%d\n单位制:%d\n",
                m_txtheader->ntrpr, m_txtheader->dto, m_txtheader->hns, m_txtheader->format, m_txtheader->mfeet);
    ui->txtTextHeader->setText(str_binary);

}

void MainWindow::OnBtnShowAscii()
{
    QString str_ascii;
    char* ascii;
    ascii =m_segy.GetTextHead();
    str_ascii=QString(QLatin1String(ascii));
    ui->txtVolumeHeader->setText(str_ascii);


}
