#include "controleur.h"

controleur::controleur()
{
}



controleur::controleur(QString path)
    :filePath(path)
{
    this->unParseur = new parseurVcard(this->filePath);
}


void controleur::setPathFile(QString path)
{
    this->filePath = path;
    this->unParseur = new parseurVcard(this->filePath);

}

int controleur::countVcard()
{
    return this->unParseur->countContact();
}

void  controleur::setPathFolder(QDir* leD)
{
    this->unParseur->setLedossier(leD);
}

void controleur::creationCarte()
{
    this->unParseur->createVcards();

}
