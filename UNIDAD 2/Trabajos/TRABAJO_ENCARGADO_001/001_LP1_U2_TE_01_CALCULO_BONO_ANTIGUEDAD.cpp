#include <iostream>
using namespace std;

int Tiempo(int anosAntiguedad) {
    int grupoAntiguedad = 0;

    if (anosAntiguedad >= 10) {
        grupoAntiguedad = 3;      
    } else if (anosAntiguedad >= 5) {
        grupoAntiguedad = 2;      
    } else if (anosAntiguedad >= 1) {
        grupoAntiguedad = 1;      
    } else {
        grupoAntiguedad = 0;      
    }

    return grupoAntiguedad;
}


double calcularBono(int anosAntiguedad) {
    double Bono = 0.0;
    int grupoAntiguedad = Tiempo(anosAntiguedad);

    switch (grupoAntiguedad) {
        case 3:
            Bono = 0.15;
            break;
        case 2:
            Bono = 0.10;
            break;
        case 1:
            Bono = 0.05;
            break;
        case 0:
            Bono = 0.0;
            break;
        default:
            Bono = 0.0;
            break;
    }

    return Bono;
}

void mostrarResultados(double sueldoBase, double montoBono, double sueldoTotal) {
    cout << "Sueldo base: S/ " << sueldoBase << endl;
    cout << "Monto del bono: S/ " << montoBono << endl;
    cout << "Sueldo neto a cobrar: S/ " << sueldoTotal << endl;
}

int main() {
    double sueldoBase = 0.0;
    int anosAntiguedad = 0;
    double Bono = 0.0;
    double montoBono = 0.0;
    double sueldoTotal = 0.0;

    cout << "Ingrese el sueldo base del empleado: ";
    cin >> sueldoBase;

    cout << "Ingrese los anos de antiguedad del empleado: ";
    cin >> anosAntiguedad;

    Bono = calcularBono(anosAntiguedad);
    montoBono = sueldoBase * Bono;
    sueldoTotal = sueldoBase + montoBono;

    mostrarResultados(sueldoBase, montoBono, sueldoTotal);

    return 0;
}