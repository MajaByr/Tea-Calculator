#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "teaCalculations.h"
#include <unistd.h>
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    TeaType getTeaType();
    int getStrength();
    int getBrewNumber();
    double calculateCoffeine(); //calculate coffeine amont

private slots:
    void on_btnCalculate_clicked();

    void on_btnCalculate_2_clicked();

private:
    Ui::MainWindow *ui;
    TeaType str2Type(QString str);
};
#endif // MAINWINDOW_H
