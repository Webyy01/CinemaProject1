#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "WelcomeWindow.h"
#include <iostream>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->errorAgesLessThanTweve->setVisible(false);
    ui->errorAllFieldMustBeFilled->setVisible(false);
    ui->errorAlreadyExisting->setVisible(false);
    ui->errorNotMatching->setVisible(false);

}
RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerButton_clicked()
{
    ui->errorAgesLessThanTweve->setVisible(false);
    ui->errorAllFieldMustBeFilled->setVisible(false);
    ui->errorAlreadyExisting->setVisible(false);
    ui->errorNotMatching->setVisible(false);

    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString reTypePassword = ui->lineEditRetypePassword->text();
    QString month = ui->monthComboBox->currentText();
    QString day = ui->dayLineEdit->text();
    QString year = ui->yearLineEdit->text();
    QString gender = "";
    QString accountType = "";
    QString genres[7];

    int age = 2024 - year.toInt();

    if(ui->femaleRadioButton->isChecked())
        gender = "female";
    else if(ui->maleRadioButton->isChecked())
        gender = "male";


    if(ui->adminRadioButton->isChecked())
        accountType="admin";
    else if (ui->userRadioButton->isChecked())
        accountType="user";

    int counter = 0;
    if(ui->ComedyCheckBox->isChecked())
    {
        genres[counter] = "Comedy";
        counter++;
    }
    if(ui->actionCheckBox->isChecked())
    {
        genres[counter] = "Action";
        counter++;
    }
    if(ui->romanceCheckBox->isChecked())
    {
        genres[counter] = "Romance";
        counter++;
    }
    if(ui->dramaCheckBox->isChecked())
    {
        genres[counter] = "Drama";
        counter++;
    }
    if(ui->horrorCheckBox->isChecked())
    {
        genres[counter] = "Horror";
        counter++;
    }
    if(ui->otherCheckBox->isChecked())
    {
        genres[counter] = "Other";
        counter++;
    }

    for(int i = 0; i < usersCount; i++){
        if(username == usernames[i]){
            ui->errorAlreadyExisting->setVisible(true);
            return;
        }
        if(reTypePassword != password){
            ui->errorNotMatching->setVisible(true);
            return;
        }
        if(age < 12){
            ui->errorAgesLessThanTweve->setVisible(true);
            return;
        }
        if(username == "" || password == "" || reTypePassword == "" || day == "" || year == "" || gender == "" || accountType == ""){
            ui->errorAllFieldMustBeFilled->setVisible(true);
            return;
        }
    }

    usernames[usersCount] = username;
    passwords[usersCount] = password;
    ages[usersCount] = age;
    usersCount++;


    this->hide();
    WelcomeWindow* welcomeWindow = new WelcomeWindow(this, username, age);
    welcomeWindow->show();


}

