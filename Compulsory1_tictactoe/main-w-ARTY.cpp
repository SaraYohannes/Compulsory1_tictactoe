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
//void playingWithArty();//AI
//void artyisUp();
//int randomNrforArty();

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
			std::cout << "You chose option 2.";
			system("cls");
			//playingWithArty();
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

	std::cout << "Player " << nrTurns << " please enter your move!";
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

////maingame, playing with Arty
//void playingWithArty() {
//
//	int validity{};
//	
//	if (nrTurns >= 5) {
//				
//		int declearWinner{};
//
//		declearWinner = wincondition();
//
//		if (declearWinner == 1) {
//			std::cout << "\nX wins";
//			menu();
//		}
//		else if (declearWinner == 2) {
//			std::cout << "\nO wins";
//			menu();
//		}
//		else if (nrTurns == 10) { //automatic draw
//			system("cls");
//			std::cout << "its a draw";
//			menu();
//		}
//		else {
//			playingWithArty();
//		}
//	}
//
//	std::cout << "Human player! Chose your move: ";
//	std::cin >> marked;
//
//	validity = checkValidity(); //function calls on 'check validity'
//
//	if (validity == 0) {
//		std::cout << "Invalid input, please try again.";
//		playingWithArty();
//	}
//	else {
//		system("cls");
//		gameBoard();
//		nrTurns++;
//	}
//
//	artyisUp();
//}
//
////Arty the AI
//void artyisUp() {
//
//	int helpingArty{};
//	int validity{};
//
//	if (nrTurns == 2) { //arty choses one of the four corners to put their mark in
//		
//		helpingArty = randomNrforArty(); //call on random nr to chose corner
//		
//		if (helpingArty % 3 == 0) {
//			boardSpaces[0][0] = playerMark();
//		}
//		else if (helpingArty % 5 == 0) {
//			boardSpaces[2][0] = playerMark();
//		}
//		else {
//			boardSpaces[2][2] = playerMark();
//		}
//
//		validity = checkValidity();	//checks if valid
//
//		if (validity == 0) {
//			artyisUp();
//		}
//		else {
//			system("cls");
//			gameBoard();
//			nrTurns++;
//		}
//	}
//	else //checks if human is about to win and places own mark to block
//		if (boardSpaces[0][1] == boardSpaces[0][2] == 'O') {		//A
//			boardSpaces[0][0] = playerMark();
//		}
//		else if (boardSpaces[1][1] == boardSpaces[2][2] == 'O') {	//B
//			boardSpaces[0][0] = playerMark();
//		}
//		else if (boardSpaces[1][0] == boardSpaces[2][0] == 'O') {	//C
//			boardSpaces[0][0] = playerMark();
//		}
//		else if (boardSpaces[0][0] == boardSpaces[0][2] == 'O') {	//D
//			boardSpaces[0][1] = playerMark();
//		}
//		else if (boardSpaces[1][1] == boardSpaces[2][1] == 'O') {	//E
//			boardSpaces[0][1] = playerMark();
//		}
//		else if (boardSpaces[0][0] == boardSpaces[0][1] == 'O') {	//F
//			boardSpaces[0][2] = playerMark();
//		}
//		else if (boardSpaces[1][1] == boardSpaces[2][0] == 'O') {	//G
//			boardSpaces[0][2] = playerMark();
//		}
//		else if (boardSpaces[1][2] == boardSpaces[2][2] == 'O') {	//H
//			boardSpaces[0][2] = playerMark();
//		}
//		else if (boardSpaces[0][0] == boardSpaces[2][0] == 'O') {	//I
//			boardSpaces[1][0] = playerMark();
//		}
//		else if (boardSpaces[1][1] == boardSpaces[1][2] == 'O') {	//J
//			boardSpaces[1][0] = playerMark();
//		}
//		else if (boardSpaces[0][1] == boardSpaces[2][1] == 'O') {	//K
//			boardSpaces[1][1] = playerMark();
//		}
//		else if (boardSpaces[1][0] == boardSpaces[1][2] == 'O') {	//L
//			boardSpaces[1][1] = playerMark();
//		}
//		else if (boardSpaces[0][2] == boardSpaces[2][2] == 'O') {	//N
//			boardSpaces[1][2] = playerMark();
//		}
//		else if (boardSpaces[1][0] == boardSpaces[1][1] == 'O') {	//M
//			boardSpaces[1][2] = playerMark();
//		}
//		else if (boardSpaces[0][0] == boardSpaces[1][0] == 'O') {	//O
//			boardSpaces[2][0] = playerMark();
//		}
//		else if (boardSpaces[0][2] == boardSpaces[1][1] == 'O') {	//P
//			boardSpaces[2][0] = playerMark();
//		}
//		else if (boardSpaces[2][1] == boardSpaces[2][2] == 'O') {	//Q
//			boardSpaces[2][0] = playerMark();
//		}
//		else if (boardSpaces[0][1] == boardSpaces[1][1] == 'O') {	//R	
//			boardSpaces[2][1] = playerMark();
//		}
//		else if (boardSpaces[2][0] == boardSpaces[2][2] == 'O') {	//S
//			boardSpaces[2][1] = playerMark();
//		}
//		else if (boardSpaces[0][0] == boardSpaces[1][1] == 'O') {	//T
//			boardSpaces[2][2] = playerMark();
//		}
//		else if (boardSpaces[0][2] == boardSpaces[1][1] == 'O') {	//U
//			boardSpaces[2][2] = playerMark();
//		}
//		else if (boardSpaces[2][0] == boardSpaces[2][1] == 'O') {	//V
//			boardSpaces[2][2] = playerMark();
//		}		//if valid, mark it//block win by trying to mark it
//				//if not valid, try again//human is about to win
//		else { //tries to heighten chance of winning//check if valid
//
//		}
//
//	playingWithArty();
//}
//
////randomgenerated numbers to help Arty make decisions
//int randomNrforArty() {
//	
//	int nrArty{};
//
//	std::srand(static_cast<unsigned int>(std::time(nullptr)));
//
//	nrArty << std::rand();
//
//	return nrArty;
//}
