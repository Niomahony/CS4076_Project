#include "recipe_info.h"
#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QString>
#include <QDebug>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QJsonObject>
#include <QByteArray>
using namespace std;


Recipe JSONReader(QString recipeName){
    QDir f = "C:\Users\omaho\OneDrive\Desktop\cs4076\recipes.json";
    QFile file(f);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File open error";
    } else {
        qDebug() << "JSONTest2 File open!";
    }

    QByteArray data = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonObject jObj = document.object();
    QJsonObject recipeObj = jObj.value(recipeName).toObject();

    QString n = recipeObj.value("name").toString();
    int c = recipeObj.value("calories").toInt();
    QString d = recipeObj.value("description").toString();
    QString m = recipeObj.value("method").toString();

    QStringList ing;
    QJsonArray ingArray = recipeObj.value("ingredients").toArray();
    for(int i = 0; i < ingArray.size(); i++){
        ing.append(ingArray[i].toString());
    }

    return Recipe(n, ing, m, d, c);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Recipe r = JSONReader("pasta");
    r.printRecipe(r);
    return app.exec();
}
