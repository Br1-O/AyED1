// includes
#include <iostream>
#include <fstream> // Para manejar archivos
#include <string>  // Para manejar cadenas de texto

using namespace std;

struct Teoria
{
    string punto1 = R"(         
    1. Por que necesitaria usar Archivos en una aplicacion?
    - Los archivos permiten almacenar datos de manera persistente. 
    A traves de archivos, podemos guardar informacion que no se pierde al cerrar la aplicacion. 
    Por ejemplo, un programa de gestión de contactos puede guardar la lista de contactos en un archivo para que estén disponibles en la próxima ejecucion.

    )";

    string punto2 = R"( 
    2. Explicar las diferencias entre archivos de texto y binarios?
    - Los archivos de texto almacenan datos en un formato legible por humanos, como caracteres ASCII o UTF-8. 
    Ejemplos incluyen .txt o .csv. En cambio, los archivos binarios almacenan datos en un formato que no es directamente legible por humanos, 
    permitiendo un uso más eficiente del espacio y la representación precisa de datos complejos, como imágenes o audio.

    )";

    string punto3 = R"( 
    3. Que entiende por "Flujos" en la lectura y Escritura?
    - Los flujos son secuencias de datos que se pueden leer o escribir. 
    En C++, se utilizan flujos para interactuar con datos que provienen de archivos o la entrada/salida estandar (teclado y pantalla). 
    Los flujos permiten leer y escribir datos de manera estructurada, utilizando operadores como "<<" y ">>".

    )";

    string punto4 = R"( 
    4. Explicar la libreria y los objetos (la secuencia) que se utilizan para leer un Archivo?
    - La librería <fstream> permite manejar archivos. 
    Los objetos más utilizados son ifstream (entrada de archivos) para leer datos de un archivo y ofstream (salida de archivos) para escribir datos en un archivo. 
    La secuencia para leer un archivo típicamente incluye:
    1. Crear objeto ifstream:
        ifstream file(path);
    2. Abrir archivo:
        file.open("nombre_archivo.txt");
    3. Leer datos del archivo:
        while (getline(file, linea)) {
            //procesar la línea
         }
    4. Cerrar archivo:
         file.close();

    )";

    string punto5 = R"( 
    5. ¿Cómo deberemos poner el camino o “Path” del archivo a leer o escribir?
    - El camino del archivo puede ser relativo (en relación a la ubicación del ejecutable) o absoluto (la ruta completa en el sistema de archivos). 
    De ser posible siempre deberian usarse ubicaciones relativas, 
    para evitar posibles conflictos de ubicacion al lanzar a produccion el programa.

    )";

    string punto6 = R"( 
    6. Explicar en un Diagrama la secuencia de comandos usados en la Escritura de Archivo
    - La secuencia de comandos usados en la escritura de un archivo:

      1. Crear objeto ofstream:
        ofstream file(path);
      2. Abrir archivo:
        file.open("nombre_archivo.txt");
      3. Escribir en el archivo:
        file << "contenido";
      4. Cerrar archivo:
        file.close();

    )";

    string punto7 = R"( 
    7. Dar Ejemplos de código "Descriptivamente Comentado" de Lectura de Archivos.
    - Ejemplo de Lectura de un Archivo:

        ifstream archivoEntrada("datos.txt"); //crea un objeto ifstream para leer desde "datos.txt"
        
        if (archivoEntrada.is_open()) { //verifica si el archivo se abrió correctamente
            string linea;
            while (getline(archivoEntrada, linea)) { //lee linea por linea hasta el final del archivo
                cout << linea << endl; //imprime la linea en la consola
            }
            archivoEntrada.close(); //cierra el archivo despues de leer
        } else {
            cout << "No se pudo abrir el archivo." << endl; //mensaje de error si no se pudo abrir el archivo
        }

    )";

    string punto8 = R"( 
    8. Dar Ejemplos de código "Descriptivamente Comentado" de Escritura de Archivos.
    - Ejemplo de Escritura en un Archivo:

        ofstream archivoSalida("resultados.txt"); //crea un objeto ofstream para escribir en "resultados.txt"
        
        if (archivoSalida.is_open()) { // Verificar si el archivo se abrió correctamente
            archivoSalida << "Resultado 1\n"; //escribe el primer resultado en el archivo
            archivoSalida << "Resultado 2\n"; //escribe el segundo resultado en el archivo
            archivoSalida.close(); //cierra el archivo despues de escribir
        } else {
            cout << "No se pudo abrir el archivo." << endl; //mensaje de error si no se pudo abrir el archivo
        }
        
    )";
};

int main(int argc, char const *argv[])
{
    cout << "--- TEORIA - GUIA 4 --- Archivos ---" << endl << endl;

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
