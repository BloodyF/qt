#ifndef COMMON_H
#define COMMON_H
#include <QTableWidgetItem>
#include <QQueue>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

#define MAX_COL_SHOW 6
#define MAX_ROW_SHOW 3

struct row {
    QQueue<QTableWidgetItem> items;
};

struct col {
    QQueue<QTableWidgetItem> items;
};

#endif // COMMON_H
