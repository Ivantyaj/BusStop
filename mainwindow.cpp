#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnRead_clicked()
{
    timeTable = new TimeTable(FileWorker::readData(QFileDialog::getOpenFileName(this, ("Open"))));
    ui->tableViewRaw->setModel(timeTable->getModelTransport(timeTable->getAllTransport()));
}

void MainWindow::on_btnSave_clicked()
{
    if(!timeTable){
        QMessageBox::warning(this,"Ошибка","Необходимо считать данные!");
    } else {
        QString fileName = QFileDialog::getSaveFileName(this, ("Save"));
        FileWorker::writeData(timeTable->reduceByCompany(), fileName);
    }
}

void MainWindow::on_btnReduce_clicked()
{
    if(!timeTable){
        QMessageBox::warning(this,"Ошибка","Необходимо считать данные!");
    } else {
        auto list = timeTable->reduceByCompany();
        ui->tableViewPosh->setModel(timeTable->getModelTransport(list.at(0)));
        ui->tableViewGrotty->setModel(timeTable->getModelTransport(list.at(1)));
    }
}
