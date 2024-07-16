#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_cipher(string plaintext, string key);
int only_26(string key);

int main(int argc, string argv[])
{
    // Ask for a 26 character key, if there is no key print Usage: - argc must be 2

    if (argc == 2 && only_26(argv[1]))
    {
        string key = argv[1];
        // Ask for input
        string plaintext = get_string("plaintext: ");

        // Calculate and display ciphertext
        calculate_cipher(plaintext, key);

        return 0;
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

int only_26(string key)
{
    int flag = 1;
    // Check if key has 26 characters, if not return 0.
    if (strlen(key) == 26)
    {
        for (int i = 0, n = strlen(key); i < n; i++)
        { // Check if character is alphabetic
            if (isalpha(key[i]))
            {
                // Check if there are any characters that are the same as selected character
                for (int j = i + 1; j < n; j++)
                {
                    if (key[i] == key[j])
                    {
                        flag = 0;
                    }
                }
            }

            else
            {
                flag = 0;
            }
        }
    }

    else
    {
        flag = 0;
    }

    return flag;
}

void calculate_cipher(string plaintext, string key)
{
    printf("ciphertext: ");

    char character = ' ';

    char A = ' ';
    char a = ' ';
    char B = ' ';
    char b = ' ';
    char C = ' ';
    char c = ' ';
    char D = ' ';
    char d = ' ';
    char E = ' ';
    char e = ' ';
    char F = ' ';
    char f = ' ';
    char G = ' ';
    char g = ' ';
    char H = ' ';
    char h = ' ';
    char I = ' ';
    char i = ' ';
    char J = ' ';
    char j = ' ';
    char K = ' ';
    char k = ' ';
    char L = ' ';
    char l = ' ';
    char M = ' ';
    char m = ' ';
    char N = ' ';
    char n = ' ';
    char O = ' ';
    char o = ' ';
    char P = ' ';
    char p = ' ';
    char Q = ' ';
    char q = ' ';
    char R = ' ';
    char r = ' ';
    char S = ' ';
    char s = ' ';
    char T = ' ';
    char t = ' ';
    char U = ' ';
    char u = ' ';
    char V = ' ';
    char v = ' ';
    char W = ' ';
    char w = ' ';
    char X = ' ';
    char x = ' ';
    char Y = ' ';
    char y = ' ';
    char Z = ' ';
    char z = ' ';

    // Go through the key and set up a dictionary
    for (int count = 0, length = strlen(key); count < length; count++)
    {
        switch (count)
        {
            case 0:
                A = toupper(key[count]);
                a = tolower(key[count]);
                break;

            case 1:
                B = toupper(key[count]);
                b = tolower(key[count]);
                break;

            case 2:
                C = toupper(key[count]);
                c = tolower(key[count]);
                break;

            case 3:
                D = toupper(key[count]);
                d = tolower(key[count]);
                break;

            case 4:
                E = toupper(key[count]);
                e = tolower(key[count]);
                break;

            case 5:
                F = toupper(key[count]);
                f = tolower(key[count]);
                break;

            case 6:
                G = toupper(key[count]);
                g = tolower(key[count]);
                break;

            case 7:
                H = toupper(key[count]);
                h = tolower(key[count]);
                break;

            case 8:
                I = toupper(key[count]);
                i = tolower(key[count]);
                break;

            case 9:
                J = toupper(key[count]);
                j = tolower(key[count]);
                break;

            case 10:
                K = toupper(key[count]);
                k = tolower(key[count]);
                break;

            case 11:
                L = toupper(key[count]);
                l = tolower(key[count]);
                break;

            case 12:
                M = toupper(key[count]);
                m = tolower(key[count]);
                break;

            case 13:
                N = toupper(key[count]);
                n = tolower(key[count]);
                break;

            case 14:
                O = toupper(key[count]);
                o = tolower(key[count]);
                break;

            case 15:
                P = toupper(key[count]);
                p = tolower(key[count]);
                break;

            case 16:
                Q = toupper(key[count]);
                q = tolower(key[count]);
                break;

            case 17:
                R = toupper(key[count]);
                r = tolower(key[count]);
                break;

            case 18:
                S = toupper(key[count]);
                s = tolower(key[count]);
                break;

            case 19:
                T = toupper(key[count]);
                t = tolower(key[count]);
                break;

            case 20:
                U = toupper(key[count]);
                u = tolower(key[count]);
                break;

            case 21:
                V = toupper(key[count]);
                v = tolower(key[count]);
                break;

            case 22:
                W = toupper(key[count]);
                w = tolower(key[count]);
                break;

            case 23:
                X = toupper(key[count]);
                x = tolower(key[count]);
                break;

            case 24:
                Y = toupper(key[count]);
                y = tolower(key[count]);
                break;

            case 25:
                Z = toupper(key[count]);
                z = tolower(key[count]);
                break;
        }
    }

    // Go through plaintext and print new key

    for (int count2 = 0, length2 = strlen(plaintext); count2 < length2; count2++)
    {
        if (isalpha(plaintext[count2]))
        {
            switch (plaintext[count2])
            {
                case 'A':
                    printf("%c", A);
                    break;

                case 'a':
                    printf("%c", a);
                    break;

                case 'B':
                    printf("%c", B);
                    break;

                case 'b':
                    printf("%c", b);
                    break;

                case 'C':
                    printf("%c", C);
                    break;

                case 'c':
                    printf("%c", c);
                    break;

                case 'D':
                    printf("%c", D);
                    break;

                case 'd':
                    printf("%c", d);
                    break;

                case 'E':
                    printf("%c", E);
                    break;

                case 'e':
                    printf("%c", e);
                    break;

                case 'F':
                    printf("%c", F);
                    break;

                case 'f':
                    printf("%c", f);
                    break;

                case 'G':
                    printf("%c", G);
                    break;

                case 'g':
                    printf("%c", g);
                    break;

                case 'H':
                    printf("%c", H);
                    break;

                case 'h':
                    printf("%c", h);
                    break;

                case 'I':
                    printf("%c", I);
                    break;

                case 'i':
                    printf("%c", i);
                    break;

                case 'J':
                    printf("%c", J);
                    break;

                case 'j':
                    printf("%c", j);
                    break;

                case 'K':
                    printf("%c", K);
                    break;

                case 'k':
                    printf("%c", k);
                    break;

                case 'L':
                    printf("%c", L);
                    break;

                case 'l':
                    printf("%c", l);
                    break;

                case 'M':
                    printf("%c", M);
                    break;

                case 'm':
                    printf("%c", m);
                    break;

                case 'N':
                    printf("%c", N);
                    break;

                case 'n':
                    printf("%c", n);
                    break;

                case 'O':
                    printf("%c", O);
                    break;

                case 'o':
                    printf("%c", o);
                    break;

                case 'P':
                    printf("%c", P);
                    break;

                case 'p':
                    printf("%c", p);
                    break;

                case 'Q':
                    printf("%c", Q);
                    break;

                case 'q':
                    printf("%c", q);
                    break;

                case 'R':
                    printf("%c", R);
                    break;

                case 'r':
                    printf("%c", r);
                    break;

                case 'S':
                    printf("%c", S);
                    break;

                case 's':
                    printf("%c", s);
                    break;

                case 'T':
                    printf("%c", T);
                    break;

                case 't':
                    printf("%c", t);
                    break;

                case 'U':
                    printf("%c", U);
                    break;

                case 'u':
                    printf("%c", u);
                    break;

                case 'V':
                    printf("%c", V);
                    break;

                case 'v':
                    printf("%c", v);
                    break;

                case 'W':
                    printf("%c", W);
                    break;

                case 'w':
                    printf("%c", w);
                    break;

                case 'X':
                    printf("%c", X);
                    break;

                case 'x':
                    printf("%c", x);
                    break;

                case 'Y':
                    printf("%c", Y);
                    break;

                case 'y':
                    printf("%c", y);
                    break;

                case 'Z':
                    printf("%c", Z);
                    break;

                case 'z':
                    printf("%c", z);
                    break;
            }
        }

        else
        {
            printf("%c", plaintext[count2]);
        }
    }

    printf("\n");
}
