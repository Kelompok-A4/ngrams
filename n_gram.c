#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Parser.h"

// Source
// https://www.geeksforgeeks.org/circular-singly-linked-list-insertion/
// https://www.geeksforgeeks.org/circular-linked-list-set-2-traversal/

// Variabel
char filename [100]; // Menampung nama file external
char buffer[100]; // Menampung token parsing
int n; // Menampung nilai n
int count; //
// Lookup table diimplementasikan dengan Linked List
/*
struct Node
{
    char key[100];
    char value[100];
    struct Node *next;
    struct Node *prev;
};
*/

int main(){
    printf("Judul:\n");
    printf("N-Gram based Random Text Generator\n");
    printf("\n");
    printf("Deskripsi:\n");
    printf("Program ini akan membuat string dari kata-kata yang random.\n");
    printf("String yang dihasilkan akan memiliki gaya penulisan yang cukup mirip\n");
    printf("dengan gaya penulisan manusia.");
    printf("\n\n");
    printf("Masukan nama file eksternal:");
    gets(filename);
    printf("Masukan nilai n");
    FILE *fp;
    fp = fopen(filename, "r");
    struct Node* last = NULL;

    /*
    fgets(buffer, 100, fp);
    printf("%s", buffer);
    fclose(fp);
    */

}
