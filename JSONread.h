#ifndef JSONread_h
#define JSONread_h

#include "recipe_info.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QDir>

Recipe readJsonFile(QString rName)
{
    // Open the JSON file for reading
    QString filePath = QDir::currentPath() + "/recipes.json";
    qDebug() << filePath;
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open JSON file";
    }

    // Read the contents of the file into a QByteArray
    QByteArray jsonData = jsonFile.readAll();

    // Parse the JSON data
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        qWarning() << "Couldn't parse JSON file:" << jsonError.errorString();
        return Recipe();
    }

    // Get the root object of the JSON document
    QJsonObject jsonObj = jsonDoc.object();

    // Access values in the JSON object
    if (!jsonObj.contains(rName)) {
        qWarning() << "Recipe not found";
        return Recipe();
    }
    QJsonObject recipeObj = jsonObj[rName].toObject();
    QString name = recipeObj["name"].toString();

    // Access values in a JSON array
    QJsonArray ingredients = recipeObj["ingredients"].toArray();
    QStringList ing;
    for(int i = 0; i < ingredients.size(); i++){
        ing.append(ingredients[i].toString());
    }

    QString m = recipeObj["method"].toString();
    QString d = recipeObj["description"].toString();
    int c = recipeObj["calories"].toInt();

    // Close the file
    jsonFile.close();

    return Recipe(name, ing, m, d, c);
}

#endif
