#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hinzufuegen.h"
#include "database.h"
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_hinzufuegen, SIGNAL(clicked(bool)), this, SLOT(hinzufuegen()));
    connect(ui->btn_loeschen, SIGNAL(clicked(bool)), this, SLOT(loeschen()));

    updateList();

}

void MainWindow::loeschen()
{
    DataBase* db = DataBase::getInstance();
    QString currentItem = ui->recipesList->currentItem()->text();
    QString id = currentItem.split(".")[0];
    db->deleteRecipe(id);

    updateList();
}

void MainWindow::hinzufuegen()
{
    Hinzufuegen* hinzufuegen_dlg = new Hinzufuegen();
    hinzufuegen_dlg->exec();
    updateList();
}

void MainWindow::updateList()
{
    DataBase* db = DataBase::getInstance();
    QList<QString> recipes = db->getRecipes();

    ui->recipesList->clear();

    for(int i = 0; i < recipes.length(); i++)
    {
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(recipes[i]);
        ui->recipesList->addItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
