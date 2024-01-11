#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::info)
{
    ui->setupUi(this);
    connect(ui->backToDash, SIGNAL(clicked()), this, SLOT(back()));
}

info::~info()
{
    delete ui;
}

void info::setTitle(std::string t)
{
    QString qstr = QString::fromStdString(t);
    ui->title->setText(qstr);
}

void info::setDate(std::string t)
{
    QString qstr = QString::fromStdString(t);
    ui->date->setText(qstr);
}

void info::setCategory(std::string t)
{
    QString qstr = QString::fromStdString(t);
    ui->catogory->setText(qstr);
}

void info::setSubject(std::string t)
{
    QString qstr = QString::fromStdString(t);
    ui->subject->setText(qstr);
}

void info::setTopic(std::string t)
{
    QString qstr = QString::fromStdString(t);
    ui->topic->setText(qstr);
}

void info::back(){
    this->close();
    emit sendToDash();
}

