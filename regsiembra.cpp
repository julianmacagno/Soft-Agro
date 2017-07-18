#include "regsiembra.h"
#include "ui_regsiembra.h"

RegSiembra::RegSiembra(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::RegSiembra)
{
    ui->setupUi(this);
    connect(ui->pbAgregar,SIGNAL(pressed()),this,SLOT(slot_pbAgregar()));
}

RegSiembra::~RegSiembra()
{
    delete ui;
}

void RegSiembra::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(0,0,this->width(),this->height(),QColor(102,178,255));
}

void RegSiembra::slot_pbAgregar()
{

}
