#ifndef RECIPE_INFO_H
#define RECIPE_INFO_H

#include <QString>
#include <QDebug>

using namespace std;


class Recipe {
protected:
    QString name;
    QStringList ingredients;
    QString description;
    QString method;
    int calories;
    int prepTime;
public:
    Recipe(){
        name = "";
        calories = 0;
        description = "";
        method = "";
        ingredients = {""};
        prepTime = 0;
    }
    Recipe(QString& n, QStringList& i, QString& m, QString& d, int c, int p){
        name = n;
        calories = c;
        description = d;
        method = m;
        ingredients = i;
        prepTime = p;
    }

    QString getName() const {
        return name;
    }

    QStringList getIngredients() const {
        return ingredients;
    }

    QString getDescription() const {
        return description;
    }

    QString getMethod() const {
        return method;
    }

    int getCalories()  {
        return calories;
    }

    int getPrepTime(){
        return prepTime;
    }

    void printRecipe(Recipe recipe) {
        qDebug() << "Recipe:" << recipe.getName();
        qDebug() << "Ingredients:";
        QStringList ingredients = recipe.getIngredients();
        for (int i = 0; i < ingredients.size(); i++) {
            qDebug() << "- " << ingredients[i];
        }
        qDebug() << "Description:" << recipe.getDescription();
        qDebug() << "Method:" << recipe.getMethod();
        qDebug() << "Calories:" << recipe.getCalories();
    }
};

#endif // RECIPE_INFO_H
