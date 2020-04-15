#include <stdlib.h>
#include <stdio.h>
  
void RandomValue(struct Node **head){ 
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    int n_random = (rand() % 100); // merandom head keberapa
    //struct Node *current = head;
    temp = *head;

    // Jika list kosong
     if (head != NULL) {
       
    // Iterasi head ke head yang telah dirandom
    for (int n=0; n<=n_random; n++){}}
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
