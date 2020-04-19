#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    FILE *fp = fopen("README.md", "a");
    FILE *code;
    char str[50];
    char category[10];
    char file[20];
    char problem[10];
    strcpy(category, argv[1]);
    
    for(int i=2;i<argc;i++){
        if((code = fopen(argv[i],"r"))==NULL){
            printf("cannot open %s", argv[i]);
            break;
        }
        strcpy(file, argv[i]);
        char path[20];
        strcpy(path, file);
        char ext[5];
        char fileName[20];
        strcpy(fileName, file);
        strtok(fileName, ".");
        strcpy(ext, strtok(NULL, "."));
        strcpy(problem, fileName);
        strtok(problem, "/");
        strcpy(problem, strtok(NULL, "/"));
        
        fprintf(fp, "| %s | [BOJ](https://www.acmicpc.net/problem/%s) | [%s.%s](%s) | description |\n", category, problem, problem, ext, path);
    }
    
    fclose(fp);
    fclose(code);
    return 0;
}