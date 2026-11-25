#include <iostream>
using namespace std;

const int VENDEDORES = 4;
const int DIAS = 7;

void registrarVentas(double ventas[VENDEDORES][DIAS]) {
    cout << "REGISTRO DE VENTAS SEMANALES" << endl;

    for (int i = 0; i < VENDEDORES; i++) {
        cout << "\nVendedor " << i << endl;

        for (int j = 0; j < DIAS; j++) {
            double venta = -1.0;

            do {
                cout << "Venta del dia " << j << ": ";
                cin >> venta;

                if (venta < 0) {
                    cout << "ERROR: El monto no puede ser negativo." << endl;
                }
            } while (venta < 0);

            ventas[i][j] = venta;
        }
    }
}

void mostrarPorVendedor(double ventas[VENDEDORES][DIAS]) {
    double total = 0.0;

    cout << "\nTOTAL VENDIDO POR CADA VENDEDOR" << endl;
    for (int i = 0; i < VENDEDORES; i++) {
        total = 0.0;

        for (int j = 0; j < DIAS; j++) {
            total = total + ventas[i][j];
        }

        cout << "Vendedor " << i << ": S/ " << total << endl;
    }
}

void mostrarPorDia(double ventas[VENDEDORES][DIAS]) {
    double total = 0.0;

    cout << "\nTOTAL VENDIDO POR CADA DIA" << endl;

    for (int j = 0; j < DIAS; j++) {
        total = 0.0;

        for (int i = 0; i < VENDEDORES; i++) {
            total = total + ventas[i][j];
        }

        cout << "Dia " << j << ": S/ " << total << endl;
    }
}

double calcularTotal(double ventas[VENDEDORES][DIAS]) {
    double total = 0.0;

    for (int i = 0; i < VENDEDORES; i++) {
        for (int j = 0; j < DIAS; j++) {
            total = total + ventas[i][j];
        }
    }

    return total;
}

int main() {
    double ventas[VENDEDORES][DIAS];
    double total = 0.0;

    registrarVentas(ventas);
    mostrarPorVendedor(ventas);
    mostrarPorDia(ventas);

    total = calcularTotal(ventas);

    cout << "\nMONTO TOTAL ACUMULADO DE LA SEMANA" << endl;
    cout << "Total vendido en toda la semana: S/ " << total << endl;

    return 0;
}