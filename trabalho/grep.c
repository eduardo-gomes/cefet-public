#include <stdio.h>
#include <string.h>
FILE *arquivo_atual;
int file_name = 0, invalid = 0, helped = 0;
void help(){//HELP
	helped = 1;
	printf("USAGE: Dugrep [option] \"patern\"  File[1] ... File[n]\n");
	printf("Dugrep --help for details\n");
	printf("\n");
	printf("\tOptions:\n");
	printf("\t\t--file_name :Show File name, line and col first patern found\n");
	printf("\t\tWIP\n");
}

void busca_no_arquivo(char *patern, char* param){//search and print on patern found
	char line[123456];
	arquivo_atual = fopen(param, "r");
	if (arquivo_atual == NULL){
		printf("CAN'T OPEN %s\n", param);
		return;
	}
	for(int i = 0; fgets(line, 123456, arquivo_atual) != NULL; ++i){
		char *posi = strstr(line, patern);
		if(posi != NULL){
			if(file_name)
				printf("%s %d:%ld: ", param, i+1, posi-line+1);
			printf("%s", line);
		}
	}
	fclose(arquivo_atual);
}

int main(int argc, char *argv[]){	// patern File1 ... Filen
									//	arg1	arg2	arg(argc-1)
	int params = 0;
	while(params + 1 < argc && argv[1+params][0] == '-'){// le parametros
		if(strcmp(argv[1+params], "--help") == 0) help();
		else if(strcmp(argv[1+params], "--file_name") == 0) file_name = 1;
		else invalid = 1;
		params++;
	}
	if(argc < 3) invalid = 1;
	if(invalid && !helped){// argumentos insuficientes
		printf("USAGE: %s \"patern\"  File[1] ... File[n]\n%s --help for details\n", argv[0], argv[0]);
		return 0;
	}
	char *find = argv[1+params];
	for(int i = 2 + params; i < argc; ++i){
		busca_no_arquivo(find, argv[i]);
	}
}