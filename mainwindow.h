#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
//#include "dashboard.h"
#include "loginwindow.h"
#include "adduserwindow.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Login_clicked();
    void on_pushButton_AddUser_clicked();

private:
    Ui::MainWindow *ui;
    //Dashboard * dashboard;
    LoginWindow * loginWindow;
    AddUserWindow * addUserWindow;
};
#endif // MAINWINDOW_H
