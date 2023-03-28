#ifndef JSONread_h
#define JSONread_h

#include "recipe_info.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <istream>

Recipe readJsonFile(QString rName)
{
    // Open the JSON file for reading
    qDebug() << filePath;
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open JSON file";
        return Recipe();
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
    QString name = jsonObj.value("name").toString();

    // Access values in a JSON array
    QJsonArray ingredients = jsonObj.value("ingredients").toArray();
    QStringList ing;
    for(int i = 0; i < ingredients.size(); i++){
        ing.append(ingredients[i].toString());
    }

    QString m = jsonObj.value("method").toString();
    QString d = jsonObj.value("description").toString();
    int c = jsonObj.value("calories").toInt();
    int p = jsonObj.value("preptime").toInt();
    // Close the file
    jsonFile.close();


    return Recipe(name, ing, m, d, c, p);
}


//void saveRecipe(){

//        // Open the existing JSON file for reading
//      QString filePath = QDir::currentPath() + "/recipes.json";
//        QFile file(filePath);

//        // Read the file contents into a QJsonDocument
//        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());

//        // Get the root object
//        QJsonObject root = doc.object();

//        // Add new data to the root object
//        QJsonObject newObject;
//        newObject.insert("name", "Soup");
//        QJsonArray ingredientsArray;
//        ingredientsArray.append("Chicken broth");
//        ingredientsArray.append("Vegetables");
//        ingredientsArray.append("Noodles");
//        newObject.insert("ingredients", ingredientsArray);
//        newObject.insert("method", "1. Heat the chicken broth in a pot over medium heat. \n2. Add the vegetables and cook until tender. \n3. Add the noodles and simmer for 8-10 minutes. \n4. Serve hot.");
//        newObject.insert("description", "A warm and comforting soup.");
//        newObject.insert("calories", 300);

//        root.insert("Soup", newObject);

//        // Close the file
//        file.close();

//        // Open the file for writing
//        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

//        // Write the updated data to the file in the same format
//        QJsonDocument newDoc;
//        newDoc(root);
//        QTextStream out(&file);
//        out << newDoc.toJson(QJsonDocument::Indented);

//        // Close the file
//        file.close();

//}
#endif
