/********************************************************************************
** Form generated from reading UI file 'dodajwpis.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJWPIS_H
#define UI_DODAJWPIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DodajWpis
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Dodaj;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_Wpisztext;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_Smutny;
    QCheckBox *checkBox_Neutralny;
    QCheckBox *checkBox_Radosny;

    void setupUi(QDialog *DodajWpis)
    {
        if (DodajWpis->objectName().isEmpty())
            DodajWpis->setObjectName(QString::fromUtf8("DodajWpis"));
        DodajWpis->resize(824, 397);
        gridLayout = new QGridLayout(DodajWpis);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Dodaj = new QPushButton(DodajWpis);
        pushButton_Dodaj->setObjectName(QString::fromUtf8("pushButton_Dodaj"));

        gridLayout->addWidget(pushButton_Dodaj, 6, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(DodajWpis);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(DodajWpis);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 0, 1, 1);

        textEdit_Wpisztext = new QTextEdit(DodajWpis);
        textEdit_Wpisztext->setObjectName(QString::fromUtf8("textEdit_Wpisztext"));

        gridLayout->addWidget(textEdit_Wpisztext, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_Smutny = new QCheckBox(DodajWpis);
        checkBox_Smutny->setObjectName(QString::fromUtf8("checkBox_Smutny"));

        horizontalLayout->addWidget(checkBox_Smutny);

        checkBox_Neutralny = new QCheckBox(DodajWpis);
        checkBox_Neutralny->setObjectName(QString::fromUtf8("checkBox_Neutralny"));

        horizontalLayout->addWidget(checkBox_Neutralny);

        checkBox_Radosny = new QCheckBox(DodajWpis);
        checkBox_Radosny->setObjectName(QString::fromUtf8("checkBox_Radosny"));

        horizontalLayout->addWidget(checkBox_Radosny);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);


        retranslateUi(DodajWpis);

        QMetaObject::connectSlotsByName(DodajWpis);
    } // setupUi

    void retranslateUi(QDialog *DodajWpis)
    {
        DodajWpis->setWindowTitle(QCoreApplication::translate("DodajWpis", "Dialog", nullptr));
        pushButton_Dodaj->setText(QCoreApplication::translate("DodajWpis", "Dodaj", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DodajWpis", "Anuluj", nullptr));
        checkBox_Smutny->setText(QCoreApplication::translate("DodajWpis", "Smutny", nullptr));
        checkBox_Neutralny->setText(QCoreApplication::translate("DodajWpis", "Neutralny", nullptr));
        checkBox_Radosny->setText(QCoreApplication::translate("DodajWpis", "Radosny", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DodajWpis: public Ui_DodajWpis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJWPIS_H
