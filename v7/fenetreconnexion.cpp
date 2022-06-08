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


    ui->lErreur->hide();
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


bool fenetreConnexion::quitterJeu()
{
    qApp->quit();
    return true;
}

bool fenetreConnexion::getConnexion()
{
    if (db->verifUtilisateur(getIdentifiant(),getMdp()))
    {
        this->close();
        return true;
    }
    ui->lErreur->show();
    return false;

}
