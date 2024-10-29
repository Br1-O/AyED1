//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Explicar con un ejemplo las Direcciones de memoria (tomar un Integer para el Ejemplo)

    - Todo dato se almacena en memoria y para acceder a dicho dato se le asigna una direccion de memoria,
    que es un identificar unico en base hexagesimal para distinguir las diferentes celdas de memoria de las que dispone el sistema.
    La direccion de memoria de una variable, donde se almacenaran nuestros datos, sera aquella celda donde se iniciara la escritura de datos,
    y reservara las subsiguientes celdas hasta alcanzar el maximo permitido por el tipo de dato asignado para la variable al declararla.
    Así, por ejemplo, para una variable de tipo Integer:

    int i = 5;

    El dato (i) se accede a partir de su dirección base (Por ej: 0F03:1A38)

    Esa sera la direccion de la primera celda de memoria utilizada por el dato, 
    y el tipo del dato (int) indica cuantos bytes (4) requiere el dato:

    00000000 00000000 00000000 00000101 -> 5

    Entonces para la variable i se reservaran 4 celdas de memoria, 0F03:1A38 - /39 - /3A - /3B, que estaran contiguas, 
    y dentro de esas celdas reservadas se almacenaran los 0/1 que representaran al numero 5 en binario. 

    )";

    string punto2=R"( 
    2. Que entiende por punteros, que representan?

    - Un puntero es una variable que almacena una direccion de memoria,
    la cual a su vez almacenara un valor del mismo tipo de dato que el tipo con el que fue declarado el puntero.
    Los punteros representan referencias a otros espacios de memoria, 
    permitiendo acceder o modificar los valores almacenados desde multiples ambitos dentro de nuestra aplicacion.

    )";

    string punto3=R"( 
    3. Que utilidades tienen los Operadores Monarios "*" y "&"?

    - El operador "*" se conoce como el operador de desreferenciacion (dereferencing operator), 
    y servira para acceder al valor dentro de una direccion de memoria, 
    de modo que al colocarlo delante de un puntero podremos acceder y modificar el valor que se almacena en el espacio de memoria al que el puntero apunta.
    Mientras el operador "&", el operador de direccion, servira para declarar que lo que sigue hace referencia a un espacio de memoria,
    permitiendo usar las direcciones de memoria de variables en lugar de sus valores. 
    Este operador es el que se usara para acceder a la direccion de memoria de una variable, para luego almacenarla en un puntero.

    Estos dos operadores son clave para poder manejar la memoria, 
    ya que nos permitiran acceder y modificar direcciones de memoria especificas y los valores que estas almacenan.

    )";

    string punto4=R"( 
    4. Que direcciones validas (valores) tengo para los Punteros?

    - Un puntero solo debe ser utilizado si tiene una direccion valida, y eso no sucede tras ser definido, sino cuando:

        Le asignamos la direccion de otro dato (operador &)
        Le asignamos otro puntero (mismo tipo base) que ya sea valido
        Le asignamos el valor NULL (puntero nulo, no apunta a nada)

        Por ej:

        int i;

        int *q; // q no tiene aun una direccion valida

        int *p = &i; // p toma una direccion valida

        q = p; // ahora q ya tiene una direccion valida

        q = NULL; // otra direccion valida para q

    )";

    string punto5=R"( 
    5. Cual es el Problema de no inicializar un Puntero?

    - El problema de no inicializar un puntero es que por defecto se le asignara como valor una direccion de memoria aleatoria,
    y asi no sabremos a que espacio de memoria apuntara, 
    y al acceder o modificar sus datos nos encontraremos con lo que se conoce como "comportamiento indeterminado" dentro de nuestro programa,
    pues los datos almacenados pueden ser de cualquier naturaleza, y modificarlos puede producir fallos criticos dentro de nuestro sistema.

    )";

    string punto6=R"( 
    6. Por que decimos que es Un valor seguro: NULL?

    - NULL (en punteros "nullptr") es un valor seguro en tanto nos da certeza de a donde apunta ese puntero.
    Al inicializar un puntero para referenciar a un espacio de memoria nulo nos aseguramos que al manipularlo 
    no modifiquemos valores dentro de espacios de memoria desconocidos,
    ya que si intentamos acceder a su valor mientras almacena una referencia nula esto resultara en un error de ejecucion,
    pero al saber la naturaleza del error podremos manejar y depurar el codigo mucho mas facilmente que ante un comportamiento indeterminado.

    )";

    string punto7=R"( 
    7. Que entiende por Copia y comparacion de punteros

    - La copia de un puntero, donde ambos deben ser del mismo tipo de dato base, 
    se realiza por medio de la asignacion de un puntero a otro, de la siguiente forma:

    int num = 5;
    int* x = &num;
    int * y = x;

    Asi el puntero "x" almacenara la direccion de memoria de "num", y al ser "x" asignado al puntero "y", 
    "y" tambien almacenara la misma direccion de memoria. 

    -----------------------

    La comparacion de punteros consiste en comparar las direcciones de memoria a las que apuntan, sus referencias,
    de tal forma que si ambos punteros contienen la misma direccion de memoria se podra decir que son iguales, caso contrario seran distintos.
    La comparacion de punteros se puede realizar de la siguiente forma por medio de los operadores de comparacion "==" y "!=":

    if (punt1 == punt2) 
    {
        cout << "Apuntan al mismo dato" << endl;
    }
    else 
    {
        cout << "No apuntan al mismo dato" << endl;
    }

    Solo se podran realizar esta comparacion entre punteros que compartan el mismo tipo de dato base.

    )";

    string punto8=R"( 
    8. Que entendemos por Tipos puntero (piense en tipos de datos)

    - Los tipos de puntero no son mas que los diferentes punteros que podemos declarar variando solo su tipo de dato base.
    Asi podremos definir punteros de variados tipos, incluso de TDAs definidos por nosotros, por ej.:

    typedef int *tIntPtr;
    typedef char *tCharPtr;
    typedef double *tDoublePtr;

    int entero = 5;
    tIntPtr puntI = &entero;

    char caracter = 'C';
    tCharPtr puntC = &caracter;

    double real = 5.23;
    tDoublePtr puntD = &real;

    )";

    string punto9=R"( 
    9. Dar ejemplos de Punteros a estructuras

    - Los punteros pueden apuntar a cualquier tipo de dato base, incluso TDAs creados por nosotros.
    Y esos TDAs pueden ser estructuras, lo cual resultaria en algo como:

    typedef struct 
    {
    int codigo;
    string nombre;
    double sueldo;
    } tRegistro;

    typedef tRegistro* tRegistroPtr;

    tRegistro registro;
    tRegistroPtr registroPtr = &registro;

    Quedando asi la variable "registro", que almacena a una estructura, asignada a nuestro puntero "registroPtr",
    que tiene el tipo "tRegistroPtr", 
    que fue definido para ser un puntero que apunte a la direccion de memoria de una variable que almacene una estructura de tipo tRegistro.

    Para acceder a los diferentes campos dentro de una estructura por medio de su referencia en un puntero deberemos usar el operador de acceso "->", por ej:

    registroPtr->codigo;
    registroPtr->nombre;
    registroPtr->sueldo;

    )";

    string punto10=R"( 
    10. Diferencie con un ejemplo Punteros a constantes y punteros constantes

    - La diferencia entre punteros a constantes y punteros constantes es que, 
    los punteros a constantes apuntan a variables que seran definidas como constantes en el puntero,
    provocando que el valor dentro del espacio de memoria al que apunta el puntero sólo pueda ser accedido, pero no pueda ser modificada.
    En cambio, los punteros constantes definen su propia asignacion de direccion de memoria como constante,
    no pudiendo posteriormente cambiar el espacio de memoria al que apuntan. Por ej:

    int num = 5;
    int num2 = 7;

    const int* x = &num; //puntero a constante
    int* const y = &num; //puntero constante

    *x = 7; //error: al intentar cambiar el valor almacenado en la direccion de memoria dentro de "x" ocurrira un error de compilacion, 
            pues el valor esta definido como constante en la declaracion de "x"

    y = &num2; //error: al intentar cambiar la referencia almacenada por "y" ocurrira un error de compilacion, pues el puntero "y" esta definido como constante

    )";

    string punto11=R"( 
    11. Que relacion hay entre Punteros y paso de parametros (relacione referencia y valor)

    - En C++ no existe un mecanismo para el pasaje de parametros por medio de referencias, 
    por defecto todos los pasajes de parametros a funciones se realizan por valor, 
    realizando una copia interna de la variable pasada como argumento dentro del ambito de la funcion.
    Para pasar una referencia como argumento a una funcion por medio de sus parametros se debe usar un puntero,
    asi el valor almacenado dentro de la variable que se pasa por referencia podra ser modificado al modificarse dentro del ambito de la funcion.
    Por ej:

    void myFunction(int* num, int* num2);
    void myOtherFunction(int num, int num2);


    int num = 1;
    int num2 = 2;

    myFunction(&num, &num2);
    myOtherFunction(num, num2);

    En myFunction cualquier cambio que se realice sobre los valores de num y num2 dentro del ambito de la funcion
    resultara en un cambio directo sobre las variables externas num y num2.
    En cambio, cualquier cambio realizado sobre los valores de num y num2 dentro del ambito de myOtherFunction 
    no afectara en absoluto a los valores de las instancias de num y num2 fuera del ambito de la funcion.

    )";

    string punto12=R"( 
    12. Explicar la relación entre Punteros y Arrays

    - Los arrays son tipos de datos dentro de C++ que en esencia se comportan como punteros al primer elemento almacenado dentro del array, 
    asi que el pasaje de un array se realiza siempre por referencia.
    Asi, al declarar un array, lo que se hace es generar un puntero con el nombre del array al espacio de memoria del primer elemento,
    y se reservara una cantidad de memoria contigua equivalente a 
    la maxima cantidad de elementos que contendra el array multiplicada por el tamaño en bytes que ocupara el tipo de dato base de los valores del array.
    Al ser estas celdas de memoria contiguas se podra acceder a sus elementos por medio de aritmetica de punteros,
    cosa que se observa en la utilizacion del Array:

    int arr[5] = {1,2,3,4,5};

    arr[0]; //1
    *arr; //1

    arr[i] | *(arr + i) //retorna el valor almacenado dentro del espacio de memoria de su primer elemento sumado i

    arr[1] | *(arr + 1) //suma al espacio de memoria de su primer elemento una seccion, saltando al final de esos 4 bytes, accediendo al valor 2

    )";

    string punto13=R"( 
    13. Explicar el "Esquema de Memoria y datos del programa"

    - La memoria del sistema se divide en:
    Datos locales - Stack (pila) 
    Datos dinamicos - Heap (memoria dinamica/monton)
    Memoria principal - Datos globales, codigo del programa, SO.

    En los datos locales, dentro de la pila, se almacenaran las variables temporales dentro del ambito de todas las funciones que se ejecutan en nuestro programa,
    y se ira liberando a medida que las ejecuciones de las funciones terminan y las variables dejan de ser usadas, ya que posee un espacio de memoria limitado.
    Los datos se iran eliminando en forma de "last in/first out", eliminandose aquellos datos que han sido creados en ultimo lugar,
    de ahí que se conozca como "pila", pues la gestion de los datos se compara con una pila, 
    donde se apilan elementos y los ultimos en colocarse son los primeros en sacarse, respondiendo al funcionamiento de los llamados a funciones.

    Los datos dinamicos, en la memoria del monton, es donde se almacenaran datos a voluntad de quien desarrolla el programa,
    pudiendo utilizar porciones de ese espacio de memoria segun lo requiera el programa,
    y luego ir liberandola a medida que ya no se necesita, para que el sistema pueda volver a gestionarla para su correcto funcionamiento.

    En la memoria principal se almacenaran las variables globales, que estan definidas por fuera de nuestras funciones y funcion main, 
    que seran accesibles a lo largo de toda la ejecucion de nuestro programa. Ademas se almacenara nuestro codigo en general para su ejecucion, 
    y el SO que gestionara el sistema en el que nos desarrollamos.

    )";

    string punto14=R"( 
    14. Que entiende por Memoria dinamica? Que uso tiene?

    - La memoria dinamica es la memoria del Heap, del Monton, que posee una capacidad de memoria mucho mas grande que la del Stack/Pila.
    Se podra reservar espacios de esta memoria a voluntad a lo largo de la ejecucion del programa,
    pudiendo hacer uso de ella sin restricciones y los datos almacenados en esta seccion perduraran por el tiempo que se requiera.
    Su uso es el de ampliar la capacidad de almacenado de datos que poseemos, pues la memoria del Stack es limitada,  
    pero se debe ser cuidadoso, pues al gestionarla manualmente deberemos asegurarnos de liberar las porciones de memoria reservadas para nuestro programa,
    ya que de no hacerlo podriamos provocar filtrados de memoria, "memory leaks", 
    situacion en la cual espacios de memoria del Heap no son liberados para su futuro uso a lo largo de la ejecucion de nuestro programa,
    y si eso sucede multiples veces provocara una escacez de recursos en la memoria,
    lo que puede desencadenar en un incorrecto funcionamiento o incluso detener la ejecucion.
    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 10 --- Punteros 1 ---" << endl << endl;

    Teoria teoria;

    cout << teoria.punto1 << endl;
    cout << teoria.punto2 << endl;
    cout << teoria.punto3 << endl;
    cout << teoria.punto4 << endl;
    cout << teoria.punto5 << endl;
    cout << teoria.punto6 << endl;
    cout << teoria.punto7 << endl;
    cout << teoria.punto8 << endl;
    cout << teoria.punto9 << endl;
    cout << teoria.punto10 << endl;
    cout << teoria.punto11 << endl;
    cout << teoria.punto12 << endl;
    cout << teoria.punto13 << endl;
    cout << teoria.punto14 << endl;
    
    return 0;
}