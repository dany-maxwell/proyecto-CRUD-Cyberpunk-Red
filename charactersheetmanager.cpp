#include "charactersheetmanager.h"
#include "ventanagregar.h"
#include "ventanaeditar.h"
#include "./ui_charactersheetmanager.h"
#include "Pesonaje.h"
#include <QFile>
#include <QDir>
#include <QObject>
#include <QPushButton>
#include <QDebug>

CharacterSheetManager::CharacterSheetManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CharacterSheetManager)
{
    ui->setupUi(this);
    QString ruta = QDir::homePath() + "/Documents/personajes.txt";
    cargarPersonajesDesdeArchivo(ruta);
    comprobarLista();
}

CharacterSheetManager::~CharacterSheetManager()
{
    delete ui;
}

void CharacterSheetManager::comprobarLista(){
    if (personajes.size() == 0){
        ui->LISTA->hide();
    }
    else{
        ui->LISTA->show();
    }
    this->adjustSize();
}

void CharacterSheetManager::on_Agregar_clicked()
{
    ventanAgregar *ventana = new ventanAgregar(this, this);
    ventana->mainRef = this;
    ventana->exec();
    comprobarLista();
}


void CharacterSheetManager::on_Salir_clicked()
{
    close();
}

void CharacterSheetManager::guardarPersonajesEnArchivo(const QString &rutaArchivo) {
    QFile archivo(rutaArchivo);
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&archivo);
        for (int i = 0; i < personajes.size(); ++i){
            out << personajes.at(i).serializar() << "\n";
        }
        archivo.close();
    }
}

void CharacterSheetManager::cargarPersonajesDesdeArchivo(const QString &rutaArchivo) {
    QFile archivo(rutaArchivo);
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        personajes.clear();
        QTextStream in(&archivo);
        while (!in.atEnd()) {
            QString linea = in.readLine();
            Cyberpunk personaje = Cyberpunk::deserializar(linea);
            personajes.append(personaje);
            agregarPersonajeEnLista(personaje);
        }
        archivo.close();
    }
}


void CharacterSheetManager::agregarPersonaje(const Cyberpunk &nuevo) {
    personajes.append(nuevo);
}

void CharacterSheetManager::agregarPersonajeEnLista(const Cyberpunk nou){
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->layoutlista->layout());
    if (layout){
        QPushButton* personaje = new QPushButton(nou.datos.nombre+" "+ nou.datos.rol);
        personaje->setProperty("nombre",nou.datos.nombre);
        personaje->setFixedHeight(30);
        personaje->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        personaje->setStyleSheet(
            "QPushButton{"
                "color: lightgray;"
                "background-color: #111111;"
                "border: 1px solid red;"
                "padding-left: 10px;"
                "font-weight: bold;"
                "text-align: left;"
            "}"
            "QPushButton:hover{"
                "background-color: #000000;"
            "}"
        );
        connect(personaje, &QPushButton::clicked, this, &CharacterSheetManager::abrirVentanaEditar);
        layout->addWidget(personaje);
        layout->setSpacing(5);
        layout->setContentsMargins(5, 5, 5, 5);
        layout->setAlignment(Qt::AlignTop);
    }
}

void CharacterSheetManager::abrirVentanaEditar(){
    QPushButton *botn = qobject_cast<QPushButton*>(sender());
    ventanaEditar *ventana = new ventanaEditar(botn, this);
    ventana->show();
}
