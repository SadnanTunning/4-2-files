#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a string is a keyword
int is_keyword(char temp[]) {
    char keywords[32][12] = {"return", "continue", "extern", "static", "long", "signed",
                             "switch", "char", "else", "unsigned", "if", "struct",
                             "union", "goto", "while", "float", "enum", "sizeof", "double", "volatile",
                             "const", "case", "for", "break", "void", "register", "int",
                             "do", "default", "short", "typedef", "auto"};
    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], temp) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *file_pointer;
    char token[50];
    char ch;

    file_pointer = fopen("demo.txt", "r");
    if (file_pointer == NULL) {
        printf("The file could not be opened.\n");
        exit(0);
    }

    int in_comment = 0;
    while ((ch = fgetc(file_pointer)) != EOF) {
        if (ch == '/') {
            if ((ch = fgetc(file_pointer)) == '*') {
                in_comment = 1;
            }
        }
        else if (ch == '*') {
            if ((ch = fgetc(file_pointer)) == '/') {
                in_comment = 0;
            }
        }

        if (!in_comment && !isspace(ch)) {
            if (ch == '#') {
                // Header file
                printf("\nHeader files:\t");
                while ((ch = fgetc(file_pointer)) != '\n') {
                    printf("%c", ch);
                }
            } else if (isalpha(ch) || ch == '_') {
                // Identifier or keyword
                int i = 0;
                token[i++] = ch;
                while ((ch = fgetc(file_pointer)) != EOF && (isalnum(ch) || ch == '_')) {
                    token[i++] = ch;
                }
                token[i] = '\0';
                if (is_keyword(token)) {
                    printf("\nKeyword:\t%s", token);
                } else {
                    printf("\nIdentifier:\t%s", token);
                }
                ungetc(ch, file_pointer);
            } else if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == ';' || ch == ',') {
                // Parenthesis, punctuation or arithmetic operator
                printf("\n%s:\t%c", (ch == '(' || ch == ')' || ch == '[' || ch == ']') ? "Parenthesis" :
                                     ((ch == ';' || ch == ',') ? "Punctuation" : "Arithmetic operator"), ch);
            } else if (ch == '=' || ch == '+') {
                // Arithmetic operator
                printf("\nArithmetic operator:\t%c", ch);
            }
        }
    }

    fclose(file_pointer);
    return 0;
}
