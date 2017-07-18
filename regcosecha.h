#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class RegCosecha;
}

class RegCosecha : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegCosecha(QWidget *parent = 0);
    ~RegCosecha();

private:
    void paintEvent(QPaintEvent *e);
    Ui::RegCosecha *ui;
    QSqlDatabase dbCampos;

private slots:
    void slot_pbAgregar();

};
