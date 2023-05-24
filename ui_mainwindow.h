/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_Smutny;
    QCheckBox *checkBox_Neutralny;
    QCheckBox *checkBox_Radosny;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_Down;
    QPushButton *pushButton_Up;
    QPushButton *pushButton_Usun;
    QPushButton *PushButton_Zapisz;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Szukaj;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_SzukaneSlowo;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit_ZnalezioneZdanie;
    QVBoxLayout *verticalLayout;
    QTextEdit *WypiszText_Poprzedzajacy;
    QTextEdit *WypiszText_Aktualny;
    QTextEdit *WypiszText_Nastepujacy;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Ulubione;
    QTextEdit *textEdit_Ulubione;
    QPushButton *pushButton_WczytajPlik;
    QPushButton *pushButton_ZapiszPlik;
    QPushButton *pushButton_test;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(850, 489);
        QFont font;
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setFocusPolicy(Qt::StrongFocus);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_Smutny = new QCheckBox(centralwidget);
        checkBox_Smutny->setObjectName(QString::fromUtf8("checkBox_Smutny"));

        horizontalLayout->addWidget(checkBox_Smutny);

        checkBox_Neutralny = new QCheckBox(centralwidget);
        checkBox_Neutralny->setObjectName(QString::fromUtf8("checkBox_Neutralny"));

        horizontalLayout->addWidget(checkBox_Neutralny);

        checkBox_Radosny = new QCheckBox(centralwidget);
        checkBox_Radosny->setObjectName(QString::fromUtf8("checkBox_Radosny"));

        horizontalLayout->addWidget(checkBox_Radosny);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(13);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_4->addWidget(textEdit);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_Down = new QPushButton(centralwidget);
        pushButton_Down->setObjectName(QString::fromUtf8("pushButton_Down"));
        pushButton_Down->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_2->addWidget(pushButton_Down);

        pushButton_Up = new QPushButton(centralwidget);
        pushButton_Up->setObjectName(QString::fromUtf8("pushButton_Up"));
        pushButton_Up->setMouseTracking(false);
        pushButton_Up->setTabletTracking(false);
        pushButton_Up->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_2->addWidget(pushButton_Up);

        pushButton_Usun = new QPushButton(centralwidget);
        pushButton_Usun->setObjectName(QString::fromUtf8("pushButton_Usun"));

        verticalLayout_2->addWidget(pushButton_Usun);

        PushButton_Zapisz = new QPushButton(centralwidget);
        PushButton_Zapisz->setObjectName(QString::fromUtf8("PushButton_Zapisz"));
        PushButton_Zapisz->setEnabled(true);

        verticalLayout_2->addWidget(PushButton_Zapisz);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        gridLayout->addLayout(horizontalLayout_4, 1, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_Szukaj = new QPushButton(centralwidget);
        pushButton_Szukaj->setObjectName(QString::fromUtf8("pushButton_Szukaj"));

        horizontalLayout_3->addWidget(pushButton_Szukaj);

        horizontalSpacer_2 = new QSpacerItem(35, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        textEdit_SzukaneSlowo = new QTextEdit(centralwidget);
        textEdit_SzukaneSlowo->setObjectName(QString::fromUtf8("textEdit_SzukaneSlowo"));

        horizontalLayout_3->addWidget(textEdit_SzukaneSlowo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        textEdit_ZnalezioneZdanie = new QTextEdit(centralwidget);
        textEdit_ZnalezioneZdanie->setObjectName(QString::fromUtf8("textEdit_ZnalezioneZdanie"));

        horizontalLayout_3->addWidget(textEdit_ZnalezioneZdanie);


        gridLayout->addLayout(horizontalLayout_3, 4, 1, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WypiszText_Poprzedzajacy = new QTextEdit(centralwidget);
        WypiszText_Poprzedzajacy->setObjectName(QString::fromUtf8("WypiszText_Poprzedzajacy"));
        QFont font1;
        font1.setBold(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        WypiszText_Poprzedzajacy->setFont(font1);
        WypiszText_Poprzedzajacy->setTabChangesFocus(true);
        WypiszText_Poprzedzajacy->setReadOnly(true);
        WypiszText_Poprzedzajacy->setOverwriteMode(true);
        WypiszText_Poprzedzajacy->setAcceptRichText(true);
        WypiszText_Poprzedzajacy->setCursorWidth(0);

        verticalLayout->addWidget(WypiszText_Poprzedzajacy);

        WypiszText_Aktualny = new QTextEdit(centralwidget);
        WypiszText_Aktualny->setObjectName(QString::fromUtf8("WypiszText_Aktualny"));
        WypiszText_Aktualny->setFont(font1);
        WypiszText_Aktualny->setTabChangesFocus(true);
        WypiszText_Aktualny->setReadOnly(true);
        WypiszText_Aktualny->setOverwriteMode(true);
        WypiszText_Aktualny->setAcceptRichText(true);
        WypiszText_Aktualny->setCursorWidth(0);

        verticalLayout->addWidget(WypiszText_Aktualny);

        WypiszText_Nastepujacy = new QTextEdit(centralwidget);
        WypiszText_Nastepujacy->setObjectName(QString::fromUtf8("WypiszText_Nastepujacy"));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setStyleStrategy(QFont::PreferDefault);
        WypiszText_Nastepujacy->setFont(font2);
        WypiszText_Nastepujacy->setTabChangesFocus(true);
        WypiszText_Nastepujacy->setReadOnly(true);
        WypiszText_Nastepujacy->setOverwriteMode(true);
        WypiszText_Nastepujacy->setAcceptRichText(true);
        WypiszText_Nastepujacy->setCursorWidth(0);

        verticalLayout->addWidget(WypiszText_Nastepujacy);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Ulubione = new QPushButton(centralwidget);
        pushButton_Ulubione->setObjectName(QString::fromUtf8("pushButton_Ulubione"));

        horizontalLayout_2->addWidget(pushButton_Ulubione);

        textEdit_Ulubione = new QTextEdit(centralwidget);
        textEdit_Ulubione->setObjectName(QString::fromUtf8("textEdit_Ulubione"));
        textEdit_Ulubione->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(textEdit_Ulubione);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 2);

        pushButton_WczytajPlik = new QPushButton(centralwidget);
        pushButton_WczytajPlik->setObjectName(QString::fromUtf8("pushButton_WczytajPlik"));

        gridLayout->addWidget(pushButton_WczytajPlik, 4, 0, 1, 1);

        pushButton_ZapiszPlik = new QPushButton(centralwidget);
        pushButton_ZapiszPlik->setObjectName(QString::fromUtf8("pushButton_ZapiszPlik"));

        gridLayout->addWidget(pushButton_ZapiszPlik, 3, 0, 1, 1);

        pushButton_test = new QPushButton(centralwidget);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));

        gridLayout->addWidget(pushButton_test, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox_Smutny->setText(QCoreApplication::translate("MainWindow", "Smutny", nullptr));
        checkBox_Neutralny->setText(QCoreApplication::translate("MainWindow", "Neutralny", nullptr));
        checkBox_Radosny->setText(QCoreApplication::translate("MainWindow", "Radosny", nullptr));
        pushButton_Down->setText(QCoreApplication::translate("MainWindow", "d\303\263\305\202", nullptr));
        pushButton_Up->setText(QCoreApplication::translate("MainWindow", "g\303\263ra", nullptr));
        pushButton_Usun->setText(QCoreApplication::translate("MainWindow", "Usu\305\204", nullptr));
        PushButton_Zapisz->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        pushButton_Szukaj->setText(QCoreApplication::translate("MainWindow", "Sprawdz slowo", nullptr));
        pushButton_Ulubione->setText(QCoreApplication::translate("MainWindow", "Dodaj Do Ulubionych", nullptr));
        pushButton_WczytajPlik->setText(QCoreApplication::translate("MainWindow", "Wczytaj Plik", nullptr));
        pushButton_ZapiszPlik->setText(QCoreApplication::translate("MainWindow", "Zapisz Plik", nullptr));
        pushButton_test->setText(QCoreApplication::translate("MainWindow", "Testuj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
