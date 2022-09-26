/* PointerPlayground.cpp
 * Author: Trip Master
 * -----------------------
 *
 * This file implements a simple pointer playground. Students will be able
 * to play around with a variety of pointer types, from struct pointers
 * to arrays. Is it even legal to have this much fun packed into one program?
 * We're not sure ourselves.
 *
 * No matter who you are, feel free to modify this file however you'd like--
 * it's meant to be a playground after all.
 *
 * If you're a student, I'd recommend reading through this code line by
 * line. I try my best to explain what the code is doing, and you can run the
 * program to examine the outputs I'm talking about -- I try to label things
 * best I can. Once again, feel free to make any changes you'd like if they
 * help you better understand what's going on.
 *
 * If you're a teacher, I'm not really sure how you can use this resource --
 * it falls in an awkward place between CS106B and CS107. Personally, these
 * are many usages of pointers that I saw in CS107 and never understood. I
 * imagine this being a resource for 106B students who want to learn more
 * about pointers and a review / sanity check for 107 students who want to
 * solidify their knowledge about pointers. Currently, I'm using this resource
 * in CS111A as a pointer refresher for CS107 graduates. For cleanliness, I 
 * don't discuss casting here (as it serves no purpose for 106B students), but 
 * once again, if you like anything here, feel free to use it and add to it. 
 * If you plan to use this resource on a large scale, it'd be cool if you could 
 * email me at tmaster@stanford.edu, and I'd be happy to support however I can.
 *
 * Last rev. 9/19/22 
 * -> Fixed a bug in explorePointersGalore where I was accidentally deleting stack
 * -> memory. Also tweaked the program to no longer rely on QT Creator.
 */

#include <iostream>
using namespace std;

/* Playground Routines */
void exploreInt();
void exploreCell();
void explorePointersGalore();

/* Struct declarations */

/* Type: CELL
 * ------------
 * The CELL type contains an int cellID and an int array cellValues. The
 * purpose of having multiple types is to get students comfortable with
 * nested pointers.
*/
struct Cell {
    int cellID;
    int* cellValues;
    Cell* next;
};



int main() {
    /* The pointer playground can be toggled with commenting. Simply
        comment out the calls to the functions you don't want to examine!*/

    /* Basic introduction to pointers, examining the * operator works and
        exploring nullptr and deleted memory. */
    exploreInt();

    /* Uses the Cell struct to show how the * and -> operators can do the
         same thing. */
    exploreCell();

    /* Briefly examines more layers of indirection using multiple nested
        pointers. */
    explorePointersGalore();


    return 0;
}

/**
 * exploreInt()
 * ----------
 * Examines stack and heap-allocated integer pointers. Briefly discusses
 * the array '[]' operators and introduces the dereference operator '*'
 * as a way to follow a memory address to the value in memory.
 */
