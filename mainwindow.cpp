#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qprocess.h>
#include <qdebug.h>

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

void MainWindow::rightMessage1()
{
    QByteArray data = process->readAllStandardOutput();
    //arm1->setText(QString data);
    QString text =  QString(data);
     ui->lineEdit_2->setText(text);
    qDebug() << text << endl;
}


void MainWindow::on_pushButton_clicked()
{
    process = new QProcess();
    QStringList argsStr;
    argsStr << "localhost";
    //QString program = "./app/client localhost";
    //process.setProgram(program);
    //process.setArguments(argsStr);
    process->start("/Users/funway/Solver/app/client localhost");
    process->waitForStarted();
    qDebug() << process->state();
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(rightMessage1()));
    //qDebug() << process->readAll();
    //qDebug() << process.readAllStandardOutput();
    QString str = ui->lineEdit->text() + "\r\n";
    process->write(str.toLocal8Bit().data());
    process->waitForBytesWritten();
    //process.waitForReadyRead();
    //QString result = process->readAll();
    //qDebug() << result;
    process->waitForFinished();
}
