#include "warstwa_uslug.h"
#include "mainwindow.h"
#include "qdebug.h"

Usluga::Usluga(QObject *parent) : QObject(parent) {}

void Usluga::UploadFiles()
{
    //Dane dane;
    m_dane.SelectFiles();
}

void Usluga::Write()
{
    m_okno = new DodajWpis(nullptr);
    m_okno->exec();
    QString tekst;
    tekst = m_okno->GetNapis();
    QString data;
    data = m_okno->GetData();
    int typ;
    typ = m_okno->GetTyp();

    delete m_okno;
    m_dane.AddMemory(data, tekst, typ);
}

void Usluga::WriteFavourites(int index)
{
    int i = index;
    m_dane.AddFavourites(i);
}
Text_Holder Usluga::current_index(int i)
{
    int index = i;
    Text_Holder dane = m_dane.Get_Index(index);
    return dane;
}

int Usluga::ListSize()
{
    int size = m_dane.ListaSize();
    return size;
}

QList<Text_Holder> Usluga::ReadFavourites()
{
    QList<Text_Holder> lista = m_dane.GetListaFav();
    return lista;
}

Text_Holder Usluga::Finder(QString tekst)
{
    return m_dane.FindFromList(tekst);
}

void Usluga::Delete(int i)
{
    m_dane.Destroy(i);
}

void Usluga::Copy()
{
    m_dane.MakeCopy();
}

void Usluga::GetCopy()
{
    m_dane.ReadCopy();
}

int Usluga::ListKlasyfikacjaSize()
{
    return m_dane.ListaKlasyfikacjaSize();
}

QList<Text_Holder> Usluga::current_index_klasyfikacja(int typ)
{
    return m_dane.Get_Index_klasyfikacja(typ);
}
