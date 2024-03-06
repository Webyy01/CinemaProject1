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

