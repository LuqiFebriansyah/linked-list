#include"tubes.h"
adrDivisi findDivisi(listDivisi L, string name){
    adrDivisi divisiPtr = L.firstDivisi;
    while (divisiPtr != NULL){
        if (divisiPtr->infoDivisi.name == name){
            return divisiPtr;
        }
        divisiPtr = divisiPtr->nextDivisi;
    }
    return NULL;
}

// Fungsi untuk mencari pegawai berdasarkan ID pada suatu divisi
adrPegawai findPegawai(listDivisi L, string divisiName, int ID){
    adrDivisi divisiPtr = findDivisi(L, divisiName);
    if (divisiPtr != NULL){
        adrPegawai pegawaiPtr = divisiPtr->nextPegawai;
        while (pegawaiPtr != NULL){
            if (pegawaiPtr->infoPegawai.ID == ID){
                return pegawaiPtr;
            }
            pegawaiPtr = pegawaiPtr->nextPegawai;
        }
    }
    return NULL;
}

// Fungsi untuk menciptakan elemen pegawai baru
adrPegawai createElmPegawai(int ID, string nama, string jabatan){
    adrPegawai newPegawai = new elmListPegawai;
    newPegawai->infoPegawai.ID = ID;
    newPegawai->infoPegawai.nama = nama;
    newPegawai->infoPegawai.jabatan = jabatan;
    newPegawai->nextPegawai = NULL;
    newPegawai->prev = NULL;
    return newPegawai;
}

// Fungsi untuk menciptakan elemen divisi baru
adrDivisi createElmDivisi(string name, string tingkat){
    adrDivisi newDivisi = new elmListDivisi;
    newDivisi->infoDivisi.name = name;
    newDivisi->infoDivisi.tingkat = tingkat;
    newDivisi->nextDivisi = NULL;
    newDivisi->nextPegawai = NULL;
    return newDivisi;
}

// Fungsi untuk memasukkan data divisi dari depan
void insertDivisi(listDivisi &L, string name, string tingkat){
    adrDivisi newDivisi = createElmDivisi(name, tingkat);
    if (L.firstDivisi == NULL){
        L.firstDivisi = newDivisi;
    } else {
        newDivisi->nextDivisi = L.firstDivisi;
        L.firstDivisi = newDivisi;
    }
}

// Fungsi untuk menampilkan seluruh data divisi
void showAllDivisi(listDivisi L){
    adrDivisi divisiPtr = L.firstDivisi;
    while (divisiPtr != NULL){
        cout << "Nama Divisi: " << divisiPtr->infoDivisi.name << endl;
        cout << "Tingkat: " << divisiPtr->infoDivisi.tingkat << endl;
        cout << endl;
        divisiPtr = divisiPtr->nextDivisi;
    }
}

// Fungsi untuk menghapus data divisi dan pegawainya
void deleteDivisi(listDivisi &L, string name){
    adrDivisi divisiPtr = L.firstDivisi;
    adrDivisi prevDivisi = NULL;

    while (divisiPtr != NULL && divisiPtr->infoDivisi.name != name){
        prevDivisi = divisiPtr;
        divisiPtr = divisiPtr->nextDivisi;
    }

    if (divisiPtr != NULL){
        if (prevDivisi == NULL){
            L.firstDivisi = divisiPtr->nextDivisi;
        } else {
            prevDivisi->nextDivisi = divisiPtr->nextDivisi;
        }
        adrPegawai pegawaiPtr = divisiPtr->nextPegawai;
        while (pegawaiPtr != NULL){
            adrPegawai nextPegawai = pegawaiPtr->nextPegawai;
            delete pegawaiPtr;
            pegawaiPtr = nextPegawai;
        }
        delete divisiPtr;
        cout << "Divisi dan pegawainya berhasil dihapus" << endl;
    } else {
        cout << "Divisi tidak ditemukan" << endl;
    }
}

// Fungsi untuk mencari data divisi
void searchDivisi(listDivisi L, string name){
    adrDivisi divisiPtr = findDivisi(L, name);
    if (divisiPtr != NULL){
        cout << "Nama Divisi: " << divisiPtr->infoDivisi.name << endl;
        cout << "Tingkat: " << divisiPtr->infoDivisi.tingkat << endl;
    } else {
        cout << "Divisi tidak ditemukan" << endl;
    }
}

