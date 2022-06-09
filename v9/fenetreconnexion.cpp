#include "fenetreconnexion.h"
#include "ui_fenetreconnexion.h"

#include <QDebug>
#include<QMessageBox>
#include <QPalette>

fenetreConnexion::fenetreConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreConnexion)
{
    ui->setupUi(this);

    connect(ui->BSeConnecter, SIGNAL(clicked()), this, SLOT(getConnexion()));

    connect(ui->SIdentifiant, SIGNAL(textChanged()), this, SLOT(getIdentifiant()));
    connect(ui->SMdp, SIGNAL(textChanged()), this, SLOT(getMdp()));

    connect(ui->bCreerCompte, SIGNAL(clicked()), this, SLOT(creerCompte()));

    connect(ui->bQuitterJeu,SIGNAL(clicked()),qApp,SLOT(quit()));


    ui->lErreur->hide();   //Dissimule le label d'erreur de saisie

    // Faire le lien entre la base de données et la fenêtre
    db = new Database();
    db->openDataBase();

}

fenetreConnexion::~fenetreConnexion()
{
    delete ui;
}

QString fenetreConnexion::getIdentifiant() // Retourne le contenu du lineEdit SIdentifiant
{
    return ui->SIdentifiant->text();
}

QString fenetreConnexion::getMdp() // Retourne le contenu du lineEdit SMdp
{
    return ui->SMdp->text();
}

void fenetreConnexion::creerCompte()
{
    db->insertUtilisateur(getIdentifiant(), getMdp());
}




bool fenetreConnexion::getConnexion()
{
    if (db->verifUtilisateur(getIdentifiant(),getMdp()))
    {
       // Si Utilisateur et mdp saisis, présents dans base de données -> ferme la fenêtre -> retourne true
        this->close();
        return true;
    }
    // Si connexion impossible -> affichage du message d'erreur de saisie d'informations
    ui->lErreur->show();
    return false;

}
