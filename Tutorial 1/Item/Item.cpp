#include "Item.hpp"

int Item::totalItems = 0;
int Item::totalRevenue = 0;

/* Ctor default: stok adalah 0 dan harga barang adalah 0 */
Item::Item() : serialNum (totalItems + 1){
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum (totalItems + 1){
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems ++;
}

/* cctor item, mengkopi seluruh atribut item, termasuk atribut sold */
Item::Item(const Item& other) : serialNum (totalItems + 1){
    this->stock = other.stock;
    this->price = other.price;
    this->sold = other.sold;
    totalItems ++;
}

Item::~Item() {
}
	
int Item::getSerialNum() const{
    return this->serialNum;
}

int Item::getSold() const{
    return this->sold;
}

int Item::getPrice() const{
    return this->price;
}

/* Menambahkan stok item. Tidak akan bernilai negatif. */
void Item::addStock(int addedStock){
    this->stock += addedStock;
}

/* Menjual item. Jika item tidak cukup, maka item terjual hanya sampai stok item habis */
void Item::sell(int soldStock){
    if (stock < soldStock){
        sold += stock;
        totalRevenue += stock * price;
        stock = 0;
    }
    else { // stock >= soldStock
        sold += soldStock;
        totalRevenue += soldStock * price;
        stock -= soldStock;
    }
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}