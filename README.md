# COMPILER-DESIGN-BASICS

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: ANIKET KESHRI

*INTERN ID*: CT04DG990

*DOMAIN*: C PROGRAMMING

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH 


This C program is a lexical analyzer, which means it reads a source code file and breaks it down into meaningful components called tokens. Tokens can include keywords, identifiers, operators, and symbols. This type of program is usually the first phase of a compiler, which translates code written by a programmer into a form the computer can understand.


**Purpose of the Program:**
The main goal is to analyze a file named test.txt, read the code inside it character by character, and print out whether each part is a keyword, identifier, operator, or symbol.


**Key Components:**
Keywords List:
An array named keywords contains 32 reserved words in C (like int, if, while, return, etc.). These are words that have special meaning in the C language.

Multi-character Operators List:
An array multiCharOperators stores operators made of two characters like ==, !=, ++, --, &&, etc.

Helper Functions:

isKeyword(char *word) checks if a given word is a keyword by comparing it with the list of keywords.

isOperator(char *op) checks if a string is a valid operator (either single or double character).

isSymbol(char ch) checks if a character is a symbol like ;, ,, (, ), {, etc.


**Main Function:**

The file test.txt is opened in read mode using fopen.

If the file is not found, it prints an error and exits.

It starts reading characters using fgetc.

If the character is a letter or underscore:

It begins forming a word by collecting all letters, digits, or underscores (common in variable names).

When the word ends, it uses isKeyword to check if it’s a keyword.

If it’s not a keyword, it prints it as an identifier.

If the character is not a letter:

It reads the next character to form a possible two-character operator (like ==).

If the combination is a valid operator, it prints it.

If not, it checks if the single character is an operator.

If neither, it checks if it's a symbol.

The program uses ungetc() to put a character back into the input stream if it was read unnecessarily (helps with correct token separation).


**Output:**
As it processes the file, it prints out lines like:

makefile
Copy code
Keyword: int
Identifier: number
Operator: ==
Symbol: ;
This makes it easier to understand what each part of the code represents.

**Summary:**
This lexical analyzer reads code from a file and separates it into meaningful components. It recognizes C language keywords, variable names (identifiers), operators (like +, ==, etc.), and punctuation symbols. It uses functions to check and classify tokens and prints them out one by one. This is an essential part of compiler design and useful for beginners learning how programming languages are processed internally.

