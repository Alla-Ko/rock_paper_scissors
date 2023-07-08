
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->choice_hum_rock->setVisible(false);
    ui->choice_hum_paper->setVisible(false);
    ui->choice_hum_scissors->setVisible(false);
    ui->choice_mash_rock->setVisible(false);
    ui->choice_mash_paper->setVisible(false);
    ui->choice_mash_scissors->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::make_choice()
{
    int r=rand()%3;
    if(r==0)
    {
        ui->choice_mash_rock->setVisible(true);
        ui->choice_mash_paper->setVisible(false);
        ui->choice_mash_scissors->setVisible(false);
    }
    if(r==1)
    {
        ui->choice_mash_rock->setVisible(false);
        ui->choice_mash_paper->setVisible(true);
        ui->choice_mash_scissors->setVisible(false);
    }
    if(r==2)
    {
        ui->choice_mash_rock->setVisible(false);
        ui->choice_mash_paper->setVisible(false);
        ui->choice_mash_scissors->setVisible(true);
    }

    chois_mash=r;
    ui->result->setText(check_winner());
}
QString MainWindow::check_winner()
{
    if(chois_mash==chois_hum)return "Нічия";
    if(chois_hum==chois_mash+1||(chois_hum==0&&chois_mash==2))return "Ти виграв/виграла";
    return "Машина виграла";

}

void MainWindow::on_Rock_clicked()
{
    chois_hum=0;
    make_choice();
    ui->choice_hum_rock->setVisible(true);
    ui->choice_hum_paper->setVisible(false);
    ui->choice_hum_scissors->setVisible(false);
}


void MainWindow::on_Paper_clicked()
{
    chois_hum=1;
    make_choice();
    ui->choice_hum_paper->setVisible(true);
    ui->choice_hum_rock->setVisible(false);
    ui->choice_hum_scissors->setVisible(false);
}


void MainWindow::on_Scissors_clicked()
{
    chois_hum=2;
    make_choice();
    ui->choice_hum_scissors->setVisible(true);
    ui->choice_hum_paper->setVisible(false);
    ui->choice_hum_rock->setVisible(false);

}

