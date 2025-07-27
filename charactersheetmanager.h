#ifndef CHARACTERSHEETMANAGER_H
#define CHARACTERSHEETMANAGER_H
#include "Pesonaje.h"
#include <QDialog>
#include <QMainWindow>
#include <qlistwidget.h>

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
    void agregarPersonajeALaLista(const Cyberpunk& personaje);
    void eliminarpersonaje(const Cyberpunk &eliminado);
    void guardarPersonajesEnArchivo(const QString &rutaArchivo);
    void cargarPersonajesDesdeArchivo(const QString &rutaArchivo);
    void comprobarLista();

private slots:
    void on_Agregar_clicked();
    void on_Salir_clicked();
    void abrirVentanaEditar(QListWidgetItem *item);
    void crearLista();


private:
    Ui::CharacterSheetManager *ui;
    QList<Cyberpunk> personajes;

};
#endif // CHARACTERSHEETMANAGER_H
