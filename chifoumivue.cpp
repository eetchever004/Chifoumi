#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include <QDebug>

enum{pierre,feuille,ciseaux};

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
    connect(ui->bPierre,SIGNAL (clicked()), this, SLOT(choixPierre()));
    connect(ui->bPapier,SIGNAL (clicked()), this, SLOT(choixPapier()));
    connect(ui->bCiseaux,SIGNAL (clicked()), this, SLOT(choixCiseaux()));
    connect(ui->bNouv,SIGNAL (clicked()),this,SLOT(nouvellePartie()));
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

void ChifoumiVue::choixPierre(){
    qDebug()<<"Pierre" << Qt::endl;
}

void ChifoumiVue::choixPapier(){
    qDebug()<<"Papier"<< Qt::endl;
}

void ChifoumiVue::choixCiseaux(){
    qDebug()<<"Ciseaux"<< Qt::endl;
}

void ChifoumiVue::nouvellePartie()
{
    qDebug() << "nouvellePartie()" << Qt::endl;
}


