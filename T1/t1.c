#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ler_alunos(int* mat, char nomes[][50], int* n ){

	FILE *f = fopen("alunos.txt", "r");
	int matr, cont;
	char c, nome[50];
	int linha = 0;
	while(feof(f) == 0){
		if(fscanf(f, "%d", &matr)<=0)
			break;
		
		c = fgetc(f);
		cont=0;
		while(c!='\n' && feof(f)==0){
			nome[cont] = c;
			c=fgetc(f);
			cont++;
		}
		nome[cont] = '\0';
		mat[linha] = matr;
		strcpy(nomes[linha], nome);
		linha++;
 	}
	*n=linha;
	fclose(f);
}
void ler_notas(float* meds){
	FILE *f = fopen("notas.txt", "r");
	int cont=0,matr;
	float n1, n2;
	
	while(feof(f) == 0){
		if(fscanf(f, "%d %f %f\n", &matr, &n1, &n2)==0)
			break;
		
		meds[cont] = (n1 + n2)/2;
		cont++;
	}
	
	fclose(f);
}

void busca(char nomes[][50],char* arg, float* meds, int* n){
	int cont;
	
	for(cont=0; cont<*n; cont++){
		if(strstr(nomes[cont], arg)!=NULL){
			printf("Media: %f Nome:%s\n", meds[cont], nomes[cont]);
		}
	}	
}

int main(int argc, char** argv){
    char* nome;
    float medias[50];
    int matriculas[50],n;
    char nomes[50][50];
    
    if(argc > 1){
        strcpy(nome, argv[1]);
        }
    printf("%s\n",nome);
        
        
    ler_alunos(matriculas, nomes, &n);
    ler_notas(medias);
    busca(nomes, nome, medias, &n);
    return 0;
}
