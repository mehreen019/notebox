#include "notes.h"

int notes::id = 0;

notes::notes():title(""), date(""), fp("")
{

}

notes::~notes()
{
    //dtor
}

notes::notes(string Title, string Date, string t, int Uid, string u) :title(Title), date(Date), fp(t), uid(Uid), userName(u)
{

}

schoolNotes::schoolNotes() {

}

schoolNotes::schoolNotes(string Cat, string Topic, string sub, string title, string date,string t, int Uid, string u) :notes(title, date, t, Uid,u),category(Cat), topicName(Topic), subject(sub)
{

}

personalNotes::personalNotes() {

}

personalNotes::personalNotes(string title, string date, string t, int Uid,string u) :notes(title, date, t, Uid, u) {

}

string notes::get_type()
{
	if ( typeid(*this) == typeid(schoolNotes))
		return "sclN";
	else if ( typeid(*this) == typeid(personalNotes))
		return "persN";
	else
	{
		return "n";
		//cerr << "\nNo such  type"; exit(1);
	}

}
