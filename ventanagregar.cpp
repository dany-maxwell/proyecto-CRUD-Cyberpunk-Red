#include "ventanagregar.h"
#include "ui_ventanagregar.h"
#include "Pesonaje.h"
#include "QMessageBox"


ventanAgregar::ventanAgregar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ventanAgregar)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    connect(ui->Guardar, &QPushButton::clicked, this, &ventanAgregar::agregarPersonaje);
}


ventanAgregar::~ventanAgregar()
{
    delete ui;
}

void ventanAgregar::agregarPersonaje() {
    Estadisticas Habilidad;
    Habilidad.inteligencia = ui->inteligenciaSpinBox->value();
    Habilidad.reflejos = ui->reflejosSpinBox->value();
    Habilidad.destreza = ui->destrezaSpinBox->value();
    Habilidad.tecnica = ui->tecnicaSpinBox->value();
    Habilidad.frialdad = ui->frialdadSpinBox->value();
    Habilidad.voluntad = ui->voluntadSpinBox->value();
    Habilidad.suerte = ui->suerteSpinBox->value();
    Habilidad.movimiento = ui->movilidadSpinBox->value();
    Habilidad.tipoCorporal = ui->tipo_corporalSpinBox->value();
    Habilidad.empatia = ui->empatiaSpinBox->value();
    Datos nuevo;
    nuevo.rol = ui->rolLineEdit->text();
    Estado condicion;
    condicion.vidaActual = ui->vidaActualSpinBox->value();
    Cyberpunk nuevoPersonaje;
    nuevoPersonaje.nombre = ui->nombreLineEdit->text();
    nuevoPersonaje.base=Habilidad;
    nuevoPersonaje.datos=nuevo;
    nuevoPersonaje.estado=condicion;
    personajes.append(nuevoPersonaje);


    QString resumen = "Personaje agregado exitosamente";

    QMessageBox::information(this, "Éxito", resumen);

}




