//includes
#include <iostream>

using namespace std;

struct Teoria
{
    string punto1= R"(         
    1. Describir el Concepto de Estructura?

    - Una estructura es una coleccion heterogenea, que puede usarse para representar un tipo de dato abstracto, 
    en el cual se pueden almacenar variables de diversos tipos,
    que estén relacionadas con el modelo que representa la estructura, de modo que queden agrupadas de forma semantica dentro de nuestro sistema.
    Esto facilita no solo la comprension del sistema y sus agrupaciones, 
    sino que tambien facilita y agiliza el acceso a los valores de las diferentes variables que representan los campos de la estructura.
    En las ultimas versiones de C++ tambien pueden incluirse funciones en ellas, 
    que podrian agruparse en su interior para representar funcionalidades posibles de la estructura.
    )";

    string punto2=R"( 
    2. Describir el concepto de Registro

    - Un Registro es una variable concreta de ese tipo de estructura, 
    que al ser creada y llenar los campos que la misma posee por defecto, al corresponder a ese TDA,
    se volverá una instancia de ese tipo de estructura. 
    Esto es particularmente util para agrupar diferentes tipos de datos complejos que esten relacionados con la estructura en un mismo espacio.
    )";

    string punto3=R"( 
    3. Como se define una estructura?

    - Una estructura, en C++, puede definirse de la siguiente forma:

    (typedef) struct 
    {
        tipoDelCampo1 nombreDelCampo1;
        tipoDelCampo2 nombreDelCampo2;
        tipoDelCampo3 nombreDelCampo3;

    } nombreEstructura;

    Para que funcione de forma mas clara como un TDA, opcionalmente podemos incluir "typedef" delante de la misma,
    así podremos ahorrarnos de usar la palabra clave "struct" al declarar una variable de ese tipo de estructura, 
    pudiendo así crearla anteponiendo sólo el nombre del tipo de estructura antes de la declaración del nombre de la variable.

    )";

    string punto4=R"( 
    4. Dar ejemplos de Estructuras o registros

    - Posibles ejemplos del uso de estructuras o registros:

    struct 
    {
        size_t id;
        string nombre;
        int curso;

    } Estudiante;

    struct Estudiante estudiante1;

    estudiante1.id = 1;
    estudiante1.nombre = "Bruno";
    estudiante1.curso = 1;

    -------------------------------------

    typedef struct 
    {
        size_t id;
        string nombre;
        int edad;
    } tPersona;

    tPersona persona1;

    persona1.id = 1;
    persona1.nombre = "Bruno";
    persona1.edad = 30;

    )";

    string punto5=R"( 
    5. Como se pueden Anidar estructuras, ejemplifique?

    - Se pueden anidar estructuras definiendo uno de los campos de una estructura como del tipo de otra estructura previamente definida.
    Asi una estructura podra contener a otra, pudiendo agrupar multiples estructuras complejas dentro de una misma facilitando, por ej.,
    la creacion de una jerarquia entre diversas estructuras que se relacionen de alguna forma.

    Por ej:

    typedef struct 
    {
        size_t id;
        string nombre;
        int DNI;
    } tProfesor;

    typedef struct
    {
        size_t id;
        size_t horasSemanales;
        tProfesor profesor;
    } tCurso;

    tCurso curso;

    curso.id = 1;
    curso.horasSemanales = 8;
    curso.profesor.id = 1;
    curso.profesor.nombre = "Jose Luis";
    curso.profesor.DNI = 1234567890;

    )";

    string punto6=R"( 
    6. Que es una lista de Longitud variable?

    - Una lista de longitud variable es un array al cual se le coloca como el numero de cantidad de elementos contenidos el nombre de una variable,
    y por medio del cambio del valor en esa variable,
    que se cambiara antes de la compilacion del programa, pues dicho valor siempre debera ser de tipo "const int",
    es que se variara la longitud de dicho array, 
    facilitando la ampliacion o reduccion del mismo, antes de la compilacion del programa, con tan solo el cambio en una variable.

    Posteriormente, para conseguir un funcionamiento dinamico de ese array se definira una variable de ese tipo de array en el interior de una estructura,
    que a su vez contendra otra variable que representará al contador de elementos.
    Cada vez que se agregue un elemento a la lista de elementos, contenida en una estructura del tipo definido, 
    la variable contador que esta contenida en la estructura sera incrementada. 
    Asi el contador reflejara la cantidad de espacios que estan en uso dentro de la lista, 
    facilitando el agregar o borrar un elemento en una posicion determinada,
    al saberse la cantidad de iteraciones a realizar, por conocerse la cantidad de elementos que la lista contiene en cada momento.

    )";

    string punto7=R"( 
    7. Como se insertan y eliminan elementos en una lista variable?

    - Insercion en una lista variable:

    //definicion del array fijo
    int maxStudents = 10;
    typedef tStudents[maxStudents] tStudentsArray;

    //agrupacion del array con el contador dentro de una misma estructura
    typedef struct
    {
        tStudentsArray students;
        int currentStudents;
    } tCourse;

    tCurso course;
    tStudent newStudent;
    int indexWhereToAdd;

    //chequeamos que la cantidad actual de estudiantes sea menor a la cantidad maxima aceptada por el array
    if(course.currentStudents < maxStudents)
    {
        //creamos un lugar en el indice deseado dentro del array
        for(int j = course.currentStudents - 1; j >= indexWhereToAdd; j--)
        {
            //copiamos el valor del ultimo elemento de la lista al siguiente indice, y al llegar al indice deseado se corta la iteracion 
            course.students[j + 1] = course.students[j];
        }

        //se agrega al nuevo estudiante en la posicion deseada, ya que su contenido original ya ha sido copiado al siguiente indice
        course.students[indexWhereToAdd] = newStudent;

        //se incrementa la variable contador en uno
        course.currentStudents++;
    }

    -------------------------------------

    - Borrado en una lista variable:

    int studentId = searchStudentId;

    //iteramos del comienzo al final de la lista
    for(int i = 0; i < course.currentStudents; i++)
    {
        //buscamos el elemento en base a la clave de ordenacion o atributo pertinente
        if(course.students[i].id == studentId)
        {
            //una vez encontrado iteramos desde el indice del elemento a borrar hasta el final de la lista
            for(int j = i; j <  course.currentStudents - 1; j++)
            {
                //copiamos el valor del siguiente elemento al actual, y asi al finalizar el elemento originalmente en i quedara borrado de la lista
                course.students[j] = course.students[j + 1];
            }

            //reducimos la variable contador para que refleje correctamente la cantidad actual de elementos en la lista
            course.currentStudents--;
        }
    }
    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 8 --- Abstraccion ---" << endl << endl;

    Teoria teoria;

    cout << teoria.punto1 << endl;
    cout << teoria.punto2 << endl;
    cout << teoria.punto3 << endl;
    cout << teoria.punto4 << endl;
    cout << teoria.punto5 << endl;
    cout << teoria.punto6 << endl;
    cout << teoria.punto7 << endl;
    
    return 0;
}