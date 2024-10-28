//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Que entiende por TDA?

    - "TDA" responde a la sigla para: "Tipo de dato abstracto", lo cual significa que el tipo del dato es un dato creado a modo de representar, o modelar,
    una entidad de la realidad dentro del sistema, 
    enfocandose en brindarsele atributos y capacidades (metodos) lo mas similares dentro de lo posible a los del objeto de la realidad,
    sin enfocarse tanto en la implementacion interna de estos sino en las operaciones que permiten y su relacion con el sistema.
    Cuan fidedigno a la realidad sea nuestro tipo de dato, o cuan abstracto sea, respondera a las necesidades de nuestro sistema.

    Si se requiere que nuestra representacion responda a un mayor tipo de casos, siendo mas flexible y general, quiza se quiera de una mayor abstraccion. 
    En cambio, si lo que se quiere es que represente de forma mas especifica el comportamiento y atributos del objeto real, 
    quizá se busque una definicion mas concreta del tipo de dato.
    Cuanto gap semantico estemos dispuestos a tener en nuestro sistema 
    y cual sea el grado de isomorfismo de nuestros tipos de datos con sus contrapartes reales sera algo a evaluar en base a nuestros requerimientos.
    )";

    string punto2=R"( 
    2. Que es Gap Semantico e Isomorfismo Estructural?

    - El gap semantico es la distancia, o diferenciacion, que posee nuestro TDA, o lo que es lo mismo, 
    nuestra representacion de una entidad de la realidad dentro de nuestro sistema. 
    A mayor grado de abstracion se conseguira una mayor versatilidad para nuestro modelo, pero el gap semantico sera mayor, 
    ya que se alejara mas de su contraparte real y no respondera a detalles concretos.

    En cambio, el isomorfismo estructural se refiere a que tan fidedigna es la representacion dentro de nuestro sistema de una entidad fuera de él.
    Mientras mas especifico y detallado sea nuestro modelo, 
    representando de forma mas concreta a su contraparte real mayor sera el grado de isomorfismo estructural que poseera.
    )";

    string punto3=R"( 
    3. Que es un Puntero, dar ejemplos de uso?

    - Un puntero es un tipo de variable que no contendra un valor en especifico, sino que almacenara la direccion en memoria de otra variable.
    Asi, siempre que se intente acceder a ella, lo que habra dentro sera la direccion de memoria de la primer variable. 
    Y a traves de este puntero se podra acceder al valor que almacena la variable a la que apunta, 
    siendo capaces de modificar dicho valor a traves de este puntero. 
    El puntero siempre debe ser del mismo tipo de dato que la variable a la que apunta.

    Ejemplos de implementacion son:

    int num = 9
    -- Puntero --
    int* ptr = &num;    
    -- Puntero a constante, de modo que no podra cambiarse el valor interno de la variable original a traves de el, pero si su asignacion de memoria --
    const int* ptrAConst = &num;
    -- Puntero constante, que no podra cambiar la direccion a la que apunta --
    int* const ptrConst = &num;   

    Su utilidad radica en poder pasar referencias a otras variables, 
    permitiendo insertarlas y trabajar con ellas en diferentes scopes de funciones, 
    de modo que los cambios sobre ellas se guarden incluso al salir de dichos scopes.
    )";

    string punto4=R"( 
    4. Como usaria la memoria dinamica?

    - Para reservar un espacio de la memoria dinamica en primera instancia crearia un puntero donde almacenar la asignacion,
    ya que la referencia a dicho espacio se podra acceder solo a traves de dicha variable, 
    que contendra la direccion del espacio de memoria dinamica reservada para ese dato:

    int* num = new int(9);
    tStudent* student1 = new tStudent("Bruno", "Ortuño", "B");
    int* arr = new int[10];
  
    Asi, en estos ejemplos, se crean punteros del tipo de dato que se quiere almacenar en dicho espacio de memoria,
    se asigna el valor a la variable, o se crea la instancia del objeto a ser almacenado, dentro de la sentencia "new".
    "New" ordenara al compilador que se cree la variable, no en la memoria de la pila/stack, sino en la memoria dinamica, el Heap.

    Luego de realizarse la asignacion, y tras usar dicho dato a lo largo del ciclo de vida de nuestro programa, 
    una vez ya no necesitada se usaria la sentencia:
    
    delete num;
    delete student1;
    delete[] arr;
    
    Borrando la asignacion del espacio de memoria dinamica a ese puntero, 
    asegurandome de esa forma que ese espacio de memoria se libere para que quede a disposicion del sistema nuevamente,
    evitando asi mismo posibles filtrados de memoria/datos ("memory leaks").
    Tambien se podria asignar el valor de "nullptr" a los punteros que ya no posean una referencia almacenada, 
    para evitar tener "punteros colgantes".

    )";

    string punto5=R"( 
    5. Que es una clase y que diferencia tiene con un Objeto?

    - Se puede considerar a una clase como un "plano" o "esquema", 
    ya que sive como template al establecer un conjunto de atributos y metodos especificos, 
    que no son mas que las cualidades y funcionalidades que posee dicha clase, o lo que es lo mismo, que es y que es capaz de hacer dicha clase. 
    Ese plano que agrupa los atributos y metodos especificos que representan a esa clase,
    se utilizara luego para poder instanciar, crear versiones concretas de dicha clase, 
    que posean esos mismos tipos de atributos y funcionalidades, aunque pudiendo tomar diferentes valores particulares.

    Esas instancias de la clase de conocen como "objetos", que son la forma concreta de la clase, su implementacion. 
    La creacion del objeto se da por medio de una clase, que establece los tipos de sus atributos y las funcionalidades que puede implementar el objeto,
    pero es en esta instanciación donde el objeto puede diferenciarse de otros estableciendo diferentes valores para esos atributos y metodos, 
    pero siempre respondiendo a los tipos y limites establecidos por su clase.
    )";

    string punto6=R"( 
    6. Que es la Agregacion y que diferencia tiene con la Herencia?

    - La agregacion es la relacion en la cual una clase contenedora incorpora a otra clase componente dentro de si, como un atributo mas de ella, 
    pero donde no necesariamente estan ligadas de forma ontologica. Es decir, ambas clases existen de forma independiente,
    y si una se borrase, la otra seguiria existiendo sin problemas, por mas que una clase incorpore a otra dentro de si para dar cuenta de una cualidad propia.

    Se diferencia de la herencia en tanto la relacion de herencia establece una jerarquia entre las clases,
    de modo que la clase madre, de la que se hereda, ponga a disposicion de la clase hija, la que hereda,
    sus atributos y metodos. Estos atributos y metodos pueden ser accedidos por parte de la clase hija, 
    siempre y cuando no sean privados, y ella puede hacer uso de ellos o sobre escribirlos,
    de modo de cambiar sus valores e implementaciones para si misma dentro de su propia definicion. 
    )";

    string punto7=R"( 
    7. Que es el Polimorfismo y que Permite?

    - El comportamiento polimorfico es la capacidad de ciertas funciones o metodos de comportarse de forma diferente en base a que objeto desencadene su comportamiento.
    Esto permite que, dada una funcion en una interface comun para 3 clases diferentes, donde todas sean hijas de una misma clase madre, 
    dicha funcionalidad puede ser sobre escrita dentro de cada una de las clases, pudiendo la misma funcion, con el mismo nombre y parametros,
    comportarse de forma diferente en base a quien la llame.
    )";

    string punto8=R"( 
    8. Que es una Interface? Que diferencia tiene con la Herencia?

    - Se puede entender a una interface como un "contrato" entre la clase abstacta que solo posee metodos virtuales puros, 
    que carecen de una implementacion concreta, y las clases que la implementan. 
    Asi, una clase estara obligada a dar una implementacion concreta a todos los metodos que posee la interface,
    respondiendo asi a todas las funcionalidades que obligatoriamente debe poseer una clase que la implemente,
    y de no hacerlo dicha clase se volvera una clase de tipo abstracta, 
    no pudiendo ser instanciada a menos que de una implementacion a todos los metodos de la interface que implemento.

    Se diferencia de la herencia en tanto la clase madre, que puede ser concreta o abstracta (donde poseera al menos un metodo virtual puro),
    siempre heredara a sus clases hijas al menos un atributo o metodo con valores o implementaciones definidas. 
    En cambio una interface no poseera atributos y todos sus metodos seran virtuales puros, sin poseer ningun tipo de implementacion.
    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- Simulacion de Parcial -- 2do Parcial -- POO y Modularizacion ---" << endl << endl;

    Teoria teoria;

    cout << teoria.punto1 << endl;
    cout << teoria.punto2 << endl;
    cout << teoria.punto3 << endl;
    cout << teoria.punto4 << endl;
    cout << teoria.punto5 << endl;
    cout << teoria.punto6 << endl;
    cout << teoria.punto7 << endl;
    cout << teoria.punto8 << endl;
    
    return 0;
}