#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include "QString"
#include "parseurvcard.h"

class controleur
{
    QString filePath;
    parseurVcard* unParseur;

public:
    controleur();
    controleur(QString);
    void setPathFile(QString);
    void setPathFolder(QDir*);
    int countVcard();
    void creationCarte();
};


#endif // CONTROLEUR_H
