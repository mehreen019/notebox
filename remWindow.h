#pragma once

#include <QMainWindow>
#include "ui_remWindow.h"
#include "Header.h"
#include "remEdit.h"

class remWindow : public QMainWindow
{
	Q_OBJECT

public:
    remWindow(QWidget *parent = nullptr, QString user="");
	~remWindow();
    QString user;

private slots:
	void on_reminder_add_clicked();
	void show_message();
	void on_Edit_button_clicked();
	void toDash();
public slots:
	void on_back_button_clicked();

signals:
	void sendToDash();

private:
	Ui::remWindowClass ui;
	QVector<QTimer*> timers;
	remEdit* re;
};
