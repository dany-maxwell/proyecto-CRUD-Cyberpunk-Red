#include "charactersheetmanager.h"
#include "ventanagregar.h"
#include "./ui_charactersheetmanager.h"

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
    ventanAgregar *ventana = new ventanAgregar(this);
    ventana->show();
}

