#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <iostream>
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include <fstream> //for file-stream functions
#include <iostream>

QMap<QString, QString> LoginWindow::passwordManager;
User* LoginWindow::userList[100];
int LoginWindow::n = 0;

int main(int argc, char *argv[])
{
    srand ( time(NULL) );
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("NOTEBOX");
    w.show();
    return a.exec();
}
