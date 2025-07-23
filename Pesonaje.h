#ifndef PESONAJE_H
#define PESONAJE_H
#include <QString>
#include <QStringList>
#include <QTextStream>
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
struct Armas {
    QString tipo;
    QString daño;
    int municion;
    int cdt;
    int armaRango;
};
struct Datos {
    QString nombre;
    QString rol;
    QString aptitudRol;
    int humanidad;
    int puntosMejora;
    int rango;
};

struct Estado {
    int vidaMaxima;
    int vidaActual;
    int salvacionMuerte;
    int gravedadHeridas;
    QString heridasCriticas;
    QString adicciones;
    QString armaduraCabeza;
    QString armaduraCuerpo;
    int proteccionCabeza;
    int proteccionCuerpo;
    QString escudo;
    int proteccionEscudo;
    QString penCabeza;
    QString penCuerpo;
    QString penEscudo;
};

struct Cyberware {
    QString cyberware1;
    QString cyberware2;
    QString cyberware3;
    QString cyberware4;
    QString cyberware5;
};

struct Cyberpunk {
    Datos datos;
    Estadisticas base;
    Estado estado;
    Armas arma;
    Armas arma2;
    Cyberware cyberware;
    QString serializar() const {
        return datos.nombre + "," +
               datos.rol + "," + datos.aptitudRol + "," +
               QString::number(datos.rango) + "," +
               QString::number(datos.puntosMejora) + "," +
               QString::number(datos.humanidad) + "," +

               QString::number(base.inteligencia) + "," +
               QString::number(base.reflejos) + "," +
               QString::number(base.destreza) + "," +
               QString::number(base.tecnica) + "," +
               QString::number(base.frialdad) + "," +
               QString::number(base.voluntad) + "," +
               QString::number(base.suerte) + "," +
               QString::number(base.suerteMax) + "," +
               QString::number(base.movimiento) + "," +
               QString::number(base.tipoCorporal) + "," +
               QString::number(base.empatia) + "," +
               QString::number(base.empatiaMax) + "," +

               QString::number(estado.vidaMaxima) + "," +
               QString::number(estado.vidaActual) + "," +
               QString::number(estado.salvacionMuerte) + "," +
               QString::number(estado.gravedadHeridas) + "," +
               estado.heridasCriticas + "," +
               estado.adicciones + "," +
               estado.armaduraCabeza + "," +
               QString::number(estado.proteccionCabeza) + "," +
               estado.penCabeza + "," +
               estado.armaduraCuerpo + "," +
               QString::number(estado.proteccionCuerpo) + "," +
               estado.penCuerpo + "," +
               estado.escudo + "," +
               QString::number(estado.proteccionEscudo) + "," +
               estado.penEscudo + "," +

               arma.tipo + "," + arma.daño + "," +
               QString::number(arma.municion) + "," +
               QString::number(arma.cdt) + "," +
               QString::number(arma.armaRango) + "," +
               arma2.tipo + "," + arma2.daño + "," +
               QString::number(arma2.municion) + "," +
               QString::number(arma2.cdt) + "," +
               QString::number(arma2.armaRango) + "," +

               cyberware.cyberware1 + "," +
               cyberware.cyberware2 + "," +
               cyberware.cyberware3 + "," +
               cyberware.cyberware4 + "," +
               cyberware.cyberware5;
    }

    static Cyberpunk deserializar(const QString &linea) {
        QStringList p = linea.split(",");
        if (p.size() < 48) return {};

        Cyberpunk c;
        int i = 0;

        c.datos.nombre = p[i++];
        c.datos.rol = p[i++];
        c.datos.aptitudRol = p[i++];
        c.datos.humanidad = p[i++].toInt();
        c.datos.puntosMejora = p[i++].toInt();
        c.datos.rango = p[i++].toInt();

        c.base.inteligencia = p[i++].toInt();
        c.base.reflejos = p[i++].toInt();
        c.base.destreza = p[i++].toInt();
        c.base.tecnica = p[i++].toInt();
        c.base.frialdad = p[i++].toInt();
        c.base.voluntad = p[i++].toInt();
        c.base.suerte = p[i++].toInt();
        c.base.suerteMax = p[i++].toInt();
        c.base.movimiento = p[i++].toInt();
        c.base.tipoCorporal = p[i++].toInt();
        c.base.empatia = p[i++].toInt();
        c.base.empatiaMax = p[i++].toInt();

        c.estado.vidaMaxima = p[i++].toInt();
        c.estado.vidaActual = p[i++].toInt();
        c.estado.armaduraCabeza = p[i++];
        c.estado.armaduraCuerpo = p[i++];
        c.estado.escudo = p[i++];
        c.estado.salvacionMuerte = p[i++].toInt();
        c.estado.gravedadHeridas = p[i++].toInt();
        c.estado.heridasCriticas = p[i++];
        c.estado.adicciones = p[i++];

        c.arma.tipo = p[i++];
        c.arma.daño = p[i++];
        c.arma.municion = p[i++].toInt();
        c.arma.cdt = p[i++].toInt();
        c.arma.armaRango = p[i++].toInt();

        c.arma2.tipo = p[i++];
        c.arma2.daño = p[i++];
        c.arma2.municion = p[i++].toInt();
        c.arma2.cdt = p[i++].toInt();
        c.arma2.armaRango = p[i++].toInt();

        c.cyberware.cyberware1 = p[i++];
        c.cyberware.cyberware2 = p[i++];
        c.cyberware.cyberware3 = p[i++];
        c.cyberware.cyberware4 = p[i++];
        c.cyberware.cyberware5 = p[i++];
        return c;
    }
};
#endif // PESONAJE_H

