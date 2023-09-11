#include <stdio.h>
#include <stdlib.h>

void saveTextToFile(char* fileName, char* text) {
	FILE* file;
	file = fopen(fileName, "w");
	if (file != NULL) {
		fputs(text, file);
		fclose(file);
	}
}

void printTextFromFile(char* fileName) {
	FILE* file;
	char fileText[100];
	file = fopen(fileName, "w");
	if (file == NULL) {
		printf("Error while opening file");
	}
	else {
		if (fgets(fileText, 100, file) != NULL)
		{
			printf("%s", fileText);
		}
		fclose(file);
	}
}

void* appendTextToBuffer(char* buffer, char input[256], size_t* bufferCapacity, size_t* bufferLength) {
	buffer = realloc(buffer, *bufferCapacity + );
}

int main() {
	int choice;

	size_t bufferLength = 0;
	size_t bufferCapacity = 0;
	char* buffer;
	
	while (1) {

		printf("Choose the command:\n\t0.Exit\n\t1.Append text symbols to the end\n\t2.Start the new line\n\t3.Use files to loading the information\n\t4.Use files to saving the information\n\t5.Print the current text to console\n\t6.Insert the text by line and symbol index\n\t7.Search\n>> ");
		scanf("%d", &choice);

		if (choice == 0) break;

		switch (choice)
		{
		case 1: {
			char input[256];
			printf("Enter text to append: ");
			scanf(" %255[^\n]", input);
			appendTextToBuffer(buffer, input, bufferCapacity, bufferLength);
			break;
		}
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			printf("The command is not implemented");
			break;
		}
	}

	free(buffer);
	
	return 0;
}