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

    // partie modèle
    coupJoueur = rien;
    coupMachine = rien;
    scoreJoueur = 0;
    scoreMachine = 0;
    etatPartie = initial;
    //ctor
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

void ChifoumiVue::choixPierre(){
    switch(etatPartie)
    {
        case initial:
            break;
        case enCours:
            setCoupJoueur(pierre);
            ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));
            setCoupMachine(genererUnCoup());
            switch (getCoupMachine())
            {
                case pierre:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));
                    break;
                case papier:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));
                    break;
                case ciseau:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png"));
                    break;
                case rien:
                    break;
            }
            majScores(determinerGagnant());
            QString strJoueur;
            QString strMachine;
            strJoueur.setNum(getScoreJoueur());
            strMachine.setNum(getScoreMachine());
            ui->lScoreJoueur->setText(strJoueur);
            ui->lScoreMachine->setText(strMachine);
            break;
    }
}

void ChifoumiVue::choixPapier(){
    switch(etatPartie)
    {
        case initial:
            break;
        case enCours:
            setCoupJoueur(papier);
            ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));
            setCoupMachine(genererUnCoup());
            switch (getCoupMachine())
            {
                case pierre:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));
                    break;
                case papier:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));
                    break;
                case ciseau:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png"));
                    break;
                case rien:
                    break;
            }
            majScores(determinerGagnant());
            QString strJoueur;
            QString strMachine;
            strJoueur.setNum(getScoreJoueur());
            strMachine.setNum(getScoreMachine());
            ui->lScoreJoueur->setText(strJoueur);
            ui->lScoreMachine->setText(strMachine);
            break;
    }
}

void ChifoumiVue::choixCiseaux(){
    switch(etatPartie)
    {
        case initial:
            break;
        case enCours:
            setCoupJoueur(ciseau);
            ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png"));
            setCoupMachine(genererUnCoup());
            switch (getCoupMachine())
            {
                case pierre:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));
                    break;
                case papier:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));
                    break;
                case ciseau:
                    ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png"));
                    break;
                case rien:
                    break;
            }
            majScores(determinerGagnant());
            QString strJoueur;
            QString strMachine;
            strJoueur.setNum(getScoreJoueur());
            strMachine.setNum(getScoreMachine());
            ui->lScoreJoueur->setText(strJoueur);
            ui->lScoreMachine->setText(strMachine);
            break;
    }
}

void ChifoumiVue::nouvellePartie()
{
    switch(etatPartie)
    {
        case initial:
        ui->bCiseaux->setEnabled(true);
        ui->bPierre->setEnabled(true);
        ui->bPapier->setEnabled(true);
        etatPartie=enCours;
            break;
        case enCours:
        ui->lScoreJoueur->setText("0");
        ui->lScoreMachine->setText("0");
        setScoreJoueur(0);
        setScoreMachine(0);
        ui->lChoixMachine->setPixmap(QPixmap(":/chifoumi/images/rien_115.png"));
        ui->lChoixJoueur->setPixmap(QPixmap(":/chifoumi/images/rien_115.png"));
            break;
    }
}



///* ---- PARTIE MOD�LE ---------------------------

    /// Getters

ChifoumiVue::UnCoup ChifoumiVue::getCoupJoueur() {
return coupJoueur;
}

ChifoumiVue::UnCoup ChifoumiVue::getCoupMachine() {
return coupMachine;
}

unsigned int ChifoumiVue::getScoreJoueur() {
return scoreJoueur;
}

unsigned int ChifoumiVue::getScoreMachine() {
return scoreMachine;
}

char ChifoumiVue::determinerGagnant()
{
char gagnantARetourner;

// avant de commencer : match nul
gagnantARetourner = 'N';

// il sera modifié dans l'un des cas suivants
if (coupJoueur == papier && coupMachine == pierre)
{
    scoreJoueur += 1;
}
switch (coupJoueur)
{
case pierre : // On détermine le gagnant si le joueur joue la pierre
    if (coupMachine == ciseau)
        gagnantARetourner = 'J';
    if (coupMachine == papier)
        gagnantARetourner = 'M';
    if (coupMachine == pierre)
        gagnantARetourner = 'N';
    break;
case papier : // On détermine le gagnant si le joueur joue le papier
    if (coupMachine == pierre)
        gagnantARetourner = 'J';
    if (coupMachine == ciseau)
        gagnantARetourner = 'M';
    if (coupMachine == papier)
        gagnantARetourner = 'N';
    break;
case ciseau : // On détermine le gagnant si le joueur joue le ciseau
    if (coupMachine == papier)
        gagnantARetourner = 'J';
    if (coupMachine == pierre)
        gagnantARetourner = 'M';
    if (coupMachine == ciseau)
        gagnantARetourner = 'N';
    break;
default:
    break;
}
return gagnantARetourner;
}

     ///* M�thodes utilitaires du Modèle

int randMinMax(int min, int max){
/* pré-condition : min<max ;
   Le nbre aléatoire est compris entre [min, max[ */
return rand()%(max-min) + min;
}

ChifoumiVue::UnCoup ChifoumiVue::genererUnCoup()
{
    ChifoumiVue::UnCoup valeurGeneree;   // valeur � retourner
        unsigned int nbAleatoire;
        nbAleatoire = rand()%(4-1) + 1;
        switch (nbAleatoire)
        {
        case 1 :
            valeurGeneree = ChifoumiVue::pierre;
            break;
        case 2 :
            valeurGeneree = ChifoumiVue::papier;
            break;
        case 3 :
            valeurGeneree = ChifoumiVue::ciseau;
            break;
        default:
            break;
        }
        return valeurGeneree;
}

    /// Setters

void ChifoumiVue::setCoupJoueur(UnCoup p_coup) {
coupJoueur = p_coup;
}

void ChifoumiVue::setCoupMachine(UnCoup p_coup) {
coupMachine = p_coup;
}

void ChifoumiVue::setScoreJoueur(unsigned int p_score) {
scoreJoueur = p_score;
}

void ChifoumiVue::setScoreMachine(unsigned int p_score) {
scoreMachine = p_score;
}

void ChifoumiVue::majScores(char p_gagnant) {
switch (p_gagnant)
{
case 'J':
    scoreJoueur += 1; // Si le joueur est gagnant, son score augmente
    break;
case 'M':
    scoreMachine +=1; // Si la machine est gagnante, son score augmente
case 'N':
    break; // Si il y a égalité, aucun score n'est mis à jour
}
}

void ChifoumiVue::initScores() {
scoreJoueur = 0;
scoreMachine = 0;
}

void ChifoumiVue::initCoups() {
coupJoueur = rien;
coupMachine = rien;
}
