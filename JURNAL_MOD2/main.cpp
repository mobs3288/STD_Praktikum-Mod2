#include <iostream>

using namespace std;

// Tipe bentukan untuk mhs
struct mhs {
    string nama, NIM;
    float ipk;
    int semester;
    int kode_unik;
};

// Fungsi untuk mencari prodi dan jumlah prodi yang dimasukkan
void prodi(string nim, int &prod1, int &prod2, int &prod3) {
    string prodi;

    // Pengkondisian
    if (nim == "1") {
        prodi = "Art of Coffee";
        prod1 = prod1 + 1;
    } else if (nim == "2") {
        prodi = "Creative Content";
        prod2 = prod2 + 1;
    } else if (nim == "3") {
        prodi = "Mental Health";
        prod3 = prod3 + 1;
    }

    cout << "Prodi Anda adalah " << prodi << endl;
}

// Fungsi untuk mengecek apakah dia cumlaude atau tidak
void cumlaude (float ipk, int semester) {
    // Pengkondisian
    if (ipk > 3.5 && semester <= 8) {
        cout << "CUMLAUDE" << endl;
    }
}

// Fungsi untuk mencari apakah kode unik itu adalah bilangan prima atau bukan
void prime (int number) {
    bool isPrime = true;
    int i;

    // Pengkondisian
    if (number == 0 || number == 1) {
        isPrime = false;
    }
    else {
        // Pengulangan sebanyak 2 kali
        for (i = 2; i <= number / 2; ++i) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        cout << "MAHASISWA BERPRESTASI" << endl << endl;
    } else {
        cout << endl << endl;
    }
}

// Fungsi untuk mencari ipk yang terbesar dan menimpa nama menjadi yang terbesar
void terbesar(float &ipk_besar, string &nama_ipk, float ipk, string nama) {
    // Pengkondisian
    if (ipk_besar == 0 || ipk_besar < ipk) {
        ipk_besar = ipk;
        nama_ipk = nama;
    }
}

// Fungsi utama
int main()
{
int n, prod1, prod2, prod3;
    float rata_ipk, ipk_besar;
    string nama_ipk;

    cout << "Jumlah data : ";
    cin >> n;

    // Array maha dengan panjang n
    mhs maha[n];

    prod1 = 0;
    prod2 = 0;
    prod3 = 0;

    // Perulangan sebanyak n kali, n dimasukan oleh user
    for (int i = 0; i < n; i++) {
        cout << "Data ke " << i + 1 << endl;

        cout << "Nama : ";
        cin >> maha[i].nama;

        cout << "NIM : ";
        cin >> maha[i].NIM;
        prodi(maha[i].NIM.substr(1,1), prod1, prod2, prod3);

        cout << "Ipk : ";
        cin >> maha[i].ipk;

        terbesar(ipk_besar, nama_ipk, maha[i].ipk, maha[i].nama);

        rata_ipk = rata_ipk + maha[i].ipk;

        cout << "Semester : ";
        cin >> maha[i].semester;
        cumlaude(maha[i].ipk, maha[i].semester);

        cout << "Kode unik : ";
        cin >> maha[i].kode_unik;
        prime(maha[i].kode_unik);
    }

    cout << endl;
    cout << "IPK terbesar didapatkan oleh "<< nama_ipk << endl;
    cout << "IPK Rata-rata : " << rata_ipk / n << endl;

    cout << "Program Studi Studi Art of Coffee : " << prod1 << endl;
    cout << "Program Studi Creative Content : " << prod2 << endl;
    cout << "Program Studi Mental Health : " << prod3 << endl;

    return 0;
}
