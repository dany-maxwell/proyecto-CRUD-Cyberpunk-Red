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
    ui->heridas_label->setRange(0,3);
    ui->suerteAct_label->setRange(0,10);
    ui->humanidad_label->setRange(0,100);
    ui->rango_label->setRange(4,10);
    leerPersonaje();

    connect(ui->humanidad_label, QOverload<int>::of(&QSpinBox::valueChanged), this, &ventanaEditar::rangoMaximo);
    connect(ui->suerteAct_label, QOverload<int>::of(&QSpinBox::valueChanged), this, &ventanaEditar::rangoMaximo);
}

ventanaEditar::~ventanaEditar()
{
    delete ui;
}

void ventanaEditar::leerPersonaje(){
    for (const Cyberpunk& personaje : lista) {
        if (personaje.datos.nombre == nombre) {
            this->rutaIcon = personaje.rutaIcon;
            ui->iconPersonaje_label->setPixmap(QPixmap(personaje.rutaIcon));
            ui->iconPersonaje_label->setScaledContents(true);
            ui->nombreLineEdit->setText(personaje.datos.nombre);
            ui->rol_comboBox->setText(personaje.datos.rol);
            ui->aptRol_label->setText(personaje.datos.aptitudRol);
            ui->rango_label->setValue(personaje.datos.rango);
            ui->humanidad_label->setValue(personaje.datos.humanidad);
            ui->punto_label->setValue(personaje.datos.puntosMejora);

            ui->inteligenciaSpinBox->setText(QString::number(personaje.base.inteligencia));
            ui->reflejosSpinBox->setText(QString::number(personaje.base.reflejos));
            ui->destrezaSpinBox->setText(QString::number(personaje.base.destreza));
            ui->tecnicaSpinBox->setText(QString::number(personaje.base.tecnica));
            ui->frialdadSpinBox->setText(QString::number(personaje.base.frialdad));
            ui->voluntadSpinBox->setText(QString::number(personaje.base.voluntad));
            ui->suerteAct_label->setValue(personaje.base.suerte);
            ui->suerteMax_SpinBox->setText(QString::number(personaje.base.suerteMax));
            ui->movilidadSpinBox->setText(QString::number(personaje.base.movimiento));
            ui->tipo_corporalSpinBox->setText(QString::number(personaje.base.tipoCorporal));
            ui->empatia_label->setText(QString::number(personaje.base.empatia));
            ui->empatiaMax_SpinBox->setText(QString::number(personaje.base.empatiaMax));

            ui->vidaActual_label->setValue(personaje.estado.vidaActual);
            ui->vidaMax_label->setText(QString::number(personaje.estado.vidaMaxima));
            ui->herCrit_lineedit->setText(personaje.estado.heridasCriticas);
            ui->svMuerte_label->setText(QString::number(personaje.estado.salvacionMuerte));
            ui->heridas_label->setValue(personaje.estado.gravedadHeridas);
            ui->Adicc_lineedit->setText(personaje.estado.adicciones);

            ui->Arma1_lineEdit->setText(personaje.arma.tipo);
            ui->Arma2_lineEdit->setText(personaje.arma2.tipo);
            ui->Arma1d_lineEdit->setText(personaje.arma.daño);
            ui->Arma2d_lineEdit->setText(personaje.arma2.daño);
            ui->munic1_spinBox->setValue(personaje.arma.municion);
            ui->munic2_spinBox->setValue(personaje.arma2.municion);
            ui->cdt1_spinBox->setValue(personaje.arma.cdt);
            ui->cdt2_spinBox->setValue(personaje.arma2.cdt);
            ui->armaRango_spinBox->setValue(personaje.arma.armaRango);
            ui->arma2Rango_spinBox->setValue(personaje.arma2.armaRango);

            ui->Armadura1_lineEdit->setText(personaje.estado.armaduraCabeza);
            ui->Armadura2_lineEdit->setText(personaje.estado.armaduraCuerpo);
            ui->Armadura3_lineEdit->setText(personaje.estado.escudo);
            ui->cp1_spinBox->setValue(personaje.estado.proteccionCabeza);
            ui->cp2_spinBox->setValue(personaje.estado.proteccionCuerpo);
            ui->cp3_spinBox->setValue(personaje.estado.proteccionEscudo);
            ui->Armadura1pn_lineEdit->setText(personaje.estado.penCabeza);
            ui->Armadura2pn_lineEdit->setText(personaje.estado.penCuerpo);
            ui->Armadura3pn_lineEdit->setText(personaje.estado.penEscudo);

            ui->ciber_lineEdit->setText(personaje.cyberware.cyberware1);
            ui->ciber_lineEdit_2->setText(personaje.cyberware.cyberware2);
            ui->ciber_lineEdit_3->setText(personaje.cyberware.cyberware3);
            ui->ciber_lineEdit_4->setText(personaje.cyberware.cyberware4);
            ui->ciber_lineEdit_5->setText(personaje.cyberware.cyberware5);
            break;
        }
    }
}


