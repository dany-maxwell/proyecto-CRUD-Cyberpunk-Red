#include "charactersheetmanager.h"
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
