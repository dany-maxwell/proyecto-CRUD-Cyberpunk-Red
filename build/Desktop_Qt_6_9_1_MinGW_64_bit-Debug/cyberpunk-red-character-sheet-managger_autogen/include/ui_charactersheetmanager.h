/********************************************************************************
** Form generated from reading UI file 'charactersheetmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERSHEETMANAGER_H
#define UI_CHARACTERSHEETMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterSheetManager
{
public:
    QWidget *centralwidget;
    QLabel *logo;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *CharacterSheetManager)
    {
        if (CharacterSheetManager->objectName().isEmpty())
            CharacterSheetManager->setObjectName("CharacterSheetManager");
        CharacterSheetManager->resize(379, 448);
        CharacterSheetManager->setAutoFillBackground(false);
        CharacterSheetManager->setStyleSheet(QString::fromUtf8("background-color: #202020;\n"
"font: 9pt \"OCR A\";\n"
"color: #f0f0f0;\n"
"border: 4px solid red;\n"
""));
        centralwidget = new QWidget(CharacterSheetManager);
        centralwidget->setObjectName("centralwidget");
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(50, 30, 281, 111));
        logo->setStyleSheet(QString::fromUtf8("border: 0px solid red;\n"
""));
        logo->setPixmap(QPixmap(QString::fromUtf8("imagenes/Cyberpunk-RED-logo.png")));
        logo->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 140, 301, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("OCR A")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("border: 0px solid red;\n"
"font: 14pt \"OCR A\";"));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2->setWordWrap(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 220, 241, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #b4b4b4;\n"
"border: 4px solid red;\n"
"font-weight: bold;\n"
"color: black;\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(70, 270, 241, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #c0c0c0;\n"
"border: 4px solid red;\n"
"font-weight: bold;\n"
"color: black;\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(70, 320, 241, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #c0c0c0;\n"
"border: 4px solid red;\n"
"font-weight: bold;\n"
"color: black;\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(60, 210, 261, 201));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(50, 160, 161, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: #c0c0c0;\n"
"border: 4px solid red;\n"
"font-weight: bold;\n"
"color: black;\n"
""));
        CharacterSheetManager->setCentralWidget(centralwidget);
        frame->raise();
        label_2->raise();
        logo->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();

        retranslateUi(CharacterSheetManager);

        QMetaObject::connectSlotsByName(CharacterSheetManager);
    } // setupUi

    void retranslateUi(QMainWindow *CharacterSheetManager)
    {
        CharacterSheetManager->setWindowTitle(QCoreApplication::translate("CharacterSheetManager", "CharacterSheetManager", nullptr));
        logo->setText(QString());
        label_2->setText(QCoreApplication::translate("CharacterSheetManager", "GESTOR HOJA DE PERSONAJE", nullptr));
        pushButton->setText(QCoreApplication::translate("CharacterSheetManager", "AGREGAR", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CharacterSheetManager", "EDITAR", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CharacterSheetManager", "ELIMINAR", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CharacterSheetManager", "SALIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharacterSheetManager: public Ui_CharacterSheetManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERSHEETMANAGER_H
