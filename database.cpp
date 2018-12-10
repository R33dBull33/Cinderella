#include "database.h"

#include <QDebug>

DataBase* DataBase::instance = 0;
const QString DRIVER("QSQLITE");

DataBase* DataBase::getInstance()
{
    if (!instance)
    {
        instance = new DataBase();
    }

    return instance;
}

void DataBase::deleteRecipe(QString id)
{
    QString query = "DELETE FROM recipes WHERE id = " + id + ";";
    thorwQuerry(query);
}

QList<QString> DataBase::getRecipes()
{
    QSqlQuery query("SELECT * FROM recipes");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    QList<QString> recipes;

    while(query.next())
    {
        recipes.append(QString(query.value(0).toString()).append(". ").append(query.value(1).toString()));
        qDebug() << query.value(1).toString();
    }
    return recipes;
}

bool DataBase::insertRecipe(QString title)
{
    QString id = 0;
    QSqlQuery countquery("SELECT COUNT(*) FROM RECIPES");
    if(!countquery.exec())
      qWarning() << "ERROR: " << countquery.lastError().text();
    if(countquery.first())
      id = QString::number(countquery.value(0).toInt() + 1);

    QString query = "insert into recipes (id, title) values (" + id + ",'" + title + "');";
    thorwQuerry(query);

    return true;
}

bool DataBase::createTables()
{
    QString querry = "CREATE TABLE IF NOT EXISTS recipes (id INTEGER PRIMARY KEY, title varchar(255));";
    thorwQuerry(querry);

    return true;
}

bool DataBase::thorwQuerry(QString querry)
{
    QSqlQuery qslQuerry(querry);

    if(!qslQuerry.isActive())
        qWarning() << "MainWindow::DatabaseInit - ERROR: " << qslQuerry.lastError().text();
    return true;
}

DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("Cinderella.db");
    if(!db.open())
        qWarning() << "ERROR: " << db.lastError();

    createTables();
}
