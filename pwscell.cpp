#include "pwscell.h"
#include "ui_pwscell.h"

pwsCell::pwsCell(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pwsCell)
{
    ui->setupUi(this);
    connect(ui->displayImage, SIGNAL(clicked()), this, SLOT(onDisplayClick()));
    connect(ui->showInfo, SIGNAL(clicked()), this, SLOT(onShowInfoClick()));
}

pwsCell::~pwsCell()
{
    delete ui;
}

void pwsCell::onShowInfoClick(){
    QMessageBox::information(this, "success", "info show");
    emit sendInfoClick(cellNum);
}

void pwsCell::setTitle(std::string t)
{
    QString qstr = QString::fromStdString(t);
    ui->label->setText(qstr);
}


void pwsCell::onDisplayClick() {
    emit sendDisplayImage(cellNum);
}

