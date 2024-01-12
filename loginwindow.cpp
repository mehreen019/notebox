#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "adduserwindow.h"

#define filepath "E:/coding/projects/hopefullyfinalnotebox/user.dat"
#define bgFilePath "E:/coding/projects/hopefullyfinalnotebox/four.jpg"

AddUserWindow * newAddNewUser;

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(bgFilePath);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}
LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::on_pushButton_login_clicked()
{
    LoginWindow::readAll();
    for(int i = 0; i < n; i++)
    {
        QString userNameQString = QString::fromUtf8(userList[i]->getUserName());
        QString userPasswordQString = QString::fromUtf8(userList[i]->getUserPassword());
        passwordManager[userNameQString] = userPasswordQString;
    }
    LoginWindow::login();
}
void LoginWindow::addUser(QString userName,QString userPassword, QString name, QString id, QString email)
{
   // LoginWindow::readAll(); //read into the array userList

    /*//std::string str = userName.toStdString();
    const char* userNameChar =  userName.toStdString().c_str();

    //str = userPassword.toStdString();
    const char * userPasswordChar = userPassword.toStdString().c_str();


    //std::string str = name.toStdString();
    const char * nameChar = name.toStdString().c_str();


    //str = id.toStdString();
    const char * idChar = id.toStdString().c_str();


    //str = email.toStdString();
    const char * emailChar = email.toStdString().c_str();


    bool validUsername = false;
    validUsername = LoginWindow::findUser(userName);*/

   char *userNameChar = new char[userName.length() + 1];
   strcpy(userNameChar, userName.toStdString().c_str());
   cout << "username is : " << userNameChar << endl;

   char *userPasswordChar = new char[userPassword.length() + 1];
   strcpy(userPasswordChar, userPassword.toStdString().c_str());
   cout << "password is : " << userPasswordChar << endl;

   char *nameChar = new char[name.length() + 1];
   strcpy(nameChar, name.toStdString().c_str());
   cout << "name is : " << nameChar << endl;

   char *idChar = new char[id.length() + 1];
   strcpy(idChar, id.toStdString().c_str());
   cout << "ID is : " << idChar << endl;

   char *emailChar = new char[email.length() + 1];
   strcpy(emailChar, email.toStdString().c_str());
   cout << "email is : " << emailChar << endl;


   bool validUsername = false;
   validUsername = LoginWindow::findUser(userName);

   cout << "typed username before if : ";
   cout<< userNameChar <<endl;
    if(!validUsername)
    {
        userList[n] = new User;
        userList[n]->setUserName(userNameChar);
        userList[n]->setUserPassword(userPasswordChar);
        userList[n]->setName(nameChar);
        userList[n]->setId(idChar);
        userList[n]->setEmail(emailChar);
        n++;
        passwordManager[userName] = userPassword;
    }
}

bool LoginWindow::updateUser(QString userName, QString userPassword)
{
    LoginWindow::readAll();

    bool userFound = false;
    userFound = LoginWindow::findUser(userName);

    if(userFound)
    {

        for(int i = 0; i < n; i++)
        {
            const char* charArray = userList[i]->getUserName();
            QString temp = QString::fromUtf8(charArray);

            if(temp == userName)
            {
                userList[i]->setUserPassword(userPassword.toStdString().c_str());
                LoginWindow::writeAll();
                passwordManager[userName] = userPassword;

                QMessageBox::information(this, "Update Password", "Password Updated");
                return true;
            }
        }



        return true;
    }
    else
    {
        QMessageBox::information(this, "Update Password", "No such user exist");
        return false;
    }

}

