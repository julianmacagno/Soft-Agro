#include "databaseadmin.h"

DatabaseAdmin::DatabaseAdmin()
{

}

bool DatabaseAdmin::connect(QString type, QString databaseName, QString connectionName)
{
    manager = QSqlDatabase::addDatabase(type,connectionName);

    manager.setDatabaseName(databaseName);

    return manager.isOpen();
}

bool DatabaseAdmin::insert(QString table, QStringList rows, QStringList values)
{
    if(rows.size() != values.size())
    {
        return false;
    }

    else
    {
        if(manager.isOpen())
        {
            QString query = "INSERT INTO " + table + " ('";

            for(int i=0; i<rows.size();i++)
            {
                query.append(rows.at(i) + "', '");
            }

            query.chop(3);
            query.append(") VALUES ('");

            for(int i=0; i<rows.size();i++)
            {
                query.append(values.at(i) + "', '");
            }

            query.chop(3);
            query.append(")");

            qDebug() << query;

            manager.exec(query);

            //habria que comprobar si el query realmente se hizo.
            return true;
        }

        else
        {
            return false;
        }
    }
}
