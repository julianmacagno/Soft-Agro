#include "regpulverizacion.h"
#include "ui_regpulverizacion.h"

RegPulverizacion::RegPulverizacion(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::RegPulverizacion)
{
    ui->setupUi(this);
    connect(ui->pbAgregar, SIGNAL(pressed()),this,SLOT(slot_pbAgregar()));
}

RegPulverizacion::~RegPulverizacion()
{
    delete ui;
}

void RegPulverizacion::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(0,0,this->width(),this->height(),QColor(102,178,255));
}

void RegPulverizacion::slot_pbAgregar()
{

}
