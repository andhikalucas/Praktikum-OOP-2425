#include "BarangElektronik.hpp"

// string nama;
// int berat; // dalam kg
//     int voltase;

BarangElektronik::BarangElektronik(string nama, int berat, int voltase): Barang(nama, berat){
    this->voltase = voltase;
}

int BarangElektronik::getVoltase() const{
    return this->voltase;
}

string BarangElektronik::getJenis() const {
    return "Elektronik";
}
