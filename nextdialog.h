#ifndef NEXTDIALOG_H
#define NEXTDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class NextDialog;
}

class NextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NextDialog(QWidget *parent = nullptr);
    ~NextDialog();


private slots:
    void on_pushButton_clicked();

private:
    Ui::NextDialog *ui;
    QSqlDatabase database;
    QSqlTableModel *tableModel;
};

#endif // NEXTDIALOG_H
