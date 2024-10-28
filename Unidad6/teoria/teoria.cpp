//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Describir el concepto de Algoritmo de ordenacion por insercion

    -  En el algoritmo de ordenacion por insercion se implementa una comparación elemento a elemento,
    donde, empezando desde el segundo elemento del array, se lo compara con el elemento inmediatamente anterior a el.
    Así de forma práctica quedaría el array divido en 2 zonas, una ordenada donde todos los elementos ya han sido comparados entre si,
    asegurandose de que el anterior es menor a su elemento siguiente; y una zona desordenada, de la cual se irá seleccionando un elemento por vez,
    comparandolo con el anterior, y asi iterando por todos los elementos hasta llegar al final de la lista, 
    de modo que al finalizar todos los elementos esten ordenados.
    Este algoritmo consiste de 3 bucles anidados, el primero itera desde el segundo elemento hasta el último, asegurandose que todos los elementos son comparados.
    El segundo bucle comprabará que la posición sea igual o mayor a la actual,
    y que a su vez el elemento presente en esa posicion sea mayor al que se quiere insertar en la zona ordenada.
    Una vez encontrada la posicion del primer elemento mayor al nuevo, se iterará desde la posicion del nuevo elemento hasta la posicion del primer elemento mayor,
    copiando el contenido de su predecesor dentro de cada posicion, creando asi un espacio para el nuevo elemento al final de la seccion ordenada de la lista. 
    Una vez llegado al final de este bucle, sólo se copiara el valor del nuevo elemento a ser insertado dentro de la posicion donde estaba el primer elemento mayor.
    )";

    string punto2=R"( 
    2. Que Diferencia tiene con el Algoritmo de ordenacion por insercion con intercambios?

    -   El algoritmo de ordenación por insercion con intercambios en cambio se basa en comparar, desde el segundo elemento,
    el elemento a ordenarse con su antecesor y, de ser mayor a este, intercambiarlos, copiando el antecesor hacia la derecha
    y el elemento a ordenar a la izquierda, y luego repitiendo el proceso hasta que el antecesor deje de ser menor a el o hayamos llegado al inicio de la lista.
    )";

    string punto3=R"( 
    3. Dar pautas de Claves de ordenacion

    - Las claves de ordenacion son aquellos campos concretos que se utilizan para comparar 2 elementos y así ordenarlos.
    Las claves de ordenacion pueden ser tanto el valor que contiene un elemento como atributos especificos de un objeto (como su id, precio, nombre, etc),
    que se pueden comparar de forma directa, o sobrecargando operadores, de requerirlo.
    )";

    string punto4=R"( 
    4. Que entiende por Estabilidad de la ordenacion?

    - La estabilidad de la ordenación se refiere a si un algoritmo de ordenamiento preserva el orden relativo de los elementos iguales en una coleccion. 
    De modo que, al ordenar una lista, si dos elementos son iguales en términos de la clave de ordenacion, 
    un algoritmo de ordenamiento estable mantendra su orden original en la salida, 
    asi el elemento que aparecia primero seguira estando primero tras ser ordenado, 
    y el elemento de igual clave de ordenacion que aparecia posteriormente seguira apareciendo despues el primero. 
    Asegurar la estabilidad de ordenacion es particularmente necesario si los elementos poseen otros datos relevantes ademas de su clave de ordenacion,
    cuyos datos o interpretacion podrian verse afectados si al ordenarse se cambiase el orden original en elementos de igual clave de ordenamiento.
    )";

    string punto5=R"( 
    5. Describir la Ordenacion por seleccion directa

    - En el algoritmo de ordenacion por seleccion directa se comienza desde el principio de la lista, 
    se almacena el indice en una variable que almacenara el indice del valor "menor", y luego se itera desde el segundo elemento hasta el último,
    comparando los valores del indice actual con el valor en el indice "menor", 
    de ser más chico el valor del elemento actual su indice se almacenará en "menor", identificandose como el elemento más chico de la lista.
    Una vez concluido, si "menor" es mayor que el indice i, que es la iteracion exterior actual en la lista, 
    se intercambiaran los valores de la posicion comparada de la lista y la posicion en la que se encontro el elemento actual mas chico.
    De esta forma los elementos mas chicos quedan ordenados al inicio y ya no se comparan en siguientes iteraciones, 
    seleccionandose siempre a los elementos mas chicos de cada iteracion.
    )";

    string punto6=R"( 
    6. Como funciona el Metodo de la burbuja

    - El metodo por burbujeo consiste en establecer un primer ciclo desde el primer elemento hasta el penultimo, 
    y luego otro en el que se comience desde el ultimo elemento hasta el siguiente al elemento actual, inicialmente el segundo elemento,
    descendiendo el valor de la variable contador mientras se comparan los valores chequeando si el elemento en la ultima posicion es menor que su antecesor,
    de serlo se intercambiaran los valores en sus posiciones, y se volverá a iterar el ciclo.
    Así se comparara ese elemento con todos los de la lista, hasta que se cumpla que el antecesor no sea mayor al elemento que se esta ordenando, 
    o que se llegue al elemento con index igual al numero de iteracion actual en el primer bucle y se rompa la condicion del segundo bucle.
    )";

    string punto7=R"( 
    7. Como gestionaria Listas Listas ordenadas y estructuras?

    - Se gestionan de forma identica en lo que es la declaracion de estructuras y declaracion de interfaces y sus implementaciones, 
    con la diferenciacion solamente radicando en las funciones que se encarguen de la insercion y la busqueda.
    En esas dos funcionalidades el factor del orden deberia tener en cuenta, 
    asegurandose de que la insercion respete y mantenga el orden pre-establecido en la lista,
    y en la busqueda se use dicho orden para realizarla de una forma mucho mas eficiente.
    )";

    string punto8=R"( 
    8. Como se realiza las busquedas en listas ordenadas

    - En las listas ordenadas las busquedas se realizan sumando una tercer condicion, que es si se ha encontrado un valor superior al de la clave de ordenamiento.
    Al estar los valores en orden sabemos que, ademas de llegar al final de la lista o de hecho encontrar el valor buscado, 
    ademas otra condicion para determinar prematuramente que la busqueda debe terminar es el encontrar un valor superior al buscado. 
    Si eso pasase significa que el valor no esta en nuestra lista. Asi, la busqueda se realiza de comienzo a fin, 
    pero chequeando que ademas de no haber llegado al final de la lista o que no se ha encontrado el valor buscado entre los elementos comparados,
    tambien no se ha encontrado un valor superior al buscado.
    )";

    string punto9=R"( 
    9. Que es y como se Implementa la Busqueda binaria

    - La busqueda binaria consiste en aprovechar el hecho de que la lista esta ordenada, pudiendose aplicar solo en listas previamente ordenadas,
    y comparando el valor de la clave de ordenacion del elemento buscado con el del elemento en la mitad de la lista (con index=ini+fin/2).
    Si el valor del elemento buscado es superior, entonces se re define el inicio de la lista como la mitad + 1, 
    repitiendose la comparacion en la iteracion con esa nueva redefinicion. 
    Caso contrario, si el valor es inferior, entonces se re define el final de la lista como el de la mitad - 1.
    Asi se continuara con la iteracion, 
    re definiendo la mitad en base a si el valor del elemento buscado es superior o inferior al de la clave de los elementos en las sucesivas mitades,
    hasta que eventualmente se encuentre el elemento, o el indice de inicio termine siendo mayor o igual al valor del indice del final, 
    indicando que ya no quedan elementos para comparar y el elemento buscado no se encontraba en nuestra lista.
    Una implementacion en codigo se veria de la siguiente forma:

    const int N = 10;
    typedef int tLista[N];
    tLista lista;

    int searchedValue;
    int start=0, end=N-1, half;
    bool found = false;

    while((start <= end) && (found != true))
    {
        half= (start + end)/2;

        if(lista[half] == searchedValue){
            found = true;
        }else if(searchedValue < lista[half]){
            end= half - 1;
        }else{
            start= half + 1;
        }
    }
    )";
};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 6 --- Ordenamiento y Listas con Estructuras ---" << endl << endl;

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
    
    return 0;
}