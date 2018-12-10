#include "hinzufuegen.h"
#include "ui_hinzufuegen.h"
#include "database.h"

#include <QDebug>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGroupBox>

Hinzufuegen::Hinzufuegen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hinzufuegen)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(add()));
    connect(ui->btn_addZutat, SIGNAL(clicked(bool)), this, SLOT(addZutat()));
    connect(ui->btn_addStep, SIGNAL(clicked(bool)), this, SLOT(add_Step()));
}

void Hinzufuegen::addStep()
{   QVBoxLayout* layout = ui->layout_Zubereitung;
    QFrame* frame = new QFrame();

    QHBoxLayout layoutH = new  QHBoxLayout();

    QGroupBox* box = new QGroupBox("Schritt " + QString::number(layout->count()));
    layout->addWidget(box);

}

void Hinzufuegen::addZutat()
{
    QFrame* frame = new QFrame();
    QHBoxLayout* layout = new QHBoxLayout(frame);

    QLineEdit* name = new QLineEdit(frame);
    QLineEdit* menge = new QLineEdit(frame);
    QComboBox* einheit = new QComboBox(frame);
    einheit->addItem("TL");
    einheit->addItem(("EL"));
    einheit->addItem("ml");
    einheit->addItem("l");
    einheit->addItem("g");
    einheit->addItem("kg");

    layout->addWidget(name);
    layout->addWidget(menge);
    layout->addWidget(einheit);

    frame->setLayout(layout);
    ui->layout_Zutaten->addWidget(frame);
}

void Hinzufuegen::add()
{
    DataBase* db = DataBase::getInstance();
    db->insertRecipe(ui->lineEdit_title->text());
}

Hinzufuegen::~Hinzufuegen()
{
    delete ui;
}
