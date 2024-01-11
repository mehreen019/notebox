#include "updatebutton.h"
#include "ui_updatebutton.h"

updateButton::updateButton(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::updateButton)
{
    ui->setupUi(this);
    connect(ui->submit, SIGNAL(clicked()), parent, SLOT(onUpdateSubmitClick()));
}

updateButton::~updateButton()
{
    delete ui;
}
