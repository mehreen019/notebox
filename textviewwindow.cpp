#include "textviewwindow.h"
#include "ui_textviewwindow.h"
#define filePath "E:/coding/projects/hopefullyfinalnotebox/mytext.txt"


textViewWindow::textViewWindow(QWidget *parent, std::string filepath) :
    QMainWindow(parent),
    ui(new Ui::textViewWindow)
{
    ui->setupUi(this);
    QFile file( QString::fromStdString(filepath));
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "error", "cannot open");

    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}

textViewWindow::~textViewWindow()
{
    delete ui;
}
