#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ler_aluno(int* mat, char** nomes, int* n ){

	FILE *f = fopen("alunos.txt", "r");
	int matr, i;
	char c, nome[50];
	int linha = 0;
	while(feof(f) != 0){
		fscanf(f, "%d", &matr);
		i=0;
		c = fgetc(f);
		while(c==' ')
			c=fgetc(f);
		while(c!='\n'){
			nome[i] = c;
			i++;
		}
		nome[i] = '\0';
		mat[linha] = matr;
		strcpy(nomes[linha], nome);
		linha++;
 	}
	*n=linha;
	fclose(f);
}





int main( int argc, char **argv)
{
	char *nome;
	char nomes[50][50]
	int matricula[50], n;
	if(argc>1){
		nome=argv[1];
	}
	printf("%s\n", nome);
	return 0;
	ler_aluno(matricula, nomes, &n);
}



