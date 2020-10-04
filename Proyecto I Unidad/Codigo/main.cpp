#include <iostream>
#include "startShip.h"
#include "snake.h"
#include "XO.h"


using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
      
    int opcion=0;
   
    do{
    cout <<"-----------------------------------------------" << endl;
    cout <<"-                OWL CONSOLE INC              -" << endl;
    cout <<"-----------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese una opcion: " << endl;
    cout << "1 - Startship" << endl;
    cout << "2 - Snake" << endl;
    cout << "3 - X0" << endl;
    cout << "4 - Salir de Owl Console" << endl;
    cout << "0 - Seguir de Owl Console" << endl;

    cin >> opcion;
   
    switch(opcion){

    case 1: starShip();
    break;
    case 2: snake();
    break;
    case 3: XO();
    break;
    default:
            cout << "Owl Console Inc Enterteinment"<< endl;
    break;
    }
} while (opcion==0);
    return 0;
}
