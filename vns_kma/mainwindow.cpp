#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parsanddrow.h"
#include "pc.h"
#include "switch.h"
#include <QGraphicsPixmapItem>
#include <QFile>
#include "router.h"
#include<QMouseEvent>
#include <QPointF>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QLineEdit>
#include <stdlib.h>
#include <time.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap;
    QPixmap pixmapp;
    QPixmap pixmappp;
    QPixmap pixmapppp;
    pixmapppp.load("del.png");
    pixmap.load("sw.png");
    pixmappp.load("pc.png");
    pixmapp.load("modem.png");
    QIcon ButtonIconn(pixmap);
    QIcon ButtonIcon(pixmapp);
    QIcon ButtonIconnn(pixmappp);
    QIcon ButtonIconnnn(pixmapppp);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(QSize(60,60));
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->viewport()->setMouseTracking(1);
    ui->pushButton_3->setIcon(ButtonIconn);
    ui->pushButton_3->setIconSize(QSize(60,60));
    ui->pushButton_4->setIcon(ButtonIconnn);
    ui->pushButton_4->setIconSize(QSize(60,60));
    ui->pushButton_6->setIcon(ButtonIconnnn);
    ui->pushButton_6->setIconSize(QSize(48,48));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked() //роутер тут!
{
    router a;
    parsanddrow d;
    QString mac;
    QString name;
    QString newname;
    QString newmac;
    int m;
    srand(time(NULL));
    int dd;
    name=ui->lineEdit_5->text();
    mac=ui->lineEdit_6->text();
    a.addconfig(openfil(),300,300,mac,name);
    drawinwindow();
    int namber;
    dd=(d.count(openfil())/5);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord(openfil(),dd);//
    namber=d.coutofdev("modem",dd);
    newname="Router"+QString::number(namber);
    for(int j=0;j<dd;j++)
    {
        newname="Router" +QString::number(namber);
        if(d.getname(j)==newname)
        {
            namber++;
            j--;
        }
    }
    for(int j=0;j<8;j++)
    {
        m = rand()%100;
        newmac=newmac+QString::number( m, 16 );

    }
    for(int j=0;j<dd;j++)
    {
        if(d.getname(j)==newmac)
        {
             j=0;
             for(int j=0;j<8;j++)
             {
                 m = rand()%100;
                 newmac=newmac+QString::number( m, 16 );

             }
        }
    }
    ui->lineEdit_5->setText(newname);
    ui->lineEdit_6->setText(newmac);
    drawinwindow();
}

void MainWindow::on_pushButton_2_clicked()
{
    parsanddrow d;
    d.stop("graphic.txt");
    exit(0);
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)// --------
{
    int var;
    parsanddrow d;
    int dd;
    if(d.count(openfil())!=0)
    {
    dd=(d.count(openfil()))/5;
    d.cord(openfil(),dd);
    qreal x;
    qreal y;
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,621,431);//розмір сцені
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    QDebug qd= qDebug();
     if(event->type() == QEvent::MouseButtonPress)
     {
         if(d.movstart("graphic.txt")==0)
         {
             d.movs("graphic.txt");
         }
         else
         if (d.movstart("graphic.txt")==3)
         {
             QMouseEvent *mouseEvent =(QMouseEvent*) event;
             {
             for(int i=0;i<dd;i++)
             {
                 x=mouseEvent->pos().x();
                 y=mouseEvent->pos().y();
                 if(d.getx(i)>x-30 && d.getx(i)<x+30 && d.gety(i)>y-30 &&d.gety(i)<y+30 )
                 {
                     d.delate(openfil(),dd,i);
                     drawinwindow();
                 }
             }
             }
         }

          else
          {

              d.stop("graphic.txt");
          }
     }
     if(event->type() == QEvent::MouseMove)
    {

         qd<<event;
         qd<<d.movstart("graphic.txt");
         QMouseEvent *mouseEvent =(QMouseEvent*) event;
         {
             if(d.movstart("graphic.txt")==1)
               {
             x=mouseEvent->pos().x();
             y=mouseEvent->pos().y();

             qd<<x<<"   "<<y<<" draw"<<"\n";
             for(int i=0;i<dd;i++)
             {
                 if(d.getx(i)>x-30 && d.getx(i)<x+30 && d.gety(i)>y-30 &&d.gety(i)<y+30 )
                  {
                     qd<<x<<"   "<<y<<" cath"<<"\n";
                     int dd=(d.count(openfil()))/5;
                     d.rewritedata(openfil(),dd,i,x,y);
                     drawinwindow();
                 }
             }
             }
         }
         return true;
    }
       d.deletemas();
       return false;
    }
    }
      //Событие должно быть обработано родительским виджетом
