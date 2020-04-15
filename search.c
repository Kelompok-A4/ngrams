/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : A4
* Hari dan Tanggal : Selasa, 14 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : search.c
* Deskripsi : Implementasi search character dalam linked list
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[15];
    struct Node *next;
};

/* Fungsi untuk mencari character dalam linked list*/
void search(struct Node* head, int x) 
{ 
    struct Node* current = head;  
    while (current != NULL) 
    { 
        if (strcmp(current->data, x)){ 
            return 1; 
        }
        current = current->next; 
    } 
    return 0; 
} 
