#ifndef RECIPE_INFO_H
#define RECIPE_INFO_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Recipe {
private:
    string recipeArray[4];
    string name, description, calories, ingCount; // ingredient count
public:
    Recipe(string s[]){
        for(int i = 0; i<4; i++){
            recipeArray[i] = s[i];
        }
        name = recipeArray[0];
        description = recipeArray[1];
        calories = recipeArray[2];
        ingCount = recipeArray[3];
    }

    void print(){
        for(int i = 0; i<4; i++){
            cout << recipeArray[i] << " ";
        }
    }

    ~Recipe(){
    }

    string getName(){
        return name;
    }

    string getDescription(){
        return description;
    }
    int getCals(){
        return stoi(calories);
    }
    int getNoIng(){
        return stoi(ingCount);
    }

};

class Ingredient{
private:
    string name;
    vector<string> ingredients;
    vector<string> allergies;

public:
    Ingredient(string strArr[], string strArr1[]) {
        ingredients = assignIng(strArr);
        allergies = assignAll(strArr1);
    }


    vector<string> assignIng(string strArr[]){
        for(int i = 0; i<strArr->length(); i++){
            ingredients.push_back(strArr[i]);
        }
        return ingredients;
    }

    vector<string> assignAll(string strArr1[]){
        for(int i = 0; i<strArr1->length(); i++){
            allergies.push_back(strArr1[i]);
        }
        return ingredients;
    }

    vector<string> getIngredients(){
        return ingredients;
    }

    vector<string> getAllergies(){
        return allergies;
    }

    void print(vector<string> v){
        for(const auto& eles : v){
            cout << "- " << eles << endl;
        }
    }

};

#endif // RECIPE_INFO_H
