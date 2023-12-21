procedure main():
    call displayGroupMembers()
    call showMenu()

procedure displayGroupMembers():
    output "=================================================="
    output "||                Nama Kelompok                 ||"
    output "=================================================="
    output "||    1. Putu Satria Arya Putra (2305551122)    ||"
    output "||    2. Anthony Wisnu Jati     (2305551138)    ||"
    output "||    3. Azka Ilham Ramadhani   (2305551171)    ||"
    output "=================================================="
    output "Enter untuk melanjutkan..."

procedure showMenu():
    input choice
    switch choice:
        case 1:
            call loginAdmin()
        case 2:
            call showCustomerMenu()
        case 3:
            call exitProgram()
        default:
            output "Error"

procedure loginAdmin():
    input username
    input password
    if (username == "admin" and password == "123"):
        call menuAdmin()
    else:
        output "Password atau Username Salah!"
        output "Tekan Enter untuk Kembali..."
        wait for Enter key press
        call showMenu()

procedure menuAdmin():
    repeat:
        output "=============================================================="
        output "||                   Tampilan Menu Admin                    ||"
        output "||==========================================================||"
        output "||  [1] Menampilkan riwayat transaksi                       ||"
        output "||----------------------------------------------------------||"
        output "||  [2] Log out                                             ||"
        output "=============================================================="
        output "Masukkan pilihan Anda [1][2][3] : "
        input choice
        switch choice:
            case 1:
                call displayTransactionHistory()
            case 2:
                call showMenu()
            default:
                output "Menu tidak tersedia!"

procedure displayTransactionHistory():
    open "RiwayatTransaksi.txt" file
    read and output content of the file
    close file
    output "Apakah Mau kembali ke menu admin ? (Y/N) : "
    input decision
    if (decision == "Y" or decision == "y"):
        call menuAdmin()
    else:
        call exitProgram()

procedure showCustomerMenu():
    output "=============================================================="
    output "||                        SELAMAT DATANG                    ||"
    output "||==========================================================||"
    output "||  [1] Registrasi                                          ||"
    output "||----------------------------------------------------------||"
    output "||  [2] Login                                               ||"
    output "||----------------------------------------------------------||"
    output "||  [3] Exit                                                ||"
    output "=============================================================="
    output "Masukkan Pilihan Anda : "
    input choice
    if (choice == 1):
        call registerCustomer()
    elif (choice == 2):
        call loginCustomer()
    elif (choice == 3):
        call exitProgram()
    else:
        output "Angka yang Anda inputkan salah!"
        output "Mohon inputkan pilihan yang benar..."
        output "Masukkan pilihan Anda: "
        repeat:
            input choice
        until (choice is a valid option)
        call showCustomerMenu()

procedure registerCustomer():
    open "DataCustomer.txt" file for append
    input username
    while (username already exists in the file):
        output "username sudah terdaftar. Coba gunakan username lainnya"
        input new username
    input PIN
    write username and PIN to the file
    close file
    output "Registrasi berhasil!"
    call loginCustomer()

procedure loginCustomer():
    open "DataCustomer.txt" file for read
    input username
    input PIN
    while (not end of file):
        read username and PIN from the file
        if (username and PIN match):
            output "Login berhasil"
            call menuOrder()
    close file
    output "Login gagal. Silahkan periksa username dan PIN Anda."
    call showCustomerMenu()

procedure menuOrder():
    output "==============================================="
    output "||        SELAMAT DATANG DIBIOSKOP TI        ||"
    output "==============================================="
    output "||               Tampilan Menu               ||"
    output "==============================================="
    output "||  1. Menu Pemesanan Tiket                  ||"
    output "||  2. Exit                                  ||"
    output "==============================================="
    output "Masukkan Pilihan Anda: "
    input choice
    if (choice == 1):
        call chooseMovieGenre()
    elif (choice == 2):
        call exitProgram()
    else:
        output "Error"

