#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} list_t;

list_t *add_node(list_t **head, const char *str) {
    // Check if the input string is not NULL
    if (str == NULL) {
        return NULL;
    }

    // Allocate memory for the new node
    list_t *new_node = malloc(sizeof(list_t));
    if (new_node == NULL) {
        return NULL; // Allocation failed
    }

    // Duplicate the input string using strdup
    new_node->str = strdup(str);
    if (new_node->str == NULL) {
        free(new_node);
        return NULL; // strdup failed
    }

    // Set the next pointer of the new node to the current head
    new_node->next = *head;

    // Update the head to point to the new node
    *head = new_node;

    // Return the address of the new element
    return new_node;
}

int main() {
    list_t *head = NULL;

    // Example usage
    add_node(&head, "Class");
    add_node(&head, "Hey");

    // Print the elements in the list
    list_t *current = head;
    while (current != NULL) {
        printf("%s ", current->str);
        current = current->next;
    }

    // Free the memory allocated for the list
    current = head;
    while (current != NULL) {
        list_t *temp = current;
        current = current->next;
        free(temp->str);
        free(temp);
    }

    return 0;
}
