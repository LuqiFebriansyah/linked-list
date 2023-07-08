#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct divisi{
    string name;
    string tingkat;
};

struct pegawai{
    int ID;
    string nama;
    string jabatan;
};

typedef pegawai infotypePegawai;
typedef divisi infotypeDivisi;
typedef struct elmListDivisi *adrDivisi;
typedef struct elmListPegawai *adrPegawai;

struct elmListPegawai{
    infotypePegawai infoPegawai;
    adrPegawai nextPegawai;
    adrPegawai prev;
};

struct listPegawai{
    adrPegawai firstPegawai;
    adrPegawai lastPegawai;
};

struct elmListDivisi{
    infotypeDivisi infoDivisi;
    adrDivisi nextDivisi;
    adrPegawai nextPegawai;
};

struct listDivisi{
    adrDivisi firstDivisi;
};
adrDivisi findDivisi(listDivisi L, string name);
adrPegawai findPegawai(listDivisi L, string divisiName, int ID);
adrPegawai createElmPegawai(int ID, string nama, string jabatan);
adrDivisi createElmDivisi(string name, string tingkat);
void insertDivisi(listDivisi &L, string name, string tingkat);
void showAllDivisi(listDivisi L);
void deleteDivisi(listDivisi &L, string name);
void searchDivisi(listDivisi L, string name);
void insertPegawai(listDivisi &L, string divisiName, int ID, string nama, string jabatan);
void connectDivisiPegawai(listDivisi &L, string divisiName, int ID);
void showAllData(listDivisi L);
void searchPegawai(listDivisi L, string divisiName, int ID);
void deletePegawai(listDivisi &L, string divisiName, int ID);
void showDivisiMaxPegawai(listDivisi L);
void runProgram();
#endif // TUBES_H_INCLUDED