void exploreInt() {
    cout << "Now running exploreInt()...\n" << endl;
    int x = 5; // Stack-allocated integer.
    int* addrOfX = &x; // The '&' operator returns the address of x.

    /* We now have X and a pointer to X. Sweet! We can examine the value
         of X (5) by using the '*' operator, which we call the 'dereference'
         operator. */
    cout << "The memory address of x is: " << addrOfX << "\n"
                "The value at that address is: " << *addrOfX << "\n" << endl;

    /* Cool beans. Notice that this integer wasn't allocated on the heap, so
        there's no need to delete it. This also means that when we leave the
         exploreInt() function, the address we just printed will be reclaimed
         by the runtime and our memory will get clobbered. This is why we
         allocate things like linked list nodes on the heap -- so that they won't
         get erased by the OS! */

    /* Question: if addrOfX is an int*, what makes that different from the
         arrays that you used in priorityQueue? Could we use the [] operator
         on this pointer? */
    cout << "The output of addrOfX[0] is: " << addrOfX[0] << endl;

    /* Looks like it worked! What happens if we try index 1? */
    cout << "The output of addrOfX[1] is: " << addrOfX[1] << "\n" << endl;

    /* Oh. Is that behavior expected? Why or why not? */


    /* Let's move to the heap now. */
    int* myNewInt = new int;

    /* Using our shiny new friend the '*' operator: */
    *myNewInt = 137; // Keith's favorite number!

    /* We now have a heap allocated integer. Let's do a sanity check to
         ensure that we can see the address and the value: */
    cout << "The memory address of myNewInt is: " << myNewInt << "\n"
                "The value at that address is: " << *myNewInt << "\n" << endl;

    /* Take a looksie at the memory addresses. Are they remotely close
        to each other? What might that tell you about the relative locations
        of the stack and the heap? */

    /* Let's clean up our memory now. Remember that you call delete on the
        pointer (the memory address) and not on the actual value (137). */
    delete myNewInt;

    /* What actually happens when you delete something on the heap? Does
         the value of your pointer change? */
    cout << "After deletion, the value of myNewInt is: " << myNewInt << endl;

    /* Interesting... is this pointer even considered nullptr? */
    if (myNewInt != nullptr) cout << "This statement is being printed iff "
                            "myNewInt is NOT nullptr, even after deletion" << endl;

    /* Ruh roh. Be sure to look out for that down the road.

        One last thing: if we want to test whether a pointer is a nullptr, we can
        treat our pointers like booleans to do so: */
    int* nullPointer = nullptr;
    if (nullPointer) cout << "This statement is being printed iff "
                                       "nullPointer is NOT nullptr" << endl;
    if (!nullPointer) cout << "This statement is being printed iff "
                                        "nullPointer is nullptr" << endl;

    /* Under the hood, the if statement is checking to see whether the
        number stored by the pointer is 0x0, which is equivalent to 0 or false.
        any nonzero value will be interpreted as true, so any non-0x0
        addresses will be interpreted as NOT nullptr. Be careful with this --
        as we showed above, just because a pointer is not nullptr doesn't mean
        that you can dereference it safely! */

    cout << "\n----------------------------------------------------------\n" << endl;
}

/**
* exploreCell()
* ----------
* Declares a pointer to a CELL struct and sets the cellValues field.
* Examines the relationship between '*' and '->' by nesting an int* inside
* of a CELL*.
*/
void exploreCell() {
    cout << "Now running exploreCell()...\n" << endl;

    /* Heap allocate a cell with ID 0, and no values array or next pointer */
    Cell* myFirstCell = new Cell{ 0, nullptr, nullptr };

    /* What does the pointer myFirstCell actually look like? */
    cout <<  "The memory address of myFirstCell is: " <<myFirstCell << endl;

    /* Initialize the cellValues array as the pointer to a dynamic array. */
    myFirstCell->cellValues = new int[5];

    /* Fill in cellValues, showing that the '->' operator is really
         just a fancy way of dereferencing a struct. */
    for (int i = 0; i < 5; i++) {
        /* Woah woah woooah, what's happening down there?
            We used the dereference operator '*' to access the literal struct
            myFirstCell on the heap (instead of dealing with a pointer to it).
            From there, all we had to do was access its cellValues member like
            the good old days with the '.' operator. NOTE that the parentheses
            matter here: *(myFirstCell).cellValues[i] will NOT compile, because
            the dereference operator (*) does NOT have precedence over the
            '.' operator. Funky!

            This line is functionally equivalent to:
            myFirstCell->cellValues[i] = 10* i;   */
        (*myFirstCell).cellValues[i] = 10 * i;
    }

    /* Show it worked with a simple print out. */
    cout << "After the loop, myFirstCell->cellValues is: { ";
    for (int i = 0; i < 5; i++) {
         cout << myFirstCell->cellValues[i];
         cout << ((i < 4) ? " " : " }");
    }

    /* Free your memory!
         Conceptual quiz: Why does one line use delete[] and the other use
          delete with no '[]'? */
    delete[] myFirstCell->cellValues;
    delete myFirstCell;

    cout << "\n----------------------------------------------------------\n" << endl;
}

/**
 * explorePointersGalore()
 * -------------------
 * Declares multiple pointers to pointers, diving into levels of indirection.
 * Attempts to rationalize why levels of indirection are useful -- if you
 * can't pass by reference (which you can't do in C), double pointers come
 * in handy!
 */
