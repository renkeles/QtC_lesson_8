#include "mythread.h"
#include <windows.h>
#include <QDebug>
#include <QDirIterator>

myThread::myThread()
{

}

void myThread::run()
{
    if(path != "" && user_filename != "")
    {
        QDirIterator it(path, QStringList() << user_filename, QDir::Files, QDirIterator::Subdirectories);

            while (it.hasNext())
            {
                break;
            }
            singleton_crutch = true;
            emit send(it.next(), singleton_crutch);
    }else
    {
        singleton_crutch = true;
        result = "Введите имя файла и выберете путь!";
        emit send(result, singleton_crutch);
    }
}

void myThread::receiveGlobalVar(QString path_, QString user_filename_, bool singleton_crutch_)
{
    qDebug() << path_;
    qDebug() << user_filename_;

    this->singleton_crutch = singleton_crutch_;
    this->path = path_;
    this->user_filename = user_filename_;
}
