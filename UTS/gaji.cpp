/*
Soal UTS:
Buatlah program dalam C++ untuk penyelesaian berikut:
a. Menghitung gaji berdasarkan: golongan & jam lembur

Program harus terdapat:
1. Menggunakan salah satu: Array/Pointer
2. Menggunakan Fungsi
3. Menggunakan Looping
4. Menggunakan Kondisional
*/


//Jawaban:
/*
NAMA        : Panji Jaya Sutra
NIM         : 20220801517
Prodi       : Teknik Informatika

Mata Kuliah : Struktur Data
Dosen       : Bpk Masmur Tarigan,ST.,M.Kom    
*/

#include <iostream>
#include <unordered_map>
using namespace std;

//Fungsi untuk menghitung pemotongan gaji
int pemotonganGaji(int kehadiran, int gapok){
    int pemotongan = 0;
    //Conditional
    if (kehadiran < 25){
        pemotongan = gapok * (25 - kehadiran) / 25;
    }
    return pemotongan;
}

// Fungsi untuk menghitung total gaji
int hitungTotalGaji(int kehadiran, int gapok, int tunjangan, int transportasi, int uang_makan, int lemburan) {
    int pemotongan = pemotonganGaji(kehadiran, gapok);
    // hitung total gaji
    int total_gaji = gapok + tunjangan + transportasi + uang_makan + lemburan - pemotongan;
    return total_gaji;
}

// Fungsi untuk menampilkan detail gaji
void tampilkanDetailGaji(int golongan, int gapok, int tunjangan, int transportasi, int uang_makan, int lemburan, int pemotongan) {
    cout << "\nDetail Gaji:\n";
    cout << "Golongan: " << golongan << "\n";
    cout << "Gapok: " << gapok << "\n";
    cout << "Tunjangan: " << tunjangan << "\n";
    cout << "Transportasi: " << transportasi << "\n";
    cout << "Uang Makan: " << uang_makan << "\n";
    cout << "Lemburan: " << lemburan << "\n";
    cout << "Pemotongan: " << pemotongan << "\n";
}

int main() {
    cout << "Perhitungan Gaji\n";

    unordered_map<int, unordered_map<string, int>> data_gaji = {
        {1, {{"gapok", 1000000}, {"tunjangan", 100000}, {"transportasi", 100000}, {"uang_makan", 250000}, {"lemburan", 15000}}},
        {2, {{"gapok", 2000000}, {"tunjangan", 200000}, {"transportasi", 200000}, {"uang_makan", 250000}, {"lemburan", 20000}}},
        {3, {{"gapok", 3000000}, {"tunjangan", 300000}, {"transportasi", 300000}, {"uang_makan", 250000}, {"lemburan", 25000}}},
        {4, {{"gapok", 4000000}, {"tunjangan", 400000}, {"transportasi", 400000}, {"uang_makan", 250000}, {"lemburan", 30000}}},
        {5, {{"gapok", 5000000}, {"tunjangan", 500000}, {"transportasi", 500000}, {"uang_makan", 250000}, {"lemburan", 35000}}},
        {6, {{"gapok", 6000000}, {"tunjangan", 600000}, {"transportasi", 600000}, {"uang_makan", 0}, {"lemburan", 0}}},
        {7, {{"gapok", 7000000}, {"tunjangan", 700000}, {"transportasi", 700000}, {"uang_makan", 0}, {"lemburan", 0}}},
        {8, {{"gapok", 8000000}, {"tunjangan", 800000}, {"transportasi", 800000}, {"uang_makan", 0}, {"lemburan", 0}}},
        {9, {{"gapok", 9000000}, {"tunjangan", 900000}, {"transportasi", 900000}, {"uang_makan", 0}, {"lemburan", 0}}},
        {10, {{"gapok", 10000000}, {"tunjangan", 1000000}, {"transportasi", 1000000}, {"uang_makan", 0}, {"lemburan", 0}}}
    };

    int kehadiran, golongan, jumlah_lemburan;
    cout << "Jumlah kehadiran dalam 1 Bulan (*25 hari) = ";
    cin >> kehadiran;
    cout << "Golongan (1 ~ 10) = ";
    cin >> golongan;
    cout << "Jumlah jam lembur = ";
    cin >> jumlah_lemburan;

    // Looping for dengan indeks
    for (int i = 0; i < data_gaji.size(); ++i) {
        //Conditional pengecekan golongan
        if (golongan==i+1) {
            auto gaji = data_gaji[i + 1];

            int gapok = gaji["gapok"];
            int tunjangan = gaji["tunjangan"];
            int transportasi = gaji["transportasi"];
            int uang_makan = gaji["uang_makan"];
            int lemburan = gaji["lemburan"];

            //declarasi pointer
            int *kehadiran_pointer;
            int *gapok_pointer;

            // set memory address pointer
            kehadiran_pointer = &kehadiran;
            gapok_pointer = &gapok;

            lemburan = jumlah_lemburan * lemburan;

            // Memanggil fungsi untuk menghitung total gaji
            int pemotongan = pemotonganGaji(*kehadiran_pointer, *gapok_pointer);
            int total_gaji = hitungTotalGaji(kehadiran, gapok, tunjangan, transportasi, uang_makan, lemburan);
            // Memanggil fungsi untuk menampilkan detail gaji
            tampilkanDetailGaji(golongan, gapok, tunjangan, transportasi, uang_makan, lemburan, pemotongan);
            //Display total gaji
            cout << "Total gaji Anda: Rp " << total_gaji << endl;

            return 0;
        }
    }

    cout << "Golongan tidak ditemukan\n";

    return 0;
}
