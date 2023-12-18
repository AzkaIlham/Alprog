#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int validasiRange() {
    char input[100], notValid;
    int valid;
    scanf("%[^\n]", input);
    getchar();
    if (sscanf(input, "%d%c", &valid, &notValid) == 0 && valid >= 1 || valid <= 6){
        return valid;      
    }
    else {
        system("cls");
        printf("\t\t ______________________________________________________________  \n");
        printf("\t\t   __________________________________________________________  \n");
        printf("\t\t| |                                                          | |\n");
        printf("\t\t| |                Maaf Input anda salah !                   | |\n");
        printf("\t\t| |                                                          | |\n");
        printf("\t\t| |              Masukan Input Dengan Benar                  | |\n");            
        printf("\t\t| |__________________________________________________________| |\n");
        printf("\t\t________________________________________________________________ \n");
        validasiRange();
    }
}

float validasiFloat(){
    char input[100], notValid;
    float valid;
    scanf("%[^\n]", input);
    getchar();
    if (sscanf(input, "%f%c", &valid, &notValid) == 1 && valid > 0){
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
        validasiFloat();
        }
}

int validasiBack() {
    char input[100], notValid;
    int valid;
    scanf("%[^\n]", input);
    getchar();
    if (sscanf(input, "%d%c", &valid, &notValid) ==1){
        return valid;      
    }
    else {
        system("cls");
        printf("\t\t ______________________________________________________________  \n");
        printf("\t\t   __________________________________________________________  \n");
        printf("\t\t| |                                                          | |\n");
        printf("\t\t| |                Maaf Input anda salah !                   | |\n");
        printf("\t\t| |                                                          | |\n");
        printf("\t\t| |              Masukan Input Dengan Benar                  | |\n");            
        printf("\t\t| |__________________________________________________________| |\n");
        printf("\t\t________________________________________________________________ \n");
        validasiBack();
    }
}


// Fungsi

void tube(){
    printf("======================================== \n");
    printf("Program Mencari Luas Permukaan tube \n");
    printf("======================================== \n");

    // deklarasi variable
    float surface_area, volume, circle_radius, tall;
    

    //input
    printf("Masukkan Jari Jari : ");
    circle_radius = validasiFloat();
    printf("Masukkan tall : ");
    tall = validasiFloat();


    volume = PI * circle_radius * circle_radius * tall;

    printf("======================================== \n");;
    printf("Volume dari tube adalah : %.2f \n", volume);

    surface_area = 2 * PI * circle_radius * (circle_radius + tall); 
  
    printf("Luas Permukaan dari tube adalah : %.2f \n", surface_area);
    printf("======================================== \n");

}

void cone(){
    printf("======================================== \n");
    printf("Program Mencari Luas Permukaan cone \n");
    printf("======================================== \n");

    float surface_area, volume, circle_radius, tall, blanket;

    printf("Masukkan Jari Jari : ");
    circle_radius = validasiFloat();
    printf("Masukkan tall : ");
    tall = validasiFloat();

    volume = 1 * PI * circle_radius * circle_radius * tall / 3;

    printf("======================================== \n");
    printf("Volume dari cone adalah : %.2f \n", volume);

    blanket = sqrt((circle_radius * circle_radius)+(tall * tall));
    
    printf("blanket dari cone adalah : %.2f \n", blanket);

    surface_area = PI * circle_radius * (blanket + circle_radius);
    // surface_area = (PI * circle_radius * blanket) + ( PI * circle_radius *circle_radius);
 
    printf("Luas Permukaan dari cone adalah : %.2f \n", surface_area);
    printf("======================================== \n"); 

}

void ball(){
    printf("======================================== \n");
    printf("Program Mencari Luas Permukaan ball \n");
    printf("======================================== \n");

    float surface_area, volume, circle_radius;
    

    printf("Masukkan Jari Jari : ");
    circle_radius = validasiFloat();

    volume = 4 * PI * circle_radius * circle_radius * circle_radius / 3;

    printf("======================================== \n");
    printf("Volume dari ball adalah : %.2f \n", volume);

    surface_area = 4 * PI * circle_radius * circle_radius;
 
    printf("Luas Permukaan dari ball adalah : %.2f \n", surface_area);
    printf("======================================== \n"); 

}

