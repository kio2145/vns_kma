#include "switchseting.h"
#include "ui_switchseting.h"

Switchseting::Switchseting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Switchseting)
{
    ui->setupUi(this);
}

Switchseting::~Switchseting()
{
    delete ui;
}
