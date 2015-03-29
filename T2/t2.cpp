#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int tamanho(){
	
	FILE *f = fopen("alunos.txt", "r");
	int con=0;
	char c;
	while(feof(f) == 0){
		c = fgetc(f);
		while(c!='\n' && feof(f)==0)
			c=fgetc(f);
		con++;
	}

	return con;	
}

void ler_alunos(int* mat, char** nomes, int* n){

	FILE *f = fopen("alunos.txt", "r");
	int matr, cont;
	char c;
	int linha = 0;
	char* nome;
	
	nome = (char*) malloc(50* sizeof(char));
	if(nome == NULL){
    	printf("Memória insuficiente");
    }
	
	
	while(c!= EOF){
		if(fscanf(f, "%d", &matr)<=0)
			break;
		
		c=fgetc(f);
		cont=0;
		while(c!='\n' && feof(f)==0){
			nome[cont] = c;
			c=fgetc(f);
			cont++;
		}
		nome[cont] = '\0';
		mat[linha] = matr;
		nomes[linha] = (char*) malloc((strlen(nome) + 1)*sizeof(char));
		strcpy(nomes[linha], nome);
		linha++;
 	}
	*n=linha;
	free(nome);
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

void busca(int tam, char* arg, char** nomes){
	
	int  *mtrNotas, *mtrAlunos,mtrNotas1, mtrAlunos1, i, j;
	float *med, n1, n2;
	FILE *f = fopen("notas.txt", "r");
	
	mtrNotas = (int*) malloc(tam* sizeof(int));
	med = (float*) malloc(tam* sizeof(float));
	
	for(i=0; i<tam; i++){
		
		fscanf(f, "%d %f %f", &mtrNotas1, &n1, &n2);
		med[i] = (n1+n2)/2;		
		mtrNotas[i] = mtrNotas1;
	}
	
	fclose(f);
	
	FILE *a = fopen("alunos.txt", "r");
	
	mtrAlunos = (int*) malloc(tam* sizeof(int));
	
	
	for(i=0; i<tam; i++){
		
		fscanf(a, "%d ", &mtrAlunos1);	
		mtrAlunos[i] = mtrAlunos1;
	}
	
	for(j=0; j<tam; j++){
		for(i=0; i<tam; i++){
			if(strstr(nomes[i], arg)!=NULL)
				if(mtrNotas[i] == mtrAlunos[j]){
				printf("Nome: %s Media: %f", med[i]);
				}
		}	
	}
	
	free(mtrNotas);
	free(mtrAlunos);
	free(med);
	fclose(a);
}

int main(int argc, char** argv){
    char *nome;
    float *medias;
    int *matriculas,n;
    int tam, i;
    char **nomes;
    
    
    nome = (char*) malloc(50* sizeof(char));
    if(nome == NULL){
    	printf("Memória insuficiente");
    }
    
    if(argc > 1){
        nome=argv[1];
        }
    
    
    tam=tamanho();
    medias = (float*) malloc(tam* sizeof(float));
    
    if(medias == NULL){
    	printf("Memória insuficiente");
    }
    
    matriculas = (int*) malloc(tam* sizeof(int));
    
    if(matriculas == NULL){
    	printf("Memória insuficiente");
    }
    
    nomes = (char**) malloc(tam*sizeof(char*));
    if(nomes == NULL){
    	printf("Memória insuficiente");
    } 
    
       
    ler_alunos(matriculas, nomes, &n);
    ler_notas(medias);
    busca(tam, nome, nomes);
    
    
    
    for(i=0; i<n; i++){
    	free(nomes[i]);
    }
	
	free(nome);
	free(medias);
    free(matriculas);
    free(nomes);
    
    
    return 0;
}
