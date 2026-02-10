# Module 1: Classes and Objects

## Overview

This module introduces **classes and objects** — the fundamental building blocks for all data structures we'll study this semester. Students will understand why objects are better than parallel arrays and implement a `Course` class with getters, setters, and display methods.

## Learning Objectives

By the end of this module, students will be able to:

1. Explain why parallel arrays are problematic for managing related data
2. Define a class with private member variables and public methods
3. Implement getters and setters with basic validation
4. Create and manipulate objects in both C++ and Python
5. Understand the relationship between classes (blueprints) and objects (instances)

## Contents

### Lecture Materials

| Resource | Description |
|----------|-------------|
| [m1-classes-objects.md](lecture/m1-classes-objects.md) | Main lecture document (concise version) |
| [m1-supplemental-notes.md](lecture/m1-supplemental-notes.md) | Comprehensive notes for deeper learning |
| [m1-slides.pptx](lecture/m1-slides.pptx) | Slide deck (17 slides) |

### Interactive Demo

| Resource | Description |
|----------|-------------|
| [parallel-arrays-demo.html](demo/parallel-arrays-demo.html) | Visual demonstration of the parallel arrays problem |

Open in a browser to see how sorting breaks parallel arrays but keeps objects intact.

### Assignment Files

**C++ Version** (`assignment/cpp/`)
- `Course.h` - Class skeleton with TODOs
- `main.cpp` - Driver program with TODOs

**Python Version** (`assignment/python/`)
- `course.py` - Class skeleton with TODOs
- `main.py` - Driver program with TODOs

## Assignment Summary

Students receive a skeleton `Course` class with:
- 5 private fields: `name`, `code`, `credits`, `instructor`, `isOnline`
- Method stubs for getters, setters, and display

**Tasks:**
1. Implement all getters (return private fields)
2. Implement all setters (with validation for credits: clamp to 1-5)
3. Implement `toString()` / `__str__()` for formatted display
4. Complete the `main` program to create and test Course objects

## Compilation / Execution

### C++
```bash
cd assignment/cpp
g++ -o main main.cpp
./main
```

### Python
```bash
cd assignment/python
python main.py
```

## Key Concepts Covered

- **Class**: Blueprint defining state (data) and behavior (methods)
- **Object**: Instance of a class with actual values
- **Encapsulation**: Hiding internal details, providing controlled access
- **Getters/Setters**: Methods for reading/writing private data with validation
- **Constructor**: Special method that initializes new objects
- **State vs. Behavior**: Data the object holds vs. operations it can perform

## Connection to Future Modules

This foundational material prepares students for:

- **Linked Lists** (M4): Node objects pointing to other Node objects
- **Stacks & Queues** (M4): Objects controlling data flow
- **Trees** (M6): Objects in parent-child hierarchies
- **Hash Tables** (M5): Objects enabling fast key-value lookup

## Estimated Time

- Lecture/reading: 45-60 minutes
- Interactive demo: 10 minutes
- Assignment: 60-90 minutes

---

*CSC 249 - Data Structures*
