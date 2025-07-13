#ifndef PESONAJE_H
#define PESONAJE_H
#include <QString>
using namespace std;
struct Estadisticas {
    int inteligencia;
    int reflejos;
    int destreza;
    int tecnica;
    int frialdad;
    int voluntad;
    int suerte;
    int suerteMax;
    int movimiento;
    int tipoCorporal;
    int empatia;
    int empatiaMax;
};

struct Datos {
    QString nombre;
    QString rol;
    QString habilidadRol;
    int nivelHabilidad;
    int humanidad;
    int puntosMejora;
};

struct Estado {
    int vidaMaxima;
    int vidaActual;
    int armaduraCabeza;
    int armaduraCuerpo;
};

struct Cyberpunk {
    QString nombre;
    Datos datos;
    Estadisticas base;
    Estado estado;
};
#endif // PESONAJE_H
