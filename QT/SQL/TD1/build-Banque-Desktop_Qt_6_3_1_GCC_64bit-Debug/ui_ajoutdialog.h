/********************************************************************************
** Form generated from reading UI file 'ajoutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTDIALOG_H
#define UI_AJOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_Nom;
    QLabel *label_Nom;
    QSpacerItem *horizontalSpace_Nom;
    QLineEdit *lineEdit_Nom;
    QHBoxLayout *horizontalLayout_Prenom;
    QLabel *label_Prenom;
    QSpacerItem *horizontalSpacer_Prenom;
    QLineEdit *lineEdit_Prenom;
    QHBoxLayout *horizontalLayout_Numero;
    QLabel *label_Numero;
    QSpacerItem *horizontalSpacer_Numero;
    QLineEdit *lineEdit_Numero;
    QHBoxLayout *horizontalLayout_Solde;
    QLabel *label_Solde;
    QSpacerItem *horizontalSpacer_Solde;
    QLineEdit *lineEdit_Solde;
    QHBoxLayout *horizontalLayout_Ville;
    QLabel *label_Ville;
    QSpacerItem *horizontalSpacer_Ville;
    QLineEdit *lineEdit_Ville;
    QHBoxLayout *horizontalLayout_Agence;
    QLabel *label_Agence;
    QComboBox *comboBox_Agence;

    void setupUi(QDialog *AjoutDialog)
    {
        if (AjoutDialog->objectName().isEmpty())
            AjoutDialog->setObjectName(QString::fromUtf8("AjoutDialog"));
        AjoutDialog->resize(306, 312);
        AjoutDialog->setStyleSheet(QString::fromUtf8("background-color: #101010"));
        buttonBox = new QDialogButtonBox(AjoutDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-50, 240, 341, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(AjoutDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 221));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 255, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_Nom = new QHBoxLayout();
        horizontalLayout_Nom->setObjectName(QString::fromUtf8("horizontalLayout_Nom"));
        label_Nom = new QLabel(layoutWidget);
        label_Nom->setObjectName(QString::fromUtf8("label_Nom"));
        label_Nom->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_Nom->addWidget(label_Nom);

        horizontalSpace_Nom = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Nom->addItem(horizontalSpace_Nom);

        lineEdit_Nom = new QLineEdit(layoutWidget);
        lineEdit_Nom->setObjectName(QString::fromUtf8("lineEdit_Nom"));
        lineEdit_Nom->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold; border: 1px inset white;"));

        horizontalLayout_Nom->addWidget(lineEdit_Nom);


        verticalLayout->addLayout(horizontalLayout_Nom);

        horizontalLayout_Prenom = new QHBoxLayout();
        horizontalLayout_Prenom->setObjectName(QString::fromUtf8("horizontalLayout_Prenom"));
        label_Prenom = new QLabel(layoutWidget);
        label_Prenom->setObjectName(QString::fromUtf8("label_Prenom"));
        label_Prenom->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_Prenom->addWidget(label_Prenom);

        horizontalSpacer_Prenom = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Prenom->addItem(horizontalSpacer_Prenom);

        lineEdit_Prenom = new QLineEdit(layoutWidget);
        lineEdit_Prenom->setObjectName(QString::fromUtf8("lineEdit_Prenom"));
        lineEdit_Prenom->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold; border: 1px inset white;"));

        horizontalLayout_Prenom->addWidget(lineEdit_Prenom);


        verticalLayout->addLayout(horizontalLayout_Prenom);

        horizontalLayout_Numero = new QHBoxLayout();
        horizontalLayout_Numero->setObjectName(QString::fromUtf8("horizontalLayout_Numero"));
        label_Numero = new QLabel(layoutWidget);
        label_Numero->setObjectName(QString::fromUtf8("label_Numero"));
        label_Numero->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_Numero->addWidget(label_Numero);

        horizontalSpacer_Numero = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Numero->addItem(horizontalSpacer_Numero);

        lineEdit_Numero = new QLineEdit(layoutWidget);
        lineEdit_Numero->setObjectName(QString::fromUtf8("lineEdit_Numero"));
        lineEdit_Numero->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold; border: 1px inset white;"));

        horizontalLayout_Numero->addWidget(lineEdit_Numero);


        verticalLayout->addLayout(horizontalLayout_Numero);

        horizontalLayout_Solde = new QHBoxLayout();
        horizontalLayout_Solde->setObjectName(QString::fromUtf8("horizontalLayout_Solde"));
        label_Solde = new QLabel(layoutWidget);
        label_Solde->setObjectName(QString::fromUtf8("label_Solde"));
        label_Solde->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_Solde->addWidget(label_Solde);

        horizontalSpacer_Solde = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Solde->addItem(horizontalSpacer_Solde);

        lineEdit_Solde = new QLineEdit(layoutWidget);
        lineEdit_Solde->setObjectName(QString::fromUtf8("lineEdit_Solde"));
        lineEdit_Solde->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold; border: 1px inset white;"));

        horizontalLayout_Solde->addWidget(lineEdit_Solde);


        verticalLayout->addLayout(horizontalLayout_Solde);

        horizontalLayout_Ville = new QHBoxLayout();
        horizontalLayout_Ville->setObjectName(QString::fromUtf8("horizontalLayout_Ville"));
        label_Ville = new QLabel(layoutWidget);
        label_Ville->setObjectName(QString::fromUtf8("label_Ville"));
        label_Ville->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_Ville->addWidget(label_Ville);

        horizontalSpacer_Ville = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Ville->addItem(horizontalSpacer_Ville);

        lineEdit_Ville = new QLineEdit(layoutWidget);
        lineEdit_Ville->setObjectName(QString::fromUtf8("lineEdit_Ville"));
        lineEdit_Ville->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold; border: 1px inset white;"));

        horizontalLayout_Ville->addWidget(lineEdit_Ville);


        verticalLayout->addLayout(horizontalLayout_Ville);

        horizontalLayout_Agence = new QHBoxLayout();
        horizontalLayout_Agence->setObjectName(QString::fromUtf8("horizontalLayout_Agence"));
        label_Agence = new QLabel(layoutWidget);
        label_Agence->setObjectName(QString::fromUtf8("label_Agence"));
        label_Agence->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_Agence->addWidget(label_Agence);

        comboBox_Agence = new QComboBox(layoutWidget);
        comboBox_Agence->setObjectName(QString::fromUtf8("comboBox_Agence"));
        comboBox_Agence->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #ffffff; font-weight: bold;"));

        horizontalLayout_Agence->addWidget(comboBox_Agence);


        verticalLayout->addLayout(horizontalLayout_Agence);


        retranslateUi(AjoutDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AjoutDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AjoutDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AjoutDialog);
    } // setupUi

    void retranslateUi(QDialog *AjoutDialog)
    {
        AjoutDialog->setWindowTitle(QCoreApplication::translate("AjoutDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AjoutDialog", "Ajout client", nullptr));
        label_Nom->setText(QCoreApplication::translate("AjoutDialog", "Nom :", nullptr));
        label_Prenom->setText(QCoreApplication::translate("AjoutDialog", "Pr\303\251nom :", nullptr));
        label_Numero->setText(QCoreApplication::translate("AjoutDialog", "Num\303\251ro de compte :", nullptr));
        label_Solde->setText(QCoreApplication::translate("AjoutDialog", "Solde :", nullptr));
        label_Ville->setText(QCoreApplication::translate("AjoutDialog", "Ville :", nullptr));
        label_Agence->setText(QCoreApplication::translate("AjoutDialog", "Agence :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutDialog: public Ui_AjoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTDIALOG_H