Cyberpunk ventanaEditar::personajEditado() const{
    Cyberpunk editado;
    editado.base.inteligencia = ui->inteligenciaSpinBox->text().toInt();
    editado.base.destreza = ui->destrezaSpinBox->text().toInt();
    editado.base.empatia = ui->empatia_label->text().toInt();
    editado.base.empatiaMax = ui->empatiaMax_SpinBox->text().toInt();
    editado.base.frialdad = ui->frialdadSpinBox->text().toInt();
    editado.base.movimiento = ui->movilidadSpinBox->text().toInt();
    editado.base.reflejos = ui->reflejosSpinBox->text().toInt();
    editado.base.suerte = ui->suerteAct_label->text().toInt();
    editado.base.suerteMax = ui->suerteMax_SpinBox->text().toInt();
    editado.base.tecnica = ui->tecnicaSpinBox->text().toInt();
    editado.base.tipoCorporal = ui->tipo_corporalSpinBox->text().toInt();
    editado.base.voluntad = ui->voluntadSpinBox->text().toInt();

    editado.datos.nombre = ui->nombreLineEdit->text();
    editado.datos.rol = ui->rol_comboBox->text();
    editado.datos.aptitudRol = ui->aptRol_label->text();
    editado.datos.rango = ui->rango_label->value();
    editado.datos.humanidad = ui->humanidad_label->value();
    editado.datos.puntosMejora = ui->punto_label->value();

    editado.estado.vidaActual = ui->vidaActual_label->value();
    editado.estado.vidaMaxima = ui->vidaMax_label->text().toInt();
    editado.estado.heridasCriticas = ui->herCrit_lineedit->text();
    editado.estado.gravedadHeridas = ui->heridas_label->text().toInt();
    editado.estado.adicciones = ui->Adicc_lineedit->text();
    editado.estado.salvacionMuerte = ui->svMuerte_label->text().toInt();

    editado.estado.armaduraCabeza = ui->Armadura1_lineEdit->text();
    editado.estado.armaduraCuerpo = ui->Armadura2_lineEdit->text();
    editado.estado.escudo = ui->Armadura3_lineEdit->text();
    editado.estado.proteccionCabeza = ui->cp1_spinBox->value();
    editado.estado.proteccionCuerpo = ui->cp2_spinBox->value();
    editado.estado.proteccionEscudo = ui->cp3_spinBox->value();
    editado.estado.penCabeza = ui->Armadura1pn_lineEdit->text();
    editado.estado.penCuerpo = ui->Armadura2pn_lineEdit->text();
    editado.estado.penEscudo = ui->Armadura3pn_lineEdit->text();

    editado.arma.tipo = ui->Arma1_lineEdit->text();
    editado.arma2.tipo = ui->Arma2_lineEdit->text();
    editado.arma.daño = ui->Arma1d_lineEdit->text();
    editado.arma2.daño = ui->Arma2d_lineEdit->text();
    editado.arma.cdt = ui->cdt1_spinBox->value();
    editado.arma2.cdt = ui->cdt2_spinBox->value();
    editado.arma.municion = ui->munic1_spinBox->value();
    editado.arma2.municion = ui->munic2_spinBox->value();
    editado.arma.armaRango = ui->armaRango_spinBox->value();
    editado.arma2.armaRango = ui->arma2Rango_spinBox->value();

    editado.cyberware.cyberware1 = ui->ciber_lineEdit->text();
    editado.cyberware.cyberware2 = ui->ciber_lineEdit_2->text();
    editado.cyberware.cyberware3 = ui->ciber_lineEdit_3->text();
    editado.cyberware.cyberware4 = ui->ciber_lineEdit_4->text();
    editado.cyberware.cyberware5 = ui->ciber_lineEdit_5->text();

    editado.rutaIcon = this->rutaIcon;

    return editado;
}

void ventanaEditar::on_Descartar_clicked()
{
    close();
}


void ventanaEditar::on_Guardar_clicked()
{
    Cyberpunk personajeActualizado = personajEditado();
    for (int i = 0; i < lista.size(); ++i) {
        if(lista[i].datos.nombre == nombre){
            lista[i] = personajeActualizado;
            break;
        }
    }

    QString ruta = QDir::homePath() + "/Documents/personajes.txt";
    QFile archivo(ruta);
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&archivo);
        for(const Cyberpunk &personaje:lista){
            out<<personaje.serializar()<<"\n";
        }
        archivo.close();
    }
    accept();
}

void ventanaEditar::on_vidaActual_label_valueChanged(int vidaActual)
{
    int empatia = vidaActual/10;
    ui->empatia_label->setText(QString::number(empatia));
    ui->vidaActual_label->setValue(vidaActual);
}

void ventanaEditar::rangoMaximo()
{
    int humanidad = ui->humanidad_label->value();
    int empatiaMax = ui->empatiaMax_SpinBox->text().toInt();
    int rangoHumanidad = empatiaMax * 10;
    if(humanidad > rangoHumanidad){
        ui->humanidad_label->setValue(rangoHumanidad);
    }

    int suerte = ui->suerteAct_label->value();
    int suerteMax = ui->suerteMax_SpinBox->text().toInt();
    int rangoSuerte = suerteMax;
    if(suerte > rangoSuerte){
        ui->suerteAct_label->setValue(rangoSuerte);
    }
}

