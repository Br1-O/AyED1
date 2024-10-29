//includes
#include <iostream>

using namespace std;

struct Practica
{
    string punto1= R"(         
    1. Sin ejecutarlo, que mostraria el siguiente codigo?
        int x = 5, y = 12, z; //se declararon 3 variables de tipo int, 2 inicializadas y una solo declarada
        int *p1, *p2, *p3; //se declararon 3 punteros de tipo int
        p1 = &x; //se asigno la direccion de x al puntero p1
        p2 = &y; //se asigno la direccion de y al puntero p2
        z = *p1 * *p2; //se accedio a los valores dentro de la direccion de memoria a la que apunta cada puntero, se los multiplico (60) 
                        y se asigno el resultado a la variable z
        p3 = &z; //se asigno la direccion de memoria de la variable z al puntero p3
        (*p3)++; //se accedio al valor dentro de la direccion de memoria a la que apunta p3 y se lo incremento en uno
        p1 = p3; //se asigno la direccion de referencia contenida en p3 a p1

        cout << *p1 << " " << *p2 << " " << *p3;

    - El codigo mostrara "61 12 61".

    )";

    string punto2=R"( 
    2. Que problema hay en el siguiente codigo?
        int dato = 5;
        int *p1, p2;
        p1 = &dato;
        p2 = p1;
        cout << *p2;

    - El problema es que p2 no es un puntero, pues no se uso el operador "*" delante de su declaracion, sino que es una variable de tipo int.
    Al momento de asignar a p2 el valor contenido en *p1, que es la direccion en memoria de la variable dato, ocurrira un error de compilacion.
    Asi mismo luego se intenta desreferenciar el valor de p2, que si fuera un valor de tipo int, como su tipo base, igualmente causaria un error de compilacion.

    )";

    string punto3=R"( 
    3. Que problema hay en el siguiente codigo?
        double d = 5.4, e = 1.2, f = 0.9;
        double *p1, *p2, *p3;
        p1 = &d;
        (*p1) = (*p1) + 3;
        p2 = &e;
        (*p3) = (*p1) + (*p2);
        cout << *p1 << " " << *p2 << " " << *p3;

    - El problema con el codigo es que ninguno de los 3 punteros fue inicializado en su declaracion,
    asi que al intentar desreferenciar el puntero p3 y modificar el valor que contiene, 
    se estara accediendo al valor contenido en un espacio de memoria desconocido,
    lo cual puede generar un comportamiento indeterminado sobre nuestro programa, 
    potencialmente ocasionando un mal funcionamiento o que incluso se detenga su ejecucion.
    Para evitarlo de forma sencilla podria asignarse antes un espacio de memoria valido a p3, como es el de f,
    asi con: p3 = &f; antes de la desreferenciacion de p3, podra realizarse la asignacion sin problemas.

    )";

    string punto4=R"( 
    4. Como declararias un puntero constante p para apuntar a una constante entera? (Repasa las diapositivas 877‐878 de la presentación del tema.)

    - Lo declararia de la siguiente forma:
        int num = 5;
        const int* const numPtr = &num; //puntero constante a constante

    De esta forma el valor contenido en la direccion de memoria almacenada en el puntero numPtr no podra ser modificado a traves de su desreferenciacion,
    ni podra cambiarse la direccion de memoria almacenada en el puntero numPtr por otra.

    )";

    string punto5=R"( 
    5. Dado el siguiente tipo:
            typedef struct {
                string nombre;
                double sueldo;
                int edad;
            } tRegistro;

        Y el siguiente subprograma:

            void func(tRegistro &reg, double &irpf, int &edad) {
                const double TIPO = 0.18;
                reg.edad++;
                irpf = reg.sueldo * TIPO;
                edad = reg.edad;
            }

        Reescribe el subprograma para que implemente el paso de parametros por variable con punteros,
        en lugar de las referencias que usa ahora (modifica el prorotipo y la implementacion convenientemente).

    - Respuesta: 
        void func(tRegistro* reg, double* irpf, int* edad) {
            const double TIPO = 0.18;
            reg->edad++;
            *irpf = reg->sueldo * TIPO;
            *edad = reg->edad;
        }

    )";

};
    

int main(int argc, char const *argv[])
{
    cout << "--- PRACTICA - GUIA 10 --- Punteros 1 ---" << endl << endl;

    Practica practica;

    cout << practica.punto1 << endl;
    cout << practica.punto2 << endl;
    cout << practica.punto3 << endl;
    cout << practica.punto4 << endl;
    cout << practica.punto5 << endl;
    
    return 0;
}