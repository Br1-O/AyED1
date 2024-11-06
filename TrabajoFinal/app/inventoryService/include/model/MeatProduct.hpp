#ifndef MEATPRODUCT_HPP
#define MEATPRODUCT_HPP

    #include "../../../businessService/include/model/Article.hpp"
    #include "./Meat.hpp"

    class MeatProduct : public Article {
    private:
        Meat* typeOfMeat;                    // Pointer to a Meat object (composition)
        float relationOfPortionWithRawMaterial;

    public:
        MeatProduct(std::string name, double price, int unitsInStock, Meat* typeOfMeat, float relationOfPortionWithRawMaterial);

        // Getters
        Meat* getTypeOfMeat() const;
        float getRelationOfPortionWithRawMaterial() const;

        // Setters
        void setTypeOfMeat(Meat* meat);
        void setRelationOfPortionWithRawMaterial(float relation);
    };

#endif // MEATPRODUCT_HPP
