//Compulsory1, make a tic-tac-toe game, optional - with an AI opponent

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//board array
const int row = 3;
const int col = 3;
char boardSpaces[row][col] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

//functions
void menu();			
void gameBoard();		
int checkValidity();	
void markSpaces();		
char playerMark();
void cleanBoard();
int wincondition();
void playingWithArty();
void artyisUp();
int randomNrforArty();

//global variables
int nrTurns{ 1 };
char marked{};
char markX = 'X';
char markO = 'O';

int main() {
	
	menu();

	return 0;

}

//Menu selectionscreen FIRST STOP, send off to 
void menu() {

	char menuChoice{};

	std::cout << "\n\t\tWelcome to Tic-tac-toe! Please make a selection:\n\n"; 
	std::cout << "\t\t1. Two-player game\n" << "\t\t2. Play against an AI\n" << "\t\t0. Quit\n";
	std::cin >> menuChoice;

	switch (menuChoice) {

		case '1': 
			system("cls");
			cleanBoard();
			gameBoard();
			markSpaces();
			break;

		case '2': 
			system("cls");
			cleanBoard();
			gameBoard();
			playingWithArty();
			break;

		case '0':
			std::exit(0);
			break;

		default: 
			std::cout << "Invalid input, please try again.";
			system("cls");
			menu();
	
	}

}

//draws gameboard
void gameBoard() {

	std::cout << '\n' << '\t' << "-------------------" << std::endl;
	std::cout << '\t' << "|  " << boardSpaces[0][0] << "  |  " << boardSpaces[0][1] << "  |  " << boardSpaces[0][2] << "  |" << std::endl;
	std::cout << '\t' << "-------------------" << std::endl;
	std::cout << '\t' << "|  " << boardSpaces[1][0] << "  |  " << boardSpaces[1][1] << "  |  " << boardSpaces[1][2] << "  |" << std::endl;
	std::cout << '\t' << "-------------------" << std::endl;
	std::cout << '\t' << "|  " << boardSpaces[2][0] << "  |  " << boardSpaces[2][1] << "  |  " << boardSpaces[2][2] << "  |" << std::endl;
	std::cout << '\t' << "-------------------" << std::endl;
}

//function will check if move is valid, then mark it with an appropriate marker
void markSpaces() { 

	int validity{};
	char playerName{};

	playerName = playerMark();

	std::cout << "Player, " << playerName << " please enter your move!";
	std::cin >> marked;

	validity = checkValidity(); //function calls on 'check validity'

	if (validity == 0) {
		std::cout << "Invalid input, please try again.";
		markSpaces();
	}
	else {
		system("cls");
		gameBoard();
		nrTurns++;
	}

	if (nrTurns >= 6) { 
	
		int declearWinner{};
	
		declearWinner = wincondition();
			
		if (declearWinner == 1) {
			std::cout << "\nX wins";
			menu();

		}
		else if (declearWinner == 2) {
			std::cout << "\nO wins";
			menu();
		}
		else if (nrTurns == 10) { //automatic draw
			system("cls");
			std::cout << "its a draw";
			menu();
		}
		else {
			markSpaces();
		}
		
	}
		
	markSpaces();

}

//checks validity of move, if space already has an 'X' or an 'O' the move is not valid, then checks for number of turn to decide if it is a draw or not
int checkValidity() { 
	
	int checked{};

	for (int u = 0; u < col; u++) {
		for (int v = 0; v < row; v++) {

			if (marked == boardSpaces[u][v]) {

				boardSpaces[u][v] = playerMark(); //space is marked if valid

				checked = 1;
				
				break;

			}

		}
	
	}

	return checked; //returns to markSpaces function
}

char playerMark() { //add correct marker

	char marker;

	if (nrTurns % 2 == 0){
		marker = markX;
	}
	else {
		marker = markO;
	}
	
	return marker;
}

