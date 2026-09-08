#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE 64
#define MAX_LANG  16


typedef struct Book {
    char   title[MAX_TITLE];
    double price;
    int    pages;
    char   language[MAX_LANG];
    double weight;
    int    year;
    struct Book *next;
} Book;

void  printHeader();
void  copyString(char *dest, const char *src, int size);
Book *createBook(const char *title, double price, int pages,
                 const char *language, double weight, int year);

void  addBook(Book **head, Book *node);
void  fillList(Book **head);
int   countBooks(const Book *head);
void  printBook(const Book *book, int number);
void  printList(const Book *head);
void  printSummary(const Book *head);
void  freeList(Book **head);
void  pauseBeforeExit();

int main(void) {
    Book *head = NULL;

    printHeader();

    fillList(&head);

    if (head == NULL) {
        printf("The list is empty.\n");
        pauseBeforeExit();
        return EXIT_FAILURE;
    }

    printList(head);
    printSummary(head);

    freeList(&head);
    printf("\nMemory has been released. Books in the list: %d\n", countBooks(head));

    pauseBeforeExit();

    return EXIT_SUCCESS;
}

void printHeader() {
    printf("=============================================================\n");
    printf("  Author:  Artem Cherednichenko\n");
    printf("  Task:    Harry Potter book series stored in a linked list\n");
    printf("=============================================================\n\n");
}

void copyString(char *dest, const char *src, int size) {
    int i = 0;

    while (src[i] != '\0' && i < size - 1) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

Book *createBook(const char *title, double price, int pages,
                 const char *language, double weight, int year) {
    Book *node = (Book *)malloc(sizeof(Book));

    if (node == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    copyString(node->title, title, MAX_TITLE);
    copyString(node->language, language, MAX_LANG);
    node->price  = price;
    node->pages  = pages;
    node->weight = weight;
    node->year   = year;
    node->next   = NULL;

    return node;
}

void addBook(Book **head, Book *node) {
    Book *current;

    if (*head == NULL) {
        *head = node;
        return;
    }

    current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

void fillList(Book **head) {
    addBook(head, createBook("Harry Potter and the Philosopher's Stone",
                             249.00, 223, "English", 280.0, 1997));
    addBook(head, createBook("Harry Potter and the Chamber of Secrets",
                             269.00, 251, "English", 310.0, 1998));
    addBook(head, createBook("Harry Potter and the Prisoner of Azkaban",
                             299.00, 317, "English", 380.0, 1999));
    addBook(head, createBook("Harry Potter and the Goblet of Fire",
                             399.00, 636, "English", 720.0, 2000));
    addBook(head, createBook("Harry Potter and the Order of the Phoenix",
                             449.00, 766, "English", 860.0, 2003));
    addBook(head, createBook("Harry Potter and the Half-Blood Prince",
                             429.00, 607, "English", 690.0, 2005));
    addBook(head, createBook("Harry Potter and the Deathly Hallows",
                             429.00, 607, "English", 700.0, 2007));
}

int countBooks(const Book *head) {
    int count = 0;
    const Book *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void printBook(const Book *book, int number) {
    printf("Book #%d\n", number);
    printf("  Title:     %s\n", book->title);
    printf("  Price:     %.2f UAH\n", book->price);
    printf("  Pages:     %d\n", book->pages);
    printf("  Language:  %s\n", book->language);
    printf("  Weight:    %.1f g\n", book->weight);
    printf("  Year:      %d\n\n", book->year);
}

void printList(const Book *head) {
    const Book *current = head;
    int number = 1;

    while (current != NULL) {
        printBook(current, number);
        current = current->next;
        number++;
    }
}

void printSummary(const Book *head) {
    const Book *current = head;
    double totalPrice = 0.0;
    double totalWeight = 0.0;
    int    totalPages = 0;
    int    count = 0;

    while (current != NULL) {
        totalPrice  += current->price;
        totalWeight += current->weight;
        totalPages  += current->pages;
        count++;
        current = current->next;
    }

    printf("-------------------------------------------------------------\n");
    printf("Books in the series: %d\n", count);
    printf("Total price:         %.2f UAH\n", totalPrice);
    printf("Total pages:         %d\n", totalPages);
    printf("Total weight:        %.1f g\n", totalWeight);
    printf("Average price:       %.2f UAH\n", totalPrice / count);
    printf("-------------------------------------------------------------\n");
}

void freeList(Book **head) {
    Book *current = *head;
    Book *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void pauseBeforeExit() {
    printf("\nPress Enter to exit...");
    getchar();
}
