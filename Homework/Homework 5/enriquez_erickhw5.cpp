#include <iostream>
using namespace std;
/* constant values for the suits*/
enum suit {
	heart,club,spade,diamond
};

/*a structure made up of 3 members a suit enum, a value, and a boolean is flipped value*/
struct cardStruct
{
	 suit cardSuit;
	 int cardValue;
	 bool isFlipped;
};

/*functions*/
void buildDeck(cardStruct[]);//builds the deck of 52 cards in order
void shuffleDeck(cardStruct*, int);//shuffles the deck
bool cardMatch(cardStruct, cardStruct);//checks to see if 2 cards match in value
void printGrid(cardStruct**, int, int);//prints the grid 
void flipCard(cardStruct**, int, int);//flips card from faceup or facedown
void clearScreen();//"clears the screen"
bool checkForWin(int);//see if all of the pairs are done
cardStruct draw(cardStruct*, int&,int);//place cards from dealer array into 2d grid

/*global variables*/
int numOfColumns;
int numOfCards;
bool won = false;
char pause;


int main(){
	cardStruct mydeck[52];//create an array of 52 cards
	buildDeck(mydeck);// build the deck of cards
	cout << "Welcome to CSE 240 Memory!\nThe rules are simple, pick 2 cards and see if they match.\nuntil you've matched all of the cards\nyou may enter -1 for your cards at any time during play to quit.\n\nHow many columns of cards do you want to play with?\nmin of 3 and max of 13:\t";
	cin >> numOfColumns;
	if (numOfColumns <= 13 && numOfColumns >= 3) {
		numOfCards = 4 * numOfColumns;//get the total number of cards that will be used for the game
		cardStruct* dealerDeck = new cardStruct[numOfCards];//allocate an array of 4* number of columns of cardStructs
		for (int i = 0; i < numOfCards; i++) {// copy as many cards as the user wants to play the game
			dealerDeck[i] = mydeck[i];//copy the cards from the array to a dealer deck middle-man
		}
		shuffleDeck(dealerDeck, numOfCards);//shuffle the dealer deck
		
		cardStruct** grid = new cardStruct*[4];//create a grid to place dealer array into
		for (int i = 0; i < 4; i++) {
			grid[i] = new cardStruct[numOfColumns];//allocate number of columns to each of the rows
		}
		int count = 0;
		for (int i = 0; i < 4; i++) {//take the shuffled dealer deck and place it into the grid of cards
			for (int j = 0; j < numOfColumns; j++) {
				grid[i][j] = draw(dealerDeck,numOfCards,count);//copy the dealer array into the grid array
				count++;
			}
		}
		int x1, y1, x2, y2;// coordinates for the cards
		do {
			clearScreen();
			printGrid(grid,4,numOfColumns);//print the grid
			cout << "\ncoordinates of card1?\n";
			cin >> x1 >> y1;//set coordinates of card 1
			if (x1 == -1 && y1 == -1) {
				won = true;//if the player enters -1,-1 in for first coordinates
				break;//end loop
			}

			if (grid[x1][y1].isFlipped != true) {//if the first card hasnt been already flipped
				flipCard(grid, x1, y1);//set the first card to be flipped
				clearScreen();//clear the screen
				printGrid(grid, 4, numOfColumns);//print the grid again
				cout << "\ncoordinates of card2?\n";
				cin >> x2 >> y2;

				if (grid[x2][y2].isFlipped != true) {//if the 2nd card hasnt been already flipped
					flipCard(grid, x2, y2);//flip card so user can see it 
					clearScreen();//clear screen
					printGrid(grid, 4, numOfColumns);//reprint the grid

					if (cardMatch(grid[x1][y1], grid[x2][y2]) == false) {
						grid[x1][y1].isFlipped = false;//set card 1 to not be flipped
						grid[x2][y2].isFlipped = false;// set card 2 to not be flipped
						cout << "\nNot A Match\n";
						cin >> pause;
						clearScreen();
						printGrid(grid, 4, numOfColumns);
					}
					cout << "\ncards match\n";
					numOfCards -= 2;// subtract the pair from num of cards in play
					won = checkForWin(numOfCards);//check to see if user has won game
				}
				else {
					cout << "\ninvlalid card already flipped\n\n";
				}
			}
			else {
				cout << "\ninvlalid card already flipped\n\n";
			}
		} while (won != true);
		
	}
	else {
		cout << endl << "invalid input" << endl;
	}
	return 0;
}

/*This function takes an array of cardstructs and initalizes them in order*/
void buildDeck(cardStruct deck[51]) {
	int suit;
	int count = 1;
	int x = 0;
	/*loop through and make 13 groupings of all the suits*/
	for (int i = 0; i <= 51; i++) {
		suit = i % 4;
		switch (suit) {
		case 0: deck[i].cardSuit = heart; break;
		case 1: deck[i].cardSuit = club; break;
		case 2: deck[i].cardSuit = spade; break;
		case 3: deck[i].cardSuit = diamond; break;
		}
	}
	/*loop through and give each of the 13 pairs a value from 1-13*/
	for (int i = 0; i < 52; i += 4) {
		for (int j = 0; j % 5 <4; j++) {
			deck[x].cardValue = count;
			x++;
		}
		count++;
	}
}

/*This function takes in an array and a size and "shuffles" the cards in the array*/
void shuffleDeck(cardStruct* deck, int size) {
	cout << "-------------------Shuffling deck--------------------" << endl;
	cardStruct temp;// create a temporary cardStrcut  variable
	int randomIndex = 0;// will give you random numbers
	for (int i = 0; i < size; i++) {
		randomIndex = rand() % size;//this will give you a random index between 0 and 51
		temp = deck[i];//take the cardStruct at deck index i and store it in temp
		deck[i] = deck[randomIndex];//take the index of i and swap it with the random index generated
		deck[randomIndex] = temp;//store the value of the temp cardStruct and store it at the index of randomIndex
	}
}

/*This function takes in 2 cardstructs and checks to see if they have the same numerical value*/
bool cardMatch(cardStruct card1, cardStruct card2)
{
	if (card1.cardValue == card2.cardValue) {
		return true;
	}
	else {
		return false;
	}
}

void printGrid(cardStruct ** grid, int rows, int columns){
	int count = 0;
	//print the top of the grid
	for (int i = 0; i < columns; i++) {
		cout << "   " << i;
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		cout << endl << count << " ";
		for (int j = 0; j < columns; j++) {
			if (grid[i][j].isFlipped == true) {
				cout<<" "<<grid[i][j].cardValue<<"  ";//loop through the grid and print the value of the card
			}
			else {
				cout << " *  ";
			}
		}
		count++;
	}
}
/*flip the card over if the card is not already flipped*/

void flipCard(cardStruct ** grid, int x, int y){
	if (grid[x][y].isFlipped != true) {
		grid[x][y].isFlipped = true;
	}
}

/*check to see if the user has won the game*/
bool checkForWin(int numOfPairs)
{
	if (numOfPairs == 0) {
		return true; 
	}
	else {
		return false;
	}
}

/*this function takes in an array ,a size , and an index and draws from the array*/
cardStruct draw(cardStruct * deck, int &size,int index)
{
	return deck[index];
}

/*This function outputs a bunch of newlines so that it apprears to "clear" screen*/
void clearScreen() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

