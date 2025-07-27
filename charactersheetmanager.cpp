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
#include <QMessageBox>

CharacterSheetManager::CharacterSheetManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CharacterSheetManager)
{
    ui->setupUi(this);
    comprobarLista();
    connect(ui->listaPersonajes, &QListWidget::itemClicked,this, &CharacterSheetManager::abrirVentanaEditar);
}

CharacterSheetManager::~CharacterSheetManager()
{
    delete ui;
}

void CharacterSheetManager::comprobarLista(){
    QString ruta = QDir::homePath() + "/Documents/personajes.txt";
    cargarPersonajesDesdeArchivo(ruta);
    if (personajes.size() == 0){
        ui->LISTA->hide();
    }
    else{
        ui->LISTA->show();
    }
    crearLista();
    this->adjustSize();
}

void CharacterSheetManager::on_Agregar_clicked()
{
    ventanAgregar ventana(this, this);

    if (ventana.exec() == QDialog::Accepted) {
        Cyberpunk nuevo = ventana.nuevoPersonaje;
        agregarPersonaje(nuevo);
        agregarPersonajeALaLista(nuevo);
        guardarPersonajesEnArchivo(QDir::homePath() + "/Documents/personajes.txt");
        comprobarLista();
    }
}

void CharacterSheetManager::on_Salir_clicked()
{
    close();
}

void CharacterSheetManager::guardarPersonajesEnArchivo(const QString &rutaArchivo) {
    QFile archivo(rutaArchivo);
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&archivo);
        for (const Cyberpunk &personaje : personajes){
            out << personaje.serializar() << "\n";
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
        }
        archivo.close();
    }
}

void CharacterSheetManager::agregarPersonaje(const Cyberpunk &nuevo) {
    personajes.append(nuevo);
}

void CharacterSheetManager::agregarPersonajeALaLista(const Cyberpunk& personaje) {
    ui->listaPersonajes->addItem(personaje.datos.nombre);
}

//para actualizar la lista mostrada en el menú principal
void CharacterSheetManager::crearLista(){
    ui->listaPersonajes->clear();
    for (const Cyberpunk& personaje : personajes) {
        ui->listaPersonajes->addItem(personaje.datos.nombre);
    }
}

void CharacterSheetManager::abrirVentanaEditar(QListWidgetItem *item){
    QString nombre = item->text();
    ventanaEditar *ventana = new ventanaEditar(nombre, personajes, this);
    connect(ventana, &ventanaEditar::personajeEliminado, this, [=](const QString &nombre){
        for (int i = 0; i < personajes.size(); ++i) {
            if (personajes[i].datos.nombre == nombre) {
                personajes.removeAt(i);
                break;
            }
        }
        guardarPersonajesEnArchivo(QDir::homePath() + "/Documents/personajes.txt");
        comprobarLista();
    });

    ventana->show();
}
