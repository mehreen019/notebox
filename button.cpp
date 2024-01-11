#include "button.h"

button::button(QWidget *parent)
    : QMainWindow(parent)
{ 
    ui.setupUi(this);
    connect(ui.upload, SIGNAL(clicked()), parent, SLOT(submitFile()));
    connect(ui.submit_info, SIGNAL(clicked()), parent, SLOT(submitPersNoteInfo()));
}

button::~button()
{

}

/*void button::click() {
    QMessageBox::information(this, "runs", "ok");
    QString picpath = QFileDialog::getOpenFileName(
        this, "Open file", "C://", "JPG file(*.jpg)::PNG file(*.png)"
    );
    
}*/

void button::ffs_click() {
    
    QString picpath = QFileDialog::getOpenFileName(
        this, "Open file", "C://", "JPG file(*.jpg)::PNG file(*.png)"
    );
    
    
    
    /*std::string p = picpath.toLocal8Bit().constData();
    const char* char_p = p.c_str();
    //QMessageBox::information(this, "runs", picpath);

    FILE* tempfile = fopen( char_p , "r");
    note.setFile(tempfile);

    if (!tempfile) {
            QMessageBox::information(this, "failed", "pic has not been loaded");
    }*/


    /*QImage image;

    // Load an image from file
    bool loadSuccess = image.load(picpath);
    if (loadSuccess) {
        QMessageBox::information(this, "success", "pic has been loaded");
    }
    */

}

void button::submit_all_info() {
    QMessageBox::information(this, "success", "info loaded");
    QString title = ui.lineEdit_title->text();
    QString date = ui.lineEdit_date->text();

    //QString pic = ui.upload->

    std::string mt = title.toLocal8Bit().constData();
    note.Settitle(mt);

    std::string md = date.toLocal8Bit().constData();
    note.Setdate(md);



    button::close();
}