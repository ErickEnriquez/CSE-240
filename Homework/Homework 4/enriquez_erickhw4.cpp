#include<iostream>
using namespace std;

//prototype functions
void drivePart1();
void drivePart2();
void sort(char*,int);
int getFrequencyOf(char*,char,int);
void fillArray(char* ,int);
void removeChar(char*,char,int);

//variables
bool endLoop = false;//will end the program
char choice;//user input for the menu
char letter;//letter user input for various options
char* oneDimArray;//a character pointer for 1D arrays
char** doublePointer;//a double pointer for 2D arrays

int main() 
{
	do {
		cout << "\nWelcome to Assignment 4\n1 - Single dimension array proccessing\n2 - 2D Proccessing\n0 -End program\nChoose an option:" ;//print prompt
		cin >> choice;// get user input
		switch (choice){
		case '1':
			drivePart1(); break;// if user wants to work in single dimesion
		case '2':
			drivePart2(); break;//if user wants to work in 2D
		case '0':
			endLoop = true; break;// if user wants to end the loop
			}
	} while (endLoop != true);
	return 0;
}
/*This part is for single dimension arrays*/
void drivePart1() {
	oneDimArray = new char[51];//allocate 51 bytes to the array
	fillArray(oneDimArray,51);//fill the array with random characters
	do {
		cout << "\nOptions\n1 - check the frequency of a letter\n2 - remove a letter from the array\n3- sort\n0 - return to the main menu\nchoose an option:";
		cin >> choice;
		switch (choice) {
		case '1': {// if the user wants to check the frequency of a letter
			cout << "\nwhich letter would you like to check?\t";
			cin >> letter;
			if (letter >= 97 && letter <= 123) {//check if letter is lowercase with its ASCII value
				cout << letter << " is in array " << getFrequencyOf(oneDimArray, letter,51) << " times\n";
			}
			else {
				cout << letter << " is an invalid character";
			}
		}
			break;
		case '2': {//if user wants to remove a letter from array
			cout << "which letter would you like to remove\t";
			cin >> letter;
			if (letter >= 97 && letter <= 123) {//check if letter is lowercase with its ASCII value
				removeChar(oneDimArray, letter, 51);
				for (int i = 0; i < 51; i++) {
					cout << oneDimArray[i];//loop through and print the array
				}	
			}
			else {
				cout << letter << " is invalid\n";
			}
		}
			break;
		case '3': {//if the user wants to for the array alphabetically
			cout << "\nSorting\n" ;
			sort(oneDimArray,51);//sort array
			for (int i = 0; i < 51; i++) {
				cout << oneDimArray[i];//print out the one dimension array
			}
			cout << endl;
		}
			break;
		case '0':break;//if user wants to exit loop
		default:cout << "Invalid\n"; break;//if user enters invalid input
		}
		
	} while (choice != '0');
	delete[] oneDimArray;// free up memory

}
/*This part is 2D Strings*/
void drivePart2() {
	doublePointer = new char*[10];//allocate 10 character pointers
	for (int i=0; i < 10; i++) {
		oneDimArray = new char[15];// loop through and allocate 15 bytes 
		doublePointer[i] = oneDimArray;//place the 15 bytes at each of the 10 char* to get a 2d array
	}

	for (int i = 0; i < 10; i++) {
		cout << "Enter string "<<i+1<<"\t";//ask for user input 10 times and store each of the C style strings at the double pointer at index i
		cin >> doublePointer[i];
	}

	for (int i = 0; i < 10; i++) {
		cout  <<"you entered\t"<< doublePointer[i]<<endl;//print out the users input
	}

	do {//loop through until the user input 1 
		cout << "options\n1 - Check the frequency of a letter\n2 - Remove a letter\n0 - Return to main menu:\t";
		cin >> choice;
		switch (choice) {
		case '1': {//if the user wants to check the frequency of a letter
			cout << "Which letter?\t";
			cin >> letter;
			if (letter >= 97 && letter <= 123) {
				for (int i = 0; i < 10; i++) {
					cout <<doublePointer[i]<<" - "<< getFrequencyOf(doublePointer[i], letter, 15)<<endl;//print out each of the 10 char* and the number of times letter is in them
				}
			}
			else cout << letter << " is invalid input\n";//if user enters something that is invalid
		}
				  break;
		case '2': {//if user wants to remove a character from the strings
			cout << "which letter?\t";
			cin >> letter;
			if (letter >= 97 && letter <= 123) {//check if the value is lowercase letter
				for (int i = 0; i < 10; i++) {
					removeChar(doublePointer[i], letter, 15);//remove the selected character from the arrays
				}
				for (int i = 0; i < 10; i++) {//loop through and print the 2D array
					for (int j = 0; j < 15; j++) {
						if (doublePointer[i][j] != '\0') {
							cout << doublePointer[i][j];
						}
					}
				}
			}
			else cout << letter << " is invalid\n";
		}
				  break;
		case'0':break;//if user wants to end loop
		default: cout << "Invalid\n"; break;// in case user inputs a number that isn't valid
		}
	} while (choice !='0');
	
}
/*This function will fill an array with random lower case values*/
void fillArray(char* lettersPtr,int size) {
	cout << "\nFilling array!\n";
	char randomLetter; 
	for (int i = 0; i < size; i++) {//loop through array and fill them with random lowercase letters
		randomLetter = 97 + (rand() % 26);// will give you a random lowercase letter from a-z  which are 97 through 123 in ASCII
		lettersPtr[i] = randomLetter;//store the character at index i
		cout << lettersPtr[i];//print out the array
	}
	cout << "\n";
}
/*The function will give you the number of times the letter is in the array*/
int getFrequencyOf(char* lettersPtr,char letter,int size) {
	int count = 0;
	for (int i = 0; i !=  size ; i++) {
		if (*(lettersPtr + i) == letter) {//if the value at the address of pointer is equal to the letter increment counter
			count++;
		}
	}
	return count;
}
/*This function sorts the array alphabetically for lowercase letters */
void sort(char* letters, int size) {
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
/*The function will remove any instances of the char from the array*/
void removeChar(char* lettersPtr,char letter,int size) {
	char* arrayCopy = new char[size]; //create a temporary array to copy letters[]
	/*loop through and if the item is in array set it to \0 */
	for (int i = 0; i < size; i++) {
		if (letter == lettersPtr[i]) {
			lettersPtr[i] = '\0';

		}
		arrayCopy[i] = '\0'; //fill the copy array with \0
	}
	int count = 0; //index for copy array
				   /*copy all of the non \0 characters from letters into arrayCopy*/
	for (int i = 0; i < size; i++) {
		if (lettersPtr[i] != '\0') {
			arrayCopy[count] = lettersPtr[i];
			count++; //increment the count by 1
		}
	}
	/*loop through and copy elements from the copy back into the original array*/
	for (int i = 0; i < size; i++) {
		lettersPtr[i] = arrayCopy[i];
	}
	


}