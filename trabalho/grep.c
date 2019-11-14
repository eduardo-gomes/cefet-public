#include <stdio.h>
#include <string.h>
FILE *arquivo_atual;
int file_name = -1, invalid = 0, helped = 0, prt_color = 'R', color_enable = 1;
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
		"\t\t-H, --with-filename :Show File name, line and col first patern found (Default with multiple files)\n"
		"\t\t-h, --no-filename :Dont File name, line and col first patern found (Default with single file)\n"
		"\t\t--color= :highlight color, avaliable R - red, B - Blue, M - magenta, N - no color\n"
		"\t\t--no_color :No color\n"
		"\t\tWIP\n";
	printf("%s", help);
}
char *color(int enable){
	char *red = "\x1B[31m", *blue = "\x1B[34m", *mag = "\x1B[35m", *norm = "\x1B[0m", *not = "";
	char *fname = "\x1B[32m";
	if(color_enable){
		if(enable == 'H')//Filename color
			return fname;
		else if(enable == 'h')
			return norm;
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
					printf("%s%s %d:%ld:%s ", color('H'), param, (i + 1), posi - line + 1, color('h'));
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
					memcpy(pt[2], line + linepos , sizeof(char) * (strlen(line + linepos) + 1));
					//add EOL
					pt[2][strlen(line + linepos) + 1] = 0;//Fixed bug last thar dont show
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
		else if (strcmp(argv[1 + params], "--with-filename") == 0 || strcmp(argv[1 + params], "-H") == 0)
			file_name = 1;								  //Print File info
		else if (strcmp(argv[1 + params], "--no-filename") == 0 || strcmp(argv[1 + params], "-h") == 0)
			file_name = 0;
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
	int first_file = 2 + params, file_count = -first_file +argc;
	if(file_name == -1){// if not defined
		if(file_count > 1) file_name = 1; //if multiple files
		else file_name = 0; //if single
	}
	if(argc < 2) invalid = 1;
	if(invalid && !helped){// argumentos insuficientes
		printf("USAGE: %s \"patern\"  File[1] ... File[n]\n%s --help for details\n", argv[0], argv[0]);
		return 0;
	}
	if(stop) return 0;
	char *find = argv[1+params];
	for(int i = first_file; i < argc; ++i){
		busca_no_arquivo(find, argv[i]);
	}
	if(!file_count)
		busca_no_arquivo(find, NULL);
}