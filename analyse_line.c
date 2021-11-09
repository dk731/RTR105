#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 512
#define MIN_WORD_SIZE 5

int main()
{
    printf("Please eneter you sentence: \n");

    char my_str[MAX_INPUT_LENGTH];
    scanf(" %[^\n]s", my_str);

    char *prev_occurence = my_str;
    char *cur = NULL;
    int words_count = 0;
    int sum_words = 1;

    while (cur = strchr(prev_occurence, ' '))
    {
        int dif = cur - prev_occurence;

        if (dif >= MIN_WORD_SIZE)
            words_count++;

        if (dif > 0)
            sum_words++;

        prev_occurence = cur + 1;
    }

    if (strlen(my_str) - (prev_occurence - my_str) >= MIN_WORD_SIZE ) words_count++;

    printf("Found %d words with minimal length: %d. Total words count: %d\n", words_count, MIN_WORD_SIZE, sum_words);
    
    return 0;
}