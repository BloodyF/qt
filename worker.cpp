#include "worker.h"

Worker::Worker()
{
}

Worker::Worker(QObject *parent) :
    QObject(parent)
{
}

Worker::~Worker()
{
}

void
Worker::updateUpCache() {
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    while (upCache.size() < MAX_CACHE_UP) {
        int randData;
        printf("update upCache\n");
        struct row mRow;
        QString line;
        for (int i = 0; i < MAX_COL_SHOW; i++) {
            randData =rand();
            printf("create data %d\n",randData);
            line = QString::number(randData);
            QTableWidgetItem cell;
            cell.setText(line);
            mRow.items.push_back(cell);
        }
        upCache.push_back(mRow);
    }
}
void
Worker::updateDownCache() {
//    while (this->downCache.size() < MAX_CACHE_DOWN) {
//        printf("update downCache\n");
//    }
}

void
Worker::updateCache() {
    //while (true) {
        updateUpCache();
        updateDownCache();
    //}

}
struct row* Worker::getUpRow() {
    if (upCache.empty()) {
        return NULL;
    }
    struct row* mRow = new row;
    *mRow = upCache.front();
    upCache.removeFirst();
    updateUpCache();
    //printf("size after get=%d\n",upCache.size());
    return mRow;
}

struct row* Worker::getDownRow() {
    if (downCache.empty()) {
        return NULL;
    }
    struct row* mRow = new row;
    *mRow = downCache.front();
    return mRow;
}
