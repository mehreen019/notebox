#include "updatepasswordwindow.h"
#include "ui_updatepasswordwindow.h"
#include "loginwindow.h"

LoginWindow * loginWindow;

updatePasswordWindow::updatePasswordWindow(QWidget *parent, std::string s) :

    QMainWindow(parent),
    ui(new Ui::updatePasswordWindow)
{
    userName = s;
    ui->setupUi(this);
}

updatePasswordWindow::~updatePasswordWindow()
{
    delete ui;
}

void updatePasswordWindow::on_pushButton_Save_clicked()
{
    loginWindow->readAll();
    QString newPassword = ui->lineEdit_newPassword->text();
    QString confirmPassword = ui->lineEdit_confirmPassword->text();
    if(newPassword == confirmPassword)
    {
        loginWindow->updateUser(QString::fromStdString(userName), newPassword);
    }
    else
    {
        QMessageBox::information(this, "Update Password", "Passwords do not match");
    }
    //loginWindow->writeAll();
}


void updatePasswordWindow::on_pushButton_cancel_clicked()
{

}


void updatePasswordWindow::on_pushButton_goBack_clicked()
{
    hide();
    loginWindow = new LoginWindow;
    loginWindow->setWindowTitle("Log in");
    loginWindow->readAll();
    loginWindow->writeAll();
    loginWindow->show();
}
