#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveTextToFile(char* fileName, char* text) {
    FILE* file;
    if (fopen_s(&file, fileName, "a") == 0) {
        fputs(text, file);
        fclose(file);
        printf("%s", "\nText has been saved successfully");
    }
    else {
        printf("Error while opening file");
    }
}

void loadTextFromFile(char* fileName, char** buffer) {
    FILE* file;
    char fileText[100];
    if (fopen_s(&file, fileName, "r") == 0) {
        while (fgets(fileText, sizeof(fileText), file) != NULL) {
            *buffer = realloc(*buffer, strlen(*buffer) + strlen(fileText) + 1);
            strcat(*buffer, fileText);
        }
        fclose(file);
        printf("%s", "\nText has been loaded successfully");
    }
    else {
        printf("Error while opening file");
    }
}

void appendTextToBuffer(char** buffer, char* input) {
    *buffer = realloc(*buffer, strlen(*buffer) + strlen(input) + 1);
    if (*buffer != NULL) {
        strcat(*buffer, input);
    } else {
        printf("Memory allocation failed.\n");
    }
}

void searchText(char** buffer, char* searchText) {
    char* token = strtok(*buffer, "\n");
    int lineNumber = 0;

    while (token != NULL) {
        char* position = strstr(token, searchText);
        while (position != NULL) {
            int index = position - token;
            printf("Your text is present in this position: %d %d (Line: %d)\n", lineNumber, index, lineNumber + 1);
            position = strstr(position + 1, searchText);
        }

        token = strtok(NULL, "\n");
        lineNumber++;
    }
}


int main() {
    int choice;

    char* buffer = (char*) malloc(sizeof(char));
    *buffer = '\0';

    while (1) {
        printf("\nChoose the command:\n\t0.Exit\n\t1.Append text symbols to the end\n\t2.Start the new line\n\t3.Load text from file\n\t4.Save current text to file\n\t5.Print the current text to console\n\t6.Insert the text by line and symbol index\n\t7.Search\n>> ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            char input[256];
            printf("Enter text to append: ");
            scanf("%255[^\n]", input);
            appendTextToBuffer(&buffer, input);
            break;
        }
        case 2: {
            char newline[] = "\n";
            appendTextToBuffer(&buffer, newline);
            printf("%s", "New line is started");
            break;
        }
        case 3: {
            char fileName[256];
            printf("Enter the file name for loading: ");
            scanf("%255s", fileName);
            loadTextFromFile(fileName, &buffer);
            break;
        }
        case 4: {
            char fileName[256];
            printf("Enter the file name for saving: ");
            scanf("%255s", fileName);
            saveTextToFile(fileName, buffer);
            break;
        }
        case 5:
            printf("%s\n", buffer);
            break;
        case 6: {
            
        }
        case 7: {
            char input[256];
            printf("Enter text to search: ");
            scanf("%255[^\n]", input);
            searchText(&buffer, input);
            break;
        }
        default:
            printf("The command is not implemented\n");
            break;
        }
    }

    free(buffer);

    return 0;
}
