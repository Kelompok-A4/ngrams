/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : A4
* Hari dan Tanggal : Kamis, 17 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : random.h
* Deskripsi : Fungsi berisi Randomization, search, dan output
*/

#include <stdlib.h>
#include <stdio.h>

//Fungsi untuk mengrandom nilai head yang akan digunakan
struct Node* RandomValue(struct Node **head){ 
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
    return *head;
}
// Fungsi ini untuk mencari sebuah kata dalam linked list dan copy data linked list yang mempunyai kata tersebut kedalam linked list baru. 
struct Node* search(struct Node *head, char word[])
{
    struct Node *current = head;
    struct Node *searched = NULL;
    char delimiter[] = " ";
    char *firstWord, *secondWord, *remainder, *context;
    do 
    {
        int inputLength = strlen(current->key);
        char *inputCopy = (char*) calloc(inputLength + 1, sizeof(char));
        strncpy(inputCopy, current->key, inputLength);

        firstWord = strtok_r (inputCopy, delimiter, &context);
        secondWord = strtok_r (NULL, delimiter, &context);
        remainder = context;
		if (current == NULL){
			return head;
        }
		
		if (!(strcmp(firstWord, word))){
            push_initkey(&searched, current->key);
            add_value(&searched, current->value);
       }
        current = current->next;
        free(inputCopy);

        if (current == head){
            free(inputCopy);
            return searched;
        }
    } while (current != head);

    // Jika tidak ditemukan
   return head;
}

//Fungsi untuk mengeprint kata yang telah dirandom sesuai dengan jumlah yang telah diminta
void printOutput(struct Node *head, int word_count, int n){
    int count = n;
    struct Node *temp = head;
    struct Node *searched = NULL;
    char delimiter[] = " ";
    char *firstWord, *context;
    printf("... %s ", temp -> key);
    if (n != word_count){
    while(count < word_count){
        searched = search(temp, temp->value);
        RandomValue(&searched);
         if (word_count - count == 1){
            int inputLength = strlen(searched->key);
            char *inputCopy = (char*) calloc(inputLength + 1, sizeof(char));
            strncpy(inputCopy, searched->key, inputLength);

            firstWord = strtok_r (inputCopy, delimiter, &context);
            printf("%s ", firstWord);
        }
        else{
        printf("%s ", searched->key);
        }
        while((strcmp(temp->key,searched->key))){
            temp = temp->next;
        }
       
        count += n;
    }
    }
    printf("...\n");
}

