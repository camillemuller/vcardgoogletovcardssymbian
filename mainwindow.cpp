#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    leCtrl = new controleur();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bpvcard_clicked()
{
    QString vcardFilePath = QFileDialog::getOpenFileNames(this, tr("Open File"),"",tr("Vcard Files (*.vcf)")).at(0);
    this->ui->linevcard->setText(vcardFilePath);
    leCtrl->setPathFile(vcardFilePath);
    this->ui->contactnombre->setText(QString::number(this->leCtrl->countVcard()));
}

void MainWindow::on_bpfolder_clicked()
{
    QDir* directory;
    directory = new QDir();
    QString path = QFileDialog::getExistingDirectory (this, tr("Directory"), "");
    directory->setPath(path);
    this->ui->linedossiervcard->setText(directory->path());
    this->leCtrl->setPathFolder(directory);
}

void MainWindow::on_bpexit_clicked()
{
    this->close();
}

void MainWindow::on_bpcreation_clicked()
{
    this->leCtrl->creationCarte();
}
