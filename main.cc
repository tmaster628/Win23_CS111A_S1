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
    // TODO: Implement me!
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
    // TODO: Implement me!
    return msg;
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
 * (This is because in a C environment, you can't use strings, but in a
 * CPP environment, you can still use C-strings).
*/

void get_path (const char *path, vector<string>& tokens) {
    // TODO: Implement me!
    (void) path, tokens;
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
    for (course c : all_cs_courses) {
        c.unit_count++;
    }
}

/**
 * Function #5:
 * 
 * After fixing their bug, the CS department has hired you for more jobs. This time,
 * they want you correct the ALL_CS_COURSES vector to include accurate COURSE_RATING
 * values. Currently, the COURSE_RATING value for every class in the vector is 0.0.
 * 
 * Luckily, you're given a map called RATINGS that maps string course codes to double 
 * course ratings.
 * 
 * Your task is to ensure that the vector ALL_CS_COURSES has the correct ratings for 
 * every course.
 * 
 * ex. all_cs_course: { "troccoli", "CS111", 5, 0.0 } -> { "troccoli", "CS111", 5, 5.0 }
*/


void change_rating (vector<course> &all_cs_courses, const map<string, double> &ratings) {
    // TODO: Implement me!
    (void) all_cs_courses, ratings;
}



// Augograder down here. Ignore everything below this point.

int main() {

    vector<int> tests;
    tests.resize(5);

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
    } else {
        cout << "Function #1: FAILS the sample test!" << endl;
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
    } else {
        cout << "Function #2: FAILS the sample test!" << endl;
    }

    cout << "#################################\n\n" << endl;

    cout << "Testing Function #3: Path Tokenization" << endl;
    cout << "#################################" << endl;

    vector<string> path;
    vector<string> sol = { "Desktop", "cs111", "assignment1" };
    const char * path_literal = "Desktop/cs111/assignment1";
    get_path(path_literal, path);
    if (sol.size() != path.size()) {
        cout << "Path output and solution output do not match!" << endl;
        cout << "Expected output size: 3" << endl;
        cout << "Actual output size: " << path.size() << endl;
        tests[2] = 1;
    } else {
        for (int i = 0; i < sol.size(); i++)  {
            if (sol[i] != path[i]) {
                cout << "Sample mismatch at index " << i << endl;
                cout << "Expected Output: " << sol[i] << endl;
                cout << "Actual Output: " << path[i] << endl; 
                tests[2] = 1;
            }
        }
    }

    if (tests[2] == 0) {
        cout << "Function #3: Passes the sample test!" << endl;
    } else {
        cout << "Function #3: FAILS the sample test!" << endl;
    }

    cout << "#################################\n\n" << endl;


    cout << "Testing Function #4: Unit count increment" << endl;
    cout << "#################################" << endl;

    course c1 = {"Troccoli","CS111",1, 0.0};
    course c2 = {"Gregg","CS107",4, 0.0};
    course c3 = {"Schwarz","CS106B",2, 0.0};
    course c4 = {"Parlante","CS106A",3, 0.0};

    vector<course> cs_courses = { c1, c2, c3, c4 };
    auto dup = cs_courses;
    increment_units(cs_courses);
    for (int i = 0; i < cs_courses.size(); i++) {
        if (dup[i].unit_count != cs_courses[i].unit_count-1) {
            cout << "Sample mismatch!" << endl;
            cout << "Input: " << dup[i].unit_count << endl;
            cout << "Expected Output: " << (dup[i].unit_count + 1) << endl;
            cout << "Actual Output: " << cs_courses[i].unit_count << endl; 
            tests[3] = 1;
        }
    }

    if (tests[3] == 0) {
        cout << "Function #4: Passes the sample test!" << endl;
    } else {
        cout << "Function #4: FAILS the sample test!" << endl;
    }

    cout << "#################################\n\n" << endl;

    cout << "Testing Function #5: Updating Course Mappings" << endl;
    cout << "#################################" << endl;

    course c1_2 = {"Troccoli","CS111",5, 0.0};
    course c2_2 = {"Gregg","CS107",5, 0.0};
    course c3_2 = {"Schwarz","CS106B",5, 0.0};
    course c4_2 = {"Parlante","CS106A",5, 0.0};

    vector<course> cs_courses_ = { c4_2, c3_2, c2_2, c1_2 };// Don't ask.

    map<string, double> course_ratings = { {"CS106A", 4.5 }, {"CS106B", 4.5}, {"CS107", 4.7}, {"CS111", 5.0}};
    auto elem = course_ratings.begin();

    change_rating (cs_courses_, course_ratings);
    for (int i = 0; i < course_ratings.size(); i++) {
        if (cs_courses_[i].course_rating != (*elem).second) {
            cout << "Sample mismatch!" << endl;
            cout << "Expected Output: " << (*elem).first << ": "<<(*elem).second << endl;
            cout << "Actual Output: " << cs_courses_[i].code  << ": "<< cs_courses_[i].course_rating << endl; 
            tests[4] = 1;
        }
        elem++;
    }

    if (tests[4] == 0) {
        cout << "Function #5: Passes the sample test!" << endl;
    } else {
        cout << "Function #5: FAILS the sample test" << endl;
    }

    cout << "#################################\n\n" << endl;
    
    int num_pass = 5;
    for (int i = 0; i < 5; i++) {
        num_pass -= tests[i];
    }
    cout << "You passed " << num_pass << " of the provided tests.";
    if (num_pass == 5) cout << "Wahoo!" << endl;
    else cout << endl;
}





