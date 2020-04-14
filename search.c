#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[15];
    struct Node *next;
};

//Fungsi untuk mencari kesamaan antara dua linked list
//Ada nama1 dan nama2 agar nama user dapat di print pada fungsi ini
void findList(struct Node* first, struct Node* second, char nama1[20], char nama2[20]) 
{ 
    //Deklarasu variable
    int index1 = 1; //Index user 1
    int index2 = 1; //Index user 2
    int found = 0;  //Boolean untuk melihat jika ada kesamaan
    struct Node* ptr1 = first; // linked list user 1
    struct Node*ptr2 = second; // linked list user 2
  
    //Program mulai dengan linked list user 2 
    //lalu menjalankan linked list user 1 (index user 1 naik)
    //sampai linked list user 1 mencapai akhir.
    //Saat linked list user 1 akhir, linked list user 2 jalan (index naik)
    while (second != NULL) 
    { 
        //inisiasi linked list
        ptr2 = second; 
        while (ptr1 != NULL) 
        { 
            if (!strcmp(ptr1->data,ptr2->data)) //jika data linked list sama
            { 
                printf("Hewan yang sama: ");
                printf("%s\n", ptr1->data);
                printf("Ditemukan di indeks: %d dari hewan milik %s dan %d dari hewan milik %s\n\n\n", index1, nama1, index2, nama2);
                //Linked list user 1 naik 1 index
                ptr1 = ptr1->next; 
                index1++; 
                found = 1; //Variable found jadi true
            } 
            else  //Linked list user 1 naik 1 index
            {
                ptr1 = ptr1->next; 
                index1++;
            } 
        } 
        //Jika linked list user 1 nyampe akhir
        if (ptr1 == NULL) {
        //inisiasi linked list
        ptr1 = first; 

        //index linked list user 1 reset
        index1= 1;

        //linked list user 2 naik 1 index
        second = second->next; 
        index2++;
        }
    } 
    //Kondisi jika tidak ditemukan kesamaan
    if (found == 0){
        printf("Tidak ditemukan hewan yang sama");
    }
    return; 
} 

/* Checks whether the value x is present in linked list */
void search(struct Node* head, int x) 
{ 
    struct Node* current = head;  // Initialize current 
    while (current != NULL) 
    { 
        if (strcmp(current->data, x)){ 
            return 1; 
        }
        current = current->next; 
    } 
    return 0; 
} 