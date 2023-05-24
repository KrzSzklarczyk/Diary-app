#include "warstwa_danych.h"

Dane::Dane() {}

Text_Holder Dane::Get_Index(int i)
{
    return m_lista_napis[i];
}

QList<Text_Holder> Dane::Get_Index_klasyfikacja(int i)
{
    m_lista_klasyfikacja.clear();
    for(int i=0; i<m_lista_napis.size(); i++)
    {
        if(m_lista_napis[i].GetTyp()==Typ::Smutne)
            m_lista_klasyfikacja.push_back(m_lista_napis[i]);
        else if(m_lista_napis[i].GetTyp()==Typ::Neutralne)
            m_lista_klasyfikacja.push_back(m_lista_napis[i]);
        else if(m_lista_napis[i].GetTyp()==Typ::Radosne)
            m_lista_klasyfikacja.push_back(m_lista_napis[i]);
    }
    return m_lista_klasyfikacja;
}

int Dane::ListaSize()
{
    return m_lista_napis.size();
}

int Dane::ListaKlasyfikacjaSize()
{
    return m_lista_klasyfikacja.size();
}

void Dane::SelectFiles()
{
    QString in_fileName = "Wspomnienia.txt";
    static QString fileName = "";
    if(!in_fileName.isEmpty())
        fileName = in_fileName;
    bool noEmpty = !fileName.isEmpty();
    if(noEmpty)
    {
        m_MyFile.setFileName(fileName);
        //ui->statusBar->showMessage("Plik ustawiony");
        qDebug() << "Plik ustawiony";
    }
    else
    {
        //ui->statusBar->showMessage("Brak pliku");
        qDebug() << "Brak pliku";
    }

    m_MyFile.close();
    m_lista_napis.clear();
    m_lista_napis_fav.clear();

    if(m_MyFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&m_MyFile);
        while(!inStream.atEnd())
        {
            QString line = inStream.readLine();
            if(!line.contains(";"))
            {
                continue;
            }

            QList<QString> split = line.split(';');
            Text_Holder text(split[0], split[1]);
            QString typ = split[2];
            if(typ == '0')
                text.SetTyp(Typ::Smutne);
            else if(typ=='1')
                text.SetTyp(Typ::Neutralne);
            else
                text.SetTyp(Typ::Radosne);
            m_lista_napis.push_back(text);
        }
        //ui->statusBar->showMessage("Odczytano tekst");
        qDebug() << "Odczytano tekst";
        m_MyFile.close();
    }
    //else ui->statusBar->showMessage("Bład otwarcia pliku!");
    else qDebug() << "Bład otwarcia pliku!";

    QString sciezka = "Ulubione.txt";
    m_MyFile_Favourite.setFileName(sciezka);
    if(m_MyFile_Favourite.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&m_MyFile_Favourite);
        while(!inStream.atEnd())
        {
            QString line = inStream.readLine();
            if(!line.contains(";"))
            {
                continue;
            }

            QList<QString> split = line.split(';');
            Text_Holder text(split[0], split[1]);
            m_lista_napis_fav.push_back(text);
        }
        //ui->statusBar->showMessage("Odczytano tekst");
        qDebug() << "Odczytano tekst ulubionych";
        m_MyFile_Favourite.close();
    }
    //else ui->statusBar->showMessage("Bład otwarcia pliku!");
    else qDebug() << "Bład otwarcia pliku!";
}

void Dane::AddMemory(QString data, QString tekst, int i)
{
    m_MyFile.close();
    //QString in_fileName = "Wspomnienia.txt";
    //m_MyFile.setFileName(in_fileName);
    if(m_MyFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream outStream(&m_MyFile);
        qDebug() << "dziala";
        Text_Holder text(data, tekst);
        text.SetTyp(Typ(i));

        m_lista_napis.push_back(text);
        std::sort(m_lista_napis.begin(), m_lista_napis.end());

        for(Text_Holder& text : m_lista_napis)
        {
        outStream << text.GetData();
        outStream << ";";
        outStream << text.GetNapis();
        outStream << ";";
        outStream << (int)text.GetTyp();
        outStream << "\n";
        }

        qDebug() << "Zapisano tekst!";//ui->statusBar->showMessage("Zapisano tekst");
        m_MyFile.close();
        //set_tekst_GUI(++current_index);

    }
    else qDebug() << "Bład otwarcia plikku!"; //ui->statusBar->showMessage("Bład otwarcia pliku!");
}

