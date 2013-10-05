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
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap;
    QPixmap pixmapp;
    QPixmap pixmappp;
    pixmap.load("sw.png");
    pixmappp.load("pc.png");
    pixmapp.load("modem.png");
    QIcon ButtonIconn(pixmap);
    QIcon ButtonIcon(pixmapp);
     QIcon ButtonIconnn(pixmappp);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(QSize(60,60));
    //ui->pushButton->setAutoFillBackground(true);
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->viewport()->setMouseTracking(1);
    ui->pushButton_3->setIcon(ButtonIconn);
    ui->pushButton_3->setIconSize(QSize(60,60));
    ui->pushButton_4->setIcon(ButtonIconnn);
    ui->pushButton_4->setIconSize(QSize(60,60));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked() //роутер тут!
{
    router a;
    a.addconfig("exmp.txt",300,300,"mac888");
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,621,431);//розмір сцені
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/sw.png";
    QPixmap pcc;
    QPixmap modem;
    QPixmap sw;
    pcc.load("pc.png");
    modem.load("modem.png");
    sw.load("sw.png");
    QString l; //назва приладу
    QDebug qd= qDebug();
    parsanddrow d;
    int dd; //кілкість приладів
    dd=(d.count("exmp.txt")/4);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord("exmp.txt",dd);//заповнення масивік кординатами та іменами (and mac)
    qd<<dd;
    for(int h=0; h<dd; h++) //малювання
    {
        l=d.getdev(h);
                if(l=="sw")
                {
                    QGraphicsPixmapItem * a=scene->addPixmap(sw);
                    a->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="pc")
                {
                    QGraphicsPixmapItem * b=scene->addPixmap(pcc);
                    b->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="modem")
                {
                  QGraphicsPixmapItem * bc=scene->addPixmap(modem);
                  bc->moveBy(d.getx(h),d.gety(h));
                }
                if((l!="modem")|(l!="sw")|(l!="pc"))
                {
                   qd<<l;
                }

     }

    qd<<l;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->scene()->installEventFilter(this);
    d.deletemas();
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)// --------
{
    int w;
    int pos;
    parsanddrow d;
    int dd=(d.count("exmp.txt"))/4;
    d.cord("exmp.txt",dd);
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
         {
             d.movstop("graphic.txt");
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
                 if(d.getx(i)>x-25 && d.getx(i)<x+25 && d.gety(i)>y-25 &&d.gety(i)<y+25 )
                  {
                     pos=i;
                     qd<<x<<"   "<<y<<" cath"<<"\n";
                     int dd=(d.count("exmp.txt"))/4;
                     d.rewritedata("exmp.txt",dd,pos,x,y);
                     qd<<x<<"   "<<y<<"done";
                     qApp->applicationDirPath() +"/sw.png";
                     QPixmap pcc;
                     QPixmap modem;
                     QPixmap sw;
                     pcc.load("pc.png");
                     modem.load("modem.png");
                     sw.load("sw.png");
                     QString l; //назва приладу
                     for(int h=0; h<dd; h++) //малювання
                      {
                         l=d.getdev(h);
                         if(l=="sw")
                          {
                             QGraphicsPixmapItem * a=scene->addPixmap(sw);
                             a->moveBy(d.getx(h),d.gety(h));
                         }
                         if(l=="pc")
                         {
                             QGraphicsPixmapItem * b=scene->addPixmap(pcc);
                             b->moveBy(d.getx(h),d.gety(h));
                         }
                         if(l=="modem")
                         {
                             QGraphicsPixmapItem * bc=scene->addPixmap(modem);
                             bc->moveBy(d.getx(h),d.gety(h));
                         }
                     }
                     //w=3;
                     ui->graphicsView->setScene(scene);
                     ui->graphicsView->show();
                   }
             }
             x=mouseEvent->pos().x();
             y=mouseEvent->pos().y();
             qd<<x<<"   "<<y<<" cath"<<"\n";
           }
         }
         return true;
    }
       return false;
    }
      //Событие должно быть обработано родительским виджетом
