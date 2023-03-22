
#include "mainwindow.h"
#include "recipe_info.h"
#include <QApplication>
#include <array>
#include <string>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    string pizza [4] = {"Pizza", "We all know what a pizza is cmon like", "1000", "11"};
    string pizzaIng [6] =  {"cheeese", "flour", "beep", "boop", "basil", "poop"};
    string pizzaAllergy [3] = {"gluten", "dairy", "tomato"};

    Recipe myR(pizza);
    myR.print();

    Ingredient myIng(pizzaIng, pizzaAllergy);
    myIng.print(myIng.getIngredients());
    myIng.print(myIng.getAllergies());
    return a.exec();
}
