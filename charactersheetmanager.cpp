#include "charactersheetmanager.h"
#include "ventanagregar.h"
#include "./ui_charactersheetmanager.h"
#include "Pesonaje.h"
#include <QFile>

CharacterSheetManager::CharacterSheetManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CharacterSheetManager)
{
    ui->setupUi(this);
}

CharacterSheetManager::~CharacterSheetManager()
{
    delete ui;
}

void CharacterSheetManager::on_Agregar_clicked()
{
    ventanAgregar *ventana = new ventanAgregar(this, this);
    ventana->exec();
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
        }
        archivo.close();
    }
}


void CharacterSheetManager::agregarPersonaje(const Cyberpunk &nuevo) {
    personajes.append(nuevo);
}




