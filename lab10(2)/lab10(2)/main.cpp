//
//  main.cpp
//  lab10(2)
//
//  Created by Max on 4/12/17.
//  Copyright © 2017 Saske. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

double equation1(double x, int differentiate ) {
//    cout << "1" << endl;
    if (differentiate == 1) {
        return -5 * cos(5 * x) + 2;
    } else if (differentiate == 2) {
        return 25 * sin(5 * x);
    }
    return 2 * x - sin(5 * x);
}

double equation2(double x, int differentiate ) {
//    cout << "2" << endl;
    if (differentiate == 1) {
        return pow(3 * x, 2) + sin(x);
    } else if (differentiate == 2) {
        return 18 * x + cos(x);
    }
    return pow(x,3) - cos(x);
}

double equation3(double x, int differentiate ) {
//    cout << "3" << endl;
    if (differentiate == 1) {
        return 2 * x - 5 * cos(5 * x);
    } else if (differentiate == 2) {
        return 25 * sin(5 * x) + 2;
    }
    return pow(x, 2) - sin(5 * x);
}

double equation4(double x, int differentiate ) {
//    cout << "4" << endl;
    if (differentiate == 1) {
        return sin(x) + 2 * cos(x);
    } else if (differentiate == 2) {
        return -2 * sin(x) + cos(x);
    }
    return 2 * sin(x) - cos(x);
}


double findEquasionRootsUsingNutonMethod(double* gap, double accuracy, double (*pEquation)(double x, int dif)) {

    double x0 = gap[1];
    double x;
    
    // if f(x) * f''(x) > 0 x = b else x = a
    pEquation(x0, 1) * pEquation(x0, 2) > 0 ? x = gap[1] : x = gap[0];
    
    do {
        try {
            x0 = x;
            // setting 2nd argument to true like sayong that we want differential of this equation
            x = x0 - pEquation(x, 0) / pEquation(x, 1);
        } catch (invalid_argument e) {
            cout << "Check input params";
            return -1;
        }
        
    } while(fabs(x0 - x) > accuracy);
    
    return x;
}


int main(int argc, const char * argv[]) {
    bool valid = false;
    
    double (*pEquations[4])(double x, int dif) = {equation1, equation2, equation3, equation4};
    
    string buffer;
    int choice;
    double result;
    
    double* gap = new double[2];
    gap[0] = 0.4;
    gap[1] = 1.0;
    
    double accuracy = 0.0001;
    
    while (!valid) {
        try {
            cin >> buffer;
            choice = stoi(buffer);
            
            result = findEquasionRootsUsingNutonMethod(gap, accuracy, pEquations[choice-1]);
            if (result < 0) throw runtime_error("Fatal error");
            valid = true;
            cout << result << endl;
            
        } catch(invalid_argument e) {
            cout << "You entered invalid argument." << endl;
        } catch(runtime_error e) {
            cout << e.what() << endl;
        }
    }
    
    
    
    
    
    
}
