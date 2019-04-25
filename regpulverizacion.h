#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class RegPulverizacion;
}

class RegPulverizacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegPulverizacion(QWidget *parent = 0);
    ~RegPulverizacion();

private:
    Ui::RegPulverizacion *ui;

    /**
     * @brief dbCampos - Administrador de base de datos para la lista de campos
     */
    QSqlDatabase dbCampos;

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
