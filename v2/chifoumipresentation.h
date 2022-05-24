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

public slots:
    void nouvellePartie();
    void choixPierre();
    void choixCiseaux();
    void choixPapier();
   // void choixFigure(Chifoumi::UnCoup c);

private:
    Chifoumi* chifoumiModele;
    ChifoumiVue* chifoumiVue;
    UnEtat etatPartie;  // état actuel de la partie

};

#endif // CHIFOUMIPRESENTATION_H
