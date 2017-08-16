#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include<QPlainTextEdit>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *button;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;
};

#endif // MAINWINDOW_H
