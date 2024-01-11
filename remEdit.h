#pragma once

#include <QDialog>
#include "ui_remEdit.h"
#include "Header.h"

class remEdit : public QDialog
{
	Q_OBJECT

public:
    remEdit(QWidget *parent = nullptr, const QString& username=" ");
	~remEdit();
    QString user;
	QListWidget* getListWidget() const;

private slots:
	void on_remove_clicked();
	void on_back_clicked();

	void on_save_clicked();

signals:
	void toRemWindow();

private:
	Ui::remEditClass ui;
	QVector<QTimer*> timers;
};

