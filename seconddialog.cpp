#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "nextdialog.h"
SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);
}

SecondDialog::~SecondDialog()
{
    delete ui;
}

void SecondDialog::on_pushButton_clicked()
{
    NextDialog nextdialog;
    nextdialog.setModal(true);
    nextdialog.exec();
}
