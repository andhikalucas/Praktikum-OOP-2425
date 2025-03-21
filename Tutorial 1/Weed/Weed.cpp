#include "Weed.hpp"
using namespace std;

Weed::Weed(){
    this->many = 1;
}       
// Membuat Weed dengan jumlah kawanan 1

Weed::Weed(int n){
    this->many = n;
}  
// Membuat Weed dengan jumlah kawanan n

Weed::Weed(const Weed &b){
    this->many = b.many;
}

Weed::~Weed(){}

void Weed::step(){
    for (int i = 0; i < many; i++){
        cout << "kresek...";
    }
    cout << endl;
}  
// Menghasilkan bunyi "kresek..." berulang
// sebanyak n kawanan