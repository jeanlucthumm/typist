#include <iostream>
#include <fstream>

using namespace std;

// Most common two letter combinations
void two_sequence() {
    unsigned long counter[26][26] = {0};
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

    // DEBUG print most common sequence
    int let1max = 0, let2max = 0;
    unsigned long max = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (counter[i][j] > max) {
                let1max = i;
                let2max = j;
                max = counter[i][j];
            }
        }
    }
    cout << "Most common combination: " << (char) (let1max + 'a') << " "
         << (char) (let2max + 'a')
         << " with count of " << max;
}

int main() {
    two_sequence();
}