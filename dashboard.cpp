#include "dashboard.h"
#define filepath "E:/coding/projects/hopefullyfinalnotebox/userInfo.txt"
int cellToUpdate;


dashboard::dashboard(QWidget *parent)
    : QMainWindow(parent), rownumber(0), feduprow(0), tf(""), b(NULL), img(NULL), pws(NULL)
{
	ui.setupUi(this); 
	connect(ui.noteAdd, SIGNAL(clicked()), this, SLOT(persNoteAddClick()));
	connect(ui.sclNoteAdd, SIGNAL(clicked()), this, SLOT(sclNoteAddClick()));
	connect(this, SIGNAL(crossClicked()), this, SLOT(handleClose()));
	connect(ui.ws_button, SIGNAL(clicked()), this, SLOT(toWS()));
	connect(ui.reminderAdd, SIGNAL(clicked()), this, SLOT(toRem()));
    //connect(ui.exitbtn, SIGNAL(clicked), this, SLOT(handleClose()));
}

dashboard::~dashboard()
{
	for (int j = 0; j < rownumber; j++)
	{
		delete allNotes[j];
	}
}

void dashboard::toRem() {
    QString userr = QString::fromStdString(user);
    w = new remWindow(this, userr);
	w->show();

	connect(w, SIGNAL(toDash()), this, SLOT(backToDash()));
}

void dashboard::addTask()
{

}

void dashboard::addPersonalNote(string title, string date)
{
    //const char* neww = (const char*)malloc((tf.size() + 1)* sizeof(char)); // Allocate 1 more char
    //neww = tf.c_str();          // Correct number of bytes to copy
	//personalNotes tempPers(title, date, tf);

    int r = rand();
    allNotes[rownumber] = new personalNotes(title, date, tf, r, user);
    //const char* char_p = date.c_str();
    //QMessageBox::information(this, "success", neww);
	//qDebug() << rownumber;
    addPersCells(allNotes[rownumber]->Gettitle(), r, rownumber);
    rownumber++;
	//string n=display(0);
}

string dashboard::display(int num) {
	return allNotes[num]->getFile();
}

void dashboard::addOnLoad() {
	readFromFile();
	char q[10];
	sprintf(q, "%d", rownumber);
	QMessageBox::information(this, "success", q);
	feduprow = 1;
    for (int i = 0; i < rownumber; i++) {
        string uk= allNotes[i]->getUser();
                cout<< "the number of note is: "<<i<<"the notes user is: "<< uk << " and current username is: " << this->user <<endl;
                if(uk== this->user){

                    cout<<"ok1"<<endl;
                    string t = allNotes[i]->Gettitle();
                    int unique = allNotes[i]->getUnique();
                    string pType= allNotes[i]->get_type();
                    cout<<"ok2"<<endl;
                    if (pType == "sclN") {
                        addCells(t, unique, i);
                    }
                    else {
                        addPersCells(t, unique, i);
                    }
        }
		//QString qstr = QString::fromStdString();
        //addCells(allNotes[i]->getFile());
    }
}

void dashboard::handleClose() {
	
	writeToFile();
	//this->close();
	QMessageBox::information(this, "success", "written to file");
	QCoreApplication::quit();
	//QCloseEvent::QCloseEvent();
}

void dashboard::addCells(string t, int r, int num)
{
	//if (feduprow == 0) feduprow++;
	cell* newCell = new cell(this);
    //ui.gridLayout_2->addWidget(newCell, num+1, 0);
    ui.scrollArea->setWidgetResizable(true);

    ui.ver->addWidget(newCell);

	newCell->setAttribute(Qt::WA_DeleteOnClose, true);
    newCell->cellNum = num;
	newCell->unique = r;
	newCell->setTitle(t);
	allCells.push_back(newCell);

	connect(newCell, SIGNAL(sendDeleteCellSignal(int)), this, SLOT(receiveDelete(int)));
	connect(newCell, SIGNAL(sendDisplayImage(int)), this, SLOT(receiveDisplayImage(int)));
	connect(newCell, SIGNAL(sendUploadClick(int)), this, SLOT(uploadFile(int)));
    connect(newCell, SIGNAL(sendUpdateClick(int)), this, SLOT(receiveUpdate(int)));
    connect(newCell, SIGNAL(sendInfoClick(int)), this, SLOT(receiveInfo(int)));

    //rownumber++; sendUpdateClick(cellNum) sendInfoClick(cellNum)
	//feduprow++;
}

