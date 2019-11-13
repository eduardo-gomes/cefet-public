#include <stdio.h>
#include <string.h>
FILE *arquivo_atual;
int file_name = 0, invalid = 0, helped = 0, prt_color = 'R', color_enable = 1;
/////////////////////////////////////////////////////////////////////////
/////////////////////////////// TO PRINT ////////////////////////////////
void help(){//HELP
	helped = 1;
	char *version = \
		"Du grep 0.0.4	 © All rights reserved";
	char *help =
		"USAGE: Dugrep [option] \"patern\"  File[1] ... File[n]\n"
		"USAGE: Dugrep [option] \"patern\" For standard input\n"
		"Dugrep --help for details\n"
		"\n"
		"\tOptions:\n"
		"\t\t-?, --help :Show this\n"
		"\t\t-FN, --file_name :Show File name, line and col first patern found\n"
		"\t\t--color= :highlight color, avaliable R - red, B - Blue, M - magenta, N - no color\n"
		"\t\t--no_color :No color\n"
		"\t\tWIP\n";
	printf("%s", help);
}
char *color(int enable){
	char *red = "\x1B[31m", *blue = "\x1B[34m", *mag = "\x1B[35m", *norm = "\x1B[0m", *not = "";
	if(color_enable){
		if(enable){
			if(prt_color == 'R')
				return red;
			else if(prt_color == 'B')
				return blue;
			else if(prt_color == 'M')
				return mag;
			else
				return norm;//Color not found
		}else
			return norm;
	}else
		return not;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////// TO SEARCH ///////////////////////////////
void busca_no_arquivo(char *patern, char* param){ //search and print on patern found
		const long long patern_len = strlen(patern);
		char line[123456], pt[3][123456];
		arquivo_atual = fopen(param, "r");
		if(param == NULL) arquivo_atual = stdin;
		if (arquivo_atual == NULL){
			printf("CAN'T OPEN %s\n", param);
			return;
		}
		for (int i = 0; fgets(line, 123456, arquivo_atual) != NULL; ++i){
			long linepos = 0;
			char *posi = strstr(line, patern);
			if (posi != NULL){
				if (file_name)
					printf("%s %d:%ld: ", param, (i + 1), posi - line + 1);
				//Split ocorences and COLOR
				while(posi != NULL){// Split to insert color
					//Copy str before
					memcpy(pt[0], line + linepos, sizeof(char) * ( posi - line - linepos));
					//Add EOL
					pt[0][posi - line - linepos] = '\0';
					linepos = posi - line;//New linepos, before patern
					//Copy patern
					memcpy(pt[1], line + linepos, sizeof(char) * patern_len);
					//add EOL
					pt[1][patern_len] = 0;
					//Copy rest of line
					linepos += patern_len;//New linepos, after patern
					memcpy(pt[2], line + linepos , sizeof(char) * strlen(line + linepos));
					//add EOL
					pt[2][strlen(line + linepos + patern_len) + 1] = 0;
					//Print with color
					printf("%s%s%s%s", pt[0], color(1), pt[1], color(0));
					posi = strstr(line + linepos, patern);
				}
				printf("%s", pt[2]);//Print end
			}
		}
		fclose(arquivo_atual);
}
/////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]){	// patern File1 ... Filen
									//	arg1	arg2	arg(argc-1)
	int params = 0, stop = 0;
	while(params + 1 < argc && argv[1+params][0] == '-'){// le parametros
		if (strcmp(argv[1 + params], "--help") == 0 || strcmp(argv[1 + params], "-?") == 0)
			help(0);													  //Help
		else if (strcmp(argv[1 + params], "--file_name") == 0 || strcmp(argv[1 + params], "-FN") == 0)
			file_name = 1;								  //Print File info
		else if(strcmp(argv[1+params], "--version") == 0){//Print version
			help('v');
			stop = 1;//dont run with this option
		}else if(strncmp(argv[1+params], "--color=X", 8) == 0){//Print color
			color_enable = 1;
			prt_color = argv[1+params][8];//Get color
			if(argv[1+params][8] == 'N') color_enable = 0;
		}else if(strcmp(argv[1+params], "--no-color") == 0)//Disable color
			color_enable = 0;
		else invalid = 1;//Invalid option
		params++;
	}
	if(argc < 2) invalid = 1;
	if(invalid && !helped){// argumentos insuficientes
		printf("USAGE: %s \"patern\"  File[1] ... File[n]\n%s --help for details\n", argv[0], argv[0]);
		return 0;
	}
	if(stop) return 0;
	char *find = argv[1+params];
	for(int i = 2 + params; i < argc; ++i){
		busca_no_arquivo(find, argv[i]);
	}
	if(2 + params == argc)
		busca_no_arquivo(find, NULL);
}