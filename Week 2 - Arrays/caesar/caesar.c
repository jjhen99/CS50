#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_cipher(string plaintext, int key);
int only_digits(string input);

int main(int argc, string argv[])
{
    // Ask for a key, if there is no key print Usage: - argc must be 2

    if (argc == 2 && only_digits(argv[1]) && atoi(argv[1]) > 0)
    {
        int key = atoi(argv[1]);
        // Ask for input
        string plaintext = get_string("plaintext: ");

        // Calculate and display ciphertext
        calculate_cipher(plaintext, key);

        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

void calculate_cipher(string plaintext, int key)
{
    printf("ciphertext: ");
    string ciphertext = "";
    int p_i = 0;
    int c_i = 0;
    char c = ' ';

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Find p_i of the character so it can be converted used in the formula
        if (isalpha(plaintext[i]))
        {
            switch (plaintext[i])
            {
                case 'A':
                case 'a':
                    p_i = 0;
                    break;

                case 'B':
                case 'b':
                    p_i = 1;
                    break;

                case 'C':
                case 'c':
                    p_i = 2;
                    break;

                case 'D':
                case 'd':
                    p_i = 3;
                    break;

                case 'E':
                case 'e':
                    p_i = 4;
                    break;

                case 'F':
                case 'f':
                    p_i = 5;
                    break;

                case 'G':
                case 'g':
                    p_i = 6;
                    break;

                case 'H':
                case 'h':
                    p_i = 7;
                    break;

                case 'I':
                case 'i':
                    p_i = 8;
                    break;

                case 'J':
                case 'j':
                    p_i = 9;
                    break;

                case 'K':
                case 'k':
                    p_i = 10;
                    break;

                case 'L':
                case 'l':
                    p_i = 11;
                    break;

                case 'M':
                case 'm':
                    p_i = 12;
                    break;

                case 'N':
                case 'n':
                    p_i = 13;
                    break;

                case 'O':
                case 'o':
                    p_i = 14;
                    break;

                case 'P':
                case 'p':
                    p_i = 15;
                    break;

                case 'Q':
                case 'q':
                    p_i = 16;
                    break;

                case 'R':
                case 'r':
                    p_i = 17;
                    break;

                case 'S':
                case 's':
                    p_i = 18;
                    break;

                case 'T':
                case 't':
                    p_i = 19;
                    break;

                case 'U':
                case 'u':
                    p_i = 20;
                    break;

                case 'V':
                case 'v':
                    p_i = 21;
                    break;

                case 'W':
                case 'w':
                    p_i = 22;
                    break;

                case 'X':
                case 'x':
                    p_i = 23;
                    break;

                case 'Y':
                case 'y':
                    p_i = 24;
                    break;

                case 'Z':
                case 'z':
                    p_i = 25;
                    break;
            }
        }

        // Use formula to find c_i

        c_i = (p_i + key) % 26;

        // Find new character according to c_i
        // Check upper characters
        if (isupper(plaintext[i]))
        {
            switch (c_i)
            {
                case 0:
                    c = 'A';
                    break;

                case 1:
                    c = 'B';
                    break;

                case 2:
                    c = 'C';
                    break;

                case 3:
                    c = 'D';
                    break;

                case 4:
                    c = 'E';
                    break;

                case 5:
                    c = 'F';
                    break;

                case 6:
                    c = 'G';
                    break;

                case 7:
                    c = 'H';
                    break;

                case 8:
                    c = 'I';
                    break;

                case 9:
                    c = 'J';
                    break;

                case 10:
                    c = 'K';
                    break;

                case 11:
                    c = 'L';
                    break;

                case 12:
                    c = 'M';
                    break;

                case 13:
                    c = 'N';
                    break;

                case 14:
                    c = 'O';
                    break;

                case 15:
                    c = 'P';
                    break;

                case 16:
                    c = 'Q';
                    break;

                case 17:
                    c = 'R';
                    break;

                case 18:
                    c = 'S';
                    break;

                case 19:
                    c = 'T';
                    break;

                case 20:
                    c = 'U';
                    break;

                case 21:
                    c = 'V';
                    break;

                case 22:
                    c = 'W';
                    break;

                case 23:
                    c = 'X';
                    break;

                case 24:
                    c = 'Y';
                    break;

                case 25:
                    c = 'Z';
                    break;
            }
        }

        // If the character for the original plaintext is lower case, new character will also be
        // lower case
        else if (islower(plaintext[i]))
        {
            switch (c_i)
            {
                case 0:
                    c = 'a';
                    break;

                case 1:
                    c = 'b';
                    break;

                case 2:
                    c = 'c';
                    break;

                case 3:
                    c = 'd';
                    break;

                case 4:
                    c = 'e';
                    break;

                case 5:
                    c = 'f';
                    break;

                case 6:
                    c = 'g';
                    break;

                case 7:
                    c = 'h';
                    break;

                case 8:
                    c = 'i';
                    break;

                case 9:
                    c = 'j';
                    break;

                case 10:
                    c = 'k';
                    break;

                case 11:
                    c = 'l';
                    break;

                case 12:
                    c = 'm';
                    break;

                case 13:
                    c = 'n';
                    break;

                case 14:
                    c = 'o';
                    break;

                case 15:
                    c = 'p';
                    break;

                case 16:
                    c = 'q';
                    break;

                case 17:
                    c = 'r';
                    break;

                case 18:
                    c = 's';
                    break;

                case 19:
                    c = 't';
                    break;

                case 20:
                    c = 'u';
                    break;

                case 21:
                    c = 'v';
                    break;

                case 22:
                    c = 'w';
                    break;

                case 23:
                    c = 'x';
                    break;

                case 24:
                    c = 'y';
                    break;

                case 25:
                    c = 'z';
                    break;
            }
        }

        // Non alphabetic characters will be the same as character from plaintext
        else
        {
            c = plaintext[i];
        }

        printf("%c", c);
    }

    printf("\n");
}

int only_digits(string input)
{
    int flag = 1;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isdigit(input[i]) == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}
