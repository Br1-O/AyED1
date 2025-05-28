//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Comentar la Siguiente Expresion: "El origen de la revolución informatica ocurrio dentro de una maquina. 
    Por tanto, el origen de nuestros lenguajes de programacion tiende a parecerse a esa maquina."

    - Esa oracion busca expresar que, como toda la revolucion informatica esta fundamentada por los aspectos mas basicos que comprenden a una computadora,
    como son los codigos binarios, que no son mas que una abstraccion de estados electricos dentro de los circuitos del procesador, 
    y las posibles abstracciones logicas por medio de ellos, como son los bucles y estructuras de control; 
    entonces todos los lenguajes de programacion fundamentalmente tendran estos aspectos por detras,
    y toda su evolucion siempre tendera a parecerse a esta forma estructurada,
    donde no sera mas que un conjunto de comandos y ejecuciones secuenciales,
    con un sistema ambivalente por detras.
    )";

    string punto2=R"( 
    2. Comentar la Siguiente Expresion: La programacion orientada a objetos es parte de este movimiento hacia un uso del ordenador como medio de expresion

    - Esta oracion se relaciona en oposicion a la del anterior punto, ya que los ordenadores no son tanto maquinas como herramientas de amplificacion de la mente, 
    y un medio de expresion diferente. Como resultado, las herramientas empiezan a parecerse menos a las maquinas y mas a partes de nuestra mente, 
    y tambien a otros medios de expresion, como la escritura, la pintura, la escultura, la animacion y la cinematografia.
    Nos permite plasmar, no solo el mundo tal cual es, sino como lo imaginamos. Crear nuevas cosmovisiones, con nuestras propias reglas y valoraciones.

    )";

    string punto3=R"( 
    3. Que se entiende por Clase?, dar un ejemplo?

    - Una clase se puede entender como un "plano" con el cual crearemos diferentes instancias de objetos,
    permitiendo que todos ellos, al pertenecer a esa misma clase, posean tipos de atributos y funcionalidades en comun,
    pudiendo variar los valores en particular de cada uno, pero todos respondiendo a una misma tipologia y forma.
    Asi, por ejemplo, la clase Animal podra ser madre de multiples tipos de animales, como perros, 
    y asi mismo la clase Perro podra dar lugar a una infinita multiplicidad de instancias de perros,
    perros que en particular podran tener su propia raza, nombre, edad, color de pelaje, capacidad de comer, dormir, etc. 
    pero que todos tendran en comun el ser capaces de poseer esos tipos de atributos y capacidades en comun.

    )";

    string punto4=R"( 
    4. Que se entiende por Objeto, que relacion tiene con la Clase

    - Un Objeto es la instancia particular de una Clase, relacionandose con ella en los atributos y en las funcionalidades que posee
    (ya sea solo sus tipos en general, o compartiendo tambien los valores e implementaciones de cada uno, de poseerlos)

    )";

    string punto5=R"( 
    5. Que diferencia Plantea este paradigma, respecto al Imperativo?

    - El paradigma orientado a objetos define los programas en terminos de comunidades de objetos. 
    Los objetos con caracteristicas comunes se agrupan en clases. 
    Los objetos son entidades que combinan un estado (datos) y un comportamiento (funciones o metodos). 
    Estos objetos se comunican entre ellos para realizar tareas. 
    Es en este modo de ver un programa donde este paradigma difiere del paradigma imperativo
    o estructurado, en los que los datos (el estado del programa) y los metodos (sentencias que cambian dicho estado) estan separados y sin relacion. 
    Los programas imperativos son asi un conjunto de instrucciones que le indican a la computadora como realizar una tarea,
    mientras que el paradigma orientado a objetos es una forma de entender estos metodos y datos como conjuntos con una semantica en comun,
    que a su vez poseen ciertas logicas inherentes a la cosmovision del paradigma, 
    como son la herencia, polimorfismo, encapsulacion y abstraccion. 
    De esta forma es una evolucion de los paradigmas imperativos, que permite una mayor facilidad en la reutilizacion, mantenimiento y manejo del codigo.

    )";

    string punto6=R"( 
    6. Que es la Abstraccion? Que representa? Que aporta?

    - La abstraccion es el proceso por el cual se crea un modelo que representara 
    a una entidad del espacio del problema dentro del sistema que se plantea dentro del espacio de solución.
    Por medio de esta abstraccion se dejaran de lado ciertas caracteristicas especificas de la entidad representada,
    permitiendo una mayor simplicidad en el manejo y comprension de la entidad,
    asi como facilitando su versatilidad y reutilizacion a lo largo del codigo para adaptarse en la representacion de otras entidades.
    Mientras mas atributos y funcionalidades especificos se dejen de lado,
    mas versatil y simple de manejar sera el modelo, pudiendo reutilizarse en la representacion de una mayor cantidad de entidades del espacio del problema;
    pero asi mismo sera menos acertada su representacion como modelo de una entidad especifica, 
    que poseera caracteristicas que no se veran reflejadas en un modelo mas general y amplio,
    ampliando el gap semantico entre la representacion y la entidad del espacio del problema.
    En cambio, si se conserva la mayor cantidad de atributos y funcionalidades de una entidad en particular en su modelo representacion,
    se incrementara el isomorfismo estructural entre ambas, en decrimento de la versatilidad y simplicidad aportada por un proceso de abstraccion mayor.

    )";

    string punto7=R"( 
    7. Relacionar la Abstraccion con Clases y Objetos?

    - Son justamente las clases, el tipo al que perteneceran ciertos objetos brindandoseles determinados atributos y funcionalidades, 
    las que permiten crear una abstraccion de los objetos dentro del espacio del problema.
    Asi, los objetos del espacio del problema se veran reflejados en objetos que los representaran y funcionaran como modelos de ellos
    dentro del espacio de la solucion. 
    Cuan acertada, univoca y fehaciente sea esta representacion dependera de que tan especificos sean los atributos y funcionalidades,
    de modo que a mayor cantidad y especificidad de ellos dentro de una clase, 
    mayor sera el isomorfismo estructural entre el objeto modelo y el objeto de la realidad.

    )";

    string punto8=R"( 
    8. Dar ejemplos de Lenguajes POO?, explicar las Ideas de Alan Kay.

    - Smalltalk fue uno de los precursores dentro de los lenguajes con programacion orientada a objetos,
    inspirando a lenguajes como C++, dando lugar asi al surgimiento de otros, como Java, C# o Python, 
    que irian aumentando su nivel de abstraccion y separacion del lenguaje maquina.

    Las ideas de Alan Kay, presentes en Smalltalk, que representan a estos lenguajes son:
        > Todo es un objeto: 
        Todo componente dentro del programa puede ser representando por un objeto,
        al igual que toda entidad dentro del espacio del problema. 
        Asi, se puede pensar a toda funcion como un metodo perteneciente a un objeto que recibira una peticion para realizar la accion,
        o a todo atributo como la representacion del estado particular dentro de un objeto.
        > Un programa es un grupo de objetos enviando mensajes a otros para decirles que hacer:
        Dado que todo es un objeto, el programa puede ser pensado como un conjunto de objetos, creados a partir de clases particulares,
        que tendran metodos que seran invocados para que realicen una accion sobre si mismos o sobre otros objetos,
        permitiendo asi afectar el estado interno de los atributos de otros objetos o realizar ciertas acciones sobre ellos.
        > Cada objeto tiene su propia memoria constituida por otros objetos:
        Asi mismo, como todo puede ser considerado un objeto, todo objeto puede ser pensado como la conjuncion de objetos mas pequeños,
        y mientras estos objetos componentes sean cada vez mas abstractos y complejos, 
        mayor sera la habilidad de abstraccion y complejidad del objeto resultante.
        > Cada objeto tiene un tipo:
        Todo objeto debera ser creado perteneciendo a un tipo particular, conocido como "clase". 
        Y sera esta clase la que le designara tipos de atributos base y funcionalidades posibles,
        delimitando que mensajes puede recibir o enviar a otros objetos dentro del programa.
        > Todos los objetos de un tipo particular pueden recibir los mismos mensajes:
        Ya que la clase determinara los atributos y funcionalidades base, 
        objetos que sean creados a partir de las mismas clases 
        podran hacer uso de esas funcionalidades y atributos para responder a los mismos tipos de peticiones,
        dando como resultado una respuesta particular en base al estado del objeto en cuestion,
        pero cada uno generando una misma tipologia de respuesta a partir de una determinada peticion.

    )";

    string punto9=R"( 
    9. Que entiende por Interfaz?, que funcion Cumple?

    - 

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