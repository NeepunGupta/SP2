#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    compdur = 5000;
    ui->setupUi(this);
    ui->progressBar->reset();
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);
    connect(ui->RedButton, &QPushButton:: clicked,
            this,
            &MainWindow::RedButtonClicked);
    connect(ui->BlueButton, &QPushButton:: clicked,
            this,
            &MainWindow::BlueButtonClicked);
    connect(ui->startButton, &QPushButton:: clicked,
            this,
            &MainWindow::startGame);
   ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
   ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RedButtonClicked(){
    int b = mod.addInput(true);
    if(b == 2){
      mod.nextTurn();
      playcompTurn();
    }
    else if(b == 0){
        wrongAnswer();
    }
    ui->progressBar->setValue(mod.percentcomplete);
}

void MainWindow::BlueButtonClicked(){
    int b = mod.addInput(false);
    if(b == 2){
      mod.nextTurn();
      playcompTurn();
    }
    else if(b == 0){
        wrongAnswer();
    }
    ui->progressBar->setValue(mod.percentcomplete);
}

void MainWindow::startGame(){
    ui->startButton->setEnabled(false);
    ui->BlueButton->setEnabled(true);
    ui->RedButton->setEnabled(true);
    mod.newGame();
    mod.nextTurn();
    playcompTurn();
}

void MainWindow::playcompTurn(){
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);

    q.start(2000);
    while(q.remainingTime()!= 0){
    }
    q.stop();

    for(unsigned long i = 0; i < mod.compMove.size(); i++){
        if(mod.compMove[i]){
            ui->RedButton->setStyleSheet("background-color: rgb(255,150,150)");
            q.start(compdur);
            while(q.remainingTime()!= 0){
            }
            q.stop();
            ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
        }
        else{
            ui->BlueButton->setStyleSheet("background-color: rgb(150,150,255)");
            q.start(compdur);
            while(q.remainingTime()!= 0){
            }
            q.stop();
            ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
        }
    }
    if (compdur > 500){
        compdur *= .99;
    }

    ui->BlueButton->setEnabled(true);
    ui->RedButton->setEnabled(true);
}

void MainWindow::wrongAnswer(){
    ui->startButton->setEnabled(true);
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);

    QMessageBox::information(this, tr("Simon"), tr("You Lose!"));
}

