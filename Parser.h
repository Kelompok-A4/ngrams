struct Node // Struktur data yang merupakan basis struktur LookUpTabel
{
    char key[100];
    char value[100];
    struct Node *next;
    struct Node *prev;
};

/*
struct little_node // Struktur data yang menyimpan value
{
    char value [100];
    struct little_node *next;
    struct little_node *prev;
};
*/

// Fungsi untuk push kata-kata sebagai key dalam CLL
struct Node* push_initkey(struct Node **last_reff, char data [100]){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        if (*last_reff == NULL){ // Kondisi apabila CLL masih kosong
            strcpy(temp->key,"\0");
            strcat(temp->key, data); // Masukan data
            *last_reff = temp; // Mengubah pointer last
            (*last_reff)->next = (*last_reff); // Next akan merujuk ke dirinya sendiri
            (*last_reff)->prev = (*last_reff); // Prev akan merujuk ke dirinya sendiri juga
            return (*last_reff); // Mengembalikan pointer last yang telah di-up
        }
        else{   // Kalo CLL udah ada isi
            strcpy(temp->key,"\0");
            strcat(temp->key, data); // Masukan data
            temp -> next = (*last_reff)->next; // Next dari temp akan merujuk ke next dari last yg blom diupdate
            ((*last_reff)->next)->prev = temp;
            temp -> prev = (*last_reff); // prev dari temp akan merujuk ke last yang lama
            (*last_reff)->next = temp; //next dari pointer last akan di-up merujuk ke temp
            (*last_reff) = temp; //jadikan temp sebagai last yang baru
            return (*last_reff); // Mengembalikan pointer last yang telah di-up
        }
};

// Fungsi untuk melengkapi key
void concat_key(struct Node **last_reff, char data [100])
{
    struct Node *temp = *last_reff;
    if (*last_reff != NULL)
    {

        strcat((*last_reff)->key, " ");
        strcat((*last_reff)->key, data);
        *last_reff = (*last_reff)->next;
    }
};

// Fungsi untuk menentukan value
void add_value(struct Node **last_reff, char data [100])
{
    struct Node *temp = *last_reff;
    if (*last_reff != NULL)
    {
            strcpy((*last_reff)->value,"\0");
            strcat((*last_reff)->value, data);
            *last_reff = (*last_reff)->next;
    }
};

void printList(struct Node *first)
{
    struct Node *temp = first;

    // If linked list is not empty
    if (first != NULL)
    {
        // Keep printing nodes till we reach the first node again
        do
        {
            printf("%s | %s\n", temp->key, temp->value);
            temp = temp->next;
        }
        while (temp != first);
    }
}


