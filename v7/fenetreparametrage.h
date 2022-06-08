#ifndef FENETREPARAMETRAGE_H
#define FENETREPARAMETRAGE_H

#include <QDialog>

namespace Ui {
class FenetreParametrage;
}

class FenetreParametrage : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreParametrage(QWidget *parent = nullptr);
    ~FenetreParametrage();

public:
    QString getNom();
    int getLimite();
    void afficherParametres(QString nom , int limite);

private:
    Ui::FenetreParametrage *ui;
};

#endif // FENETREPARAMETRAGE_H
