#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "1 Consultar saldo" << endl<<"2 Retirar dinero" << endl<<"3 Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void consultarSaldo(double saldo) {
    cout << "Saldo disponible: S/ " << saldo << endl;
}

double realizarRetiro(double saldo) {
    double monto = 0.0;

    cout << "Ingrese el monto a retirar: ";
    cin >> monto;

    if (monto <= 0) {
        cout << "ERROR: El monto debe ser mayor a 0." << endl;
    } else if (monto > saldo) {
        cout << "ERROR: El monto solicitado supera el saldo disponible." << endl;
    } else {
        saldo = saldo - monto;
        cout << "Retiro exitoso. Nuevo saldo: S/ " << saldo << endl;
    }

    return saldo;
}

int main() {
    double saldo = 2000.0;
    int op = 0;

    do {
        mostrarMenu();
        cin >> op;

        if (op == 1) {
            consultarSaldo(saldo);
        }
        else if (op == 2) {
            saldo = realizarRetiro(saldo);
        }
        else if (op == 3) {
            cout << "Gracias por usar el cajero. Hasta pronto." << endl;
        }
        else {
            cout << "ERROR: Opcion no valida. Intente nuevamente." << endl;
        }

    } while (op != 3);

    return 0;
}