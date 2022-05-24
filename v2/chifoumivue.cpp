#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include <QDebug>


ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
    connect(ui->bPierre,SIGNAL (clicked()), this, SLOT(choixPierre()));
    connect(ui->bPapier,SIGNAL (clicked()), this, SLOT(choixPapier()));
    connect(ui->bCiseaux,SIGNAL (clicked()), this, SLOT(choixCiseaux()));
    connect(ui->bNouv,SIGNAL (clicked()),this,SLOT(nouvellePartie()));

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
            break;
        case ChifoumiPresentation::enCours:
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

void ChifoumiVue::choixPierre(){
    chifoumiPresentation->choixPierre();
}

void ChifoumiVue::choixPapier(){
    chifoumiPresentation->choixPapier();
}

void ChifoumiVue::choixCiseaux(){
    chifoumiPresentation->choixCiseaux();
}

void ChifoumiVue::nouvellePartie(){
    chifoumiPresentation->nouvellePartie();
}