void triangular_prism(){
    printf("======================================== \n");
    printf("Program Mencari Luas Permukaan Prisma Segitiga \n");
    printf("======================================== \n");

    float surface_area, volume, base, tall, tall_prism, base_circum, sideA, sideB, base_area;

    printf("Masukkan Alas : ");
    base = validasiFloat();
    printf("Masukkan Tinggi Segitiga: ");
    tall = validasiFloat();
    printf("Masukkan Sisi A Segitiga: ");
    sideA = validasiFloat();
    printf("Masukkan Sisi B Segitiga: ");
    sideB = validasiFloat();
    printf("Masukkan Tinggi Prisma : ");
    tall_prism = validasiFloat();


    base_circum = sideA + base + sideB;
 
    printf("======================================== \n");
    printf("Keliling segitiga adalah : %.2f \n", base_circum);

    base_area = 1 * base * tall / 2;

    printf("Luas base adalah : %.2f \n", base_area);
    printf("======================================== \n");

    volume = base_area * tall_prism;
    
    surface_area = (2 * base_area) + (base_circum * tall_prism);

    printf("Volume dari Prisma Segitiga adalah : %.2f \n", volume);
 
    printf("Luas Permukaan dari Prisma Segitiga adalah : %.2f \n", surface_area);
    printf("======================================== \n"); 

}

void rectangular_pyramid(){
    printf("======================================== \n");
    printf("Program Mencari Luas Permukaan Limas Segi Empat \n");
    printf("======================================== \n");

    float surface_area, volume, tall, side, base_area, area_triangle;
    

    printf("Masukkan sisi : ");
    side = validasiFloat();
    printf("Masukkan Tinggi : ");
    tall = validasiFloat();
    
    area_triangle = 1 * side * tall / 2;

    printf("======================================== \n");
    printf("Luas segitiga adalah : %.2f \n", area_triangle);

    base_area = side * side ;

    // printf("======================================== \n");
    printf("luas alas dari Limas Segi Empat adalah : %.2f \n", base_area);

    volume = 1 * base_area * tall / 3 ;

    // printf("======================================== \n");
    printf("Volume dari Limas Segi Empat adalah : %.2f \n", volume);

    surface_area = base_area + (4 * area_triangle );
  
    printf("Luas Permukaan dari Limas Segi Empat adalah : %.2f \n", surface_area);
    printf("======================================== \n");

}

void groupName(){
    printf("\t================================================================\n"); 
    printf("\t||  PROGRAM MENGHITUNG LUAS PERMUKAAN DAN VOLUME BANGUN RUANG ||\n");
    printf("\t||                         KELOMPOK 14                        ||\n");
    printf("\t||1. Ni Luh Made Tika Kurniasari (2305551034)                 ||\n");
    printf("\t||2. Luh Dewita Cahyani Ardiningsih (2305551045)              ||\n");
    printf("\t||3. Ni Komang Dama Angelina (2305551059)                     ||\n");
    printf("\t||4. Carlos Qnova Bha'a Gani (2305551100)                     ||\n");
    printf("\t||5. Ida Bagus Gde Raditya Wedananta (2305551102)             ||\n");
    printf("\t||6. Glenaro Yerikho Ressi (2305551166)                       ||\n");
    printf("\t||7. Azka Ilham Ramadhani (2305551171)                        ||\n");
    printf("\t================================================================\n");
    system("pause");
    system("cls");
}


int main(){
    int operator;
    int kembali = 1;

    groupName();
      
    do
    {
        printf("+===============================================+\n");
        printf("|                  MENU UTAMA                   |\n");
        printf("+===============================================+\n");
        printf("|        Program Menghitung Bangun Ruang        |\n");
        printf("+===============================================+\n");
        printf("|         Silakan pilih bangun ruang            |\n");
        printf("+===============================================+\n");
        printf("| 1. Tabung                                     |\n");
        printf("| 2. Bola                                       |\n");
        printf("| 3. Limas Segiempat                            |\n");
        printf("| 4. Prisma Segitiga                            |\n");
        printf("| 5. Kerucut                                    |\n");
        printf("| 6. Keluar Program                             |\n");
        printf("+===============================================+\n");

        printf("Masukkan Operator :");
        // scanf("%d", &operator);
        operator = validasiRange();   

        switch (operator)
        {
            case 1:
                tube();
                break;
            case 2:
                ball();
                break;
            case 3:
                rectangular_pyramid();
                break;
            case 4:
                triangular_prism();
                break;
            case 5:
                cone();
                break;
            case 6:
                return 0;
                break;
            default:
                // validasiRange();
                printf("Pilihan tidak valid.\n");
                break;
        }
        printf("Apakah Anda ingin kembali ke menu utama? (1 = Ya, 2 = Tidak): ");
        // scanf("%d", &kembali);
        kembali = validasiBack();
        system("cls");
        
        // Membersihkan input buffer
        // while (getchar() != '\n');
        
    } while (kembali == 1);

        return 0;
}