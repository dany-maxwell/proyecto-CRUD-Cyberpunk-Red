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
    connect(ui->rol_comboBox, &QComboBox::currentIndexChanged, this, &ventanAgregar::actualizarAptRol);
    connect(ui->Armadura1_comboBox, &QComboBox::currentIndexChanged, this, &ventanAgregar::ActualizarArmaduraP1);
    connect(ui->Armadura2_comboBox, &QComboBox::currentIndexChanged, this, &ventanAgregar::ActualizarArmaduraP2);
    connect(ui->Armadura3_comboBox, &QComboBox::currentIndexChanged, this, &ventanAgregar::ActualizarArmaduraP3);
}

QMap<QString, QString> RolesyAptRol = {
    {"Rockero","Impacto Carismático"},
    {"Mercenario","Conciencia de Combate"},
    {"Netrunner","Interface"},
    {"Técnico","Manipulación"},
    {"TecnoMédico","Medicina"},
    {"Periodista","Credibilidad"},
    {"Corpo","Recursos"},
    {"Policía","Apoyo"},
    {"Fixer","Gestión"},
    {"Nómada","Motor"}
};

QMap<QString, QString> ArmadurasP = {
    {"Ligera","Sin penalizador"},
    {"Pesada","Menor Movimiento"},
    {"Blindada","Menor Reflejos"}
};

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
    skill.suerteMax = ui->suerteMax_SpinBox->value();
    skill.suerte = ui->suerteAct_label->text().toInt();
    skill.movimiento = ui->movilidadSpinBox->value();
    skill.tipoCorporal = ui->tipo_corporalSpinBox->value();
    skill.empatiaMax = ui->empatiaMax_SpinBox->value();
    skill.empatia = ui->empatia_label->text().toInt();
    Datos nuevo;
    nuevo.nombre = ui->nombreLineEdit->text();
    nuevo.rol = ui->rol_comboBox->currentText();
    nuevo.aptitudRol = ui->aptRol_label->text();
    nuevo.rango = ui->rango_label->text().toInt();
    nuevo.humanidad = ui->humanidad_label->text().toInt();
    nuevo.puntosMejora = ui->punto_label->text().toInt();
    Estado condicion;
    condicion.vidaMaxima = ui->vidaMax_label->text().toInt();
    condicion.vidaActual = ui->vidaActual_label->text().toInt();
    condicion.heridasCriticas = ui->herCrit_lineedit->text();
    condicion.salvacionMuerte = ui->svMuerte_label->text().toInt();
    condicion.gravedadHeridas = ui->heridas_label->text().toInt();
    condicion.adicciones = ui->Adicc_lineedit->text();
    condicion.armaduraCabeza = ui->Armadura1_comboBox->currentText();
    condicion.armaduraCuerpo = ui->Armadura2_comboBox->currentText();
    condicion.escudo = ui->Armadura3_comboBox->currentText();
    condicion.proteccionCabeza = ui->cp1_spinBox->value();
    condicion.proteccionCuerpo = ui->cp2_spinBox->value();
    condicion.proteccionEscudo = ui->cp3_spinBox->value();
    condicion.penCabeza = ui->Armadura1pn_label->text();
    condicion.penCuerpo = ui->Armadura2pn_label->text();
    condicion.penEscudo = ui->Armadura3pn_label->text();
    Armas nou_arma1;
    nou_arma1.tipo = ui->Arma1_comboBox->currentText();
    nou_arma1.daño = ui->Arma1d_lineEdit->text();
    nou_arma1.municion = ui->munic1_spinBox->value();
    nou_arma1.cdt = ui->cdt1_spinBox->value();
    nou_arma1.armaRango = ui->armaRango_spinBox->value();
    Armas nou_arma2;
    nou_arma2.tipo = ui->Arma2_comboBox->currentText();
    nou_arma2.daño = ui->Arma2d_lineEdit->text();
    nou_arma2.municion = ui->munic2_spinBox->value();
    nou_arma2.cdt = ui->cdt2_spinBox->value();
    nou_arma2.armaRango = ui->arma2Rango_spinBox->value();
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
    //para extraer la ruta de la pfp elegida
    nuevoPersonaje.rutaIcon = ui->galeriaPersonajes_comboBox
                                  ->itemData(ui->galeriaPersonajes_comboBox->currentIndex(), Qt::UserRole).toString(); //para guardar la truta como texto

    //para generar la ruta para poder guardarla
    QString rutaEnArchivo = QDir::homePath() + "/Documents/personajes.txt";

    this->nuevoPersonaje = nuevoPersonaje;

    accept();
}
void ventanAgregar::ActualizarArmaduraP1(){
    QString tipoSeleccionado = ui->Armadura1_comboBox->currentText();
    QString penalizador = ArmadurasP.value(tipoSeleccionado,"");
    ui->Armadura1pn_label->setText(penalizador);
}

void ventanAgregar::ActualizarArmaduraP2(){
    QString tipoSeleccionado = ui->Armadura2_comboBox->currentText();
    QString penalizador = ArmadurasP.value(tipoSeleccionado,"");
    ui->Armadura2pn_label->setText(penalizador);
}
void ventanAgregar::ActualizarArmaduraP3(){
    QString tipoSeleccionado = ui->Armadura3_comboBox->currentText();
    QString penalizador = ArmadurasP.value(tipoSeleccionado,"");
    ui->Armadura3pn_label->setText(penalizador);
}

void ventanAgregar::actualizarAptRol(){
    QString rolSeleccionado = ui->rol_comboBox->currentText();
    QString aptRol = RolesyAptRol.value(rolSeleccionado,"");
    ui->aptRol_label->setText(aptRol);
}

void ventanAgregar::on_suerteMax_SpinBox_valueChanged(int suerteMax)
{
    ui->suerteAct_label->setText(QString::number(suerteMax));
}


void ventanAgregar::on_empatiaMax_SpinBox_valueChanged(int empMax)
{
    int humanidad=empMax * 10;
    ui->humanidad_label->setText(QString::number(humanidad));
    ui->empatia_label->setText(QString::number(empMax));
}


void ventanAgregar::on_voluntadSpinBox_valueChanged(int voluntad)
{
    int tipoCorporal = ui->tipo_corporalSpinBox->value();
    int vidaMax = (voluntad + tipoCorporal)*10;
    ui->vidaMax_label->setText(QString::number(vidaMax));
    ui->vidaActual_label->setText(QString::number(vidaMax));
}


void ventanAgregar::on_tipo_corporalSpinBox_valueChanged(int tipoCorporal)
{
    int voluntad = ui->voluntadSpinBox->value();
    int vidaMax = (tipoCorporal + voluntad)*10;
    ui->vidaMax_label->setText(QString::number(vidaMax));
    ui->vidaActual_label->setText(QString::number(vidaMax));
    ui->svMuerte_label->setText(QString::number(tipoCorporal));
}

void ventanAgregar::on_Descartar_clicked()
{
    close();
}
