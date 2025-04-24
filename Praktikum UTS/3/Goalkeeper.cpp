#include "Goalkeeper.hpp"

//   int cleanSheets;
//   int saves;
//   int totalShotsOnGoal;

  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
    // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  Goalkeeper::Goalkeeper(): Footballer(){
    cleanSheets = 0;
    saves = 0;
    totalShotsOnGoal = 0;
    playPosition = "goalkeeper";
  }

  // User-defined constructor
  // parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
  // set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
  // nationality, height, dan weight gunakan nilai default superclass
  Goalkeeper::Goalkeeper(string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal): Footballer(){
    this->cleanSheets = cleanSheets;
    this->saves = saves;
    this->totalShotsOnGoal = totalShotsOnGoal;
    playPosition = "goalkeeper";
    this->name = name;
    this->birthYear = birthYear;
  }

  // Getter dan Setter untuk cleanSheets
  void Goalkeeper::setCleanSheets(int a){
    cleanSheets = a;
  }
  int Goalkeeper::getCleanSheets(){
    return cleanSheets;
  }

  // Getter dan Setter untuk saves
  void Goalkeeper::setSaves(int a){
    saves = a;
  }
  int Goalkeeper::getSaves(){
    return saves;
  }

  // Getter dan Setter untuk totalShotsOnGoal
  void Goalkeeper::setTotalShotsOnGoal(int a){
    totalShotsOnGoal = a;
  }
  int Goalkeeper::getTotalShotsOnGoal(){
    return totalShotsOnGoal;
  }

  // Method tambahan: savePercentage
  // rumus: (saves / totalShotsOnGoal) * 100
  // return dalam bentuk float
  float Goalkeeper::savePercentage(){
    if (totalShotsOnGoal == 0) return 0.0;
    return (static_cast<float> (saves) / totalShotsOnGoal) * 100;
  }

  // Override transferRate:
  // rumus: (700.000 * cleanSheets) + (50.000 * saves)
  // hasil berupa int
  int Goalkeeper::transferRate() {
    return (700000 * cleanSheets) + (50000 * saves);
  }

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
  // Format:
  // Clean Sheets: <cleanSheets>
  // Saves: <saves>
  // Save Percentage: <savePercentage>% 
  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  void Goalkeeper::displayInfo(){
    Footballer::displayInfo();
    cout << "Clean Sheets: " << cleanSheets << endl;
    cout << "Saves: " << saves << endl;
    cout << "Save Percentage: " << fixed << setprecision(2) << savePercentage() << "%" << endl;
}