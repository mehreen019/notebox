#pragma once
//#include <QMainWindow>
#include "ui_publicWorkspace.h"
#include "Header.h"
#include "notes.h"
#include "wsCell.h"
#include "image.h"
#include <cstring>
#include "textviewwindow.h"
#include "sclButton.h"
#include "pwsCell.h"
#include "info.h"

class publicWorkspace : public QMainWindow
{
	Q_OBJECT

public:
	publicWorkspace(QWidget *parent = nullptr);
	~publicWorkspace();
	//static void uploadFile();
	void filterByName();
	void filterByTopic();
	void filterByUser();
	void filterBySubject();
    void addCells(string, int, int);
	static notes* pubNotes[];
	static int pubNoteNum;

    QVector<pwsCell*> allCells;

	void addOnLoad();
    static void readFromFile();
	static void writeToFile();

public slots:
	void onToDashClick();
	void receiveDelete(int num);
	void receiveDisplayImage(int);
	void closeEvent(QCloseEvent* event) {
		emit crossClicked();
		event->ignore();
	}
	void handleClose();
    void receiveInfo(int);

signals:
	void sendToDash();
	void crossClicked();

private:
	Ui::publicWorkspaceClass ui;
	image* img;
    textViewWindow * textView;
    info* Info;
};