void dashboard::receiveUpdate(int num){
    cout<<"reached to update"<<endl;
    //ub = new updateButton(this);
    //ub->show();
    //cellToUpdate=num;
    receiveDelete(num);
    sb = new sclButton(this);
    sb->show();
    QMessageBox::information(this, "success", "update reached");
}

void dashboard::onUpdateSubmitClick(){

}

void dashboard::addPersCells(string t, int r, int num)
{
	//if (feduprow == 0) feduprow++;
	wsCell* newCell = new wsCell(this);
    //ui.gridLayout_2->addWidget(newCell, num + 1, 0);
    ui.scrollArea->setWidgetResizable(true);

    ui.ver->addWidget(newCell);

	newCell->setAttribute(Qt::WA_DeleteOnClose, true);
    newCell->cellNum = num;
	newCell->unique = r;
	newCell->setTitle(t);
	allPersCells.push_back(newCell);

	connect(newCell, SIGNAL(sendDeleteCellSignal(int)), this, SLOT(receiveDelete(int)));
	connect(newCell, SIGNAL(sendDisplayImage(int)), this, SLOT(receiveDisplayImage(int)));
    connect(newCell, SIGNAL(sendUpdateClick(int)), this, SLOT(receiveSclUpdate(int)));
    connect(newCell, SIGNAL(sendInfoClick(int)), this, SLOT(receiveInfo(int)));

    //rownumber++;
	//feduprow++;
}

void dashboard::receiveSclUpdate(int num){
    cout<<"reached to update"<<endl;
    //ub = new updateButton(this);
    //ub->show();
    //cellToUpdate=num;
    receiveDelete(num);
    b = new button(this);
    b->show();
    QMessageBox::information(this, "success", "update reached");
}

void dashboard::uploadFile(int num) {
    publicWorkspace::readFromFile();
	//QMessageBox::information(this, "success", "reached to upload");
	publicWorkspace::pubNotes[publicWorkspace::pubNoteNum] = allNotes[num];
	//publicWorkspace::addCells();
	publicWorkspace::pubNoteNum++;
	publicWorkspace::writeToFile();
	QMessageBox::information(this, "success", "uploaded");
}

void dashboard::toWS() {

    { pws = new publicWorkspace(this);  }
    pws->addOnLoad();
	pws->show();
	this->hide();

	connect(pws, SIGNAL(sendToDash()), this, SLOT(backToDash()));
}

void dashboard::backToDash() {
	this->show();
}

void dashboard::receiveInfo(int num){
    //QMessageBox::information(this, "success", "info show");
    Info = new info(this);
    //Info->setModal(true);
    Info->setTitle(allNotes[num]->Gettitle());
    Info->setDate(allNotes[num]->Getdate());
    Info->setCategory(allNotes[num]->getCategory());
    Info->setTopic(allNotes[num]->getTopic());
    Info->setSubject(allNotes[num]->getSubject());
    Info->show();

    connect(Info, SIGNAL(sendToDash()), this, SLOT(backToDash()));

}

void dashboard::receiveDelete(int num) {
    QMessageBox::information(this, "success", "deleted");
	for (int i = 0; i < rownumber; i++) {
        if (allNotes[i]->getUnique() == num) {
			//allCells[i]->close();
			for (int j = i; j < rownumber; j++) {
				if (j + 1 == rownumber) break;

				allNotes[j] = allNotes[j + 1];
				//allCells[j] = allCells[j + 1];
			}
			rownumber--;
			break;
		}
	}
}

void dashboard::receivePersDelete(int num) {
	/*for (int i = 0; i < rownumber; i++) {
		if (allNotes[i]->getUnique() == num) {
			allPersCells[i]->close();
			for (int j = i; j < rownumber; j++) {
				if (j + 1 == rownumber) break;

				allNotes[j] = allNotes[j + 1];
				allPersCells[j] = allPersCells[j + 1];
			}
			rownumber--;
			break;
		}
	}*/
}

void dashboard::bufferimg() {
	QMessageBox::information(this, "success", "ok");
	QMessageBox::information(this, "success", allNotes[0]->Gettitle().c_str());
}

void dashboard::receiveDisplayImage(int num) {
	char q[10];
	sprintf(q, "%d", num);
	string kk = allNotes[num]->getFile();
	//bufferimg();
	//for (int i = 0; i < rownumber; i++) {
		//if (i == num) {
			//p_type ptype = allNotes[i]->get_type();
    if(kk[kk.size()-1]=='t'){
        textView = new textViewWindow(this, kk);
        textView->show();
    }
    else{
			//
			img = new image(this);

			QMessageBox::information(this, "success", kk.c_str());
			//string ft = allNotes[i]->getFile();
			//string ft = allNotes[i]->fp;
			//QMessageBox::information(this, "success", "pic received");
            //const char* temp = kk.c_str();
            img->finallyImageOutput(kk.c_str());
			//break;
    }
	//}
}

