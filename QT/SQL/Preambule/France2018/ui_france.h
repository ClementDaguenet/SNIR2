/********************************************************************************
** Form generated from reading UI file 'france.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRANCE_H
#define UI_FRANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_France
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Connexion;
    QPushButton *pushButton_Quitter;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Nom;
    QLineEdit *lineEdit_Nom;
    QPushButton *pushButton_Nom;
    QLineEdit *lineEdit_Resultat;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_Regions;
    QComboBox *comboBox_Departements;
    QComboBox *comboBox_Villes;

    void setupUi(QWidget *France)
    {
        if (France->objectName().isEmpty())
            France->setObjectName(QString::fromUtf8("France"));
        France->resize(563, 272);
        France->setStyleSheet(QString::fromUtf8("background-color: #101010"));
        layoutWidget = new QWidget(France);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 541, 224));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Connexion = new QPushButton(layoutWidget);
        pushButton_Connexion->setObjectName(QString::fromUtf8("pushButton_Connexion"));
        pushButton_Connexion->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_2->addWidget(pushButton_Connexion);

        pushButton_Quitter = new QPushButton(layoutWidget);
        pushButton_Quitter->setObjectName(QString::fromUtf8("pushButton_Quitter"));
        pushButton_Quitter->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_2->addWidget(pushButton_Quitter);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Nom = new QLabel(layoutWidget);
        label_Nom->setObjectName(QString::fromUtf8("label_Nom"));
        label_Nom->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));

        horizontalLayout->addWidget(label_Nom);

        lineEdit_Nom = new QLineEdit(layoutWidget);
        lineEdit_Nom->setObjectName(QString::fromUtf8("lineEdit_Nom"));
        lineEdit_Nom->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));

        horizontalLayout->addWidget(lineEdit_Nom);

        pushButton_Nom = new QPushButton(layoutWidget);
        pushButton_Nom->setObjectName(QString::fromUtf8("pushButton_Nom"));
        pushButton_Nom->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));

        horizontalLayout->addWidget(pushButton_Nom);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit_Resultat = new QLineEdit(layoutWidget);
        lineEdit_Resultat->setObjectName(QString::fromUtf8("lineEdit_Resultat"));
        lineEdit_Resultat->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold; font-style: italic;"));
        lineEdit_Resultat->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_Resultat);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_Regions = new QComboBox(layoutWidget);
        comboBox_Regions->addItem(QString());
        comboBox_Regions->setObjectName(QString::fromUtf8("comboBox_Regions"));
        comboBox_Regions->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));

        horizontalLayout_3->addWidget(comboBox_Regions);

        comboBox_Departements = new QComboBox(layoutWidget);
        comboBox_Departements->addItem(QString());
        comboBox_Departements->setObjectName(QString::fromUtf8("comboBox_Departements"));
        comboBox_Departements->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));

        horizontalLayout_3->addWidget(comboBox_Departements);

        comboBox_Villes = new QComboBox(layoutWidget);
        comboBox_Villes->addItem(QString());
        comboBox_Villes->setObjectName(QString::fromUtf8("comboBox_Villes"));
        comboBox_Villes->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));

        horizontalLayout_3->addWidget(comboBox_Villes);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(France);
        QObject::connect(pushButton_Quitter, &QPushButton::clicked, France, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(France);
    } // setupUi

    void retranslateUi(QWidget *France)
    {
        France->setWindowTitle(QCoreApplication::translate("France", "France", nullptr));
        pushButton_Connexion->setText(QCoreApplication::translate("France", "Connexion", nullptr));
        pushButton_Quitter->setText(QCoreApplication::translate("France", "Quitter", nullptr));
        label_Nom->setText(QCoreApplication::translate("France", "Donnez le num\303\251ro du d\303\251partement", nullptr));
        pushButton_Nom->setText(QCoreApplication::translate("France", "Nom de ce d\303\251partement ?", nullptr));
        lineEdit_Resultat->setText(QCoreApplication::translate("France", "Nom du d\303\251partement", nullptr));
        comboBox_Regions->setItemText(0, QCoreApplication::translate("France", "Choisissez une r\303\251gion", nullptr));

        comboBox_Regions->setCurrentText(QCoreApplication::translate("France", "Choisissez une r\303\251gion", nullptr));
        comboBox_Departements->setItemText(0, QCoreApplication::translate("France", "Choisissez un d\303\251partement", nullptr));

        comboBox_Villes->setItemText(0, QCoreApplication::translate("France", "Choisissez une ville", nullptr));

    } // retranslateUi

};

namespace Ui {
    class France: public Ui_France {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRANCE_H
