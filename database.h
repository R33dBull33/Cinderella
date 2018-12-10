#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>

class DataBase
{
public:
    ~DataBase();
    static DataBase* getInstance();
    bool insertRecipe(QString title);
    QList<QString> getRecipes();
    void deleteRecipe(QString id);

private:
    DataBase();
    static DataBase* instance;
    QSqlDatabase db;
    bool createTables();
    bool thorwQuerry(QString querry);

};

#endif // DATABASE_H
