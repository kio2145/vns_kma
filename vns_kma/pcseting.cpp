#include "pcseting.h"
#include "ui_pcseting.h"

PCseting::PCseting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCseting)
{
    ui->setupUi(this);
}

PCseting::~PCseting()
{
    delete ui;
}
