//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Definir y Conceptualizar "Espacio del Problema y Espacio Solucion"?

    - El espacio de los problemas, es todo aquello que presente el motivo por el cual iniciamos el desarrollo de software, 
    podriamos decir que es la especificacion para nuestro programa, o el problema que nuestro programa desea solucionar.
    Por el contrario, el espacio de soluciones, vendria a ser precisamente, nuestro software o solucion a un problema dado.

    )";

    string punto2=R"( 
    2. Identificar Espacio del Problema y Espacio Solucion dentro del TP Final?

    - El espacio del problema seria la necesidad de registrar todos los pedidos para la empresa en cuestion,
    y todos los posibles obstaculos que dicho problema puede tener de por medio, asi como todo lo que dicha necesidad abarca.
    En cambio, el espacio de la solucion seria nuestro programa, 
    que responde a esa necesidad por medio de un menu y diferentes funciones a las que se puede acceder por medio de el,
    pudiendo ingresar pedidos, borrarlos y visualizarlos grupal e individualmente a traves de la persistencia dentro de un archivo externo.

    )";

    string punto3=R"( 
    3. Explicar la siguiente imagen, de se posible con un ejemplo??

    - La imagen muestra como el espacio del problema es en primera instacia explorado para poder posteriormente
    idear posibles soluciones, modelando las entidades de la realidad, con sus atributos y funcionalidades,
    dentro del sistema de nuestro programa. 
    De esta forma se intetará hacer converger cada posible especificacion de las entidades del espacio del problema en una especificacion dentro de nuestro programa,
    intentando crear una correspondencia uno a uno entre los atributos y metodos de nuestros modelos y sus contrapartes reales.

    Posteriormente, tras las primeras ideas y prototipados, se volvera a analizar el espacio del problema,
    observando y analizando que tan bien se adapta nuestra primer aproximacion a su solucion.
    Asi, la creacion de la solucion al problema se dara mediante un proceso iterativo, 
    que consistira en ir acercandose lo mas posible al correcto modelado de la realidad, 
    tanto en los atributos y funcionalidades de sus entidades, como en las relaciones que mantienen estas.
    Todo esto siempre en pos de responder a la problematica principal.

    Un ejemplo es el TP final, donde se nos planteo el registro de clientes y pedidos. 
    Para dar una solucion a este problema se intenta modelar de la forma mas cercana posible a las entidades de clientes, productos y pedidos,
    que existen en la realidad, dentro de nuestro sistema. Asi se definieron sus atributos, sus metodos para delimitar sus posibles acciones,
    y se los organizo de forma que se agrupen de forma semanticamente correcta, y se crearon funcionalidades que reflejen sus posibles relaciones.
    Todo esto en pos de aumentar el isomorfismo estructural que existe entre nuestros modelos y las entidades del espacio del problema.

    )";

    string punto4=R"( 
    4. Explicar la siguiente cita de Grady Booch?
    
    " Si examinamos los lenguajes naturales, verificamos que todos tienen dos componentes
    primarios, verbos y sustantivos, deberia existir una estructura similar o paralela en los
    lenguajes simbolicos que provea construcciones para implementar objetos y operaciones.
    Todavia la mayoria de los lenguajes son primariamente imperativos, ellos proveen de un rico
    conjunto de construccion que soportan implementar opiniones, mas en general son
    significativamente pobres o deficientes en cuanto a la abstracción de objetos de la realidad."

    - En esa cita Grady Booch habla principalmente de la programacion orientada a objetos, 
    comparando los atributos y metodos de objetos con los sustantivos y verbos del lenguaje natural.
    Asi sostiene que deberian existir las mismas herramientas para crear programas como las existen para crear oraciones,
    en tanto es el lenguaje el primer sistema por el cual el ser humano modela la realidad,
    conectando significantes a significados, o lo que es lo mismo objetos a sus atributos, capacidades y funcionalidades.
    Entonces es mediante un enfoque hacia el modelado de objetos que entiende que se puede llegar a una mayor capacidad de modelado de la realidad,
    reduciendo lo mas posible el gap semantico y maximizando un isomorfismo estructural 
    entre la realidad que se busca modelar y los sistemas que se crean para hacerlo.

    )";

    string punto5=R"( 
    5. Que entiende por Gap Semantico?

    - El gap semantico es la distancia que existe entre el modelo creado en un sistema y su contraparte en la realidad,
    de modo que mientras mas abstracta sea la representacion dentro de nuestro sistema,
    y exista una menor especificidad y correspondencia uno a uno entre los atributos y metodos de uno con el otro,
    mayor sera dicho gap semantico.
    En otras palabras, esta distancia reflejara que tan bien describe nuestro modelo los atributos, funcionalidades y relaciones 
    de aquella entidad que busca representar.

    )";

    string punto6=R"( 
    6. Que es el Isomorfismo Estructural?

    - El isomorfismo estructural representa que tan correcta es la representacion de nuestro modelo con su contraparte real,
    siendo inversa al concepto de gap semantico. 
    Para que exista dicho isomorfismo estructural debera existir una relacion uno a uno entre los atributos y funcionalidades de nuestro modelo
    y la entidad real que representa, de esta forma seran ontologicamente equivalentes, 
    y la representacion dentro de nuestro sistema sera acorde a la que existe fuera de el.

    )";

    string punto7=R"( 
    7. Comparar los espacio del Problema, el espacio de la Solucion con el Isomorfismo Estructural?

    - Por lo dicho anteriormente en esta guia queda claro que mientras mejor se exploren las especifidades que existan en el espacio del problema,
    recabando correctamente los atributos, funcionalidades y relaciones que existen entre las entidades que habiten dicho espacio en la realidad,
    mejor se podran luego representar dentro de nuestro sistema, permitiendonos responder al problema que se plantea de una forma acorde.
    Mientras mejor representen nuestras estructuras a las entidades del espacio del problema, 
    nuestra solucion tendra una mayor probabilidad de responder al problema planteado,
    ya que actuara sobre las relaciones, 
    funcionalidades y caracteristicas de entidades que son isomorficas con aquellas que participan de forma directa en el problema planteado.
    Asi, intentar que exista de un isomorfismo estructural, una correspondencia uno a uno, 
    entre nuestros modelos y las entidades del espacio del problema,
    normalmente aumentara las probabilidades de exito en la resolucion del problema en cuestion.

    )";

    string punto8=R"( 
    8. Que entiende por sistema Abstracto?

    - Un sistema abstracto es un conjunto de entidades, o estructuras, 
    que son descriptas con atributos, funcionalidades y relaciones determinadas,
    y que responden a un conjunto de leyes que rigen sus interacciones,
    pero que en la naturaleza puramente no tienen ningún lugar. 
    Son parte y producto del pensamiento, han sido ideadas como parte de una representacion, constituyendo asi un sistema intangible.
    Un sistema abstracto requiere operar en conjunto con un sistema concreto para
    cumplir su funcion como solucion a un problema determinado.

    )";

    string punto9=R"( 
    9. Que son los Isomorfismos en el Diseño de Software?

    - Son soluciones entre las cuales se puede ir y venir sin perdida de
    información, es decir que son intercambiables entre si, al corresponderse y existir un isomorfismo estructural entre ellas.
    Por ejemplo, se puede aplicar el metodo de extraccion seguido del metodo en línea y volver al estado inicial del sistema.
    Ser consciente de los isomorfismos de diseño de software nos permitira seleccionar la mejor alternativa para resolver un problema en particular. 
    Identificar isomorfismos de programacion tambien es importante porque nos permitira analizar formalmente la estructura del codigo, 
    al reducir muchas representaciones alternativas complejas a una representacion canonica mas simple.

    )";

    string punto10=R"( 
    10. Armar una Reflexion con todos los conceptos anteriores relacionados??

    - Es importante conocer estos conceptos, en tanto mas fidedignas sean nuestros modelos de la realidad que se refleja en el espacio del problema, 
    mejor podremos responder al problema en cuestion, 
    poblando nuestro espacio de la solucion con representaciones que posean un menor gap semantico y aseguren un isomorfismo estructural,
    asegurando de esta forma que al utilizar nuestro sistema para responder al problema no se este perdiente informacion,
    al intercambiar entre las entidades del problema y nuestras representaciones dentro de la solucion, 
    planteada por nuestro sistema abstracto de relaciones y funcionalidades.

    )";

    string punto11=R"( 
    11. Que es la Abstraccion y para que sirve?

    - La abstraccion es una forma de alejarse de la representacion concreta de algo, 
    centrandose en ciertos atributos y funcionalidades clave que ponderaremos por sobre otras que valoramos menos relevantes.
    Asi, por medio del acto de abstraccion crearemos un concepto mas generalizado de algo,
    en tanto carecera de ciertos detalles especificos y sus propiedades remanentes podran aplicarse a una mayor cantidad de casos concretos.
    En la creacion de software nos servira para crear modelos que sean mas versatiles y generales,
    creando una correspondencia con una mayor cantidad de entidades concretas, 
    pero donde dicha correspondencia sera mas vaga que una con una mayor especificidad.
    Asi podria decirse que mientras mayor sea la abstraccion tambien lo seria el gap semantico entre nuestra solucion y el problema,
    y por consiguiente no tendriamos un isomorfismo estructural entre el modelo y la entidad real.

    )";

    string punto12=R"( 
    12. Que entiende por Modularidad?

    - Entiendo a la modularidad como el acto de separar algo en diferentes partes, 
    creando modulos, que no seran mas que agrupaciones de elementos en base a una relacion compartida entre ellos.
    Asi mismo cada elemento tendra dentro de si otro conjunto de elementos que se agruparan en el para responder a algo en particular.
    En el desarrollo de software esto facilita la reutilizacion de componentes, 
    en tanto sera mucho mas facil de encontrarlos al dividirlos en base a una relacion que compartan 
    (como que todos los elementos sean funciones que calculen algo),
    y tambien sera mucho mas facil de delimitar que elemento debe usarse en que situacion, 
    al agrupar dentro de cada componente solo aquello que responda a una problematica concreta.

    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 8 --- Gap Semantico ---" << endl << endl;

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