#ifndef VENTANAEDITAR_H
#define VENTANAEDITAR_H

#include <QDialog>
//#include "Pesonaje.h"
#include "ventanagregar.h"
#include "charactersheetmanager.h"
#include <QList>
namespace Ui {
class ventanaEditar;
}

class ventanaEditar : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaEditar(const QString& nombre, QList<Cyberpunk>& listaRef, QWidget *parent = nullptr);
    CharacterSheetManager* mainRef;
    ventanAgregar* secRef;
    ~ventanaEditar();

private:
    Ui::ventanaEditar *ui;
    void leerPersonaje();
    QString nombre;
    QList<Cyberpunk> &lista;
};

#endif // VENTANAEDITAR_H
