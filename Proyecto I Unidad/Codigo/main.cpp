#include <iostream>
#include "startShip.h"
#include "snake.h"
//#include "Pong3.h"


using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
      
    int opcion=0;
   
    while(true){
    cout <<"-----------------------------------------------" << endl;
    cout <<"-                OWL CONSOLE INC              -" << endl;
    cout <<"-----------------------------------------------" << endl;
    cout << "Ingrese una opcion: " << endl;
    cout << "1 - Startship" << endl;
    cout << "2 - Snake" << endl;
    cout << "3 - Pong" << endl;
    cout << "0 - Salir de Owl Console" << endl;

    cin >> opcion;
   
    switch(opcion){

    case 1: starShip();
    break;
    case 2: snake();
    break;
    case 3: Pong3();
    break;
    default:
    break;
    }
} while (opcion==0){
    break;
}
    
    return 0;
}
