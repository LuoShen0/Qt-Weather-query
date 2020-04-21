#include "win2.h"
#include "ui_win2.h"
#include "mainwindow.h"

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
#include <QJsonValue>
#include <QPixmap>

#define wpic1  "C:/Users/eva/Desktop/yun.jpg"
#define wpic2  "C:/Users/eva/Desktop/yu.jpg"
#define wpic3  "C:/Users/eva/Desktop/sun.jpg"

#define lpic1  "/weather/yun.jpg"
#define lpic2  "/weather/yu.jpg"
#define lpic3  "/weather/sun.jpg"

extern QString msg;

QJsonParseError err;

win2::win2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::win2)
{
    ui->setupUi(this);
    //QTabBar::tab{ min-height: 30px; min-width:110px;}
    ui->tabWidget->setDocumentMode(true);
    QString str;
    str.append("QTabWidget::pane{border-width: 0px;border-color:white;border-style:outset;background-color: rgb(89,128,166);border-radius: 3px;}");

    if(msg != nullptr)
    {
        QString json_data = msg;
        QJsonDocument json = QJsonDocument::fromJson(json_data.toUtf8(),&err);
        QJsonObject obj = json.object();  

        //地点
        QJsonValue  value1  =  obj.take("cityInfo").toObject().take("city");   //市
        QJsonObject obj1 = json.object();
        QJsonValue  value2  =  obj1.take("cityInfo").toObject().take("parent");  //省


        //省市显示到七个窗口
        ui->label_16->setText((value2.toString()+"   "+value1.toString()));   //01
         ui->label_17->setText((value2.toString()+"   "+value1.toString()));   //02
          ui->label_18->setText((value2.toString()+"   "+value1.toString()));   //03
           ui->label_19->setText((value2.toString()+"   "+value1.toString()));   //04
            ui->label_20->setText((value2.toString()+"   "+value1.toString()));   //05
             ui->label_21->setText((value2.toString()+"   "+value1.toString()));   //06
              ui->label_22->setText((value2.toString()+"   "+value1.toString()));   //07

//第一天

        QJsonArray json_arry = obj.take("data").toObject().take("forecast").toArray();

        QString msg1 = json_arry.at(0).toObject().take("high").toString();  //高温
        QString msg2 = json_arry.at(0).toObject().take("low").toString();  //低温
        ui->label_2->setText(msg1+" "+"~"+" "+msg2);

        QString msg3 = json_arry.at(0).toObject().take("ymd").toString();   //日期
        ui->label_3->setText(msg3);

        QString msg4 = json_arry.at(0).toObject().take("week").toString();   //星期
        ui->label_7->setText(msg4);

        int msg5 = json_arry.at(0).toObject().take("aqi").toInt();   //空气质量指数
        QString::number(msg5);
        ui->label_5->setText(QString::number(msg5));

        QString msg6 = json_arry.at(0).toObject().take("fx").toString();   //风
        QString msg7 = json_arry.at(0).toObject().take("fl").toString();   //风力大小
        ui->label_4->setText(msg6+" "+msg7);

        QString msg8 = json_arry.at(0).toObject().take("type").toString();   //云
        QString msg9 = json_arry.at(0).toObject().take("notice").toString();   //温馨提示
        ui->label_34->setText(msg8);
        ui->label_33->setText(msg9);

        //判断是天气情况来显示相应图片
        if(msg8.indexOf("阴") >=0)
        {

            QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label->width(),ui->label->height());

             //把图片显示到标签中
             ui->label->setPixmap(tmp1);
        }
        else if(msg8.indexOf("雨") >=0)
        {
             QString tmp = wpic2;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label->width(),ui->label->height());

             //把图片显示到标签中
             ui->label->setPixmap(tmp1);
        }
        else if (msg8.indexOf("云") >=0)
        {         

             QString tmp = wpic1;


            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label->width(),ui->label->height());

             //把图片显示到标签中
             ui->label->setPixmap(tmp1);
        }
        else
        {        

             QString tmp = wpic3;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label->width(),ui->label->height());

             //把图片显示到标签中
             ui->label->setPixmap(tmp1);
        }


