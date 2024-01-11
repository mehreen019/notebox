#ifndef USER_H
#define USER_H

#include <QObject>
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <QLabel>
const int LEN = 50;
#include <cstring>

class User : public QObject
{
    Q_OBJECT
    public:
 //   User();
    explicit User(QObject *parent = nullptr);

     void setName(const char* s);
     void setId(const char* i);
     void setEmail(const char* s);
     void setUserName(const char* s);
     void setUserPassword(const char* s);

     const char* getUserName();
     const char* getUserPassword();
     const char* getName();
     const char* getId();
     const char* getEmail();

     private:
     char name[LEN]; //formal name
     char id[LEN];      // student id
     char userName[LEN];    // unique username
     char userPassword[LEN];  //password for login
     char email[LEN];
//    signals:
//        void mySignal(int value);

//    public slots:
//        void mySlot();

};

#endif // USER_H
