#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QIcon>
#include <QDialog>
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
    RegCosecha *ventCosecha;
    RegPulverizacion *ventPulverizacion;
    RegSiembra *ventSiembra;
    void configLayout();
    void paintEvent(QPaintEvent *e);    

private slots:
    void slot_RegCosechas();
    void slot_RegSiembras();
    void slot_RegPulverizaciones();
    void slot_Ver();
};
