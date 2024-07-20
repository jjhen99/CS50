#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO

    // Record preference
    // Go through each voter
    // Voter inputs a name for first rank
    // Use the preference array

    // How to make sure no two names are the same?

    // Check if the name has already been recorded for this voter
    for (int r = 0; r < rank; r++)
    {
        if (strcmp(name, candidates[preferences[voter][r]].name) == 0)
        {
            // The name has already been recorded for a previous rank
            return false;
        }
    }

    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // preference stores the index of the preferred candidate
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO

    // GO through each voter using vote_count
    // Top choice is preferences[i][0] and second choice is preferences[i][1]
    // Check to see if any candidate is eleiminated - if so don't count their votes
    // Update votes of each non-eliminated candidate

    // Go through preferences of each voter
    // If highest preference is not eliminated, add one vote
    // If highest preference is eliminated, move to the next preference and add one vote

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int index = preferences[i][j];
            if (candidates[index].eliminated == false)
            {
                candidates[index].votes += 1;
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Check to see if a candidate has more than 50% of the vote (if candidate is not eliminated)
    float max_percentage = 0;
    float percentage = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false) // This if statement might not be necessary
        {
            percentage = (float) candidates[i].votes / (float) voter_count;

            if (max_percentage < percentage)
            {
                max_percentage = percentage;
            }
        }
    }

    if (max_percentage > 0.5)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[j].eliminated == false) // This if statement might not be necessary
            {
                percentage = (float) candidates[j].votes / (float) voter_count;
                if (max_percentage == percentage)
                {
                    printf("%s\n", candidates[j].name);
                    return true;
                }
            }
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min_vote = MAX_VOTERS;

    // Cycle through each valid candidate and record votes
    // If votes is less than min_vote, make min_vote equal to their vote

    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes < min_vote)
            {
                min_vote = candidates[i].votes;
            }
        }
    }
    return min_vote;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    // Check if all candidates have the minimum number of votes
    // If any votes aren't the same, return false
    // Otherwise, return true at the end

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }

    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO

    // Check if candidate has minimum votes
    // If they do, set candidates[i].eliminated to true

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }

    return;
}
