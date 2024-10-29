//includes
#include <iostream>
#include <string>
#include <vector> // Para el uso de listas

using namespace std;

struct Teoria
{
    string punto1 = R"(         
    1. Describir el Concepto de Array?

    - Un array es una estructura de datos que permite almacenar multiples elementos del mismo tipo en posiciones de memoria contiguas. 
    Cada elemento en el array se accede mediante un indice, que indica su posición dentro del array. 
    Los arrays son de tamaño fijo, es decir, una vez definidos, su tamaño no se puede cambiar.
    )";

    string punto2 = R"( 
    2. Dar un Ejemplo de:

        1. Creación de Arrays (preferentemente con typeof):

            int numeros[] = {1, 2, 3, 4, 5};
            auto otroArray = numeros;
        
        2. Asignación de Arrays:

            int numeros[5];
            numeros[0] = 10;
            numeros[1] = 20;
        
        3. Recorrido de Arrays:

            int numeros[] = {1, 2, 3, 4, 5};
            for (int i = 0; i < 5; i++) {
                cout << numeros[i] << " ";
            }

    )";

    string punto3 = R"( 
    3. Describir el Concepto de Listas (sin estructura)

    - Una lista es una colección de elementos que permite almacenar datos de manera secuencial y flexible. 
    A diferencia de los arrays, las listas pueden cambiar de tamaño dinamicamente 
    (es decir, podemos agregar o eliminar elementos sin que sea necesario definir un tamaño fijo).
    )";

    string punto3_1 = R"( 
    3.1 Dar un ejemplo de Inserción de un elemento

    -
        vector<int> lista;
        lista.push_back(10); //inserta el valor 10 al final de la lista

    )";

    string punto3_2 = R"( 
    3.2 Dar un ejemplo de Borrado de un elemento

    -
        vector<int> lista = {10, 20, 30};
        lista.pop_back(); //elimina el último elemento de la lista
    )";

    string punto4 = R"( 
    4. Describir el Tipo de Dato "String"

    - Un "String" es una secuencia de caracteres que se utiliza para representar texto. 
    En C++, el tipo de dato string es una clase que permite manipular cadenas de texto de manera sencilla y eficiente, 
    proporcionando diversas funciones integradas para operaciones comunes de texto.
    )";

    string punto4_1 = R"( 
    4.1 Dar ejemplos de 4 Funciones "Incluidas" en el Tipo "String"

    -
        > length(): Devuelve el número de caracteres en la cadena.
        > substr(pos, len): Devuelve una subcadena que comienza en "pos" y tiene "len" caracteres.
        > find(str): Busca la primera aparición de "str" y devuelve su posición.
        > replace(pos, len, str): Reemplaza parte de la cadena desde "pos" y de longitud "len" con "str".
    )";

    string punto4_2 = R"( 
    4.2 Que sentencia de Entrada usaría para leer un String con espacio x teclado?

    - Usaria la función "getline(cin, variable) para leer cadenas con espacios, de la siguiente forma:

        string nombre;
        cout << "Ingresa tu nombre completo: ";
        getline(cin, nombre);

    )";

    string punto5 = R"( 
    5. Describir la sentencia de repetición Do While

    - La sentencia `do-while` permite ejecutar un bloque de codigo al menos una vez antes de evaluar la condicion. 
    Esto es util cuando queremos que el ciclo se ejecute al menos una vez sin importar la condicion.
    )";

    string punto5_1 = R"( 
    5.1 ¿Qué diferencia tiene con la sentencia While?

    - La principal diferencia es que "while" evalua la condicion antes de ejecutar el bloque de codigo, 
    mientras que "do-while" la evalua despues, asegurando al menos una ejecucion del bloque.
    )";

    string punto5_2 = R"( 
    5.2 Dar 2 ejemplos de Uso de la Sentencia Do While

    - 
    1: 
        int numero;
        do {
            cout << "Introduce un número positivo: ";
            cin >> numero;
        } while (numero < 0);
      
    2:
        char respuesta;
        do {
            cout << "¿Desea continuar? (s/n): ";
            cin >> respuesta;
        } while (respuesta == 's' || respuesta == 'S');

    )";
};

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 4 --- Tipos de datos estructurados ---" << endl << endl;

    Teoria teoria;

    cout << teoria.punto1 << endl;
    cout << teoria.punto2 << endl;
    cout << teoria.punto3 << endl;
    cout << teoria.punto3_1 << endl;
    cout << teoria.punto3_2 << endl;
    cout << teoria.punto4 << endl;
    cout << teoria.punto4_1 << endl;
    cout << teoria.punto4_2 << endl;
    cout << teoria.punto5 << endl;
    cout << teoria.punto5_1 << endl;
    cout << teoria.punto5_2 << endl;

    return 0;
}
