#ifndef FENETRERESULTATS_H
#define FENETRERESULTATS_H

#include <QDialog>

namespace Ui {
class fenetreResultats;
}

class fenetreResultats : public QDialog
{
    Q_OBJECT

public:
    explicit fenetreResultats(QWidget *parent = nullptr);
    ~fenetreResultats();

public:
    void afficherResultats(QString Utilisateur);

private:
    Ui::fenetreResultats *ui;
};

#endif // FENETRERESULTATS_H
