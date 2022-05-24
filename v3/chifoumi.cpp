/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe métier (= modèle) Chifoumi-v0
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MODèLE ---------------------------

Chifoumi::Chifoumi()
{
    //ctor
    // partie modèle
    initScores();
    initCoups();
    srand(time(NULL)); // initialisation du gérérateur de nombres aléatoires rand
}

Chifoumi::~Chifoumi()
{
    //dtor
}

        /// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return scoreMachine;
}

char Chifoumi::determinerGagnant()
{
    char gagnantARetourner;

    // avant de commencer : match nul
    gagnantARetourner = 'N';

    // il sera modifié dans l'un des cas suivants
    if ((coupJoueur == pierre) && (coupMachine == papier)) {
    gagnantARetourner='M'; }
    else if ((coupJoueur == pierre) && (coupMachine == ciseau)) {
             gagnantARetourner='J';}
    else if ((coupJoueur == papier) && (coupMachine == pierre)) {
             gagnantARetourner='J';}
    else if ((coupJoueur == papier) && (coupMachine == ciseau)) {
             gagnantARetourner='M';}
    else if ((coupJoueur == ciseau) && (coupMachine == pierre)) {
             gagnantARetourner='M';}
    else if ((coupJoueur == ciseau) && (coupMachine == papier)) {
             gagnantARetourner='J';}

    return gagnantARetourner;
}

         ///* Méthodes utilitaires du Modèle

int randMinMax(int min, int max){
    /* pré-condition : min<max ;
       Le nbre aléatoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur à retourner
    unsigned int nbAleatoire;
    nbAleatoire = randMinMax(1, 4);
    switch (nbAleatoire) {
        case 1 : valeurGeneree = Chifoumi::pierre;break;
        case 2 : valeurGeneree = Chifoumi::papier;break;
        case 3 : valeurGeneree = Chifoumi::ciseau;break;
        default: break;
    }
    return valeurGeneree;
}

        /// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    coupJoueur = p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    coupMachine = p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    scoreJoueur = p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    scoreMachine = p_score;
}

void Chifoumi::majScores(char p_gagnant) {
/* Mise à jour des scores en fonction des règles de gestion actuelles :
    - 1 point pour la gagnant lorsqu'il y a un gagnant
    - 0 point en cas de match nul
*/
  switch(p_gagnant)
  {
      case 'M' : scoreMachine++; break;
      case 'J' : scoreJoueur++; break;
      case 'N' :                        // aucun point pour personne
      default : break;
  }
}

void Chifoumi::initScores() {
    setScoreJoueur(0);
    setScoreMachine(0);
}

void Chifoumi::initCoups() {
    setCoupJoueur(rien);
    setCoupMachine(rien);
}
