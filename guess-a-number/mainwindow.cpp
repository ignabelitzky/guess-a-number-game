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
    ui->stateLabel->setText("");
    if(from < to) {
        rndNumber = generateRandomNumber(from, to);
        ui->inputLabel->setText("Guess the number...");
        ui->inputLineEdit->setEnabled(true);
        ui->tryPushButton->setEnabled(true);
    } else {
        ui->stateLabel->setText("Try again ('to' is less or equal than 'from')");
    }
}


void MainWindow::on_tryPushButton_clicked()
{
    int clue = generateRandomNumber(1, 3);
    int userGuess = ui->inputLineEdit->text().toInt();
    if(userGuess == rndNumber) {
        ui->stateLabel->setText("Congratulations!!! You won!!!");
        ui->inputLineEdit->setEnabled(false);
        ui->tryPushButton->setEnabled(false);
        ui->inputLabel->setText("");
    } else {
        switch(clue) {
        case 1:
            if(userGuess < rndNumber) {
                ui->stateLabel->setText("The random number is greater than " + QString::number(userGuess) + "\ntry again please...");
            } else {
                ui->stateLabel->setText("The random number is less than " + QString::number(userGuess) + "\ntry again please...");
            }
            break;
        case 2:
            if(rndNumber % 2 == 0) {
                ui->stateLabel->setText("The number you seek is even.");
            } else {
                ui->stateLabel->setText("The number you seek is odd");
            }
            break;
        case 3:
            if(rndNumber % 5 == 0 || rndNumber % 10 == 0) {
                ui->stateLabel->setText("The number you seek it's a multiple of 5 or 10");
            } else {
                ui->stateLabel->setText("The number you seek it's not a multiple of 5 or 10");
            }
            break;
        default:
            break;
        }
    }

}
