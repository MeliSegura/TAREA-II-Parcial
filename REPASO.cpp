#include <iostream>
#include <string>

using namespace std;

int main() {
    int num_estudiantes;

    cout << "Ingrese el número de estudiantes: ";
    cin >> num_estudiantes;

    int IDs[num_estudiantes];
    string nombres[num_estudiantes];
    string apellidos[num_estudiantes];
    float notas[num_estudiantes][4];
    float promedio;

    for(int i = 0; i < num_estudiantes; i++) {
        cout << "Ingrese el ID del estudiante " << i + 1 << ": ";
        cin >> IDs[i];
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin.getline(nombres,i);
        cout << "Ingrese el apellido del estudiante " << i + 1 << ": ";
        cin >> apellidos[i];

        promedio = 0;
        for(int j = 0; j < 4; j++) {
            cout << "Ingrese la nota " << j + 1 << " del estudiante " << i + 1 << ": ";
            cin >> notas[i][j];
            promedio += notas[i][j];
        }
        promedio = promedio / 4;

        cout << "El estudiante " << nombres[i] << " " << apellidos[i] << " con ID " << IDs[i];
        cout << " tiene un promedio de " << promedio << ". ";
        if (promedio >= 60) {
            cout << "Estado: Aprobado\n";
        } else {
            cout << "Estado: Reprobado\n";
        }
    }

    system ("pause");
}


