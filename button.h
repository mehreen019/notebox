#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_button.h"
#include "Header.h"
#include "notes.h"


class button : public QMainWindow
{
    Q_OBJECT

public:
    button(QWidget *parent = nullptr);
    ~button();
    notes note;
    Ui::buttonClass ui;

public slots:
    void ffs_click();
    void submit_all_info();
    
private:
    
    QPushButton* btn;
};
