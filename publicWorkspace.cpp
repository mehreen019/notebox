#include "publicWorkspace.h"
#define filepath "E:/coding/projects/hopefullyfinalnotebox/WSinfo.txt"

publicWorkspace::publicWorkspace(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.toDash, SIGNAL(clicked()), this, SLOT(onToDashClick()));
	connect(this, SIGNAL(crossClicked()), this, SLOT(handleClose()));
}

int publicWorkspace::pubNoteNum = 0;
notes* publicWorkspace::pubNotes[1000];

publicWorkspace::~publicWorkspace()
{}

/*void publicWorkspace::uploadFile()
{

}*/
void publicWorkspace::handleClose() {

	publicWorkspace::writeToFile();
	//this->close();
	QMessageBox::information(this, "success", "written to file");
	QCoreApplication::quit();
	//QCloseEvent::QCloseEvent();
}

void publicWorkspace::addCells(string t, int r, int pNum) {
	QMessageBox::information(this, "success", "reached to upload");
    pwsCell* newCell = new pwsCell(this);
    //ui.gridLayout_2->addWidget(newCell, pNum +1 , 0);
    ui.scrollArea->setWidgetResizable(true);

    ui.ver->addWidget(newCell);

	newCell->setAttribute(Qt::WA_DeleteOnClose, true);
    newCell->cellNum = pNum;
	newCell->unique = r;
	newCell->setTitle(t);
	allCells.push_back(newCell);

    //connect(newCell, SIGNAL(sendDeleteCellSignal(int)), this, SLOT(receiveDelete(int)));
    connect(newCell, SIGNAL(sendDisplayImage(int)), this, SLOT(receiveDisplayImage(int)));
    connect(newCell, SIGNAL(sendInfoClick(int)), this, SLOT(receiveInfo(int)));

    //pubNoteNum++;
}

void publicWorkspace::receiveInfo(int num){
    //QMessageBox::information(this, "success", "info show");
    Info = new info(this);
    //Info->setModal(true);
    Info->setTitle(pubNotes[num]->Gettitle());
    Info->setDate(pubNotes[num]->Getdate());
    Info->setCategory(pubNotes[num]->getCategory());
    Info->setTopic(pubNotes[num]->getTopic());
    Info->setSubject(pubNotes[num]->getSubject());
    Info->show();

    connect(Info, SIGNAL(sendToDash()), this, SLOT(backToDash()));

}

void publicWorkspace::receiveDelete(int num) {
	for (int i = 0; i < pubNoteNum; i++) {
		if (pubNotes[i]->getUnique() == num) {
			allCells[i]->close();
			for (int j = i; j < pubNoteNum; j++) {
				if (j + 1 == pubNoteNum) break;

				pubNotes[j] = pubNotes[j + 1];
				allCells[j] = allCells[j + 1];
			}
			pubNoteNum--;
			break;
		}
	}
}

void publicWorkspace::receiveDisplayImage(int num) {
	char q[10];
	sprintf(q, "%d", num);
	string kk = pubNotes[num]->getFile();
    if(kk[kk.size()-1]=='t'){
        textView = new textViewWindow(this, kk);
        textView->show();

    }
    else{
	img = new image(this);

	QMessageBox::information(this, "success", kk.c_str());
    const char * temp = kk.c_str();
    img->finallyImageOutput(temp);
    }
}

void publicWorkspace::onToDashClick() {
	this->hide();
	writeToFile();
	emit sendToDash();
}

void publicWorkspace::filterByName()
{

}
void publicWorkspace::filterByTopic()
{

}
void publicWorkspace::filterByUser()
{

}
void publicWorkspace::filterBySubject()
{

}

void publicWorkspace::addOnLoad() {
	readFromFile();
	char q[10];
	sprintf(q, "%d", pubNoteNum);
	QMessageBox::information(this, "success", q);


    for(int i = 0; i < pubNoteNum; i++) {
        string t = pubNotes[i]->Gettitle();
        int unique = pubNotes[i]->getUnique();
        addCells(t, unique,i);
    }
}

void publicWorkspace::readFromFile() {
	int size;
	string ptype;
	ifstream inf;
	inf.open(filepath, ios::in);
	if (!inf)
	{
		//QMessageBox::information(this, "failed", "couldn't read info");
		return;
	}
    pubNoteNum = 0;
	while (true)
	{
		if (inf.eof()) { cout << pubNoteNum << " end of file" << endl; break; }
		inf >> ptype;
		if (!inf)
		{
            cout << pubNoteNum << "can't open file2" << endl;
			return;
		}
		if (ptype == "sclN") {
			pubNotes[pubNoteNum] = new schoolNotes();
			size = sizeof(schoolNotes);
		}
		else if (ptype == "persN") {
			pubNotes[pubNoteNum] = new personalNotes();
			size = sizeof(personalNotes);
			cout << "type detected" << endl;
		}
		else cout << "unknown class type" << endl;

		pubNotes[pubNoteNum]->deserialize(inf);

        //string t = pubNotes[pubNoteNum]->Gettitle();
        //int unique = pubNotes[pubNoteNum]->getUnique();
        //addCells(t, unique);
        //cout << pubNotes[pubNoteNum]->Getdate() << " " << pubNotes[pubNoteNum]->getFile() << " " << pubNoteNum << " printed from read" << endl;
		//rownumber++;
        pubNoteNum++;
	}
	inf.close();
}

void publicWorkspace::writeToFile() {
	int size;
	ofstream ouf;
	string ptype;
	ouf.open(filepath, ios::binary);
	if (!ouf)
	{
		//qDebug() << "\nCan't open file\n"; return;
		//QMessageBox::information(this, "failed", "couldn't write info");
		return;
	}
	for (int j = 0; j < pubNoteNum; j++)
	{
		ptype = pubNotes[j]->get_type();
		ouf << ptype << " ";
		pubNotes[j]->serialize(ouf);
		if (!ouf)
		{
			//QMessageBox::information(this, "failed", "couldn't read info");
			return;
		}

	}
	ouf.close();
}


