
#include "allergen.h"
#include "recipe_info.h"
class allergen
{
    public:

        allergen(Recipe r, int c, int p, QString& a) :
            Recipe(n, i, m, d, c, p), allergen(a) {
        }

//        bool checkAllergy(const QString& allergen, const Recipe& recipe) {
//            QString allergenLower = allergen.toLower();
//            for (const QString& ingredient : recipe.getIngredients()) {
//                QString ingredientLower = ingredient.toLower();
//                if (ingredientLower.contains(allergenLower)) {
//                    return true;
//                }
//            }
//            return false;
//        }

        QString getAllergen() const {
            return allergen;
        }

        void setAllergen(QString& a) {
            allergen = a;
        }
    };

