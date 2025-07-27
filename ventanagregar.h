#ifndef VENTANAGREGAR_H
#define VENTANAGREGAR_H
#include "Pesonaje.h"
#include <QDialog>
class CharacterSheetManager;

namespace Ui {
class ventanAgregar;
}

class ventanAgregar : public QDialog
{
    Q_OBJECT

public:
    explicit ventanAgregar(QWidget *parent = nullptr, CharacterSheetManager *main = nullptr);
    ~ventanAgregar();
    CharacterSheetManager* mainRef;
    QList<Cyberpunk> personajes;
    Cyberpunk nuevoPersonaje;


private:
    Ui::ventanAgregar *ui;
    //QList<Cyberpunk> personajes;
private slots:
    void agregarPersonaje();
    void on_Descartar_clicked();
    void actualizarAptRol();
    void ActualizarArmaduraP1();
    void ActualizarArmaduraP2();
    void ActualizarArmaduraP3();
    void on_suerteMax_SpinBox_valueChanged(int suerteMax);
    void on_empatiaMax_SpinBox_valueChanged(int empMax);
    void on_voluntadSpinBox_valueChanged(int voluntad);
    void on_tipo_corporalSpinBox_valueChanged(int tipoCorporal);
};


#endif // VENTANAGREGAR_H
