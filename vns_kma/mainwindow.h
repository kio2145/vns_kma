#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    bool eventFilter(QObject *target, QEvent *event);
   /* {
        if (event->type() == QEvent::MouseButtonDblClick)
        {
            QMouseEvent *mouseEvent = (QMouseEvent *) event;
            QMessageBox::warning(0,"Warning", "Warning message text");
            //qDebug<<mouseEvent->pos().x()<<"     "<<mouseEvent->pos().y();    //в консоль выводим координаты
            return true;    //возвращаю true, событие обработано, дальнейшая обработка не требуется
        }
        return false;    //Событие должно быть обработано родительским виджетом
    }*/

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
