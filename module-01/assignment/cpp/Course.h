/**
 * Course.h - Course class definition
 * CSC 249 - Module 1: Classes and Objects
 *
 * This header file contains a skeleton for the Course class.
 * Your task: Implement the getters, setters, and toString() method.
 *
 * A Course object bundles together all the data for a single course,
 * keeping related information together so it can be sorted, searched,
 * and manipulated as a unit.
 */

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    // === STATE (member variables) ===
    // These are private - external code cannot access them directly.
    // This protects the internal state and allows validation in setters.

    std::string name;       // Course title, e.g., "Data Structures"
    std::string code;       // Course code, e.g., "CSC 249-0901"
    int credits;            // Credit hours (valid range: 1-5)
    std::string instructor; // Instructor name
    bool isOnline;          // true if online, false if in-person

public:
    // === BEHAVIOR (member functions/methods) ===

    /**
     * Constructor - initializes a Course with all its data
     *
     * @param name       The course title
     * @param code       The course code
     * @param credits    Credit hours (will be clamped to 1-5)
     * @param instructor The instructor's name
     * @param isOnline   Whether the course is delivered online
     */
    Course(std::string name, std::string code, int credits,
           std::string instructor, bool isOnline);

    // --- GETTERS ---
    // These provide read-only access to private member variables.
    // TODO: Implement each getter to return the corresponding member variable.

    std::string getName() const;
    std::string getCode() const;
    int getCredits() const;
    std::string getInstructor() const;
    bool getIsOnline() const;

    // --- SETTERS ---
    // These allow controlled modification of private member variables.
    // TODO: Implement each setter to update the corresponding member variable.
    // NOTE: setCredits should validate the input (clamp to range 1-5).
    //       For now we use simple clamping; proper exception handling
    //       will be introduced in a later module.

    void setName(std::string name);
    void setCode(std::string code);
    void setCredits(int credits);
    void setInstructor(std::string instructor);
    void setIsOnline(bool isOnline);

    // --- DISPLAY ---
    // TODO: Implement toString() to return a formatted string representation.
    // Example output: "CSC 249-0901: Data Structures (3 credits) - Dr. Smith [Online]"
    //
    // NOTE: Some designs choose to separate display/UI logic into a different
    // class or layer. For simplicity, we include it here. This is a common
    // pattern for simple classes, but be aware that larger systems may
    // benefit from separating "what the data is" from "how it's displayed."

    std::string toString() const;
};

// =============================================================================
// IMPLEMENTATION SECTION
// Implement each method below the class definition.
// In larger projects, implementations often go in a separate .cpp file.
// =============================================================================

// Constructor implementation
Course::Course(std::string name, std::string code, int credits,
               std::string instructor, bool isOnline) {
    // TODO: Initialize all member variables.
    // HINT: Use the setters where appropriate (especially for credits)
    //       to ensure validation is applied consistently.

}

// --- GETTER IMPLEMENTATIONS ---

std::string Course::getName() const {
    // TODO: Return the course name
    return ""; // Replace this
}

std::string Course::getCode() const {
    // TODO: Return the course code
    return ""; // Replace this
}

int Course::getCredits() const {
    // TODO: Return the credit hours
    return 0; // Replace this
}

std::string Course::getInstructor() const {
    // TODO: Return the instructor name
    return ""; // Replace this
}

bool Course::getIsOnline() const {
    // TODO: Return whether the course is online
    return false; // Replace this
}

// --- SETTER IMPLEMENTATIONS ---

void Course::setName(std::string name) {
    // TODO: Set the course name

}

void Course::setCode(std::string code) {
    // TODO: Set the course code

}

void Course::setCredits(int credits) {
    // TODO: Set the credit hours WITH VALIDATION
    // If credits < 1, set to 1
    // If credits > 5, set to 5
    // Otherwise, use the provided value
    //
    // NOTE: This simple clamping approach is a stopgap. In production code,
    // you might throw an exception to alert the caller of invalid input.
    // We'll cover exception handling in a later module.

}

void Course::setInstructor(std::string instructor) {
    // TODO: Set the instructor name

}

void Course::setIsOnline(bool isOnline) {
    // TODO: Set the online status

}

// --- DISPLAY IMPLEMENTATION ---

std::string Course::toString() const {
    // TODO: Return a formatted string representation of the course
    // Format: "CODE: Name (X credits) - Instructor [Online/In-Person]"
    // Example: "CSC 249-0901: Data Structures (3 credits) - Dr. Smith [Online]"
    //
    // HINT: Use std::to_string() to convert int to string
    // HINT: Use a ternary operator for Online/In-Person: (condition ? "Yes" : "No")

    return ""; // Replace this
}

#endif // COURSE_H