void MainWindow::on_pushButton_3_clicked() //тут свитчи
{
    switches a;
    parsanddrow d;
    QString mac;
    QString name;
    QString newname;
    QString newmac;
    int m;
    srand(time(NULL));
    int dd;
    mac=ui->lineEdit_4->text();
    name=ui->lineEdit_3->text();
    a.addconfig(openfil(),250,250,mac,name);
    int namber;
    dd=(d.count(openfil())/5);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord(openfil(),dd);//
    namber=d.coutofdev("Switch",dd);
    newname="Switch"+QString::number(namber);
    for(int j=0;j<dd;j++)
    {
        newname="Switch" +QString::number(namber);
        if(d.getname(j)==newname)
        {
            namber++;
            j--;
        }
    }
    for(int j=0;j<8;j++)
    {
        m = rand()%100;
        newmac=newmac+QString::number( m, 16 );

    }
    for(int j=0;j<dd;j++)
    {
        if(d.getname(j)==newmac)
        {
             j=0;
             for(int j=0;j<8;j++)
             {
                 m = rand()%100;
                 newmac=newmac+QString::number( m, 16 );

             }
        }
    }
    ui->lineEdit_4->setText(newmac);
    ui->lineEdit_3->setText(newname);
    drawinwindow();
}

void MainWindow::on_pushButton_4_clicked() //тут пк
{
    pc a;
    parsanddrow d;
    QString mac;
    QString name;
    QString newname;
    QString newmac;
    int m;
    srand(time(NULL));
    int dd=0;
    name=ui->lineEdit->text();
    mac=ui->lineEdit_2->text();
    a.addconfig(openfil(),0,0,mac,name);
    int namber;
    dd=(d.count(openfil())/5);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord(openfil(),dd);//
    namber=d.coutofdev("pc",dd);
    newname="pc"+QString::number(namber);
    for(int j=0;j<dd;j++)
    {
        newname="PC" +QString::number(namber);
        if(d.getname(j)==newname)
        {
            namber++;
            j--;
        }
    }
    for(int j=0;j<8;j++)
    {
        m = rand()%100;
        newmac=newmac+QString::number( m, 16 );

    }
    for(int j=0;j<dd;j++)
    {
        if(d.getname(j)==newmac)
        {
             j=0;
             for(int j=0;j<8;j++)
             {
                 m = rand()%100;
                 newmac=newmac+QString::number( m, 16 );

             }
        }
    }
    ui->lineEdit_2->setText(newmac);
    ui->lineEdit->setText(newname);
    drawinwindow();
}

