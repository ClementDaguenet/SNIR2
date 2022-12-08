/********************************************************************************
** Form generated from reading UI file 'banqueserveurwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANQUESERVEURWIDGET_H
#define UI_BANQUESERVEURWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BanqueServeurWidget
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *BanqueServeurWidget)
    {
        if (BanqueServeurWidget->objectName().isEmpty())
            BanqueServeurWidget->setObjectName(QString::fromUtf8("BanqueServeurWidget"));
        BanqueServeurWidget->resize(200, 91);
        pushButton = new QPushButton(BanqueServeurWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 181, 71));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);

        retranslateUi(BanqueServeurWidget);
        QObject::connect(pushButton, &QPushButton::clicked, BanqueServeurWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(BanqueServeurWidget);
    } // setupUi

    void retranslateUi(QWidget *BanqueServeurWidget)
    {
        BanqueServeurWidget->setWindowTitle(QCoreApplication::translate("BanqueServeurWidget", "BanqueServeurWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("BanqueServeurWidget", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BanqueServeurWidget: public Ui_BanqueServeurWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANQUESERVEURWIDGET_H
