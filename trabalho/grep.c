#include <stdio.h>
#include <string.h>
#define filenamecoloron 'H'
#define filenamecoloroff 'h'
FILE *arquivo_atual;
int file_name = -1, invalid = 0, helped = 0, prt_color = 'R', color_enable = 1, matches = 0, echonfind = 1, listwith = -1, listcount = 0, maxlines = -1;
/////////////////////////////////////////////////////////////////////////
/////////////////////////////// TO PRINT ////////////////////////////////
void help(){//HELP
	helped = 1;
	char *version = \
		"Du grep 0.0.6	 © All rights reserved";
	char *help =
		"USAGE: Dugrep [option] \"patern\"  File[1] ... File[n]\n"
		"USAGE: Dugrep [option] \"patern\" For standard input\n"
		"Dugrep --help for details\n"
		"\n"
		"\tOptions:\n"
		"\t\t-?, --help :Show this\n"
		"\t\t-H, --with-filename :Show File name, line and col first patern found (Default with multiple files)\n"
		"\t\t-h, --no-filename :Dont File name, line and col first patern found (Default with single file)\n"
		"\t\t-c, --count : print number of mathes per file\n"
		"\t\t-L, --files-without-match :Print name of files with no match\n"
		"\t\t-l, --files-with-match :print name of files with match\n"
		"\t\t-c=max, --max-count=num :Search first max lines of file\n"
		"\t\t--color= :highlight color, avaliable R - red, B - Blue, M - magenta, N - no color\n"
		"\t\t--no_color :No color\n"
		"\t\tWIP\n";
	printf("%s", help);
}
char *color(int enable){
	char *red = "\x1B[31m", *blue = "\x1B[34m", *mag = "\x1B[35m", *norm = "\x1B[0m", *not = "";
	char *fname = "\x1B[32m";
	if(color_enable){
		if(enable == filenamecoloron)//Filename color
			return fname;
		else if(enable == filenamecoloroff)
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
		matches = 0;// Matches per file 
		arquivo_atual = fopen(param, "r");// open file
		if(param == NULL) arquivo_atual = stdin;// if NULL read stdin
		if (arquivo_atual == NULL){// if cant open
			printf("CAN'T OPEN %s\n", param);
			return;
		}
		long linec = 0;
		for (int i = 0; fgets(line, 123456, arquivo_atual) != NULL; ++i){
			long linepos = 0;
			char *posi = strstr(line, patern);
			if (posi != NULL){
				if (file_name){
					if(echonfind)
						printf("%s%s %d:%ld:%s ", color(filenamecoloron), param, (i + 1), posi - line + 1, color(filenamecoloroff));
				}
				//Split ocorences and COLOR
				while(posi != NULL){// Split to insert color
					matches++;// count ocorences
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
					if (echonfind)
						printf("%s%s%s%s", pt[0], color(1), pt[1], color(0));
					posi = strstr(line + linepos, patern);
				}
				if (echonfind)
					printf("%s", pt[2]); //Print end
			}
			linec++;//line count
			if(maxlines > 0 && linec >= maxlines) break;//stop afet max lines
		}
		fclose(arquivo_atual);
}
void files_with_without_matches(int with, char *file){
	if(with){
		if(matches || listcount){
			printf("%s%s%s", color(filenamecoloron), file, color(filenamecoloroff));//print match
			if(listcount) printf(":%d", matches);//print count
			printf("\n");//LF
		}
	}else{
		if(!matches){
			printf("%s%s%s\n", color(filenamecoloron), file, color(filenamecoloroff));
		}
	}
}
/////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]){	// patern File1 ... Filen
									//	arg1	arg2	arg(argc-1)
	int params = 0, stop = 0;

	while(params + 1 < argc && argv[1+params][0] == '-'){// le parametros
		if (strcmp(argv[1 + params], "--help") == 0 || strcmp(argv[1 + params], "-?") == 0){
			help(0);													  //Help
			stop = 1;//Dont run
		}
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
		else if(strcmp(argv[1+params], "-l") == 0 || strcmp(argv[1+params],"--files-with-match") == 0){
			echonfind = 0;
			listwith = 1;
		}else if(strcmp(argv[1+params], "-L") == 0 || strcmp(argv[1+params],"--files-without-match") == 0){
			echonfind = 0;
			listwith = 0;
		}
		else if(strcmp(argv[1+params], "-c") == 0 || strcmp(argv[1+params],"--count") == 0){
			echonfind = 0;
			listwith = listcount = 1;
		}
		else if(strncmp(argv[1+params], "-m=num", 3) == 0 || strncmp(argv[1+params],"--max-count=num", 12) == 0){
			sscanf(argv[1 + params], "%*[^=]%*c%d", &maxlines);
			printf("MAXL%d %s\n", maxlines, argv[1 + params]);
		}
		else invalid = 1;//Invalid option
		params++;
	}

	int first_file = 2 + params, file_count = -first_file +argc;
	if(file_name == -1){// if not defined
		if(file_count > 1) file_name = 1; //if multiple files
		else file_name = 0; //if single
	}
	if(stop) return 0;// if true stop
	if(argc < 2) invalid = 1;
	if(invalid && !helped){// argumentos invalidos
		printf("USAGE: %s [option] \"patern\"  File[1] ... File[n]\nUSAGE: %s -? for help\n", argv[0], argv[0]);
		return 0;
	}
	char *find = argv[1+params];
	for(int i = first_file; i < argc; ++i){
		busca_no_arquivo(find, argv[i]);
		if(listwith != -1) files_with_without_matches(listwith, argv[i]);
	}
	if(!file_count)
		busca_no_arquivo(find, NULL);
}