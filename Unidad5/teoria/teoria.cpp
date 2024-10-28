//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Escribir y explicar la secuencia de cogido de recorrido de Arrays con Centinela.

    -   Se inicializa el array mediante la sentencia: 
    TipoDeDatoContenido NombreDeArray[TamañoMaximoArray], 
    opcionalmente asignandosele valores iniciales igualandolo al conjunto de datos en la forma: 
    NombreDeArray[TamañoMaximoArray] = {dato1, dato2, dato3...}.
    Posteriormente para recorrerlo se aplica un bucle while con una variable externa como incrementador, 
    usandose la variable de incremento como indice del array:
    int centinela = -1;
    int i = 0;
    while(NombreDeArray[i] != centinela)
    {
        i++;
    }
    Comprobandose que ese espacio del array no posea el valor del centinela. De no ser así, el ciclo se repite pero incrementando el index en 1, 
    hasta que se llega al espacio que posea el valor del centinela. Una vez alcanzado el valor del centinela el bucle concluye, 
    y se habra recorrido el array en su totalidad.
    )";

    string punto2=R"( 
    2. Escribir y explicar la secuencia de cogido de Búsqueda un Arrays.

    -   Para buscar un valor especifico en un array inicialmente se especificará tanto el array, como el tamaño del array (si es que no se usa centinela), 
    el valor a ser buscado, una variable para la posición inicializada en 0, 
    y una variable bandera para comprobar si el item fue encontrado que será inicializada en false. 
    Se iterará en un bucle while comprobando que la posición sea inferior al tamaño maximo del array,
    y a su vez que el valor de "encontrado" sea false (estas serán las condiciones del bucle). 
    Dentro del bucle se tendrá un condicional comprobando que el valor buscado esté contenido en la posición actual del array, 
    y de ser así e ingresar se cambiará el valor de "encontrado" a true, de lo contrario se incrementará la variable incrementadora en 1.
    Fuera del bucle normalmente se tendrá otro condicional, en caso de que encontrado sea true, indicando que el valor se ha encontrado, 
    o que esto no haya pasado y su valor no haya cambiado de false.
    )";

    string punto3=R"( 
    3. Que entiende por Arrays Multidimensionales?

    - Una matriz multidimensional es una estructura de datos que consiste en varios vectores contenidos dentro de otros vectores, o lo que es lo mismo,
    equivale a un array que en sus posiciones, en lugar de valores unitarios, contiene a otros arrays. 
    Así, una matriz no es simplemente una lista de elementos en una sola dimensión, 
    sino que se organiza en múltiples dimensiones, que pueden entenderse de forma más organizada como filas y columnas. 
    En c++ se expresa de la forma:
    tipoDeDatos NombreDeArray[max1][max2]...
    )";

    string punto4=R"( 
    4. Dar un ejemplo de Arrays multimensional en Código (definición e inicializacion)

    const int students = 3;
    const int exams = 3;
    typedef int courseGrades[students][exams];

    courseGrades courseGradesList = 
    {
        {7, 10, 9}, 
        {8, 7, 9}, 
        {7, 7, 8}
    };
    
    Asi cada indice del array contenedor, o cada "fila", representa a un alumno (3 alumnos en este caso), 
    y cada valor del array contenido en la posición, o cada "columna", representa al conjunto de sus notas. (3 examenes)
    )";

    string punto5=R"( 
    5. Como se recorre un Arrays multimensonal, dar un ejemplo de Código.

    - Para recorrer un array multidimensional deben usarse bucles anidados, 
    donde el primer bucle debe iterar a traves del primer array contenedor,
    y dentro de él debe posicionarse otro iterando a traves de los elementos del siguiente array, y así sucesivamente.
    Retomando el ejemplo anterior:

    for (size_t i = 0; i < students; i++)
    {
        cout << "el alumno " << ( i + 1 ) << ", tiene las siguientes notas:" << endl;
        
        for (int j = 0; j < exams; j++)
        {
            cout << courseGradesList[i][j] << endl;
        }
    }
    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 5 --- Recorrido y busqueda de Arrays ---" << endl << endl;

    Teoria teoria;

    cout << teoria.punto1 << endl;
    cout << teoria.punto2 << endl;
    cout << teoria.punto3 << endl;
    cout << teoria.punto4 << endl;
    
    return 0;
}