void Dane::AddFavourites(int current_index)
{
    m_MyFile_Favourite.close();
    if(m_MyFile_Favourite.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream outStream(&m_MyFile_Favourite);
        qDebug() << "dziala";
        QString tekst;
        tekst = m_lista_napis[current_index].GetNapis();
        QString data;
        data = m_lista_napis[current_index].GetData();
        Text_Holder text(data, tekst);
        Typ t = m_lista_napis[current_index].GetTyp();
        m_lista_napis_fav.push_back(text);
        std::sort(m_lista_napis_fav.begin(), m_lista_napis_fav.end());

        for(Text_Holder& text : m_lista_napis_fav)
        {
        outStream << text.GetData();
        outStream << ";";
        outStream << text.GetNapis();
        outStream << "\n";
        }

        qDebug() << "Zapisano ulubiony tekst!";
        m_MyFile_Favourite.close();

    }
    else qDebug() << "Bład otwarcia ulubionego plikku!";
}

QList<Text_Holder> Dane::GetListaFav()
{
    return m_lista_napis_fav;
}

Text_Holder Dane::FindFromList(QString tekst)
{
    m_MyFile.close();
       if(m_MyFile.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           QTextStream inStream(&m_MyFile);
           while(!inStream.atEnd())
           {
               QString line = inStream.readLine();
               if(line.contains(tekst))
               {
                   QList<QString> split = line.split(';');
                   Text_Holder text(split[0], split[1]);
                   return text;
               }
           }
           qDebug() << "Odczytano szukany tekst!";
           m_MyFile.close();
       }
       else qDebug() << "Nie udalo sie odczytac szukanego tekst!";
}

void Dane::Destroy(int index)
{
    m_lista_napis.removeAt(index);
}

void Dane::MakeCopy()
{
    m_MyFile.close();
    QString in_fileName;
    in_fileName = QFileDialog::getOpenFileName();
    static QString fileName = "";
    if(!in_fileName.isEmpty())
    fileName = in_fileName;
    bool noEmpty = !fileName.isEmpty();
    if(noEmpty)
    {
    qDebug() << fileName;
    m_MyFile.setFileName(fileName);
    qDebug() << "Plik do kopii ustawiony!";
    }
    else
    {
    qDebug() << "Nie udalo sie ustawic pliku do kopii";
    }

    if(m_MyFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream outStream(&m_MyFile);
        qDebug() << "dziala";

        std::sort(m_lista_napis.begin(), m_lista_napis.end());

        for(Text_Holder& text : m_lista_napis)
        {
        outStream << text.GetData();
        outStream << ";";
        outStream << text.GetNapis();
        outStream << "\n";
        outStream << (int)text.GetTyp();
        outStream << "\n";
        }

        qDebug() << "Zapisano tekst!";
        m_MyFile.close();
    }
    else qDebug() << "Bład otwarcia plikku!";
}

void Dane::ReadCopy()
{
    m_MyFile.close();
    QString in_fileName;
    in_fileName = QFileDialog::getOpenFileName();
    static QString fileName = "";
    if(!in_fileName.isEmpty())
    fileName = in_fileName;
    bool noEmpty = !fileName.isEmpty();
    if(noEmpty)
    {
    qDebug() << fileName;
    m_MyFile.setFileName(fileName);
    qDebug() << "Plik do kopii ustawiony!";
    }
    else
    {
    qDebug() << "Nie udalo sie ustawic pliku do kopii";
    }

    if(m_MyFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&m_MyFile);
        while(!inStream.atEnd())
        {
            QString line = inStream.readLine();
            if(!line.contains(";"))
            {
                continue;
            }

            QList<QString> split = line.split(';');
            Text_Holder text(split[0], split[1]);
            QString typ = split[2];
            if(typ == '0')
                text.SetTyp(Typ::Smutne);
            else if(typ=='1')
                text.SetTyp(Typ::Neutralne);
            else
                text.SetTyp(Typ::Radosne);
            m_lista_napis.push_back(text);
        }
        //ui->statusBar->showMessage("Odczytano tekst");
        qDebug() << "Odczytano tekst";
        m_MyFile.close();
    }
}
