#pragma once

#include <QMainWindow>
#include "ui_sclButton.h"
#include "notes.h"

class sclButton : public QMainWindow
{
	Q_OBJECT

public:
	sclButton(QWidget *parent = nullptr);
	~sclButton();
	notes note;
	Ui::sclButtonClass ui;

private:
	
};
