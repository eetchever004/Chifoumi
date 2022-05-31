#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include "fenetreparametrage.h"
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
        QMessageBox *fenetreFin = new QMessageBox;
        fenetreFin->setWindowTitle("Fin de partie");
        QString strLimite;
        strLimite.setNum(limite);
        if (getModele()->getScoreJoueur()==getModele()->getLimite())
        {
            fenetreFin->setText(" Bravo " + getModele()->getNom() + " ! Vous gagnez avec " + strLimite + " points.");
            fenetreFin->show();
            setEtat(initial);
            getVue()->griserElements();
        }

        else if (getModele()->getScoreMachine()==getModele()->getLimite())
        {
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
                                         getModele()->getCoupMachine());
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
                                         getModele()->getCoupMachine());
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
                                         getModele()->getCoupMachine());
            getVue()->majElementsInteractifs(this->getEtat());
            finDePartie(getModele()->getLimite());
        break;
        default:break;
    }
}

void ChifoumiPresentation::parametrer()
{
    switch(this->getEtat())
    {
    case initial:
    {


        FenetreParametrage *Parametrage = new FenetreParametrage;
        Parametrage->setWindowTitle("Paramètres");
        Parametrage->afficherParametres(getModele()->getNom(), getModele()->getLimite());
        bool confirmation = Parametrage->exec();

        if(confirmation == QDialog::Accepted && (Parametrage->getNom()!="") && (Parametrage->getLimite()!=0)){

            QString strLimite;
            strLimite.setNum(getModele()->getLimite());

            getModele()->setNom(Parametrage->getNom());
            getModele()->setLimite(Parametrage->getLimite());

            getVue()->afficherParametres(getModele()->getLimite(),
                                         getModele()->getNom());

            Parametrage->setNom(getModele()->getNom());
            Parametrage->setLimite(getModele()->getLimite());

        }

        break;
    }
     case enCours:
    {
        break;
    }
    }
}

