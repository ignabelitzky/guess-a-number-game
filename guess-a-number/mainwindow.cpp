#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomnumber.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->inputLineEdit->setEnabled(false);
    ui->tryPushButton->setEnabled(false);
    ui->stateLabel->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

static int generateRandomNumber(int to, int from) {
    // Initialize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr))};

    // Create a reusable random number generator that generates uniform numbers between 1 and 100
    std::uniform_int_distribution<> die{to, from};

    // Set a random number
    int randomNumber = die(mersenne);
    return randomNumber;
}


void MainWindow::on_pushButton_clicked()
{
    int from = ui->fromLineEdit->text().toInt();
    int to = ui->toLineEdit->text().toInt();
    rndNumber = generateRandomNumber(from, to);
    ui->inputLabel->setText("Guess the number...");
    ui->inputLineEdit->setEnabled(true);
    ui->tryPushButton->setEnabled(true);
}


void MainWindow::on_tryPushButton_clicked()
{
    int userGuess = ui->inputLineEdit->text().toInt();
    if(userGuess > rndNumber) {
        ui->stateLabel->setText("The random number is less than " + QString::number(userGuess) + "\n try again...");
    } else if(userGuess < rndNumber) {
        ui->stateLabel->setText("The random number is greater than " + QString::number(userGuess) + "\ntry again...");
    } else {
        ui->stateLabel->setText("Congratulations!!! You won!!!");
        ui->inputLineEdit->setEnabled(false);
        ui->tryPushButton->setEnabled(false);
    }
}

