#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Course {
    string name;
    int credits;
    char grade;
};

double calculateGPA(vector<Course> courses) {
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (Course course : courses) {
        totalCredits += course.credits;

        switch (toupper(course.grade)) {
        case 'O':
            totalGradePoints += course.credits * 10.0;
            break;
        case 'A':
            totalGradePoints += course.credits * 8.0;
            break;
        case 'A' + :
            totalGradePoints += course.credits * 9.0;
            break;
        case 'B':
            totalGradePoints += course.credits * 6.0;
            break;
        case 'B' + :
            totalGradePoints += course.credits * 7.0;
            break;
        case 'C':
            totalGradePoints += course.credits * 5.0;
            break;
        case 'P':
            totalGradePoints += course.credits * 4.0;
            break;
        case 'F':
            totalGradePoints += course.credits * 0.0;
            break;
        default:
            totalGradePoints += course.credits * 0.0;
            break;
        }
    }

    return totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; i++) {
        cout << "Enter course " << (i + 1) << " details:" << endl;
        cout << "Name: ";
        getline(cin, courses[i].name);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Add this line
        cout << "Credits: ";
        cin >> courses[i].credits;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Grade (O, A+, A, B+, B, C, P, F): ";
        cin >> courses[i].grade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double cgpa = calculateGPA(courses);

    cout << "CGPA: " << cgpa << endl;

    return 0;
}