#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 1024

int main() {
    // Open the input file
    FILE *fp_in = fopen("input_file.txt", "r");
    if (fp_in == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file
    FILE *fp_out = fopen("output_file.txt", "w");
    if (fp_out == NULL) {
        perror("Error opening output file");
        fclose(fp_in);
        return 1;
    }

    // Read the words from the input file
    char word[MAX_WORD_LEN];
    while (fgets(word, MAX_WORD_LEN, fp_in) != NULL) {
        // Remove the newline character from the end of the word
        word[strcspn(word, "\n")] = '\0';

        // Add the word to a linked list
        struct node {
            char *word;
            struct node *next;
        };
        struct node *head = NULL;
        struct node *curr = head;
        while (curr != NULL) {
            if (strcmp(word, curr->word) < 0) {
                // Insert the word into the sorted list
                struct node *new_node = malloc(sizeof(struct node));
                new_node->word = strdup(word);
                new_node->next = curr;
                head = new_node;
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL) {
            // Add the word to the end of the list
            struct node *new_node = malloc(sizeof(struct node));
            new_node->word = strdup(word);
            new_node->next = NULL;
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node;
        }
    }

    // Write the sorted words to the output file
    struct node *curr = head;
    while (curr != NULL) {
        fprintf(fp_out, "%s\n", curr->word);
        curr = curr->next;
    }

    // Clean up
    while (head != NULL) {
        struct node *next = head->next;
        free(head->word);
        free(head);
        head = next;
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}