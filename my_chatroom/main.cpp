#include "mainwindow.h"
#include <QApplication>
#include <my_lib/mylib.h>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout<<"version information:";
#ifdef DEBUG
    std::cout<<"debug version"<<std::endl;
 #endif
    return a.exec();
}
