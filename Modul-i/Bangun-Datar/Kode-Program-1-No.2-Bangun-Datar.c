#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14
int validation() {
    char input[100], notValid;
    int valid;
    scanf("%[^\n]", input);
    getchar();
    if (sscanf(input, "%d%c", &valid, &notValid) == 1 && valid >=1  && valid <=2 ){
        return valid;      
    }
    else {
        system("cls");
        printf("\t==============================================================\n");
        printf("\t||                                                          ||\n");
        printf("\t||                MAAF INPUT ANDA SALAH !                   ||\n");
        printf("\t||               MASUKAN INPUT DENGAN BENAR                 ||\n");
        printf("\t||                                                          ||\n");            
        printf("\t==============================================================\n");
        printf("\tAPAKAH ANDA INGIN KEMBALI KE MENU UTAMA? (1 = YA, 2 = TIDAK): ");
        validation();
    }
}

int floatvalidation(){
    char input[100], notValid;
    float valid;
    scanf("%[^\n]", input);
    getchar();
    if (sscanf(input, "%f%c", &valid, &notValid) == 1){
        return valid;      
    }
    else {
        system("cls");
        printf("\t==============================================================\n");
        printf("\t||                                                          ||\n");
        printf("\t||                MAAF INPUT ANDA SALAH !                   ||\n");
        printf("\t||               MASUKAN INPUT DENGAN BENAR                 ||\n");
        printf("\t||                                                          ||\n");            
        printf("\t==============================================================\n");
        printf("\tMASUKAN DENGAN BENAR!!!!!: ");
        floatvalidation();
    }
}

int rengeValidation() {
    char input[100], notValid;
    int valid;
    scanf("%[^\n]", input);
    getchar();
    if (sscanf(input, "%d%c", &valid, &notValid) == 1 && valid >= 1 && valid <= 6){
        return valid;      
    }
    else {
        system("cls");
        printf("\t==============================================================\n");
        printf("\t||                                                          ||\n");
        printf("\t||                MAAF INPUT ANDA SALAH !                   ||\n");
        printf("\t||               MASUKAN INPUT DENGAN BENAR                 ||\n");
        printf("\t||                                                          ||\n");            
        printf("\t==============================================================\n");
        printf("\t|| PILIH BANGUN DATAR:                                      ||\n");
        printf("\t|| 1. SEGITIGA SEMBARANG                                    ||\n");
        printf("\t|| 2. BELAH KETUPAT                                         ||\n");
        printf("\t|| 3. JAJAR GENJANG                                         ||\n");
        printf("\t|| 4. TRAPESIUM                                             ||\n");
        printf("\t|| 5. LINGKARAN                                             ||\n");
        printf("\t|| 6. KELUAR PROGRAM                                        ||\n");
        printf("\t==============================================================\n");
        printf("\tMASUKAN NOMOR PILIHAN ANDA: ");
        rengeValidation();
    }
}

void calculateareacircumtriangle() {
    float base, height, side1, side2, side3;
    printf("\tMasukkan panjang alas segitiga: ");
    base = floatvalidation();
    printf("\tMasukkan tinggi segitiga: ");
    height = floatvalidation();
    printf("\tMasukkan panjang sisi pertama: ");
    side1 = floatvalidation();
    printf("\tMasukkan panjang sisi kedua: ");
    side2 = floatvalidation();
    printf("\tMasukkan panjang sisi ketiga: ");
    side3 = floatvalidation();

    float area = 0.5 * base * height;

    float circum = side1 + side2 + side3;

    printf("\tLuas segitiga: %f\n", area);
    printf("\tKeliling segitiga: %f\n", circum);
}

void calculateareacircumrhombus() {
    float diagonal1, diagonal2, sisi;
    printf("\tMasukkan panjang diagonal 1: ");
    diagonal1 = floatvalidation();
    printf("\tMasukkan panjang diagonal 2: ");
    diagonal2 = floatvalidation();
    printf("\tMasukkan panjang sisi: ");
    sisi = floatvalidation();

    float area = 0.5 * diagonal1 * diagonal2;

    float circum = 4 * sisi;

    printf("\tLuas belah ketupat: %f\n", area);
    printf("\tKeliling belah ketupat: %f\n", circum);
}

