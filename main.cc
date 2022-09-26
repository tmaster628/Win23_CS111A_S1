#include <iostream>
#include <vector>

using namespace std;

void reverseVec(vector<int> &vec);


int main() {
    vector<int> vec = { 1, 2, 3, 4, 5 };
    reverseVec(vec);
   
    /* Print vector. */
    cout << "vec = {  ";
    for (int n : vec) cout << n << ", ";
    cout << " }" << endl;
}



void reverseVec(vector<int> &vec) {
    (void)vec; // TODO: Write code here!
}

