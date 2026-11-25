#include <iostream>
using namespace std;

int pedirCantidad() {
    int productos = 0;

    do {
        cout << "Ingrese la cantidad de productos (1 a 20): ";
        cin >> productos;

        if (productos < 1 || productos > 20) {
            cout << "ERROR: Debe ingresar un valor entre 1 y 20." << endl;
        }
    } while (productos < 1 || productos > 20);

    return productos;
}

void registrarUnidades(int unidades[], int productos) {
    for (int i = 0; i < productos; i++) {
        int unidad = -1;

        do {
            cout << "Ingrese unidades disponibles del producto " << i << ": ";
            cin >> unidad;

            if (unidad < 0) {
                cout << "ERROR: El stock no puede ser negativo." << endl;
            }
        } while (unidad < 0);

        unidades[i] = unidad;
    }
}

int sumar(int unidades[], int productos) {
    int suma = 0;
    for (int i = 0; i < productos; i++) {
        suma = suma + unidades[i];
    }
    return suma;
}

int indiceMayor(int unidades[], int productos) {
    int mayor = 0;
    for (int i = 0; i < productos; i++) {
        if (unidades[i] > unidades[mayor]) {
            mayor = i;
        }
    }
    return mayor;
}

int indiceMenor(int unidades[], int productos) {
    int menor = 0;
    for (int i = 0; i < productos; i++) {
        if (unidades[i] < unidades[menor]) {
            menor = i;
        }
    }
    return menor;
}

int contarBajos(int unidades[], int productos, int limite) {
    int bajos = 0;
    for (int i = 0; i < productos; i++) {
        if (unidades[i] < limite) {
            bajos = bajos + 1;
        }
    }
    return bajos;
}

int main() {
    int productos = 0;
    int unidades[20];
    int suma = 0;
    int mayor = 0;
    int menor = 0;
    int limite = 0;
    int bajos = 0;

    productos = pedirCantidad();
    registrarUnidades(unidades, productos);

    suma = sumar(unidades, productos);
    mayor = indiceMayor(unidades, productos);
    menor = indiceMenor(unidades, productos);

    cout << "\nIngrese el limite minimo de stock: ";
    cin >> limite;

    bajos = contarBajos(unidades, productos, limite);

    cout << "\nStock registrado por producto:" << endl;
    for (int i = 0; i < productos; i++) {
        cout << "  Producto [" << i << "]: " << unidades[i] << " unidades" << endl;
    }

    cout << "\nTotal de unidades en existencia: " << suma << endl;
    cout << "Mayor stock: indice " << mayor << " con " << unidades[mayor] << " unidades" << endl;
    cout << "Menor stock: indice " << menor << " con " << unidades[menor] << " unidades" << endl;

    if (bajos > 0) {
        cout << "ALERTA: " << bajos << " producto(s) requieren reabastecimiento." << endl;
    } else {
        cout << "No hay productos por debajo del limite minimo." << endl;
    }

    return 0;
}