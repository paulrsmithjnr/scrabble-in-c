#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// typedef struct dictionary {
//     char key;
//     int value;
// } Dict;

// Dict * createLetterScoreDict();
// int getLetterScore(Dict * letterScores, char letter);
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

    // Dict * letterScoresP = createLetterScoreDict();

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

    void checkWord(int x, int y) {
        int a = x - 1;
        int b = y - 1;
        // grid[a][b];

        char word[8];
        // strcpy(word, "");
        for (int i = 0; i < 8; i++) {
            word[i] = '\0';
        }

        //left
        int i = 0;
        while (1) {
            if((grid[a-i][b] == ' ') || ((a-i) < 0)) {
                break;
            } else {
                word[i] = toupper(grid[a-i][b]);
            }
            i++;
        }
        printf("checkWord: %s\n", word);
        printf("isWord: %d\n", isWord(word));
        
        // for(int i = 0; ; i++) {
        //     // word = grid[a][b-i];
            
        // }
    }
    
    void getPlayerMove() {
        char letter[4];
        char xy[2];
        printf("\nEnter the letter you would like to play: ");
        scanf("%s", letter);
        while(strcmp(letter, "Quit") != 0) {
            // char* play = getLetter(letter[0]);
            char play = letter[0];

            printf("\nEnter the x and y coordinates for the position to place the letter\n");
            printf("(in the form 'xy'): ");
            scanf("%s", xy);

            int x = xy[0] - '0';
            int y = xy[1] - '0';
            makePlay(x, y, play);
            checkWord(x, y);
            drawBoard();

            printf("\nEnter the letter you would like to play: ");
            scanf("%s", letter);
        }
    }

    void startBoard() {
        getNewBoard();
        
        // char *alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
        char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        for(int i = 0; i < 10; i++) {
            int x = (rand()%8) + 1;
            int y = (rand()%8) + 1;

            int cIndex = rand()%26;
            char character = alphabet[cIndex];
            
            makePlay(x, y, character);
        }
        drawBoard();
    }

    startBoard();
    getPlayerMove();


    // while(1) {
        

    //     // printf("\nLetter entered: %s\n", play);
    //     // printf("strlen(play) = %ld\n", strlen(play));
    //     printf("Letter: %c\n", play);
    //     printf("Address: %s\n", &play);

        
    //     printf("Outside function - Grid letter: %s\n", grid[7][7]);

    //     drawBoard();
    //     play = getPlayerMove();
    // }
    // drawBoard();
    // printf("%s\n", getPlayerMove());
    // while(strcmp(xy, "0") != 0) {
    //     char *play = getPlayerMove();
    //     int x = xy[0] - '0';
    //     int y = xy[1] - '0';
    //     printf("(%d, %d)\n", x, y);
    //     makePlay(x, y, play);
    //     printf("Play: %s\n", play);
    //     drawBoard();
    // }
    
    
    // getNewBoard();
    // drawBoard();
    //notice the use of spaces
    // makePlay(3,7,"a");    
    // makePlay(4,5,"b");    
    // drawBoard();

    // /*Testing purposes*/
    // printf("\n\n");
    // getPlayerMove();
    // int x = xy[0] - '0';
    // int y = xy[1] - '0';
    // printf("%d\n", isOnBoard(x, y));
    // Dict * letterScoresP = createLetterScoreDict();
    // printf("Q: %d\n", getLetterScore(letterScoresP, 'Q'));
    // printf("K: %d\n", getLetterScore(letterScoresP, 'K'));
    // printf("Z: %d\n", getLetterScore(letterScoresP, 'Z'));

    // printf("%d\n", calculateScore("cat"));
    // printf("%d\n", calculateScore("thing"));
    // printf("%d\n", calculateScore("it"));

    return 0;
}

int calculateScore(char * word) {
    int score = 0;
    // Dict * letterScoresP = createLetterScoreDict();
    // printf("\nLength of word: %d\n", (int) strlen(word));
    // for(int i = 0; i < strlen(word); i++) {
    //     char letter = *(word + i);
    //     printf("%c %d\n", letter, getLetterScore(letterScoresP, letter));
    //     score += getLetterScore(letterScoresP, letter);
    // }

    for(int i = 0; i < strlen(word); i++) {
        score += getLetterScore(word[i]);
    }

    return score;
}

int isWord(char word[]) {
    char words[84000][25];
    FILE *pRead;
    pRead = fopen("words.txt", "r");
    int x = 0;
    if (pRead == NULL) 
		printf("\n File not opened\n"); 
	else 

	{
        fscanf(pRead, "%s\n", words[x]);
		
        while(!feof(pRead))
        {
            x++;
            fscanf(pRead, "%s\n", words[x]);
            if(strcmp(words[x], word) == 0) {
                fclose(pRead);
                return 1;
            }

        }
        fclose(pRead);
    }
    return 0;
}

