#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu();
void login_admin();
void menu_admin();
void riwayat_transaksi();
void data_customer();
void regis_customer();
void login_customer();
void menu_customer();
void genreFilm();
void horor();
void komedi();
void romantis();
void pemesanan();
void pembayaran();
void keluar();

float jam1[6]= {0,12.00, 14.00, 16.00, 20.00, 22.00};
float jam2[6]= {0,12.30, 14.30, 16.30, 20.30, 22.30};
int hari;

struct customer{
	char nama_cust[50];
	int pin_cust;
};

struct customer registrasi;
struct customer login;

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
    printf("\n\tEnter untuk melanjutkan...");
    while (getchar() != '\n')
        ;
    menu();
}

void menu(){
    int pil;

    system("cls");
    printf("\n\t==================================================");
    printf("\n\t||                Pilihan Masuk                 ||");
    printf("\n\t==================================================");
    printf("\n\t||       1. Masuk Sebagai Admin                 ||");
    printf("\n\t||       2. Regis Sebagai Pelanggan             ||");
    printf("\n\t||       3. Login Sebagai Pelanggan             ||");
    printf("\n\t||       4. Exit                                ||");
    printf("\n\t==================================================");
    printf("\n\t Masukkan Pilihan Anda: ");
    scanf("%d", &pil);
    if(pil==1){
        login_admin();
    }
    else if(pil==2){
        regis_customer();
    }
    else if(pil==3){
        login_customer();
    }
    else if(pil==4){
        keluar();
    }
    else{
        printf("Error\n");
    }
}

void login_admin(){
    char username [15];
	char password [15];

	printf("\nMasukkan username: ");
	scanf("%s", &username);
	printf("\nMasukkan password: ");
	fflush(stdin);
	scanf("%s", &password);
    if ((strcmp(username, "admin") == 0) && (strcmp(password, "123") ==0)){
        getchar();
        printf("\n\n\tTekan Enter untuk melanjutkan...");
        getchar();
        system ("cls");
        menu_admin();
	}else {
		printf("\nPassword atau Username Salah!\n");
        getchar();
        printf("\nTEKAN ENTER UNTUK KEMBALI");
        getchar();
        system ("cls");
        menu();
	}
}

void menu_admin(){
    int pil;
	while (pil!=4){
	system("cls");
	printf("\n\t==============================================================");
    printf("\n\t||                   Tampilan Menu Admin                    ||");
    printf("\n\t||==========================================================||");
    printf("\n\t||  [1] Menampilkan riwayat transaksi                       ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [2] Menampilkan data customer                           ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [3] Log out                                             ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan pilihan Anda [1][2][3] : ");
    scanf("%d", &pil);
    switch(pil){
    	case 1:
    		{
    			//riwayat_transaksi();
    			break;
			}
		case 2:
			{
				//data_customer();
				break;
			}
			case 3:{
                menu();
                break;
			}
		default:
			{
				printf("Menu tidak tersedia!");
				break;
			}
	}


	}
}

void regis_customer(){
    int i;
    struct customer cust01;
	FILE *regis = fopen("DataCustomer.txt", "a+");

	printf("\n\t=========================::::::::::::::::=====================\n");
    printf("\n\t||                    -- MENU REGISTRASI --                 ||\n");
    printf("\n\t=========================::::::::::::::::=====================\n");
    printf("\n\tMasukkan username : ");
    scanf("%d[^\n]", registrasi.nama_cust);
	fflush(stdin);

	//Mengecek data customer dalam file DataCustomer.txt
	while (!feof(regis)){
		//membaca data customer dalam file DataCustomer.txt
		fscanf(regis, "%[^#]#%d\n", &cust01.nama_cust, &cust01.pin_cust);
		fflush(stdin);

		//mengecek apakah username yang diinputkan sudah pernah terdaftar sebelumnya. Apabila sudah, customer akan diminta menginputkan username baru.
		if (strcmp(cust01.nama_cust, registrasi.nama_cust)==0){
            printf("\n\t -- username sudah terdaftar. Coba gunakan username lainnya -- ");
            printf("\n\t==============================================================\n");
            fclose(regis);
			printf("\n\n\tTekan Enter untuk melanjutkan...");
            getchar();
			regis_customer();
			break;
		}
	}
	//ketika username yang diinputkan belum pernah terdaftar, maka program akan lanjut meminta inputan PIN
    fflush(stdin);
    printf("\n\tMasukkan PIN : ");
	while(scanf("%d", &registrasi.pin_cust)==0 || registrasi.pin_cust < 0){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan PIN : ");
        while((getchar())!='\n');
    }
    fprintf(regis, "%s#%d\n", registrasi.nama_cust, registrasi.pin_cust);
    fclose(regis);

    printf("\n\t\tRegistrasi dengan username %s berhasil!", registrasi.nama_cust);
    printf("\n\t --------------------------------------------------------------\n");
    login_customer();
}

void login_customer(){
    int i;
	int kode;
	struct customer cust01;
	FILE *regis = fopen("DataCustomer.txt", "a+");

    printf("\n\t=========================::::::::::::::::=====================\n");
    printf("\n\t||                       -- MENU LOGIN --                   ||\n");
    printf("\n\t=========================::::::::::::::::=====================\n");
	printf("\n\tMasukkan PIN : ");
	while(scanf("%d", &kode)==0 || kode < 0){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan PIN : ");
        while((getchar())!='\n');
    }

	// mengecek data customer dalam file DataCustomer.txt
	while (!feof(regis)){
		//membaca data customer dalam file DataCustomer.txt
		fscanf(regis, "%[^#]#%d\n", &cust01.nama_cust, &cust01.pin_cust);
		fflush(stdin);

		//mengecek apakah PIN yang diinputkan telah terdaftar
		if (cust01.pin_cust == kode){
			// jika PIN telah terdaftar maka  akan ditampilkan username customer
			printf("\n\t==============================================================");
			printf("\n\t\t\t\t LOGIN BERHASIL");
			printf("\n\t--------------------------------------------------------------");
			printf("\n\tHello, %s !", cust01.nama_cust);
			printf("\n\t==============================================================");
			strcpy(login.nama_cust, cust01.nama_cust);
			fclose(regis);
			menu_customer();
			break;
		}
		else{
            printf("Anda Belum Terdaftar\n\t");
            login_customer();
		}
	}
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
        printf("Error\n");
    }
}

