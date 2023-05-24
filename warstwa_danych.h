#ifndef DANE_H
#define DANE_H

#include "text_holder.h"
#include "dodajwpis.h"

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>>
#include <iostream>
#include <QKeyEvent>
#include <QMoveEvent>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QSinglePointEvent>
#include <QPoint>

class Dane
{
public:
    Dane();
    void SelectFiles();
    void AddMemory(QString data, QString tekst, int);
    void AddFavourites(int);
    Text_Holder Get_Index(int);
    QList<Text_Holder> Get_Index_klasyfikacja(int);
    int ListaSize();
    int ListaKlasyfikacjaSize();
    QList<Text_Holder> GetListaFav();
    Text_Holder FindFromList(QString);
    void Destroy(int);
    void MakeCopy();
    void ReadCopy();
private:
    QList<Text_Holder> m_lista_napis;
    QList<Text_Holder> m_lista_napis_fav;
    QList<Text_Holder> m_lista_klasyfikacja;
    QString m_alldane;
    QFile m_MyFile;
    QFile m_MyFile_Favourite;
    QFile m_MyFile_Copy;
    void fileSelected();
};

#endif // DANE_H
