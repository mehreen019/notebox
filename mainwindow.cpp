#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#define bgFilePath "E:/coding/projects/hopefullyfinalnotebox/img/four.jpg"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(bgFilePath);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_Login_clicked()
{
    hide();
    loginWindow = new LoginWindow(this);
    loginWindow->setWindowTitle("Log in");
    loginWindow->show();
}
void MainWindow::on_pushButton_AddUser_clicked()
{
    hide();
    addUserWindow = new AddUserWindow(this);
    addUserWindow->setWindowTitle("Sign Up");
    addUserWindow->show();
}