void genreFilm(){
    int pil;
    system("cls");
    printf("\n\t\t=========================");
    printf("\n\t\t||     Genre Film      ||");
    printf("\n\t\t=========================");
    printf("\n\t\t||   1. Horor          ||");
    printf("\n\t\t||   2. Komedi         ||");
    printf("\n\t\t||   3. Romantis       ||");
    printf("\n\t\t=========================");
    printf("\n\t\t Masukkan Pilihan Genre Film Anda: ");
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
    int id_movie, jumlah_tiket, hari, i;
    int cari = 0;
    double price;
    struct tm *local;
    time_t now;
    now = time(NULL);
    local = localtime(&now);
    system("cls");
    printf("\n\t=====================================================================================================");
    printf("\n\t||                                Daftar Film yang Tayang                                          ||");
    printf("\n\t=====================================================================================================");
    printf("\n\t ID \t| Title \t\t| Genre \t| Stock \t| Price Weekday | Price Weekend");
    printf("\n\t-----------------------------------------------------------------------------------------------------");
    for (i = 0; i < jumlah_movie; i++) {
        printf("\n\t %-2d \t| %-20s \t| %-10s \t| %-7d \t| %-12.2lf \t| %-12.2lf", movies[i].id, movies[i].title, movies[i].genre, movies[i].stock, movies[i].weekday_price, movies[i].weekend_price);
    }
    printf("\n\t Silahkan pilih ID film yang akan dipesan: ");
    scanf("%d", &id_movie);
    for (i = 0; i < jumlah_movie; i++) {
        if (movies[i].id == id_movie) {
            cari = 1;
            break;
        }
    }

    hari = local->tm_wday;
    if(hari==0){
        printf("\n\t Hari minggu");
    }else if(hari==1){
        printf("\n\t Hari senin");
    }else if(hari==2){
        printf("\n\t Hari selasa");
    }else if(hari==3){
        printf("\n\t Hari rabu");
    }else if(hari==4){
        printf("\n\t Hari kamis");
    }else if(hari==5){
        printf("\n\t Hari jumat");
    }else {
        printf("\n\t Hari sabtu");
    }
    printf(" adalah hari ke %d/%d/%d", local->tm_mday, local->tm_mon+1, local->tm_year+1900);

    if (cari == 1) {
        switch (hari) {
            case 0:
            case 6:
                price = movies[i].weekend_price;
                break;
            default:
                price = movies[i].weekday_price;
                break;
        }
        printf("\n\t Film yang Anda pilih adalah '%s'. Harga tiketnya adalah Rp %.2lf", movies[i].title, price);
        printf("\n\t Berapa jumlah tiket yang ingin Anda pesan: ");
        scanf("%d", &jumlah_tiket);

        if (price = movies[i].weekday_price)
        {
            printf("\n\t%.2f \t%.2f \t%.2f \t%.2f \t%.2f ", jam1[1],jam1[2],jam1[3],jam1[4],jam1[5]);
        }else if (price = movies[i].weekend_price)
        {
            printf("\n\t%.2f \t%.2f \t%.2f \t%.2f \t%.2f ", jam2[1],jam2[2],jam2[3],jam2[4],jam2[5]);
        }
        printf("\nSilahkan Pilih Jam tayang : ");

        if (jumlah_tiket > movies[i].stock) {
            printf("\n\t Maaf, stock tiket yang tersedia adalah %d", movies[i].stock);
        } else {
            movies[i].stock -= jumlah_tiket;
            pembayaran(movies[i], jumlah_tiket, price);
        }
    } else {
        printf("\n\t Maaf, ID film yang Anda masukkan tidak valid! ");
    }
}

void pembayaran(Movie movie, int jumlah_tiket, double price) {
    double total_harga = price * jumlah_tiket;
    double uang_bayar;
    system("cls");
    printf("\n\t=============================================");
    printf("\n\t||            PEMBAYARAN TIKET             ||");
    printf("\n\t=============================================");
    printf("\n\t Film yang anda pesan: %s", movie.title);
    printf("\n\t Jumlah tiket yang anda pesan: %d", jumlah_tiket);
    printf("\n\t---------------------------------------------");
    printf("\n\t Total harga pembelian tiket adalah Rp %.2lf", total_harga);
    printf("\n\t---------------------------------------------");
    printf("\n\t Silahkan masukkan jumlah uang yang akan Anda bayarkan: ");
    scanf("%lf", &uang_bayar);

    if (uang_bayar < total_harga) {
        printf("\n\t Maaf, uang yang Anda masukkan tidak cukup untuk membayar tiket! ");
    } else {
        double kembalian = uang_bayar - total_harga;
        printf("\n\t Terima kasih atas pemesanan Anda! Tiket yang Anda pesan telah berhasil dipesan. ");
        printf("\n\t Uang kembalian Anda adalah Rp %.2lf", kembalian);
    }
}

void keluar() {
    printf("\n\t Terima Kasih Telah Menggunakan Sistem Pemesanan Tiket di Bioskop TI ");
    printf("\n\t Selamat Datang Kembali! ");
    getchar();
    exit(0);
}

int main() {
    intro();
    return 0;
}
