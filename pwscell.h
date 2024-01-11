#ifndef PWSCELL_H
#define PWSCELL_H

#include <QDialog>
#include "Header.h"

namespace Ui {
class pwsCell;
}

class pwsCell : public QDialog
{
    Q_OBJECT

public:
    explicit pwsCell(QWidget *parent = nullptr);
    ~pwsCell();

    int cellNum;
    int unique;
    void setTitle(std::string t);

public slots:
    void onDisplayClick();
    void onShowInfoClick();

signals:
    void sendDisplayImage(int);
    void sendInfoClick(int);

private:
    Ui::pwsCell *ui;
};

#endif // PWSCELL_H
