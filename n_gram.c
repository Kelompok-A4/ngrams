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
int count_iteration; // Acuan aksi dalam iterasi
int count_words; // Menampung jumlah kata dalam file input
int len; // Menampung panjang token
char* temp_pointer; // Memperbaiki token jika ada ganti baris

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
    int n; // Menampung nilai n
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
    printf("Masukan nilai n :");
    scanf("%d", &n);
    FILE *fp;
    count_iteration = 0;
    count_words = 0;
    struct Node* last = NULL;
    struct Node* jalanjalan;
    while (count_iteration <= n){
        count_iteration += 1;
        fp = fopen(filename, "r");
        if (count_iteration == 1){
            while(fgets(buffer, 100, fp) != NULL) //Ambil baris per baris
                {
                char* token = strtok(buffer, " "); //Ambil token pada baris tsb.
                while (token != NULL) //Apabila ada
                {
                    len = strlen(token); // Cek panjang token
                    if (strcmp(token+len-1, "\n") != 0)
                    {
                        push_initkey(&last, token); // Push ke CLL
                        jalanjalan = last; // Update jalan" karena last juga berubah
                        count_words += 1; // Jumlah kata + 1
                    }
                    else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                    {
                        temp_pointer = strchr(token,'\n');
                        *temp_pointer = '\0';
                        push_initkey(&last, token);
                        jalanjalan = last;
                        count_words += 1;
                    }
                    token = strtok(NULL, " ");
                }
            }
        }
        else if ((count_iteration > 1) && (count_iteration <= n)){
            while (fgets(buffer, 100, fp) != NULL){
                char *token = strtok(buffer, " ");
                while (token != NULL){
                    len = strlen(token);
                    if (strcmp(token + len - 1, "\n") != 0){
                        concat_key(&jalanjalan, token);
                    }
                    else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                    {
                        temp_pointer = strchr(token,'\n');
                        *temp_pointer = '\0';
                        concat_key(&jalanjalan, token);
                    }
                    token = strtok(NULL, " ");
            }
        }
        jalanjalan = jalanjalan->prev;
        }
        else {
            while (fgets(buffer, 100, fp) != NULL){
                char *token = strtok(buffer, " ");
                while (token != NULL){
                    len = strlen(token);
                    if (strcmp(token + len - 1, "\n") != 0)
                    {
                    add_value(&jalanjalan, token);
                    }
                    else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                    {
                        temp_pointer = strchr(token,'\n');
                        *temp_pointer = '\0';
                        add_value(&jalanjalan, token);
                    }
                    token = strtok(NULL, " ");
            }
        }

    }
    fclose(fp);
    }
    printList(last); // Testing print LookupTable
    return 0;
}
