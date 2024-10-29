#include <iostream>
#include <fstream>

using namespace std;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(1)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(a)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//product
typedef struct 
{
    unsigned int id;
    double price;
    int unitsInStock;
} tProduct;

//array of products
const int maxListedProducts= 10;
typedef tProduct tProductArray[maxListedProducts];

//List constaining array of products and elements counter
typedef struct
{
    tProductArray productArray;
    int currentListedProducts;
} tProductList;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(b)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//type for reading/writing file
typedef ifstream tReadFile;
typedef ofstream tWriteFile;
typedef string tFilePath;

//reading and loading a file
bool loadFile(tFilePath path, tProductList* productList);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(c)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//finding the most value product in stock (price*stock)
tProduct findMostValuatedProductInStock(const tProductList productList);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(d)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//delete a product from tProductList
bool deleteProductFromList(tProductList* productList, int productId);

//writing into a file
bool saveIntoFile(tFilePath path, const tProductList productList);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ MAIN ■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
int main(int argc, char const *argv[])
{
    tProductList productList;
    tFilePath path = "products.txt";

    loadFile(path, &productList);

    cout << "El producto con el valor colectivo mayor en stock es: " << (findMostValuatedProductInStock(productList)).id 
    << " con un valor de: " << ( (findMostValuatedProductInStock(productList)).price )*( (findMostValuatedProductInStock(productList)).unitsInStock ) << endl;

    int deleteFirstProduct = deleteProductFromList(&productList, 1); 
    
    if(deleteFirstProduct){
        cout << "Se ha borrado exitosamente el producto 1" << endl;
    }else{
        cout << "No se ha podido borrar el producto 1" << endl;
    }

    int saveChanges = saveIntoFile(path, productList); 

    if (saveChanges)
    {
        cout << "Se ha salvado exitosamente los cambios en la lista" <<endl;
    }
    else
    {
        cout << "No se han podido salvar los cambios en la lista" <<endl;
    }

    return 0;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(b)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
//reading a file
bool loadFile(tFilePath path, tProductList* productList){

    tReadFile file(path);

    bool completed = false;

    if (file.is_open())
    {
        int index = 0;
        size_t tempId = 0;

        file >> tempId;

        while (tempId != 999)
        {
            productList->productArray[index].id  = tempId;
                
            file >> productList->productArray[index].price 
            >> productList->productArray[index].unitsInStock;

            index++;
            productList->currentListedProducts++;

            file >> tempId;
        }

        for (size_t i = 0; i < productList->currentListedProducts; i++)
        {
            cout << "id: " << productList->productArray[i].id << endl;
            cout << "precio: " << productList->productArray[i].price << endl;
            cout << "unidades en stock: " << productList->productArray[i].unitsInStock << endl << endl;
        }

        completed = true;

        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo."<< endl;
    }

    return completed;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(c)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
//find most valuated product in stock (price * stock)
tProduct findMostValuatedProductInStock (const tProductList productList){

    tProduct mostValuatedProductInStock = {};
    double valueOfMostValuatedProductInStock = 0;

    for (size_t i = 0; i < productList.currentListedProducts; i++)
    {
        if(i == 0){
            mostValuatedProductInStock = productList.productArray[i];
            valueOfMostValuatedProductInStock = ( (productList.productArray[i]).price )*( (productList.productArray[i]).unitsInStock );
        }else{
            double valueOfCurrentProduct = ( (productList.productArray[i]).price )*( (productList.productArray[i]).unitsInStock );

            if ( valueOfMostValuatedProductInStock < valueOfCurrentProduct )
            {
                mostValuatedProductInStock = productList.productArray[i];
                valueOfMostValuatedProductInStock = ( (productList.productArray[i]).price )*( (productList.productArray[i]).unitsInStock );
            }
        }
    }

    return mostValuatedProductInStock;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(d)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//delete a product from tProductList
bool deleteProductFromList(tProductList* productList, int productId){

    bool completed = false;

    for (size_t i = 0; i < productList->currentListedProducts; i++)
    {
        if ((productList->productArray[i]).id == productId)
        {

            for (size_t j = i; j < (productList->currentListedProducts - 1); j++)
            {
                productList->productArray[j] = productList->productArray[j+1];
            }

            productList->currentListedProducts--;
            
            completed = true;
            break;
        }
    }

    return completed;
};

//writing into a file
bool saveIntoFile(tFilePath path, const tProductList productList){

    tWriteFile fileW(path);

    bool completed = false;

    if (fileW.is_open())
    {
        for (size_t i = 0; i < (productList.currentListedProducts); i++)
        {
            fileW << (productList.productArray[i]).id << " " 
                 << (productList.productArray[i]).price << " " 
                 << (productList.productArray[i]).unitsInStock << endl;
        }

        fileW << 999;

        fileW.close();
        completed = true;
    }else{
        cout << "No se pudo salvar la lista de productos al archivo." <<endl;
    }
    
    return completed;
};