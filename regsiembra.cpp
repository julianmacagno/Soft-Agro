#include "regsiembra.h"
#include "ui_regsiembra.h"

RegSiembra::RegSiembra(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::RegSiembra)
{
    ui->setupUi(this);

    dbCampos = QSqlDatabase::addDatabase("QSQLITE");
    dbCampos.setDatabaseName("../Soft-Agro/resources/databases/campos.sqlite");
    cargarCampos();

    connect(ui->pbAgregar,SIGNAL(pressed()),this,SLOT(slot_pbAgregar()));
}

RegSiembra::~RegSiembra()
{
    delete ui;
}

void RegSiembra::cargarCampos()
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

void RegSiembra::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(0,0,this->width(),this->height(),QColor(102,178,255));
}

void RegSiembra::slot_pbAgregar()
{

}
