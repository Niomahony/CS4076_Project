
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "JSONread.h"
#include "recipe_info.h"
#include <QVBoxLayout>
#include

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Recipe *r = nullptr;
    setIngredients(r->getIngredients());
    ui->setupUi(this);
}

void setIngredients(QStringList s){
    QVBoxLayout *checkboxLayout = new QVBoxLayout(widget);

    // Loop through the list of ingredients and create a checkbox for each one
    foreach (const QString &ingredient, ingredients) {
        QCheckBox *checkbox = new QCheckBox(ingredient, widget);
        checkboxLayout->addWidget(checkbox);
    }

    // Set the layout for the widget
    widget->setLayout(checkboxLayout);
}

Recipe setRecipe(){
    if()
    r = new Recipe();
}

MainWindow::~MainWindow()
{
    delete ui;
}


