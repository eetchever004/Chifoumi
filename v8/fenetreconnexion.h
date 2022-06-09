#ifndef FENETRECONNEXION_H
#define FENETRECONNEXION_H

#include <QDialog>
#include "database.h"


namespace Ui {
class fenetreConnexion;
}

class fenetreConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit fenetreConnexion(QWidget *parent = nullptr);
    ~fenetreConnexion();

public:
    QString getIdentifiant();    // Retourne l'Identifiant saisi dans SIdentifiant
    QString getMdp();            // Retourne le mot de passe saisi dans SMdp

public slots:
    bool getConnexion();
    void creerCompte();
private:
    Ui::fenetreConnexion *ui;
    Database *db;
};

#endif // FENETRECONNEXION_H
