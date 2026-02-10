/**
 * Course_test.h - Completed Course class implementation for testing
 * This file is used to verify the module deliverables compile correctly.
 */

#ifndef COURSE_TEST_H
#define COURSE_TEST_H

#include <string>

class Course {
private:
    std::string name;
    std::string code;
    int credits;
    std::string instructor;
    bool isOnline;

public:
    Course(std::string name, std::string code, int credits,
           std::string instructor, bool isOnline);

    std::string getName() const;
    std::string getCode() const;
    int getCredits() const;
    std::string getInstructor() const;
    bool getIsOnline() const;

    void setName(std::string name);
    void setCode(std::string code);
    void setCredits(int credits);
    void setInstructor(std::string instructor);
    void setIsOnline(bool isOnline);

    std::string toString() const;
};

// Constructor implementation
Course::Course(std::string name, std::string code, int credits,
               std::string instructor, bool isOnline) {
    this->name = name;
    this->code = code;
    setCredits(credits);
    this->instructor = instructor;
    this->isOnline = isOnline;
}

// Getter implementations
std::string Course::getName() const {
    return name;
}

std::string Course::getCode() const {
    return code;
}

int Course::getCredits() const {
    return credits;
}

std::string Course::getInstructor() const {
    return instructor;
}

bool Course::getIsOnline() const {
    return isOnline;
}

// Setter implementations
void Course::setName(std::string name) {
    this->name = name;
}

void Course::setCode(std::string code) {
    this->code = code;
}

void Course::setCredits(int credits) {
    if (credits < 1) {
        this->credits = 1;
    } else if (credits > 5) {
        this->credits = 5;
    } else {
        this->credits = credits;
    }
}

void Course::setInstructor(std::string instructor) {
    this->instructor = instructor;
}

void Course::setIsOnline(bool isOnline) {
    this->isOnline = isOnline;
}

// Display implementation
std::string Course::toString() const {
    std::string mode = isOnline ? "Online" : "In-Person";
    return code + ": " + name + " (" + std::to_string(credits) + " credits) - " + instructor + " [" + mode + "]";
}

#endif // COURSE_TEST_H
