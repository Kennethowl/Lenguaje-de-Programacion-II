# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <windows.h>
# define V 25
# define H 50


void inicio (char campo[V][H], int px, int py, int ij, int fj, int ini, int fni);
void area(char campo[V][H]);
void raqueta(char campo[V][H], int ij, int fj);
void raqueta2(char campo[V][H], int ini, int fni);
void pelota(char campo [V][H], int px,int py);
void leercamp(char campo [V][H]);
void gameloop (char campo[V][H], int px, int py, int ij, int fj, int ini, int fni, int modx, int mody, int modia);
void draw(char campo [V][H]);
void input (char campo[V][H], int *px, int *py, int *ij, int *fj, int *ini, int *fni, int *modx, int *mody, int *modia, int *punto);
void update(char campo[V][H], int px, int py, int ij, int fj, int ini, int fni);


int main (){
	
	int px,py,ij,fj,ini,fni;
	int modx, mody, modia;
	char campo[V][H];
	
	system("color 3f");
	
	//Posicion
	
	px=30;
	py=10;
	
	ij=8;
	fj=12;
	
	ini=8;
	fni=12;
	
	//Modificacion
	
	modx = -1;
	mody = -1;
	modia = -1;
	
	inicio(campo,px,py,ij,fj,ini,fni);
	gameloop(campo,px,py,ij,fj,ini,fni, modx, mody, modia);
	system("pause");

	return 0;
}

void inicio (char campo[V][H], int px, int py, int ij, int fj, int ini, int fni){
	area(campo);
	raqueta(campo,ij,fj);
	raqueta2(campo, ini,fni);
	pelota(campo,px,py);
}
void area( char campo [V] [H] ){
	int a,b;
	
	for(a=0;a<V;a++){ 
	    for (b=0;b<H;b++){
          if (a==0||a==V-1){
		      campo[a][b]='*';
		  }
		  else if (b==0||b==H-1){
		           campo[a][b]='|'; }
		  else { campo [a][b]=' ';
		  }         
		}
	}
}
void raqueta(char campo[V][H], int ij, int fj){               //Raquetas
	int a,b;
	
	for (a=ij;a<=fj;a++){
		for(b=2;b<=3;b++){
			campo[a][b]='X';
				
		}
	}
}
void raqueta2(char campo[V][H], int ini, int fni){
	int a,b;
	for (a=ini;a<=fni;a++){
		for(b=H-4;b<=H-3;b++){
			campo[a][b]='%';
		}
	}
}
void pelota(char campo [V][H], int px,int py){    //Funcion pelota
	campo[px][py]='O';
}
void leercamp(char campo [V][H]){                //leer campo
	int a,b;
	
	for (a=0;a<V;a++){
		for(b=0;b<H;b++){
			printf("%c",campo[a][b]);
			}
			printf("\n");
	}
}

void gameloop (char campo[V][H], int px, int py, int ij, int fj, int ini, int fni, int modx, int mody, int modia){
	
	int punto;
	punto=0;
	
	do{
		draw(campo); //Draw
		input(campo, &px, &py, &ij, &fj, &ini, &fni, &modx, &mody, &modia, &punto); // Verified and modified the position in the matrix
		update(campo,px,py,ij,fj,ini,fni); //actualizar matriz campo
		Sleep(10); // sleep the processor
	}while (punto==0);
}

void draw(char campo [V][H]){
	system("cls");
	leercamp(campo);
}

void input (char campo[V][H], int *px, int *py, int *ij, int *fj, int *ini, int *fni, int *modx, int *mody, int *modia, int *punto){
	
	int i;
	char key;
	
	//Verificacion
	
	if (*py== 1 || *py == V -2){
		*mody *= -1; 
	}
	if (*px==1 || *px == H -2){
		*punto = 1; 
}
    if(*px==4){
      for ( i = (*ij); i <=(*fj);i++){
      	if(i==(*py)){
      		*modx*=-1;
		  }
	  }	
	}
	if(*px == H - 5){
      for ( i = (*ini); i <=(*fni);i++){
      	if(i==(*py)){
      		*modx*=-1;
		  }
	  }	
	}
	if (*ini== 1 || *fni == V -1){
		*modia *= -1; 
    }

    // Modificacion
    if (*punto == 0){
    	
               //Pelota 
			       	
	    	 *px += (*modx);
	         *py += (*mody);
	         
	         //Rqueta IA
	         
	         *ini += (*modia);
	         *fni += (*modia); 
			 
			 
			 if(kbhit()==1) {
			 key = getch();
			 
  	 if(key=='a'){
			 	if(*ij != 1){
			 		*ij -= 1;
			 		*fj -= 1;
				 }
			 }
			 
			 if(key=='s'){
			 	if(*fj != V -2){
			 		*ij += 1;
			 		*fj += 1;
		        } 
           }
       }
   }
}
void update(char campo[V][H], int px, int py, int ij, int fj, int ini, int fni){
	area(campo);
	raqueta(campo,ij,fj);
	raqueta2(campo, ini,fni);
	pelota(campo,px,py);
}
