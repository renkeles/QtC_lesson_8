#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutprogram.h"
#include "buttonchange.h"
#include "language.h"
#include <QTranslator>
#include <QFileSystemModel>
#include "style.h"
#include <QTextCharFormat>
#include <QDateTime>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_open_triggered();

    void on_openReadOnly_triggered();

    void on_save_triggered();

    void on_exit_triggered();

    void on_create_triggered();

    void on_aboutProgram_triggered();

    void on_buttons_triggered();

    void on_treeViewShow_triggered();

    void on_dark_triggered();

    void on_light_triggered();

    void on_russian_triggered();

    void on_english_triggered();

    void on_treeFileView_doubleClicked(const QModelIndex &index);

    void on_print_triggered();

    void on_Rand_color_triggered();

    void on_Align_center_triggered();

    void on_Align_left_triggered();

    void on_Align_right_triggered();

    void on_Font_triggered();

    void on_CopyFormat_triggered();

    void on_PasteFormat_triggered();

    void on_Enter_Date_triggered();

    void on_Enter_time_triggered();

    void on_Search_file_clicked();

    void update(QString, bool);

signals:
    void sendGlobalVar(QString, QString, bool);

private:
    Ui::MainWindow *ui;
    aboutProgram *aboutPr;
    buttonChange *btnCh;
    QTranslator qtranslator;
    QFileSystemModel *model;
    QTextCharFormat textCharFormat;
    QTextBlockFormat textBlockFormat;
    enum ReadOnlyType {readonly, read};
    QDateTime dateTime;

    int counter;

    void setDefaultLanguage();

    void setStyle(Style::StyleName stlName);
    void setLanguage(Language::CodeLanguage codeLanguage);
    void openFile(ReadOnlyType, QFile &file, QString);
    void setAlign(Qt::Alignment align);
    void initDateTime();

    bool singleton_crutch = true;
    myThread *thread;

};
#endif // MAINWINDOW_H
