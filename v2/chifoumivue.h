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

    void majElementsInteractifs(ChifoumiPresentation::UnEtat e);


    // slots qui réagissent aux événements de l'utilisateur
    // et qui relaient cete info à la Présentation
private slots:
    void nouvellePartie();
    void choixPierre();
    void choixCiseaux();
    void choixPapier();

private:
    Ui::ChifoumiVue *ui;
    ChifoumiPresentation* chifoumiPresentation;

private:
    QString nomImageDuCpoup (Chifoumi::UnCoup c);
    // retourene le chemin de l'image représentant la figure c


};
#endif // CHIFOUMIVUE_H