void explorePointersGalore() {
    cout << "Now running explorePointersGalore()...\n" << endl;

    /* Let's start things off easy -- let's heap allocate an integer
        and set its value. */
    int* firstPointer = new int;
    *firstPointer = 42;

    /* Cool. We now have a pointer, which stores the address of some int
         on the heap. Is it possible to have a pointer TO that pointer? There's
         no way this is legal... */
    int** secondPointer = &firstPointer;

    /* Wait a second... why is it an int**? -- It turns out the compiler
         doesn't let you write store an int* in another int* on the principle
         that a pointer to an integer is different than something that stores
         a pointer to an integer.

        Think of it this way -- if you COULD store firstPointer as an int*,
         would you have ANY idea whether your pointer was a single, double,
         triple, etc... pointer? It would be terrible!  Let's test this out: */
    int*** thirdPointer = &secondPointer;

    /* Yep. The compiler got angry when I tried to make thirdPointer a
        measly int **. This is DEFINITELY for the better, so that we actually
        know how many levels we need to dereference to find out data. To be
        really crazy, let's add another level of indirection, with a twist. */
    int**** fourthPointer = new int***;
    *fourthPointer = thirdPointer;

    /* Woah. The only way to get this to compile is to ask the heap to carve
         out an int*** -- why is that the case?

        As you've probably seen, the 'new' keyword always returns a pointer.
        in this case, we know that 'new' will give us a single pointer, so we only
        need to ask for an int*** instead of a disgusting int**** -- think of
        the new keyword as already providing us a single star.

        Also, yep. It's totally fine to have some of these pointers be on the
        stack and others on the heap -- it's like having friends play a video
        game together in real time, even if they live in different countries. Just
        remember that if you have a heap-allocated pointer, you'll need to dereference
        it to assign it correctly, unlike the simple equality assignments we used for
        thirdPointer, for example. */

    /* Let's try and extract our value now. */
    int veryIndirectValue = ****fourthPointer;

    /* Huh. That actually wasn't that bad -- the int**** needed to be
        dereferenced 4 times to get the value. Maybe this pointer stuff isn't
        that terrible?

        How else can we extract this value?*/
    int sortOfIndirectValue = ***thirdPointer;
    cout << "veryIndirectValue: " << veryIndirectValue << " | "
                "sortOfIndirectValue: " << sortOfIndirectValue << endl;
    /*Nice! Take my word for it -- these values are the same.

       Let's try deleting this now... Remeber from earlier that to delete
       heap memory, you need to delete the pointer to that memory --
       another way to think of that is you delete the handle that the 'new'
       keyword gave you. This will only work if we properly assigned fourthPointer
       (meaning we dereferenced it to put its pointee on the heap). */
    delete fourthPointer;

    /* So long as the compiler didn't complain, that worked! Let's try deleting the
        original heap pointer:*/
    delete **thirdPointer;

    /* I tried to be a sly weasel here and delete firstPointer via
        thirdPointer. The math checks out here -- I dereference thirdPointer
        twice to get a single int* -- that's exactly what the 'new' keyword
        originally returned to me! */


    /* Just for completeness, observe the following line:

        delete *thirdPointer;

        Think about what's going on here -- we're dereferencing thirdPointer
        once, so we're trying to free the memory associated with
        secondPointer, but secondPointer is a stack allocated pointer! What
        happens here? We're not sure, but you shouldn't do it. Stack memory
        is automatically reclaimed when the variable goes out of scope, so
        calling delete on the memory is pointless, and it gives undefined
        behavior to boot.*/


    /* Let's talk about one more thing -- why are these double, triple, etc...
        pointers even useful?

        If you haven't taken CS107 yet, there's something you should know
        about the programming language C (which is what you use in CS107,
        unlike C++ in CS106B).

        There's no such thing as pass-by-reference.

        To be specific, you can't include a parameter with the '&' symbol and
        get the 'pass by reference' behavior you're used to in C++. Luckily, we
        can get around this with pointers. The two simple functions below are
        equivalent:

        void foo (int& x) {
            x += 1;
        }

        void foo2(int* x) {
            (*x) += 1;
        }

        The bottom function simply utilizes pointers to achieve the same end
        as pass by reference.

        By this logic, we use double pointers in C when we'd want to pass a
        pointer by reference in C++, and this logic scales with double pointers
        and beyond.
    */
}
