#include "ventanagregar.h"
#include "ui_ventanagregar.h"
#include "Pesonaje.h"
#include "QMessageBox"
#include "charactersheetmanager.h"


ventanAgregar::ventanAgregar(QWidget *parent, CharacterSheetManager *main)
    : QDialog(parent)
    , ui(new Ui::ventanAgregar)
    , mainRef(main)
{
    ui->setupUi(this);
    QStringList rutas = {
        ":/img/imagenes/img31.jpg",
        ":/img/imagenes/img41.jpg",
        ":/img/imagenes/img51.jpg",
        ":/img/imagenes/img61.jpg",
        ":/img/imagenes/img75.jpg",
        ":/img/imagenes/img85.jpg",
        ":/img/imagenes/img95.jpg",
        ":/img/imagenes/img105.jpg",
        ":/img/imagenes/img115.jpg",
        ":/img/imagenes/img127.jpg"
    };
    //para tener un texto antes de desplgar la lista de icons
    ui->galeriaPersonajes_comboBox->addItem("Selecciona una imagen...");
    ui->galeriaPersonajes_comboBox->setCurrentIndex(0);
    //para mostrar las opciones, osea un salto a la posición 0
    connect(ui->galeriaPersonajes_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index){
        if (index == 0) return;

        QString ruta = ui->galeriaPersonajes_comboBox->itemData(index, Qt::UserRole).toString();
        if (!ruta.isEmpty()) {
            QPixmap pix(ruta);
            ui->iconPersonaje_label->setPixmap(pix.scaled(ui->iconPersonaje_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    });

    for (const QString &ruta : rutas) {
        QIcon icono(ruta);
        ui->galeriaPersonajes_comboBox->addItem(icono, "");
        ui->galeriaPersonajes_comboBox->setItemData(ui->galeriaPersonajes_comboBox->count() - 1, ruta, Qt::UserRole); // para guardar la ruta
    }

    ui->galeriaPersonajes_comboBox->setIconSize(QSize(64, 64));

    this->adjustSize();
    connect(ui->Guardar, &QPushButton::clicked, this, &ventanAgregar::agregarPersonaje);
}


ventanAgregar::~ventanAgregar()
{
    delete ui;
}

void ventanAgregar::agregarPersonaje() {
    Estadisticas Habilidad;
    Habilidad.inteligencia = ui->inteligenciaSpinBox->value();
    Habilidad.reflejos = ui->reflejosSpinBox->value();
    Habilidad.destreza = ui->destrezaSpinBox->value();
    Habilidad.tecnica = ui->tecnicaSpinBox->value();
    Habilidad.frialdad = ui->frialdadSpinBox->value();
    Habilidad.voluntad = ui->voluntadSpinBox->value();
    Habilidad.suerte = ui->suerteSpinBox->value();
    Habilidad.movimiento = ui->movilidadSpinBox->value();
    Habilidad.tipoCorporal = ui->tipo_corporalSpinBox->value();
    Datos nuevo;
    nuevo.rol = ui->rolLineEdit->text();
    Estado condicion;
    Cyberpunk nuevoPersonaje;
    nuevoPersonaje.nombre = ui->nombreLineEdit->text();
    nuevoPersonaje.base=Habilidad;
    nuevoPersonaje.datos=nuevo;
    nuevoPersonaje.estado=condicion;
    personajes.append(nuevoPersonaje);


    QString resumen = "Personaje agregado exitosamente";

    QMessageBox::information(this, "Éxito", resumen);

}


void ventanAgregar::on_Descartar_2_clicked()
{

}

