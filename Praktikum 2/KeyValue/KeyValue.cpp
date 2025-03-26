#include <iostream>
using namespace std;

template <class T1, class T2>
class KeyValue{
    private:
        T1 keys[10];
        T2 values[10];
        int n; // Jumlah set yang sudah terdefinisi

    public:
        /* CTOR */
        KeyValue() : n(0) {} // bisa initialize biasa pake this->n = 0. initializer list ini lebih efisien aja

        /* HELPER */
        bool isEqual(double a, double b){
            return (a - b < 0.01) && (b - a < 0.01);
        }
      
        template <typename U>
        bool isEqual(U a, U b){
            return a == b;
        }

        /* METHOD */
        void set (T1 key, T2 value){
            if (n >= 10){
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            }
            else{
                // If key already in keys
                for (int i = 0; i < n; i++){
                    if (isEqual(keys[i], key)){
                        values[i] = value;
                        return;
                    }
                }
                // If key not in keys
                keys[n] = key;
                values[n] = value;
                n++;
            }
        }

        void display(T1 key){
            for (int i = 0; i < n; i++){
                if (isEqual(keys[i], key)){
                    cout << values[i] << endl;
                    return;
                }
            }
            cout << "Key tidak ditemukan!" << endl;
        }    
};
