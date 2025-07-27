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
    Cyberpunk personajEditado() const;
    ~ventanaEditar();

private slots:
    void on_Descartar_clicked();
    void on_Guardar_clicked();
    void on_humanidad_label_valueChanged(int humanidad);
    void rangoMaximo();
    void EditarArmaduraP1(int index);
    void EditarArmaduraP2(int index);
    void EditarArmaduraP3(int index);

    //void on_vidaActual_label_valueChanged(int arg1);

    void on_Eliminar_clicked();
    //void eliminarPersonaje();

signals:
    void personajeEliminado(const QString &nombre);

private:
    Ui::ventanaEditar *ui;
    void leerPersonaje();
    QString nombre;
    QList<Cyberpunk> &lista;
    QString rutaIcon;
};

#endif // VENTANAEDITAR_H
