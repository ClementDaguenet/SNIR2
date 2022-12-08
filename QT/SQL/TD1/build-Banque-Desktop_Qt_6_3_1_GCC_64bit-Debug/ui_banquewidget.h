/********************************************************************************
** Form generated from reading UI file 'banquewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANQUEWIDGET_H
#define UI_BANQUEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BanqueWidget
{
public:
    QPushButton *pushButton_Connexion;
    QGroupBox *groupBox_Informations;
    QTextEdit *textEdit_Informations;
    QPushButton *pushButton_Informations;
    QTableWidget *tableWidget_Informations;
    QPushButton *pushButton_Quitter;
    QPushButton *pushButton_Ajouter;

    void setupUi(QWidget *BanqueWidget)
    {
        if (BanqueWidget->objectName().isEmpty())
            BanqueWidget->setObjectName(QString::fromUtf8("BanqueWidget"));
        BanqueWidget->resize(634, 423);
        BanqueWidget->setStyleSheet(QString::fromUtf8("background-color: #101010"));
        pushButton_Connexion = new QPushButton(BanqueWidget);
        pushButton_Connexion->setObjectName(QString::fromUtf8("pushButton_Connexion"));
        pushButton_Connexion->setGeometry(QRect(10, 10, 161, 61));
        QFont font;
        font.setBold(true);
        pushButton_Connexion->setFont(font);
        pushButton_Connexion->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 24px; color: #ffffff; font-weight: bold;"));
        groupBox_Informations = new QGroupBox(BanqueWidget);
        groupBox_Informations->setObjectName(QString::fromUtf8("groupBox_Informations"));
        groupBox_Informations->setGeometry(QRect(10, 90, 611, 311));
        groupBox_Informations->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));
        textEdit_Informations = new QTextEdit(groupBox_Informations);
        textEdit_Informations->setObjectName(QString::fromUtf8("textEdit_Informations"));
        textEdit_Informations->setGeometry(QRect(10, 50, 591, 251));
        textEdit_Informations->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));
        textEdit_Informations->setReadOnly(true);
        pushButton_Informations = new QPushButton(groupBox_Informations);
        pushButton_Informations->setObjectName(QString::fromUtf8("pushButton_Informations"));
        pushButton_Informations->setGeometry(QRect(10, 20, 281, 23));
        pushButton_Informations->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));
        tableWidget_Informations = new QTableWidget(groupBox_Informations);
        if (tableWidget_Informations->columnCount() < 6)
            tableWidget_Informations->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Informations->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Informations->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Informations->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Informations->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Informations->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Informations->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_Informations->setObjectName(QString::fromUtf8("tableWidget_Informations"));
        tableWidget_Informations->setGeometry(QRect(10, 50, 591, 251));
        tableWidget_Informations->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;"));
        pushButton_Quitter = new QPushButton(BanqueWidget);
        pushButton_Quitter->setObjectName(QString::fromUtf8("pushButton_Quitter"));
        pushButton_Quitter->setGeometry(QRect(460, 10, 161, 61));
        pushButton_Quitter->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 24px; color: #ffffff; font-weight: bold;"));
        pushButton_Ajouter = new QPushButton(BanqueWidget);
        pushButton_Ajouter->setObjectName(QString::fromUtf8("pushButton_Ajouter"));
        pushButton_Ajouter->setGeometry(QRect(240, 10, 161, 61));
        pushButton_Ajouter->setStyleSheet(QString::fromUtf8("background-color: #151515; font-size: 24px; color: #808080; font-weight: bold;"));

        retranslateUi(BanqueWidget);
        QObject::connect(pushButton_Quitter, &QPushButton::clicked, BanqueWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(BanqueWidget);
    } // setupUi

    void retranslateUi(QWidget *BanqueWidget)
    {
        BanqueWidget->setWindowTitle(QCoreApplication::translate("BanqueWidget", "BanqueWidget", nullptr));
        pushButton_Connexion->setText(QCoreApplication::translate("BanqueWidget", "Connexion", nullptr));
        groupBox_Informations->setTitle(QCoreApplication::translate("BanqueWidget", "Informations de la banque", nullptr));
        pushButton_Informations->setText(QCoreApplication::translate("BanqueWidget", "Afficher les informations de tous les comptes", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Informations->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BanqueWidget", "Num\303\251ro", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Informations->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BanqueWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Informations->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BanqueWidget", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Informations->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BanqueWidget", "Solde (\342\202\254)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Informations->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BanqueWidget", "Agence", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Informations->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("BanqueWidget", "Ville", nullptr));
        pushButton_Quitter->setText(QCoreApplication::translate("BanqueWidget", "Quitter", nullptr));
        pushButton_Ajouter->setText(QCoreApplication::translate("BanqueWidget", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BanqueWidget: public Ui_BanqueWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANQUEWIDGET_H
