// Gradebook.hpp
#include "Gradebook.hpp"

// #include <string>
// #include <map>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// class Gradebook
// {
// private:
//     // Struktur data utama: memetakan nama mahasiswa (string) ke nilai (double)
//     map<string, double> studentGrades;

    /*
     * Menambah atau mengupdate nilai mahasiswa.
     * Jika mahasiswa sudah ada, nilainya akan diupdate.
     * Jika mahasiswa belum ada, akan ditambahkan dengan nilai yang diberikan.
     */
    void Gradebook::addOrUpdateStudent(const string &studentName, double grade){
        studentGrades[studentName] = grade; // Menambah key jika tidak ada, meng-update jika ada

        // Alternatif lain jika ingin insert apabila key belum ada
        // studentGrades.insert({studentName, grade});
    }

    /*
     * Menghapus mahasiswa dari gradebook.
     * Mengembalikan true jika mahasiswa ditemukan dan berhasil dihapus,
     * false jika tidak ditemukan.
     */
    bool Gradebook::removeStudent(const string &studentName){
        // Cara 1: menggunakan count() untuk menentukan apakah ada value atau tidak pada key. (karena map disini 1 atau 0 doang)
        if (studentGrades.count(studentName) > 0){
            studentGrades.erase(studentName);
            return true;
        } else return false;

        // Cara 2: menggunakan find() untuk menentukan index nya pada map. Jika tidak ada key, maka iterator akan berakhir di end().
        auto it = studentGrades.find(studentName);
        if (it != studentGrades.end()){
            studentGrades.erase(it); // Menghapus mahasiswa dari gradebook
            return true; // Mahasiswa ditemukan dan dihapus
        } else return false; // Mahasiswa tidak ditemukan
    }

    /*
     * Mengambil nilai dari mahasiswa tertentu.
     * Mengembalikan true jika mahasiswa ditemukan dan nilainya disimpan
     * di parameter 'grade', false jika mahasiswa tidak ditemukan.
     */
    bool Gradebook::getGrade(const string &studentName, double &grade) const{
        // Mari menggunakan count()
        if (studentGrades.count(studentName) > 0){
            grade = studentGrades.at(studentName);
            return true;
        } else return false;
    }

    /*
     * Memeriksa apakah mahasiswa ada dalam gradebook.
     * Mengembalikan true jika mahasiswa ada, false jika tidak.
     */
    bool Gradebook::studentExists(const string &studentName) const{
        return studentGrades.count(studentName) > 0;
    }

    /*
     * Mencetak semua nama mahasiswa dan nilai mereka
     * Jika gradebook kosong, akan mencetak pesan "Gradebook kosong\n"
     * Format:
     * 1. <nama_mahasiswa>: <nilai>
     * 2. <nama_mahasiswa>: <nilai>
     * ...
     */
    void Gradebook::printGrades() const{
        if (studentGrades.empty()){
            cout << "Gradebook kosong\n";
        }
        else{
            int i = 1;
            for (auto it = studentGrades.begin(); it != studentGrades.end(); ++it){
                cout << i << ". " << it->first << ": " << it->second << endl; // First adalah key, second adalah value
                i++;
            }
            // Alternatif lain menggunakan range-based for loop
            // for (const auto &student : studentGrades){
            //     cout << i << ". " << student.first << ": " << student.second << endl;
            //     i++;
            // }
        }
    }

    /*
     * Mencetak semua nama mahasiswa dan nilai mereka, terurut berdasarkan nilai terbesar ke terkecil.
     * Hint: gunakan vector<pair<string, double>> untuk menyimpan semua data mahasiswa untuk memudahkan pengurutan. Gunakan fungsi bantuan untuk komparasi pada std::sort.
     * Format:
     * 1. <nama_mahasiswa>: <nilai>
     * 2. <nama_mahasiswa>: <nilai>
     * ...
     */
    void Gradebook::printGradesRank() const{
        vector<pair<string, double>> v(studentGrades.begin(), studentGrades.end()); // Mengubah map ke vector

        sort(v.begin(), v.end(), [](const pair<string, double> &a, const pair<string, double> &b){
            return a.second > b.second; // Mengurutkan berdasarkan nilai terbesar ke terkecil
        });
        // Instead of argument sepanjang itu, bisa diseperate ke custom function
        // bool compare(const pair<string, double> &a, const pair<string, double> &b){
        //     return a.second > b.second
        // }
        // Nanti panggil di sort dengan sort(v.begin(), v.end(), compare);
        int i = 1;
        for (auto student : v){
            cout << i++ << ". " << student.first << ": " << student.second << endl;
        }
    }

    /*
     * Mengembalikan daftar nama mahasiswa yang nilainya di atas threshold tertentu.
     * Mengembalikan vector berisi nama mahasiswa dengan nilai lebih besar dari threshold,
     * terurut berdasarkan abjad.
     */
    vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const{
        vector<string> daftar;
        for (auto student : studentGrades){
            if (student.second > threshold){
                daftar.push_back(student.first); // Append ke vector
            }
        }
        return daftar;
    }

    /*
     * Menghitung rata-rata nilai semua mahasiswa dalam gradebook.
     * Mengembalikan rata-rata nilai, atau 0.0 jika gradebook kosong.
     */
    double Gradebook::getAverageGrade() const{
        if (studentGrades.empty()){
            return 0.0; // Gradebook kosong
        } else {
            double total = 0.0;
            for (auto student : studentGrades){
                total += student.second; // Menjumlahkan semua nilai mahasiswa
            }
            return total / studentGrades.size(); // Mengembalikan rata-rata
        }
    }

    /*
     * Mengembalikan jumlah mahasiswa yang ada dalam gradebook.
     */
    size_t Gradebook::getNumberOfStudents() const{
        return studentGrades.size();
    }