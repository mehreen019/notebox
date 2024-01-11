#pragma once

#include <QMainWindow>
#include "ui_cell.h"
#include "Header.h"
#include "updatebutton.h"

class cell : public QMainWindow
{
	Q_OBJECT

public:
	cell(QWidget *parent = nullptr);
	~cell();
	int cellNum;
	int unique;
	void setTitle(std::string t);

public slots:
	void onDeleteClick();
	void onDisplayClick();
	void onUploadClick();
    void onShowInfoClick();
    void sendUpdate();
signals:
	void sendDeleteCellSignal(int cellNum);
	void sendDisplayImage(int);
	void sendUploadClick(int);
    void sendUpdateClick(int);
    void sendInfoClick(int);

private:
	Ui::cellClass ui;
};
