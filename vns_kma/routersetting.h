#ifndef ROUTERSETTING_H
#define ROUTERSETTING_H

#include <QDialog>

namespace Ui {
class routersetting;
}

class routersetting : public QDialog
{
    Q_OBJECT

public:
    explicit routersetting(QWidget *parent = 0);
    ~routersetting();

private:
    Ui::routersetting *ui;
};

#endif // ROUTERSETTING_H
