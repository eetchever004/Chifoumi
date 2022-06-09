#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H


#include "chifoumi.h"

#include <QObject>
class ChifoumiVue;
class ChifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    explicit ChifoumiPresentation(QObject *parent = nullptr);
    enum UnEtat {initial, enCours};
    // getteres et setters des propriétés privées
    Chifoumi* getModele();
    ChifoumiVue* getVue();
    void setModele(Chifoumi* m);
    void setVue(ChifoumiVue* v);
    UnEtat getEtat();
    void setEtat(UnEtat e);
    
    void finDePartie(unsigned int limite);      /* Si limite atteinte -> arrete la partie (UnEtat enCours -> initial)
                       et affiche le message de fin adapté */

public slots:
    void nouvellePartie();                // Permet de lancer une nouvelle Partie
    void choixPierre();
    void choixCiseaux();
    void choixPapier();
    void parametrer();                    // Permet d'afficher une fenêtre dans laquelle l'utilisateur peut modifier les paramètres de la partie
    void connexion();                     // Permet a l'utilisateur de se connecter sur son compte via la fenetre de connexion
   


private:
    Chifoumi* chifoumiModele;
    ChifoumiVue* chifoumiVue;
    UnEtat etatPartie;  // état actuel de la partie


};

#endif // CHIFOUMIPRESENTATION_H
