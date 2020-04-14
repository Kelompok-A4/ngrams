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
