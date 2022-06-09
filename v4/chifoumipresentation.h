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
    
    void finDePartie(unsigned int limite);  /* Si limite atteinte -> arrete la partie (UnEtat enCours -> initial)
                       et affiche le message de fin adapté */

public slots:
    void nouvellePartie();   // Permet d'initialiser les informations pour lancer une nouvelle  partie
    void choixPierre();
    void choixCiseaux();
    void choixPapier();
   

private:
    Chifoumi* chifoumiModele;
    ChifoumiVue* chifoumiVue;
    UnEtat etatPartie;  // état actuel de la partie


};

#endif // CHIFOUMIPRESENTATION_H
