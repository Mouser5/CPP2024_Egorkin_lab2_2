#include "Header.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Discriminant(const double a, const double b, const double c, double& D) {
    D = b * b - 4 * a * c;
}

void Root(const double a, const double b, const double c, double D,double&x) {
    x = (-b + sqrt(D)) / (2 * a);
};

void Roots(const double a, const double b, const double c, double D, double& x1,double&x2) {
    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);
};

void InputData(double& a, double& b, double& c,const int num) {
    ifstream file("input.txt");
    string s;
    for (int i = 0; i < (num-1); i++) {
        getline(file, s);
    }
    file >> a>>b>>c;
}

