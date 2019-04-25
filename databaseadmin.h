#pragma once
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>
#include <QDebug>

class DatabaseAdmin
{
public:
    DatabaseAdmin();

    bool connect(QString typte, QString databaseName, QString connectionName);
    bool insert(QString table, QStringList rows, QStringList values);

private:
    QSqlDatabase manager;
};
