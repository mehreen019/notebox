#include "remEdit.h"

remEdit::remEdit(QWidget *parent, const QString& username)
    : QDialog(parent), user(username)
{
	ui.setupUi(this);

    connect(ui.goBack, SIGNAL(clicked()), this, SLOT(on_back_clicked()));
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + user + "/reminder.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui.listWidget);
        ui.listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();
}

remEdit::~remEdit()
{}

void remEdit::on_back_clicked() {
    this->hide();
    emit toRemWindow();
}

void remEdit::on_remove_clicked()
{
    int currentRow = ui.listWidget->currentRow();
    if (currentRow >= 0)
    {
        QListWidgetItem* item = ui.listWidget->takeItem(currentRow);

        // Assuming MainWindow has a QVector<QTimer*> timers;
        if (currentRow < timers.size())
        {
            timers[currentRow]->stop();
            timers[currentRow]->deleteLater();
            timers.removeAt(currentRow);
        }

        delete item;

    }
}

QListWidget* remEdit::getListWidget() const
{
    return ui.listWidget;
}



void remEdit::on_save_clicked()
{
    // Update the file after removing the reminder
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + user + "/reminder.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QMessageBox::information(0, "Error", "Unable to open file for writing: " + file.errorString());
        //QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream out(&file);
    file.resize(0);  // Clear the file content

    // Re-populate the file with the remaining reminders
    for (int i = 0; i < ui.listWidget->count(); ++i)
    {
        out << ui.listWidget->item(i)->text() << "\n";
    }

    file.close();
}


