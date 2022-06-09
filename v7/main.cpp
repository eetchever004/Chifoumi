#include "chifoumivue.h"
#include "chifoumi.h"
#include "chifoumipresentation.h"
#include "fenetreconnexion.h"

#include <QApplication>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // création des 3 objets
    ChifoumiVue v;
    Chifoumi * m = new Chifoumi();
    ChifoumiPresentation *p = new ChifoumiPresentation();



    // mise en relation de Présentation, Modeèle et Vue
    v.setPresentation(p);
    p->setModele(m);
    p->setVue(&v);
    p->connexion();
    
    return a.exec();
}
