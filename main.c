#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char f[100], var[10], matriz[10][10];
int p=0, tempN, indice=0, qtVar=0;
void e0();
void e1();
void e2();
void funcao1(char simbolo);
void funcao2(char simbolo);
void funcao3();
void funcao4(char simbolo);
void funcao5(char simbolo);
void funcao6();

void e0(){
	if( (f[p] >= 65 && f[p] <= 90) || (f[p] >= 97 && f[p] <= 122) ){ // entre A-Z ou a-z
		funcao1(f[p]);
		p++;
		e1();
	}
	else{
		if(f[p] >= 48 && f[p] <= 57){ // entre 0-9
			funcao4(f[p]);
			p++;
			e2();
		}
		else{
			if(f[p] == 0){
				printf("\n");
				getch();
				exit(0);
			}
			else{
				printf("\n-> FALHA e0()\n");
				getch();
				exit(0);
			}
		}
	}
}

void e1(){
	
	if((f[p] >= 65 && f[p] <= 90) || (f[p] >= 97 && f[p] <= 122)){ // entre A-Z ou a-z
		funcao2(f[p]);
		p++;
		e1();
	}
	else{
		if(f[p] >= 48 && f[p] <= 57){ // entre 0-9
			funcao2(f[p]);
			p++;
			e1();
		}
		else{
			if(f[p] == 32){ // espaço
				funcao3();
				p++;
				e0();
			}
			else{
				printf("\n-> FALHA e1()\n");
				getch();
				exit(0);
			}
		}
	}
}

void e2(){
	if(f[p] >= 48 && f[p] <= 57){ // entre 0-9
		funcao5(f[p]);
		p++;
		e2();
	}
	else{
		if(f[p] == 32){ // espaço
			funcao6();
			p++;
			e0();
		}
		else{
			printf("\n-> FALHA e2()\n");
			getch();
			exit(0);
		}
	}
}

void funcao1(char simbolo){
	var[indice] = simbolo;
	indice++;
}

void funcao2(char simbolo){
	var[indice] = simbolo;
	indice++;
}

void funcao3(){
	int posicao = -1, i;
	
	for(i=0; i<qtVar; i++){
		if(strcmp(var, matriz[i]) == 0){
			posicao = i;
		}
	}
	
	if(posicao == -1){
		strcpy(matriz[qtVar], var);
		posicao = qtVar;
		qtVar++;
	}
	
	printf("V(%d) ", posicao);
	indice=0;
}

void funcao4(char simbolo){
	tempN = simbolo - '0';
}

void funcao5(char simbolo){
	tempN = tempN*10 + (simbolo - '0');
}

void funcao6(){
	printf("N(%d) ", tempN);
	tempN = 0;
}

void inicializaMatriz(){
	int i, j;
	
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			matriz[i][j] = 0;
		}
	}
}

int main(int argc, char *argv[]){
	int i;
	
	inicializaMatriz();
		
	printf("Linha: ");
	
	gets(f);
	
	e0();

	system("pause");
	return 0;
}
