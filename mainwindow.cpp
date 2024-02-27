#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font("Garamond");
    font.setPointSize(18);
    //font.setStyleHint(QFont::Monospace);
    //QApplication::setFont(font);
    //ui->label->setFont(QApplication::font());
    //ui->QLabel::setFont(font);
    setStyleSheet("background-color: #224d1f;");
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

TeaType MainWindow::getTeaTypeC()
{
    return str2Type( ui->cboxTypeC->currentText() );
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

int MainWindow::getBrewNumber() //1-3
{
    return ui->sliderBrewN->value();
}

int MainWindow::getBrewNumberCof() //1-3
{
    return ui->sliderBrewNC->value();
}


void MainWindow::on_btnCalculate_2_clicked()
{
    ui->labCoffeineRes->setText( QString::number(calculateCoffeine(getTeaTypeC(), getSize(), getBrewNumberCof()), 'g', 5) );
}

int MainWindow::getSize()
{
    switch ( ui->cBoxSize->currentIndex() ) {
        case 1: return 150;
        case 2: return 250;
        case 3: return 300;
        case 4: return 500;
        default: return 250;
    }
}

int MainWindow::getSizeW()
{
    switch ( ui->cbSizeW->currentIndex() ) {
        case 1: return 150;
        case 2: return 250;
        case 3: return 300;
        case 4: return 500;
        default: return 250;
    }
}

void MainWindow::on_btnCalculate_3_clicked()
{
    if( getExpectTemp()>getLiquidTemp() || getOutsideTemp()>getLiquidTemp() ) { ui->labelWaitRes->setText("Invalid parameters"); return; }
    ui->labelWaitRes->setText( QString::number(calculateWaitingTime(getSizeW(), getOutsideTemp(), getLiquidTemp(), getExpectTemp())) );
}

double MainWindow::getOutsideTemp()
{
    return ui->spinBoxOut->value();
}

double MainWindow::getLiquidTemp()
{
    return ui->spinBoxLiq->value();
}

double MainWindow::getExpectTemp()
{
    return ui->spinBoxExp->value();
}


void MainWindow::on_btnCalculate_4_clicked()
{
    if( getColdW()>getHotW() || getColdW()>getExpectTempM() || getHotW()<getExpectTempM() ) return;
    double* ColdHot = calculateProportions( getColdW(), getHotW(), getExpectTempM() );
    ui->labelColdRes->setText( QString::number(ColdHot[0]) );
    ui->labelHotRes->setText( QString::number(ColdHot[1]) );
}

double MainWindow::getExpectTempM()
{
    return ui->spinBoxExpM->value();
}

double MainWindow::getColdW()
{
    return ui->spinBoxColdW->value();
}

double MainWindow::getHotW()
{
    return ui->spinBoxHotW->value();
}
