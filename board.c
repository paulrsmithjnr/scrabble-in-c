/*
Paul Smith
620118115
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Function Declarations
int calculateScore(char * word);
int isOnBoard(int x, int y);
int getLetterScore(char letter);
char* getLetter(char letter);
int isWord(char word[]);

int main(){

    int k,j;
    int const NUM_RANGE=8;

    //global declaration structure grid
    char grid[NUM_RANGE][NUM_RANGE];

    char *wordsFound[70];
    int player[70];
    int nextIndex = 0;

    //variables to help keep track of the current player and the players' scores
    int playersScores[2] = {0, 0}, currentPlayer = 0;


    void getNewBoard(){
        //creates a brand new blank board. Returns a pointer to the array 
        for (j = 0; j < NUM_RANGE; j++){
            for (k = 0; k < NUM_RANGE; k++)
            {
                grid[k][j]=' ';
            }//Endfor
        }//Endfor
        return;
    }//EndFunction getNewBoard

    void drawBoard(){
        //This function prints out the board that was passed. Returns void
        char * const NLINE = "    1    2    3    4    5    6    7    8";
        char * const HLINE = "  +----+----+----+----+----+----+----+----+";
        char * const VLINE = "  |    |    |    |    |    |    |    |    |";

        printf("%s\n",NLINE);
        printf("%s\n",HLINE);
        for (j = 0; j < NUM_RANGE; j++)
        {  
            printf("%s\n",VLINE);
            printf("%d ",j+1);
            for (k = 0; k < NUM_RANGE; k++)
            {  //if(strcmp(grid[k][j],"   ")==0)
                if(grid[k][j] == ' '){
                    printf("| %c  ",grid[k][j]);
                }else{
                    printf("| %c  ",grid[k][j]);
                }
            }
            printf("%s","|");
            printf("\n");
            printf("%s\n",VLINE);
            printf("%s\n",HLINE);
        }
        return;
    }//EndFunction drawBoard

    
    void makePlay(int x, int y, char c){
        //Arrays are zero indexed but our grid starts at index 1
        grid[x-1][y-1]=c;
        return;
    }


    //This function checks to see if the board is full; returns 1 if it is and 0 if it is not
    int isBoardFull() {
        for(int a = 0; a < NUM_RANGE; a++) {
            for(int b = 0; b < NUM_RANGE; b++) {
                if(grid[a][b] == ' ') {
                    return 0;
                }
            }
        } 
        return 1;
    }


    //This function adds a word found on the grid to the "wordsFound" array
    void addWord(char *word) {
        wordsFound[nextIndex] = malloc(strlen(word));
        strcpy(wordsFound[nextIndex], word);

        player[nextIndex] = currentPlayer;

        nextIndex++;
    }

    //This function checks every direction to see if the last  
    //letter entered starts a word (diagonals are included)
    int checkWords(int x, int y) {
        int a = x - 1;
        int b = y - 1;
        int score = 0; //Keeps track of the score generated from all the words found

        int wordFoundFlag = 0; //changes to 1 when a word is found
        int index = nextIndex, wordCount = 0;

        //declares and initializes the string
        char word[8];
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }

        //checks if the last letter entered starts a word that goes toward the left
        int i = 0;
        while (1) {
            if((grid[a-i][b] == ' ') || ((a-i) < 0)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a-i][b]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }


        //checks if the last letter entered starts a word that goes toward the right
        i = 0;
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }
        while (1) {
            if((grid[a+i][b] == ' ') || ((a+i) > 7)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a+i][b]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }

        //checks if the last letter entered starts a word that goes up
        i = 0;
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }
        while (1) {
            if((grid[a][b-i] == ' ') || ((b-i) < 0)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a][b-i]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }

        //checks if the last letter entered starts a word that goes down
        i = 0;
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }
        while (1) {
            if((grid[a][b+i] == ' ') || ((b+i) > 7)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a][b+i]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }

        //checks if the last letter entered starts a word that runs diagonally - up, left
        i = 0;
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }
        while (1) {
            if((grid[a-i][b-i] == ' ') || ((a-i) < 0) || ((b-i) < 0)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a-i][b-i]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }

        //checks if the last letter entered starts a word that runs diagonally - up, right
        i = 0;
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }
        while (1) {
            if((grid[a+i][b-i] == ' ') || ((a+i) > 7) || ((b-i) < 0)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a+i][b-i]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }

        //checks if the last letter entered starts a word that runs diagonally - down, left
        i = 0;
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }
        while (1) {
            if((grid[a-i][b+i] == ' ') || ((a-i) < 0) || ((b+i) > 7)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a-i][b+i]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }

        //checks if the last letter entered starts a word that runs diagonally - down, right
        i = 0;
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }
        while (1) {
            if((grid[a+i][b+i] == ' ') || ((a+i) > 7) || ((b+i) > 7)) { //if the current spot on the grid is empty or the location is out of bounds...
                break;
            } else {
                word[i] = toupper(grid[a+i][b+i]); //stores all characters found in the word array
            }
            i++;
        }
        //calculates the score of the word found if it is an actual word
        if(isWord(word)) {
            addWord(word);
            score += calculateScore(word);
            wordFoundFlag = 1;
            wordCount++;
        }

        if(wordFoundFlag) {
            printf("\nWORDS FOUND:\n");
            for(int i = (nextIndex-1); i < (nextIndex-1) + wordCount; i++) {
                printf("** %s\n", wordsFound[i]);
            }

            char input[5];
            printf("\nEnter 'c' to continue... ");
            scanf("%s", input);
        }

        printf("\n\n");
        return score;
    }
    
    //This function repeatedly prompts the players to enter 
    //their moves and keeps track of their scores until either someone ends the game
    //or the board is full
    void getPlayerMove() {
        char letter[4]; //to store the players' moves
        char xy[2]; //to store coordinates
        
        printf("SCORES:\n ** Player one: %d points\n ** Player two: %d points\n\n", playersScores[0], playersScores[1]);
        printf("PLAYER ONE'S TURN:\n");
        printf("\nEnter the letter you would like to play (Enter 'Quit' to end game): ");
        scanf("%s", letter);

        while(1) { //loop infinitely
            char play = tolower(letter[0]);

            if(isalpha(play) == 0) { //if they character entered is not a letter
                printf("\n **** ERROR: Character entered is not a letter! ****\n\n");
                
                printf("\nEnter the letter you would like to play (Enter 'Quit' to end game): ");
                scanf("%s", letter);
                if((strcmp(letter, "Quit") == 0) || (strcmp(letter, "quit") == 0)) { //if the current play entered "Quit" or "quit"
                    return;
                } else {
                    continue;
                }
            }

            printf("\nEnter the x and y coordinates for the position to place the letter\n");
            printf("(in the form 'xy'): ");
            scanf("%s", xy);

            if((isdigit(xy[0]) == 0) || (isdigit(xy[1]) == 0)) { //if the coordinates input contains a non-digit character
                printf("\n **** ERROR: Invalid input! ****\n\n");
                printf("\nEnter the letter you would like to play (Enter 'Quit' to end game): ");
                scanf("%s", letter);
                if((strcmp(letter, "Quit") == 0) || (strcmp(letter, "quit") == 0)) {
                    return;
                } else {
                    continue;
                }
            }

            //converts the coordinates input to actual intergers
            int x = xy[0] - '0';
            int y = xy[1] - '0';
            
            if (isOnBoard(x, y)) {//if the coordinates entered are not out of bounds
                if(grid[x-1][y-1] == ' ') { //if the referenced location does not have a letter
                    makePlay(x, y, play);
                    playersScores[currentPlayer] += checkWords(x, y); //increments the current player's score based on the scores of the words found
                    drawBoard();

                    //displays scores
                    printf("SCORES:\n ** Player one: %d points\n ** Player two: %d points\n\n", playersScores[0], playersScores[1]);

                    //switches to current player based on the previous player
                    if(isBoardFull()) { //if the board is full
                        printf(" **** The board is now full! ****\n");
                        return;
                    } else if(currentPlayer == 0) {
                        currentPlayer = 1;
                        printf("PLAYER TWO'S TURN:\n");
                    } else {
                        currentPlayer = 0;
                        printf("PLAYER ONE'S TURN:\n");
                    }

                    printf("\nEnter the letter you would like to play (Enter 'Quit' to end game): ");
                    scanf("%s", letter);
                    if((strcmp(letter, "Quit") == 0) || (strcmp(letter, "quit") == 0)) { 
                        return;
                    }
                } else { //if the referenced location already has a letter
                    printf("\n **** ERROR: A letter is already at the given location! ****\n\n");
                    printf("\nEnter the letter you would like to play (Enter 'Quit' to end game): ");
                    scanf("%s", letter);
                    if((strcmp(letter, "Quit") == 0) || (strcmp(letter, "quit") == 0)) {
                        return;
                    } else {
                        continue;
                    }
                }
                
            } else { //if the coordinates entered are out of bounds
                printf("\n **** ERROR: Coordinates entered are not on board! ****\n\n");
                printf("\nEnter the letter you would like to play (Enter 'Quit' to end game): ");
                scanf("%s", letter);
                if((strcmp(letter, "Quit") == 0) || (strcmp(letter, "quit") == 0)) {
                    return;
                } else {
                    continue;
                }
            }

            
        }
    }

    //This function starts the game by randomly placing ten letters on the board
    void startBoard() {
        getNewBoard();
        
        char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        //the randomization is done here
        for(int i = 0; i < 10; i++) {
            int x = (rand()%8) + 1; //randomly chooses a number between 1 and 8
            int y = (rand()%8) + 1; //randomly chooses a number between 1 and 8

            int cIndex = rand()%26; //randomly chooses an index between 0 and 25
            char character = alphabet[cIndex];
            
            makePlay(x, y, character);
        }

        drawBoard();
    }

    printf("\n ************************************************\n\n");
    printf("                  MyScrabble\n\n");
    printf(" ************************************************\n\n");

    printf(" HOW TO PLAY:\n\n");
    printf("\tThe aim of the game is to spell words with \n\t4 or more letters. Each letter has");
    printf(" a value,\n\tso therefore, a player's score for a word\n\tis calculated by using these values.\n\n");

    startBoard(); //starts game
    time_t startTime = time(NULL);
    getPlayerMove(); //gets players' moves

    //when the game has ended
    printf("\n\n *** GAME ENDED! *** \n\n");
    time_t endTime = time(NULL);
    int timeDifference = difftime(endTime, startTime);

    if(timeDifference < 60) {
        printf("Play Time: %d seconds\n", timeDifference);
    } else {
        int minutes = timeDifference/60;
        int seconds = timeDifference%60;

        printf("Play Time: %d minutes and %d seconds\n", minutes, seconds);
    }
    

    printf("\nAll words found:\n");
    for(int i = 0; i < nextIndex; i++) {
        printf("    ** %s - ", wordsFound[i]);
        free(wordsFound[i]);

        if(player[i]) {
            printf("Player two\n");
        } else {
            printf("Player one\n");
        }
    }

    printf("\nWINNER: ");

    //displays winner(s) and their score(s)
    if(playersScores[0] > playersScores[1]) {
        printf("Player one with %d points!\n", playersScores[0]);
    } else if(playersScores[0] < playersScores[1]) {
        printf("Player two with %d points!\n", playersScores[1]);
    } else {
        printf("Players one and two (TIE) with %d points!\n", playersScores[0]);
    }

    return 0;
}

//This function calculates the score for the word passed to it
//based on the sum of the associated scores of its letters
int calculateScore(char * word) {
    int score = 0;

    for(int i = 0; i < strlen(word); i++) {
        score += getLetterScore(word[i]);
    }

    return score;
}

//This function checks the word passed to it against all the words
//in the words.txt file to see if it is an actual word
int isWord(char word[]) {

    char words[84000][8]; //declares string array to store words read from the file
    FILE *pRead; //declares file pointer

    pRead = fopen("words.txt", "r"); //opens file with the mode that allows its content to be read

    int x = 0; //counter
    if (pRead == NULL) //if file was not found
		printf("\n File not opened\n"); 
	else 

	{
        fscanf(pRead, "%s\n", words[x]); //reads word from file and stores it in array
		
        while(!feof(pRead)) //while not at the end of the file...
        {
            if((strcmp(words[x], word) == 0) && (strlen(words[x])) >= 4) { //if the word has at least 4 letters and is found in the file...
                fclose(pRead); //closes file
                return 1; //true
            }

            x++; //increments counter
            fscanf(pRead, "%s\n", words[x]); //reads next word from file and stores it in array
        }
        fclose(pRead); //closes file
    }
    return 0; //false
}

//This function checks to see if the coordinates passed
//to it are out of bounds
int isOnBoard(int x, int y) {
    int returnVal = 1; //true

    if(((x < 1) || (x > 8)) || ((y < 1) || (y > 8))) { //if location is out of bounds
        returnVal = 0; //false
    }

    return returnVal;
}

//This function returns the associated score of the letter passed to it based on the switch statement inside
int getLetterScore(char letter) {
    int score;
    switch (letter) {
        case 'A':
        case 'a':
            score = 1;
            break;

        case 'B':
        case 'b':
            score = 3;
            break;

        case 'C':
        case 'c':
            score = 3;
            break;

        case 'D':
        case 'd':
            score = 2;
            break;

        case 'E':
        case 'e':
            score = 1;
            break;

        case 'F':
        case 'f':
            score = 4;
            break;

        case 'G':
        case 'g':
            score = 2;
            break;

        case 'H':
        case 'h':
            score = 4;
            break;

        case 'I':
        case 'i':
            score = 1;
            break;

        case 'J':
        case 'j':
            score = 8;
            break;

        case 'K':
        case 'k':
            score = 5;
            break;

        case 'L':
        case 'l':
            score = 1;
            break;

        case 'M':
        case 'm':
            score = 3;
            break;

        case 'N':
        case 'n':
            score = 1;
            break;

        case 'O':
        case 'o':
            score = 1;
            break;

        case 'P':
        case 'p':
            score = 3;
            break;

        case 'Q':
        case 'q':
            score = 10;
            break;

        case 'R':
        case 'r':
            score = 1;
            break;

        case 'S':
        case 's':
            score = 1;
            break;

        case 'T':
        case 't':
            score = 1;
            break;

        case 'U':
        case 'u':
            score = 1;
            break;
        
        case 'V':
        case 'v':
            score = 4;
            break;

        case 'W':
        case 'w':
            score = 4;
            break;

        case 'X':
        case 'x':
            score = 8;
            break;

        case 'Y':
        case 'y':
            score = 4;
            break;

        case 'Z':
        case 'z':
            score = 10;
            break;

        default:
            printf("\nERROR: Character entered is not a letter.\n");
            score = 0;
            break;
    }

    return score;
}