bool LoginWindow::findUser(QString userToFind)
{
    for(int i = 0; i < n; i++)
    {
        const char* charArray = userList[i]->getUserName();
        QString temp = QString::fromUtf8(charArray);

        if(temp == userToFind)
        {
            return true;
        }
    }
    return false;
}
bool LoginWindow::deleteUser()
{
    QString userName = ui->lineEdit_userName->text();
    string unn = userName.toStdString();
    QString userPassword = ui->lineEdit_userPassword->text();

    bool userFound = false;
    userFound = LoginWindow::findUser(userName);
    if(userFound)
    {
        QString foundPassword = passwordManager[userName];
        if(foundPassword == userPassword)
        {
             LoginWindow::readAll();
             std::cout << "N is: " << n << endl;
             bool found = false;
             for(int i = 0; i < n; i++)
             {
                    if(found) break;
                    if(userList[i]->getUserName() == userName)
                    {
                        found = true;
                        for(int j = i; j < n - 1; j++)
                        {
                            userList[j] = userList[j + 1];
                        }
                        n--;
                    }
             }
             if(found)
                QMessageBox::information(this, "Delete", "Your account has been removed");
             else QMessageBox::information(this, "Delete", "Error while removing acc");

             dashboard* d = new dashboard();
             d->readFromFile();
             for (int i = 0; i < d->rownumber; i++) {
                 if (d->allNotes[i]->getUser() == unn) {
                     //allCells[i]->close();
                     cout<<d->allNotes[i]->Gettitle()<<endl;
                     for (int j = i; j < d->rownumber; j++) {
                         if (j + 1 == d->rownumber) break;

                         d->allNotes[j] = d->allNotes[j + 1];
                         //allCells[j] = allCells[j + 1];
                     }
                     d->rownumber--;
                 }
             }
             d->writeToFile();



             std::cout << "after deelete n = "<< n << std::endl;
             LoginWindow::writeAll();
             return true;
        }
        else
        {
            QMessageBox::information(this, "Login", "Wrong Password");
            return false;
        }
    }
    else
    {
        QMessageBox::information(this, "Login", "No such user exist.\nType Your Login information correctly");
        return false;
    }

}
bool LoginWindow::login()
{
    QString userName = ui->lineEdit_userName->text();
    QString userPassword = ui->lineEdit_userPassword->text();

    if(userName.isEmpty())
    {
        QMessageBox::information(this, "Warning", "Fields cannot be empty"); return false;
    }
    else if(userPassword.isEmpty())
    {
        QMessageBox::information(this, "Warning", "password cannot be empty"); return false;
    }
    else{
    bool userFound = false;
    userFound = LoginWindow::findUser(userName);

    if(userFound)
    {
        QString foundPassword = passwordManager[userName];
        if(foundPassword == userPassword)
        {
             QMessageBox::information(this, "Login", "Successful");
             hide();
             QString dashboardTitle = userName;
             dashboardTitle += "'s Dashboard\n";

//             userDashboard->dashboard_text_update(dashboardTitle);
//             userDashboard->show();

             userDashboard = new dashboard(this);
             userDashboard->setWindowTitle(dashboardTitle);
             userDashboard->user= userName.toStdString();
             userDashboard->readFromFile();
             userDashboard->addOnLoad();
             userDashboard->show();
             return true;
        }
        else
        {
            QMessageBox::information(this, "Login", "Wrong Password");
            return false;
        }
    }
    else
    {
        QMessageBox::information(this, "Login", "No such user exist");
        return false;
    }
    }
}
void LoginWindow::readAll()
{
    std::cout << "READING IN FILE = " << n << "items\n";
    std::ifstream inf;
    inf.open(filepath, std::ios::binary);
    if(!inf)
    {
        std::cout << "Cannot open file\n ";
        return;
    }
    n = 0;

    User *temp = new User;
    while(inf.read(reinterpret_cast<char*>(temp), sizeof(User)))
    {
        userList[n++] = temp;
        if(!inf)
        {
            std::cout << "cant read from file\n";
        }
        temp = new User;
    }
    inf.close();
}
void LoginWindow::writeAll()
{
    std::cout << "WRITING IN FILE = " << n << "items\n";
    std::ofstream ouf;
    ouf.open(filepath, std::ios::trunc | std::ios::binary);
    if(ouf)
    {
        for(int i = 0; i < n; i++)
        {
            ouf.write(reinterpret_cast<char*>(userList[i]), sizeof(User));
        }
    }
    else std::cout << "Cant open file\n";
    ouf.close();
}

void LoginWindow::on_pushButton_back_clicked()
{
    hide();
    newAddNewUser = new AddUserWindow;
    newAddNewUser->setWindowTitle("Sign Up");
    newAddNewUser->show();
}

void LoginWindow::on_pushButton_delete_clicked()
{
    LoginWindow::readAll();
    for(int i = 0; i < n; i++)
    {
        QString userNameQString = QString::fromUtf8(userList[i]->getUserName());
        QString userPasswordQString = QString::fromUtf8(userList[i]->getUserPassword());
        passwordManager[userNameQString] = userPasswordQString;
    }
    LoginWindow::deleteUser();

}

void LoginWindow::on_pushButton_updatePassword_clicked()
{
    LoginWindow::readAll();
    for(int i = 0; i < n; i++)
    {
        QString userNameQString = QString::fromUtf8(userList[i]->getUserName());
        QString userPasswordQString = QString::fromUtf8(userList[i]->getUserPassword());
        passwordManager[userNameQString] = userPasswordQString;
    }
    QString userName = ui->lineEdit_userName->text();
    QString userPassword = ui->lineEdit_userPassword->text();

    // updatePassword = new updatePasswordWindow(nullptr, userName.toStdString());
    // updatePassword->show();
    if(userPassword == passwordManager[userName])
    {
        updatePassword = new updatePasswordWindow(nullptr, userName.toStdString());
        updatePassword->show();
    }
    else
    {
        QMessageBox::information(this, "Login", "Wrong Password");
    }
}
