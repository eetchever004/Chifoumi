#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

#define DATABASE_NAME "elabastie_bd"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();
    bool verifUtilisateur(QString Identifiant, QString Mdp);
    /* verification de l'existence de l'Identifiant et du Mdp correspondant dans la base de données
       renvoie true si connexion valide */
    bool insertUtilisateur(QString Identifiant, QString Mdp);
     /* insertion d'un utilisateur dans la base de données grâce aux informations saisies
      sur la fenêtre de connexion ; renvoie true si compte créé */


private:
    QSqlDatabase mybd;
};

#endif // DATABASE_H
