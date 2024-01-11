#include "remWindow.h"

remWindow::remWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    connect(ui.toDash, SIGNAL(clicked()), this, SLOT(toDash()));
}

remWindow::~remWindow()
{}

void remWindow::toDash() {
    this->close();
    emit sendToDash();
}

void remWindow::on_reminder_add_clicked()
{
    QDateTime reminderDateTime = ui.reminder_date->dateTime();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    qint64 secondsDifference = currentDateTime.secsTo(reminderDateTime) * 1000;

    // Create a new timer and store it in the timers QVector
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &remWindow::show_message);
    if (secondsDifference < 0)
    {
        QMessageBox::warning(this, "Reminder", "Invalid Time !!!");
        return;
    }
    timer->start(qMax(secondsDifference, qint64(0))); // Ensure non-negative value
    timers.append(timer);

    QString text = ui.Reminders->text() + "- (" + reminderDateTime.toString("yyyy-MM-dd hh:mm:ss") + ")";
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\reminder.txt");
    if (!file.open(QIODevice::Append))
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream out(&file);
    out << text << "\n";

    ui.statusbar->showMessage("Reminder added!!!!", 2000);
}

void remWindow::show_message()
{
    QMessageBox::information(this, "Reminder", "It's time!");
}

void remWindow::on_Edit_button_clicked()
{
    hide();
    /*remEdit di;
    di.setModal(true);
    di.exec();*/

    re = new remEdit(this);
    re->show();
    
    connect(re, SIGNAL(toRemWindow()), this, SLOT(on_back_button_clicked()));
}

void remWindow::on_back_button_clicked()
{
    this->show();
    // Placeholder for removing reminders from the main window
    // Implement as needed based on your application's logic
}
