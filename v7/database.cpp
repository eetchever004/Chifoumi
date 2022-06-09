#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "database.h"


Database::Database()
{

}

bool Database::openDataBase() // Retourne Vrai si la connexion est réussie
{
    mybd = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mybd.setDatabaseName(DATABASE_NAME);
    bool ok = mybd.open();

    if(ok)
    {
        qDebug() << "La base de données est ouverte" << Qt::endl;
    }
    else
    {
        qDebug() << "La base de données ne peut pas s'ouvrir" << Qt::endl;
    }
    return ok;
}

void Database::closeDataBase() // Ferme la base de données
{
    mybd.close();
}

bool Database::verifUtilisateur(QString Identifiant, QString Mdp) // Retourne Vrai lorsque le mot de passe et le nom d'utilisateur entrés sont répertoriés dans la BD
{
    QSqlQuery query;
    query.exec("SELECT Utilisateur, Mdp FROM Authentification WHERE Utilisateur = '" + Identifiant + "' AND Mdp = '" + Mdp + "'");
    query.first();
    qDebug() << query.value(0) << Qt::endl;
    if(query.value(0).toString() == Identifiant && Identifiant != "" && query.value(1).toString() == Mdp)
    {
        return true;
    }
    return false;

}

bool Database::insertUtilisateur(QString Identifiant, QString Mdp)
{
    if (Identifiant!="" && Mdp!="")
    {
        QSqlQuery query;
        if (query.exec("INSERT INTO Authentification VALUES ('" + Identifiant + "' , '" + Mdp + "')"))
        {
            // Affichage d'une fenêtre de confirmation de création du compte
            QMessageBox *compteCree = new QMessageBox;
            compteCree -> setText(" Votre compte a été créé !");
            compteCree -> setWindowTitle("Creation d'un compte");
            compteCree -> show();
            return true;
        }
        return false;
    }
}
