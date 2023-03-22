
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
    string pizzaIng [11] =  {"300g strong bread flour", "1 tsp instant yeast (from a sachet or a tub)", "1 tsp salt",  "1 tbsp olive oil, plus extra for drizzling", "100ml passata", "handful fresh basil or 1 tsp dried", "handful fresh basil or 1 tsp dried", "125g ball mozzarella, sliced","handful grated or shaved parmesan (or vegetarian alternative)", "handful of cherry tomatoes, halved", "handful of basil leaves (optional)"};
    string pizzaAllergy [3] = {"gluten", "dairy", "tomato"};

//    Recipe myR(pizza);
//    myR.print();

    Ingredient myIng(pizzaIng, pizzaAllergy);
    myIng.print(myIng.getIngredients());
    myIng.print(myIng.getAllergies());
    return a.exec();
}
