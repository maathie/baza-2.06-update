#include "nextdialog.h"
#include "ui_nextdialog.h"

NextDialog::NextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextDialog)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setDatabaseName("bazauczniow");
    database.setUserName("root");
    database.setPassword("1234");

    if(database.open()) {

        tableModel = new QSqlTableModel();
        tableModel->setTable("uczniowie");
        tableModel->select();

        tableModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
        tableModel->setHeaderData(1, Qt::Horizontal, tr("Imię"));
        tableModel->setHeaderData(2, Qt::Horizontal, tr("Nazwisko"));
        tableModel->setHeaderData(3, Qt::Horizontal, tr("Klasa"));
        tableModel->setHeaderData(4, Qt::Horizontal, tr("Wiek"));
        tableModel->setHeaderData(5, Qt::Horizontal, tr("Dyscyplina"));
        tableModel->setHeaderData(6, Qt::Horizontal, tr("Hasło"));

        ui->tableView->setModel (tableModel);



    }else {
        QMessageBox::information(this, "Failed", "Connection Failed");
    }

}

NextDialog::~NextDialog()
{
    database.close();
    delete ui;
}

void NextDialog::on_pushButton_clicked()
{
    QString ID = ui->lineEdit_ID->text();
    QString Imie = ui->lineEdit_Imie->text();
    QString Nazwisko = ui->lineEdit_Nazwisko->text();
    QString Klasa = ui->lineEdit_Klasa->text();
    QString Wiek = ui->lineEdit_Wiek->text();
    QString Dyscyplina = ui->lineEdit_Dyscyplina->text();

    const int row = tableModel->rowCount();
    tableModel->insertRows(row, 1);
    tableModel->setData(tableModel->index(row, 0), ID);
    tableModel->setData(tableModel->index(row, 1), Imie);
    tableModel->setData(tableModel->index(row, 2), Nazwisko);
    tableModel->setData(tableModel->index(row, 3), Klasa);
    tableModel->setData(tableModel->index(row, 4), Wiek);
    tableModel->setData(tableModel->index(row, 5), Dyscyplina);

    tableModel->submitAll();

    ui->tableView->update();
}
