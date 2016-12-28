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

void sequence(string inpath, unsigned int n) {
    map<string, unsigned long> counter;
    unsigned long char_count = 0; // used to compute %

    ifstream infile{inpath};

    // Process every word
    string word;
    while (getline(infile, word)) {
        if (word.size() > 1) char_count += word.size();
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

    // Sort map into vector
    vector<pair<string, unsigned long>> table;
    for (auto &elem : counter) {
        table.push_back(elem);
    }
    sort(table.begin(), table.end(), greater_pair);

    ofstream outfile{"outfile.txt", ios::out};
    for (auto &elem : table) {
        outfile << elem.first << "," << (double) elem.second / (double) char_count * 100 << endl;
    }

    outfile.close();
    infile.close();
}

int main() {
    sequence("w.csv", 2);
//    sequence("words.txt", 2);
}