// Fungsi untuk memasukkan data pegawai dari belakang
void insertPegawai(listDivisi &L, string divisiName, int ID, string nama, string jabatan){
    adrDivisi divisiPtr = findDivisi(L, divisiName);
    if (divisiPtr != NULL){
        adrPegawai newPegawai = createElmPegawai(ID, nama, jabatan);
        if (divisiPtr->nextPegawai == NULL){
            divisiPtr->nextPegawai = newPegawai;
        } else {
            adrPegawai pegawaiPtr = divisiPtr->nextPegawai;
            while (pegawaiPtr->nextPegawai != NULL){
                pegawaiPtr = pegawaiPtr->nextPegawai;
            }
            pegawaiPtr->nextPegawai = newPegawai;
            newPegawai->prev = pegawaiPtr;
        }
    } else {
        cout << "Divisi tidak ditemukan" << endl;
    }
}

// Fungsi untuk menghubungkan data divisi ke data pegawai
void connectDivisiPegawai(listDivisi &L, string divisiName, int ID){
    adrDivisi divisiPtr = findDivisi(L, divisiName);
    adrPegawai pegawaiPtr = findPegawai(L, divisiName, ID);
    if (divisiPtr != NULL && pegawaiPtr != NULL){
        pegawaiPtr->nextPegawai = divisiPtr->nextPegawai;
        divisiPtr->nextPegawai = pegawaiPtr;
    } else {
        cout << "Divisi atau pegawai tidak ditemukan" << endl;
    }
}

// Fungsi untuk menampilkan seluruh data divisi beserta pegawainya
void showAllData(listDivisi L){
    adrDivisi divisiPtr = L.firstDivisi;
    while (divisiPtr != NULL){
        cout << "Nama Divisi: " << divisiPtr->infoDivisi.name << endl;
        cout << "Tingkat: " << divisiPtr->infoDivisi.tingkat << endl;

        adrPegawai pegawaiPtr = divisiPtr->nextPegawai;
        while (pegawaiPtr != NULL){
            cout << "ID Pegawai: " << pegawaiPtr->infoPegawai.ID << endl;
            cout << "Nama Pegawai: " << pegawaiPtr->infoPegawai.nama << endl;
            cout << "Jabatan: " << pegawaiPtr->infoPegawai.jabatan << endl;
            cout << endl;
            pegawaiPtr = pegawaiPtr->nextPegawai;
        }

        divisiPtr = divisiPtr->nextDivisi;
        cout << endl;
    }
}

// Fungsi untuk mencari data pegawai pada divisi tertentu
void searchPegawai(listDivisi L, string divisiName, int ID){
    adrPegawai pegawaiPtr = findPegawai(L, divisiName, ID);
    if (pegawaiPtr != NULL){
        cout << "ID Pegawai: " << pegawaiPtr->infoPegawai.ID << endl;
        cout << "Nama Pegawai: " << pegawaiPtr->infoPegawai.nama << endl;
        cout << "Jabatan: " << pegawaiPtr->infoPegawai.jabatan << endl;
    } else {
        cout << "Pegawai tidak ditemukan" << endl;
    }
}

// Fungsi untuk menghapus data pegawai pada divisi tertentu
void deletePegawai(listDivisi &L, string divisiName, int ID){
    adrDivisi divisiPtr = findDivisi(L, divisiName);
    if (divisiPtr != NULL){
        adrPegawai pegawaiPtr = divisiPtr->nextPegawai;
        adrPegawai prevPegawai = NULL;

        while (pegawaiPtr != NULL && pegawaiPtr->infoPegawai.ID != ID){
            prevPegawai = pegawaiPtr;
            pegawaiPtr = pegawaiPtr->nextPegawai;
        }

        if (pegawaiPtr != NULL){
            if (prevPegawai == NULL){
                divisiPtr->nextPegawai = pegawaiPtr->nextPegawai;
            } else {
                prevPegawai->nextPegawai = pegawaiPtr->nextPegawai;
            }
            delete pegawaiPtr;
            cout << "Pegawai berhasil dihapus" << endl;
        } else {
            cout << "Pegawai tidak ditemukan" << endl;
        }
    } else {
        cout << "Divisi tidak ditemukan" << endl;
    }
}

