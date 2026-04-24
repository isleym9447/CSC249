#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// =====================
// EXERCISE 1: HASH FUNCTION
// =====================
unsigned long hashPassword(string password) {
    unsigned long hash = 0;

    for (char c : password) {
        hash = hash * 31 + c;
    }

    return hash;
}

// =====================
// EXERCISE 2: BASIC USER SYSTEM
// =====================
struct UserRecord {
    string username;
    unsigned long hashedPassword;
};

UserRecord registerUser(string username, string password) {
    UserRecord user;
    user.username = username;
    user.hashedPassword = hashPassword(password);

    cout << "User " << username << " registered. Stored hash: "
         << user.hashedPassword << endl;

    return user;
}

bool loginUser(UserRecord user, string attemptedPassword) {
    unsigned long attemptHash = hashPassword(attemptedPassword);

    if (attemptHash == user.hashedPassword) {
        cout << "Login successful" << endl;
        return true;
    } else {
        cout << "Login failed" << endl;
        return false;
    }
}

// =====================
// EXERCISE 3: SALTED SYSTEM
// =====================
struct SaltedUserRecord {
    string username;
    unsigned long hashedPassword;
    string salt;
};

string generateSalt(int length) {
    const string chars =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    string salt = "";

    for (int i = 0; i < length; i++) {
        salt += chars[rand() % chars.size()];
    }

    return salt;
}

SaltedUserRecord registerSaltedUser(string username, string password) {
    SaltedUserRecord user;

    user.username = username;
    user.salt = generateSalt(8);

    string combined = password + user.salt;
    user.hashedPassword = hashPassword(combined);

    cout << "User " << username << " registered.\n";
    cout << "Salt: " << user.salt << endl;
    cout << "Hash: " << user.hashedPassword << endl;

    return user;
}

bool loginSaltedUser(SaltedUserRecord user, string attemptedPassword) {
    string combined = attemptedPassword + user.salt;
    unsigned long attemptHash = hashPassword(combined);

    if (attemptHash == user.hashedPassword) {
        cout << "Login successful" << endl;
        return true;
    } else {
        cout << "Login failed" << endl;
        return false;
    }
}

// =====================
// MAIN TESTING
// =====================
int main() {
    srand(time(0)); // IMPORTANT: only once

    // ===== Exercise 1 Tests =====
    cout << "Hash tests:\n";
    cout << hashPassword("password") << endl;
    cout << hashPassword("password") << endl;
    cout << hashPassword("Password") << endl;
    cout << hashPassword("123456") << endl;

    cout << "\n";

    // ===== Exercise 2 Tests =====
    UserRecord alice = registerUser("alice", "securePass99");

    loginUser(alice, "securePass99");   // success
    loginUser(alice, "securepass99");   // fail
    loginUser(alice, "wrongpassword");  // fail

    cout << "\nStored user data:\n";
    cout << alice.username << " | " << alice.hashedPassword << endl;

    cout << "\n";

    // ===== Exercise 3 Tests =====
    SaltedUserRecord bob = registerSaltedUser("bob", "123456");
    SaltedUserRecord carol = registerSaltedUser("carol", "123456");

    cout << "\n";

    loginSaltedUser(bob, "123456");   // success
    loginSaltedUser(bob, "654321");   // fail
    loginSaltedUser(carol, "123456"); // success

    return 0;
}