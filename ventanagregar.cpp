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
    Personaje nuevo;
    nuevo.nombre = ui->nombreLineEdit->text();
    nuevo.inteligencia = ui->inteligenciaSpinBox->value();
    nuevo.reflejos = ui->reflejosSpinBox->value();
    nuevo.destreza = ui->destrezaSpinBox->value();
    nuevo.tecnica = ui->tecnicaSpinBox->value();
    nuevo.frialdad = ui->frialdadSpinBox->value();
    nuevo.voluntad = ui->voluntadSpinBox->value();
    nuevo.suerte = ui->suerteSpinBox->value();
    nuevo.movilidad = ui->movilidadSpinBox->value();
    nuevo.tipoCorporal = ui->tipo_corporalSpinBox->value();
    nuevo.empatia = ui->empatiaSpinBox->value();

    QString resumen = "Personaje agregado exitosamente";

    QMessageBox::information(this, "Éxito", resumen);

}




