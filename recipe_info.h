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
using namespace std;


class Recipe {
private:
    QString name;
    QStringList ingredients;
    QString description;
    QString method;
    int calories;

public:
    Recipe(const QString& name, const QStringList& ingredients, const QString& method, const QString& description, int calories ){
        this->name = name;
        this->calories = calories;
        this->description = description;
        this->method = method;
        this->ingredients = ingredients;
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


    void printRecipe(const Recipe& recipe) {
        qDebug() << "Recipe:" << recipe.getName();
        qDebug() << "Ingredients:";
        QStringList ingredients = recipe.getIngredients();
        for (int i = 0; i < ingredients.size(); i++) {
            qDebug() << "- " << ingredients[i];
        }
        qDebug() << "Description:" << recipe.getDescription();
        qDebug() << "Method:" << recipe.getMethod();
    }
};



#endif // RECIPE_INFO_H