void MainWindow::on_pushButton_5_clicked()
{
    drawinwindow();
}
void MainWindow::on_pushButton_6_clicked()
{
    parsanddrow d;
    int dd=(d.count(openfil()))/5;
    d.cord(openfil(),dd);
    if(d.movstart("graphic.txt")==3)
    {
        d.stop("graphic.txt");
    }
    else
    {
    d.startdel("graphic.txt");
    }
}
void MainWindow::drawinwindow()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,725,575);//розмір сцені
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"C:/Users/Igro/build-vns_kma-Desktop_Qt_5_1_1_MinGW_32bit-Debug/24.jpeg";
    QPixmap pcc;
    QPixmap modem;
    QPixmap sw;
    QPainterPath path;
    QFont font;
    font.setPixelSize(50);
    //pcc.load("C:/Users/Igro/build-vns_kma-Desktop_Qt_5_1_1_MinGW_32bit-Debug/pc.png");
    pcc.load("pc.png");
    modem.load("modem.png");
    sw.load("sw.png");
    QString l; //назва приладу
    QDebug qd= qDebug();
    parsanddrow d;
    int dd; //кілкість приладів
    if(d.count(openfil())!=0)
    {
    dd=(d.count(openfil())/5);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord(openfil(),dd);//заповнення масивік кординатами та іменами (and mac)
    for(int h=0; h<dd; h++) //малювання
    {
        l=d.getdev(h);
                if(l=="sw")
                {
                    QGraphicsPixmapItem * a=scene->addPixmap(sw);
                    a->moveBy(d.getx(h),d.gety(h));
                    QFont font;
                    QPainterPath path;
                    font.setPixelSize(20);
                    font.setBold(false);
                    font.setFamily("Calibri");
                    path.addText(d.getx(h)-2,d.gety(h)+63,font,d.getname(h));
                    scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
                }
                if(l=="pc")
                {
                    QGraphicsPixmapItem * b=scene->addPixmap(pcc);
                    b->moveBy(d.getx(h),d.gety(h));
                    QFont font;
                    QPainterPath path;
                    font.setPixelSize(20);
                    font.setBold(false);
                    font.setFamily("Calibri");
                    path.addText(d.getx(h)-2,d.gety(h)+63,font,d.getname(h));
                    scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
                }
                if(l=="modem")
                {
                  QGraphicsPixmapItem * bc=scene->addPixmap(modem);
                  bc->moveBy(d.getx(h),d.gety(h));
                  QFont font;
                  QPainterPath path;
                  font.setPixelSize(20);
                  font.setBold(false);
                  font.setFamily("Calibri");
                  path.addText(d.getx(h)-2,d.gety(h)+63,font,d.getname(h));
                  scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
                }
                if((l!="modem")|(l!="sw")|(l!="pc"))
                {
                   qd<<l;
                }

     }
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->scene()->installEventFilter(this);
    d.deletemas();
    }
}

void MainWindow::on_actionExit_triggered()
{
    parsanddrow d;
    d.stop("graphic.txt");
    exit(0);
}

void MainWindow::on_action_triggered()
{
    QString filew=QFileDialog::getOpenFileName();
    if(filew.size()<=0)
    {
        QMessageBox::warning(0,"Warning", "УВАГА ВИ ПРАЦЮЕТЕ З ФАЙЛОМ "+openfil());
    }
    else
    {
    QFile file("worckfile");
    QTextStream stream(&file);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,"Warning", " ---");
    }
    else
    {
        stream<<filew.replace("\\\"","/"""); //шаманизм с эскейп последовательностью с форума он пашет
    }
    file.close();
    }
    drawinwindow();
}
QString MainWindow::openfil()
{
    QString mainfails;
    QFile file("worckfile");
    QTextStream t( &file );
    if ( !file.open(QIODevice::ReadOnly) )
          {
             QMessageBox::warning(0,"Warning", "робочій файл пошкоджено");
          }
    else
    {
    while ( !t.atEnd() )
    {
        mainfails=t.readLine();

    }
    }
    file.close();
    return mainfails;
}

void MainWindow::on_actionNew_triggered()
{
    QString filew=QFileDialog::getSaveFileName();
    QFile file("worckfile");
    QFile filen(filew.replace("\\\"","/"""));
    QTextStream streamm(&filen);
    filen.open(QIODevice::WriteOnly | QIODevice::Text);
    filen.close();
    QTextStream stream(&file);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,"Warning", " ---");
    }
    else
    {
        stream<<filew.replace("\\\"","/"""); //шаманизм с эскейп последовательностью с форума он пашет
    }
    file.close();

}
