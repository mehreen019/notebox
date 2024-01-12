#include "adduserwindow.h"
#include "ui_adduserwindow.h"
#include <iostream>
#define bgFilePath "E:/coding/projects/hopefullyfinalnotebox/four.jpg"

AddUserWindow::AddUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(bgFilePath);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

AddUserWindow::~AddUserWindow()
{
    delete ui;
}

void AddUserWindow::on_pushButton_AddUser_clicked()
{
    QString userName = ui->lineEdit_userName->text();
    QString userPassword = ui->lineEdit_userPassword->text();
    QString name = ui->lineEdit_name->text();
    QString id = ui->lineEdit_id->text();
    QString email = ui->lineEdit_email->text();

    if(userName.isEmpty())
    {
        QMessageBox::information(this, "Warning", "username cannot be empty"); return;
    }
    if(userPassword.isEmpty())
    {
        QMessageBox::information(this, "Warning", "password cannot be empty"); return;
    }
    if(name.isEmpty())
    {
        QMessageBox::information(this, "Warning", "name cannot be empty"); return;
    }
    if(id.isEmpty())
    {
        QMessageBox::information(this, "Warning", "id cannot be empty"); return;
    }
    if(email.isEmpty())
    {
        QMessageBox::information(this, "Warning", "email cannot be empty"); return;
    }

    LoginWindow::readAll();
    bool userNameExists = LoginWindow::findUser(userName);
    if(userNameExists)
    {
        QMessageBox::information(this, "Invalid Username", "Username already exists");
        return;
    }

    //LoginWindow::addUser(userName, userPassword, name, id, email);

    hide();
    loginWindow = new LoginWindow;
    loginWindow->setWindowTitle("Log in");
    loginWindow->readAll();
    loginWindow->addUser(userName, userPassword, name, id, email);
    loginWindow->writeAll();
    loginWindow->show();
}


void AddUserWindow::on_pushButton_login_clicked()
{
    hide();
    loginWindow = new LoginWindow;
    loginWindow->setWindowTitle("Log in");
    loginWindow->readAll();
    loginWindow->writeAll();
    loginWindow->show();
}

