#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int age = get_int("How old are you? ");
    printf("Your age is %i.\n", age);

    if (age<18) {
        printf("You are not old enough to drink!\n");
    }

    else if (age == 18){
        printf("Barely legal! Have fun!\n");
    }

    else{
        printf("Have a good time!\n");
    }
}
