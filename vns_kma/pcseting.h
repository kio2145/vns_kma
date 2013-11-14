#ifndef PCSETING_H
#define PCSETING_H

#include <QDialog>

namespace Ui {
class PCseting;
}

class PCseting : public QDialog
{
    Q_OBJECT

public:
    explicit PCseting(QWidget *parent = 0);
    ~PCseting();

private:
    Ui::PCseting *ui;
};

#endif // PCSETING_H
