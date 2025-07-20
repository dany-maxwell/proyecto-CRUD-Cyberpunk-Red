#ifndef VENTANAEDITAR_H
#define VENTANAEDITAR_H

#include <QDialog>
//#include "Pesonaje.h"
#include "ventanagregar.h"
#include "charactersheetmanager.h"
namespace Ui {
class ventanaEditar;
}

class ventanaEditar : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaEditar(QPushButton *personaje, QWidget *parent = nullptr, CharacterSheetManager *main = nullptr, ventanAgregar *sec = nullptr);
    CharacterSheetManager* mainRef;
    ventanAgregar* secRef;
    ~ventanaEditar();

private:
    Ui::ventanaEditar *ui;
    void leerPersonaje();
    QString nombre;
};

#endif // VENTANAEDITAR_H
