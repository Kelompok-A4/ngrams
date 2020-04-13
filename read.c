#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char N[100][20];
int H[100];
int main(){
    FILE* fptr;
    char filename[20];
    char name[20];
    char buff[1024];
    char *field;
    int word_count = 0;
    int index; 
    int n;

    printf("Masukkan nama file: ");
    scanf("%s", filename);
    printf("Masukkan nama pelanggan yang ingin dicari: ");
    scanf("%d", n);
    fptr = fopen(filename, "r");
    if(fptr == NULL) {
        printf("File tidak ditemukan!");
        exit(1);  
    }
    while (fgets(buff, 1024, fptr) != NULL){
        word_count=0;                                 
        field = strtok(buff, " ");                      
        while (field) {                                 
            strcpy(N[word_count],field);
            word_count++;
        }
        word_count++;
    }
}