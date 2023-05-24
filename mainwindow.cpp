#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "text_holder.h"
#include <algorithm>
#include <qdebug.h>
#include <QList>
#include <QFileDialog>
#include <QTextStream>
#include <QColor>
static int current_index;
MainWindow::MainWindow(QWidget *parent, Usluga *us)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      usluga(us)
{
    ui->setupUi(this);    
    usluga.UploadFiles();
    set_tekst_GUI(0);
    set_tekst_fav(usluga.ReadFavourites());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_Zapisz_clicked()
{
    usluga.Write();
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    m_prevPosition = event->pos();
    qDebug() << "nacisniecie";
}
void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
    qDebug() << "ruch";
    m_currentPosition = event->pos();
}
void MainWindow::mouseReleaseEvent(QMouseEvent * event)
{
    qDebug() << "puszczony";
    on_mouse_event("ruch", m_currentPosition);
}
void MainWindow::on_mouse_event(const QString &eventName, const QPoint &pos)
{
    if(m_currentPosition.y() - m_prevPosition.y() > 0)
        {
            on_pushButton_Down_clicked();
        }
        else
            on_pushButton_Up_clicked();
}


void MainWindow::set_tekst_fav(QList<Text_Holder> m_lista_napis_fav)
{
    ui->textEdit_Ulubione->clear();

    for(Text_Holder& text : m_lista_napis_fav)
    {
        ui->textEdit_Ulubione->setFontWeight(1000);
        ui->textEdit_Ulubione->insertPlainText(text.GetData());
        ui->textEdit_Ulubione->insertPlainText("\n");
        ui->textEdit_Ulubione->setFontWeight(200);
        ui->textEdit_Ulubione->insertPlainText(text.GetNapis());
        ui->textEdit_Ulubione->insertPlainText("\n");
    }
}

void MainWindow::on_pushButton_Ulubione_clicked()
{
    usluga.WriteFavourites(current_index);
    set_tekst_fav(usluga.ReadFavourites());
}

void MainWindow::on_pushButton_Up_clicked()
{
     current_index++;
     set_tekst_GUI(current_index);
}

void MainWindow::on_pushButton_Down_clicked()
{
    if(current_index>0)
     current_index--;
     set_tekst_GUI(current_index);
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    Q_UNUSED(event);
}

