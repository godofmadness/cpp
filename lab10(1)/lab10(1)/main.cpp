//
//  main.cpp
//  lab10(1)
//
//  Created by Max on 4/11/17.
//  Copyright © 2017 Saske. All rights reserved.
//

#include <iostream>
using namespace std;



int length(char* str) {
    int charCounter = 0;
    
    for (int i = 0; i < 100; i++) {
        if (str[i] == '\0') {
            return charCounter;
        }
        charCounter++;
    }
    return -1;
}

int numberOfSpaces(char* str){
 
    int numberOfSpaces = 0;
    for (int i = 0; i < 100; i++) {
        if (str[i] == ' ') {
            numberOfSpaces++;
        } else if (str[i] == '\0') {
            return numberOfSpaces;
        }
    }
    return -1;
}

int positionOfFirstSpace(char* str){
    for (int i = 0; i < 100; i++) {
        if (str[i] == ' ') {
            return i;
        } else if (str[i] == '\0') {
            return 0;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...

//    char* str = new char();
    
    char str [50];
    for (int i = 0; i < 50; i++) {
        str[i] = '0';
    }
    
    int (*pArrayOfFunctions[3])(char*) = {length, numberOfSpaces, positionOfFirstSpace};
    
    cout << "Enter string:!\n";
    cin.getline(str, 50);
    
    cout << "Enter 1 - length\nEnter 2 nubmer Of spaces\nEnter 3 - first space postition\n";
    string buffer;
    int result = 0;
    int choice;
    bool valid = false;

    
    while (!valid) {
        try {
            cin >> buffer;
            choice = stoi(buffer);
            result = pArrayOfFunctions[choice-1](str);
            result == - 1 ? throw runtime_error("fatal error") :
            valid = true;
        } catch(invalid_argument e) {
            cout << "You entered invalid argument." << endl;
        } catch(runtime_error e) {
            cout << e.what() << endl;
        }
    }
    
    cout << "RESULT: " << result << endl;
 


    
    
    return 0;
}
