#include "wsCell.h"

wsCell::wsCell(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.delete2, SIGNAL(clicked()), this, SLOT(onDeleteClick()));
	connect(ui.display, SIGNAL(clicked()), this, SLOT(onDisplayClick()));
}

wsCell::~wsCell()
{}

void wsCell::setTitle(std::string t)
{
	QString qstr = QString::fromStdString(t);
	ui.label->setText(qstr);
}

void wsCell::onDeleteClick() {
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "delete confirmation", "are you sure you want to delete?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
        emit sendDeleteCellSignal(unique);
		this->close();
	}
}

void wsCell::onDisplayClick() {
	emit sendDisplayImage(cellNum);
}
