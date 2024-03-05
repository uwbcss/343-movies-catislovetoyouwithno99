<h1>CSS 343 Movie Project</h1>

Created By Houming Ge, Jack Landers
Date 3/4/2024

The file name means that this is what this file will be created by who.
From the start, we did not think about the EX point as it would break how we should create the structure of this project within one week of working.


The | ---- meaning this is the file that is being controlled by the current file or it is the importation of it
And fileA ----- fileB meaning that fileB is the importation of the fileA

How the store is working
Manager.h ---- manager.cpp
  |
  |
  | ---------- moviestore.h ------ moviestore.cpp
  |                 | 
  |                 | ------------ inventory.h --------- inventory.cpp
  |                 |
  |                 | ------------ hashtable.h --------- hashtable.cpp
  |                 |                   |
  |                 |                   | -------------- customer.h -------- customer.cpp
  |                 |
  |                 | ------------ transaction.h ------- transaction.cpp
  |                 |                   |
  |                 |                   | -------------- return.h ---------- return.cpp
  |                 |                   |                     |
  |                 |                   |                     | ------------ returnfactory.cpp
  |                 |                   |
  |                 |                   | -------------- borrow.h ---------- borrow.cpp
  |                 |                   |                     |
  |                 |                   |                     | ------------ borrowfactory.cpp



The object of the DVD and how it child object files
dvdmovie.h --- dvdmovie.cpp
  | child
  |
  | ----- classic.h --- classic.cpp
  |           | ------- classicFactory.cpp
  | 
  |
  | ----- comedy.h ---- comedy.cpp
  |           | ------- comedyFactory.cpp
  | 
  |
  | ----- drama.h ----- drama.cpp
  |           | ------- dramaFactory.cpp




ALL files::
  language and testing:: DO NOT NEED BE DOC DEFAULT FILES
    .clang-format
    .git
    .vscode
    create-output.sh
    data4commands.txt
    data4customers.txt
    data4movies.txt
    main.cpp
    output.txt
    README.md
    self-evaluation.md
    store_test.cpp
    testcommands-1.txt
    trackdown.txt
  
  Source code files::
    borrow.h
    borrow.cpp
    borrowfactory.cpp
    classic.cpp
    classic.h
    classicFactory.cpp
    comedy.cpp
    comedy.h
    comedyFactory.cpp
    hashtable.cpp
    hashtable.h
    inventory.cpp
    inventory.h
    manager.cpp
    manager.h
    moviestore.cpp
    moviestore.h
    return.h
    return.cpp
    returnfactory.cpp
    transaction.cpp
    transaction.h
    customer.cpp
    customer.h
    drama.cpp
    drama.h
    dramaFactory.cpp
    dvdmovie.cpp
    dvdmovie.h

