#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_findPushButton_clicked()
{
    QFile file_object( ui->fileLineEdit-> text());
    QString key = ui->keyLineEdit -> text();

    if ( file_object.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText("File found");
            if (key.size() == 0)
            {
                return;
            }
            QTextStream in(&file_object);
            while (! in.atEnd())
            {
                QString line = in.readLine();

                if(not ui->matchCheckBox->isChecked() and line.contains(key,
                                                                 Qt::CaseInsensitive))
                {
                    ui->textBrowser->setText("Word found");
                    return;
                }
                else if (( ui->matchCheckBox->isChecked()) and line.contains(key))
                {
                    ui->textBrowser->setText("Word found");
                    return;
                }

            }
            ui->textBrowser->setText("Word not found");
        }
        else
        {
            ui->textBrowser->setText("File not found");
        }

}
