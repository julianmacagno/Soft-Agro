/*TODO: quede en terminar de realizar el databaseadmin, una clase para administrar todas
 * las conexiones a una base de datos independientemente del tipo de base de datos que se
 * este utilizando. Estuve realizando algunos cambios en la clase regcosecha. Intente
 * realizar algunas conexiones y querys a la base, sin el databaseadmin; sino directamente
 * y tuve exito. Quede en terminar de "migrar" las pocas consultas que tengo hechas
 * directamente a consultas enviadas a la databaseadmin (que no me anduvieron). Por hacer,
 * definir un databaseadmin en la clase regcosecha, y en el cpp, cambiar las instrucciones
 * directas, por instrucciones para usar la nueva clase administradora. Revisar .cpp
 * Aca en el main, estuve probando los comandos para testear que los querys estuvieran bien
 * formados, anduvieron. queda probar que anden en la clase nueva. Al parecer, no funciona la
 * conexion a la base desde la clase nueva. Habria que probar borrando definitivamente la
 * conexion vieja desde la clase regcosecha*/
#include "mainwindow.h"
#include <QApplication>
/*#include "databaseadmin.h"
#include "QStringList"*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*DatabaseAdmin admin;
    admin.connect("QSQLITE", "Campos", "Conecion1");
    QStringList lista, lista2;
    lista.append("nombre");
    lista.append("superficie");
    lista2.append("Angelina lote 23");
    lista2.append("una banda");

    admin.insert("campos",lista, lista2);*/



    MainWindow w;
    w.showMaximized();




    return a.exec();
}
