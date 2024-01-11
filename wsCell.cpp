#include "wsCell.h"

wsCell::wsCell(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.delete2, SIGNAL(clicked()), this, SLOT(onDeleteClick()));
	connect(ui.display, SIGNAL(clicked()), this, SLOT(onDisplayClick()));
    connect(ui.update, SIGNAL(clicked()), this, SLOT(sendUpdate()));
    connect(ui.showInfo, SIGNAL(clicked()), this, SLOT(onShowInfoClick()));
}

wsCell::~wsCell()
{}

void wsCell::onShowInfoClick(){
    QMessageBox::information(this, "success", "info show");
    emit sendInfoClick(cellNum);
}

void wsCell::setTitle(std::string t)
{
	QString qstr = QString::fromStdString(t);
	ui.label->setText(qstr);
}

void wsCell::sendUpdate(){
    emit sendUpdateClick(unique);
    this->close();

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
