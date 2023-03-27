#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "JSONread.h"
#include "recipe_info.h"
#include <QVBoxLayout>
#include <QListWidget>


Recipe *r = new Recipe(readJsonFile("Pizza")); // set default recipe to Pizza

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize listWidget with the pointer to the UI widget
    listWidget = ui->listWidget;

    // Set default recipe to Pizza
    r = new Recipe(readJsonFile("Pizza"));

    // Update the ingredients list
    updateIngredientsList();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPizza_triggered()
{
    delete r; // free memory of old recipe
    r = new Recipe(readJsonFile("Pizza")); // set new recipe to Pizza
    updateIngredientsList(); // update the ingredients list
}


void MainWindow::on_actionPasta_triggered()
{
    delete r; // free memory of old recipe
    r = new Recipe(readJsonFile("Pasta")); // set new recipe to Pasta
    updateIngredientsList(); // update the ingredients list
}


void MainWindow::on_actionSalad_triggered()
{
    delete r; // free memory of old recipe
    r = new Recipe(readJsonFile("Salad")); // set new recipe to Salad
    updateIngredientsList(); // update the ingredients list
}


void MainWindow::updateIngredientsList()
{
    QStringList itemLabels = r->getIngredients();
    // clear existing items in list widget
    ui->listWidget->clear();

    // add new items to list widget
    for(QString ingredient : itemLabels) {
        QListWidgetItem *listItem = new QListWidgetItem(ingredient, ui->listWidget);
        listItem->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(listItem);
    }
}



