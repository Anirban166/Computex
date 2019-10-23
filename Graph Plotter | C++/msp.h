#ifndef MSP_H
#define MSP_H

#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

using namespace std;

class msp
{
    public:
        msp(string infix);

        double returnYvalue(double xVal);

    private:
        string input; // input Infix

        int prec(char c);
        int endPosOfTrigFuncInfix(string s, int pos);
        string trigFunctionValueInString(int posOfLbracket, string s, string trigFuncName);
        string infixToPostfix(string s);
        double evaluatePostfix(string s);
        template <class T>
        T multiCharDigitToNumber(T intOrDec, string inputCharDigits);
};

#endif // MSP_H
