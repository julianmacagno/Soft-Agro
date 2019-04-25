#include "regpulverizacion.h"
#include "ui_regpulverizacion.h"

RegPulverizacion::RegPulverizacion(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::RegPulverizacion)
{
    ui->setupUi(this);

    dbCampos = QSqlDatabase::addDatabase("QSQLITE");
    dbCampos.setDatabaseName("../Soft-Agro/resources/databases/campos.sqlite");
    cargarCampos();

    connect(ui->pbAgregar, SIGNAL(pressed()),this,SLOT(slot_pbAgregar()));
}

RegPulverizacion::~RegPulverizacion()
{
    delete ui;
}

void RegPulverizacion::cargarCampos()
{
    if(dbCampos.open())
    {
        qDebug() << "Se abrio";

        QSqlQuery query = dbCampos.exec("SELECT nombre FROM campos");

        while(query.next())
        {
            ui->cbCampos->addItem(query.value(0).toString());
        }
    }

    else
    {
        qDebug() << "No se abrio";
    }
}

void RegPulverizacion::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(0,0,this->width(),this->height(),QColor(102,178,255));
}

void RegPulverizacion::slot_pbAgregar()
{

}
