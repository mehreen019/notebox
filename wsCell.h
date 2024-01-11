#pragma once

#include <QMainWindow>
#include "Header.h"
#include "ui_wsCell.h"

class wsCell : public QMainWindow
{
	Q_OBJECT

public:
	wsCell(QWidget *parent = nullptr);
	~wsCell();

	int cellNum;
	int unique;
	void setTitle(std::string t);

public slots:
	void onDeleteClick();
	void onDisplayClick();

signals:
	void sendDeleteCellSignal(int cellNum);
	void sendDisplayImage(int);

private:
	Ui::wsCellClass ui;
};
