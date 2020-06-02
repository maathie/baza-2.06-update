#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

#include <QMainWindow>
#include "seconddialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SecondDialog *secondDialog;
};
#endif // MAINWINDOW_H
