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
    void finDePartie(unsigned int limite);

public slots:
    void nouvellePartie();    // Permet d'initialiser le jeu pour lancer une nouvelle Partie
    void choixPierre();
    void choixCiseaux();
    void choixPapier();
    void parametrer();    // Permet d'afficher une fenêtre dans laquelle l'utilisateur peut modifier les paramètres de la partie
 

private:
    Chifoumi* chifoumiModele;
    ChifoumiVue* chifoumiVue;
    UnEtat etatPartie;  // état actuel de la partie


};

#endif // CHIFOUMIPRESENTATION_H
