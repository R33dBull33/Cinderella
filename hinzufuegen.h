#ifndef HINZUFUEGEN_H
#define HINZUFUEGEN_H

#include <QDialog>

namespace Ui {
class Hinzufuegen;
}

class Hinzufuegen : public QDialog
{
    Q_OBJECT

public:
    explicit Hinzufuegen(QWidget *parent = 0);
    ~Hinzufuegen();

private:
    Ui::Hinzufuegen *ui;

private slots:
    void add();
    void addZutat();
    void addStep();
};

#endif // HINZUFUEGEN_H
