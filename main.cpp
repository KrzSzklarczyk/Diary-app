#include "mainwindow.h"
#include "warstwa_uslug.h"
#include "warstwa_danych.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QObject>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dane dane;
    Usluga usluga;
    MainWindow window(nullptr,&usluga);
    window.show();
    return a.exec();
}
