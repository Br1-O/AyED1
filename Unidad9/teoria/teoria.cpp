//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Que entiende Programas multiarchivo y compilacion separada

    - Programas multiarchivo hacen referencia a codigo fuente repartido entre varios archivos, o modulos,
    donde cada modulo contendra sus declaraciones y subprogramas relacionados a una entidad o funcionalidad en particular.
    De esta forma se pasara de la programacion monolitica,
    donde tenemos las declaraciones de las funciones y sus implementaciones en conjuncion dentro del archivo principal donde se ejecutaran,
    a una programacion modular, donde ciertos archivos cabecera contendran las declaraciones de nuestras entidades y sus funciones relacionadas,
    otros archivos contendran las implementaciones de cada una, y luego ambas seran importadas para su uso dentro del archivo principal del programa.
    Al compilar el programa se debera compilar no solo al archivo principal, sino a todos los archivos .cpp que han sido usados, 
    dandose una compilacion separada para cada uno dentro del mismo llamado al compilador.

    )";

    string punto2=R"( 
    2. Describir el concepto de Interfaz frente a implementacion

    - La interfaz abarca las definiciones/declaraciones de datos y prototipos, todo lo que el usuario de la unidad funcional necesita saber para su uso.
    Dentro de un programa en C++ la podremos definir dentro de un archivo de cabecera .h

    En cambio la Implementacion contiene al codigo de los subprogramas que hacen el trabajo, el usuario no necesita conocerlo para que el sistema funcione.
    Se la podra guardar en archivos con la extension .cpp

    )";

    string punto3=R"( 
    3. Que utilidad tienen los modulos de biblioteca, que archivos los componen y representan cada uno?

    - Los modulos unidad de biblioteca sirven para dividir al programa de una forma organizada,
    agrupando en archivos solo a aquellas entidades o funcionalidades que esten relacionadas con un subproblema especifico.
    Esto facilitara la reutilizacion de codigo, asi como la legibilidad y uso del mismo.  
    Estos modulos contendran a grandes rasgos 2 tipos de archivos: 
    los archivos de cabecera, de tipo .h, que representaran a todas las interfaces que necesitara el usuario llamar para hacer uso de sus operaciones;
    y los archivos con las implementaciones, de tipo .cpp, que representaran a las definiciones internas de esas funcionalidades.
    De esta forma se facilita tambien el mantenimiento del codigo, 
    en tanto los cambios en la implementacion no afectaran a su uso externo por medio del llamado a las declaraciones de su interfaz.

    )";

    string punto4=R"( 
    4. Como se realiza la Compilacion de programas multiarchivo

    - En G++: se colocan los archivos de cabecera e implementación en la misma carpeta, o especificando la ubicacion relativa de uno al otro en sus.
    Luego listamos todos los .cpp usados en el programa en la orden g++:

    E:\AyEDI\Uni08>g++ -o Main.exe Main.cpp Myfunctions.cpp

    De esta forma se compilaran los codigo objeto de cada archivo .cpp, para luego enlazarse y dar como resultado el archivo ejecutable.

    )";

    string punto5=R"( 
    5. Que funcion tiene El preprocesador, dar un ejemplo

    - Antes de compilar se pone en marcha el preprocesador, 
    que interpreta las directivas y genera un unico archivo temporal con todo el codigo del modulo o programa.
    Un ejemplo de directiva es la inclusion, que son las ejecutadas por medio de la directiva #include:

    #include <iostream> (incluyendo una biblioteca nativa de C++)
    #include "students.h" (incluyendo el archivo cabecera de un modulo propio)

    O tambien la definicion:

    #define PI 3.14159 (permitiendo que el precompilador reemplace toda referencia a PI con el valor con que lo definimos)

    )";

    string punto6=R"( 
    6. Que entiende x programacion modular y en que beneficia

    - La programacion modular consiste por la separacion de nuestro programa en multiples conjuntos de archivos,
    dentro de los cuales se almacenaran por separado declaraciones e implementaciones de las entidades y funcionalidades de nuestro sistema.
    A su vez estos archivos podran agruparse en base al subproblema que resuelven, las funciones que brindan o las entidades que los relacionan.
    Esta division en unidades modulares beneficia a la organizacion del codigo, su legibilidad y a su reutilizacion.

    )";

    string punto7=R"( 
    7. Describir el Problema de las inclusiones multiples

    - El problema de las inclusiones multiples se refiere al problema donde una directiva de inclusion se encuentra repetida en un mismo archivo .cpp,
    entonces al momento de realizar la pre compilacion sucedera un error, 
    pues al incluir los archivos necesarios para la compilacion se encontraran identificadores unicos repetidos.
    Estos problemas suelen suceder cuando en un archivo .cpp se incluye un archivo cabecera que a su vez incluye otras bibliotecas y modulos,
    y si alguno de estos tambien es incluido dentro del archivo .cpp sucedera un error.

    )";

    string punto8=R"( 
    8. Que entiende x Compilacion condicional

    - La compilacion condicional en C++ se refiere al proceso en el que
    ciertas secciones de codigo se incluyen o excluyen durante la
    compilacion segun se cumplan ciertas condiciones. 
    Esto se logra mediante el uso de directivas de preprocesador, 
    que indican al compilador que partes del codigo deben ser consideradas.

    La compilacion condicional es util cuando se desea incluir o excluir secciones de codigo en función de ciertas configuraciones,
    caracteristicas o plataformas de destino, lo que permite una mayor flexibilidad y portabilidad del codigo.


    )";

    string punto9=R"( 
    9. Como nos protegemos frente a inclusiones multiples

    - Mediante la compilación condicional, utilizando guardas de compilacion: 
        #ifndef X (if not defined). 
        #define X

        ... // Módulo

        #endif

    La directiva "#ifndef" verifica si una constante o un simbolo no esta definido mediante el uso de `#define` previo en el codigo. 
    Si el símbolo no esta definido, lo define con el identificador incluido tras la directiva "#define",
    y el bloque de codigo que sigue sera incluido en el proceso de compilacion; de lo contrario, si ya fue definido, se excluye.

    De esta forma se asegura que un modulo no sea accidentalmente incluido mas de una vez dentro del mismo archivo .cpp.

    )";

    string punto10=R"( 
    10. Que entiende x Espacios de nombres

    - Un namespace, espacio de nombres, es un mecanismo que permite agrupar y organizar el codigo en unidades logicas, 
    y asi evitar conflictos de nombres entre diferentes partes de un programa.
    Un namespace actua como un contenedor para declaraciones de variables, funciones, clases y otros elementos.
    
    Al usar diferentes namespaces se evita la ambigüedad y se facilita la gestion y comprension del codigo.

    Por ejemplo:

        namespace miEspacio {
            int i;
            double d;
        }

    Podremos acceder a las variables definidas dentro del namespace miEspacio por medio del uso del operador de resolucion de ambito ::

        miEspacio::i;
        miEspacio::d;
    
    Pero podremos ahorrarnos el tener que especificar el ambito de la variable si especificamos que estaremos usando ese espacio de nombres dentro de nuestro .cpp:

    using namespace miEspacio;

    Asi podremos llamar a las variables como si estuvieran definidas directamente en nuestro archivo, sin necesidad de especificar su ambito.

    )";

    string punto11=R"( 
    11. Dar ejemplos de Espacios de Nombres y su Utilidad.

    - Ejemplos de espacios de nombres son los usados por las bibliotecas nativas de C++:

    #include <iostream> (incluimos la biblioteca iostream, que a su vez tiene el namespace std)

    using namespace std;

    std::cout << "Hola";

    De esta forma podemos hacer uso de sus variables y funciones sin necesidad de especificar su ambito cada vez:

    cout << "Hola";

    Su utilidad radica en poder organizar entidades y funcionalidades bajo un mismo ambito,
    evitando crear conflictos por identificadores unicos repetidos al realizar importaciones de un modulo a otro,
    asi como tambien facilitar la reutilizacion, legibilidad y mantenimiento del codigo, 
    al permitir subdivisiones logicas dentro de los archivos que los contienen.

    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 9 --- Programacion Modular ---" << endl << endl;

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
    
    return 0;
}