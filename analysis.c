#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word);
int isOperator(char *op);
int isSymbol(char ch);

char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while"
};

char *multiCharOperators[] = {
    "==", "!=", "<=", ">=", "++", "--", "+=", "-=", "*=", "/=", "%=", "&&", "||"
};

int main() {
    FILE *fptr = fopen("test.txt", "r");
    if (!fptr) {
        printf("Could not open test.txt\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n");

    char ch;
    char word[100];
    int i = 0;

    while ((ch = fgetc(fptr)) != EOF) {
        // Skip whitespace
        if (isspace(ch)) continue;

        // Identifiers and Keywords
        if (isalpha(ch) || ch == '_') {
            word[i++] = ch;
            while ((ch = fgetc(fptr)) != EOF && (isalnum(ch) || ch == '_')) {
                word[i++] = ch;
            }
            word[i] = '\0';
            i = 0;
            ungetc(ch, fptr);

            if (isKeyword(word))
                printf("Keyword: %s\n", word);
            else
                printf("Identifier: %s\n", word);
        }
        // Multi-character operators
        else {
            char next = fgetc(fptr);
            char opStr[3] = {ch, next, '\0'};
            if (isOperator(opStr)) {
                printf("Operator: %s\n", opStr);
            } else {
                ungetc(next, fptr);
                opStr[1] = '\0';
                if (isOperator(opStr)) {
                    printf("Operator: %s\n", opStr);
                }
                else if (isSymbol(ch)) {
                    printf("Symbol: %c\n", ch);
                }
            }
        }
    }

    fclose(fptr);
    return 0;
}

int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char *op) {
    char singleOps[] = "+-*/%=<>";
    for (int i = 0; i < strlen(singleOps); i++) {
        if (strlen(op) == 1 && op[0] == singleOps[i]) return 1;
    }

    for (int i = 0; i < sizeof(multiCharOperators) / sizeof(multiCharOperators[0]); i++) {
        if (strcmp(op, multiCharOperators[i]) == 0) return 1;
    }
    return 0;
}

int isSymbol(char ch) {
    char symbols[] = ";:,(){}[]";
    for (int i = 0; i < strlen(symbols); i++) {
        if (ch == symbols[i]) return 1;
    }
    return 0;
}
