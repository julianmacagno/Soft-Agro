#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ventCosecha = NULL;
    ventPulverizacion = NULL;
    ventSiembra = NULL;
    configLayout();

    connect(ui->pbRegCosechas,SIGNAL(pressed()),this,SLOT(slot_RegCosechas()));
    connect(ui->pbRegSiembras,SIGNAL(pressed()),this,SLOT(slot_RegSiembras()));
    connect(ui->pbRegPulverizaciones,SIGNAL(pressed()),this,SLOT(slot_RegPulverizaciones()));
    connect(ui->pbVer,SIGNAL(pressed()),this,SLOT(slot_Ver()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configLayout()
{
    int altura = this->height()/3;

    setWindowTitle("Soft-Agro");
    setWindowIcon(QIcon(":/resources/icons/agro.png"));

    ui->pbRegCosechas->setMinimumHeight(altura);
    ui->pbRegCosechas->setIcon(QIcon(":/resources/icons/register.png"));
    ui->pbRegCosechas->setIconSize(QSize(altura, altura));

    ui->pbRegPulverizaciones->setMinimumHeight(altura);
    ui->pbRegPulverizaciones->setIcon(QIcon(":/resources/icons/register.png"));
    ui->pbRegPulverizaciones->setIconSize(QSize(altura, altura));

    ui->pbRegSiembras->setMinimumHeight(altura);
    ui->pbRegSiembras->setIcon(QIcon(":/resources/icons/register.png"));
    ui->pbRegSiembras->setIconSize(QSize(altura, altura));

    ui->pbVer->setMinimumHeight(this->height()/3);
    ui->pbVer->setIcon(QIcon(":/resources/icons/view.png"));
    ui->pbVer->setIconSize(QSize(altura, altura));
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(0,0,this->width(),this->height(),QColor(102,178,255));
}

void MainWindow::slot_RegCosechas()
{
    if(!ventCosecha)
    {
        ventCosecha = new RegCosecha(this);
    }

    ventCosecha->showMaximized();
}

void MainWindow::slot_RegSiembras()
{
    if(!ventSiembra)
    {
        ventSiembra = new RegSiembra(this);
    }

    ventSiembra->showMaximized();
}

void MainWindow::slot_RegPulverizaciones()
{
    if(!ventPulverizacion)
    {
        ventPulverizacion = new RegPulverizacion(this);
    }

    ventPulverizacion->showMaximized();
}

void MainWindow::slot_Ver()
{

}
