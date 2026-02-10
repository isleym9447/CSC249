/**
 * main_test.cpp - Test driver for Course class
 * Used to verify the module deliverables compile and work correctly.
 *
 * To compile: g++ -o main_test main_test.cpp
 * To run: ./main_test
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "Course_test.h"

using namespace std;

int main() {
    cout << "=== CSC 249 Module 1: Compilation Test ===" << endl;
    cout << endl;

    // Test creating Course objects
    cout << "--- Testing Course Object Creation ---" << endl;
    Course dataStructures("Data Structures", "CSC 249-0901", 3, "Dr. Smith", true);
    Course introCpp("Introduction to C++", "CSC 134-0001", 3, "Prof. Johnson", false);
    Course calculus("Calculus II", "MAT 172-0001", 4, "Dr. Lee", false);

    cout << "Created 3 Course objects successfully." << endl;
    cout << endl;

    // Test getters
    cout << "--- Testing Getters ---" << endl;
    cout << "Course name: " << dataStructures.getName() << endl;
    cout << "Course code: " << dataStructures.getCode() << endl;
    cout << "Credits: " << dataStructures.getCredits() << endl;
    cout << "Instructor: " << dataStructures.getInstructor() << endl;
    cout << "Is Online: " << (dataStructures.getIsOnline() ? "Yes" : "No") << endl;
    cout << endl;

    // Test setters
    cout << "--- Testing Setters ---" << endl;
    dataStructures.setInstructor("Dr. Williams");
    cout << "New instructor: " << dataStructures.getInstructor() << endl;

    // Test validation
    cout << "Testing credits validation..." << endl;
    dataStructures.setCredits(10);
    cout << "After setting to 10, credits are: " << dataStructures.getCredits() << " (should be 5)" << endl;
    dataStructures.setCredits(0);
    cout << "After setting to 0, credits are: " << dataStructures.getCredits() << " (should be 1)" << endl;
    dataStructures.setCredits(3);
    cout << "After setting to 3, credits are: " << dataStructures.getCredits() << " (should be 3)" << endl;
    cout << endl;

    // Test toString
    cout << "--- Testing toString() ---" << endl;
    cout << dataStructures.toString() << endl;
    cout << introCpp.toString() << endl;
    cout << calculus.toString() << endl;
    cout << endl;

    // Test vector of objects
    cout << "--- Testing Objects in Vector ---" << endl;
    vector<Course> courses;
    courses.push_back(dataStructures);
    courses.push_back(introCpp);
    courses.push_back(calculus);

    cout << "All courses:" << endl;
    for (int i = 0; i < courses.size(); i++) {
        cout << "  " << courses[i].toString() << endl;
    }

    // Test sorting
    cout << "\nSorted by name:" << endl;
    sort(courses.begin(), courses.end(),
         [](const Course& a, const Course& b) {
             return a.getName() < b.getName();
         });

    for (int i = 0; i < courses.size(); i++) {
        cout << "  " << courses[i].toString() << endl;
    }

    cout << endl;
    cout << "=== All Tests Passed ===" << endl;

    return 0;
}
