#include "fenetreparametrage.h"
#include "ui_fenetreparametrage.h"
#include <QDebug>

FenetreParametrage::FenetreParametrage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreParametrage)
{
    ui->setupUi(this);
    connect(ui->BAnnuler, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->BConfirmer, SIGNAL(clicked()), this, SLOT(accept()));

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

void FenetreParametrage::setNom(QString nom)
{
    ui->LNom->setText(nom);
}

void FenetreParametrage::setLimite(int limite)
{
    QString strLimite;
    strLimite.setNum(limite);
    ui->LLimite->setText(strLimite);
}

void FenetreParametrage::afficherParametres(QString nom , int limite)
{
    QString strLimite;
    strLimite.setNum(limite);
    ui->LLimite->setText(strLimite);
    ui->LNom->setText(nom);
}
