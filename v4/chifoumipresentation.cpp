#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include <QDebug>
#include <QMessageBox>

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

void ChifoumiPresentation::finDePartie(unsigned int limite)
{
    switch(etatPartie)
    {
    case initial:
    {
        break;
    }
    case enCours:
    {
         // Creation de la fenêtre de fin de partie de type MessageBox Information
        QMessageBox *fenetreFin = new QMessageBox;
        fenetreFin->setWindowTitle("Fin de partie");
        fenetreFin->setIcon(QMessageBox::Information);
        
        // Texte adapté pour scénario joueur gagnant
        if (getModele()->getScoreJoueur()==limite)
        {
            QString strLimite;
            strLimite.setNum(limite);
            fenetreFin->setText(" Bravo Joueur ! Vous gagnez avec " + strLimite + " points.");
            fenetreFin->show();       // On affiche la fenêtre
            setEtat(initial);         // Retour à l'état initial car fin de partie
            getVue()->griserElements();   // On désactive les boutons
        }
         // Texte adapté pour scénario Machine gagnante
        else if (getModele()->getScoreMachine()==limite)
        {
            QString strLimite;
            strLimite.setNum(limite);
            fenetreFin->setText(" Bravo Machine ! Vous gagnez avec " + strLimite + " points.");
            fenetreFin->show();
            setEtat(initial);
            getVue()->griserElements();
        }
        break;
    }
    }
}

void ChifoumiPresentation::nouvellePartie()
{
    switch(this->getEtat())
    {
        case initial:
            getModele()->initCoups();
            getModele()->initScores();
            getVue()->majElementsInteractifs(this->getEtat());
            getVue()->afficherValeursJeu(getModele()->getScoreJoueur(),
                                         getModele()->getScoreMachine(),
                                         getModele()->getCoupJoueur(),
                                         getModele()->getCoupMachine(),
                                         getModele()->getLimite());
            setEtat(enCours);
            break;
        case enCours:
            getModele()->initCoups();
            getModele()->initScores();
            getVue()->afficherValeursJeu(getModele()->getScoreJoueur(),
                                         getModele()->getScoreMachine(),
                                         getModele()->getCoupJoueur(),
                                         getModele()->getCoupMachine(),
                                         getModele()->getLimite());
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
                                         getModele()->getCoupMachine(),
                                         getModele()->getLimite());
            getVue()->majElementsInteractifs(this->getEtat());
            finDePartie(getModele()->getLimite());
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
                                         getModele()->getCoupMachine(),
                                         getModele()->getLimite());
            getVue()->majElementsInteractifs(this->getEtat());
            finDePartie(getModele()->getLimite());
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
                                         getModele()->getCoupMachine(),
                                         getModele()->getLimite());
            getVue()->majElementsInteractifs(this->getEtat());
            finDePartie(getModele()->getLimite());
        break;
        default:break;
    }
}


