#include <iostream>
using namespace std;

int pedirCantEst();
void llenarNotas(double notas[], int n);
double calcPromedio(double notas[], int n);
double notaMayor(double notas[], int n);
double notaMenor(double notas[], int n);
int contarAprob(double notas[], int n);
int contarDesap(double notas[], int n);

int pedirCantEst() {
    int n = 0;

    do {
        cout << "Ingrese la cantidad de estudiantes (1 a 30): ";
        cin >> n;

        if (n < 1 || n > 30) {
            cout << "ERROR: Debe ingresar un valor entre 1 y 30." << endl;
        }
    } while (n < 1 || n > 30);

    return n;
}

void llenarNotas(double notas[], int n) {
    for (int i = 0; i < n; i++) {
        double notaTmp = -1.0;

        do {
            cout << "Ingrese la nota final " << (i + 1) << " (0 a 20): ";
            cin >> notaTmp;

            if (notaTmp < 0 || notaTmp > 20) {
                cout << "ERROR: La nota debe estar entre 0 y 20." << endl;
            }
        } while (notaTmp < 0 || notaTmp > 20);

        notas[i] = notaTmp;
    }
}

double calcPromedio(double notas[], int n) {
    double suma = 0.0;
    double prom = 0.0;

    for (int i = 0; i < n; i++) {
        suma = suma + notas[i];
    }

    prom = suma / n;
    return prom;
}

double notaMayor(double notas[], int n) {
    double max = 0.0;

    for (int i = 0; i < n; i++) {
        if (notas[i] > max) {
            max = notas[i];
        }
    }

    return max;
}

double notaMenor(double notas[], int n) {
    double min = 20.0;

    for (int i = 0; i < n; i++) {
        if (notas[i] < min) {
            min = notas[i];
        }
    }

    return min;
}

int contarAprob(double notas[], int n) {
    int apro = 0;

    for (int i = 0; i < n; i++) {
        if (notas[i] >= 10.5) {
            apro = apro + 1;
        }
    }

    return apro;
}

int contarDesap(double notas[], int n) {
    int desap = 0;

    for (int i = 0; i < n; i++) {
        if (notas[i] < 10.5) {
            desap = desap + 1;
        }
    }

    return desap;
}

int main() {
    int n = 0;
    double notas[30];
    double prom = 0.0;
    double max = 0.0;
    double min = 20.0;
    int apro = 0;
    int desap = 0;

    n = pedirCantEst();
    llenarNotas(notas, n);

    prom = calcPromedio(notas, n);
    max = notaMayor(notas, n);
    min = notaMenor(notas, n);
    apro = contarAprob(notas, n);
    desap = contarDesap(notas, n);

    cout << endl << "Cantidad de estudiantes: " << n << endl;
    cout << "Promedio general: " << prom << endl;
    cout << "Nota mas alta: " << max << endl;
    cout << "Nota mas baja: " << min << endl;
    cout << "Aprobados: " << apro << endl;
    cout << "Desaprobados: " << desap << endl;

    return 0;
}