#include "ventanagregar.h"
#include "ui_ventanagregar.h"
#include "Pesonaje.h"
#include "QMessageBox"
#include "charactersheetmanager.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDir>

ventanAgregar::ventanAgregar(QWidget *parent, CharacterSheetManager *main)
    : QDialog(parent)
    , ui(new Ui::ventanAgregar)
    , mainRef(main)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);

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

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widget->layout());

    if (layout) {
        QLabel* ejemplo = new QLabel("Texto de prueba dentro del scroll");
        layout->addWidget(ejemplo);
    }

    this->resize(this->size());
    connect(ui->minimizarButton, &QPushButton::clicked, this, &QWidget::showMinimized);
}


ventanAgregar::~ventanAgregar()
{
    delete ui;
}

void ventanAgregar::agregarPersonaje() {
    Estadisticas skill;
    skill.inteligencia = ui->inteligenciaSpinBox->value();
    skill.reflejos = ui->reflejosSpinBox->value();
    skill.destreza = ui->destrezaSpinBox->value();
    skill.tecnica = ui->tecnicaSpinBox->value();
    skill.frialdad = ui->frialdadSpinBox->value();
    skill.voluntad = ui->voluntadSpinBox->value();
    skill.suerteMax = ui->suerteSpinBox_2->value();
    skill.suerte = skill.suerteMax;
    ui->suerteSpinBox->setValue(skill.suerte);
    skill.movimiento = ui->movilidadSpinBox->value();
    skill.tipoCorporal = ui->tipo_corporalSpinBox->value();
    skill.empatiaMax = ui->empatiaSpinBox->value();
    Datos nuevo;
    nuevo.nombre = ui->nombreLineEdit->text();
    nuevo.rol = ui->rolLineEdit->text();
    nuevo.aptitudRol = ui->rolApt_lineEdit->text();
    nuevo.rango = ui->rango_spinBox->value();
    nuevo.humanidad = skill.empatiaMax*10;
    skill.empatia=nuevo.humanidad/10;
    Estado condicion;
    condicion.vidaMaxima = (skill.voluntad+skill.tipoCorporal)*5;
    condicion.vidaActual = condicion.vidaMaxima;
    condicion.heridasCriticas = ui->herCrit_lineedit->text();
    condicion.salvacionMuerte = skill.tipoCorporal;
    condicion.gravedadHeridas = ui->heridas_spinBox->value();
    condicion.adicciones = ui->Adicc_lineedit->text();
    condicion.armaduraCabeza = ui->Armadura1_lineEdit->text();
    condicion.armaduraCuerpo = ui->Armadura2_lineEdit->text();
    condicion.escudo = ui->Armadura3_lineEdit->text();
    condicion.proteccionCabeza = ui->cp1_spinBox->value();
    condicion.proteccionCuerpo = ui->cp2_spinBox->value();
    condicion.proteccionEscudo = ui->cp3_spinBox->value();
    condicion.penCabeza = ui->Armadura1pn_lineEdit->text();
    condicion.penCuerpo = ui->Armadura2pn_lineEdit->text();
    condicion.penEscudo = ui->Armadura3pn_lineEdit->text();
    Armas nou_arma1;
    nou_arma1.tipo = ui->Arma1_lineEdit->text();
    nou_arma1.daño = ui->Arma1d_lineEdit->text();
    nou_arma1.municion = ui->munic1_spinBox->value();
    nou_arma1.cdt = ui->cdt1_spinBox->value();
    Armas nou_arma2;
    nou_arma2.tipo = ui->Arma2_lineEdit->text();
    nou_arma2.daño = ui->Arma2d_lineEdit->text();
    nou_arma2.municion = ui->munic2_spinBox->value();
    nou_arma2.cdt = ui->cdt2_spinBox->value();
    Cyberware lcyberware;
    lcyberware.cyberware1 = ui->ciber_lineEdit->text();
    lcyberware.cyberware2 = ui->ciber_lineEdit_2->text();
    lcyberware.cyberware3 = ui->ciber_lineEdit_3->text();
    lcyberware.cyberware4 = ui->ciber_lineEdit_4->text();
    lcyberware.cyberware5 = ui->ciber_lineEdit_5->text();
    Cyberpunk nuevoPersonaje;
    nuevoPersonaje.base=skill;
    nuevoPersonaje.datos=nuevo;
    nuevoPersonaje.estado=condicion;
    nuevoPersonaje.arma=nou_arma1;
    nuevoPersonaje.arma2=nou_arma2;
    nuevoPersonaje.cyberware=lcyberware;
    mainRef->agregarPersonaje(nuevoPersonaje);
    QString ruta = QDir::homePath() + "/Documents/personajes.txt";
    mainRef->guardarPersonajesEnArchivo(ruta);
    QString resumen = "Personaje agregado exitosamente";
    QMessageBox::information(this, "Éxito", resumen);

    mainRef->agregarPersonajeEnLista(nuevoPersonaje);
    this->close();
}

void ventanAgregar::on_Descartar_clicked()
{
    close();
}
