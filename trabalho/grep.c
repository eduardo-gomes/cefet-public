#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
//#include <errno.h>
#define qqcoisa "*"
#define LINESZ 123456
#define filenamecoloron 'H'
#define filenamecoloroff 'h'
FILE *arquivo_atual;
int file_name = -1, on_line = -1, invalid = 0, helped = 0, prt_color = 'R', color_enable = 0, echonfind = 1, listwith = -1, listcount = 0, maxlines = -1, out_mode = 0/*0 = stdout, 1 = file with random name*/, case_sensitive = 1, file_without = 0, tcount = 0;
long long  matches = 0, allmatches = 0;
/////////////////////////////////////////////////////////////////////////
///////////////////////////// Define default ////////////////////////////
void load_du(){
	color_enable = 1;
	file_name = on_line = 1;
	//case_sensitive = 0;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////// TO PRINT ////////////////////////////////
void help(int type){//HELP
	helped = 1;
	char *version = \
		"Du grep 0.1.1	 © All rights reserved";//nope
	char *help =
		"USAGE: Dugrep [option] \"patern\"  File[1] ... File[n]\n"
		"USAGE: Dugrep [option] \"patern\" For standard input\n"
		"Dugrep --help for details\n"
		"\n"
		"\tOptions:\n"
		"\t\t-?, --help :Show this\n"
		"\t\t-v : Display version\n"
		"\t\t-H, --with-filename :Show File name, line and col first patern found (Default with multiple files)\n"
		"\t\t-h, --no-filename :Dont File name, line and col first patern found (Default with single file)\n"
		"\t\t-c, --count : print number of mathes per file\n"
		"\t\t-L, --files-without-match :Print name of files with no match\n"
		"\t\t-l, --files-with-match :print name of files with match\n"
		"\t\t-n, --line :print number of line, (Default with multiple files)\n"
		"\t\t-i, --case_insensitive :do search case insensitive(Default off)\n"
		"\t\t-d, --duplicate-without :create a copy of the file without all matches nammed old_file_TIMESTAMP"
		"\t\t--total-count :display number of matches\n"
		"\t\t--echo :to use after --total-count to display on found\n"
		"\t\t-m=max, --max-count=num :Search first max lines of file\n"
		"\t\t--color= :highlight color, avaliable R - red, B - Blue, M - magenta, N - no color\n"
		"\t\t--no_color :No color\n"
		"\t\tWIP\n";
	if(type == 'v'){
		printf("%s\n", version);
	}else{
		printf("%s", help);
	}
}
char *color(int enable){
	char *red = "\x1B[31m\x1B[1m", *blue = "\x1B[34m\x1B[1m", *mag = "\x1B[35m\x1B[1m", *norm = "\x1B[0m", *not = "";
	char *fname = "\x1B[32m";
	if(color_enable && !out_mode){//Dont print color command if
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
////////////////////////////// malloc size //////////////////////////////
///(pointer to pointer that will change, pointer to actual size, to size)
void change_to(char **var, unsigned long *atu, unsigned long to){
	if(*atu <= to){
		*atu = to*2;
		//printf("%p to %lu %lu\n", *var, *atu, to);
		char *old = *var;
		*var = realloc(*var, *atu);
		if(var == NULL){
			*var = old;
			printf("CAN'T REALLOC\n");
		}
	}else return;
}
void pt_change(char **pt, unsigned long *atu, unsigned int to){
	if(*atu <= to){
		*atu = to*2;
		for(int i = 0; i < 3; ++i){
			char *ptbackup = pt[i];
			//printf("%d st, to %lu\n", i, *atu);
			ptbackup = realloc(ptbackup, *atu);
			//printf("%d ed, to %lu\n", i, *atu);
			if(ptbackup)pt[i] = ptbackup;
		}
	}
}
/////////////////////////////////////////////////////////////////////////
////////////////////////////// dir or file //////////////////////////////
void chama_busca(char* , char*);
void se_dir_open(char *find, char* diretorio){
	DIR* dir = opendir(diretorio);//Pointer to dir
	struct dirent *direntry;//Pointer to something inside dir
	//char arquivo[123456];//string of directory/file
	unsigned long arquivo_sz = 16;
	char *arquivo = malloc(arquivo_sz);
	if (dir != NULL){//If is directory
		//arquivo[0] = '\0';//"Clear" string
		//strcpy(arquivo, diretorio);//Set arquivo dir
		//arquivo[strlen(diretorio)] = '/';// add / do open dir+/+file
		//arquivo[strlen(diretorio)+1] = '\0';//Replace EOL
		size_t dr_sz = strlen(diretorio);
		change_to(&arquivo, &arquivo_sz, dr_sz);// Change arquivo size
		sprintf(arquivo, "%s/", diretorio);
		size_t cont = strlen(arquivo);//Pointer to end of directory on string
		while((direntry = readdir(dir)) != NULL){// If has something inside
			if(strcmp(direntry->d_name, ".") == 0 || strcmp(direntry->d_name, "..") == 0) continue;//skip (go to upper level and loop), "." ".."
			change_to(&arquivo, &arquivo_sz, dr_sz + strlen(direntry->d_name));					   // Change arquivo size
			strcpy(arquivo + cont, direntry->d_name);//Add file found to arquivo
			//printf("%s %lu\n", arquivo, cont);
			se_dir_open(find, arquivo);//Recursion
			//cont[0] = '\0'; //To continue from here
		}
		closedir(dir);
	}else{//if isn't dir or don exist try to open as file
		chama_busca(find, diretorio);
		//printf("FILE %s\n", arquivo);
	}
	free(arquivo);
}
FILE *output;
void open_without(char *address, int open){
	if(open){
		char nfilename[1234];
		double tatu = time(NULL);
		sprintf(nfilename, "%s_%.lf", address, tatu);
		output = fopen(nfilename, "a");
	}else{
		fclose(output);
	}
}
void write_without(char *toprint){
	fprintf(output, "%s", toprint);
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////// TO SEARCH ///////////////////////////////
char *strcase(const char *st, const char *fd){
	if(case_sensitive) return strstr(st, fd);
	return strcasestr(st, fd);
}
typedef struct found_data{
	char *posi;
	long long size;
}found_data;
found_data simple_search(const char *str, const char *find){
	found_data to_return;
	char *newfind = malloc(strlen(find) * sizeof(char) + 2);// +2 to \n + free
	strcpy(newfind, find);//copy data to avoid alteration
	char *ate = strtok(newfind, qqcoisa);//pointer to the start of newfind ending on qqcoisa
	//printf("%s\n",ate);
	char *searching = strcase(str, ate); //where to resume search, starting with first token
	//printf("%p\n", searching);
	to_return.posi = searching;//start of match
	unsigned long long szlastok = 0, sz = (unsigned long long)searching;//to calc length
	//printf("HERE\n");
	if(searching != NULL){//if find first continue
		do{
			searching = strcase(searching + szlastok, ate);//continue search
			//printf("(%s::%s)\n", searching, ate);
			//printf("HERE4\n");
			szlastok = strlen(ate);// update before changing
			ate = strtok(NULL, qqcoisa);//update token
			//printf("%p\n", ate);
		}while(ate != NULL && searching != NULL && *ate != '\n'/*if end*/);// continue if token continue and find
	}
	//printf("HERE3\n");
	to_return.size = (unsigned long long)(searching + szlastok) - sz; // update size
	if(searching == NULL){
		to_return.posi = NULL;//Return null if don't match
		to_return.size = 0;
		//printf("NOT\n");
	}//else printf("FUNCIONAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	//printf("END\n");
	free(newfind);
	return to_return;
}
void busca_no_arquivo(char *patern, char* param){ //search and print on patern found
		unsigned long long patern_len = strlen(patern);//Will be modified by search with '*'
		//char line[LINESZ], pt[3][LINESZ];
		size_t line_sz = 16, pt_sz = 16, ptorew, pt_to;
		char *line = malloc(line_sz), *pt[3] = {malloc(pt_sz), malloc(pt_sz), malloc(pt_sz)};
		found_data tmp;//var to save return of search
		matches = 0;// Matches per file
		arquivo_atual = fopen(param, "r");// open file
		if(param == NULL) arquivo_atual = stdin;// if NULL read stdin
		if (arquivo_atual == NULL){// if cant open
			printf("CAN'T OPEN %s\n", param);
			return;
		}
		if(file_without)
			open_without(param, 1); //Open file to write
		// fseek(arquivo_atual, ftell(arquivo_atual), SEEK_END);
		// line_sz = ftell(arquivo_atual);
		// printf("LSZ %lu\n", line_sz*2);
		// line = realloc(line, line_sz * 2);
		// rewind(arquivo_atual);
		//printf("HERE\n");
		ptorew = ftell(arquivo_atual);
		fscanf(arquivo_atual, "%*[^\n]%*c");
		pt_to = ftell(arquivo_atual) - ptorew;
		fseek(arquivo_atual, ptorew, SEEK_SET);
		pt_change((char **)pt, &pt_sz, line_sz);//pt_to);
		//printf("HERE2\n");
		for (int i = 0; fgets(line, line_sz-1, arquivo_atual) != NULL; ++i){
			long linepos = 0;
			tmp = simple_search(line, patern);
			patern_len = tmp.size;//update size
			char *posi = tmp.posi;//strstr(line, patern);//first match
			if (posi != NULL){//Found on this line
				if (echonfind){//if need to print filename
					if(file_name)//if print somefing
						printf("%s%s:%s ", color(filenamecoloron), param, color(filenamecoloroff));
					if(on_line)
						printf("%s%d:%s ", color(filenamecoloron), (i + 1), color(filenamecoloroff));
				}
				//Split ocorences and COLOR
				while(posi != NULL){// Split to insert color
					matches++;// count ocorences
					//printf("HERE\n");
					////////////pt_change((char**)pt, &pt_sz, strlen(line));// first realloc
					//Copy str before
					//memcpy(pt[0], line + linepos, sizeof(char) * ( posi - line - linepos));
					strncpy(pt[0], line + linepos, posi - line - linepos);
					//Add EOL //strncpy 
					//pt[0][posi - line - linepos] = '\0';
					linepos = posi - line;//New linepos, before patern
					//Copy patern
					//memcpy(pt[1], line + linepos, sizeof(char) * patern_len);
					strncpy(pt[1], line + linepos, patern_len);
					//add EOL
					//pt[1][patern_len] = 0;
					linepos += patern_len;//New linepos, after patern
					//Copy rest of line
					//memcpy(pt[2], line + linepos , sizeof(char) * (strlen(line + linepos) + 1));
					strcpy(pt[2], line + linepos);
					//add EOL
					//pt[2][strlen(line + linepos) + 1] = 0;//Fixed bug last thar dont show
					//Print with color
					if (echonfind)
						printf("%s%s%s%s", pt[0], color(1), pt[1], color(0));
					if(file_without)//If want to print file without match
						write_without(pt[0]);//Write before
					tmp = simple_search(line + linepos, patern);
					patern_len = tmp.size;//update size
					posi = tmp.posi;//strstr(line + linepos, patern);
				}
				if (echonfind)
					printf("%s", pt[2]); //Print end
				if(file_without)//Write after
					write_without(pt[2]);
			}else{//Not found
				//printf("HERE NFO\n");
				if (file_without) //Write line
					write_without(line);
			}
			if(maxlines > 0 && i+1 >= maxlines) break;//stop afet max lines
			//printf("HERE3\n");
			// ptorew = ftell(arquivo_atual);
			// if(fscanf(arquivo_atual, "%*[^\n]%*c") != EOF){
			// 	//printf("HERE5\n");
			// 	pt_to = ftell(arquivo_atual) - ptorew;
			// 	//printf("HERE6, %p, %lu %lu\n", pt, pt_sz, pt_to);
			// 	pt_change((char **)pt, &pt_sz, pt_to);
			// 	//printf("HERE7\n");
			// }
			// fseek(arquivo_atual, ptorew, SEEK_SET);
			//printf("HERE4\n");
		}
		//printf("HERE NFO 2\n");
		if (file_without)
			open_without(NULL, 0); //Close file to write
		//printf("HERE NFO 3 %p\n", arquivo_atual);
		fclose(arquivo_atual);
		free(line);
		for(int i = 0; i < 3; ++i)
			free(pt[i]);
		//printf("HERE NFO 4\n");
		allmatches += matches;//Count all matches
}
void files_with_without_matches(int with, char *file){
	if(with){
		if(matches || listcount){
			printf("%s%s%s", color(filenamecoloron), file, color(filenamecoloroff));//print match
			if(listcount) printf(":%lld", matches);//print count
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
	load_du();
	//system("ls > 0.txt");
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
		else if(strcmp(argv[1+params], "--version") == 0 || strcmp(argv[1+params], "-v") == 0){//Print version
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
		}else if(strcmp(argv[1+params], "-n") == 0 || strcmp(argv[1+params],"--line") == 0){
			on_line = 1;
		}else if(strcmp(argv[1+params], "-i") == 0 || strcmp(argv[1+params],"--case_insensitive") == 0){
			case_sensitive = 0;
		}else if(strcmp(argv[1+params], "-d") == 0 || strcmp(argv[1+params],"--duplicate-without") == 0){//--total-count
			file_without = 1;
		}else if(strcmp(argv[1+params], "--total-count") == 0){
			echonfind = 0;
			tcount = 1;
		}else if(strcmp(argv[1+params], "--echo") == 0){
			echonfind = 1;
		}
		else invalid = 1;//Invalid option
		params++;
	}

	int first_file = 2 + params, file_count = -first_file +argc;
	if(file_name == -1){// if not defined
		if(file_count > 1) file_name = 1; //if multiple files
		else file_name = 0; //if single
	}
	if(on_line == -1){// if not defined
		on_line = file_name;
	}
	if(stop) return 0;// if true stop
	if(argc < 2) invalid = 1;
	if(invalid && !helped){// argumentos invalidos
		printf("USAGE: %s [option] \"patern\"  File[1] ... File[n]\nUSAGE: %s -? for help\n", argv[0], argv[0]);
		return 0;
	}
	char *find = argv[1+params];
	for(int i = first_file; i < argc; ++i){
		se_dir_open(find, argv[i]);
		//busca_no_arquivo(find, argv[i]);
		//if(listwith != -1) files_with_without_matches(listwith, argv[i]);
	}
	if(!file_count)
		busca_no_arquivo(find, NULL);
	if(tcount){
		printf("found %llu\n", allmatches);
	}
}
void chama_busca(char* find, char* argv){
	busca_no_arquivo(find, argv);
	if(listwith != -1) files_with_without_matches(listwith, argv);
}
