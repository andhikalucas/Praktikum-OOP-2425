#include <iostream>
#include "Gradebook.hpp"

using namespace std;

int main() {
    Gradebook gradebook;

    // Test addOrUpdateStudent
    gradebook.addOrUpdateStudent("Alice", 85.5);
    gradebook.addOrUpdateStudent("Bob", 90.0);
    gradebook.addOrUpdateStudent("Charlie", 78.0);
    gradebook.addOrUpdateStudent("Alice", 88.0); // Update Alice's grade

    // Test printGrades
    cout << "All Grades:" << endl;
    gradebook.printGrades();

    // Test getGrade
    double grade;
    if (gradebook.getGrade("Alice", grade)) {
        cout << "Alice's grade: " << grade << endl;
    } else {
        cout << "Alice not found!" << endl;
    }

    // Test studentExists
    cout << "Does Bob exist? " << (gradebook.studentExists("Bob") ? "Yes" : "No") << endl;

    // Test removeStudent
    cout << "Removing Charlie..." << endl;
    if (gradebook.removeStudent("Charlie")) {
        cout << "Charlie removed successfully." << endl;
    } else {
        cout << "Charlie not found!" << endl;
    }

    // Test printGradesRank
    cout << "\nGrades Ranked:" << endl;
    gradebook.printGradesRank();

    // Test getStudentsWithGradeAbove
    cout << "\nStudents with grades above 80:" << endl;
    vector<string> above80 = gradebook.getStudentsWithGradeAbove(80);
    for (const auto &student : above80) {
        cout << student << endl;
    }

    // Test getAverageGrade
    cout << "\nAverage Grade: " << gradebook.getAverageGrade() << endl;

    // Test getNumberOfStudents
    cout << "Number of Students: " << gradebook.getNumberOfStudents() << endl;

    return 0;
}