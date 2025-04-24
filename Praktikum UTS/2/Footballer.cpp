#include "Footballer.hpp"

//   string name;
//   string playPosition;
//   int birthYear;

//   string nationality;
//   int height;
//   int weight;

  // Default cosntructor set nilai attribut sebagai berikut:
  // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  Footballer::Footballer(){
    name = "noname";
    birthYear = 2000;
    playPosition = "none";
    nationality = "Indonesia";
    height = 180;
    weight = 70;
  }

  // User-defined constructor:
  // set nilai atribut berdasarkan nilai parameter masukan
  // dengan urutan: name, birthYear, playPosition, nationality, height, weight
  Footballer::Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight){
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = playPosition;
    this->nationality = nationality;
    this->height = height;
    this->weight = weight;
  }

  // Copy constructor
  Footballer::Footballer (const Footballer& other){
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
  }

  // Destructor
  Footballer::~Footballer(){}

  // Operator assignment
  Footballer& Footballer::operator=(const Footballer& other){
    if (this != &other){
      this->name = other.name;
      this->birthYear = other.birthYear;
      this->playPosition = other.playPosition;
      this->nationality = other.nationality;
      this->height = other.height;
      this->weight = other.weight;
    }
    return *this;
  }

  // Getter dan setter name
  void Footballer::setName(string name){
    this->name = name;
  }
  string Footballer::getName() const{
    return name;
  }

  // Getter dan setter playPosition
  void Footballer::setPlayPosition(string pp){
    this->playPosition = pp;
  }
  string Footballer::getPlayPosition() const{
    return playPosition;
  }

  // Getter dan setter nationality
  void Footballer::setNationality(string n){
    this->nationality = n;
  }
  string Footballer::getNationality() const{
    return nationality;
  }

  // Getter dan setter height and weight
  void Footballer::setHeight(int h){
    this->height = h;
  }
  int Footballer::getHeight() const{
    return height;
  }
  void Footballer::setWeight(int w){
    this->weight = w;
  }
  int Footballer::getWeight() const{
    return weight;
  }

  // gunakan CURRENT_YEAR untuk menghitung umur
  int Footballer::getAge() const{
    return CURRENT_YEAR - birthYear;
  }

  // gunakan height and weight untuk menghitung BMI
  // BMI = weight(kg) / (height(m))²
  double Footballer::getBMI() const{
    if (height == 0) return 0;
    else{
      double h = height;
      double w = weight;
      return w / (h * h * 0.0001);
    }
  }

  // gunakan BMI untuk mendapat category
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
string Footballer::getCategory() const{
    double bmi = getBMI();
    if (bmi < 18.5) return "Underweight";
    if (bmi >= 18.5 && bmi < 25.0) return "Normal";
    if (bmi >= 25.0 && bmi < 30.0) return "Overweight";
    return "Obese";
}

  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  // Transfer Rate: {hasil pemanggilan transferRate()}
  void Footballer::displayInfo() const{
    cout << "Name: " << name << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << playPosition << endl;
    cout << "Nationality: " << nationality << endl;
    cout << fixed << setprecision(2);
    cout << "BMI: " << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl;
}

  int Footballer::transferRate() const{
    return 200;
  }