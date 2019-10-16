#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include <model.h>
#include <list>
#include <string>

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
    model mod;
    QTimer q;
    int compdur;
    void RedButtonClicked();
    void BlueButtonClicked();
    void wrongAnswer();
    void startGame();
    void playcompTurn();

};
#endif // MAINWINDOW_H
