#include "BigNumber.hpp"
using namespace std;

const int BigNumber::max_digit = 20;
BigNumber::BigNumber(){
    this->digit = new int[max_digit];
}

BigNumber::BigNumber(int number){
    this->digit = new int[max_digit];
    for (int i = 0; i < max_digit; i++){
        this->digit[i] = number % 10;
        number /= 10;
    }
}

BigNumber::BigNumber(string aVeryBigNumber){
    this->digit = new int[max_digit];
    int strSize = aVeryBigNumber.size();
    for (int i = 0; i < strSize; i++) {
        this->digit[i] = aVeryBigNumber[strSize - 1 - i] - '0';
    }
}

BigNumber::BigNumber(const BigNumber& bn){
    this->digit = new int[max_digit];
    for (int i = 0; i < max_digit; i++){
        this->digit[i] = bn.digit[i];
    }
}

BigNumber::~BigNumber(){
    delete[] this->digit;
}

int BigNumber::getMaxDigit(){
    return BigNumber::max_digit;
}

void BigNumber::setDigit(int i, int digit){
    this->digit[i] = digit;
}

int BigNumber::operator[](int i) const{
    return this->digit[i];
}
int& BigNumber::operator[](int i){
    return this->digit[i];
}

// implement method-method berikut
bool BigNumber::operator==(const BigNumber& other){
    for (int i = max_digit - 1; i >= 0; i--){
        if (this->digit[i] != other.digit[i]){
            return false;
        }
    }
    return true;
}
bool BigNumber::operator<(const BigNumber& other){
    for (int i = max_digit - 1; i >= 0; i--){
        if (this->digit[i] < other.digit[i]){
            return true;
        }
    }
    return false;
}

bool BigNumber::operator>(const BigNumber& other){
    for (int i = max_digit - 1; i >= 0; i--){
        if (this->digit[i] > other.digit[i]){
            return true;
        }
    }
    return false;
}
BigNumber BigNumber::operator+(const BigNumber& other){
    BigNumber temp;

    for (int i = 0 ; i < max_digit; i++){
        temp[i] = 0;
    }

    for (int i = 0; i < max_digit; i++) {
        temp[i] += digit[i] + other[i];
        if (temp[i] >= 10){
            temp[i] -= 10;
            temp[i+1]++;
      }
    }
    return temp;
  }