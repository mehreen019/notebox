#pragma once

#include <QMainWindow>
#include "ui_dashboard.h"
#include "Header.h"
#include "notes.h"
#include "button.h"
#include "sclButton.h"
#include "cell.h"
#include "image.h"
#include "publicWorkspace.h"
#include "remWindow.h"
#include <cstring>
#include "textviewwindow.h"
#include "info.h"

using namespace std;


class dashboard : public QMainWindow
{
	Q_OBJECT

public:
	dashboard(QWidget *parent = nullptr);
	~dashboard();

	string tf;
    string user;

	void addTask();
	void addPersonalNote(string title, string date);
	void addSclNote(string Cat, string Topic, string sub, string title, string date, string t);
	void addReminder();
	void addDeadline();
	string display(int);
    void addCells(string, int,int);
    void addPersCells(string, int, int);

	QVector<cell*> allCells;
	QVector<wsCell*> allPersCells;
	int rownumber;
	int feduprow;

	void readFromFile();
	void writeToFile();
	void addOnLoad();
	void bufferimg();
	notes* allNotes[1000];



public slots:
	void persNoteAddClick();
	void sclNoteAddClick();
	void submitPersNoteInfo();
	void submitSclNoteInfo();
	void submitFile();
	void receiveDelete(int num);
	void receiveDisplayImage(int);
	void receivePersDelete(int);
	void closeEvent(QCloseEvent* event) {
		emit crossClicked();
		event->ignore();
	}
	void handleClose();
	void uploadFile(int);
	void toWS();
	void backToDash();
	void toRem();
    void receiveUpdate(int);
    void receiveSclUpdate(int);
    void onUpdateSubmitClick();
    void receiveInfo(int);
    //void onSclUpdateSubmitClick();

signals:
	void crossClicked();

private slots:
    void on_exitbtn_clicked();

private:
    Ui::dashboard ui;
	//vector<notes*> sclNotes;
	//vector<notes*> personal;
    vector<string> pTypeArr;
	button* b;
	sclButton* sb;
	image* img;
	publicWorkspace* pws;
	remWindow* w;
    textViewWindow * textView;
    updateButton* ub;
    info* Info;
	//vector<task> tasks;

};