void calculateareacircumparallelogram() {
    float base, height, side1, side2;
    printf("\tMasukkan panjang alas: ");
    base = floatvalidation();
    printf("\tMasukkan tinggi: ");
    height = floatvalidation();
    printf("\tMasukkan panjang sisi 1: ");
    side1 = floatvalidation();
    printf("\tMasukkan panjang sisi 2: ");
    side2 = floatvalidation();

    float area = base * height;

    float circum = 2 * (side1 + side2);

    printf("\tLuas jajar genjang: %f\n", area);
    printf("\tKeliling jajar genjang: %f\n", circum);
}


void calculateareacircumtrapezium() {
    float side1, side2, side3, sisi4, height;
    printf("\tMasukkan panjang sisi 1: ");
    side1 = floatvalidation();
    printf("\tMasukkan panjang sisi 2: ");
    side2 = floatvalidation();
    printf("\tMasukkan panjang sisi 3: ");
    side3 = floatvalidation();
    printf("\tMasukkan panjang sisi 4: ");
    sisi4 = floatvalidation();
    printf("\tMasukkan height: ");
    height = floatvalidation();

    float area = 0.5 * (side1 + side3) * height;

    float circum = side1 + side2 + side3 + sisi4;

    printf("\tLuas trapesium: %f\n", area);
    printf("\tKeliling trapesium: %f\n", circum);
}

void calculateareacircumcircle() {
    float radius;
    printf("\tMasukkan panjang jari-jari: ");
    radius = floatvalidation();

    float area = PI * radius * radius;

    float circum = 2 * PI * radius;

    printf("\tLuas lingkaran: %f\n", area);
    printf("\tKeliling lingkaran: %f\n", circum);
}

void groupName(){
    printf("\t==============================================================\n");
    printf("\t||       PROGRAM MENGHITUNG LUAS KELILING BANGUN DATAR      ||\n");
    printf("\t||                         KELOMPOK 14                      ||\n");
    printf("\t||                                                          ||\n");
    printf("\t||1. Ni Luh Made Tika Kurniasari (2305551034)               ||\n");
    printf("\t||2. Luh Dewita Cahyani Ardiningsih (2305551045)            ||\n");
    printf("\t||3. Ni Komang Dama Angelina (2305551059)                   ||\n");
    printf("\t||4. Carlos Qnova Bha'a Gani (2305551100)                   ||\n");
    printf("\t||5. Ida Bagus Gde Raditya Wedananta (2305551102)           ||\n");
    printf("\t||6. Glenaro Yerikho Ressi (2305551166)                     ||\n");
    printf("\t||7. Azka Ilham Ramadhani (2305551171)                      ||\n");
    printf("\t==============================================================\n");
    system("pause");
    system("cls");
}
int main() {
    int choice;
    int return_to_homepage;
    groupName();
    
    do {
        printf("\t==============================================================\n");
        printf("\t|| PILIH BANGUN DATAR:                                      ||\n");
        printf("\t|| 1. SEGITIGA SEMBARANG                                    ||\n");
        printf("\t|| 2. BELAH KETUPAT                                         ||\n");
        printf("\t|| 3. JAJAR GENJANG                                         ||\n");
        printf("\t|| 4. TRAPESIUM                                             ||\n");
        printf("\t|| 5. LINGKARAN                                             ||\n");
        printf("\t|| 6. KELUAR PROGRAM                                        ||\n");
        printf("\t==============================================================\n");
        printf("\tMASUKAN NOMOR PILIHAN ANDA: ");
            choice = rengeValidation();
        switch (choice) {
            case 1:
                calculateareacircumtriangle();
                break;
            case 2:
                calculateareacircumrhombus();
                break;
            case 3:
                calculateareacircumparallelogram();
                break;
            case 4:
                calculateareacircumtrapezium();
                break;
            case 5:
                calculateareacircumcircle();
                break;
            case 6:
                return 0;
            default:
                printf("\tPilihan tidak valid.\n");
                break;
        }
    
        printf("\tAPAKAH ANDA INGIN KEMBALI KE MENU UTAMA? (1 = YA, 2 = TIDAK): ");
        getchar();
        return_to_homepage = validation();

    } while (return_to_homepage == 1);

    return 0;
}