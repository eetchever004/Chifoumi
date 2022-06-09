#include "fenetreparametrage.h"
#include "ui_fenetreparametrage.h"
#include <QDebug>

FenetreParametrage::FenetreParametrage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreParametrage)
{
    ui->setupUi(this);

    // Connexion boutons
    connect(ui->BAnnuler, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->BConfirmer, SIGNAL(clicked()), this, SLOT(accept()));

    // Connexion labels de saisie
    connect(ui->SNom, SIGNAL(textChanged()), this, SLOT(getNom()));
    connect(ui->SLimite, SIGNAL(textChanged()), this, SLOT(getLimite()));
}

FenetreParametrage::~FenetreParametrage()
{
    delete ui;
}

QString FenetreParametrage::getNom()
{
     return ui->SNom->text();
}

int FenetreParametrage::getLimite()
{
    return ui->SLimite-> text().toInt();
}


void FenetreParametrage::afficherParametres(QString nom , int limite)
{
    QString strLimite;
    strLimite.setNum(limite);

    // Initialisation des labels
    ui->LLimite->setText(strLimite);
    ui->LNom->setText(nom);
}
