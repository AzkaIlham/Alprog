#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_customer();
void genreFilm();
void horor();
void komedi();
void romantis();
void pemesanan();
void keluar();

typedef struct{
    int id;
    char title[50];
    char genre[20];
    int stock;
    float price;
}Movie;

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

    system("cls");
    printf("\n\t===============================================");
    printf("\n\t||        SELAMAT DATANG DIBIOSKOP TI        ||");
    printf("\n\t===============================================");
    printf("\n\t||               Tampilan Menu               ||");
    printf("\n\t===============================================");
    printf("\n\t||  1. Menu Pemesanan Tiket                 ||");
    printf("\n\t||  2. Exit                                 ||");
    printf("\n\t===============================================");
    printf("\n\t Masukkan Pilihan Anda: ");
    scanf("%d", &menu);
    if(menu==1){
        genreFilm();
    }
    else if(menu==2){
        keluar();
    }
    else{
        printf("Eror/n");
    }
}

void genreFilm(){
    int pil;

    printf("\n\t=========================");
    printf("\n\t||     Genre Film      ||");
    printf("\n\t=========================");
    printf("\n\t||   1. Horor          ||");
    printf("\n\t||   2. Komedi         ||");
    printf("\n\t||   3. Romantis       ||");
    printf("\n\t=========================");
    printf("\n\t Masukkan Pilihan Genre Film Anda: ");
    scanf("%d", &pil);
    if(pil==1){
        horor();
    }
    else if(pil==2){
        komedi();
    }
    else if(pil=3){
        romantis();
    }
    else{
        printf("\n\tMasukkan Pilihan Yang Benar");
    }
}

void horor(){
    Movie movies[] = {
        {1, "Conjuring", "Horor", 50, 80000},
        {2, "Annabelle Creation", "Horor", 30, 85000},
        {3, "It", "Horor", 20, 90000},
    };
    pemesanan(movies, 3);
}

void komedi(){
    Movie movies[] = {
        {4, "Friends", "Komedi", 100, 60000},
        {5, "Modern Family", "Komedi", 70, 70000},
        {6, "Curb Your Enthusiasm", "Komedi", 40, 65000},
    };
    pemesanan(movies, 3);
}

void romantis(){
    Movie movies[] = {
        {7, "Pride and Prejudice", "Romantis", 60, 70000},
        {8, "Love Actually", "Romantis", 40, 75000},
        {9, "When Harry Met Sally", "Romantis", 50, 80000},
    };
    pemesanan(movies, 3);
}

void pemesanan(Movie movies[], int jumlah_movie){
    int id_movie, jumlah_tiket, i;
    int cari = 0;
    printf("\n\t==============================");
    printf("\n\t||   Daftar Film yang Tayang ||");
    printf("\n\t==============================");
    printf("\n\t ID | Title               | Genre    | Stock | Price   ");
    printf("\n\t-----------------------------------------------------------------");
    for(i=0; i<jumlah_movie; i++){
        printf("\n\t %d | %s             | %s   |   %d   | Rp. %.2f ",
        movies[i].id, movies[i].title, movies[i].genre, movies[i].stock, movies[i].price);
    }
    printf("\n\t-----------------------------------------------------------------");
    printf("\n\t Masukkan ID Film yang Anda Pilih: ");
    scanf("%d", &id_movie);

    for(i=0; i<jumlah_movie; i++){
        if(movies[i].id == id_movie){
            cari = 1;
            printf("\n\t Anda telah memilih film: %s", movies[i].title);
            printf("\n\t Jumlah Stock Tersedia: %d", movies[i].stock);
            printf("\n\t Masukkan Jumlah Tiket yang Anda Inginkan: ");
            scanf("%d", &jumlah_tiket);

            if(jumlah_tiket > movies[i].stock){
                printf("\n\t Maaf, Jumlah Tiket yang Anda Inginkan tidak tersedia. ");
            }
            else{
                movies[i].stock -= jumlah_tiket;
                printf("\n\t Berhasil Membeli %d Tiket Film %s. Sisa Stock Tiket: %d ", jumlah_tiket, movies[i].title, movies[i].stock);
            }
        }
    }

    if(cari == 0){
        printf("\n\t Eror/n");
    }

    printf("\n\t Untuk Melanjutkan Silahkan Pilih Genre Film ");
    genreFilm();
}

void keluar(){
    printf("\n\t Terima Kasih Telah Menggunakan Sistem Pemesanan Tiket di Bioskop TI ");
    printf("\n\t Selamat Datang Kembali! ");
    getchar();
    exit(0);
}

int main(){
    intro();
    return 0;
}
