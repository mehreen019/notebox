#ifndef UPDATEPASSWORDWINDOW_H
#define UPDATEPASSWORDWINDOW_H

#include <QMainWindow>

namespace Ui {
class updatePasswordWindow;
}

class updatePasswordWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit updatePasswordWindow(QWidget *parent = nullptr, std::string s = "");
    ~updatePasswordWindow();

private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_goBack_clicked();

private:
    Ui::updatePasswordWindow *ui;
    std::string userName;
};

#endif // UPDATEPASSWORDWINDOW_H
