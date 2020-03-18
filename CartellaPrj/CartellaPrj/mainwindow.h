#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void fillPbArray(void);
    void connectSlots(void);

private slots:
    void paintButton(void);
    void on_creditsBtn_released();
};

#endif // MAINWINDOW_H
