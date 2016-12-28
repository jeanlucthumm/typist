#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool greater_pair(const pair<string, unsigned long> &a,
                  const pair<string, unsigned long> &b)
{
    return a.second > b.second;
}

// Most common two letter combinations
void two_sequence() {
    unsigned long counter[26][26] = {0};
    vector<pair<string, unsigned long>> table; // holds <freq, string>
    ifstream infile("w.csv");   // use csvparser.py to generate this

    // Process every word
    string word;
    while (getline(infile, word)) {
        // Find letter combinations
        for (int i = 0; i < word.size() - 1; i++) {
            int let1 = word[i] - 'a';
            int let2 = word[i + 1] - 'a';
            counter[let1][let2]++; // register combination
        }
    }

    // Get a sortable list of the frequencies
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (counter[i][j] != 0) {
                string s = "";
                s += (char) (i + 'a');
                s += (char) (j + 'a');
                table.push_back(pair<string, unsigned long>{s, counter[i][j]});
            }
        }
    }

    // Sort frequencies
    sort(table.begin(), table.end(), greater_pair);

    // Output to file
    ofstream out{"two-seq-freq.csv", ios::out};
    for (auto &elem : table) {
        cout << elem.first << " : " << elem.second << endl; // DEBUG
        out << elem.first << "," << elem.second << endl;
    }

    infile.close();
    out.close();
}

// Most common three letter combinations
void three_sequence() {
    unsigned long counter[26][26] = {0};
    vector<pair<string, unsigned long>> table; // holds <freq, string>
    ifstream infile("w.csv");   // use csvparser.py to generate this

    // Process every word
    string word;
    while (getline(infile, word)) {
        // Find letter combinations
        for (int i = 0; i < word.size() - 1; i++) {
            int let1 = word[i] - 'a';
            int let2 = word[i + 1] - 'a';
            counter[let1][let2]++; // register combination
        }
    }

    // Get a sortable list of the frequencies
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (counter[i][j] != 0) {
                string s = "";
                s += (char) (i + 'a');
                s += (char) (j + 'a');
                table.push_back(pair<string, unsigned long>{s, counter[i][j]});
            }
        }
    }

    // Sort frequencies
    sort(table.begin(), table.end(), greater_pair);

    // DEBUG
    for (auto &elem : table) {
        cout << elem.first << " : " << elem.second << endl;
    }
}

int main() {
    two_sequence();
}