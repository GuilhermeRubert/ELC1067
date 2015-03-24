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

void busca(char** nomes,char* arg, float* meds, int* n, int* matriculas){
	
	int *matr,i;
	
	matr = (int*) malloc(50*sizeof(int));
	FILE *f = fopen("notas.txt", "r"); 
	
	while(feof(f)==0){
			fscanf(f, "%d * *", &matr);
			for(i=0; i<*n; i++){
				if(matriculas[i]==*matr)
					if(strstr(nomes[i], arg)!=NULL)
					printf("Media: %f Nome:%s\n", meds[i], nomes[i]);
			}
		}
		
	free(matr);
	fclose(f);
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
    busca(nomes, nome, medias, &n, matriculas);
    
    
    for(i=0; i<n; i++){
    	free(nomes[i]);
    }
	
	free(nome);
	free(medias);
    free(matriculas);
    free(nomes);
    
    
    return 0;
}
