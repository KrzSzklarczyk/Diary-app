#ifndef DODAJWPIS_H
#define DODAJWPIS_H

#include <QDialog>
#include <QMainWindow>
#include <QFile>
#include <iostream>

namespace Ui {
class DodajWpis;
}

class DodajWpis : public QDialog
{
    Q_OBJECT

public:
    explicit DodajWpis(QWidget *parent = nullptr);
    ~DodajWpis();
    QString GetNapis();
    QString GetData();
    int GetTyp();
    void SetNapis(QString napis);
    void SetData(QString data);
    void SetTyp(int i);
private slots:
    void on_pushButton_Dodaj_clicked();
    void on_pushButton_2_clicked();
    void on_checkBox_Smutny_stateChanged(int arg1);
    void on_checkBox_Neutralny_stateChanged(int arg1);
    void on_checkBox_Radosny_stateChanged(int arg1);
private:
    Ui::DodajWpis *ui;
    QString m_napis;
    QString m_data;
    int m_typ;
};

#endif // DODAJWPIS_H
