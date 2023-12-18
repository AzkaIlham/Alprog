#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float floatvalidation(){
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

int rangeValidation(int min, int max){
    char input[100], notValid;
    int valid;
    scanf("%[^\n]", input);
    getchar();
    if (sscanf(input, "%d%c", &valid, &notValid) == 1 && valid >= min && valid <= max){
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
        rangeValidation(min,max);
    }
}

void perhitungan(int pilihan){
    float num1;
    float num2;
    float hasil;
    bool isValid = true;
    printf("Masukkan angka pertama: ");
    num1 = floatvalidation();
    printf("Masukkan angka kedua: " );
    num2 = floatvalidation();

    if(pilihan == 1) {
        hasil = num1 + num2;    
    } else if(pilihan == 2) {
        hasil = num1 - num2;
    } else if(pilihan == 3) {
        hasil = num1 * num2;
    } else if(pilihan == 4) {
        hasil = num1 / num2;
    } else if (pilihan == 5){
        if (num1 <=0 || num2 <=0 ){
            printf("Modulus tidak valid!");
            isValid = false;
        } else {
            hasil = (int)num1 % (int)num2;
        }
    }
        
    if (isValid) {
        printf("Hasil perhitungan: %.2f", hasil);
    }
}

int main() {
  int pilihan;
  int repeat;
    do{
        system("cls");
        
        printf ("|=============================================|\n");
        printf ("|      KALKULATOR SEDERHANA KELOMPOK 1        |\n");
        printf ("|=============================================|\n");
        printf ("|     Menu:                                   |\n");
        printf ("| 1. Penjumlahan (+)                          |\n");
        printf ("| 2. Pengurangan (-)                          |\n");
        printf ("| 3. Perkalian   (*)                          |\n");
        printf ("| 4. Pembagian   (/)                          |\n");
        printf ("| 5. Modulus     (%%)                          |\n"); 
        printf ("| 6. Keluar                                   |\n");  
        printf ("|=============================================|\n");                                                                                        
    
        printf("Pilih menu : ");
        pilihan = rangeValidation(1,6);

        if(pilihan == 6 ){
            return 0;
        }
        else if(pilihan >= 1 && pilihan <= 5){
            perhitungan(pilihan);        
        }
        printf("\nApakah anda ingin kembali ke menu utama? 1 = Ya, 2 = Tidak\n=> ");
        repeat = rangeValidation(1,2);
    }while(repeat == 1);
}
        