#ifndef NOTES_H
#define NOTES_H
#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

enum p_type { sclN, persN, n };

class notes
{
public:
    notes();
    notes(string title, string date, string t, int uid, string u);
    virtual ~notes();
    
    static int id;

    string Gettitle() { return title; }
    void Settitle(string val) { title = val; }
    string Getdate() { return date; }
    void Setdate(string val) { date = val; }
    void setFile(string tempFile) { fp = tempFile; }
    string getFile() { return fp; }
    void setUnique() { uid = rand(); }
    int getUnique() { return uid;  }
    void setUser(string t) { userName=t; }
    string getUser() { return userName; }
    virtual string getCategory() { return "None"; }
    virtual string getTopic() { return "None"; }
    virtual string getSubject() { return "None"; }
    

    void displayinfo();
    virtual string get_type();

    virtual void serialize(ofstream& out) const
    {
        out << title << " " << date << " " << fp << " " << uid << " " << userName << " ";
    }

    virtual void deserialize(ifstream& in)
    {
        in >> title >> date >> fp >> uid >> userName;
    }
    
    
protected:

private:
    string title;
    string date;
    //FILE* fp;
    string fp;
    int uid;
    string userName;
};

class personalNotes : public notes
{
private:

public:
    personalNotes();
    personalNotes(string title, string date, string t,int uid, string u);
    void updateNoteInfo();

    void serialize(ofstream& out) const override
    {
        notes::serialize(out);
        // Additional serialization for personalNotes
    }
    void deserialize(ifstream& in) override
    {
        notes::deserialize(in);
        // Additional deserialization for personalNotes
    }

};

class schoolNotes : public notes
{
private:
    string category;
    string topicName;
    string subject;
    

public:
    schoolNotes();
    schoolNotes(string Cat, string Topic, string sub, string title, string date, string t, int uid, string u);
 
    string getCategory() override{ return category; }
    void setCategory(string cat) { category = cat; }
    string getTopic() override{ return topicName; }
    void setTopic(string top) { topicName = top; }
    string getSubject() override{ return subject; }
    void setSubject(string sub) { subject = sub; }

    void serialize(ofstream& out) const override
    {
        notes::serialize(out);
        out << category << " " << topicName << " " << subject << " ";
    }

    void deserialize(ifstream& in) override
    {
        notes::deserialize(in);
        in >> category >> topicName >> subject;
    }
};

#endif // NOTES_H

