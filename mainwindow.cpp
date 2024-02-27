#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_btnCalculate_clicked()
{
    ui->lcdTemperature->display( calculateTemperature( getTeaType() ) );
    double teaTime=calculateTime( getTeaType(), getStrength(), getBrewNumber() );
    ui->lcdTime->display( teaTime );
}

TeaType MainWindow::getTeaType()
{
    return str2Type( ui->cboxType->currentText() );
}

TeaType MainWindow::str2Type(QString str)
{
    if(str == "Black") return Black;
    else if(str == "Green") return Green;
    else if(str == "White") return White;
    else if(str == "Oolong") return Oolong;
    else exit(1); //in other case shut down, add exception
}


int MainWindow::getStrength()
{
    return ui->sliderStrength->value(); //zwraca 0-99
}

int MainWindow::getBrewNumber()
{
    return ui->sliderBrewN->value();
}



void MainWindow::on_btnCalculate_2_clicked()
{
    ui->lcdTemperature->display( calculateTemperature( getTeaType() ) );
    ui->labCoffeineRes->setText( calculateCoffeine() );
}

