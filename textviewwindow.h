#ifndef TEXTVIEWWINDOW_H
#define TEXTVIEWWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>
namespace Ui {
class textViewWindow;
}

class textViewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit textViewWindow(QWidget *parent = nullptr, std::string filepath = "E:/coding/projects/hopefullyfinalnotebox/mytext.txt");
    ~textViewWindow();

private:
    Ui::textViewWindow *ui;
};

#endif // TEXTVIEWWINDOW_H
