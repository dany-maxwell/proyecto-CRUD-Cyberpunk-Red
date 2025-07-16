#include "ventanagregar.h"
#include "ui_ventanagregar.h"
#include "Pesonaje.h"
#include "QMessageBox"
#include "charactersheetmanager.h"
#include <QString>
#include <QDir>

ventanAgregar::ventanAgregar(CharacterSheetManager *manager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ventanAgregar)
    , managerRef(manager)
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
    Habilidad.suerteMax = ui->suerteMaximaSpinBox->value();
    Habilidad.movimiento = ui->movilidadSpinBox->value();
    Habilidad.tipoCorporal = ui->tipo_corporalSpinBox->value();
    Habilidad.empatia = ui->empatiaSpinBox->value();
    Habilidad.empatiaMax = ui->empatiaMaximaSpinBox->value();
    Datos nuevo;
    nuevo.rol = ui->rolLineEdit->text();
    nuevo.aptitudRol = ui->rolApt_lineEdit->text();
    nuevo.humanidad = ui->humanidad_spinBox->value();
    nuevo.rango = ui->rango_spinBox->value();
    Estado condicion;
    condicion.vidaMaxima = ui->vidaMaximaSpinBox->value();
    condicion.vidaActual = ui->vidaActualSpinBox->value();
    condicion.armaduraCabeza = ui->Armadura1_lineEdit->text();
    condicion.armaduraCuerpo = ui->Armadura2_lineEdit->text();
    condicion.escudo = ui->Armadura3_lineEdit->text();
    condicion.extra = ui->Armadura4_lineEdit->text();
    condicion.salvacionMuerte = ui->svMuerte_spinBox->value();
    condicion.gravedadHeridas = ui->heridas_spinBox->value();
    condicion.heridasCriticas = ui->herCrit_textEdit->toPlainText();
    condicion.adicciones = ui->Adicc_textEdit->toPlainText();
    Armas arma_;
    arma_.tipo = ui->Arma1_lineEdit->text();
    arma_.daño = ui->Arma1d_lineEdit->text();
    arma_.municion = ui->munic1_spinBox->value();
    arma_.cdt = ui->cdt1_spinBox->value();
    Cyberpunk nuevoPersonaje;
    nuevoPersonaje.nombre = ui->nombreLineEdit->text();
    nuevoPersonaje.base=Habilidad;
    nuevoPersonaje.datos=nuevo;
    nuevoPersonaje.estado=condicion;
    nuevoPersonaje.arma=arma_;
    managerRef->agregarPersonaje(nuevoPersonaje);
    QString ruta = QDir::homePath() + "/Documents/personajes.txt";
    managerRef->guardarPersonajesEnArchivo(ruta);


    QString resumen = "Personaje agregado exitosamente";

    QMessageBox::information(this, "Éxito", resumen);

    mainRef->agregarPersonajeEnLista(nuevoPersonaje);
    this->close();
}

void ventanAgregar::on_Descartar_clicked()
{
    close();
}

void ventanAgregar::on_inteligenciaSpinBox_valueChanged(int arg1)
{

}
