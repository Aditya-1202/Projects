#include <stdio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isNumberString(const string& s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string ccNumber;

    cout << "This program uses Luhn Algorigthm to check a credit card number." << endl;
    cout << "You can enter 'exit' to quit." << endl;

    while (true) {

        cout << "Please enter a CC number to validate: ";
        cin >> ccNumber;

        if (ccNumber == "exit"){ break;}
           

        else if (!isNumberString(ccNumber)) {
            cout << "The input should consist of digits between 0 and 9 ";
            continue;
        }

        int n = ccNumber.length();
        int Sum = 0;  

        for (int i = n - 2; i >= 0; i -= 2) {
            int dbl = ((ccNumber[i] - '0') * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            Sum += dbl;
        }

        for (int i = n - 1; i >= 0; i = i-=2) {
            Sum += (ccNumber[i] - '0');
        }

        if(Sum%10 == 0){cout<<"The number is valid"<<endl;}
        else {cout<<"The number is invalid"<<endl;}

        continue;        
    }

    return 0;
}
