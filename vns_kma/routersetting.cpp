#include "routersetting.h"
#include "ui_routersetting.h"

routersetting::routersetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::routersetting)
{
    ui->setupUi(this);
}

routersetting::~routersetting()
{
    delete ui;
}
