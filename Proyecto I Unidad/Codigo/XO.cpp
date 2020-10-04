# include <stdio.h>
# include <time.h>
# include <iostream>
# include <algorithm>

void loop( char tablero[3][3]);
void meterprimera (char tablero[3][3]);
void tabla(char tablero[3][3]);
void metervalores(char tablero[3][3]);
void metevaloresIA(char tablero[3][3]);
int gana (char tablero[3][3]);

int XO (){

    char tablero[3][3];
    
    loop (tablero); // Llamada de funciones elementales
    system("pause");
    system("cls");

    return 0;
}

void loop( char tablero[3][3]){
    int valor, win;
    
    valor=0;
    
    
    meterprimera(tablero);
   

    do{
      
      system("cls");
      printf("Bienvenido al XO \n****************");
      printf("\n");
      tabla(tablero);

      if (valor % 2 == 0){
        metervalores(tablero);
      }
      else{
        metevaloresIA(tablero);
      }
      
       win = gana(tablero);
       valor++;
       
      system("cls");
      tabla(tablero);

    }while (valor <= 9 && win == 2);
    
    if (win == 0){
    	printf("Congratulations, you have won");
        printf("\n");
	}
	else if (win == 1){
		printf("You can do, for now you have lost");
        printf("\n");
	}
	else {
		printf("This fight has been marvelous, you have tied");
        printf("\n");
	}
   
}

void meterprimera (char tablero[3][3]){
    int a, b; // contadores
    char auxiliar;

    auxiliar='1';

    for ( a=0; a < 3; a++  ){
        for ( b=0; b < 3; b++  ){
            tablero[a][b]=auxiliar++;
        }
    }
}

void metervalores(char tablero[3][3]){
    
    int e,f,g;
    char casilla;

    do{
        do{
            printf("\n Elegir casilla: ");
            fflush(stdin);
            scanf("%c",&casilla);
        }while (casilla < '1' || casilla > '9');
        
        g=0;

        switch(casilla){
            case '1':
                     e=0;
                     f=0;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '2':
                     e=0;
                     f=1;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '3':
                     e=0;
                     f=2;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '4':
                     e=1;
                     f=0;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '5':
                     e=1;
                     f=1;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=5;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '6':
                     e=1;
                     f=2;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '7':
                     e=2;
                     f=0;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '8':
                     e=2;
                     f=1;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;
            case '9':
                     e=2;
                     f=2;
                if(tablero[e][f]== 'X'||tablero[e][f]== 'O'){
                    g=1;
                    printf("\n\n Casilla Ocupada");
                }
                 break;    
        }
    }while(g==1);
    tablero[e][f] = 'X';
} 

void metevaloresIA(char tablero[3][3]){   //Valores que ingresa Inteligencia artificial
   
   int e,f,k;
  

   srand(time(NULL));

   do{          
        e = rand () % 3;
        f = rand () % 3;
        k=0;


        if(tablero[e][f] == 'X' || tablero[e][f] == 'O'){
            k=1;
        }
    
   } while(k==1);
    
	tablero[e][f] = 'O';  
}

void tabla(char tablero[3][3]){
   int c,d;
   
    for ( c=0; c < 3; c++  ){
        for ( d=0; d < 3; d++  ){
            if (d < 2){
             printf(" %c |", tablero[c][d] );
            } else{
             printf(" %c  ", tablero[c][d] );
            }
        }
         if( c < 2){
         printf("\n-----------\n");
       }
    }
    printf("\n\n");
}

int gana (char tablero[3][3]){
	if (tablero[0][0] == 'X' || tablero[0][0] == 'O'){
		if (tablero[0][0]==tablero[0][1] && tablero[0][0]==tablero[0][2]){
			if(tablero[0][0]=='X'){
				return 0; // Ganador
			}
			else {
				return 1; // Perdedor
			}
		}
	if (tablero[0][0]==tablero[1][0] && tablero[0][0]==tablero[2][0]){
		if(tablero[0][0]=='X'){
			return 0; // Ganador
			}
			else {
				return 1; // Perdedor
			}
		}
	}
	if (tablero[1][1] == 'X' || tablero[1][1] == 'O'){
		if (tablero[1][1]==tablero[0][0] && tablero[1][1]==tablero[2][2]){
			if(tablero[1][1]=='X'){
				return 0; // Ganador
			}
			else {
				return 1; // Perdedor
			}
		}
		if (tablero[1][1]==tablero[1][0] && tablero[1][1]==tablero[1][2]){
			if(tablero[1][1]=='X'){
				return 0; // Ganador
			}
			else {
				return 1; // Perdedor
			}
		}
		if (tablero[1][1]==tablero[2][0] && tablero[1][1]==tablero[0][2]){
			if(tablero[1][1]=='X'){
				return 0; // Ganador
			}
			else {
				return 1; // Perdedor
			}
        }
       	if (tablero[1][1]==tablero[0][1] && tablero[1][1]==tablero[2][1]){
			if(tablero[1][1]=='X'){
				return 0; // Ganador
			}
			else {
				return 1; // Perdedor
			}
		}
	}
	if (tablero[2][2] == 'X' || tablero[2][2] == 'O'){
		if (tablero[2][2] == tablero[2][0] && tablero[2][2] == tablero[2][1]){
			if(tablero[2][2]=='X'){
				return 0; // Ganador
			}
			else {
				return 1; // Perdedor
			}
		}
		if (tablero[2][2] == tablero[0][2] && tablero[2][2] == tablero[1][2]){
			if(tablero[2][2]=='X'){
				return 0; // Ganador
			}
			else {
				return 1; // Perdedor
	      	}
		}
	}
	return 2;	  	
}

