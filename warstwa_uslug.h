#ifndef USLUGA_H
#define USLUGA_H

#include <QObject>
#include "warstwa_danych.h"
#include "dodajwpis.h"
#include <QFileDialog>>
#include <QFile>

class MainWindow;

class Dane;

class Usluga : public QObject
{
public:
    explicit Usluga(QObject *parent = nullptr);
    void UploadFiles();
    void Write();
    void WriteFavourites(int index);
    QList<Text_Holder> ReadFavourites();
    Text_Holder Finder(QString);
    Text_Holder current_index(int);
    int ListSize();
    int ListKlasyfikacjaSize();
    void Delete(int);
    void Copy();
    void GetCopy();
    QList<Text_Holder> current_index_klasyfikacja(int);
private:
    MainWindow *GUI= nullptr;
    DodajWpis *m_okno;
    Dane m_dane;
};

#endif // USLUGA_H
