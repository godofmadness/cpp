//
//  main.cpp
//  lab10(3)
//
//  Created by Max on 4/12/17.
//  Copyright © 2017 Saske. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;


double mSin(double x) {
    return sin(x);
}

double kv(double x) {
    return pow(x, 2);
}

double gip(double a, double b) {
    return sqrt(pow(a,2) + pow(b,2));
}

double mExp(double x, double y) {
    return pow(x, y);
}

int main(int argc, const char * argv[]) {
    double result = 0;
    
    double (*pSin)(double) = mSin;
    double (*pKv)(double) = kv;
    double (*pGip)(double, double) = gip;
    double (*pExp)(double, double) = mExp;
    
    
    try {
        if (argc <= 1) throw runtime_error("You need to enter commandline params");
        if (argc == 2) throw runtime_error("You need to enter parameters");
        if (!(strcmp(argv[1],"sin"))) {
            
            result = pSin(stod(argv[2]));
            
        } else if(!(strcmp(argv[1],"kv"))) {
            
            result = pKv(stod(argv[2]));
            
        } else if(!(strcmp(argv[1],"gip"))) {
            
            if (argc < 4) throw runtime_error("Not enough parameters");
            
            result = pGip(stod(argv[2]), stod(argv[3]));
            
        } else if (!(strcmp(argv[1],"exp"))) {
            
            if (argc < 4) throw runtime_error("Not enough parameters");
            
            result = pExp(stod(argv[2]), stod(argv[3]));
            
        } else {
            throw runtime_error("No such function");
        }
        
        cout << result << endl;
    } catch(runtime_error e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
