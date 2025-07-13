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
    Estadisticas nuevo;
    nuevo.inteligencia = ui->inteligenciaSpinBox->value();
    nuevo.reflejos = ui->reflejosSpinBox->value();
    nuevo.destreza = ui->destrezaSpinBox->value();
    nuevo.tecnica = ui->tecnicaSpinBox->value();
    nuevo.frialdad = ui->frialdadSpinBox->value();
    nuevo.volundad = ui->voluntadSpinBox->value();
    nuevo.suerte = ui->suerteSpinBox->value();
    nuevo.movimiento = ui->movilidadSpinBox->value();
    nuevo.tipoCorporal = ui->tipo_corporalSpinBox->value();
    nuevo.empatia = ui->empatiaSpinBox->value();

    QString resumen = "Personaje agregado exitosamente";

    QMessageBox::information(this, "Éxito", resumen);

}




