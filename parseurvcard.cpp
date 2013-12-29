#include "parseurvcard.h"
#include "QDebug"

parseurVcard::parseurVcard(QString path)
    :filePath(path)
{
    this->fileVcard = new QFile(path);
    if (!this->fileVcard->open(QIODevice::ReadOnly | QIODevice::Text))
        exit(-1);


}

/**
 * @brief parseurVcard::countContact
 * @return
 */
int parseurVcard::countContact()
{
    QString lefichiee;
    int count = 0;
    in =  new QTextStream(this->fileVcard);


    while(!in->atEnd())
    {
        lefichiee = in->readLine();
        this->lefichier.append(lefichiee);
        if( lefichiee.contains("BEGIN"))
        {
           count++;
        }

    }
    return count;
}

void parseurVcard::setLedossier(QDir* leD)
{
    this->ledossier = leD;
}

void parseurVcard::createVcards()
{
    qDebug() <<"Crash";
    QString vcard,nomfichier;

    foreach (QString uneLigne, this->lefichier)
    {
        if(uneLigne.contains("BEGIN"))
        {

            vcard = uneLigne+"\n";


        }
        else if(uneLigne.contains("FN:") && !uneLigne.contains("VERSION"))
        {
            vcard +=uneLigne+'\n';
            nomfichier = uneLigne.remove(0,uneLigne.indexOf(':')+1).remove(uneLigne.indexOf(';',uneLigne.lastIndexOf(';'))).simplified();
            qDebug() << nomfichier;
        }
        else if(uneLigne.contains("END"))
          {
            // Ecris la vcard
            vcard += uneLigne+"\n";
            QFile* unecard = new QFile(this->ledossier->path()+'/'+nomfichier+".vcf");
            unecard->open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(unecard);

            out << vcard;
            unecard->close();
        }
        else
        {
            vcard  += uneLigne+"\n";
        }

    }




}
