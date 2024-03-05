# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 4

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: TODO(student)
History: TODO(student)
Borrow: TODO(student)
Return: TODO(student)


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): Yes

- -1 for each function not documented

## Location of error message or functionality

MAYBE read the readme.md first as I have created more information...

State the file and function where the information can be found

invalid command code: moviestore.h -------- moviestore.cpp

invalid movie type: moviestore.h -------- moviestore.cpp

invalid customer ID: customer.h -------- customer.cpp
 
invalid movie: inventory.h -------- inventory.cpp

factory classes: dvdmovie.h -------- dvdmovie.cpp , transaction.h -------- transaction.cpp

hashtable: hashtable.h -------- hashtable.cpp
    Linear Probing by cobie all information base on Customer ID by this cal
    Customer ID = num
    ((num[0] - '0') + (2 * (num[1] - '0')) + (3 * (num[2] - '0')) + (4 * (num[3] - '0'))) %
         buckets;

container used for comedy movies: moviesstore by movies valuable

Under inventory
map<char, vector<DVDMovie *>> inventory;

function for sorting comedy movies: comedy.h -------- comdey.cpp

function where comedy movies are sorted: inventory.h -------- inventory.cpp

I DO NOT UNDERSTAND two function are function or where it being called?

functions called when retrieving a comedy movie based on title and year:

function: comedy.h -------- comedy.cpp
where being called: inventory.h -------- inventory.cpp

WHAT HAPPEN TO THIS ORDER?

functions called for retrieving and printing customer history: 

function: customer.h -------- customer.cpp
where being called: moviesstore.cpp in processCommands function

container used for customer history: TODO(student)

vector(history *) under customer.h

functions called when borrowing a movie: 

call the processTran under moviestore 

explain borrowing a movie that does not exist: If they are not in that class will be call the cerr

explain borrowing a movie that has 0 stock: 

call cerr when that happen in the each class

explain returning a movie that customer has not checked out: 

Once the requied asking the movestore will throw this requied to the customer.h customer will taking here and chekcing the if this is nullptr or else if it was nullptr it will be return as the cerr message having been send under the customer end command.

any static_cast or dynamic_cast used: yes


Q: Total points: 25? (max 25)