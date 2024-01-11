#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();

    void setTitle(std::string);
    void setDate(std::string);
    void setCategory(std::string);
    void setTopic(std::string);
    void setSubject(std::string);

public slots:
    void back();
signals:
    void sendToDash();

private:
    Ui::info *ui;
};

#endif // INFO_H
