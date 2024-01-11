#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QLabel>
#include "dashboard.h"
#include "user.h"
#include <QFile>
#include <QByteArray>
#include <fstream> //for file-stream functions
#include <iostream>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    static void addUser(QString userName,QString userPassword, QString name, QString id, QString email);
    bool login();
    void updateUser();
    static bool findUser(QString userToFind);
    bool deleteUser();
    static User* userList[];
    static int n;
    static void readAll();
    static void writeAll();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::LoginWindow *ui;
   // Dashboard * userDashboard;
    dashboard * userDashboard;
    static QMap <QString, QString> passwordManager;

    QString userName;
    QString userPassword;
};

#endif // LOGINWINDOW_H