void dashboard::addSclNote(string Cat, string Topic, string sub, string title, string date, string tf)
{
	int r = rand();
    allNotes[rownumber]= new schoolNotes(Cat, Topic, sub, title, date, tf, r, user);
	QMessageBox::information(this, "success", "info loaded");
    addCells(allNotes[rownumber]->Gettitle(), r, rownumber);
    rownumber++;
}

void dashboard::persNoteAddClick() {
	
	b = new button(this);
	b->show();
	
}

void dashboard::sclNoteAddClick() {

	sb = new sclButton(this);
	sb->show();
}



void dashboard::submitFile() {
    QString pic = QFileDialog::getOpenFileName(
        this, "Open file", "C://", "Text files (*.txt);;Images (*.png *.xpm *.jpg)"	);
    QString picpath = pic.replace(" ", "-");
	string p = picpath.toLocal8Bit().constData();
    if(p==""){QMessageBox::information(this, "WARNING", "no file uploaded"); return; }
	tf = p;
	//char* ff;
	//strcpy(tf, p.c_str());
	//QMessageBox::information(this, "runs", tf);

	//tf = fopen(char_p, "r");
	

	/*if (tf == "") {
		QMessageBox::information(this, "failed", "pic has not been loaded");
	}*/
}

void dashboard::submitPersNoteInfo() {
	//QMessageBox::information(this, "success", "info loaded");
    QString t = b->ui.lineEdit_title->text();
    if(t==""){QMessageBox::information(this, "WARNING", "no title given"); return; }
    QString title = t.replace(" ", "-");
    QString d = b->ui.lineEdit_date->text();
    if(d==""){QMessageBox::information(this, "WARNING", "no date given"); return; }
    QString date = d.replace(" ", "-");

    if(tf==""){QMessageBox::information(this, "WARNING", "no file uploaded"); return; }

	std::string mt = title.toLocal8Bit().constData();
	//note.Settitle(mt);

	std::string md = date.toLocal8Bit().constData();
	//note.Setdate(md);
	
	//QMessageBox::information(this, "runs", tf);
	addPersonalNote(mt, md);

	b->close();
}

void dashboard::submitSclNoteInfo() {
	//QMessageBox::information(this, "success", "info loaded");
    QString t = sb->ui.title->text();
    if(t==""){QMessageBox::information(this, "WARNING", "no title given"); return; }
    QString title = t.replace(" ", "-");

    QString  d= sb->ui.date->text();
    if(d==""){QMessageBox::information(this, "WARNING", "no date given"); return; }
    QString date = d.replace(" ", "-");

    QString  pi= sb->ui.category->text();
    if(pi==""){QMessageBox::information(this, "WARNING", "no category given"); return; }
    QString category = pi.replace(" ", "-");

    QString  top= sb->ui.topic->text();
    if(top==""){QMessageBox::information(this, "WARNING", "no topic given"); return; }
    QString topic = top.replace(" ", "-");

    QString sub = sb->ui.subject->text();
    if(sub==""){QMessageBox::information(this, "WARNING", "no subject given"); return; }
    QString subject = sub.replace(" ", "-");

    if(tf==""){QMessageBox::information(this, "WARNING", "no file uploaded"); return; }

	std::string mt = title.toLocal8Bit().constData();
	//note.Settitle(mt);

	std::string md = date.toLocal8Bit().constData();
	//note.Setdate(md);
	std::string mc = category.toLocal8Bit().constData();
	std::string mto = topic.toLocal8Bit().constData();
	std::string ms = subject.toLocal8Bit().constData();


	//QMessageBox::information(this, "runs", tf);
	addSclNote(mc, mto, ms, mt, md, tf);

	sb->close();
}

void dashboard::addReminder()
{

}
void dashboard::addDeadline()
{

}

