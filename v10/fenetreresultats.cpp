#include <QSqlQuery>
#include "fenetreresultats.h"
#include "ui_fenetreresultats.h"


fenetreResultats::fenetreResultats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreResultats)
{
    ui->setupUi(this);
}

fenetreResultats::~fenetreResultats()
{
    delete ui;
}

void fenetreResultats::afficherResultats(QString Utilisateur)
{
    QStringList header; // nom des colonnes
    header << "Horodatage" << "Nom du Joueur" << "Score du joueur" << "Nom de l'opposant" << "Score de l'opposant" ;
    ui->tResultats->setColumnCount(header.size());
    // On applique les noms des colonnes
    ui->tResultats->setHorizontalHeaderLabels(header);
    // on cache les numéros de ligne
    ui->tResultats->verticalHeader()->setHidden(true);

    QHeaderView * headerView = ui->tResultats->horizontalHeader();
    // on redimensionne automatiquement la colonne pour occuper l'espacedisponible
    headerView->setSectionResizeMode(QHeaderView::Stretch);


     QSqlQuery recupMeilleurScores;
     recupMeilleurScores.exec("SELECT Horodatage , NomJoueur , ScoreJoueur , NomMachine , ScoreMachine , (ScoreJoueur - ScoreMachine ) as score FROM Resultats WHERE Utilisateur='"+ Utilisateur +"' ORDER BY score DESC LIMIT 10 ");

     for(int i = 0; recupMeilleurScores.next(); i++){
     QTableWidgetItem *Horodatage = new QTableWidgetItem(QString(recupMeilleurScores.value(0).toString()));
     QTableWidgetItem *NomJoueur = new QTableWidgetItem(QString(recupMeilleurScores.value(1).toString()));
     QTableWidgetItem *ScoreJoueur = new QTableWidgetItem(QString(recupMeilleurScores.value(2).toString()));
     QTableWidgetItem *NomMachine = new QTableWidgetItem(QString(recupMeilleurScores.value(3).toString()));
     QTableWidgetItem *ScoreMachine = new QTableWidgetItem(QString(recupMeilleurScores.value(4).toString()));
     ui->tResultats->insertRow(i);
     ui->tResultats->setItem(i,0 , Horodatage);
     ui->tResultats->setItem(i,1 , NomJoueur);
     ui->tResultats->setItem(i,2 , ScoreJoueur);
     ui->tResultats->setItem(i,3 , NomMachine);
     ui->tResultats->setItem(i,4 , ScoreMachine);
     }
}

