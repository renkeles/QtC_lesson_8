#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread();

    void run();

public slots:
    void receiveGlobalVar(QString, QString, bool);

signals:
    void send(QString, bool);

private:
    QString path;
    QString user_filename;

    bool singleton_crutch;
    QString result;
};

#endif // MYTHREAD_H
