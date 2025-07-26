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

    ui->inteligenciaSpinBox->setRange(0,10);
    ui->destrezaSpinBox->setRange(0,10);
    ui->voluntadSpinBox->setRange(0,10);
    ui->empatiaMax_SpinBox->setRange(0,10);
    ui->frialdadSpinBox->setRange(0,10);
    ui->tecnicaSpinBox->setRange(0,10);
    ui->tipo_corporalSpinBox->setRange(0,10);
    ui->movilidadSpinBox->setRange(0,10);
    ui->suerteMax_SpinBox->setRange(0,10);
    ui->reflejosSpinBox->setRange(0,10);
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
    nou_arma1.armaRango = ui->armaRango_spinBox->value();
    Armas nou_arma2;
    nou_arma2.tipo = ui->Arma2_lineEdit->text();
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

    //para extraer la ruta de la pfp elegida
    nuevoPersonaje.rutaIcon = ui->galeriaPersonajes_comboBox
                                  ->itemData(ui->galeriaPersonajes_comboBox->currentIndex(), Qt::UserRole).toString(); //para guardar la truta como texto

    //para generar la ruta para poder guardarla
    QString rutaEnArchivo = QDir::homePath() + "/Documents/personajes.txt";

    this->nuevoPersonaje = nuevoPersonaje;

    accept();
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

Cyberpunk ventanAgregar::personajEditado() const{
    Cyberpunk editado;
    editado.base.inteligencia = ui->inteligenciaSpinBox->value();
    editado.base.destreza = ui->destrezaSpinBox->value();
    editado.base.empatia = ui->empatia_label->text().toInt();
    editado.base.empatiaMax = ui->empatiaMax_SpinBox->value();
    editado.base.frialdad = ui->frialdadSpinBox->value();
    editado.base.movimiento = ui->movilidadSpinBox->value();
    editado.base.reflejos = ui->reflejosSpinBox->value();
    editado.base.suerte = ui->suerteAct_label->text().toInt();
    editado.base.suerteMax = ui->suerteMax_SpinBox->value();
    editado.base.tecnica = ui->tecnicaSpinBox->value();
    editado.base.tipoCorporal = ui->tipo_corporalSpinBox->value();
    editado.base.voluntad = ui->voluntadSpinBox->value();

    editado.datos.nombre = ui->nombreLineEdit->text();
    editado.datos.rol = ui->rol_comboBox->currentText();
    editado.datos.aptitudRol = ui->aptRol_label->text();
    editado.datos.rango = ui->rango_label->text().toInt();
    editado.datos.humanidad = ui->humanidad_label->text().toInt();
    editado.datos.puntosMejora = ui->punto_label->text().toInt();

    editado.estado.vidaActual = ui->vidaActual_label->text().toInt();
    editado.estado.vidaMaxima = ui->vidaMax_label->text().toInt();
    editado.estado.heridasCriticas = ui->herCrit_lineedit->text();
    editado.estado.gravedadHeridas = ui->heridas_label->text().toInt();
    editado.estado.adicciones = ui->Adicc_lineedit->text();
    editado.estado.salvacionMuerte = ui->svMuerte_label->text().toInt();

    editado.estado.armaduraCabeza = ui->Armadura1_lineEdit->text();
    editado.estado.armaduraCuerpo = ui->Armadura2_lineEdit->text();
    editado.estado.escudo = ui->Armadura3_lineEdit->text();
    editado.estado.proteccionCabeza = ui->cp1_spinBox->value();
    editado.estado.proteccionCuerpo = ui->cp2_spinBox->value();
    editado.estado.proteccionEscudo = ui->cp3_spinBox->value();
    editado.estado.penCabeza = ui->Armadura1pn_lineEdit->text();
    editado.estado.penCuerpo = ui->Armadura2pn_lineEdit->text();
    editado.estado.penEscudo = ui->Armadura3pn_lineEdit->text();

    editado.arma.tipo = ui->Arma1_lineEdit->text();
    editado.arma2.tipo = ui->Arma2_lineEdit->text();
    editado.arma.daño = ui->Arma1d_lineEdit->text();
    editado.arma2.daño = ui->Arma2d_lineEdit->text();
    editado.arma.cdt = ui->cdt1_spinBox->value();
    editado.arma2.cdt = ui->cdt2_spinBox->value();
    editado.arma.municion = ui->munic1_spinBox->value();
    editado.arma2.municion = ui->munic2_spinBox->value();
    editado.arma.armaRango = ui->armaRango_spinBox->value();
    editado.arma2.armaRango = ui->arma2Rango_spinBox->value();

    editado.cyberware.cyberware1 = ui->ciber_lineEdit->text();
    editado.cyberware.cyberware2 = ui->ciber_lineEdit_2->text();
    editado.cyberware.cyberware3 = ui->ciber_lineEdit_3->text();
    editado.cyberware.cyberware4 = ui->ciber_lineEdit_4->text();
    editado.cyberware.cyberware5 = ui->ciber_lineEdit_5->text();

    editado.rutaIcon = ui->galeriaPersonajes_comboBox
                           ->itemData(ui->galeriaPersonajes_comboBox->currentIndex(), Qt::UserRole).toString();

    return editado;
}
