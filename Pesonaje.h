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
};
struct Datos {
    QString rol;
    QString aptitudRol;
    int nivelHabilidad;
    int humanidad;
    int puntosMejora;
    int rango;

};

struct Estado {
    int vidaMaxima;
    int vidaActual;
    QString armaduraCabeza;
    QString armaduraCuerpo;
    QString escudo;
    QString extra;
    int salvacionMuerte;
    int gravedadHeridas;
    QString heridasCriticas;
    QString adicciones;
};

struct Cyberpunk {
    QString nombre;
    Datos datos;
    Estadisticas base;
    Estado estado;
    Armas arma;
    QString serializar() const {
        return nombre + "," +
               datos.rol + "," + datos.aptitudRol + "," +
               QString::number(datos.nivelHabilidad) + "," +
               QString::number(datos.humanidad) + "," +
               QString::number(datos.puntosMejora) + "," +
               QString::number(datos.rango) + "," +

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
               estado.armaduraCabeza + "," +
               estado.armaduraCuerpo + "," +
               estado.escudo + "," +
               estado.extra + "," +
               QString::number(estado.salvacionMuerte) + "," +
               QString::number(estado.gravedadHeridas) + "," +
               estado.heridasCriticas + "," +
               estado.adicciones + "," +

               arma.tipo + "," + arma.daño + "," +
               QString::number(arma.municion) + "," +
               QString::number(arma.cdt);
    }

    static Cyberpunk deserializar(const QString &linea) {
        QStringList p = linea.split(",");
        if (p.size() < 38) return {};

        Cyberpunk c;
        int i = 0;

        c.nombre = p[i++];
        c.datos.rol = p[i++];
        c.datos.aptitudRol = p[i++];
        c.datos.nivelHabilidad = p[i++].toInt();
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
        c.estado.extra = p[i++];
        c.estado.salvacionMuerte = p[i++].toInt();
        c.estado.gravedadHeridas = p[i++].toInt();
        c.estado.heridasCriticas = p[i++];
        c.estado.adicciones = p[i++];

        c.arma.tipo = p[i++];
        c.arma.daño = p[i++];
        c.arma.municion = p[i++].toInt();
        c.arma.cdt = p[i++].toInt();

        return c;
    }
};
#endif // PESONAJE_H

