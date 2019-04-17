#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QIODevice>

#include "fileworker.h"
#include "timetable.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_btnRead_clicked();

    void on_btnSave_clicked();

    void on_btnReduce_clicked();

private:
    Ui::MainWindow *ui;
    TimeTable * timeTable;
};

#endif // MAINWINDOW_H
