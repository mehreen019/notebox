#include "user.h"

User::User(QObject *parent):
    QObject(parent)
{

}
void User::setName(const char* s)
{
    strcpy(name, s);
}
void User::setId(const char* i)
{
    strcpy(id, i);
}
void User::setEmail(const char* s)
{
    strcpy(email, s);
}
void User::setUserName(const char* s)
{
    strcpy(userName, s);
}
void User::setUserPassword(const char* s)
{
    strcpy(userPassword, s);
}

const char* User::getName()
{
    return name;
}
const char* User::getId()
{
    return id;
}
const char* User::getEmail()
{
    return email;
}
const char* User::getUserName()
{
    return userName;
}
const char* User::getUserPassword()
{
    return userPassword;
}
