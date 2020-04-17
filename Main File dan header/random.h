/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : A4
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : random.h
* Deskripsi : Header yang berisi fungsi untuk melakukan Randomization dan Output
*/

#include <stdlib.h>
#include <stdio.h>
  
void RandomValue(struct Node **head){ 
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    int n_random = (rand() % 100); // merandom head keberapa
    //struct Node *current = head;
    temp = *head;

    // Jika list kosong
    if (head != NULL) {
      for (int n=0; n<=n_random; n++){
        }
    }
    int n;
    // Iterasi head ke head yang telah dirandom
    for (n=0; n<=n_random; n++) { 
        *head = temp->next;
         temp = *head;
    }
    *head = temp->next;
}

//Fungsi untuk mengeprint kata yang telah dirandom sesuai dengan jumlah yang telah diminta
void printOutput(struct Node *head, int word_count){
    int count = 1;
    struct Node *temp = head;
    printf("... %s ", temp -> value);
    while(count <= word_count){
        temp = temp->next;
        printf("%s ", temp->value);
        count++;
    }
    printf("...\n");
}

/*void printList2(struct Node *first)
{
    struct Node *temp = first;

    // If linked list is not empty
    if (first != NULL)
    {
        // Keep printing nodes till we reach the first node again
       
            printf("%s\n", temp->value);
    }
}*/
