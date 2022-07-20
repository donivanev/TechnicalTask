#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

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