int isOnBoard(int x, int y) {
    int returnVal = 1;

    if(((x < 1) || (x > 8)) || ((y < 1) || (y > 8))) {
        returnVal = 0;
    }

    return returnVal;
}

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
            printf("ERROR: Character entered is not a letter.");
            score = 0;
            break;
    }

    return score;
}

char* getLetter(char letter) {
    // char *character;
    switch (letter) {
        case 'A':
        case 'a':
            return "a";

        case 'B':
        case 'b':
            return "b";

        case 'C':
        case 'c':
            return "c";

        case 'D':
        case 'd':
            return "d";

        case 'E':
        case 'e':
            return "e";

        case 'F':
        case 'f':
            return "f";

        case 'G':
        case 'g':
            return "g";

        case 'H':
        case 'h':
            return "h";

        case 'I':
        case 'i':
            return "i";

        case 'J':
        case 'j':
            return "j";

        case 'K':
        case 'k':
            return "k";

        case 'L':
        case 'l':
            return "l";

        case 'M':
        case 'm':
            return "m";

        case 'N':
        case 'n':
            return "n";

        case 'O':
        case 'o':
            return "o";

        case 'P':
        case 'p':
            return "p";

        case 'Q':
        case 'q':
            return "q";

        case 'R':
        case 'r':
            return "r";

        case 'S':
        case 's':
            return "s";

        case 'T':
        case 't':
            return "t";

        case 'U':
        case 'u':
            return "u";
        
        case 'V':
        case 'v':
            return "v";

        case 'W':
        case 'w':
            return "w";

        case 'X':
        case 'x':
            return "x";

        case 'Y':
        case 'y':
            return "y";

        case 'Z':
        case 'z':
            return "z";

        default:
            printf("ERROR: Character entered is not a letter.");
            break;
    }
}


/* 
This function returns a pointer to an array of the dictionary 
structure that stores the letter and its corresponding score 
*/
// Dict * createLetterScoreDict() {
//     static Dict letterScores[26];

//     letterScores[0].key = 'A';
//     letterScores[0].value = 1;

//     letterScores[1].key = 'B';
//     letterScores[1].value = 3;

//     letterScores[2].key = 'C';
//     letterScores[2].value = 3;

//     letterScores[3].key = 'D';
//     letterScores[3].value = 2;

//     letterScores[4].key = 'E';
//     letterScores[4].value = 1;

//     letterScores[5].key = 'F';
//     letterScores[5].value = 4;

//     letterScores[6].key = 'G';
//     letterScores[6].value = 2;

//     letterScores[7].key = 'H';
//     letterScores[7].value = 4;

//     letterScores[8].key = 'I';
//     letterScores[8].value = 1;

//     letterScores[9].key = 'J';
//     letterScores[9].value = 8;

//     letterScores[10].key = 'K';
//     letterScores[10].value = 5;

//     letterScores[11].key = 'L';
//     letterScores[11].value = 1;

//     letterScores[12].key = 'M';
//     letterScores[12].value = 3;

//     letterScores[13].key = 'N';
//     letterScores[13].value = 1;

//     letterScores[14].key = 'O';
//     letterScores[14].value = 1;

//     letterScores[15].key = 'P';
//     letterScores[15].value = 3;

//     letterScores[16].key = 'Q';
//     letterScores[16].value = 10;

//     letterScores[17].key = 'R';
//     letterScores[17].value = 1;

//     letterScores[18].key = 'S';
//     letterScores[18].value = 1;

//     letterScores[19].key = 'T';
//     letterScores[19].value = 1;

//     letterScores[20].key = 'U';
//     letterScores[20].value = 1;

//     letterScores[21].key = 'V';
//     letterScores[21].value = 4;

//     letterScores[22].key = 'W';
//     letterScores[22].value = 4;

//     letterScores[23].key = 'X';
//     letterScores[23].value = 8;

//     letterScores[24].key = 'Y';
//     letterScores[24].value = 4;

//     letterScores[25].key = 'Z';
//     letterScores[25].value = 10;

//     return letterScores;
//     //This doesn't return the array itself but instead returns a pointer to
//     //the first element in the array, hence the return type of the function.
// }

 /*
This function takes as paramters a pointer to an array of the dictionary 
structure that stores letters and their corresponding scores, and the letter
being queried.
 */
// int getLetterScore(Dict * letterScoresP, char letter) {
//     Dict letterScore; //creates an instance of the dictionary structure
//     // int size = 5;
//     const int SIZE = 26;
//     for(int i = 0; i < SIZE; i++) {

//         letterScore = * (letterScoresP + i); 
//         //assigns the key, value pair of the array element stored and address being pointed to
//         //in the letterScore variable
//         //NB: This works since the elements of the letterScores array are stored in contigious blocks
//         //    in memory. So, incrementing the address stored in the pointer by the value stored in i
//         //    results in the overall sum pointing to the next element of the dictionary structure array.

//         if(letterScore.key == letter) {
//             return letterScore.value;
//         }
//     }
// }