void cleanBoard() { //puts right numbers in board to make a 'clean' playing board
	
	int x{};
	char cleanNumber[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	nrTurns = 1;

	for (int u = 0; u < col; u++) {
		for (int v = 0; v < row; v++) {
			
			boardSpaces[u][v] = cleanNumber[x];
			
			++x;

		}

	}

}

//checks for win condition
int wincondition() {
	
	int chickenDinner{}; //wincondition variable
	
	//eight winconditions for both players - three horizontal, three vertical, two diagonal
	if (boardSpaces[0][0] == boardSpaces[0][1] && boardSpaces[0][0] == boardSpaces[0][2]) {
		if (boardSpaces[0][0] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[0][0] == 'O') {
			chickenDinner = 2;
		}
	}
	else if (boardSpaces[1][0] == boardSpaces[1][1] && boardSpaces[1][2] == boardSpaces[1][0]) {
		if (boardSpaces[1][0] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[1][0] == 'O') {
			chickenDinner = 2;
		}
	}
	else if (boardSpaces[2][0] == boardSpaces[2][1] && boardSpaces[2][2] == boardSpaces[2][0]) {
		if (boardSpaces[2][0] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[2][0] == 'O') {
			chickenDinner = 2;
		}
	}
	else if (boardSpaces[0][0] == boardSpaces[1][0] && boardSpaces[2][0] == boardSpaces[0][0]) {
		if (boardSpaces[0][0] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[0][0] == 'O') {
			chickenDinner = 2;
		}
	}
	else if (boardSpaces[0][1] == boardSpaces[1][1] && boardSpaces[2][1] == boardSpaces[0][1]) {
		if (boardSpaces[0][1] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[0][1] == 'O') {
			chickenDinner = 2;
		}
	}
	else if (boardSpaces[0][2] == boardSpaces[1][2] && boardSpaces[2][2] == boardSpaces[0][2]) {
		if (boardSpaces[0][2] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[0][2] == 'O') {
			chickenDinner = 2;
		}
	}
	else if (boardSpaces[0][0] == boardSpaces[1][1] && boardSpaces[2][2] == boardSpaces[0][0]) {
		if (boardSpaces[0][0] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[0][0] == 'O') {
			chickenDinner = 2;
		}
	}
	else if (boardSpaces[0][2] == boardSpaces[1][1] && boardSpaces[2][0] == boardSpaces[0][2]) {
		if (boardSpaces[0][2] == 'X') {
			chickenDinner = 1;
		}
		else if (boardSpaces[0][2] == 'O') {
			chickenDinner = 2;
		}
	}
	else {
		chickenDinner = 0;

	}
	
	return chickenDinner;
}

//AI-version specific functions

//human player starts against Arty
void playingWithArty() {

	int validity{};
	
	std::cout << "Human player! Chose your move: ";
	std::cin >> marked;

	validity = checkValidity(); //function calls on 'check validity'
	if (validity == 0) {
		std::cout << "Invalid input, please try again.";
		playingWithArty();
	}
	else if (validity == 1) {
		system("cls");
		gameBoard();
		nrTurns++;
	}

	if (nrTurns >= 5) {
				
		int declearWinner{};

		declearWinner = wincondition();

		if (declearWinner == 1) {
			std::cout << "\nX wins";
			menu();
		}
		else if (declearWinner == 2) {
			std::cout << "\nO wins";
			menu();
		}
		else if (nrTurns == 10) { //automatic draw
			system("cls");
			std::cout << "its a draw";
			menu();
		}
	
	}

	artyisUp();
}

//Arty the AI
void artyisUp() {

	int helpingArty{};
	int validity{};

	if (nrTurns == 2) { //arty choses one of the four corners to put their mark in

		helpingArty = randomNrforArty(); //call on random nr to chose corner

		if (helpingArty == 1 && 4) {
			marked = '1';
		}
		else if (helpingArty == 7 && 2) {
			marked = '7';
		}
		else if (helpingArty == 9 && 6) {
			marked = '9';
		}
		else {
			marked = '3';
		}

		validity = checkValidity();	//checks if valid move

		if (validity == 0) {
			artyisUp();
		}
		else {
			system("cls");
			gameBoard();
			nrTurns++;
		}
	}
	else {
		while (nrTurns != 2) {//checks if human is about to win and places own mark to block if they are
			if (boardSpaces[0][1] == 'O' && boardSpaces[0][2] == 'O' && boardSpaces[0][0] == '1') {		//A
				marked = '1';
				break;
			}
			else if (boardSpaces[1][1] == 'O' && boardSpaces[2][2] == 'O' && boardSpaces[0][0] == '1') {	//B
				marked = '1';
				break;
			}
			else if (boardSpaces[1][0] == 'O' && boardSpaces[2][0] == 'O' && boardSpaces[0][0] == '1') {	//C
				marked = '1';
				break;
			}
			else if (boardSpaces[0][0] == 'O' && boardSpaces[0][2] == 'O' && boardSpaces[0][1] == '2') {	//D
				marked = '2';
				break;
			}
			else if (boardSpaces[1][1] == 'O' && boardSpaces[2][1] == 'O' && boardSpaces[0][1] == '2') {	//E
				marked = '2';
				break;
			}
			else if (boardSpaces[0][0] == 'O' && boardSpaces[0][1] == 'O' && boardSpaces[0][2] == '3') {	//F
				marked = '3';
				break;
			}
			else if (boardSpaces[1][1] == 'O' && boardSpaces[2][0] == 'O' && boardSpaces[0][2] == '3') {	//G
				marked = '3';
				break;
			}
			else if (boardSpaces[1][2] == 'O' && boardSpaces[2][2] == 'O' && boardSpaces[0][2] == '3') {	//H
				marked = '3';
				break;
			}
			else if (boardSpaces[0][0] == 'O' && boardSpaces[2][0] == 'O' && boardSpaces[1][0] == '4') {	//I
				marked = '4';
				break;
			}
			else if (boardSpaces[1][1] == 'O' && boardSpaces[1][2] == 'O' && boardSpaces[1][0] == '4') {	//J
				marked = '4';
				break;
			}
			else if (boardSpaces[0][1] == 'O' && boardSpaces[2][1] == 'O' && boardSpaces[1][1] == '5') {	//K
				marked = '5';
				break;
			}
			else if (boardSpaces[1][0] == 'O' && boardSpaces[1][2] == 'O' && boardSpaces[1][1] == '5') {	//L
				marked = '5';
				break;
			}
			else if (boardSpaces[0][2] == 'O' && boardSpaces[2][2] == 'O' && boardSpaces[1][2] == '6') {	//N
				marked = '6';
				break;
			}
			else if (boardSpaces[1][0] == 'O' && boardSpaces[1][1] == 'O' && boardSpaces[1][2] == '6') {	//M
				marked = '6';
				break;
			}
			else if (boardSpaces[0][0] == 'O' && boardSpaces[1][0] == 'O' && boardSpaces[2][0] == '7') {	//O
				marked = '7';
				break;
			}
			else if (boardSpaces[0][2] == 'O' && boardSpaces[1][1] == 'O' && boardSpaces[2][0] == '7') {	//P
				marked = '7';
				break;
			}
			else if (boardSpaces[2][1] == 'O' && boardSpaces[2][2] == 'O' && boardSpaces[2][0] == '7') {	//Q
				marked = '7';
				break;
			}
			else if (boardSpaces[0][1] == 'O' && boardSpaces[1][1] == 'O' && boardSpaces[2][1] == '8') {	//R	
				marked = '8';
				break;
			}
			else if (boardSpaces[2][0] == 'O' && boardSpaces[2][2] == 'O' && boardSpaces[2][1] == '8') {	//S
				marked = '8';
				break;
			}
			else if (boardSpaces[0][0] == 'O' && boardSpaces[1][1] == 'O' && boardSpaces[2][2] == '9') {	//T
				marked = '9';
				break;
			}
			else if (boardSpaces[0][2] == 'O' && boardSpaces[1][1] == 'O' && boardSpaces[2][2] == '9') {	//U
				marked = '9';
				break;
			}
			else if (boardSpaces[2][0] == 'O' && boardSpaces[2][1] == 'O' && boardSpaces[2][2] == '9') {	//V
				marked = '9';
				break;
			}
			else { //if Arty is about to win, they will take the chance
				if (nrTurns != 2) {
					if (boardSpaces[0][1] == 'X' && boardSpaces[0][2] == 'X' && boardSpaces[0][0] == '1') {		//A
						marked = '1';
						break;
					}
					else if (boardSpaces[1][1] == 'X' && boardSpaces[2][2] == 'X' && boardSpaces[0][0] == '1') {	//B
						marked = '1';
						break;
					}
					else if (boardSpaces[1][0] == 'X' && boardSpaces[2][0] == 'X' && boardSpaces[0][0] == '1') {	//C
						marked = '1';
						break;
					}
					else if (boardSpaces[0][0] == 'X' && boardSpaces[0][2] == 'X' && boardSpaces[0][1] == '2') {	//D
						marked = '2';
						break;
					}
					else if (boardSpaces[1][1] == 'X' && boardSpaces[2][1] == 'X' && boardSpaces[0][1] == '2') {	//E
						marked = '2';
						break;
					}
					else if (boardSpaces[0][0] == 'X' && boardSpaces[0][1] == 'X' && boardSpaces[0][2] == '3') {	//F
						marked = '3';
						break;
					}
					else if (boardSpaces[1][1] == 'X' && boardSpaces[2][0] == 'X' && boardSpaces[0][2] == '3') {	//G
						marked = '3';
						break;
					}
					else if (boardSpaces[1][2] == 'X' && boardSpaces[2][2] == 'X' && boardSpaces[0][2] == '3') {	//H
						marked = '3';
						break;
					}
					else if (boardSpaces[0][0] == 'X' && boardSpaces[2][0] == 'X' && boardSpaces[1][0] == '4') {	//I
						marked = '4';
						break;
					}
					else if (boardSpaces[1][1] == 'X' && boardSpaces[1][2] == 'X' && boardSpaces[1][0] == '4') {	//J
						marked = '4';
						break;
					}
					else if (boardSpaces[0][1] == 'X' && boardSpaces[2][1] == 'X' && boardSpaces[1][1] == '5') {	//K
						marked = '5';
						break;
					}
					else if (boardSpaces[1][0] == 'X' && boardSpaces[1][2] == 'X' && boardSpaces[1][1] == '5') {	//L
						marked = '5';
						break;
					}
					else if (boardSpaces[0][2] == 'X' && boardSpaces[2][2] == 'X' && boardSpaces[1][2] == '6') {	//N
						marked = '6';
						break;
					}
					else if (boardSpaces[1][0] == 'X' && boardSpaces[1][1] == 'X' && boardSpaces[1][2] == '6') {	//M
						marked = '6';
						break;
					}
					else if (boardSpaces[0][0] == 'X' && boardSpaces[1][0] == 'X' && boardSpaces[2][0] == '7') {	//O
						marked = '7';
						break;
					}
					else if (boardSpaces[0][2] == 'X' && boardSpaces[1][1] == 'X' && boardSpaces[2][0] == '7') {	//P
						marked = '7';
						break;
					}
					else if (boardSpaces[2][1] == 'X' && boardSpaces[2][2] == 'X' && boardSpaces[2][0] == '7') {	//Q
						marked = '7';
						break;
					}
					else if (boardSpaces[0][1] == 'X' && boardSpaces[1][1] == 'X' && boardSpaces[2][1] == '8') {	//R	
						marked = '8';
						break;
					}
					else if (boardSpaces[2][0] == 'X' && boardSpaces[2][2] == 'X' && boardSpaces[2][1] == '8') {	//S
						marked = '8';
						break;
					}
					else if (boardSpaces[0][0] == 'X' && boardSpaces[1][1] == 'X' && boardSpaces[2][2] == '9') {	//T
						marked = '9';
						break;
					}
					else if (boardSpaces[0][2] == 'X' && boardSpaces[1][1] == 'X' && boardSpaces[2][2] == '9') {	//U
						marked = '9';
						break;
					}
					else if (boardSpaces[2][0] == 'X' && boardSpaces[2][1] == 'X' && boardSpaces[2][2] == '9') {	//V
						marked = '9';
						break;
					}
					else { //if they don't need to block the human player or is about to win, Arty makes more chances for themselves by marking a corner

						helpingArty = randomNrforArty(); //call on random nr to chose corner

						if (helpingArty == 1 && 3) {
							marked = '1';
						}
						else if (helpingArty == 7 && 5) {
							marked = '7';
						}
						else if (helpingArty == 9 && 2) {
							marked = '9';
						}
						else {
							marked = '3';
						}

					break;
					}
				
				}

			}

		}

	validity = checkValidity();	//checks if valid move

	if (validity == 0) {
		artyisUp();
	}
	else {
		system("cls");
		gameBoard();
		nrTurns++;
	}

	}
	
	//checks if they won
	int declearWinner{}; 

	declearWinner = wincondition();

	if (declearWinner == 1) {
		std::cout << "\nArty the AI wins!";
		menu();

	}
	else if (declearWinner == 2) {
		std::cout << "\nHuman Player wins!";
		menu();
	}
	else if (nrTurns == 10) { //automatic draw
		system("cls");
		std::cout << "It's a draw!";
		menu();
	}

	playingWithArty(); //after Arty's move and they didn't win, it is the human player's turn
}

//randomgenerated numbers to help Arty make
int randomNrforArty() {
	
	int nrArty{};
	int min = 1;
	int max = 9;

	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
	
	nrArty = min + static_cast<int>((max - min + 1) * (std::rand() *fraction));
	
	return nrArty;
}
