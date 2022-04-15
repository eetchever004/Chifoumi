/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe m�tier (= mod�le) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MOD�LE ---------------------------

Chifoumi::Chifoumi()
{
    coupJoueur = rien;
    coupMachine = rien;
    scoreJoueur = 0;
    scoreMachine = 0;
    //ctor
    // partie mod�le
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

    // il sera modifi� dans l'un des cas suivants
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

         ///* M�thodes utilitaires du Mod�le

int randMinMax(int min, int max){
    /* pr�-condition : min<max ;
       Le nbre al�atoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur � retourner

	valeurGeneree = rien;
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

void Chifoumi::initScores() {
    scoreJoueur = 0;
    scoreMachine = 0;
}

void Chifoumi::initCoups() {
    coupJoueur = rien;
    coupMachine = rien;
}
