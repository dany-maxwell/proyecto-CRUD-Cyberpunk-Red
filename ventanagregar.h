#ifndef VENTANAGREGAR_H
#define VENTANAGREGAR_H
#include <QDialog>
#include "charactersheetmanager.h"
namespace Ui {
class ventanAgregar;
}

class ventanAgregar : public QDialog
{
    Q_OBJECT

public:
    explicit ventanAgregar(CharacterSheetManager *manager, QWidget *parent = nullptr);

    ~ventanAgregar();
    CharacterSheetManager* mainRef = nullptr;

private:
    Ui::ventanAgregar *ui;
    CharacterSheetManager *managerRef;

private slots:
    void agregarPersonaje();

    void on_inteligenciaSpinBox_valueChanged(int arg1);
    void on_Descartar_clicked();
};
#endif // VENTANAGREGAR_H