void MainWindow::set_tekst_GUI(int i)
{
    std::array <QString, 3> TAB_TYP;
    TAB_TYP[0] = "Smutny";
    TAB_TYP[1] = "Neutralny";
    TAB_TYP[2] = "Radosny";

    if(i>0 && i<usluga.ListSize() - 1)
    {
        ui->pushButton_Down->setEnabled(1);
        ui->pushButton_Up->setEnabled(1);
        ui->WypiszText_Aktualny->clear();
        ui->WypiszText_Poprzedzajacy->clear();
        ui->WypiszText_Nastepujacy->clear();
        ui->WypiszText_Aktualny->setFontWeight(1000);
        ui->WypiszText_Aktualny->insertPlainText(usluga.current_index(i).GetData());
        ui->WypiszText_Aktualny->insertPlainText("  ");
        ui->WypiszText_Aktualny->insertPlainText(TAB_TYP[(int)usluga.current_index(i).GetTyp()]);
        ui->WypiszText_Aktualny->insertPlainText("\n");
        ui->WypiszText_Aktualny->setFontWeight(200);
        ui->WypiszText_Aktualny->insertPlainText(usluga.current_index(i).GetNapis());
        ui->WypiszText_Aktualny->insertPlainText("\n");
        ui->WypiszText_Poprzedzajacy->setFontUnderline(0);
        ui->WypiszText_Poprzedzajacy->setFontItalic(0);
        ui->WypiszText_Poprzedzajacy->setFontWeight(1000);
        ui->WypiszText_Poprzedzajacy->insertPlainText(usluga.current_index(i-1).GetData());
        ui->WypiszText_Poprzedzajacy->insertPlainText("  ");
        ui->WypiszText_Poprzedzajacy->insertPlainText(TAB_TYP[(int)usluga.current_index(i-1).GetTyp()]);
        ui->WypiszText_Poprzedzajacy->insertPlainText("\n");
        ui->WypiszText_Poprzedzajacy->setFontWeight(200);
        ui->WypiszText_Poprzedzajacy->insertPlainText(usluga.current_index(i-1).GetNapis());
        ui->WypiszText_Poprzedzajacy->insertPlainText("\n");
        ui->WypiszText_Nastepujacy->setFontUnderline(0);
        ui->WypiszText_Nastepujacy->setFontItalic(0);
        ui->WypiszText_Nastepujacy->setFontWeight(1000);
        ui->WypiszText_Nastepujacy->insertPlainText(usluga.current_index(i+1).GetData());
        ui->WypiszText_Nastepujacy->insertPlainText("  ");
        ui->WypiszText_Nastepujacy->insertPlainText(TAB_TYP[(int)usluga.current_index(i+1).GetTyp()]);
        ui->WypiszText_Nastepujacy->insertPlainText("\n");
        ui->WypiszText_Nastepujacy->setFontWeight(200);
        ui->WypiszText_Nastepujacy->insertPlainText(usluga.current_index(i+1).GetNapis());
        ui->WypiszText_Nastepujacy->insertPlainText("\n");
    }
    else if(i == 0)
    {
        ui->pushButton_Down->setEnabled(0);
        ui->WypiszText_Aktualny->clear();
        ui->WypiszText_Poprzedzajacy->clear();
        ui->WypiszText_Nastepujacy->clear();
        ui->WypiszText_Aktualny->setFontWeight(1000);
        ui->WypiszText_Aktualny->insertPlainText(usluga.current_index(i).GetData());
        ui->WypiszText_Aktualny->insertPlainText("  ");
        ui->WypiszText_Aktualny->insertPlainText(TAB_TYP[(int)usluga.current_index(i).GetTyp()]);
        ui->WypiszText_Aktualny->insertPlainText("\n");
        ui->WypiszText_Aktualny->setFontWeight(200);
        ui->WypiszText_Aktualny->insertPlainText(usluga.current_index(i).GetNapis());
        ui->WypiszText_Aktualny->insertPlainText("\n");
        ui->WypiszText_Poprzedzajacy->setFontUnderline(1);
        ui->WypiszText_Poprzedzajacy->setFontItalic(1);
        ui->WypiszText_Poprzedzajacy->setFontWeight(2000);
        ui->WypiszText_Poprzedzajacy->insertPlainText("Brak wspomnienia");
        ui->WypiszText_Nastepujacy->setFontWeight(1000);
        ui->WypiszText_Nastepujacy->insertPlainText(usluga.current_index(i+1).GetData());
        ui->WypiszText_Nastepujacy->insertPlainText("  ");
        ui->WypiszText_Nastepujacy->insertPlainText(TAB_TYP[(int)usluga.current_index(i+1).GetTyp()]);
        ui->WypiszText_Nastepujacy->insertPlainText("\n");
        ui->WypiszText_Nastepujacy->setFontWeight(200);
        ui->WypiszText_Nastepujacy->insertPlainText(usluga.current_index(i+1).GetNapis());
        ui->WypiszText_Nastepujacy->insertPlainText("\n");
    }
    else if(i == usluga.ListSize() - 1)
    {
        ui->pushButton_Up->setEnabled(0);
        ui->WypiszText_Aktualny->clear();
        ui->WypiszText_Poprzedzajacy->clear();
        ui->WypiszText_Nastepujacy->clear();
        ui->WypiszText_Aktualny->setFontWeight(1000);
        ui->WypiszText_Aktualny->insertPlainText(usluga.current_index(i).GetData());
        ui->WypiszText_Aktualny->insertPlainText("  ");
        ui->WypiszText_Aktualny->insertPlainText(TAB_TYP[(int)usluga.current_index(i).GetTyp()]);
        ui->WypiszText_Aktualny->insertPlainText("\n");
        ui->WypiszText_Aktualny->setFontWeight(200);
        ui->WypiszText_Aktualny->insertPlainText(usluga.current_index(i).GetNapis());
        ui->WypiszText_Aktualny->insertPlainText("\n");
        ui->WypiszText_Poprzedzajacy->setFontWeight(1000);
        ui->WypiszText_Poprzedzajacy->insertPlainText(usluga.current_index(i-1).GetData());
        ui->WypiszText_Poprzedzajacy->insertPlainText("  ");
        ui->WypiszText_Poprzedzajacy->insertPlainText(TAB_TYP[(int)usluga.current_index(i-1).GetTyp()]);
        ui->WypiszText_Poprzedzajacy->insertPlainText("\n");
        ui->WypiszText_Poprzedzajacy->setFontWeight(200);
        ui->WypiszText_Poprzedzajacy->insertPlainText(usluga.current_index(i-1).GetNapis());
        ui->WypiszText_Poprzedzajacy->insertPlainText("\n");
        ui->WypiszText_Nastepujacy->setFontWeight(1000);
        ui->WypiszText_Nastepujacy->setFontUnderline(1);
        ui->WypiszText_Nastepujacy->setFontItalic(1);
        ui->WypiszText_Nastepujacy->insertPlainText("Brak wspomnienia");
    }
}

