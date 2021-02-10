
#include < stdio.h > 
#include < stdlib.h > // for rand() function

//functions
void fillArray(char[], int);
int getFrequencyOf(char[], int, char);
void removeCharacter(char[], int, char);
void sort(char[], int);
void drivePart1();
void drivePart2();

//my variables
int choice; //user input for the menu
int endloop = 0; // end loop condition for the menu
int endPart1 = 0;//end part 1 loop
int endPart2 = 0;//end part2 loop
char letter; // character that user will input
char * myStrings[10]; // array of 10 char pointers
char oneDimArray[51]; // character array of 50 elements plus \0

int main() {

	do {
		printf("\nWelcome to Assignment 3!\nMenu:\n1 - Single Dimension Array Processing\n2 - Two-D Processing\n0 - Exit Program\nChoose an option:");
		fflush(stdout); //clear the buffer
		scanf("%d", &choice); //read user input
		switch (choice) {
		case 1: //if the user wants to work in 1 dimension arrays
			drivePart1();
			break;

		case 2: // if the user wants to work in 2 dimensional arrays2
			drivePart2();
			break;

		case 0:
			endloop = 1;
			break; // if the user inputs 0 set endloop to True to end program

		default:
			printf("Error\n"); // if you enter anything else print an error message
		}
	} while (endloop != 1);
	return 0;
}
/** this Function drives the first part for single dimension arrays*/
void drivePart1() {
	fillArray(oneDimArray, 51); //take the single dimension array and fill it with random lower case values
	do {
		printf("\nWhat would you like to do?\n1. Check the frequency of a letter\n2. Remove a letter\n3. Sort:\n0. Exit to main menu:");
		fflush(stdout); //clear the buffer
		scanf("%d", &choice); //read user input
		switch (choice) {
		case 1:
		{ //if the user wants to check the number of times their letter is in the array
			printf("\nWhich letter would you like to check?\n");
			fflush(stdout); //clear the buffer
			scanf(" %c", &letter); //read in the character
			if (letter >= 97 && letter <= 123) { // if the user prints a letter in between 97 and 123 (a-z in ASCII) then use getFreq
				printf("\n%c appears in the array %d times\n\n", letter, getFrequencyOf(oneDimArray, 51, letter));
			}
			else {
				printf("\n%c is not a valid character\n\n", letter); //if the user enters something other than an lower case letter
			}
		}
		break;
		case 2:
		{ // if the user wants to remove a letter from the array
			printf("\nWhich Letter would you like to remove\n");
			fflush(stdout);
			scanf(" %c", &letter);
			if (letter >= 97 && letter <= 123) { // if the user prints a letter in between 97 and 123 (a-z in ASCII) 
				removeCharacter(oneDimArray, 51, letter); //remove the character from the array 
				printf("\nAfter removing:\n%s\n\n", oneDimArray); //print the new array
			}
			else {
				printf("%c is not a valid character\n\n", letter); //if the user enters something other than an lower case letter
			}
		}
		break;
		case 3:
		{ // if the user wants to sort the array alphabetically
			sort(oneDimArray, 51);
			printf("\nSorting:\n%s\n\n", oneDimArray);
		}
		break;
		case 0:
			endPart1 = 1;
			break; // user enters 0 to end part1

		}
	} while (endPart1 != 1);
}
/**This function drives the 2nd part of the assignment for 2-d Arrays*/
void drivePart2() {
	for (int i = 0; i < 10; i++) {//ask user for input and store all 15 strings 
		myStrings[i] = (char *)malloc(15 * sizeof(char)); // allocate 15 bytes for the pointer
		printf("Enter a String %d: ",i+1);
		fflush(stdout); //clear the buffer
		scanf("%s", myStrings[i]); //Store the beginning C type string at the pointer address i
	}
	for (int i = 0; i < 10; i++) {
		printf("You entered %s\n", myStrings[i]); // print out the array
	}

	do {
		printf("What do you want to do \n1 - Check the frequency of a letter\n2 - Remove a character:\n0 - Return to main menu:");
		fflush(stdout);
		scanf("%d", &choice); //read in input

		switch (choice) {
		case 1:
		{ //if user wants to check the frequency of a letter
			printf("Which letter would you like to check?\n");
			fflush(stdout);
			scanf(" %c", &letter);
			for (int i = 0; i < 10; i++) { //loop through and print string plus number of instances using getFrequencyOf
				printf("%s - %d\n", myStrings[i], getFrequencyOf(myStrings[i], 10, letter));
			}
		}
		break;
		case 2:
		{ //user would like to remove a character from the 2D arrays
			printf("which letter would you like to remove?:");
			fflush(stdout);
			scanf(" %c", &letter);
			for (int i = 0; i < 10; i++) { //loop through and remove the selected charcter from each array and print new array
				removeCharacter(myStrings[i], 15, letter);
					printf(" new : %s\n", *myStrings[i]);
			}
		}
		break;
		case 0:
			endPart2 = 1;
			break; //if user enters a 0 end the loop
		}
	} while (endPart2 != 1);
}

/**This Function will fill our Array with random lower case values */
void fillArray(char letters[], int size) {
	printf("\nFilling Array!\n");
	for (int i = 0; i != size; i++) {
		char randomLowerAscii = (rand() % 26) + 97; // this will give me the values from 97-123(a-z in ASCII)
		letters[i] = randomLowerAscii;
		printf("%c", letters[i]);
	}
	printf("\n");
}

/*This function will take in a character array , a size, and an item, and return
* the number of times the item is in the array*/
int getFrequencyOf(char letters[], int size, char item) {
	int times = 0;
	for (int i = 0; i < size; i++) {
		if (letters[i] == item) {
			times++;
		}
	}
	return times;
}
/*This function takes in 3 parameters, and it removes a letter from the array and shifts all the values over*/
void removeCharacter(char letters[], int size, char item) {
	char arrayCopy[51]; //create a temporary array to copy letters[]
						/*loop through and if the item is in array set it to \0 */

	for (int i = 0; i < size; i++) {
		if (item == letters[i]) {
			letters[i] = '\0';

		}
		arrayCopy[i] = '\0'; //fill the copy array with \0
	}
	int count = 0; //index for copy array
				   /*copy all of the non \0 characters from letters into arrayCopy*/
	for (int i = 0; i < size; i++) {
		if (letters[i] != '\0') {
			arrayCopy[count] = letters[i];
			count++; //increment the count by 1
		}
	}
	/*loop through and copy elements from the copy back into the original array*/
	for (int i = 0; i < size; i++) {
		letters[i] = arrayCopy[i];
	}
}

/*this function will sort the array given alphabetically*/
void sort(char letters[], int size) {
	char temp;//temporary character
	for (int i = 0; i < letters[i]; i++) {
		for (int j = i + 1; j < letters[j]; j++) {
			if (letters[j] < letters[i]) {//if the 1st letter of the string is less than a character after in in ASCII then swap the 2 characters
				temp = letters[j];
				letters[j] = letters[i];
				letters[i] = temp;
			}
		}
	}
}