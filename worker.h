#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <common.h>

#define MAX_CACHE_UP 3
#define MAX_CACHE_DOWN 3
#define MAX_CACHE_LEFT 3
#define MAX_CACHE_RIGHT 3

class Worker : public QObject{
  Q_OBJECT
public:
  Worker();
  Worker(QObject *parent);
  virtual ~Worker();
  struct row* getUpRow();
  struct row* getDownRow();

public slots:
    void updateCache();
private:
    QQueue<struct row> upCache;
    QQueue<struct row> downCache;
    QQueue<struct col> leftCache;
    QQueue<struct col> rightCache;

    void updateUpCache();
    void updateDownCache();
};

#endif // WORKER_H
