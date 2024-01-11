#ifndef ADDUSERWINDOW_H
#define ADDUSERWINDOW_H
#include "loginwindow.h"
#include <QDialog>

namespace Ui {
class AddUserWindow;
}

class AddUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserWindow(QWidget *parent = nullptr);
    ~AddUserWindow();

private slots:
    void on_pushButton_AddUser_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::AddUserWindow *ui;
    LoginWindow * loginWindow;
};

#endif // ADDUSERWINDOW_H
