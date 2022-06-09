#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include "fenetreparametrage.h"
#include "fenetreconnexion.h"
#include "fenetreresultats.h"

#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDateTime>



ChifoumiPresentation::ChifoumiPresentation(QObject *parent)
    : QObject{parent}
{
    etatPartie = initial;


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

        QString strLimite;
        strLimite.setNum(limite);

        // Texte adapté pour scénario joueur gagnant
        if (getModele()->getScoreJoueur()==getModele()->getLimite())
        {
            fenetreFin->setText(" Bravo " + getModele()->getNom() + " ! Vous gagnez avec " + strLimite + " points.");

            fenetreFin->show();             // On affiche la fenêtre
            setEtat(initial);               // Retour à l'état initial car fin de partie
            getVue()->griserElements();     // On désactive les boutons
            sauvegarderResultat();          // On sauvegarde le score du joueur dans la base de données

        }

        // Texte adapté pour scénario Machine gagnante
        else if (getModele()->getScoreMachine()==getModele()->getLimite())
        {
            fenetreFin->setText(" Bravo Machine ! Vous gagnez avec " + strLimite + " points.");
            fenetreFin->show();
            setEtat(initial);
            getVue()->griserElements();
            sauvegarderResultat();
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
        // Création fenêtre de parametrage
        FenetreParametrage *Parametrage = new FenetreParametrage;
        Parametrage->setWindowTitle("Paramètres");
        Parametrage->afficherParametres(getModele()->getNom(), getModele()->getLimite());
        bool confirmation = Parametrage->exec();

        if(confirmation == QDialog::Accepted )
        {
            //  On recupere le Nom si le contenu de getNom (SNom)  non nul
            if (Parametrage->getNom()!="")
            {
                getModele()->setNom(Parametrage->getNom());
            }

            //  On recupere la Limite si le contenu de getLimite (SLimite)  non nul
            if (Parametrage->getLimite()!=0)
            {
                QString strLimite;
                strLimite.setNum(getModele()->getLimite());
                getModele()->setLimite(Parametrage->getLimite());
            }
            //On met a jour les labels sur l'interface de parametrage
            getVue()->afficherParametres(getModele()->getLimite(),
                                         getModele()->getNom());

        }

        break;
    }
    case enCours:
    {
        break;
    }
    }
}

void ChifoumiPresentation::connexion()
{

    switch(this->getEtat())
    {
    case initial:
    {
        // création fenêtre connexion
        fenetreConnexion *fConnexion = new fenetreConnexion();
        fConnexion->setWindowTitle("Se Connecter");
        fConnexion->exec();

        //Si la connexion est réussi (getConnexion -> true) -> on recupere l'identifiant -> on ouvre la fenêtre de jeu
        if(fConnexion->getConnexion())
        {
            getModele()->setIdentifiant(fConnexion->getIdentifiant());
            getVue()->show();
        }
        break;
    }
    case enCours:
    {
        break;
    }
    }
}


void ChifoumiPresentation::afficherResultats()
{
    fenetreResultats *fResultats = new fenetreResultats;
    fResultats->afficherResultats(getModele()->getIdentifiant());
    fResultats->show();
}

void ChifoumiPresentation::sauvegarderResultat()
{
    QSqlQuery recupResultat;
    recupResultat.prepare("INSERT INTO Resultats VALUES (?,?,?,?,?,?)");
    QString Horodatage = QDateTime::currentDateTime().toString("dd/MM hh:mm"); //Recuperer l'horodatage de la machine

    recupResultat.addBindValue(getModele()->getIdentifiant());
    recupResultat.addBindValue(Horodatage);
    recupResultat.addBindValue(getModele()->getNom());
    recupResultat.addBindValue(getModele()->getScoreJoueur());
    recupResultat.addBindValue("Machine");
    recupResultat.addBindValue(getModele()->getScoreMachine());
    recupResultat.exec();
}







