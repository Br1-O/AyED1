//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Que es abstraccion en programacion?

    - La abstraccion es un proceso mental que consiste en realzar los detalles relevantes, mientras se ignoran los detalles irrelevantes.
    En el desarrollo de software, existen varios niveles de abstraccion que permiten simplificar y organizar el codigo en diferentes niveles de detalle. 
    Estos niveles de abstraccion ayudan a los programadores a gestionar la complejidad y a crear sistemas mas mantenibles y comprensibles.

    La abstraccion permite asi una simplificacion del problema, ya que la cantidad de informacion que es necesario manejar en un momento dado disminuye,
    y podemos tratar cosas diferentes como si fueran la misma.

    )";

    string punto2=R"( 
    2. Que relacion hay entre Modelo y Abstraccion?

    - El desarrollo de software involucra un mapeo de aspectos o caracteristicas de los objetos y conceptos
    presentes en el espacio del problema en representaciones abstractas en el espacio de soluciones, 
    que seran modelos que representen la realidad, 
    de manera tal que operaciones sobre estas representaciones abstractas correspondan a operaciones en la
    realidad, a partir de ahi se diseñan algoritmos que ejecutados produciran resultados, resultados estos que
    podran ser mapeados fisicamente sobre algun suceso en tiempo real en el mundo real, o que seran
    examinados y mapeados mentalmente por personas sobre resultados en la realidad.

    De esta forma un modelo no sera mas que el producto de una accion de abstraccion sobre entidades del espacio del problema,
    y mientras mayor sea la accion de abstraccion sobre la definicion de ese modelo,
    mayor sera la distancia entre la entidad concreta real y las caracteristicas del modelo,
    simplificando posibles aspectos complejos y permitiendo una mayor versatilidad y generalizacion sobre los limites de aplicacion del modelo.

    )";

    string punto3=R"( 
    3. Por que usaria un "Proceso de Abstraccion" para resolver un Problema?

    - Usaria un proceso de abstraccion, en tanto lo permita las necesidades del sistema solucion al problema, 
    para simplificar posibles aspectos complejos en las entidades del problema que no son necesarios de abarcar dentro de la solucion
    y para poder hacer que ciertos modelos puedan ser reutilizados, al hacer que sus caracteristicas sean mas generales y abarcativas, 
    y asi sean capaces de representar a otras entidades que puedan verse reflejadas en su definicion mas amplia.
    Asi mismo pueden aplicarse multiples niveles de abstraccion sobre diferentes entidades, 
    de modo de crear una jerarquizacion sobre el nivel de detalle y complejidad, en base a como lo vaya necesitando la solucion.

    )";

    string punto4=R"( 
    4. Que es la descomposicion en el proceso de Abstraccion?

    - La descomposicion en el proceso de abstraccion es el acto de dividir un problema complejo en partes mas manejables y simples, 
    facilitando asi su comprension y resolucion. 
    Esto permite identificar y enfocar aspectos especificos del problema, eliminando detalles innecesarios que podrian complejizar la solucion.

    )";

    string punto5=R"( 
    5. Asocie abstraccion con Descomposicion?

    - En primera instancia se deben identificar las entidades y relaciones que conforman el espacio del problema, descomponiendolo en elementos mas simples. 
    Luego agrupar esos elementos segun caracteristicas comunes o funcionalidades, ayudando a simplificar la complejidad del sistema.
    Finalmente se modelara cada componente descompuesto en un modelo abstracto que lo represente, 
    para luego establecer las interacciones entre dichos modelos, 
    garantizando asi la coherencia y funcionalidad del sistema del espacio de solucion para responder al problema planteado.

    )";

    string punto6=R"( 
    6. Explicar los Mecanismos de Abstraccion?

    - Los mecanismos de abstraccion son tecnicas utilizadas para simplificar la representacion de elementos en un sistema, 
    permitiendo al desarrollador centrarse en los aspectos esenciales sin preocuparse por los detalles internos de implementacion. 
    Mediante la creacion y uso de Tipos de Datos Abstractos (TDA) se puede definir y trabajar con entidades de manera general y efectiva. 
    Los mecanismos principales incluyen:

    > Encapsulacion: Es el proceso de agrupar datos y operaciones dentro de una estructura,
    y asi ocultar los detalles internos al usuario. La encapsulacion permite controlar el acceso y proteger la integridad de los datos.

    > Interfaz: Representa el conjunto de operaciones que se exponen al usuario del TDA, sin revelar la implementacion interna. 
    Esto permite ser capaz de modificar la implementacion interna sin que el uso de la misma se vea afectada, al no cambiarse la interfaz por la cual se utiliza.

    > Precondiciones y Postcondiciones: Al diseñar un TDA, se establecen las condiciones necesarias antes y despues de cada operacion. 
    Las precondiciones son los requisitos que deben cumplirse para que una operacion se ejecute correctamente, 
    mientras que las postcondiciones son los resultados que se deben cumplir despues de la operacion. 

    > Modularidad: Al dividir el codigo en modulos o componentes, como TDAs independientes, 
    la modularidad permite desarrollar, probar y mantener cada TDA de forma aislada. 
    Esto facilita la reutilizacion y permite construir sistemas mas complejos a partir de componentes independientes y cohesivos, 
    mejorando la estructura general del programa.

    > Polimorfismo: Este mecanismo permite que diferentes TDAs o clases puedan ser usados de manera intercambiable si comparten una interfaz,
    o heredan de una clase comun. 
    En el contexto de los TDAs, el polimorfismo permite que distintos tipos de datos respondan a las mismas operaciones, 
    permitiendo que el sistema sea mas flexible y extensible.

    )";

    string punto7=R"( 
    7. Explicar los Tipos de Abstraccion?

    - En el desarrollo de software, existen varios niveles de abstraccion que permiten simplificar y organizar el código en
    diferentes niveles de detalle. Algunos de ellos son:

    > Abstraccion de datos: La abstraccion de datos se refiere a la representacion de datos de manera simplificada, ocultando los detalles
    internos de su implementacion. Esto se logra a traves de la definicion de tipos de datos abstractos (TDA) y estructuras de datos que
    encapsulan los datos y las operaciones relacionadas con ellos.

    > Abstraccion de procedimientos: La abstraccion de procedimientos implica la creacion de funciones o metodos que encapsulan un conjunto
    de instrucciones relacionadas para realizar una tarea especifica. Esto permite a los programadores reutilizar y modularizar el codigo, ya que
    pueden llamar a un procedimiento en lugar de tener que repetir el mismo codigo varias veces.

    > Abstraccion de control: La abstraccion de control se refiere a la simplificacion de la logica de control en un programa. Esto se logra mediante
    el uso de estructuras de control como bucles, condicionales y funciones de manejo de eventos, que permiten controlar el flujo de ejecucion y
    tomar decisiones basadas en condiciones.

    > Abstraccion de interfaces: La abstraccion de interfaces se centra en definir interfaces claras y bien definidas para interactuar con
    componentes de software. Una interfaz proporciona un conjunto de operaciones o servicios que un componente expone a otros
    componentes, ocultando los detalles de implementacion subyacentes y permitiendo una comunicacion eficiente y desacoplada entre los
    modulos del sistema.

    > Abstraccion de dominio: Se refiere a la representacion de conceptos y entidades del dominio del
    problema en el que se esta trabajando. Permite modelar y comprender el problema en terminos de
    objetos y relaciones relevantes. Ejemplos de abstraccion de dominio son los modelos de dominio,
    diagramas de entidad-relacion, diagramas de clases, etc.

    > Abstraccion de capas: La abstraccion de capas implica la separacion del sistema en capas logicas o
    niveles de abstraccion. Cada capa se enfoca en un aspecto especifico de la funcionalidad y oculta los
    detalles internos de las capas inferiores. Esto permite la modularidad, la reutilizacion y el
    mantenimiento independiente de cada capa.

    > Abstraccion de implementacion: Se ocupa de los detalles de implementacion internos y se enfoca en
    la modularidad y el ocultamiento de la complejidad. Permite separar las responsabilidades y los
    detalles de implementacion de diferentes componentes del sistema. Ejemplos de abstraccion de
    implementacion incluyen clases abstractas, interfaces de implementacion, patrones de diseño, etc.

    )";

    string punto8=R"( 
    8. Que entiende por TDA?

    - Un tipo de dato abstracto (TDA) es un concepto en programacion que define una estructura
    de datos, y un conjunto de operaciones que pueden realizarse en esa estructura de datos.
    Proporciona una interfaz para trabajar con la estructura de datos sin revelar su
    implementacion subyacente.    

    )";

    string punto9=R"( 
    9. Que mejoras aportan los TDA?

    - El TDA es util porque permite abstraer la complejidad de la implementacion y proporciona una
    forma mas clara y facil de trabajar con estructuras de datos en programas. 
    Ademas, facilita la reutilizacion de codigo, ya que se pueden definir multiples implementaciones del mismo TDA
    sin afectar a los usuarios que interactuan con el a traves de su interfaz.

    )";

    string punto10=R"( 
    10. Explicar la Vision Externa y la Vision Interna de los TDA?

    - Podria decirse que la vision externa es el que y la vision interna es el como. 
    La vision externa responde a lo que se ve, la interfaz con la que interactuan los usuarios,
    que solo mostrara alguna clave con la que diferenciar a dicha interfaz de otras, como un nombre,
    y se especificara al usuario bajo que precondiciones podra usarse esa interfaz de forma correcta,
    asi como los posibles rangos de parametros y los resultados esperables por parte de esa interfaz.
    Es decir, el usuario solo conoce por la vision externa del TDA cuando puede usar la interfaz y que necesita para hacerlo, nada mas.

    En cambio por medio de la vision interna del TDA se conocera la implementacion del mismo,
    el como realiza las operaciones y define los distintos campos dentro de su estructura.
    Asi, quien conozca la implementacion podra saber las estructuras de datos elegidas para su constitucion, 
    las relaciones existentes entre sus diferentes campos,
    como se definieron las operaciones de sus distintas funcionalidades internas,
    y como se encapsulan los datos en su interior.

    )";

    string punto11=R"( 
    11. Que es Encapsulamiento?

    - El encapsulamiento de datos e implementaciones hace referencia a la capacidad de ocultar los valores e implementaciones dentro de las estructuras,
    de modo que no puedan ser accesibles desde el exterior de la misma de forma directa, 
    sino solo por medio metodos especificos que limiten cuanto se conoce de la conformacion interna de la estructura.
    Esto tambien favorece a la simplificacion y abstraccion del sistema, 
    al ocultarse los detalles internos y dejar solo accesible los rasgos estrictamente necesarios para su utilizacion.

    )";

    string punto12=R"( 
    12. Que entiende Por Interface?

    - Una interface es la cara visible por la cual se puede hacer uso e implementar una estructura, o alguna de sus funcionalidades.
    Esto permite ocultar y hacer inaccesible la implementacion interna, 
    al interactuarse solo con un identificar que nos dira que es lo que estamos usando,
    y hacersenos saber de antemano solamente cuando y para que nos es posible y conveniente utilizar dicha funcionalidad.
    De esta forma el uso de interfaces favorece a la simplificacion en el uso del programa y asegura la conservacion de la integridad de los datos.

    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 8 --- Abstraccion y TDA ---" << endl << endl;

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
    
    return 0;
}