// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
// Next node is contained in node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
// Perhaps use more buckets - a, aa, ab, ac etc.
// In total 26*26 + 26 buckets = 702 buckets

// If we use a, aa, aaa, aba we would need 26 + 26*26 + 26*26*26 = 18278 buckets
// Or use a, aa, aaa, aaaa: 26 + 26*26 + 26*26*26 + 26*26*26*26 = 475254 buckets
// Value of unsigned int goes to up 4,294,967,295
// Five characters would be 12,356,630 buckets
// Theoretically could go up to six characters - 321,272,406 buckets
// Using 321,272,406 buckets actually makes the time to unload very long
const unsigned int N = 475254;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
// Must be case-insensitive
// But should return false if e.g. foo's is not in dictionary
// Can use strcasecmp, but must consider case-insensitivity
bool check(const char *word)
{
    // TODO
    if (word == NULL || strlen(word) == 0)
    {
        return false;
    }

    int len = strlen(word);

    // Convert word to lower case
    char lower_word[LENGTH + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        lower_word[i] = tolower((unsigned char) word[i]);
    }

    lower_word[len] = '\0'; // Add null terminator

    // Find the bucket
    unsigned int bucket = hash(lower_word);

    // Validate bucket index
    if (bucket >= N)
    {
        fprintf(stderr, "Invalid bucket index: %u\n", bucket);
        return false;
    }

    // Traverse the linked list in the bucket
    node *current = table[bucket];
    while (current != NULL)
    {
        if (strcmp(current->word, lower_word) == 0)
        {
            return true; // Word found
        }
        current = current->next; // Move to the next node
    }

    return false; // Word not found
}

// Hashes word to a number
// Take first letter of a word and return a unsigned int between 0 to 18277
// OR use 702 buckets. Check first character of a word and assign

// Hash function seems to work fine
// Instead of hashing the first four characters, why not hash the entire word?

unsigned int hash(const char *word)
{
    if (word == NULL || word[0] == '\0')
    {
        return 0;
    }

    char first = tolower(word[0]);

    // If second character is not null, second character becomes lowercase
    // Otherwise, second character is \0
    // Same logic applies to third character
    char second = (word[1] != '\0') ? tolower(word[1]) : '\0';
    char third = (word[2] != '\0') ? tolower(word[2]) : '\0';
    char fourth = (word[3] != '\0') ? tolower(word[3]) : '\0';

    // Hash value
    // Subtract ASCII value of 'a' or 97 from first value
    int hash_value = first - 'a';

    // If second letter exists change hash value. aa = 26, ab = 27, aaa = 702
    if (isalpha(second))
    {
        hash_value = hash_value * 26 + (second - 'a') + 26; // Adding 26 for second letter
    }

    if (isalpha(third))
    {
        hash_value = hash_value * 26 + (third - 'a') + 26;
    }

    if (isalpha(fourth))
    {
        hash_value = hash_value * 26 + (fourth - 'a') + 26;
    }

    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        fprintf(stderr, "Could not open dictionary file %s.\n", dictionary);
        return false;
    }

    // Read each word in the file
    char word_in_text[LENGTH + 1];
    while (fgets(word_in_text, sizeof(word_in_text), source))
    {
        // Remove newline character if present
        word_in_text[strcspn(word_in_text, "\n")] = '\0';

        // Skip empty lines (could be due to trailing newlines or extra empty lines in the file)
        if (strlen(word_in_text) == 0)
        {
            continue;
        }

        // Add each word to the hash table
        int bucket = hash(word_in_text);

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Failed to allocate memory to new node.\n");
            fclose(source); // Ensure the file is closed before returning
            unload();
            return false;
        }

        // Copy the word into the new node
        strncpy(new_node->word, word_in_text, LENGTH);
        new_node->word[LENGTH] = '\0';  // Ensure null termination
        new_node->next = table[bucket]; // new node points to the same address that table[bucket]
                                        // points to which is the first node in the linked list
        table[bucket] = new_node; // now table bucket points to new_node, making new_node the first
                                  // node in the linked list
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
// Use a counter
// Could count each word as the dictionary is loaded OR count through words in hash table
unsigned int size(void)
{
    // Most likely best to count words in hash table since it is a global variable

    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        node *current = table[i];

        // Traverse the linked list in the current bucket
        while (current != NULL)
        {
            counter++;
            current = current->next; // current node now becomes the next node in the linked list
        }
    }

    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Traverse each bucket
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            node *temp = current;    // Save current node
            current = current->next; // Move to the next node
            free(temp);              // Free the memory of the saved node
        }
        table[i] = NULL; // Set the bucket to NULL after freeing all nodes
    }

    return true; // Successfully unloaded
}
