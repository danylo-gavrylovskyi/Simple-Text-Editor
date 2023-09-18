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
            printf("Your text is present in this position: %d %d\n", lineNumber, index, lineNumber + 1);
            position = strstr(position + 1, searchText);
        }

        token = strtok(NULL, "\n");
        lineNumber++;
    }
}

void insertByLineAndIndex(char** buffer, int line, int index, char* input) {
    char* result = (char*)malloc(strlen(*buffer) + strlen(input) + 1);

    result[0] = '\0';

    char* token = strtok(*buffer, "\n");
    int currentLine = 0;

    while (token != NULL) {
        if (currentLine == line) {

            if (strlen(token) < index) {
                result = realloc(result, strlen(result) + (index - strlen(token)));

                char* newLine = (char*)malloc(index + strlen(input) + 1);
                strcpy(newLine, token);

                while (strlen(newLine) < index) {
                    strcat(newLine, " ");
                }
                
                strcat(newLine, input);
                strcat(result, newLine);

                free(newLine);
            }
            else {
                strncat(result, token, index);
                strcat(result, input);
                strcat(result, token + index);
            }
        }
        else {
            strcat(result, token);
        }

        strcat(result, "\n");
        token = strtok(NULL, "\n");
        currentLine++;
    }

    printf("%s\n", result);

    *buffer = result;
}


int main() {
    int choice;

    char* buffer = (char*) malloc(sizeof(char));
    *buffer = '\0';

    while (1) {
        printf("\nChoose the command:\n\t0.Exit\n\t1.Append text symbols to the end\n\t2.Start the new line\n\t3.Load text from file\n\t4.Save current text to file\n\t5.Print the current text to console\n\t6.Insert the text by line and symbol index\n\t7.Search\n>> ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            system("cls");
            char input[256];
            printf("Enter text to append: ");
            scanf("%255[^\n]", input);
            appendTextToBuffer(&buffer, input);
            break;
        }
        case 2: {
            system("cls");
            char newline[] = "\n";
            appendTextToBuffer(&buffer, newline);
            printf("%s", "New line is started");
            break;
        }
        case 3: {
            system("cls");
            char fileName[256];
            printf("Enter the file name for loading: ");
            scanf("%255s", fileName);
            loadTextFromFile(fileName, &buffer);
            break;
        }
        case 4: {
            system("cls");
            char fileName[256];
            printf("Enter the file name for saving: ");
            scanf("%255s", fileName);
            saveTextToFile(fileName, buffer);
            break;
        }
        case 5:
            system("cls");
            printf("%s\n", buffer);
            break;
        case 6: {
            system("cls");
            int line;
            int index;
            char input[256];
            printf("Enter line: ");
            scanf("%d", &line);
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter text to append: ");
            getchar();
            scanf("%255[^\n]", input);
            insertByLineAndIndex(&buffer, line, index, input);
            break;
        }
        case 7: {
            system("cls");
            char input[256];
            printf("Enter text to search: ");
            scanf("%255[^\n]", input);
            searchText(&buffer, input);
            break;
        }
        default:
            system("cls");
            printf("The command is not implemented\n");
            break;
        }
    }

    free(buffer);

    return 0;
}