// Fungsi untuk menampilkan divisi dengan pegawai terbanyak
void showDivisiMaxPegawai(listDivisi L){
    adrDivisi divisiMax = L.firstDivisi;
    int maxPegawai = 0;

    adrDivisi divisiPtr = L.firstDivisi;
    while (divisiPtr != NULL){
        adrPegawai pegawaiPtr = divisiPtr->nextPegawai;
        int count = 0;
        while (pegawaiPtr != NULL){
            count++;
            pegawaiPtr = pegawaiPtr->nextPegawai;
        }
        if (count > maxPegawai){
            maxPegawai = count;
            divisiMax = divisiPtr;
        }
        divisiPtr = divisiPtr->nextDivisi;
    }

    if (divisiMax != NULL){
        cout << "Divisi dengan pegawai terbanyak:" << endl;
        cout << "Nama Divisi: " << divisiMax->infoDivisi.name << endl;
        cout << "Tingkat: " << divisiMax->infoDivisi.tingkat << endl;
        cout << "Jumlah Pegawai: " << maxPegawai << endl;
    } else {
        cout << "Tidak ada divisi" << endl;
    }
}

// Fungsi untuk menjalankan main program
void runProgram(){
    listDivisi perusahaan;
    perusahaan.firstDivisi = NULL;

    string  choice;
    string divisiName, tingkat, nama, jabatan;
    int ID;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert data divisi dari depan" << endl;
        cout << "2. Show all data divisi" << endl;
        cout << "3. Menghapus data divisi dan pegawainya" << endl;
        cout << "4. Mencari data divisi" << endl;
        cout << "5. Insert data pegawai dari belakang" << endl;
        cout << "6. Menghubungkan data divisi ke data pegawai" << endl;
        cout << "7. Menampilkan seluruh data divisi beserta pegawainya" << endl;
        cout << "8. Mencari data pegawai pada divisi tertentu" << endl;
        cout << "9. Menghapus data pegawai pada divisi tertentu" << endl;
        cout << "10. Menampilkan divisi dengan pegawai terbanyak" << endl;
        cout << "11. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        if (choice == "1"){
            cout << "Masukkan nama divisi: ";
            cin >> divisiName;
            cout << "Masukkan tingkat: ";
            cin >> tingkat;
            insertDivisi(perusahaan, divisiName, tingkat);
            cout << "Data divisi berhasil dimasukkan" << endl;
        }else if(choice == "2"){
            cout << "Data seluruh divisi: " << endl;
            showAllDivisi(perusahaan);
        }else if (choice =="3"){
            cout << "Masukkan nama divisi yang akan dihapus: ";
            cin >> divisiName;
            deleteDivisi(perusahaan, divisiName);

        }else if (choice =="4"){
            cout << "Masukkan nama divisi yang akan dicari: ";
            cin >> divisiName;
            searchDivisi(perusahaan, divisiName);

        }else if (choice =="5"){
            cout << "Masukkan nama divisi: ";
            cin >> divisiName;
            cout << "Masukkan ID pegawai: ";
            cin >> ID;
            cout << "Masukkan nama pegawai: ";
            cin >> nama;
            cout << "Masukkan jabatan pegawai: ";
            cin >> jabatan;
            insertPegawai(perusahaan, divisiName, ID, nama, jabatan);
            cout << "Data pegawai berhasil dimasukkan" << endl;

        }else if(choice =="6"){
            cout << "Masukkan nama divisi: ";
            cin >> divisiName;
            cout << "Masukkan ID pegawai: ";
            cin >> ID;
            connectDivisiPegawai(perusahaan, divisiName, ID);
            /*cout << "Data divisi berhasil dihubungkan ke data pegawai" << endl;*/

        }else if(choice =="7"){
            cout << "Data seluruh divisi beserta pegawainya: " << endl;
            showAllData(perusahaan);
            cout << "Tekan 'Enter' untuk melanjutkan...";
            cin.ignore(); // Ignore the newline character from the previous input
            cin.get();    // Wait for user input to continue

        }else if (choice == "8"){
            cout << "Masukkan nama divisi: ";
            cin >> divisiName;
            cout << "Masukkan ID pegawai: ";
            cin >> ID;
            searchPegawai(perusahaan, divisiName, ID);
        }else if (choice == "9"){
            cout << "Masukkan nama divisi: ";
            cin >> divisiName;
            cout << "Masukkan ID pegawai: ";
            cin >> ID;
            deletePegawai(perusahaan, divisiName, ID);
        }else if (choice == "10"){
            showDivisiMaxPegawai(perusahaan);
        }else if (choice == "11"){
            cout << "Terima kasih!" << endl;
        }else {
            cout << "Pilihan tidak valid" << endl;
        }

        cout << endl;
        /*(system("pause");*/
    } while (choice != "11");
}
