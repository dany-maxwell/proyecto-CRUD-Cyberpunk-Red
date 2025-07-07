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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ventanAgregar
{
public:
    QLabel *label;
    QLabel *seccionEstado;
    QLabel *seccionEstado_2;
    QLabel *seccionEstado_3;
    QLabel *label_2;
    QPushButton *Guardar;
    QPushButton *Descartar;
    QPushButton *Descartar_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;

    void setupUi(QDialog *ventanAgregar)
    {
        if (ventanAgregar->objectName().isEmpty())
            ventanAgregar->setObjectName("ventanAgregar");
        ventanAgregar->resize(814, 603);
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
        seccionEstado = new QLabel(ventanAgregar);
        seccionEstado->setObjectName("seccionEstado");
        seccionEstado->setGeometry(QRect(10, 80, 351, 511));
        seccionEstado_2 = new QLabel(ventanAgregar);
        seccionEstado_2->setObjectName("seccionEstado_2");
        seccionEstado_2->setGeometry(QRect(370, 80, 71, 511));
        seccionEstado_3 = new QLabel(ventanAgregar);
        seccionEstado_3->setObjectName("seccionEstado_3");
        seccionEstado_3->setGeometry(QRect(450, 80, 351, 511));
        label_2 = new QLabel(ventanAgregar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 331, 181));
        Guardar = new QPushButton(ventanAgregar);
        Guardar->setObjectName("Guardar");
        Guardar->setGeometry(QRect(240, 20, 201, 41));
        Guardar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #b4b4b4;\n"
"	border: 4px solid red;\n"
"	font-weight: bold;\n"
"	color: black;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #848686;\n"
"	border: 4px solid #bd0000;\n"
"}"));
        Descartar = new QPushButton(ventanAgregar);
        Descartar->setObjectName("Descartar");
        Descartar->setGeometry(QRect(450, 20, 201, 41));
        Descartar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #b4b4b4;\n"
"	border: 4px solid red;\n"
"	font-weight: bold;\n"
"	color: black;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #848686;\n"
"	border: 4px solid #bd0000;\n"
"}"));
        Descartar_2 = new QPushButton(ventanAgregar);
        Descartar_2->setObjectName("Descartar_2");
        Descartar_2->setGeometry(QRect(660, 30, 21, 21));
        Descartar_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #ac4242;\n"
"	border: 0px solid red;\n"
"	font-weight: bold;\n"
"	color: black;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #dd5656;\n"
"	border: 0px solid #bd0000;\n"
"}"));
        label_3 = new QLabel(ventanAgregar);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(380, 90, 51, 41));
        label_3->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_4 = new QLabel(ventanAgregar);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(380, 140, 51, 41));
        label_4->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_5 = new QLabel(ventanAgregar);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 190, 51, 41));
        label_5->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_6 = new QLabel(ventanAgregar);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 240, 51, 41));
        label_6->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_7 = new QLabel(ventanAgregar);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 290, 51, 41));
        label_7->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_8 = new QLabel(ventanAgregar);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(380, 340, 51, 41));
        label_8->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_9 = new QLabel(ventanAgregar);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(380, 390, 51, 41));
        label_9->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_10 = new QLabel(ventanAgregar);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(380, 440, 51, 41));
        label_10->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_11 = new QLabel(ventanAgregar);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(380, 490, 51, 41));
        label_11->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_12 = new QLabel(ventanAgregar);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(380, 540, 51, 41));
        label_12->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_12->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit = new QLineEdit(ventanAgregar);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(390, 110, 31, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_2 = new QLineEdit(ventanAgregar);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(390, 160, 31, 21));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_2->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_3 = new QLineEdit(ventanAgregar);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(390, 210, 31, 21));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_3->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_4 = new QLineEdit(ventanAgregar);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(390, 260, 31, 21));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_4->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_5 = new QLineEdit(ventanAgregar);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(390, 310, 31, 21));
        lineEdit_5->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_5->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_6 = new QLineEdit(ventanAgregar);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(760, 580, 31, 21));
        lineEdit_6->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_7 = new QLineEdit(ventanAgregar);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(390, 410, 31, 21));
        lineEdit_7->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_7->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_8 = new QLineEdit(ventanAgregar);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(390, 360, 31, 21));
        lineEdit_8->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_8->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_9 = new QLineEdit(ventanAgregar);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(390, 460, 31, 21));
        lineEdit_9->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_9->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_10 = new QLineEdit(ventanAgregar);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(390, 510, 31, 21));
        lineEdit_10->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_10->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_11 = new QLineEdit(ventanAgregar);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(390, 560, 31, 21));
        lineEdit_11->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_11->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        retranslateUi(ventanAgregar);

        QMetaObject::connectSlotsByName(ventanAgregar);
    } // setupUi

    void retranslateUi(QDialog *ventanAgregar)
    {
        ventanAgregar->setWindowTitle(QCoreApplication::translate("ventanAgregar", "Dialog", nullptr));
        label->setText(QString());
        seccionEstado->setText(QString());
        seccionEstado_2->setText(QString());
        seccionEstado_3->setText(QString());
        label_2->setText(QString());
        Guardar->setText(QCoreApplication::translate("ventanAgregar", "GUARDAR", nullptr));
        Descartar->setText(QCoreApplication::translate("ventanAgregar", "DESCARTAR", nullptr));
        Descartar_2->setText(QCoreApplication::translate("ventanAgregar", "?", nullptr));
        label_3->setText(QCoreApplication::translate("ventanAgregar", "INT", nullptr));
        label_4->setText(QCoreApplication::translate("ventanAgregar", "REF", nullptr));
        label_5->setText(QCoreApplication::translate("ventanAgregar", "DES", nullptr));
        label_6->setText(QCoreApplication::translate("ventanAgregar", "TEC", nullptr));
        label_7->setText(QCoreApplication::translate("ventanAgregar", "FRI", nullptr));
        label_8->setText(QCoreApplication::translate("ventanAgregar", "VOL", nullptr));
        label_9->setText(QCoreApplication::translate("ventanAgregar", "SUE", nullptr));
        label_10->setText(QCoreApplication::translate("ventanAgregar", "MOV", nullptr));
        label_11->setText(QCoreApplication::translate("ventanAgregar", "T.COR", nullptr));
        label_12->setText(QCoreApplication::translate("ventanAgregar", "EMP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ventanAgregar: public Ui_ventanAgregar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAGREGAR_H