//第二天
        QString msg10 = json_arry.at(1).toObject().take("high").toString();  //高温
        QString msg11 = json_arry.at(1).toObject().take("low").toString();  //低温
        ui->label_60->setText(msg10+" "+"~"+" "+msg11);

        QString msg12 = json_arry.at(1).toObject().take("ymd").toString();   //日期
        ui->label_9->setText(msg12);

        QString msg13 = json_arry.at(1).toObject().take("week").toString();   //星期
        ui->label_8->setText(msg13);

        int msg14 = json_arry.at(1).toObject().take("aqi").toInt();   //空气质量指数
        QString::number(msg14);
        ui->label_59->setText(QString::number(msg14));

        QString msg15 = json_arry.at(1).toObject().take("fx").toString();   //风
        QString msg16 = json_arry.at(1).toObject().take("fl").toString();   //风力大小
        ui->label_61->setText(msg15+" "+msg16);

        QString msg17 = json_arry.at(1).toObject().take("type").toString();   //云
        QString msg18 = json_arry.at(1).toObject().take("notice").toString();   //温馨提示
        ui->label_58->setText(msg17);
        ui->label_94->setText(msg18);

        //判断是天气情况来显示相应图片
        if(msg17.indexOf("阴") >=0)
        {
             QString tmp = wpic1;


            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_62->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_62->setPixmap(tmp1);
        }
        else if(msg17.indexOf("雨") >=0)
        {

             QString tmp = wpic2;
            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_62->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_62->setPixmap(tmp1);
        }
        else if (msg17.indexOf("云") >=0)
        {       
            QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_62->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_62->setPixmap(tmp1);
        }
        else
        {         
              QString tmp = wpic3;
            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_62->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_62->setPixmap(tmp1);
        }

//第三天
        QString msg19 = json_arry.at(2).toObject().take("high").toString();  //高温
        QString msg20 = json_arry.at(2).toObject().take("low").toString();  //低温
        ui->label_66->setText(msg19+" "+"~"+" "+msg20);

        QString msg21 = json_arry.at(2).toObject().take("ymd").toString();   //日期
        ui->label_23->setText(msg21);

        QString msg22 = json_arry.at(2).toObject().take("week").toString();   //星期
        ui->label_10->setText(msg22);

        int msg23 = json_arry.at(2).toObject().take("aqi").toInt();   //空气质量指数
        QString::number(msg23);
        ui->label_65->setText(QString::number(msg23));

        QString msg24 = json_arry.at(2).toObject().take("fx").toString();   //风
        QString msg25 = json_arry.at(2).toObject().take("fl").toString();   //风力大小
        ui->label_67->setText(msg24+" "+msg25);

        QString msg26 = json_arry.at(2).toObject().take("type").toString();   //云
        QString msg27 = json_arry.at(2).toObject().take("notice").toString();   //温馨提示
        ui->label_64->setText(msg26);
        ui->label_95->setText(msg27);

        //判断是天气情况来显示相应图片
        if(msg26.indexOf("阴") >=0)
        {    

            QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_68->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_68->setPixmap(tmp1);
        }
        else if(msg26.indexOf("雨") >=0)
        {
             QString tmp = wpic2;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_68->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_68->setPixmap(tmp1);
        }
        else if (msg26.indexOf("云") >=0)
        {

             QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_68->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_68->setPixmap(tmp1);
        }
        else
        {
             QString tmp = wpic3;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_68->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_68->setPixmap(tmp1);
        }

//第四天
        QString msg28 = json_arry.at(3).toObject().take("high").toString();  //高温
        QString msg29 = json_arry.at(3).toObject().take("low").toString();  //低温
        ui->label_72->setText(msg28+" "+"~"+" "+msg29);

        QString msg30 = json_arry.at(3).toObject().take("ymd").toString();   //日期
        ui->label_25->setText(msg30);

        QString msg31 = json_arry.at(3).toObject().take("week").toString();   //星期
        ui->label_24->setText(msg31);

        int msg32 = json_arry.at(3).toObject().take("aqi").toInt();   //空气质量指数
        QString::number(msg32);
        ui->label_71->setText(QString::number(msg32));

        QString msg33 = json_arry.at(3).toObject().take("fx").toString();   //风
        QString msg34 = json_arry.at(3).toObject().take("fl").toString();   //风力大小
        ui->label_73->setText(msg33+" "+msg34);

        QString msg35 = json_arry.at(3).toObject().take("type").toString();   //云
        QString msg36 = json_arry.at(3).toObject().take("notice").toString();   //温馨提示
        ui->label_70->setText(msg35);
        ui->label_96->setText(msg36);


        //判断是天气情况来显示相应图片
        if(msg35.indexOf("阴") >=0)
        {
             QString tmp = wpic1;


            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_74->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_74->setPixmap(tmp1);
        }
        else if(msg35.indexOf("雨") >=0)
        {
             QString tmp = wpic2;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_74->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_74->setPixmap(tmp1);
        }
        else if (msg35.indexOf("云") >=0)
        {
             QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_74->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_74->setPixmap(tmp1);
        }
        else
        {    
              QString tmp = wpic3;
            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_74->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_74->setPixmap(tmp1);
        }

