#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "JSONread.h"
#include "recipe_info.h"
#include <QVBoxLayout>
#include <QListWidget>
#include <QAbstractItemView>

Recipe *r;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize listWidget with the pointer to the UI widget
    listWidget = ui->listWidget;
    ui->listWidget->setEditTriggers(QAbstractItemView::EditKeyPressed);

    ui->spinBox->setValue(1);
    r = new Recipe();

    // Update the ingredients list
    updateRecipe();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateRecipe()
{
    QStringList itemLabels = r->getIngredients();
    QString n  = r->getName();
    QString d = r->getDescription();
    QString m = r->getMethod();
    int c = r->getCalories();
    int p = r->getPrepTime();

    ui->spinBox->setValue(1);
    ui->listWidget->clear();
    ui->lineEdit->setText(n);
    ui->methodEdit->setText(m);
    ui->descriptionEdit->setText(d);
    ui->calAmountLabel->setText(QString::number(c));

    // add new items to list widget
    for(QString ingredient : itemLabels) {
        QListWidgetItem *listItem = new QListWidgetItem(ingredient, ui->listWidget);
        listItem->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(listItem);
    }
}



void MainWindow::on_actionOpen_Recipe_triggered()
{
  //create file dialog
    QString path = QDir::currentPath()+"/Recipes";
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", path);
    delete r; // free memory of old recipe
    r = new Recipe(readJsonFile(fileName)); // set new recipe to Salad
    updateRecipe(); // update the ingredients list
}


void MainWindow::on_actionSave_recipe_triggered()
{
    //do nothing yet
}



void MainWindow::on_actionNew_Recipe_triggered()
{
    delete r; // free memory of old recipe
    r = new Recipe();
    updateRecipe(); // update the ingredients list
}


void MainWindow::on_spinBox_valueChanged(int value)
{
    static int initialValue = 1;
    if(value == initialValue+1){

    }
}

