#include <stdio.h>
#include <stdlib.h>

float jam1[6]= {0,12.00, 14.00, 16.00, 20.00, 22.00};
float jam2[6]= {0,12.30, 14.30, 16.30, 20.30, 22.30};
float harga_tiket[3]={50.000, 75.000, 100.000};
int tanggal, film, jamtayang, tiket, kursi[40];


void main();
void menu_customer();
void pemesanan();
//void riwayat_transaksi();
void keluar();

void intro(){

    printf("\n\t==================================================");
    printf("\n\t||                Nama Kelompok                 ||");
    printf("\n\t==================================================");
    printf("\n\t||    1. Putu Satria Arya Putra (2305551122)    ||");
    printf("\n\t||    2. Anthony Wisnu Jati     (2305551138)    ||");
    printf("\n\t||    3. Azka Ilham Ramadhani   (2305551171)    ||");
    printf("\n\t==================================================");
    getchar();
    menu_customer();
}

void menu_customer(){
    int menu;
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

void studio1(){

    printf("\t\tMIRACLE IN CELL NO 7");

}

void studio2(){
    printf("PREY FOR THE DEVIL");
}

void studio3(){
    printf("MENCURI RADEN SALEH");
}

void studio4(){
    printf("KKN DI DESA PENARI");
}

void pemesanan(){
    int pilih;
    printf("\n\t=========================================================================\n");
    printf("\n\t\t\t\t\t DIBIOSKOP TI \n");
    printf("\n\t==================================== || =================================");
    printf("\n\t|                                                                       |");
    printf("\n\t|\t\t\t      DAFTAR FILM\t\t\t\t|\n");
    printf("\t|-----------------------------------------------------------------------|\n");
    printf("\t|\t  |\t\t\t|  Senin-Jumat      |   Sabtu-Minggu \t| \n");
    printf("\t| Studio  |         Film\t| --------------------------------------| \n");
    printf("\t|\t  |\t\t\t|  Regular  |  Vip  | Regular  |  Vip   | \n");
    printf("\t|-----------------------------------------------------------------------|\n");
    printf("\t|    1    | MIRACLE IN CELL NO 7|  50.000  | 75.000 | 75.000 | 100.000  | \n");
    printf("\t|    2    | PREY FOR THE DEVIL \t|  50.000  | 75.000 | 75.000 | 100.000  | \n");
    printf("\t|    3    | MENCURI RADEN SALEH |  50.000  | 75.000 | 75.000 | 100.000  |\n");
    printf("\t|    4    | KKN DI DESA PENARI \t|  50.000  | 75.000 | 75.000 | 100.000  |\n");
    printf("\t-------------------------------------------------------------------------\n");
    printf("Pilih Studio Film: ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        studio1();
        break;

    case 2:
        studio2();
        break;

    case 3:
        studio3();
        break;

    case 4:
        studio4();
        break;
    
    default:
        printf("Pilihan TIdak valid");
        break;
    }
}

void keluar(){
    printf("\n\t==========================================================");
    printf("\n\t|                                                        |");
    printf("\n\t|                T E R I M A   K A S I H                 |");
    printf("\n\t|                                                        |");
    printf("\n\t|         ----------SELAMAT MENONTON----------           |");
    printf("\n\t|                                                        |");
    printf("\n\t==========================================================\n\n");
    exit(0);
}

void main(){
    intro();
}
