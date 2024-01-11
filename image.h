#pragma once

#include <QMainWindow>
#include "ui_image.h"
#include "Header.h"
using namespace std;

class image : public QMainWindow
{
	Q_OBJECT

public:
	image(QWidget *parent = nullptr);
	~image();
	void finallyImageOutput(const char*);

private:
	Ui::imageClass ui;
};
