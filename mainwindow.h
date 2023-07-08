
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Rock_clicked();

    void on_Paper_clicked();

    void on_Scissors_clicked();

private:
    Ui::MainWindow *ui;
    //QList <QString> choises={"rock","paper","scissors"};
    int chois_hum,chois_mash;
    void make_choice();
    QString check_winner();
};

#endif // MAINWINDOW_H
