#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyleSheet("QLabel{font-size: 20pt; font-weight: bold; }"
                    "QComboBox, QPushButton, QSpinBox{font-size: 20pt;}");
    w.show();
    return a.exec();
}
