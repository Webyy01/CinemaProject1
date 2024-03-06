#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "Users.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui ->errorLabel->setVisible(false);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    bool nameFound =false, passwordFound=false;
    QString username = ui->labelUsername->text();
    QString password = ui->labelPassword->text();
    for(int i = 0; i < usersCount; i++){
        if(username.compare(usernames[i]))
            nameFound = true;
        if(password.compare(passwords[i]))
            passwordFound = true;
        if(nameFound && passwordFound)
            break;
    }
    if(nameFound && passwordFound){
        hide();
        WelcomeWindow* welcomeWindow = new WelcomeWindow(this, username, 20);
        welcomeWindow->show();
    }
    else{
        ui->errorLabel->setVisible(true);
        return;
    }
}


void LoginWindow::on_registerButton_clicked()
{

    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