//第五天
        QString msg37 = json_arry.at(4).toObject().take("high").toString();  //高温
        QString msg38 = json_arry.at(4).toObject().take("low").toString();  //低温
        ui->label_78->setText(msg37+" "+"~"+" "+msg38);

        QString msg39 = json_arry.at(4).toObject().take("ymd").toString();   //日期
        ui->label_27->setText(msg39);

        QString msg40 = json_arry.at(4).toObject().take("week").toString();   //星期
        ui->label_26->setText(msg40);

        int msg41 = json_arry.at(4).toObject().take("aqi").toInt();   //空气质量指数
        QString::number(msg41);
        ui->label_77->setText(QString::number(msg41));

        QString msg42 = json_arry.at(4).toObject().take("fx").toString();   //风
        QString msg43 = json_arry.at(4).toObject().take("fl").toString();   //风力大小
        ui->label_79->setText(msg42+" "+msg43);

        QString msg44 = json_arry.at(4).toObject().take("type").toString();   //云
        QString msg45 = json_arry.at(4).toObject().take("notice").toString();   //温馨提示
        ui->label_76->setText(msg44);
        ui->label_164->setText(msg45);

        //判断是天气情况来显示相应图片
        if(msg44.indexOf("阴") >=0)
        {
            QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_80->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_80->setPixmap(tmp1);
        }
        else if(msg44.indexOf("雨") >=0)
        {
              QString tmp = wpic2;
            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_80->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_80->setPixmap(tmp1);
        }
        else if (msg44.indexOf("云") >=0)
        {

             QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_80->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_80->setPixmap(tmp1);
        }
        else
        {
             QString tmp = wpic3;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_80->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_80->setPixmap(tmp1);
        }

//第六天
        QString msg46 = json_arry.at(5).toObject().take("high").toString();  //高温
        QString msg47 = json_arry.at(5).toObject().take("low").toString();  //低温
        ui->label_84->setText(msg46+" "+"~"+" "+msg47);

        QString msg48 = json_arry.at(5).toObject().take("ymd").toString();   //日期
        ui->label_29->setText(msg48);

        QString msg49 = json_arry.at(5).toObject().take("week").toString();   //星期
        ui->label_28->setText(msg49);

        int msg50 = json_arry.at(5).toObject().take("aqi").toInt();   //空气质量指数
        QString::number(msg50);
        ui->label_83->setText(QString::number(msg50));

        QString msg51 = json_arry.at(5).toObject().take("fx").toString();   //风
        QString msg52 = json_arry.at(5).toObject().take("fl").toString();   //风力大小
        ui->label_85->setText(msg51+" "+msg52);

        QString msg53 = json_arry.at(5).toObject().take("type").toString();   //云
        QString msg54 = json_arry.at(5).toObject().take("notice").toString();   //温馨提示
        ui->label_82->setText(msg53);
        ui->label_165->setText(msg54);


        //判断是天气情况来显示相应图片
        if(msg53.indexOf("阴") >=0)
        {

            QString tmp = wpic1;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_86->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_86->setPixmap(tmp1);
        }
        else if(msg53.indexOf("雨") >=0)
        {
            QString tmp = wpic2;
            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_86->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_86->setPixmap(tmp1);
        }
        else if (msg53.indexOf("云") >=0)
        {
             QString tmp = wpic1;


            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_86->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_86->setPixmap(tmp1);
        }
        else
        {

             QString tmp = wpic3;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_86->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_86->setPixmap(tmp1);
        }

//第七天
        QString msg55 = json_arry.at(6).toObject().take("high").toString();  //高温
        QString msg56 = json_arry.at(6).toObject().take("low").toString();  //低温
        ui->label_90->setText(msg55+" "+"~"+" "+msg56);

        QString msg57 = json_arry.at(6).toObject().take("ymd").toString();   //日期
        ui->label_31->setText(msg57);

        QString msg58 = json_arry.at(6).toObject().take("week").toString();   //星期
        ui->label_30->setText(msg58);

        int msg59 = json_arry.at(6).toObject().take("aqi").toInt();   //空气质量指数
        QString::number(msg59);
        ui->label_89->setText(QString::number(msg59));

        QString msg60 = json_arry.at(6).toObject().take("fx").toString();   //风
        QString msg61 = json_arry.at(6).toObject().take("fl").toString();   //风力大小
        ui->label_91->setText(msg60+" "+msg61);

        QString msg62 = json_arry.at(6).toObject().take("type").toString();   //云
        QString msg63 = json_arry.at(6).toObject().take("notice").toString();   //温馨提示
        ui->label_88->setText(msg62);
        ui->label_166->setText(msg63);


        //判断是天气情况来显示相应图片
        if(msg62.indexOf("阴") >=0)
        {
             QString tmp = wpic1;


            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_92->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_92->setPixmap(tmp1);
        }
        else if(msg62.indexOf("雨") >=0)
        {
             QString tmp = wpic2;

            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_92->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_92->setPixmap(tmp1);
        }
        else if (msg62.indexOf("云") >=0)
        {


            QString tmp = wpic1;
            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_92->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_92->setPixmap(tmp1);
        }
        else
        {

             QString tmp = wpic3;
            //定义一个图片处理类
             QPixmap pic(tmp);

             //根据label 的大小去设置
             QPixmap tmp1 = pic.scaled(ui->label_92->width(),ui->label->height());

             //把图片显示到标签中
             ui->label_92->setPixmap(tmp1);
        }

    }
}

win2::~win2()
{
    delete ui;
}


void win2::on_pushButton_clicked()
{

    this->parentWidget()->show();
    this->close();
}
