//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Describir la distribucion de Memoria y que tipo de dato alberga cada una?

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

    string punto2=R"( 
    2. Que es el operador NEW, para que sirve?

    - El operador NEW es una palabra clave utilizada para reservar un espacio de memoria dentro de la memoria dinamica, el HEAP, 
    que sera del tamaño necesario para albergar al tipo de dato de la variable que se especifica al momento de utilizar este operador. 
    La unica forma de acceder a este espacio de memoria sera asignandolo a una variable puntero, 
    que nos brindara un identificador por el cual almacenar su direccion de memoria y permitirnos operar sobre ese espacio.
    Asi mismo, al estar los datos almacenados en esta variable puntero dentro de la memoria del HEAP su ambito no se limitara al de una funcion en especifico,
    estando disponible a lo largo de todo el ciclo de vida de nuestro programa de ser necesario.

    )";

    string punto3=R"( 
    3. Que utilidad tiene el operador Delete, que tipo de memoria libera?

    - El operador Delete sirve para liberar el espacio de memoria dinamica, perteneciente al HEAP, 
    cuya direccion que fue asignada a un puntero para permitirnos almacenar datos y acceder a ellos a lo largo de todo el ciclo de vida de nuestro programa,
    invariablemente del ambito de nuestras funciones.
    Asi, al usar la palabra reservada Delete seguida del nombre de la variable puntero que alberga una direccion de memoria de la memoria dinamica,
    lo que sucedera es que dicho espacio sera liberado, permitiendo al sistema operativo disponer de el para su futuro uso,
    y nuestro puntero quedara "colgante", sin asignacion alguna.
    Esta palabra clave es vital para evitar fugas de memoria, es decir, para evitar ocupar espacio de la memoria dinamica de forma innecesaria,
    ya que de no liberarla una vez que ya no la necesitemos corremos el riesgo de ocuparla en su totalidad,
    lo cual puede generar un error en la ejecucion de nuestro programa, o del mismo sistema.

    )";

    string punto4=R"( 
    4. En que lugar de la memoria se definen los Punteros int *Puntero?

    - Los punteros se definen en el stack, en la Pila, ya que son variables locales reservadas dentro del ambito de la funcion en que son definidos.

    )";

    string punto5=R"( 
    5. Que entiende por colision Pila (Stack) Monton (Heap)?

    - Dado que la Pila y el Monton crecen en direcciones opuestas,
    mientras mas subprogramas se llaman dentro de la Pila, su espacio limitado va llenandose hacia abajo;
    y mientras mas espacios de memoria dentro de la memoria dinamica son reservados para el uso de nuestros punteros,
    esta crece hacia arriba y el espacio total de nuestra memoria dinamica va siendo llenado.
    Asi, la colision de la Pila con el Monton se dara cuando nuestra pila termine desbordandose (dandose un Stack overflow),
    es decir, ocupando la totalidad del espacio de memoria asignadada para su uso.
    O cuando la memoria dinamica sea la que sea ocupada por completo, colisionando con el espacio de memoria de la Pila.
    Ambos escenarios provocaran un error de ejecucion y detendran el funcionamiento de nuestro programa.

    )";

    string punto6=R"( 
    6. Que es el desbordamiento de Pila?

    - El desbordamiento de la Pila es cuando la memoria limitada del Stack es usada por completo en el llamado de subprogramas por parte de nuestra aplicacion,
    provocando asi un error de ejecucion, el Stack overflow.

    )";

    string punto7=R"( 
    7. Describir los Errores mas comunes en asignacion de Memoria Dinamica?

    - Los errores mas comunes en la asignacion de memoria dinamica son:
        > Olvidar liberar el espacio de la memoria dinamica una vez finalizado su uso, 
        dejando memoria del Monton ocupada a lo largo de toda la ejecucion de nuestro programa
        > Intentar liberar el espacio de memoria dinamica de una variable cuyo espacio de memoria dinamica ya ha sido liberado anteriormente.
        > Perder la referencia a un espacio de memoria dinamica, 
        pues a su puntero se le ha asignado una nueva direccion de memoria y ya no hay forma posible de volver a acceder al anterior espacio asignado.
        > Intentar acceder a un dato inexistente, 
        cuando la memoria dinamica ya fue liberada e intentamos desreferenciar una variable que ya no contiene una dirección de memoria valida.

    )";

    string punto8=R"( 
    8. Que entiende por array a datos dinamicos?

    - Un array a datos dinamicos es un array que contiene punteros a datos contenidos en la memoria dinamica.

    )";

    string punto9=R"( 
    9. Que son los Array dinamicos?

    - Los array dinamicos son aquellos que son contenidos directamente en la memoria dinamica,
    y se accede a ellos a traves de su direccion en memoria, almacenada en un puntero.
    A diferencia de los arrays estaticos, de la Pila, su tamano puede ser definido directamente en tiempo de ejecucion, 
    ya sea por parte del usuario o de nuestro programa.

    )";

    string punto10=R"( 
    10. Describir las diferencias entre Arrays dinamicos vs. arrays de dinamicos

    - Los arrays dinamicos son aquellos contenidos directamente en la memoria dinamica,
    lo que permite que su tamano pueda ser definido en tiempo de ejecucion, 
    y en caso de llenarse pueden ser copiados facilmente a nuevas instancias de mayor dimension dentro de la memoria dinamica.
    En cambio los arrays de dinamicos son aquellos que contienen punteros que contienen direcciones de memoria a espacios de la memoria dinamica,
    pero tanto el array como las variables puntero que contiene son almacenados en la Pila. Por esta razon su tamano debe ser definido en el momento de su declaracion,
    siendo de naturaleza estatica, y haciendo que su manipulacion sea mas compleja que la de los arrays dinamicos.

    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 10 --- Punteros 2 ---" << endl << endl;

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
    
    return 0;
}