#ifndef SWITCHSETING_H
#define SWITCHSETING_H

#include <QDialog>

namespace Ui {
class Switchseting;
}

class Switchseting : public QDialog
{
    Q_OBJECT

public:
    explicit Switchseting(QWidget *parent = 0);
    ~Switchseting();

private:
    Ui::Switchseting *ui;
};

#endif // SWITCHSETING_H
