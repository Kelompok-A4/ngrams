#include<stdio.h> 
#include<stdlib.h> 

// Fungsi random value agar head gerak dari tempat yang random
struct Node 
{ 
    char key[100];
    char value[100];
    struct Node *next;
    struct Node *prev;; 
}; 
  
struct node RandomValue(struct Node *head, int n_kata){ 
    int n_random = (rand() % (n_kata + 1)); // merandom head keberapa
    struct node *curr_node = head;

    // Jika list kosong
    if (head == NULL) 
       return; 
    // menginisialisasi node pertama
    char result = head->key; 
    int n;
    // Iterasi head ke head yang telah dirandom
    for (n=0; n = n_random; n++) { 
           head = curr_node->next; 
    } 
    return head; 
} 
