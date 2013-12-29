#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controleur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bpvcard_clicked();

    void on_bpfolder_clicked();

    void on_bpexit_clicked();

    void on_bpcreation_clicked();

private:
    Ui::MainWindow *ui;
    controleur *leCtrl;

};

#endif // MAINWINDOW_H
