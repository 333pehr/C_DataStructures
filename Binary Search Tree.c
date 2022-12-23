// Sepehr Latifi Azad -- 190254082
// Project tested by CLion and DevC++ IDEs and it works perfectly

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char word[5];
    int repeated;
    struct node *left;
    struct node *right;
} node;

struct node* root = NULL;

//Inset function that is used for creating and inserting nodes while we are getting data from text document
void insert(char word[5])
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->word, word);
    temp->repeated = 1;
    temp->left = NULL;
    temp->right = NULL;
    //checking if root of the BST is NULL or not
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *current = root;
        struct node *parent = NULL;
        while (1)
        {
            parent = current;
            //checking if we need to connect node to its parent's left or right pointer
            if (strcmp(word, current->word) < 0)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = temp;
                    return;
                }
            }
            else if (strcmp(word, current->word) > 0)
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = temp;
                    return;
                }
            }
            else
            {
                //checking if the word in repeated
                current->repeated++;
                return;
            }
        }
    }
}
// reading data from text file and creating and inserting node for each line
void read_file()
{
    FILE *filePointer;
    char word[5];
    filePointer = fopen("Words.txt", "r");
    if (filePointer == NULL)
    {
        printf("Error opening file \n");
        exit(1);
    }
    while (fscanf(filePointer, "%s", word) == 1)
    {
        insert(word);
    }
    fclose(filePointer);
}
// menu for the user to choose the right operation
int menu()
{
    printf("Please choose one of the following options:\n");
    printf("1. Print All Words\n");
    printf("2. Print All Words in Alphabetical Order\n");
    printf("3. Search for a Word\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// search function that will find the depth of a word in the BST
void DepthFinder(struct node* root, char* word, int depth) {
    struct node* temp = root;
    if (temp == NULL) {
        printf("Word not found! please try again.\n\n\n");
        return;
    }
    if (strcmp(word, temp->word) == 0) {
        printf("%s found! its depth is %d\n", word, depth);
    }
    else if (strcmp(word, temp->word) > 0){
        DepthFinder(temp->right, word, depth + 1);
    }
    else {
        DepthFinder(temp->left, word, depth + 1);
    }
}
//A function to print all the words in the sorted way
void printAllWords(struct node *root)
{
    if (root != NULL)
    {
        printAllWords(root->left);
        printf("%s repeated %d \n", root->word, root->repeated);
        printAllWords(root->right);
    }
}
//A method to print all the words in the unsorted way
void printAllWordsNotSorted(struct node *root)
{
    if (root != NULL)
    {
        printAllWordsNotSorted(root->left);
        printAllWordsNotSorted(root->right);
        printf("%s repeated %d \n", root->word, root->repeated);
    }
}
int main()
{
    int choice;
    struct node* temp = (struct node*) malloc(sizeof (struct node));
    read_file();
    while (choice != 4)
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\n Print All Words\n");
                printAllWordsNotSorted(root);
                break;
            case 2:
                printf("\n Print All Words in Alphabetical Order\n");
                printAllWords(root);
                break;
            case 3:
                printf("\n Please enter the word:\n");
                scanf("%s",temp->word);
                DepthFinder(root,temp->word,0);
                break;
            case 4:
                printf("\n Have a nice day\n");
                return 1;
            default:
                printf("\n Invalid choice! Please choose a number from 1 to 4\n");
                break;
        }
    }
    return 0;
}
