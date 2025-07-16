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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterSheetManager
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *MENU;
    QLabel *logo;
    QFrame *frame;
    QPushButton *Salir;
    QPushButton *Agregar;
    QPushButton *Editar;
    QPushButton *Revisar;
    QPushButton *Eliminar;
    QLabel *label_2;
    QWidget *LISTA;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutlista;

    void setupUi(QMainWindow *CharacterSheetManager)
    {
        if (CharacterSheetManager->objectName().isEmpty())
            CharacterSheetManager->setObjectName("CharacterSheetManager");
        CharacterSheetManager->resize(780, 468);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/imagenes/cyberpunk_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        CharacterSheetManager->setWindowIcon(icon);
        CharacterSheetManager->setAutoFillBackground(false);
        CharacterSheetManager->setStyleSheet(QString::fromUtf8("background-color: #202020;\n"
"font: 9pt \"OCR A\";\n"
"color: #f0f0f0;\n"
"border: non;\n"
""));
        centralwidget = new QWidget(CharacterSheetManager);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        MENU = new QWidget(centralwidget);
        MENU->setObjectName("MENU");
        MENU->setMinimumSize(QSize(379, 450));
        logo = new QLabel(MENU);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(40, 30, 281, 111));
        logo->setStyleSheet(QString::fromUtf8("border: 0px solid red;\n"
""));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/imagenes/Cyberpunk-RED-logo.png")));
        logo->setScaledContents(true);
        frame = new QFrame(MENU);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(60, 200, 261, 231));
        frame->setStyleSheet(QString::fromUtf8("border: 3px solid red;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        Salir = new QPushButton(frame);
        Salir->setObjectName("Salir");
        Salir->setGeometry(QRect(55, 180, 150, 31));
        Salir->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Salir->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #b4b4b4;\n"
"	border: 4px solid red;\n"
"	font-weight: bold;\n"
"	color: black;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #848686;\n"
"	border: 4px solid #bd0000;\n"
"}"));
        Agregar = new QPushButton(frame);
        Agregar->setObjectName("Agregar");
        Agregar->setGeometry(QRect(55, 20, 150, 31));
        Agregar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Agregar->setMouseTracking(true);
        Agregar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #b4b4b4;\n"
"	border: 4px solid red;\n"
"	font-weight: bold;\n"
"	color: black;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #848686;\n"
"	border: 4px solid #bd0000;\n"
"}"));
        Editar = new QPushButton(frame);
        Editar->setObjectName("Editar");
        Editar->setGeometry(QRect(55, 60, 150, 31));
        Editar->setStyleSheet(QString::fromUtf8("background-color: #c0c0c0;\n"
"border: 4px solid red;\n"
"font-weight: bold;\n"
"color: black;\n"
""));
        Revisar = new QPushButton(frame);
        Revisar->setObjectName("Revisar");
        Revisar->setGeometry(QRect(55, 100, 150, 31));
        Revisar->setStyleSheet(QString::fromUtf8("background-color: #c0c0c0;\n"
"border: 4px solid red;\n"
"font-weight: bold;\n"
"color: black;\n"
""));
        Eliminar = new QPushButton(frame);
        Eliminar->setObjectName("Eliminar");
        Eliminar->setGeometry(QRect(55, 140, 150, 31));
        Eliminar->setStyleSheet(QString::fromUtf8("background-color: #c0c0c0;\n"
"border: 4px solid red;\n"
"font-weight: bold;\n"
"color: black;\n"
""));
        label_2 = new QLabel(MENU);
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

        horizontalLayout->addWidget(MENU);

        LISTA = new QWidget(centralwidget);
        LISTA->setObjectName("LISTA");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LISTA->sizePolicy().hasHeightForWidth());
        LISTA->setSizePolicy(sizePolicy);
        LISTA->setMinimumSize(QSize(379, 450));
        LISTA->setStyleSheet(QString::fromUtf8("border: 0px solid red;"));
        verticalLayoutWidget = new QWidget(LISTA);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 371, 451));
        layoutlista = new QVBoxLayout(verticalLayoutWidget);
        layoutlista->setObjectName("layoutlista");
        layoutlista->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(LISTA);

        CharacterSheetManager->setCentralWidget(centralwidget);

        retranslateUi(CharacterSheetManager);

        QMetaObject::connectSlotsByName(CharacterSheetManager);
    } // setupUi

    void retranslateUi(QMainWindow *CharacterSheetManager)
    {
        CharacterSheetManager->setWindowTitle(QCoreApplication::translate("CharacterSheetManager", "CharacterSheetManager", nullptr));
        logo->setText(QString());
        Salir->setText(QCoreApplication::translate("CharacterSheetManager", "SALIR", nullptr));
        Agregar->setText(QCoreApplication::translate("CharacterSheetManager", "AGREGAR", nullptr));
        Editar->setText(QCoreApplication::translate("CharacterSheetManager", "EDITAR", nullptr));
        Revisar->setText(QCoreApplication::translate("CharacterSheetManager", "REVISAR", nullptr));
        Eliminar->setText(QCoreApplication::translate("CharacterSheetManager", "ELIMINAR", nullptr));
        label_2->setText(QCoreApplication::translate("CharacterSheetManager", "GESTOR HOJA DE PERSONAJE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharacterSheetManager: public Ui_CharacterSheetManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERSHEETMANAGER_H
