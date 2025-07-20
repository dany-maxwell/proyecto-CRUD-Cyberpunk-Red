#include "ventanaeditar.h"
#include "ui_ventanaeditar.h"
#include "QPushButton"
#include <QList>
#include <Qstring>
#include <QFile>
#include <QDir>

ventanaEditar::ventanaEditar(const QString& nombre, QList<Cyberpunk>& personajes, QWidget *parent)
    : QDialog(parent), nombre(nombre), lista(personajes)
    , ui(new Ui::ventanaEditar)
{
    ui->setupUi(this);
    leerPersonaje();
}

ventanaEditar::~ventanaEditar()
{
    delete ui;
}

void ventanaEditar::leerPersonaje(){
    for (const Cyberpunk& p : lista) {
        if (p.datos.nombre == nombre) {
            ui->label->setText(p.datos.nombre);
            ui->label_2->setText(p.datos.rol);
            ui->label_3->setText(p.datos.aptitudRol);
            break;
        }
    }
}
