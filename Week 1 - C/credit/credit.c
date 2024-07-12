#include <cs50.h>
#include <math.h>
#include <stdio.h>

long get_credit(void);
void luhns_algo(long credit);

int main(void)
{
    // Get a credit card number
    long credit = get_credit();

    // Use Luhn's algorithm to check if credit card number is AMEX, MASTERCARD, VISA or INVALID
    luhns_algo(credit);
}

long get_credit(void)
{
    long credit = get_long("Number: ");
    return credit;
}

void luhns_algo(long credit)
{
    // Multiply every other digit by 2, starting with second-to-last digit

    // Find the number of digits in the credit card number

    int sumone = 0;
    int sumtwo = 0;
    int remainder = 0;

    int totalsum = 0;

    // Creditsum will store the value of credit, so we can use credit for later
    long creditsum = credit;
    long creditsumtwo = credit;

    // Variable to check is 2xremainder gives a value with two digits
    int twotimes = 0;

    // While loop will add up all the numbers for sumone
    while (creditsum > 0)
    {
        // Add numbers that aren't multiplied by 2 to sumone

        sumone = sumone + (creditsum % 10);
        // Remove number
        creditsum = creditsum / 10;

        // Add numbers that are multiplied by 2 to the sum

        // Remove number
        creditsum = creditsum / 10;
    }

    // We need to add the digits of sumtwo
    // Use another while loop using another creditsumtwo

    while (creditsumtwo > 0)
    {
        // Remove last number

        creditsumtwo = creditsumtwo / 10;

        // Add remainder to sumtwo
        remainder = creditsumtwo % 10;

        // Need to check if 2*(creditsumtwo % 10) returns a value with two digits

        if ((2 * (creditsumtwo % 10)) > 9)
        {
            twotimes = 2 * (creditsumtwo % 10);

            // printf("The number bigger than 9 is: %i\n", twotimes);

            // Take the number twotimes and add the last number to sumtwo
            // Remove the last number from twotimes
            // Add the second number to sumtwo

            for (int i = 0; i < 2; i++)
            {
                sumtwo = sumtwo + twotimes % 10;
                twotimes = twotimes / 10;
            }
        }

        else
        {
            sumtwo = sumtwo + 2 * (creditsumtwo % 10);
        }

        // Remove number
        creditsumtwo = creditsumtwo / 10;
    }

    // Calculate total sum
    totalsum = sumone + sumtwo;

    // Check to see if card is valid

    int is_card_valid = totalsum % 10;

    printf("card valid? %i\n", is_card_valid);

    long amex = credit / (1e13);
    long mastercard = credit / (1e14);
    long visa1 = credit / (1e12);
    long visa2 = credit / (1e15);

    if (is_card_valid == 0)
    {
        // Check if AMEX
        if (amex == 34 || amex == 37)
        {
            printf("AMEX\n");
        }

        // Check if MasterCard
        else if (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 ||
                 mastercard == 55)
        {
            printf("MASTERCARD\n");
        }

        // Check if VISA
        else if (visa1 == 4 || visa2 == 4)
        {
            printf("VISA\n");
        }

        else
        {
            // Card is invalid
            printf("INVALID\n");
        }
    }

    else
    {
        // Card is invalid
        printf("INVALID\n");
    }
}
