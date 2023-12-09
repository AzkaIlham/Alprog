#include <stdio.h>

void menu_customer();
void genreFilm();
void horor();
void komedi();
void romantis();
void pemesanan();
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

    system("cls");
    printf("\n\t===============================================");
    printf("\n\t||        SELAMAT DATANG DIBIOSKOP TI        ||");
    printf("\n\t===============================================");
    printf("\n\t||               Tampilan Menu               ||");
    printf("\n\t===============================================");
    printf("\n\t||  1. Menu Pemesanan Tiket                  ||");
    printf("\n\t||  2. Exit                                  ||");
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
    printf("\n\tSegera Dibuat");
}

void komedi(){
    printf("\n\tSegera Dibuat");
}

void romantis(){
    printf("\n\tSegera Dibuat");
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

int main(){

    intro();

    return 0;
}
