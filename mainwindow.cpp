#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button = ui->pushButton;
    lineEdit = ui->lineEdit;
    plainTextEdit = ui->plainTextEdit;
    button->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    button->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    plainTextEdit->document()->setPlainText(lineEdit->text());
}
