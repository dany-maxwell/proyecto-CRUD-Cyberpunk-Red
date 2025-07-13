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
#include <QtWidgets/QSpinBox>

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
    QLineEdit *lineEdit_6;
    QSpinBox *inteligenciaSpinBox;
    QSpinBox *reflejosSpinBox;
    QSpinBox *destrezaSpinBox;
    QSpinBox *tecnicaSpinBox;
    QSpinBox *frialdadSpinBox;
    QSpinBox *voluntadSpinBox;
    QSpinBox *suerteSpinBox;
    QSpinBox *movilidadSpinBox;
    QSpinBox *tipo_corporalSpinBox;
    QSpinBox *empatiaSpinBox;
    QLabel *label_13;
    QLineEdit *nombreLineEdit;

    void setupUi(QDialog *ventanAgregar)
    {
        if (ventanAgregar->objectName().isEmpty())
            ventanAgregar->setObjectName("ventanAgregar");
        ventanAgregar->resize(832, 612);
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
        seccionEstado->setGeometry(QRect(10, 80, 351, 521));
        seccionEstado_2 = new QLabel(ventanAgregar);
        seccionEstado_2->setObjectName("seccionEstado_2");
        seccionEstado_2->setGeometry(QRect(370, 80, 151, 311));
        seccionEstado_3 = new QLabel(ventanAgregar);
        seccionEstado_3->setObjectName("seccionEstado_3");
        seccionEstado_3->setGeometry(QRect(530, 80, 291, 521));
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
        label_3->setGeometry(QRect(380, 90, 61, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_4 = new QLabel(ventanAgregar);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(380, 150, 61, 51));
        label_4->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_5 = new QLabel(ventanAgregar);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 210, 61, 51));
        label_5->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_6 = new QLabel(ventanAgregar);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 271, 61, 51));
        label_6->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_7 = new QLabel(ventanAgregar);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 331, 61, 51));
        label_7->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_8 = new QLabel(ventanAgregar);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(450, 90, 61, 51));
        label_8->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_9 = new QLabel(ventanAgregar);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(450, 150, 61, 51));
        label_9->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_10 = new QLabel(ventanAgregar);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(450, 210, 61, 51));
        label_10->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_11 = new QLabel(ventanAgregar);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(450, 270, 61, 51));
        label_11->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label_12 = new QLabel(ventanAgregar);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(450, 330, 61, 51));
        label_12->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_12->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lineEdit_6 = new QLineEdit(ventanAgregar);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(760, 580, 31, 21));
        lineEdit_6->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255,255,255,0);\n"
"font-weight: bold;\n"
"color: black;"));
        lineEdit_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        inteligenciaSpinBox = new QSpinBox(ventanAgregar);
        inteligenciaSpinBox->setObjectName("inteligenciaSpinBox");
        inteligenciaSpinBox->setGeometry(QRect(379, 110, 61, 25));
        inteligenciaSpinBox->setMinimumSize(QSize(50, 0));
        inteligenciaSpinBox->setMaximum(10);
        reflejosSpinBox = new QSpinBox(ventanAgregar);
        reflejosSpinBox->setObjectName("reflejosSpinBox");
        reflejosSpinBox->setGeometry(QRect(381, 170, 61, 25));
        reflejosSpinBox->setMaximum(10);
        destrezaSpinBox = new QSpinBox(ventanAgregar);
        destrezaSpinBox->setObjectName("destrezaSpinBox");
        destrezaSpinBox->setGeometry(QRect(381, 230, 61, 25));
        destrezaSpinBox->setMaximum(10);
        tecnicaSpinBox = new QSpinBox(ventanAgregar);
        tecnicaSpinBox->setObjectName("tecnicaSpinBox");
        tecnicaSpinBox->setGeometry(QRect(381, 290, 61, 25));
        tecnicaSpinBox->setMaximum(10);
        frialdadSpinBox = new QSpinBox(ventanAgregar);
        frialdadSpinBox->setObjectName("frialdadSpinBox");
        frialdadSpinBox->setGeometry(QRect(381, 350, 61, 25));
        frialdadSpinBox->setMaximum(10);
        voluntadSpinBox = new QSpinBox(ventanAgregar);
        voluntadSpinBox->setObjectName("voluntadSpinBox");
        voluntadSpinBox->setGeometry(QRect(451, 110, 61, 25));
        voluntadSpinBox->setMaximum(10);
        suerteSpinBox = new QSpinBox(ventanAgregar);
        suerteSpinBox->setObjectName("suerteSpinBox");
        suerteSpinBox->setGeometry(QRect(451, 170, 61, 25));
        suerteSpinBox->setMaximum(10);
        movilidadSpinBox = new QSpinBox(ventanAgregar);
        movilidadSpinBox->setObjectName("movilidadSpinBox");
        movilidadSpinBox->setGeometry(QRect(451, 230, 61, 25));
        movilidadSpinBox->setMaximum(10);
        tipo_corporalSpinBox = new QSpinBox(ventanAgregar);
        tipo_corporalSpinBox->setObjectName("tipo_corporalSpinBox");
        tipo_corporalSpinBox->setGeometry(QRect(451, 290, 61, 25));
        tipo_corporalSpinBox->setMaximum(10);
        empatiaSpinBox = new QSpinBox(ventanAgregar);
        empatiaSpinBox->setObjectName("empatiaSpinBox");
        empatiaSpinBox->setGeometry(QRect(451, 350, 61, 25));
        empatiaSpinBox->setMaximum(10);
        label_13 = new QLabel(ventanAgregar);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(370, 400, 151, 51));
        label_13->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 2px solid red;\n"
"font-weight: bold;\n"
"color: black;"));
        label_13->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        nombreLineEdit = new QLineEdit(ventanAgregar);
        nombreLineEdit->setObjectName("nombreLineEdit");
        nombreLineEdit->setGeometry(QRect(390, 420, 113, 24));

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
        label_13->setText(QCoreApplication::translate("ventanAgregar", "NAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ventanAgregar: public Ui_ventanAgregar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAGREGAR_H
