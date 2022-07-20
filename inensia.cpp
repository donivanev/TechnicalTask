#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

/*
We need to store anonymous data about programmers' salary and position.
Create a binary file called salary.bin.
Until there is input from the console write the data to the file.
Then read the file and calculate the average salary of a position including a word read from the console. Round the result to 2 decimal places.

Example:

Input:

Java Developer 4200
C++ Developer 5000
Javascript Developer 1000
Junior C++ Developer 1500
Software Engineer 3400
Game Developer (C++) 4000
C++

Output: Average C++ salary is: 7833,33
*/

int main()
{
    fstream file;
    file.open("salary.bin", ios::out | ios::binary);
    string input;
    double average = 0.0, salary = 0.0;

    if (!file) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    do {
        getline(cin, input);
        cout << input << endl;
        file.write(&input[0], input.size());
        file.put('\n');
    } while (input.length() != 0);

    char word[32];
    cin >> word;
    string line;

    file.open("salary.bin", ios::in | ios::binary);

    while (getline(file, line, '\n')) {
        if (line.find(word) != string::npos) { 
            vector<string> result;
            stringstream ss(line);
            string s;

            while (getline(ss, s, ' ')) {
                result.push_back(s);
            }

            salary = stod(result.back());
            average += salary;
        }
    }

    cout << "Average C++ salary is: " << setprecision(2) << average;

    file.close();

    return 0;
}