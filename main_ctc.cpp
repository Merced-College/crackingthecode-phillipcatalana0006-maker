#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include <math.h>

using namespace std;
using namespace std::chrono;

const string CHARSET = "0123456789abcd";
//const int SIZE_PW = 4;//relates to the size of the password

const int PW_LENGTH = 10;

// Function to generate a random x-digit passcode
string generatePasscode() {
    // return rand() % SIZE_PW; // Ensures x-digit number (1000-9999)
    string pw = "";
    for (int i = 0; i < PW_LENGTH; i++) {
        pw += CHARSET[rand() % CHARSET.size()];
    }
    return pw;
}

int main() {
    srand(time(0)); // Seed for random number generation
    string passcode = generatePasscode();

    //cout << "A x-digit passcode has been generated. Try to crack it!" << endl;
    cout << "A mixed-character passcode has been generated. Try to crack it!" << endl;

    cout<<passcode<<endl;

    // Start Timer
    auto start = high_resolution_clock::now();

    // Students will write their algorithm here to find 'passcode'

    //int guess = 0;
    //long long attempts = 0;

    /*for (guess = 0; guess < SIZE_PW; guess++) {
        attempts++;
        if (guess == passcode) {
            break;
        }
    }*/

    long long attempts = 0;

    int base = CHARSET.size();
    long long maxAttempts = pow(base, PW_LENGTH);
    
    for (long long i = 0; i < maxAttempts; i++){
        long long temp = i;
        string guess = "";
        for (int j = 0; j < PW_LENGTH; j++) {
            guess = CHARSET[temp % base] + guess;
            temp /= base;
        }
        attempts++;

        if (guess == passcode) {
            break;
        }
    }

    

    // Stop Timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Passcode cracked in: " << duration.count() << " nanoseconds!" << endl;
    cout << "Attempts: " << attempts << endl;


    return 0;
}
