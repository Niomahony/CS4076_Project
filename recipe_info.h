#ifndef RECIPE_INFO_H
#define RECIPE_INFO_H
#include <iostream>
#include <string>
#include <QString>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QCheckBox>
using namespace std;


class Recipe {
protected:
    QString name;
    QStringList ingredients;
    QString description;
    QString method;
    int calories;

public:
    Recipe(){
        name = "";
        calories = 0;
        description = "";
        method = "";
        ingredients = {""};
    }
    Recipe(QString& n, QStringList& i, QString& m, QString& d, int c){
        name = n;
        calories = c;
        description = d;
        method = m;
        ingredients = i;
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
