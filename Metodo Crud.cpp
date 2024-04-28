#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ESTUDIANTES = 100;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float notas[4];
    float promedio;
    string resultado;
};

void agregarEstudiante(Estudiante estudiantes[], int& numEstudiantes) {
    if (numEstudiantes < MAX_ESTUDIANTES) {
        Estudiante nuevoEstudiante;

        cout << "Ingrese el ID del estudiante: ";
        cin >> nuevoEstudiante.id;
        cin.ignore(); // Limpiar el buffer de entrada

        cout << "Ingrese los nombres del estudiante: ";
        getline(cin, nuevoEstudiante.nombres);

        cout << "Ingrese los apellidos del estudiante: ";
        getline(cin, nuevoEstudiante.apellidos);

        cout << "Ingrese las 4 notas del estudiante: ";
        for (int i = 0; i < 4; ++i) {
            cin >> nuevoEstudiante.notas[i];
        }

        // Calcular el promedio
        nuevoEstudiante.promedio = 0;
        for (int i = 0; i < 4; ++i) {
            nuevoEstudiante.promedio += nuevoEstudiante.notas[i];
        }
        nuevoEstudiante.promedio /= 4;

        // Determinar el resultado
        nuevoEstudiante.resultado = (nuevoEstudiante.promedio >= 60) ? "Aprobado" : "Reprobado";

        estudiantes[numEstudiantes++] = nuevoEstudiante;

        cout << "Estudiante agregado correctamente.\n";
    } else {
        cout << "No se pueden agregar más estudiantes, límite alcanzado.\n";
    }
}

void guardarEstudiantes(Estudiante estudiantes[], int numEstudiantes) {
    ofstream archivo("notas.dat", ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(estudiantes), numEstudiantes * sizeof(Estudiante));
        archivo.close();
        cout << "Estudiantes guardados en notas.dat correctamente.\n";
    } else {
        cout << "Error al abrir el archivo notas.dat\n";
    }
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes = 0;

    char opcion;
    do {
        cout << "\nMenú:\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Guardar estudiantes en archivo\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                agregarEstudiante(estudiantes, numEstudiantes);
                break;
            case '2':
                guardarEstudiantes(estudiantes, numEstudiantes);
                break;
            case '3':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != '3');

    system("pause");
}
