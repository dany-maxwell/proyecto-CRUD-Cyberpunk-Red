#include "ventanagregar.h"
#include "ui_ventanagregar.h"

ventanAgregar::ventanAgregar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ventanAgregar)
{
    ui->setupUi(this);
}

ventanAgregar::~ventanAgregar()
{
    delete ui;
}
