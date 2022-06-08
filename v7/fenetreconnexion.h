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
    QString getIdentifiant();
    QString getMdp();

public slots:
    bool getConnexion();
    void creerCompte();
    bool quitterJeu();
private:
    Ui::fenetreConnexion *ui;
    Database *db;
};

#endif // FENETRECONNEXION_H
