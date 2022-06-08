#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include "fenetreparametrage.h"
#include <QDebug>
#include <QMessageBox>


ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
    connect(ui->bPierre,SIGNAL (clicked()), this, SLOT(choixPierre()));
    connect(ui->bPapier,SIGNAL (clicked()), this, SLOT(choixPapier()));
    connect(ui->bCiseaux,SIGNAL (clicked()), this, SLOT(choixCiseaux()));
    connect(ui->bNouv,SIGNAL (clicked()),this,SLOT(nouvellePartie()));

    connect(ui->actionQuitter,SIGNAL (triggered()),this,SLOT(close()));
    connect(ui->actionA_propos_de,SIGNAL (triggered()),this,SLOT(ouvrirAPropos()));

    connect(ui->actionParametrer,SIGNAL (triggered()),this,SLOT(parametrer()));

}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

void ChifoumiVue::setPresentation(ChifoumiPresentation *p)
{
    chifoumiPresentation = p;
}

ChifoumiPresentation *ChifoumiVue::getPresentation()
{
    return chifoumiPresentation;
}

void ChifoumiVue::afficherValeursJeu(unsigned int sJ, unsigned int sM, Chifoumi::UnCoup cJ, Chifoumi::UnCoup cM)
{
    switch(chifoumiPresentation->getEtat())
    {
    case ChifoumiPresentation::initial:
    {
        QString strSJ;
        strSJ.setNum(sJ);
        ui->lScoreJoueur->setText(strSJ);
        QString strSM;
        strSM.setNum(sM);
        ui->lScoreMachine->setText(strSM);
        ui->lChoixJoueur->setPixmap(QPixmap(nomImageDuCpoup(cJ)));
        ui->lChoixMachine->setPixmap(QPixmap(nomImageDuCpoup(cM)));
        break;
    }
    case ChifoumiPresentation::enCours:
    {
        QString strSJ;
        strSJ.setNum(sJ);
        ui->lScoreJoueur->setText(strSJ);
        QString strSM;
        strSM.setNum(sM);
        ui->lScoreMachine->setText(strSM);
        ui->lChoixJoueur->setPixmap(QPixmap(nomImageDuCpoup(cJ)));
        ui->lChoixMachine->setPixmap(QPixmap(nomImageDuCpoup(cM)));
        break;
    }
    }
}

void ChifoumiVue::afficherParametres(unsigned int limite, QString nom)
{
    switch(chifoumiPresentation->getEtat())
    {
    case ChifoumiPresentation::initial:
    {
        QString strLimite;
        strLimite.setNum(limite);
        ui->lLimiteScore->setText(strLimite);

        ui->lNomJoueur->setText(nom);
        break;
    }
    case ChifoumiPresentation::enCours:
    {

        break;
    }
    }
}


QString ChifoumiVue::nomImageDuCpoup(Chifoumi::UnCoup c)
{
    switch(c)
    {
    case Chifoumi::pierre:
        return ":/chifoumi/images/pierre_115.png";
        break;
    case Chifoumi::papier:
        return ":/chifoumi/images/papier_115.png";
        break;
    case Chifoumi::ciseau:
        return ":/chifoumi/images/ciseau_115.png";
        break;
    case Chifoumi::rien:
        return ":/chifoumi/images/rien_115.png";
        break;
    }
}

void ChifoumiVue::ouvrirAPropos()
{
    QMessageBox *APropos = new QMessageBox;
    APropos -> setText(" Version : 7.0 \n Date de création : 05/06/2022 \n Auteurs : Etcheverry Eliott - Gouaud Romain - Labastie Esteban ");
    APropos -> setWindowTitle("A propos de cette application");
    APropos -> show();
}


void ChifoumiVue::majElementsInteractifs(ChifoumiPresentation::UnEtat e)
{
    switch(e)
    {
    case ChifoumiPresentation::initial:
        ui->bNouv->setFocus();
        ui->bCiseaux->setEnabled(true);
        ui->bPierre->setEnabled(true);
        ui->bPapier->setEnabled(true);
    case ChifoumiPresentation::enCours:
        ui->bNouv->setFocus();
    }
}

void ChifoumiVue::griserElements()
{
    ui->bPierre->setEnabled(false);
    ui->bPapier->setEnabled(false);
    ui->bCiseaux->setEnabled(false);
}

void ChifoumiVue::choixPierre(){
    chifoumiPresentation->choixPierre();
}

void ChifoumiVue::choixPapier(){
    chifoumiPresentation->choixPapier();
}

void ChifoumiVue::parametrer()
{
    chifoumiPresentation->parametrer();
}

void ChifoumiVue::choixCiseaux(){
    chifoumiPresentation->choixCiseaux();
}

void ChifoumiVue::nouvellePartie(){
    chifoumiPresentation->nouvellePartie();
}

