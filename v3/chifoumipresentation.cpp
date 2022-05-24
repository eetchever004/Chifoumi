#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include <QDebug>

ChifoumiPresentation::ChifoumiPresentation(QObject *parent)
    : QObject{parent}
{
    etatPartie = initial;
    //ctor

}

Chifoumi *ChifoumiPresentation::getModele()
{
    return chifoumiModele;
}

ChifoumiVue *ChifoumiPresentation::getVue()
{
    return chifoumiVue;
}

void ChifoumiPresentation::setModele(Chifoumi *m)
{
    chifoumiModele = m;
}

void ChifoumiPresentation::setVue(ChifoumiVue *v)
{
    chifoumiVue = v;
}

ChifoumiPresentation::UnEtat ChifoumiPresentation::getEtat()
{
    return etatPartie;
}

void ChifoumiPresentation::setEtat(UnEtat e)
{
    etatPartie = e;
}

void ChifoumiPresentation::nouvellePartie()
{
    switch(etatPartie)
    {
        case initial:
            getVue()->majElementsInteractifs(etatPartie);
            setEtat(enCours);
            break;
        case enCours:
            getModele()->initCoups();
            getModele()->initScores();
            getVue()->afficherValeursJeu(getModele()->getScoreJoueur(),
                                         getModele()->getScoreMachine(),
                                         getModele()->getCoupJoueur(),
                                         getModele()->getCoupMachine());
            break;
    }
}

void ChifoumiPresentation::choixPierre()
{
    switch(etatPartie)
    {
        case initial:
            break;
        case enCours:
            // pas de changement d'état
        // activité 1
            // maj modele
            getModele()->setCoupJoueur(Chifoumi::pierre);
            getModele()->setCoupMachine(getModele()->genererUnCoup());
            getModele()->majScores(getModele()->determinerGagnant());

            // ordonne à la vue de se mettre à jour en fonction du modele
            // et de l'état du jeu
            getVue()->afficherValeursJeu(getModele()->getScoreJoueur(),
                                         getModele()->getScoreMachine(),
                                         getModele()->getCoupJoueur(),
                                         getModele()->getCoupMachine());
            getVue()->majElementsInteractifs(this->getEtat());
        break;
        default:break;
    }
}

void ChifoumiPresentation::choixPapier()
{
    switch(etatPartie)
    {
        case initial:
            break;
        case enCours:
            // pas de changement d'état
        // activité 1
            // maj modele
            getModele()->setCoupJoueur(Chifoumi::papier);
            getModele()->setCoupMachine(getModele()->genererUnCoup());
            getModele()->majScores(getModele()->determinerGagnant());

            // ordonne à la vue de se mettre à jour en fonction du modele
            // et de l'état du jeu
            getVue()->afficherValeursJeu(getModele()->getScoreJoueur(),
                                         getModele()->getScoreMachine(),
                                         getModele()->getCoupJoueur(),
                                         getModele()->getCoupMachine());
            getVue()->majElementsInteractifs(this->getEtat());
        break;
        default:break;
    }
}

void ChifoumiPresentation::choixCiseaux()
{
    switch(etatPartie)
    {
        case initial:
            break;
        case enCours:
            // pas de changement d'état
        // activité 1
            // maj modele
            getModele()->setCoupJoueur(Chifoumi::ciseau);
            getModele()->setCoupMachine(getModele()->genererUnCoup());
            getModele()->majScores(getModele()->determinerGagnant());

            // ordonne à la vue de se mettre à jour en fonction du modele
            // et de l'état du jeu
            getVue()->afficherValeursJeu(getModele()->getScoreJoueur(),
                                         getModele()->getScoreMachine(),
                                         getModele()->getCoupJoueur(),
                                         getModele()->getCoupMachine());
            getVue()->majElementsInteractifs(this->getEtat());
        break;
        default:break;
    }
}


