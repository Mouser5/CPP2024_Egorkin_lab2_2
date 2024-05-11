#include <iostream>
#include <vector>
#include <string>
#include "Header.h"
#include <ctime>﻿
using namespace std;

class Student {
private:
    string name;
    char mark;
    vector <double> ans;
public:
    Student(const string _name, const int number) {
        ans.resize(2);
        name = _name;
        Get_Mark(mark);
        Get_ans(ans, mark, number);
    }
    void Get_Mark(char& mark) {
        srand(time(0));
        int score = rand() % (3) + 3;
        if (score == 3) {
            mark = 'C';
            return;
        }
        if (score == 4) {
            mark = 'B';
            return;
        }
            mark = 'A';
            return;
    }
    void FindRoots(vector <double>& ans, const int number) {
        double a = 0, b = 0, c = 0, D = 0;
        InputData(a, b, c,number);
        Discriminant(a, b, c, D);
        if (D == 0) {
            Root(a, b, c, D, ans[0]);
            ans[1] = NULL;
        }
        if (D < 0) {
            ans[0] = NULL;
        }
        if (D > 0)
            Roots(a, b, c, D, ans[0],ans[1]);
    }

    void Get_ans(vector <double>& ans, const char mark, const int number) {

        if (mark == 'A') {
            FindRoots(ans, number);
            return;
        }
        if (mark == 'C') {
            ans[0] = 0.0;
            return;
        }
        if (mark == 'B') {
            int chance = rand() % (20) + 1;
            if (chance <= 11)
                FindRoots(ans, number);
            else
                ans[0] = 0.0;
            return;
        }
    }
    void PrintResult(const int number) {
        cout << "Number:" << number << endl;
        cout << name<<endl;
        if (ans[0] == NULL) {
            cout << "There are no roots.";
        }
        else
            cout << ans[0]<<" ";
        if (ans[1] != NULL) {
            cout << ans[1];
        }
        ans.clear();
    }
};

int main()
{
    string name;
    int number;
    cin >> name >> number;
    Student* a = new Student(name, number);
    a->PrintResult(number);
}