void MainWindow::on_pushButton_Szukaj_clicked()
{
       ui->textEdit_ZnalezioneZdanie->clear();
       QString Szukane = ui->textEdit_SzukaneSlowo->toPlainText();
       Text_Holder Wyszukany = usluga.Finder(Szukane);
       ui->textEdit_ZnalezioneZdanie->setFontWeight(1000);
       ui->textEdit_ZnalezioneZdanie->insertPlainText(Wyszukany.GetData());
       ui->textEdit_ZnalezioneZdanie->setFontWeight(200);
       ui->textEdit_ZnalezioneZdanie->insertPlainText(Wyszukany.GetNapis());
       ui->textEdit_ZnalezioneZdanie->insertPlainText("\n");
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    int keyCode = event->key();
    if(keyCode == Qt::Key_Up)
    {
        on_pushButton_Up_clicked();;
        qDebug() << "up";
    }
    else if(keyCode == Qt::Key_Down)
    {
        qDebug() << "down";
        current_index--;
        set_tekst_GUI(current_index);
    }
}

void MainWindow::on_pushButton_Usun_clicked()
{
    usluga.Delete(current_index);
    set_tekst_GUI(current_index);
}

void MainWindow::on_pushButton_ZapiszPlik_clicked()
{
    usluga.Copy();
}


void MainWindow::on_pushButton_WczytajPlik_clicked()
{
    usluga.GetCopy();
    set_tekst_GUI(0);
}


void MainWindow::on_checkBox_Smutny_stateChanged(int arg1)
{

}


void MainWindow::on_checkBox_Smutny_clicked(bool checked)
{
    QList<Text_Holder> lista = usluga.current_index_klasyfikacja(0);
    ui->WypiszText_Poprzedzajacy->clear();
    for(int i = 0; i<usluga.ListKlasyfikacjaSize(); i++)
    {
        ui->WypiszText_Poprzedzajacy->insertPlainText("\n");
        ui->WypiszText_Poprzedzajacy->setFontWeight(1000);
        ui->WypiszText_Poprzedzajacy->insertPlainText(lista[i].GetData());
        ui->WypiszText_Poprzedzajacy->insertPlainText("  ");
        ui->WypiszText_Poprzedzajacy->insertPlainText("  ");
        ui->WypiszText_Poprzedzajacy->setFontWeight(200);
        ui->WypiszText_Poprzedzajacy->insertPlainText(lista[i].GetNapis());
        ui->WypiszText_Poprzedzajacy->insertPlainText("\n");
    }
}
void MainWindow::on_checkBox_Radosny_clicked(bool checked)
{
    QList<Text_Holder> lista = usluga.current_index_klasyfikacja(2);
    ui->WypiszText_Poprzedzajacy->clear();
    for(int i = 0; i<usluga.ListKlasyfikacjaSize(); i++)
    {
        ui->WypiszText_Nastepujacy->insertPlainText("\n");
        ui->WypiszText_Nastepujacy->setFontWeight(1000);
        ui->WypiszText_Nastepujacy->insertPlainText(lista[i].GetData());
        ui->WypiszText_Nastepujacy->insertPlainText("  ");
        ui->WypiszText_Nastepujacy->insertPlainText("  ");
        ui->WypiszText_Nastepujacy->setFontWeight(200);
        ui->WypiszText_Nastepujacy->insertPlainText(lista[i].GetNapis());
        ui->WypiszText_Nastepujacy->insertPlainText("\n");
    }
}
void MainWindow::on_checkBox_Neutralny_clicked(bool checked)
{
    QList<Text_Holder> lista = usluga.current_index_klasyfikacja(1);
    ui->WypiszText_Poprzedzajacy->clear();
    for(int i = 0; i<usluga.ListKlasyfikacjaSize(); i++)
    {
        ui->WypiszText_Aktualny->insertPlainText("\n");
        ui->WypiszText_Aktualny->setFontWeight(1000);
        ui->WypiszText_Aktualny->insertPlainText(lista[i].GetData());
        ui->WypiszText_Aktualny->insertPlainText("  ");
        ui->WypiszText_Aktualny->insertPlainText("  ");
        ui->WypiszText_Aktualny->setFontWeight(200);
        ui->WypiszText_Aktualny->insertPlainText(lista[i].GetNapis());
        ui->WypiszText_Aktualny->insertPlainText("\n");
    }
}




