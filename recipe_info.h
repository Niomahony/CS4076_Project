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
    Recipe();
    Recipe(QString& n, QStringList& i, QString& m, QString& d, int c, int p);
    Recipe& operator++();
    Recipe& operator--();
    QString getName() const;
    QStringList getIngredients() const;
    QString getDescription() const;
    QString getMethod() const;
    int getCalories();
    int getPrepTime();
};

#endif // RECIPE_INFO_H
