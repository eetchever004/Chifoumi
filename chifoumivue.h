#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();
public slots:
    void nouvellePartie();
    void choixPierre();
    void choixCiseaux();
    void choixPapier();
private:
    Ui::ChifoumiVue *ui;
};
#endif // CHIFOUMIVUE_H
