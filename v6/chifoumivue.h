#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include "chifoumipresentation.h"
#include "chifoumi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiPresentation;
class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();

    void setPresentation (ChifoumiPresentation * p);
    ChifoumiPresentation* getPresentation();

    // Ordres que la Présentation donne à la vue
    void afficherValeursJeu(unsigned int sJ,
                           unsigned int sM,
                           Chifoumi::UnCoup cJ,
                           Chifoumi::UnCoup cM);

    void afficherParametres(unsigned int limite, QString nom);

    void majElementsInteractifs(ChifoumiPresentation::UnEtat e);

    void griserElements();


    // slots qui réagissent aux événements de l'utilisateur
    // et qui relaient cete info à la Présentation
private slots:
    void nouvellePartie();
    void choixPierre();
    void choixCiseaux();
    void choixPapier();
    void parametrer();
    // Ouvre le MsgBox du menu à propos
    void ouvrirAPropos();


private:
    Ui::ChifoumiVue *ui;
    ChifoumiPresentation* chifoumiPresentation;

private:
    // retourene le chemin de l'image représentant la figure c
    QString nomImageDuCpoup (Chifoumi::UnCoup c);


};
#endif // CHIFOUMIVUE_H
