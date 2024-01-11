#ifndef UPDATEBUTTON_H
#define UPDATEBUTTON_H

#include <QDialog>

namespace Ui {
class updateButton;
}

class updateButton : public QDialog
{
    Q_OBJECT

public:
    explicit updateButton(QWidget *parent = nullptr);
    ~updateButton();




private:
    Ui::updateButton* ui;
};

#endif // UPDATEBUTTON_H
