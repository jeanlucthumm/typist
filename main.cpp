#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool greater_pair(const pair<string, unsigned long> &a,
                  const pair<string, unsigned long> &b) {
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
}

void three_sequence() {
    map<string, unsigned long> counter;
    vector<pair<string, unsigned long>> table;
    ifstream infile{"w.csv"};

    // Process every word
    string word;
    while (getline(infile, word)) {
        // Find letter combinations
        for (int i = 0; i < word.size() - 2; i++) {
            char let1 = word[i] - 'a';
            char let2 = word[i + 1] - 'a';
            char let3 = word[i + 2] - 'a';
        }
    }
}


void sequence(string inpath, unsigned int n) {
    map<string, unsigned long> counter;

    ifstream infile{inpath};

    // Process every word
    string word;
    while (getline(infile, word)) {
        // Find letter combinations up to n
        for (int i = 0; i < (int) (word.size() - (n - 1)); ++i) {
            // Get substring
            string substring;
            substring = word.substr((unsigned int) i, n);

            // Process substring
            if (substring.find('-') != string::npos) continue; // dash not important
            if (substring.find('/') != string::npos) continue; // slash not important
            transform(substring.begin(), substring.end(), substring.begin(), ::tolower);

            // Increment counter for substring
            if (counter.find(substring) == counter.end()) {
                counter[substring] = 1;
            } else {
                counter[substring]++;
            }
        }
    }

    cout << counter.size() << endl;

    // DEBUG
    for (auto &elem : counter) {
        cout << elem.first << " : " << elem.second << endl;
    }

    infile.close();
}

int main() {
    sequence("w.csv", 3);
//    sequence("words.txt", 2);
}