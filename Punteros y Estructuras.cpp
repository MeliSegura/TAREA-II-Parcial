#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    int ID;
    string nombre;
    string apellido;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
};

void calcularPromedio(Estudiante* estudiante) {
    estudiante->promedio = (estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4) / 4;
}

void aprobarReprobar(Estudiante* estudiante) {
    if (estudiante->promedio >= 60) {
        cout << estudiante->nombre << " "<< estudiante->apellido << " ha APROBADO con un promedio de " << estudiante->promedio << endl;
    } else {
        cout << estudiante->nombre << " " << estudiante->apellido << " ha REPROBADO con un promedio de " << estudiante->promedio << endl;
    }
}

int main() {
    int N;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    Estudiante* estudiantes = new Estudiante[N];

    for (int i = 0; i < N; i++) {
        cout << "Ingrese el ID del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].ID;

        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombre;

        cout << "Ingrese el apellido del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].apellido;

        cout << "Ingrese la nota 1 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota1;

        cout << "Ingrese la nota 2 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota2;

        cout << "Ingrese la nota 3 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota3;

        cout << "Ingrese la nota 4 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota4;

        calcularPromedio(&estudiantes[i]);
        aprobarReprobar(&estudiantes[i]);
    }

    delete[] estudiantes;

    system("pause");
}

