#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipe_info.h"
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPizza_triggered();
    void on_actionPasta_triggered();
    void on_actionSalad_triggered();
    void updateRecipe();

private:
    Ui::MainWindow *ui;
    Recipe *r;
    QListWidget *listWidget;
};

#endif // MAINWINDOW_H
