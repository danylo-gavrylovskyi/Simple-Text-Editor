#include <stdio.h>

int main() {
	printf("Choose the command:\n\t1.Append text symbols to the end\n\t2.Start the new line\n\t3.Use files to loading/saving the information\n\t4.Print the current text to console\n\t5.Insert the text by line and symbol index\n\t6.Search\n>> ");
	int choice;
	scanf("%d", &choice);
	
	switch (choice)
	{
	case 1:
		break;
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
	return 0;
}