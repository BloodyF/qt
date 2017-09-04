#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

#include <QThread>
#include <QKeyEvent>
#include <worker.h>
#include <common.h>

#define STOP_UP 0
#define STOP_DOWN 1
#define STOP_LEFT 2
#define STOP_RIGHT 3
#define NORMAL 4

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    char scrollFlag = NORMAL;
    Worker *mWorker;
    QThread *cacheThread;
    Ui::MainWindow *ui;
    QTableWidget *mTable;

    void addUpRow(struct row* mRow);
    void addDownRow(struct row* mRow);
    void keyPressed();
    void initTable();
    void keyPressEvent(QKeyEvent* event);
};

#endif // MAINWINDOW_H
