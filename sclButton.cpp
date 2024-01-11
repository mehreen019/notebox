#include "sclButton.h"

sclButton::sclButton(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.imgUpload, SIGNAL(clicked()), parent, SLOT(submitFile()));
	connect(ui.infoSubmit, SIGNAL(clicked()), parent, SLOT(submitSclNoteInfo()));
}

sclButton::~sclButton()
{}


