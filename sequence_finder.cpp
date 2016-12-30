#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const string DATA_DIR = "data/"; // data directory

bool greater_pair(const pair<string, unsigned long> &a,
                  const pair<string, unsigned long> &b) {
    return a.second > b.second;
}

void sequence(string inpath, string outpath, unsigned int n) {
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
        table.emplace_back(elem);
    }
    sort(table.begin(), table.end(), greater_pair);

    ofstream outfile{outpath, ios::out};
    for (auto &elem : table) {
        outfile << elem.first << "," << (double) elem.second / (double) char_count * 100 << endl;
    }

    outfile.close();
    infile.close();
}

int main() {
    sequence(DATA_DIR + "word-5000.csv", DATA_DIR + "two-seq-freq-5000.csv", 2);
    sequence(DATA_DIR + "word-5000.csv", DATA_DIR + "three-seq-freq-5000.csv", 3);
    sequence("data400k.txt", DATA_DIR + "two-seq-freq-400k.csv", 2);
    sequence("data400k.txt", DATA_DIR + "three-seq-freq-400k.csv", 3);
}
