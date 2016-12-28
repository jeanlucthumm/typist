#include <iostream>
#include <fstream>

// Which fingers belong to which key in std model, numbered 1-8 excluding thumbs from l->r
static int data[26] = {
        1, 4, 4, 3, 3, 4, 4, 5, 6, 5, 6, 7, 5, 5, 7, 8, 1, 4, 2,
        4, 5, 4, 2, 2, 5, 1
};

bool is_same_finger(char a, char b) {
    return data[a - 'a'] == data[b - 'a'];
}
