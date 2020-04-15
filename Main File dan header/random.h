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