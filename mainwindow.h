#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qprocess.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QProcess* process;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void rightMessage1();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
