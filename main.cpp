#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class data{
public:
    struct KTP{
        string nik;
        string nama;
        string tempat;
        string tl;
        string jk;
        string goldar;
        string alamat;
        string rt;
        string rw;
        string kel;
        string kec;
        string agama;
        string status;
        string pekerjaan;
        string kewarganegaraan;
    };
public:
    KTP inputKTP(){
        KTP ktp;
        cout << "Masukkan NIK: ";
        getline(cin, ktp.nik);
        cout << "Masukkan Nama: ";
        getline(cin, ktp.nama);
        cout << "Masukkan Tempat Lahir: ";
        getline(cin, ktp.tempat);
        cout << "Masukkan Tanggal Lahir (dd-mm-yyyy): ";
        getline(cin, ktp.tl);
        cout << "Masukkan Jenis Kelamin: ";
        getline(cin, ktp.jk);
        cout << "Masukkan Golongan Darah: ";
        getline(cin, ktp.goldar);
        cout << "Masukkan Alamat: ";
        getline(cin, ktp.alamat);
        cout << "Masukkan RT: ";
        getline(cin, ktp.rt);
        cout << "Masukkan RW: ";
        getline(cin, ktp.rw);
        cout << "Masukkan Kel: ";
        getline(cin, ktp.kel);
        cout << "Masukkan Kec: ";
        getline(cin, ktp.kec);
        cout << "Masukkan Agama: ";
        getline(cin, ktp.agama);
        cout << "Masukkan Status Perkawinan: ";
        getline(cin, ktp.status);
        cout << "Masukkan Pekerjaan: ";
        getline(cin, ktp.pekerjaan);
        cout << "Masukkan Kewarganegaraan: ";
        getline(cin, ktp.kewarganegaraan);
        return ktp;
    }
    void cetakKTP(const KTP& ktp) {
        cout << "====================================================================" << endl;
        cout << "NIK              : " << ktp.nik << endl;
        cout << "Nama             : " << ktp.nama << endl;
        cout << "Tempat/Tgl Lahir : " << ktp.tempat << "," << ktp.tl << endl;
        cout << "Jenis Kelamin    : " << ktp.jk << "    " << "Gol. Darah :" << ktp.goldar << endl;
        cout << "Alamat           : " << ktp.alamat << endl;
        cout << "    RT/RW        : " << ktp.rt << "/" << ktp.rw << endl;
        cout << "    Kel/Desa     : " << ktp.kel << endl;
        cout << "    Kecamatan    : " << ktp.kec << endl;
        cout << "Agama            : " << ktp.agama << endl;
        cout << "Status Kawin     : " << ktp.status << endl;
        cout << "Pekerjaan        : " << ktp.pekerjaan << endl;
        cout << "Kewarganegaraan  : " << ktp.kewarganegaraan << endl;
        cout << "Berlaku Hingga   : SEUMUR HIDUP" << endl;
        cout << "====================================================================" << endl;
        cout << endl;
        
    }
    void simpanKeFile(const vector<KTP>& dataKTP) {
    ofstream file("data_ktp.txt");
        if (file.is_open()) {
            for (const auto& ktp : dataKTP) {
                file << "====================================================================" << endl;
                file << "NIK              : " << ktp.nik << endl;
                file << "Nama             : " << ktp.nama << endl;
                file << "Tempat/Tgl Lahir : " << ktp.tempat << "," << ktp.tl << endl;
                file << "Jenis Kelamin    : " << ktp.jk << "    " << "Gol. Darah :" << ktp.goldar << endl;
                file << "Alamat           : " << ktp.alamat << endl;
                file << "    RT/RW        : " << ktp.rt << "/" << ktp.rw << endl;
                file << "    Kel/Desa     : " << ktp.kel << endl;
                file << "    Kecamatan    : " << ktp.kec << endl;
                file << "Agama            : " << ktp.agama << endl;
                file << "Status Kawin     : " << ktp.status << endl;
                file << "Pekerjaan        : " << ktp.pekerjaan << endl;
                file << "Kewarganegaraan  : " << ktp.kewarganegaraan << endl;
                file << "Berlaku Hingga   : SEUMUR HIDUP" << endl;
                file << "====================================================================" << endl;
            }
            file.close();
        } else {
            cout << "Gagal membuka file!" << endl;
        }
    }
    void prosesKTP(){
        vector<KTP> dataKTP;
        int jumlahData;
        cout << "Berapa jumlah data KTP yang ingin dimasukkan? (Maksimal 3): ";
        cin >> jumlahData;
        cin.ignore(); // Mengabaikan newline setelah input jumlahData
        if (jumlahData > 3) {
            cout << "Jumlah maksimal data KTP yang bisa dimasukkan adalah 3." << endl;
            return;
        }
        // Input data KTP dari user
        for (int i = 0; i < jumlahData; i++) {
            cout << endl;
            cout << "Masukkan data KTP ke-" << i+1 << ":" << endl;
            dataKTP.push_back(inputKTP());
        }
        // Cetak data KTP ke layar
        for (const auto& ktp : dataKTP) {
            cetakKTP(ktp);
        }
        // Simpan data KTP ke file
        simpanKeFile(dataKTP);
        cout << "Data KTP telah disimpan ke file data_ktp.txt" << endl;
    }
};

int main() {
    data x;
      x.prosesKTP();  // Panggil fungsi untuk memproses data KTP
      return 0;
}