void MainWindow::on_pushButton_3_clicked() //тут свитчи
{
    switches a;
    a.addconfig("exmp.txt",250,250,"mac777");
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,621,431);//розмір сцені
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/sw.png";
    parsanddrow d;
    QPixmap pcc;
    QPixmap modem;
    QPixmap sw;
    pcc.load("pc.png");
    modem.load("modem.png");
    sw.load("sw.png");
    QString l; //назва приладу
    QDebug qd= qDebug();
    int dd; //кілкість приладів
    dd=(d.count("exmp.txt")/4);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord("exmp.txt",dd);//заповнення масивік кординатами та іменами (and mac)
    qd<<dd;
    for(int h=0; h<dd; h++) //малювання
    {
        l=d.getdev(h);
                if(l=="sw")
                {
                    QGraphicsPixmapItem * a=scene->addPixmap(sw);
                    a->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="pc")
                {
                    QGraphicsPixmapItem * b=scene->addPixmap(pcc);
                    b->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="modem")
                {
                  QGraphicsPixmapItem * bc=scene->addPixmap(modem);
                  bc->moveBy(d.getx(h),d.gety(h));
                }

     }
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->scene()->installEventFilter(this);
    d.deletemas();
}

void MainWindow::on_pushButton_4_clicked() //тут пк
{
    pc a;
    a.addconfig("exmp.txt",0,0,"mac666");
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,621,431);//розмір сцені
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/sw.png";
    QPixmap pcc;
    QPixmap modem;
    QPixmap sw;
    pcc.load("pc.png");
    modem.load("modem.png");
    sw.load("sw.png");
    QString l; //назва приладу
    QDebug qd= qDebug();
    parsanddrow d;
    int dd; //кілкість приладів
    dd=(d.count("exmp.txt")/4);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord("exmp.txt",dd);//заповнення масивік кординатами та іменами (and mac)

    for(int h=0; h<dd; h++) //малювання
    {
        l=d.getdev(h);
                if(l=="sw")
                {
                    QGraphicsPixmapItem * a=scene->addPixmap(sw);
                    a->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="pc")
                {
                    QGraphicsPixmapItem * b=scene->addPixmap(pcc);
                    b->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="modem")
                {
                  QGraphicsPixmapItem * bc=scene->addPixmap(modem);
                  bc->moveBy(d.getx(h),d.gety(h));
                }
                if((l!="modem")|(l!="sw")|(l!="pc"))
                {
                   qd<<l;
                }

     }

    qd<<l;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->scene()->installEventFilter(this);
    d.deletemas();
}

void MainWindow::on_pushButton_5_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,621,431);//розмір сцені
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/sw.png";
    QPixmap pcc;
    QPixmap modem;
    QPixmap sw;
    pcc.load("pc.png");
    modem.load("modem.png");
    sw.load("sw.png");
    QString l; //назва приладу
    QDebug qd= qDebug();
    parsanddrow d;
    int dd; //кілкість приладів
    dd=(d.count("exmp.txt")/4);//кілкість рядків на 4 властивості отримаємо кілкість приладів
    d.cord("exmp.txt",dd);//заповнення масивік кординатами та іменами (and mac)
    for(int h=0; h<dd; h++) //малювання
    {
        l=d.getdev(h);
                if(l=="sw")
                {
                    QGraphicsPixmapItem * a=scene->addPixmap(sw);
                    a->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="pc")
                {
                    QGraphicsPixmapItem * b=scene->addPixmap(pcc);
                    b->moveBy(d.getx(h),d.gety(h));
                }
                if(l=="modem")
                {
                  QGraphicsPixmapItem * bc=scene->addPixmap(modem);
                  bc->moveBy(d.getx(h),d.gety(h));
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




