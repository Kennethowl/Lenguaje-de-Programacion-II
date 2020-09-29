#include <iostream>
#include <string>

using namespace std;

string productos[5][4] = {
    { "001", "iPhone X", "0", "0" },
    { "002", "Laptop Dell", "5","0" },
    { "003", "Monitor Samsung", "2","0"},
    { "004", "Mouse", "100","0"},
    { "005", "HeadSet", "25","0" }
};

void listarProductos() {
    system("cls");
    cout << endl;
    cout << "Listado de Productos" << endl;
    cout << "********************" << endl;
    cout << "Codigo | Descripcion  | Existencia | Ganancias y Perdidas" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << productos[i][0] << " | " << productos[i][1] << " | " << productos[i][2] <<  " | " << productos[i][3] << endl; 
    }
}

void movimientoInventario(string codigo, int cantidad, int precio, string tipoMovimiento) {
    for (int i = 0; i > 0; i++)
    {
        if (productos[i][0] == codigo) {
            if (tipoMovimiento == "+") {
                productos[i][2] = to_string(stoi(productos[i][2]) + cantidad);
            } else {
                productos[i][2] = to_string(stoi(productos[i][2]) - cantidad);
            }
            if (tipoMovimiento == "+") {
                productos[i][3] = to_string(stoi(productos[i][3]) + precio * cantidad);
            } else {
                productos[i][3] = to_string(stoi(productos[i][3]) - precio * cantidad);
            }    
        }
    }
}

void ingresoDeInventario() {
    string codigo = "";
    int cantidad = 0;
    int precio = 0;

    system("cls");
    cout << endl;
    cout << "Ingreso de Productos al Inventario" << endl;
    cout << "**********************************" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;
    cout << "Ingrese el precio: ";
    cin >> precio;
    cout << endl;

    movimientoInventario(codigo, cantidad, precio, "+");
}

void salidaDeInventario() {
    string codigo = "";
    int cantidad = 0;
    int precio = 0;

    system("cls");
    cout << endl;
    cout << "Salida de Productos del Inventario" << endl;
    cout << "**********************************" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;
    cout << "Ingrese el precio: ";
    cin >> precio;
    cout << endl;
    
    

    movimientoInventario(codigo, cantidad, precio, "-");
}

void ajustePositivodeInventario() {
    string codigo = "";
    int cantidad = 0;
    int precio = 0;

    system("cls");
    cout << endl;
    cout << "Ingrese el Ajuste Positivo" << endl;
    cout << "**********************************" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;
    cout << "Ingrese el precio: ";
    cin >> precio;
    cout << endl;
  
    
    movimientoInventario(codigo, cantidad, precio, "+");
}

void ajusteNegativodeInventario() {
    string codigo = "";
    int cantidad = 0;
    int precio = 0;

    system("cls");
    cout << endl;
    cout << "Ingrese el ajuste negativo" << endl;
    cout << "**********************************" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;
    cout << "Ingrese el precio: ";
    cin >> precio;
    cout << endl;
    

    movimientoInventario(codigo, cantidad, precio, "-");
}

int main(int argc, char const *argv[])
{
    int opcion = 0;

    while(true) {
        system("cls");

        cout << "Sistema de Inventario"; 
        cout << endl;
        cout << "*********************";
        cout << endl;
        cout << endl;
        cout << "1 - Productos" << endl;
        cout << "2 - Ingreso de Inventario" << endl;
        cout << "3 - Salida de Inventario" << endl;
        cout << "4 - Ajuste Positivo de Inventario" << endl;
        cout << "5 - Ajuste Negativo de Inventario" << endl;
        cout << "0 - Salir" << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: 
            listarProductos();            
            break;
        case 2:
            ingresoDeInventario();
            break;
        case 3:
            salidaDeInventario();
            break;
        case 4:
            ajustePositivodeInventario();
            break;
        case 5:
            ajusteNegativodeInventario();
            break;        
        
        default:
            break;
        }

        system("pause");
        cout << endl;

        if (opcion == 0) {
            break;
        }
    }

 

    return 0;
}
