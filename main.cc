#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

/**
 * Function #1:
 * 
 * Write a function that reverses a vector in-place.
 * Your function should augment the supplied vector VEC
 * to be in reverse order.
 * 
 * ex. {1, 2, 3, 4, 5 } -> { 5, 4, 3, 2, 1 }
 * 
*/
void reverseVec(vector<int> &vec) {
    for (int i = 0; i < vec.size()/2; i++) {
        int temp = vec[i];
        vec[i] = vec[vec.size() - 1 - i]; 
        vec[vec.size() - 1 - i] = temp;
    }
    //(void)vec; // TODO: Write code here!
}

/**
 * Function #2:
 * 
 * Write a function that takes in a string called MSG and 
 * replaces every instance of the letter "o" with "aur". 
 * Your function should preserve case.
 * 
 * ex. "NO Cleo!" -> "NAUR Cleaur!"
*/

string aurify_cpp(string msg) {
    //(void) msg; //TODO: Write code here!
    //return "";

    string toRet = "";
    for (int i = 0; i < msg.size(); i++) {
        if (msg[i] == 'o') {
            toRet += "aur";
        } else if (msg[i] == 'O') {
            toRet += "AUR";
        } else {
            toRet += msg[i];
        }
    }
    return toRet;
}

/**
 * Function #3:
 * 
 * Populate the vector TOKENS with each token in the PATH
 * variable, which is delimited by the '/' character.
 * 
 * ex. "Desktop/cs111/assignment1" -> { "Desktop", "cs111", "assignment1" }
 * 
 * Note that the path is a char * and the tokens use strings.
 * 
 * Bonus points if you use c-string operations to tokenize the path.
*/

void get_path (const char *path, vector<string>& tokens) {

    char buf[strlen(path) + 1];
    strcpy(buf, path);
    char *token = strtok(buf, "/");
    tokens.push_back(string(token));

    while (true) {
        // fix this line.
        char *token = strtok(NULL, "/");
        if (!token) break;
        tokens.push_back(string(token));
    }
}

/**
 * Function #4:
 * 
 * The CS department is trying to update their course catalog to increment
 * the unit count of ALL of their classes by 1. Unfortunately, their code
 * is not passing the autograder check. Please fix it by making the smallest
 * change(s) possible.
*/

struct course {
    string instructors;
	string code;
	int unit_count;
	double course_rating;
};

void increment_units (vector<course> &all_cs_courses) {
    for (course& c : all_cs_courses) {
        c.unit_count++;
    }
}



// Augograder down here. Ignore everything below this point.

int main() {

    vector<int> tests;
    tests.resize(4);

    // Running main just runs the test harness. You'll
    // Want to implement the functions below.
    vector<int> vec = { 1, 2, 3, 4, 5 };
    vector<int> reversed = {5, 4, 3, 2, 1 };
    reverseVec(vec);
    cout << "\nTesting Function #1: Vector Rerse" << endl;
    cout << "#################################" << endl;
    for (int i = 0; i < vec.size(); i++) {
        if (reversed[i] != vec[i]) {
            cout << "Error: mismatch at index " << i << endl;
            cout << "vec[i]: " << vec[i] << endl;
            cout << "reversed[i]: " << reversed[i] << endl; 
            tests[0] = 1;
        }
    }
    if (tests[0] == 0) {
        cout << "Function #1: Passes the sample test!" << endl;
    }

    cout << "#################################\n\n" << endl;

    cout << "Testing Function #2: O -> AUR on C++ strings" << endl;
    cout << "#################################" << endl;
    string msg1 = "oO o";
    string sol1 = "aurAUR aur";
    string student_sample = aurify_cpp(msg1);
    if (student_sample != sol1) {
        cout << "Sample mismatch!" << endl;
        cout << "Input: " << msg1 << endl;
        cout << "Expected Output: " << sol1 << endl;
        cout << "Actual Output: " << student_sample << endl;
        tests[1] = 1;
    }

    if (tests[1] == 0) {
        cout << "Function #2: Passes the sample test!" << endl;
    }

    cout << "#################################\n\n" << endl;

    cout << "Testing Function #3: Path Tokenization" << endl;
    cout << "#################################" << endl;

    vector<string> path;
    vector<string> sol = { "Desktop", "cs111", "assignment1" };
    const char * path_literal = "Desktop/cs111/assignment1";
    get_path(path_literal, path);
    for (int i = 0; i < path.size(); i++)  {
        if (sol[i] != path[i]) {
            cout << "Sample mismatch at index " << i << endl;
            cout << "Expected Output: " << sol[i] << endl;
            cout << "Actual Output: " << path[i] << endl; 
            tests[2] = 1;
        }
    }

    if (tests[2] == 0) {
        cout << "Function #3: Passes the sample test!" << endl;
    }

    cout << "#################################\n\n" << endl;


    cout << "Testing Function #4: Unit count increment" << endl;
    cout << "#################################" << endl;

    course c1 = {"","",1, 2.0};
    course c2 = {"","",4, 2.0};
    course c3 = {"","",2, 2.0};
    course c4 = {"","",3, 2.0};

    vector<course> cs_courses = { c1, c2, c3, c4 };
    auto dup = cs_courses;
    increment_units(cs_courses);
    for (int i = 0; i < cs_courses.size(); i++) {
        if (dup[i].unit_count != cs_courses[i].unit_count-1) {
            cout << "Sample mismatch!" << endl;
            cout << "Input: " << dup[i].unit_count << endl;
            cout << "Expected Output: " << (dup[i].unit_count + 1) << endl;
            cout << "Actual Output: " << cs_courses[i].unit_count << endl; 
            tests[3] == 1;
        }
    }

    if (tests[3] == 0) {
        cout << "Function #4: Passes the sample test!" << endl;
    }

    cout << "#################################\n\n" << endl;
}