procedure chooseMovieGenre():
    output "========================="
    output "||     Genre Film      ||"
    output "========================="
    output "||   1. Horor          ||"
    output "||   2. Komedi         ||"
    output "||   3. Romantis       ||"
    output "========================="
    output "Masukkan Pilihan Genre Film Anda: "
    input genre
    if (genre == 1):
        call displayHorrorMovies()
    elif (genre == 2):
        call displayComedyMovies()
    elif (genre == 3):
        call displayRomanticMovies()
    else:
        output "Masukkan Pilihan Yang Benar"

procedure displayHorrorMovies():
    define array of horror movies
    call displayMovieList(horror movies)

procedure displayComedyMovies():
    define array of comedy movies
    call displayMovieList(comedy movies)

procedure displayRomanticMovies():
    define array of romantic movies
    call displayMovieList(romantic movies)

procedure displayMovieList(movies):
    output "====================================================================================================="
    output "||                                Daftar Film yang Tayang                                          ||"
    output "====================================================================================================="
    output " ID \t| Title \t\t| Genre \t| Stock \t| Price Weekday | Price Weekend"
    output "-----------------------------------------------------------------------------------------------------"
    for each movie in movies:
        output movie details
    output "Silahkan pilih ID film yang akan dipesan: "
    input movieID
    if (movieID is valid):
        call performTicketReservation(selected movie)
    else:
        output "Maaf, ID film yang Anda masukkan tidak valid!"

procedure performTicketReservation(selectedMovie):
    determine current day
    determine movie price based on current day
    output "Film yang Anda pilih adalah '{selectedMovie.title}'. Harga tiketnya adalah Rp {selectedMovie.price}"
    output "Berapa jumlah tiket yang ingin Anda pesan: "
    input ticketQuantity
    if (ticketQuantity > selectedMovie.stock):
        output "Maaf, stock tiket yang tersedia adalah {selectedMovie.stock}"
    else:
        reduce selectedMovie.stock by ticketQuantity
        call selectShowTime(selectedMovie, ticketQuantity)

procedure selectShowTime(selectedMovie, ticketQuantity):
    output "Daftar jam tayang:"
    if (selectedMovie.price is weekday price):
        output show weekday show times
    else:
        output show weekend show times
    output "Silahkan Masukkan Jam tayang : "
    input selectedShowTime
    call selectSeats(selectedMovie, ticketQuantity, selectedShowTime)

procedure selectSeats(selectedMovie, ticketQuantity, selectedShowTime):
    define array of available seats
    call displaySeatMap()
    output "Silahkan pilih nomor kursi (pisahkan dengan koma jika lebih dari satu): "
    input selectedSeats
    if (selectedSeats are available):
        call confirmReservation(selectedMovie, ticketQuantity, selectedShowTime, selectedSeats)
    else:
        output "Maaf, kursi yang Anda pilih tidak tersedia. Silakan pilih kursi lain."
        call selectSeats(selectedMovie, ticketQuantity, selectedShowTime)

procedure displaySeatMap():
    output "Diagram Kursi Bioskop"

procedure confirmReservation(selectedMovie, ticketQuantity, selectedShowTime, selectedSeats):
    output "Ringkasan Pemesanan:"
    output "Film: {selectedMovie.title}"
    output "Tanggal dan Jam: {selectedShowTime}"
    output "Jumlah Tiket: {ticketQuantity}"
    output "Nomor Kursi: {selectedSeats}"
    output "Harga Total: Rp {ticketQuantity * selectedMovie.price}"
    output "Apakah Anda yakin ingin melanjutkan pemesanan? (Y/N): "
    input confirmation
    if (confirmation == "Y" or confirmation == "y"):
        write reservation details to "TransactionHistory.txt"
        output "Pemesanan berhasil! Terima kasih."
        call menuOrder()
    else:
        call menuOrder()

procedure exitProgram():
    output "Terima kasih telah menggunakan layanan kami. Sampai jumpa!"
    exit program
