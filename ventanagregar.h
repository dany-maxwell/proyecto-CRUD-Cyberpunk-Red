#ifndef VENTANAGREGAR_H
#define VENTANAGREGAR_H

#include <QDialog>

namespace Ui {
class ventanAgregar;
}

class ventanAgregar : public QDialog
{
    Q_OBJECT

public:
    explicit ventanAgregar(QWidget *parent = nullptr);
    ~ventanAgregar();

private:
    Ui::ventanAgregar *ui;
};

#endif // VENTANAGREGAR_H
