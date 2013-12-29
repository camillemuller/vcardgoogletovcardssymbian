#ifndef PARSEURVCARD_H
#define PARSEURVCARD_H
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QDir"

class parseurVcard
{
public:
    parseurVcard(QString);
    int countContact();
    void setLedossier(QDir*);
    void createVcards();
private :
    QString filePath;
    QFile* fileVcard;
    QDir* ledossier;
    QTextStream * in;
    QStringList lefichier;

};

#endif // PARSEURVCARD_H
