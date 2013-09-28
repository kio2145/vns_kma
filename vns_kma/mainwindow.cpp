#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    scene->setSceneRect(0,0,621,431);
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    qApp->applicationDirPath() +"/sw.png";
    QFile file("exmp.txt");
    QPixmap pc;
    QPixmap modem;
    QPixmap sw;
    pc.load("pc.png");
    modem.load("modem.png");
    sw.load("sw.png");
    int i=0;
    QString l;
    QString le;
    QString lei;
    QString line;
    QDebug qd= qDebug();
    QTextStream t( &file );
    qreal x;
    qreal y;
    if ( !file.open(QIODevice::ReadOnly) )
          {
                QMessageBox::warning(0,"Warning", "файл пошкоджено");
           }
    else
    {
        while ( !t.atEnd() )
        {
            i++;
            line = t.readLine();
            if(i==1)
            {
                l=line;
            }
            if(i==2)
            {
                le=line;
                x=(le.toInt());
            }
            if(i==3)
            {
                lei=line;
                y=(lei.toInt());
            }
            if(i==4)
            {
                i=0;
                if(l=="sw")
                {
                    QGraphicsPixmapItem * b=scene->addPixmap(sw);
                    b->moveBy(x,y);
                    ui->graphicsView->setScene(scene);
                    ui->graphicsView->show();
                    qd<<x<<'\n';
                    qd<<"firs";
                    line="";
                    le="";
                    lei="";
                    l="";
                }
                if(l=="pc")
                {
                    QGraphicsPixmapItem * c=scene->addPixmap(pc);
                    c->moveBy(x,y);
                    ui->graphicsView->setScene(scene);
                    ui->graphicsView->show();
                    qd<<le<<'\n';
                    qd<<"second";
                    line="";
                    le="";
                    lei="";
                    l="";
                }
              if(l=="modem")
              {
                  QGraphicsPixmapItem * m=scene->addPixmap(modem);
                  m->moveBy(x,y);
                  ui->graphicsView->setScene(scene);
                  ui->graphicsView->show();
                  qd<<le<<'\n';
                  line="";
                  le="";
                  lei="";
                  l="";
               }
            }

        }
                //file.close();
    }
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->installEventFilter(this);

}
