#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class RegSiembra;
}

class RegSiembra : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegSiembra(QWidget *parent = 0);
    ~RegSiembra();

private:
    void paintEvent(QPaintEvent *e);
    Ui::RegSiembra *ui;

private slots:
    void slot_pbAgregar();
};
