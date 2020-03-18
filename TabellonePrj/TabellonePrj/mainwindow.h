#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void fillPbArray(void);
    void connectSlots(void);

private slots:
    void paintButton(void);
    void on_creditsBtn_released();
    void on_drawBtn_released();
};
#endif // MAINWINDOW_H
