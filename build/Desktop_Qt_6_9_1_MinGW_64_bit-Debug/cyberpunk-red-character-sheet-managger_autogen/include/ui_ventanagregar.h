/********************************************************************************
** Form generated from reading UI file 'ventanagregar.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAGREGAR_H
#define UI_VENTANAGREGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ventanAgregar
{
public:
    QLabel *label;

    void setupUi(QDialog *ventanAgregar)
    {
        if (ventanAgregar->objectName().isEmpty())
            ventanAgregar->setObjectName("ventanAgregar");
        ventanAgregar->resize(891, 518);
        ventanAgregar->setStyleSheet(QString::fromUtf8("background-color: #202020;\n"
"font: 9pt \"OCR A\";\n"
"color: #f0f0f0;\n"
"border: 4px solid red;\n"
""));
        label = new QLabel(ventanAgregar);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 201, 71));
        label->setStyleSheet(QString::fromUtf8("border: 0px solid red;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/imagenes/Cyberpunk-RED-logo.png")));
        label->setScaledContents(true);

        retranslateUi(ventanAgregar);

        QMetaObject::connectSlotsByName(ventanAgregar);
    } // setupUi

    void retranslateUi(QDialog *ventanAgregar)
    {
        ventanAgregar->setWindowTitle(QCoreApplication::translate("ventanAgregar", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ventanAgregar: public Ui_ventanAgregar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAGREGAR_H
