#include "ventanaeditar.h"
#include "ui_ventanaeditar.h"
#include "ventanagregar.h"
#include "charactersheetmanager.h"
#include "QPushButton"
#include <QList>
#include <Qstring>
#include <QFile>
#include <QDir>

ventanaEditar::ventanaEditar(QPushButton *personaje, QWidget *parent, CharacterSheetManager *main, ventanAgregar *sec)
    : QDialog(parent)
    , ui(new Ui::ventanaEditar)
{
    nombre = personaje->property("nombre").toString();
    ui->setupUi(this);
    leerPersonaje();
}

ventanaEditar::~ventanaEditar()
{
    delete ui;
}

void ventanaEditar::leerPersonaje(){
    QString ruta = QDir::homePath() + "/Documents/personajes.txt";
    QFile archivo(ruta);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&archivo);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList p = linea.split(",");

        if (p[0] == nombre) {
            ui->label->setText(p[0]);
            ui->label_2->setText(p[1]);
            ui->label_3->setText(p[2]);
            break;
        }
    }
}
