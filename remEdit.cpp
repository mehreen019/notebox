#include "remEdit.h"

remEdit::remEdit(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

    connect(ui.goBack, SIGNAL(clicked()), this, SLOT(on_back_clicked()));

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\reminder.txt");
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
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\reminder.txt");
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream out(&file);
    file.resize(0);  // Clear the file content

    // Re-populate the file with the remaining reminders
    for (int i = 0; i < ui.listWidget->count(); ++i)
    {
        out << ui.listWidget->item(i)->text() << "\n";
    }
}


