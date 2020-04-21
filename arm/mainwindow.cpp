#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "win2.h"

#include"QNetworkAccessManager"
#include"QNetworkReply"
#include"QNetworkRequest"
#include <QJsonDocument>
#include <QMessageBox>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QUrlQuery>
#include <QJsonArray>
#include <QJsonParseError>
#include <QTextEdit>

QString msg;
QString city;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowOpacity(0.6);
    //this->setStyleSheet("#label{background:rgba(89,128,166,0.2);}");

    http2 = new QNetworkAccessManager(this);
    //关联结束信号，
    connect(http2,SIGNAL(finished(QNetworkReply *)),this,SLOT(read_data1(QNetworkReply *)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_data1(QNetworkReply *data1) //获取数据
{
     msg = data1->readAll();
}

void MainWindow::on_pushButton_clicked()   //点击查询 并且转到下一页
{
         this->hide();    //父界面隐藏
         win2 *a = new win2(this);   //创建一个子界面,并且把当前窗地址传给子窗
         a->setGeometry(this->geometry());   //geometry()是获取父界面的位置信息(比如窗口的x,y位置,还有长宽等信息
         a->show();
}

//this->setStyleSheet("#label{background:rgba(200,200,255,0.2);}");
//ui->label->setStyleSheet("background-color: rgb(255, 255, 0);");
//ui->label->setStyleSheet("background-color:transparent;");


void MainWindow::on_pushButton_2_clicked()
{
     city = ui->lineEdit->text();
     //发送请求
     http2->get(QNetworkRequest(QUrl("http://t.weather.sojson.com/api/weather/city/"+city)));
}
