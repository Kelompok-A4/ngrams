/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : A4
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : Parser.h
* Deskripsi : Header yang berisi fungsi untuk melakukan randomization
*/
#include <stdlib.h>
#include <stdio.h>
  
struct Node *RandomValue(struct Node *head, int word_count){ 
    int n_random = (rand() % (word_count + 1)); // merandom head keberapa
    //struct Node *current = head;

    // Jika list kosong
    if (head == NULL) 
       return 0; 
    int n;
    // Iterasi head ke head yang telah dirandom
    for (n=0; n<=n_random; n++) { 
           head = head->next; 
    } 
    return head; 
}         
