#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QStringList>
#include "databaseadmin.h"

namespace Ui {
class RegCosecha;
}

class RegCosecha : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegCosecha(QWidget *parent = 0);
    ~RegCosecha();

private:
    Ui::RegCosecha *ui;

    /**
     * @brief dbCampos - Administrador de base de datos para la lista de campos
     */
    QSqlDatabase dbCampos;

    /**
     * @brief dbRegistros - Administrador de bases de datos para el registro de las cosechas
     */
    QSqlDatabase dbRegistros;

    /**
     * @brief cargarCampos - Funcion que carga en el combo-box la lista de campos
     * Es llamada en el constructor.
     */
    void cargarCampos();

    /**
     * @brief paintEvent - Funcion dibujadora de la interfaz de usuario
     */
    void paintEvent(QPaintEvent *e);

private slots:
    //TODO
    void slot_pbAgregar();
};
