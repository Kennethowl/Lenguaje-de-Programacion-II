#include <iostream>
#include "startShip.h"
#include "snake.h"

using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
      
    int opcion=0;
    

    while(true){
    cout << "Ingrese una opcion: " << endl;
    cin >> opcion;
    cout << "1 - Startship" << endl;
    cout << "2 - Snake" << endl;

    switch{

    case 1: starShip();
    break;
    case 2: snake();
    break;
    default:
    break;
    }
    }

    if (opcion=0){
        cout << "Fin del Programa" << endl;
    }
    return 0;
}
