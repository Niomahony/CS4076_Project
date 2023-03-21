#ifndef RECIPE_INFO_H
#define RECIPE_INFO_H;
#include <QFile>
#include <QTextStream>
using namespace std;

class Recipe{
protected:
    string recipeArray[4];
    string name, description;
    double calories;
    int ingCount; // ingredient count

    Recipe(string p){
        readFile(p);
        name = recipeArray[0];
        description = recipeArray[1];
        calories = stod(recipeArray[2]);
        ingCount = stoi(recipeArray[3]);
    }

    void readFile(string path)
    {
        // Open the text file
        QFile inputFile(path);
        if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return -1;

        // Read the text file and store the data in an array
        QString line;
        QStringList parts;
        int i = 0;
        QTextStream in(&inputFile);
        while (!in.atEnd() && i < recipeArray.length)
        {
            line = in.readLine();
            parts = line.split('|');

            for (int j = 0; j < parts.size(); j++)
            {
                recipeArray[i] = parts[j].toString();
                i++;
            }
        }
        // Close the text file
        inputFile.close();
    }
};

class

#endif // RECIPE_INFO_H
