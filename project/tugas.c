#include <stdio.h>
#include <stdlib.h>

float jam1[6]= {0,12.00, 14.00, 16.00, 20.00, 22.00};
float jam2[6]= {0,12.30, 14.30, 16.30, 20.30, 22.30};
int tanggal, film, jamtayang, tiket, kursi[40];


//void main();
void menu_customer();
void pemesanan();
//void riwayat_transaksi();
void keluar();

void menu_customer(){
    int menu;
    while (menu > 2){
    printf("\n\t=============================================================");
    printf("\n\t||             SELAMAT DATANG DIBIOSKOP TI                 ||");
    printf("\n\t=============================================================");
    printf("\n\t||                  Tampilan Menu                          ||");
    printf("\n\t=============================================================");
    printf("\n\t||  1. Menu Pemesanan Tiket                                ||");
    printf("\n\t||  2. Exit                                                ||");
    printf("\n\t=============================================================");
    printf("\n\t Masukkan Pilihan Anda: ");
    scanf("%d", &menu);
    switch(menu){
            case 1:
            {
                pemesanan();
            break;
            }
            case 2:
            {
                keluar();
            break;
            }
            default:
            {
            printf("Masukkan Angka 1 atau 2");
            break;
            }
        }
    }
}

int main(){
    menu_customer();
    return 0;
}

void pemesanan(){
    printf("\n\t Pemesanan");
}

void keluar(){
    printf("\n\t Keluar");
}