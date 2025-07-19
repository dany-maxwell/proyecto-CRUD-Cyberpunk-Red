#ifndef CHARACTERSHEETMANAGER_H
#define CHARACTERSHEETMANAGER_H
#include "Pesonaje.h"
#include <QDialog>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CharacterSheetManager;
}
QT_END_NAMESPACE

class CharacterSheetManager : public QMainWindow
{
    Q_OBJECT

public:
    CharacterSheetManager(QWidget *parent = nullptr);
    ~CharacterSheetManager();
    void agregarPersonaje(const Cyberpunk &nuevo);
    void guardarPersonajesEnArchivo(const QString &rutaArchivo);
    void cargarPersonajesDesdeArchivo(const QString &rutaArchivo);
    void agregarPersonajeEnLista(const Cyberpunk nou);
    void comprobarLista();

private slots:
    void on_Agregar_clicked();
    void on_Salir_clicked();

private:
    Ui::CharacterSheetManager *ui;
    QList<Cyberpunk> personajes;

};
#endif // CHARACTERSHEETMANAGER_H
