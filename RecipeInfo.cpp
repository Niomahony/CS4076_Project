#include "recipe_info.h"

Recipe::Recipe() {
    name = "";
    calories = 0;
    description = "";
    method = "";
    ingredients = QStringList();
    prepTime = 0;
}

Recipe::Recipe(QString& n, QStringList& i, QString& m, QString& d, int c, int p) {
    name = n;
    calories = c;
    description = d;
    method = m;
    ingredients = i;
    prepTime = p;
}

Recipe& Recipe::operator++() {
    calories += calories;
    return *this;
}

Recipe& Recipe::operator--() {
    calories -= calories;
    return *this;
}

QString Recipe::getName() const {
    return name;
}

QStringList Recipe::getIngredients() const {
    return ingredients;
}

QString Recipe::getDescription() const {
    return description;
}

QString Recipe::getMethod() const {
    return method;
}

int Recipe::getCalories() {
    return calories;
}

int Recipe::getPrepTime() {
    return prepTime;
}
