#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu_customer();
void genreFilm();
void horor();
void komedi();
void romantis();
void pemesanan();
void pembayaran();
void keluar();

typedef struct{
    int id;
    char title[50];
    char genre[20];
    int stock;
    float weekday_price;
    float weekend_price;
}Movie;

void intro(){
    system("cls");
    printf("\n\t==================================================");
    printf("\n\t||                Nama Kelompok                 ||");
    printf("\n\t==================================================");
    printf("\n\t||    1. Putu Satria Arya Putra (2305551122)    ||");
    printf("\n\t||    2. Anthony Wisnu Jati     (2305551138)    ||");
    printf("\n\t||    3. Azka Ilham Ramadhani   (2305551171)    ||");
    printf("\n\t==================================================");
    printf("\n\tEnter untuk melanjutkan..");
    while (getchar() != '\n')
        ;
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
        printf("Error\n");
    }
}

void genreFilm(){
    int pil;
    system("cls");
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
    else if(pil==3){
        romantis();
    }
    else{
        printf("\n\tMasukkan Pilihan Yang Benar");
    }
}

void horor(){
    Movie movies[] = {
        {1, "Conjuring", "Horor", 50, 80000, 90000},
        {2, "Annabelle Creation", "Horor", 30, 85000, 100000},
        {3, "The Ring", "Horor", 20, 90000, 110000},
    };
    pemesanan(movies, 3);
}

void komedi(){
    Movie movies[] = {
        {4, "Friends", "Komedi", 100, 60000, 65000},
        {5, "Modern Family", "Komedi", 70, 70000, 80000},
        {6, "Curb Your Enthusiasm", "Komedi", 40, 65000, 75000},
    };
    pemesanan(movies, 3);
}

void romantis(){
    Movie movies[] = {
        {7, "Pride and Prejudice", "Romantis", 60, 70000, 80000},
        {8, "Love Actually", "Romantis", 40, 75000, 85000},
        {9, "When Harry Met Sally", "Romantis", 50, 80000, 90000},
    };
    pemesanan(movies, 3);
}

void pemesanan(Movie movies[], int jumlah_movie) {
    int id_movie, jumlah_tiket, i;
    int cari = 0;
    double price; // Mengubah tipe data menjadi double
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    system("cls");
    printf("\n\t=====================================================================================================");
    printf("\n\t||                                Daftar Film yang Tayang                                        ||");
    printf("\n\t=====================================================================================================");
    printf("\n\t ID \t| Title \t\t| Genre \t| Stock \t| Price weekday | price weekend");
    printf("\n\t-----------------------------------------------------------------------------------------------------");
    for (i = 0; i < jumlah_movie; i++) {
        printf("\n\t %-2d \t| %-20s \t| %-10s \t| %-7d \t| %-12.2lf \t| %-12.2lf", movies[i].id, movies[i].title, movies[i].genre, movies[i].stock, movies[i].weekday_price, movies[i].weekend_price); // Mengubah tanda menjadi %lf
    }
    printf("\n\t Silahkan pilih ID film yang akan dipesan: ");
    scanf("%d", &id_movie);
    for (i = 0; i < jumlah_movie; i++) {
        if (movies[i].id == id_movie) {
            cari = 1;
            break;
        }
    }

    if (cari == 1) {
        switch (tm->tm_wday) {
            case 0:
            case 6:
                price = movies[i].weekend_price;
                break;
            default:
                price = movies[i].weekday_price;
                break;
        }
        printf("\n\t Film yang Anda pilih adalah '%s'. Harga tiketnya adalah Rp %.2lf", movies[i].title, price); // Mengubah tanda menjadi %lf
        printf("\n\t Berapa jumlah tiket yang ingin Anda pesan: ");
        scanf("%d", &jumlah_tiket);
        if (jumlah_tiket > movies[i].stock) {
            printf("\n\t Maaf, stock tiket yang tersedia adalah %d", movies[i].stock);
        } else {
            movies[i].stock -= jumlah_tiket;
            pembayaran(movies[i], jumlah_tiket, price); // Mengganti &movies[i] dengan movies[i]
        }
    } else {
        printf("\n\t Maaf, ID film yang Anda masukkan tidak valid! ");
    }
}

void pembayaran(Movie movie, int jumlah_tiket, double price) { // Mengganti const Movie *movie dengan Movie movie
    double total_harga = price * jumlah_tiket; // Mengubah tipe data menjadi double
    double uang_bayar; // Mengubah tipe data menjadi double
    system("cls");
    printf("\n\t=============================================");
    printf("\n\t||            PEMBAYARAN TIKET             ||");
    printf("\n\t=============================================");
    printf("\n\t Film yang anda pesan: %s", movie.title);
    printf("\n\t Jumlah tiket yang anda pesan: %d", jumlah_tiket);
    printf("\n\t---------------------------------------------");
    printf("\n\t Total harga pembelian tiket adalah Rp %.2lf", total_harga); // Mengubah tanda menjadi %lf
    printf("\n\t---------------------------------------------");
    printf("\n\t Silahkan masukkan jumlah uang yang akan Anda bayarkan: ");
    scanf("%lf", &uang_bayar); // Mengubah tanda menjadi %lf

    if (uang_bayar < total_harga) {
        printf("\n\t Maaf, uang yang Anda masukkan tidak cukup untuk membayar tiket! ");
    } else {
        double kembalian = uang_bayar - total_harga; // Mengubah tipe data menjadi double
        printf("\n\t Terima kasih atas pemesanan Anda! Tiket yang Anda pesan telah berhasil dipesan. ");
        printf("\n\t Uang kembalian Anda adalah Rp %.2lf", kembalian); // Mengubah tanda menjadi %lf
    }
}

void keluar() {
    printf("\n\t Terima Kasih Telah Menggunakan Sistem Pemesanan Tiket di Bioskop TI ");
    printf("\n\t Selamat Datang Kembali! ");
    getchar();
    exit(0);
} // Menutup kurung kurawal

int main() {
    intro(); // Menambahkan tanda kurung
    return 0;
}
