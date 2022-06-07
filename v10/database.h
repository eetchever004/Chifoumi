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
    bool insertUtilisateur(QString Identifiant, QString Mdp);


private:
    QSqlDatabase mybd;
};

#endif // DATABASE_H
