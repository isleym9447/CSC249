/**
 * main.cpp - Driver program for Course class
 * CSC 249 - Module 1: Classes and Objects
 *
 * This program tests your Course class implementation.
 * Complete the TODOs below after implementing Course.h.
 *
 * To compile: g++ -o main main.cpp
 * To run: ./main
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "Course.h"

using namespace std;

int main() {
    cout << "=== CSC 249 Module 1: Classes and Objects ===" << endl;
    cout << endl;

    // =========================================================================
    // PART 1: Creating Course Objects
    // =========================================================================
    cout << "--- Part 1: Creating Course Objects ---" << endl;

    // Example: Creating a Course object (this one is done for you)
    Course dataStructures("Data Structures", "CSC 249-0901", 3,
                          "Dr. Smith", true);

    // TODO 1: Create a Course object for "Introduction to C++"
    //         Code: "CSC 134-0001", Credits: 3, Instructor: "Prof. Johnson"
    //         This course is NOT online (in-person).
    // Course introCpp(...);


    // TODO 2: Create a Course object for a course YOU are currently taking
    //         Use real or made-up data - your choice!
    // Course myCourse(...);


    cout << "Created 3 Course objects." << endl;
    cout << endl;

    // =========================================================================
    // PART 2: Using Getters
    // =========================================================================
    cout << "--- Part 2: Using Getters ---" << endl;

    // Example: Using getters to access data
    cout << "Course name: " << dataStructures.getName() << endl;
    cout << "Course code: " << dataStructures.getCode() << endl;

    // TODO 3: Print the credits and instructor for the introCpp course
    //         Use the appropriate getter methods.
    // cout << "Intro C++ credits: " << ... << endl;
    // cout << "Intro C++ instructor: " << ... << endl;


    // TODO 4: Print whether your course (myCourse) is online or in-person
    //         HINT: getIsOnline() returns a bool, so you might want to use
    //         a conditional to print "Online" or "In-Person"
    // cout << "My course is: " << ... << endl;

    cout << endl;

    // =========================================================================
    // PART 3: Using Setters
    // =========================================================================
    cout << "--- Part 3: Using Setters ---" << endl;

    // Example: Using a setter to modify data
    cout << "Changing Data Structures instructor..." << endl;
    dataStructures.setInstructor("Dr. Williams");
    cout << "New instructor: " << dataStructures.getInstructor() << endl;

    // TODO 5: Change the introCpp course to be online (it was in-person)
    //         Then print confirmation using the getter.
    // introCpp.setIsOnline(...);
    // cout << "Intro C++ is now: " << ... << endl;


    // TODO 6: Test the validation! Try setting credits to an invalid value.
    //         Set dataStructures credits to 10 (invalid - should clamp to 5)
    //         Then print the actual value to verify clamping worked.
    // dataStructures.setCredits(10);
    // cout << "After setting to 10, credits are: " << ... << endl;

    cout << endl;

    // =========================================================================
    // PART 4: Using toString()
    // =========================================================================
    cout << "--- Part 4: Using toString() ---" << endl;

    // Example: Using toString() for formatted output
    cout << dataStructures.toString() << endl;

    // TODO 7: Print the introCpp and myCourse objects using toString()
    // cout << introCpp.toString() << endl;
    // cout << myCourse.toString() << endl;

    cout << endl;

    // =========================================================================
    // PART 5: Objects in a Collection (Preview of Coming Attractions)
    // =========================================================================
    cout << "--- Part 5: Why Objects Matter ---" << endl;

    // This demonstrates why objects are better than parallel arrays.
    // When we put objects in a vector, all the data stays together!

    vector<Course> courses;
    courses.push_back(dataStructures);
    // TODO 8: Add your other two courses to the vector
    // courses.push_back(introCpp);
    // courses.push_back(myCourse);

    cout << "All courses in the vector:" << endl;
    for (int i = 0; i < courses.size(); i++) {
        cout << "  " << courses[i].toString() << endl;
    }

    // Sorting by name - notice how all the data stays together!
    // (We'll learn more about sorting algorithms in Module 3)
    cout << "\nSorted by name:" << endl;
    sort(courses.begin(), courses.end(),
         [](const Course& a, const Course& b) {
             return a.getName() < b.getName();
         });

    for (int i = 0; i < courses.size(); i++) {
        cout << "  " << courses[i].toString() << endl;
    }

    cout << endl;
    cout << "=== End of Module 1 Demo ===" << endl;

    return 0;
}
