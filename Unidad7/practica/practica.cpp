/*
1. Realizar un programa Que rellene un array con los 100 primeros números enteros y los
muestre en pantalla
2. Realizar un Programa Que rellene un array con los números primos comprendidos entre 1
y 100 y los muestre en pantalla
3. Realizar un Programa Que rellene un array con los números impares comprendidos entre 1 y
100 y los muestre en pantalla
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■(1)■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
void displayFirstNaturalNumbers();
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■(2)■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
void displayFirstPrimeNumbers(); 
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■(3)■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
void displayFirstOddNumbers(); 

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■( MAIN )■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    int option;

    cout << "Seleccione el punto a mostrar: (1), (2), (3)" << endl;

    cin >> option;

    switch (option)
    {
        case 1:
            displayFirstNaturalNumbers();
        break;
        
        case 2:
            displayFirstPrimeNumbers();
        break;

        case 3:
            displayFirstOddNumbers();
        break;
    }

    return 0;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■(1)■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

void displayFirstNaturalNumbers()
{
    const int maxNumbers = 100;
    typedef int tNaturalNumbersArray[maxNumbers];

    typedef struct{
        tNaturalNumbersArray numbersArray;
        int numbersCounter = 0;
    } tNaturalNumbersList;

    tNaturalNumbersList naturalNumbersList;

    cout << "El listado de los primeros 100 numeros enteros es: " << endl << endl;

    for (size_t i = 0; i < maxNumbers; i++)
    {
        naturalNumbersList.numbersCounter++;

        naturalNumbersList.numbersArray[i] = (naturalNumbersList.numbersCounter);

        cout << naturalNumbersList.numbersCounter << endl;
    }
};

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■(2)■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
void displayFirstPrimeNumbers()
{
    const int maxNumbers = 100;
    typedef int tPrimeNumbersArray[maxNumbers];

    typedef struct{
        tPrimeNumbersArray numbersArray;
        int numbersCounter = 0;
    } tPrimeNumbersList;

    tPrimeNumbersList primeNumbersList;

    cout << "El listado de los primeros 100 numeros primos entre 1 y 100 es: " << endl << endl;

    for (size_t i = 1; i < maxNumbers; i++)
    {
        if ((i != 1))
        {
            if (i == 2)
            {
                primeNumbersList.numbersArray[primeNumbersList.numbersCounter] = i;
                primeNumbersList.numbersCounter++;
                
                cout << i << endl;
            }else
            {
                if (i%2 != 0)
                {
                    int sqrI = sqrt(i);                  
                    bool isDivisibleBySqr = false;

                    for (size_t j = 2; j <= sqrI; j++)
                    {
                        if (i%j==0)
                        {
                            isDivisibleBySqr = true;
                        }
                    }

                    if (!isDivisibleBySqr)
                    {
                        primeNumbersList.numbersArray[primeNumbersList.numbersCounter] = i;
                        primeNumbersList.numbersCounter++;

                        cout << i << endl;
                    }
                }
            }
        }
    }
};

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■(3)■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
void displayFirstOddNumbers()
{
    const int maxNumbers = 100;
    typedef int tOddlNumbersArray[maxNumbers];

    typedef struct{
        tOddlNumbersArray numbersArray;
        int numbersCounter = 0;
    } tOddNumbersList;

    tOddNumbersList oddNumbersList;

    cout << "El listado de los primeros 100 numeros impares entre 1 y 100 es: " << endl << endl;

    for (size_t i = 0; i < maxNumbers; i++)
    {
        if (i%2 != 0)
        {
            oddNumbersList.numbersArray[oddNumbersList.numbersCounter] = i;
            oddNumbersList.numbersCounter++;
            cout << i << endl;
        }
    }
};
