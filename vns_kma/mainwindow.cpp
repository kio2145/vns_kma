#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parsanddrow.h"
#include <QGraphicsPixmapItem>
#include <QFile>
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
    ui->pushButton_3->setIcon(ButtonIconn);
    ui->pushButton_3->setIconSize(QSize(60,60));
    ui->pushButton_4->setIcon(ButtonIconnn);
    ui->pushButton_4->setIconSize(QSize(60,60));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QFile file("exem.txt");
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    QPen pen(Qt::green);//Просто выбираем цвет для карандашика
    qApp->applicationDirPath() +"/modem.png";
    QPixmap lol;
    lol.load("modem.png");
    QGraphicsPixmapItem * p = scene->addPixmap(lol);
    //scene->addText("Hello, world!");
    p->moveBy(0,0);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->installEventFilter(this);

}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = (QMouseEvent *) event;
        QMessageBox::warning(0,"Warning", "Warning message text");
        //qDebug<<mouseEvent->pos().x()<<"     "<<mouseEvent->pos().y();    //в консоль выводим координаты
        return true;    //возвращаю true, событие обработано, дальнейшая обработка не требуется
    }
    return false;    //Событие должно быть обработано родительским виджетом
}


void MainWindow::on_pushButton_3_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,621,431);
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/sw.png";
    QPixmap lol;
    lol.load("sw.png");
    QGraphicsPixmapItem * p = scene->addPixmap(lol);
    p->moveBy(112,255);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->installEventFilter(this);
}

void MainWindow::on_pushButton_4_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/pc.giv";
    QPixmap lol;
    lol.load("pc.png");
    QGraphicsPixmapItem * p = scene->addPixmap(lol);
    p->moveBy(100,0);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->installEventFilter(this);
}

void MainWindow::on_pushButton_5_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,621,431);//розмір сцені
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/sw.png";
    QPixmap pc;
    QPixmap modem;
    QPixmap sw;
    pc.load("pc.png");
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
                    QGraphicsPixmapItem * b=scene->addPixmap(pc);
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

}


