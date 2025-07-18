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

private:
    Ui::ventanAgregar *ui;
    QList<Cyberpunk> personajes;
private slots:
    void agregarPersonaje();
    void on_Descartar_clicked();
};


#endif // VENTANAGREGAR_H
