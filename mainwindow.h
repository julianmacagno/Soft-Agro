#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QIcon>
#include <QMessageBox>
#include "regcosecha.h"
#include "regsiembra.h"
#include "regpulverizacion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    /**
     * @brief ventCosecha - Puntero a la ventana de registros de cosecha.
     */
    RegCosecha *ventCosecha;

    /**
     * @brief ventPulverizacion - Puntero a la ventana de registros de pulverizaciones.
     */
    RegPulverizacion *ventPulverizacion;

    /**
      * @brief ventSiembra - Puntero a la ventana de registros de siembras.
     */
    RegSiembra *ventSiembra;

    /**
     * @brief configLayout - Funcion configuradora de la interfaz de usuario. Es llamada en el
     * constructor. Tiene el proposito de ordenar el codigo.
     */
    void configLayout();

    /**
     * @brief paintEvent - Realiza los dibujados de la interfaz de usuario
     */
    void paintEvent(QPaintEvent *e);    

private slots:

    /**
     * @brief slot_RegCosechas - Slot para la pulsacion del boton de cosechas. Crea y muestra
     * la ventana correspondiente.
     */
    void slot_RegCosechas();

    /**
     * @brief slot_RegSiembras - Slot para la pulsacion del boton de Siembras. Crea y muestra
     * la ventana correspondiente.
     */
    void slot_RegSiembras();

    /**
     * @brief slot_RegPulverizaciones Slot para la pulsacion del boton de Pulverizaciones.
     * Crea y muestra la ventana correspondiente.
     */
    void slot_RegPulverizaciones();

    /**
     * @brief slot_Ver - TODO
     */
    void slot_Ver();

    /**
     * @brief slot_acercaDe - Muestra info acerca del programa y del dev
     */
    void slot_acercaDe();
};
