#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "text_holder.h"
#include "warstwa_uslug.h"
#include "warstwa_danych.h"
#include "dodajwpis.h"
#include <QMainWindow>
#include <QFile>
#include <iostream>
#include <QKeyEvent>
#include <QMoveEvent>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QSinglePointEvent>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui = nullptr;
    Usluga usluga;
    QPoint m_prevPosition;
    QPoint m_currentPosition;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void on_mouse_event(const QString &eventName, const QPoint &pos);
public slots:
    void on_PushButton_Zapisz_clicked();
    void on_pushButton_Up_clicked();
    void on_pushButton_Down_clicked();
    void on_pushButton_Usun_clicked();
    void on_pushButton_Ulubione_clicked();
    void on_pushButton_Szukaj_clicked();
public:
    MainWindow(QWidget *parent = nullptr, Usluga *us = nullptr);
    ~MainWindow();
    void set_tekst_fav(QList<Text_Holder>);
    void keyPressEvent(QKeyEvent *) override;
    void closeEvent(QCloseEvent*) override;
    void set_tekst_GUI(int i);
private slots:
    void on_pushButton_ZapiszPlik_clicked();
    void on_pushButton_WczytajPlik_clicked();
    void on_checkBox_Smutny_stateChanged(int arg1);
    void on_checkBox_Smutny_clicked(bool checked);
    void on_checkBox_Radosny_clicked(bool checked);
    void on_checkBox_Neutralny_clicked(bool checked);
};
#endif // MAINWINDOW_H
