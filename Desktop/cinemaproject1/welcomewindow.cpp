#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "qpixmap.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, QString username, int age)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    ui->helloLabel->setText("Hello: " + username + " " + QString::number(age));

    QPixmap pix ("C://Users//omars//OneDrive//Documents//CinemaProject//WelcometotheCinemaLabProject11.jpg");
    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();
    ui->imageLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logoutButton_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow->show();
}

