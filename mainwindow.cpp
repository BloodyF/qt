#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cacheThread = new QThread;
    mWorker = new Worker;
    this->moveToThread(cacheThread);
    connect(cacheThread, SIGNAL(started()), mWorker, SLOT(updateCache()));
    cacheThread->start();

    ui->setupUi(this);
    mTable = ui->tableWidget;
    initTable();
}

void MainWindow::addUpRow(struct row* mRow) {

    int index = 0;
    mTable->insertRow(index);
    for(int j=0; j < mTable->columnCount(); j++)
    {
        QTableWidgetItem *cell = mRow->items.back().clone();
        mRow->items.removeLast();
        //delete mRow;
        //printf("got cell %s\n",cell->text().data());
        mTable->setItem(index, j, cell);
    }
    mTable->setCurrentCell(0,mTable->currentColumn());
    mTable->removeRow(MAX_ROW_SHOW);
}

void MainWindow::addDownRow(struct row* mRow){

}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    int key = event->key();
    switch (key) {
        case Qt::Key_Up:
            printf("Up pressed\n");
            struct row* mRow;
            mRow = mWorker->getUpRow();
            if (mRow) {
                addUpRow(mRow);
            }
            break;

        case Qt::Key_Down:
            printf("Down pressed\n");
            mRow = mWorker->getDownRow();
            if (mRow) {
                addDownRow(mRow);
            }
            break;
    }
}

void MainWindow::initTable() {
    mTable->setRowCount(MAX_ROW_SHOW);
    mTable->setColumnCount(MAX_COL_SHOW);
    mTable->setCurrentCell(2,1);
    mTable->verticalHeader()->setVisible(false);
    mTable->horizontalHeader()->setVisible(false);

    int data = 0;
    for(int i=0; i < mTable->rowCount(); i++)
    {
        for(int j=0; j < mTable->columnCount(); j++)
        {
            QTableWidgetItem *pCell = mTable->item(i, j);
            QString line = QString::number(++data);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                mTable->setItem(i, j, pCell);
            }
            pCell->setText(line);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    cacheThread->exit();
}
