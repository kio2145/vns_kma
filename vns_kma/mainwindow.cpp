#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QFile>
#include<QMouseEvent>
#include <QPointF>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap;
    pixmap.load("25.png");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(QSize(60,60));
    //ui->pushButton->setAutoFillBackground(true);
    ui->graphicsView->viewport()->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop );
    QPen pen(Qt::green);//Просто выбираем цвет для карандашика
    scene->addLine(0,90,180,90,pen);//x
    scene->addLine(90,0,90,180,pen);//y
    qApp->applicationDirPath() +"/24.jpg";
    QPixmap lol;
    lol.load("24.jpg");
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

