#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<double> grades(n), creditHours(n);
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << (i + 1) << ":\n";

        cout << "  Enter grade point (e.g., 4.0, 3.7, 3.3...): ";
        cin >> grades[i];

        cout << "  Enter credit hours: ";
        cin >> creditHours[i];

        totalCredits += creditHours[i];
        totalGradePoints += grades[i] * creditHours[i];
    }

    double gpa = totalGradePoints / totalCredits;

    // Display individual course grades
    cout << "\n----- Course Summary -----\n";
    cout << left << setw(10) << "Course" << setw(15) << "Grade Point" << setw(15) << "Credit Hours" << "\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << (i + 1) << setw(15) << grades[i] << setw(15) << creditHours[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credit Hours: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nSemester GPA: " << gpa;

    // Since this covers a single semester, overall CGPA = semester GPA here.
    // If extending to multiple semesters, accumulate totalCredits/totalGradePoints across semesters.
    cout << "\nOverall CGPA: " << gpa << endl;

    return 0;
}
