#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QFile>
#include<QMouseEvent>
#include <QPointF>
#include <QTextStream>
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
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen(Qt::green);//Просто выбираем цвет для карандашика
    scene->addLine(0,90,180,90,pen);//x
    scene->addLine(90,0,90,180,pen);//y
    qApp->applicationDirPath() +"/24.jpg";
    QPixmap lol;
    lol.load("24.jpg");
    QGraphicsPixmapItem * p = scene->addPixmap(lol);
    //scene->addText("Hello, world!");
    p->moveBy(-200,-200);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->setScene(scene);

}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}
class MyView
   : public QGraphicsView
{
    public:
         MyView(QWidget* parent = 0 );
        MyView(QGraphicsScene* scene, QWidget* parent = 0 );

    protected:

        //эту функцию реализуешь в соответсвии со своими потребностями.
        void mousePressEvent(QMouseEvent *event)
        {
              QPoint viewPos = event->pos();//позиция в системе координат виджета
              QPointF scenePos(mapToScene(viewPos));//позиция в системе координат сцены.
              QFile file("test.txt");
              file.open(QIODevice::Append | QIODevice::Text);
              QTextStream out(&file);
              out <<"lol";
              out << "\n";
              file.close();
              //твой код....
              QGraphicsView::mouseMoveEvent(event);
        }
};//class MyView
