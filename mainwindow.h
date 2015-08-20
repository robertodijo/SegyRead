#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "csegy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CSegy m_segy;
    VOLHEAD *m_txtheader;
    char m_asciiheader;


private slots:
    void OnImport(); //打开SEGY文件
    void OnBtnShowBinary();
    void OnBtnShowAscii();






};

#endif // MAINWINDOW_H
