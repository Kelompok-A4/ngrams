/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : A4
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : Parser.h
* Deskripsi : Main file 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Parser.h"
#include "random.h"

// Variabel
int main(){
    char filename [100]; // Menampung nama file external
    int n; // Menampung nilai n
    int current_menu = 1;
    int go = 1;
    char choice1, choice2;
    printf("Judul:\n");
    printf("N-Gram based Random Text Generator\n");
    printf("\n");
    printf("Deskripsi:\n");
    printf("Program ini akan membuat string dari kata-kata yang random.\n");
    printf("String yang dihasilkan akan memiliki gaya penulisan yang cukup mirip\n");
    printf("dengan gaya penulisan manusia.");
    printf("\n\n");
    do{
    switch(current_menu)
    {
        case 1 :
            printf("Masukan nama file eksternal:");
            scanf(" %[^\n]s ",filename);
            printf("Masukan nilai n :");
            scanf("%d", &n);
            lookup(filename, n);
            current_menu = 2;
            break;

        case 2:
            printf("Masukkan Jumlah kata yang diinginkan:\n");
            //input jumlah kata
            current_menu = 3;
            break;

        case 3 :
            printf("this is output\n");
            //output  
            current_menu = 4;
            break;
        
        case 4:
            printf("Program Selesai!\n");
            printf("Apakah anda ingin mencoba lagi dengan jumlah kata yang berbeda? (Y/N)");
            scanf(" %c", &choice1);
            if (choice1 == 'Y'){
                current_menu = 2;
                break;
            }
            else if(choice1 == 'N'){
                current_menu = 5;
                break;
            }
            else{
                printf("Input tidak valid!");
                current_menu = 4;
                break;
            }

        case 5:
            printf("Apakah anda ingin mencoba lagi dengan file yang berbeda? (Y/N)");
            scanf(" %c", &choice1);
            if (choice1 == 'Y'){
                current_menu = 1;
                break;
            }
            else if(choice1 == 'N'){
                printf("Terimakasih!");
                go = 0;
                exit(0);
                break;
            }
            else{
                printf("Input tidak valid!");
                current_menu = 5;
                break;
            }
        }
    }while(go =1);
    return 0;
}
    



