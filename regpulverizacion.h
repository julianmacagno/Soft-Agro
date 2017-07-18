#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>

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
    void paintEvent(QPaintEvent *e);
    Ui::RegPulverizacion *ui;

private slots:
    void slot_pbAgregar();
};
