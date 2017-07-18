#include "regcosecha.h"
#include "ui_regcosecha.h"

RegCosecha::RegCosecha(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::RegCosecha)
{
    ui->setupUi(this);
    dbCampos = QSqlDatabase::addDatabase("QSQLITE");
    dbCampos.setDatabaseName(":/resources/databases/campos.sqlite");

    connect(ui->pbAgregar,SIGNAL(pressed()),this, SLOT(slot_pbAgregar()));
}

RegCosecha::~RegCosecha()
{
    delete ui;
}

void RegCosecha::paintEvent(QPaintEvent *e)
{    
    QPainter painter(this);
    painter.fillRect(0,0,this->width(),this->height(),QColor(102,178,255));
}

void RegCosecha::slot_pbAgregar()
{

    //Esto no anda
    dbCampos.open();

    if(dbCampos.isOpen())
    {
        qDebug() << "Se abrio";

        QSqlQuery query = dbCampos.exec("SELECT nombre FROM campos");

        while(query.next())
        {
            ui->lwCampos->addItem(query.value(0).toString());
        }
    }
}
