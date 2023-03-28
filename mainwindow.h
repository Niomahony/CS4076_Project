#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipe_info.h"
#include <QListWidget>
#include <QFileDialog>
#include <QSpinBox>
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
    void on_actionOpen_Recipe_triggered();
    void on_actionSave_recipe_triggered();

    void updateRecipe();

    void on_actionNew_Recipe_triggered();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Recipe *r;
    QListWidget *listWidget;
    QSpinBox *spinBox;
};

#endif // MAINWINDOW_H