void dashboard::readFromFile() {
	int size;
	string ptype;
	ifstream inf;
	inf.open(filepath, ios::in);
	if (!inf)
	{
		QMessageBox::information(this, "failed", "couldn't read info");
		return;
	}
	rownumber = 0;
	while (true)
	{
		/*inf.read((char*)&ptype, sizeof(ptype));
		if (inf.eof()) { cout << rownumber <<endl; break; }
		if (!inf)
		{
			QMessageBox::information(this, "failed", "couldn't read info");
			return;
		}
		switch (ptype)
		{
		case sclN:
			allNotes[rownumber] = new schoolNotes;
			size = sizeof(schoolNotes);
			break;
		case persN:
			allNotes[rownumber] = new personalNotes;
			size = sizeof(personalNotes);
			break;
		default: QMessageBox::information(this, "failed", "unknown class type");
		}
		inf.read((char*)allNotes[rownumber], size);
		if (!inf)
		{
			QMessageBox::information(this, "failed", "couldn't read info");
			return;
		}
		QMessageBox::information(this, "success", "cell loaded");*/
		if (inf.eof()) { cout << rownumber << " end of file" << endl; break; }
		inf >> ptype;
		if (!inf)
		{
            cout << rownumber << " can't open file2" << endl;
			return;
		}
        pTypeArr.push_back(ptype);
		if (ptype == "sclN") {
			allNotes[rownumber] = new schoolNotes();
			size = sizeof(schoolNotes);
		}
		else if (ptype == "persN") {
			allNotes[rownumber] = new personalNotes();
			size = sizeof(personalNotes);
			cout << "type detected" << endl;
		}
		else cout << "unknown class type" << endl;

		allNotes[rownumber]->deserialize(inf);

       /* string uk= allNotes[rownumber]->getUser();
        cout<< rownumber << " and username is: " << this->user <<endl;
        if(uk== this->user){

            string t = allNotes[rownumber]->Gettitle();
            int unique = allNotes[rownumber]->getUnique();

            if (ptype == "sclN") {
                addCells(t, unique);
            }
            else {
                addPersCells(t, unique);
            }
        }*/
		//addCells(t, unique);
		//cout << allNotes[rownumber]->Getdate() << " " << allNotes[rownumber]->getFile() << "printed from read" << endl;
        rownumber++;
	}
	inf.close();
}

void dashboard::writeToFile() {

	int size;
	ofstream ouf;
	string ptype;
    cout<<"ok "<<rownumber<<endl;
    ouf.open(filepath, ios::out);
	if (!ouf)
	{
		//qDebug() << "\nCan't open file\n"; return;
		QMessageBox::information(this, "failed", "couldn't write info");
		return;
	}
	for (int j = 0; j < rownumber; j++)
	{
		/*if (typeid(*allNotes[j]) == typeid(schoolNotes)) {
			ptype = sclN;
		}
		else {
			ptype = persN;
		}*/
		//ptype = allNotes[j]->get_type();
		/*ptype = sclN;
		QMessageBox::information(this, "success", "cross clicked");
		ouf.write((char*)&ptype, sizeof(ptype));

		switch (ptype)
		{
		case sclN: size = sizeof(schoolNotes); break;
		case persN: size = sizeof(personalNotes); break;
		}
		ouf.write((char*)(allNotes[j]), size);
		if (!ouf)
		{
			//cout << "\nCan�t write to file\n"; return;
			QMessageBox::information(this, "failed", "couldn't read info");
			return;
		}*/
        cout<< j << " " <<  allNotes[j]->Gettitle() << endl;
		ptype = allNotes[j]->get_type();
		ouf << ptype << " ";
		allNotes[j]->serialize(ouf);
		if (!ouf)
		{
			QMessageBox::information(this, "failed", "couldn't read info");
			return;
		}

	}
	ouf.close();
	/*int size;
	int arrSize;
	bool isScl=false;
	ofstream ouf;
	p_type ptype = num;

	switch (ptype)
	{
	case sclN:
		size = sizeof(schoolNotes);
		arrSize = sclNotes.size();
		isScl = true;
		break;
	case persN:
		size = sizeof(personalNotes);
		arrSize = personal.size();
		isScl = false;
		break;
	}
	ouf.open(filepath, ios::trunc | ios::binary);
	if (!ouf)
	{
		qDebug() << "\nCan't open file\n"; return;
	}

	for (int j = 0; j < arrSize; j++)
	{
		ouf.write((char*)&ptype, sizeof(ptype));
		if (isScl)
		{
			ouf.write((char*)(sclNotes[j]), size);
		}
		else
		{
			ouf.write((char*)(personal[j]), size);
		}
		
		if (!ouf)
		{
			qDebug() << "\nCan't write to file\n"; return;
		}
	}*/

}


void dashboard::on_exitbtn_clicked()
{
    handleClose();
}

