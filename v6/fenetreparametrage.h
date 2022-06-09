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
    QString getNom();       // Retourne le nom indiqué dans SNom
    int getLimite();        // Retourne la limite indiquée  dans SLimite
    void setNom(QString nom);   //Attribue une valeur au nom
    void setLimite(int limite);  // Attribue une valeur a la limite
    void afficherParametres(QString nom , int limite);    // Initialise les labels de Nom et Limite sur la fenêtre de paramètres

private:
    Ui::FenetreParametrage *ui;
};

#endif // FENETREPARAMETRAGE_H
