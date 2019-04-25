#include "regcosecha.h"
#include "ui_regcosecha.h"

RegCosecha::RegCosecha(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::RegCosecha)
{
    ui->setupUi(this);

    //Para tener mas de dos conexiones de bases de datos en un mismo objeto, hay que cambiarle
    //el nombre a la conexion, pues no puede haber dos conexiones con el mismo nombre en la
    //lista de conexiones del motor de la base y la funcion addDatabase le agrega un nombre
    //por defecto el cual se repite.
    dbRegistros = QSqlDatabase::addDatabase("QSQLITE","Registros");
    dbCampos = QSqlDatabase::addDatabase("QSQLITE","Campos");

    dbRegistros.setDatabaseName("../Soft-Agro/resources/databases/registros.sqlite");
    dbCampos.setDatabaseName("../Soft-Agro/resources/databases/campos.sqlite");
    cargarCampos();

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

void RegCosecha::cargarCampos()
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

void RegCosecha::slot_pbAgregar()
{
    if(dbRegistros.open())
    {
        qDebug() << "Se abrio2";

        //Esto anda. Aunque no me gusta.
        QSqlQuery query = dbRegistros.exec("INSERT INTO Cosechas "
            "(Fecha, Rinde, Humedad, Daño, Comentarios, Campo)  VALUES ('" + ui->leFecha->text() +
            "', '" + ui->leRinde->text() + "', '" + ui->leHumedad->text() + "', '" +
            ui->leDanio->text() + "', '" + ui->leComentarios->text() + "', '" +
            ui->cbCampos->currentText() + "')");


        /*admin.connect("QSQLITE","../Soft-Agro/resources/databases/registros.sqlite","Registros2");
        QStringList lista,lista2;
        lista << "Fecha" << "Daño";
        lista2 << ui->leFecha->text() << ui->leDanio->text();

        admin.insert("Cosechas", lista, lista2);*/
    }

    else
    {
        qDebug() << "No se abrio2";
    }
}
