/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : A4
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : Parser.h
* Deskripsi : Header yang berisi fungsi untuk melakukan parsing text file
*/
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

void lookup(char filename[], int n){
    int count_iteration; // Acuan aksi dalam iterasi
    char buffer[100]; // Menampung token parsing
    int count_words; // Menampung jumlah kata dalam file input
    int len; // Menampung panjang token
    char* temp_pointer; // Memperbaiki token jika ada ganti baris

    FILE *fp;
    count_iteration = 0;
    count_words = 0;
    struct Node* last = (struct Node*)malloc(sizeof(struct Node));
    struct Node* jalanjalan = (struct Node*)malloc(sizeof(struct Node));
    last = NULL;
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("File tidak ditemukan!\n");
        printf("PROGRAM SELESAI!\n");
        exit(0);
    }
    else{
    fclose(fp);
    while (count_iteration <= n){
        fp = fopen(filename, "r");
        count_iteration += 1;
        if (count_iteration == 1){
            while(fgets(buffer, 100, fp) != NULL) //Ambil baris per baris
                {
                char* token = strtok(buffer, " "); //Ambil token pada baris tsb.
                while (token != NULL) //Apabila ada
                {
                    len = strlen(token); // Cek panjang token
                    if (strcmp(token+len-1, "\n") != 0)
                    {
                        push_initkey(&last, token); // Push ke CLL
                        jalanjalan = last; // Update jalan" karena last juga berubah
                        count_words += 1; // Jumlah kata + 1
                    }
                    else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                    {
                        temp_pointer = strchr(token,'\n');
                        *temp_pointer = '\0';
                        push_initkey(&last, token);
                        jalanjalan = last;
                        count_words += 1;
                    }
                    token = strtok(NULL, " ");
                }
            }
        }
        else if ((count_iteration > 1) && (count_iteration <= n)){
            while (fgets(buffer, 100, fp) != NULL){
                char *token = strtok(buffer, " ");
                while (token != NULL){
                    len = strlen(token);
                    if (strcmp(token + len - 1, "\n") != 0){
                        concat_key(&jalanjalan, token);
                    }
                    else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                    {
                        temp_pointer = strchr(token,'\n');
                        *temp_pointer = '\0';
                        concat_key(&jalanjalan, token);
                    }
                    token = strtok(NULL, " ");
            }
        }
        jalanjalan = jalanjalan->prev;
        }
        else {
            while (fgets(buffer, 100, fp) != NULL){
                char *token = strtok(buffer, " ");
                while (token != NULL){
                    len = strlen(token);
                    if (strcmp(token + len - 1, "\n") != 0)
                    {
                    add_value(&jalanjalan, token);
                    }
                    else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                    {
                        temp_pointer = strchr(token,'\n');
                        *temp_pointer = '\0';
                        add_value(&jalanjalan, token);
                    }
                    token = strtok(NULL, " ");
            }
        }

    }
    fclose(fp);
    }
    //printList(last); // Testing print LookupTable
    }
    return;
}


