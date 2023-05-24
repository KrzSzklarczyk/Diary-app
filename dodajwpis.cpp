#include "dodajwpis.h"
#include "ui_dodajwpis.h"

DodajWpis::DodajWpis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajWpis)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());
}

DodajWpis::~DodajWpis()
{
    delete ui;
}

void DodajWpis::SetTyp(int i)
{
    m_typ = i;
}

void DodajWpis::SetNapis(QString napis)
{
    m_napis = napis;
}

void DodajWpis::SetData(QString data)
{
    m_data = data;
}

QString DodajWpis::GetData()
{
    return m_data;
}

QString DodajWpis::GetNapis()
{
    return m_napis;
}

int DodajWpis::GetTyp()
{
    return m_typ;
}

void DodajWpis::on_pushButton_Dodaj_clicked()
{
    QString tekst;
    tekst = ui->textEdit_Wpisztext->toPlainText();
    SetNapis(tekst);
    QString data;
    data = ui->dateTimeEdit->text();
    SetData(data);
    if(ui->checkBox_Smutny->isChecked())
        SetTyp(0);
    else if((ui->checkBox_Neutralny->isChecked()))
        SetTyp(1);
    else
        SetTyp(2);
    close();
}


void DodajWpis::on_pushButton_2_clicked()
{
    close();
}


void DodajWpis::on_checkBox_Smutny_stateChanged(int arg1)
{
    ui->checkBox_Neutralny->setEnabled(0);
    ui->checkBox_Radosny->setEnabled(0);
}


void DodajWpis::on_checkBox_Neutralny_stateChanged(int arg1)
{
    ui->checkBox_Smutny->setEnabled(0);
    ui->checkBox_Radosny->setEnabled(0);
}


void DodajWpis::on_checkBox_Radosny_stateChanged(int arg1)
{
    ui->checkBox_Smutny->setEnabled(0);
    ui->checkBox_Neutralny->setEnabled(0);
}

