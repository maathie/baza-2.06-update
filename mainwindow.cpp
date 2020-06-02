#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString haslo = ui->lineEdit_haslo->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("bazauczniow");
        db.setUserName("root");
        db.setPassword("1234");
        bool ok = db.open();
        qDebug() <<  ok;

    if(id == "1234" && haslo == "admin" ) {
        QMessageBox::information(this, "Login", "Hasło jest poprawne");
        hide();
        secondDialog = new SecondDialog(this);
        secondDialog->show();
    }
    else {
        QMessageBox::information(this, "Login", "Hasło jest niepoprawne");
    }
}
