#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QWidget>
#include <QObject>
#include "user.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <QCoreApplication>
#include <QDebug>
  class Controller : public QObject
{
    Q_OBJECT
    public:
   // Controller();
    explicit Controller(QObject *parent = nullptr);

//    signals:
//        void mySignal(int value);

//    public slots:
//        void mySlot();


      void addUser();
      //bool login();
      void updateUser();
      //bool findUser(QString userToFind);
      //bool deleteUser();
  private:

      std::vector <User> userList;
      std::map <QString, QString> passwordManager;
      QString userName;
      QString userPassword;
};


#endif // CONTROLLER_H
