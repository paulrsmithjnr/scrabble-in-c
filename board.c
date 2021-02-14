#include <stdio.h>
#include <string.h>

typedef struct dictionary {
    char key;
    int value;
} Dict;

Dict * createLetterScoreDict();
int getLetterScore(Dict * letterScores, char letter);

int main(){

int k,j;
int const NUM_RANGE=8;
//global declaration structure grid
char * grid[NUM_RANGE][NUM_RANGE];

char xy[2], play;

    void getNewBoard(){
        //creates a brand new blank board. Returns a pointer to the array 
        for (j = 0; j < NUM_RANGE; j++){
            for (k = 0; k < NUM_RANGE; k++)
            {
                grid[k][j]="   ";
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
            {  if(strcmp(grid[k][j],"   ")==0){
                    printf("| %s",grid[k][j]);
                }else{
                    printf("| %s  ",grid[k][j]);
                }
            }
            printf("%s","|");
            printf("\n");
            printf("%s\n",VLINE);
            printf("%s\n",HLINE);
        }
        return;
    }//EndFunction drawBoard

    
    void makePlay(int x, int y, char* c){
        //Arrays are zero indexed but our grid starts at index 1
        grid[x-1][y-1]=c;
        return;
    }

    
    void getPlayerMove() {
        printf("\nEnter the letter you would like to play: ");
        scanf("%c", &play);

        printf("\nEnter the x and y coordinates for the position to place the letter\n");
        printf("(in the form 'xy'): ");
        scanf("%s", xy);
    }

    void calculateScore(char * word) {

    }


    getNewBoard();
    drawBoard();
    //notice the use of spaces
    makePlay(3,7,"a");    
    makePlay(4,5,"b");    
    drawBoard();

    // /*Testing purposes*/
    // printf("\n\n");
    // Dict * letterScoresP = createLetterScoreDict();
    // printf("Q: %d\n", getLetterScore(letterScoresP, 'Q'));
    // printf("K: %d\n", getLetterScore(letterScoresP, 'K'));
    // printf("Z: %d\n", getLetterScore(letterScoresP, 'Z'));

    return 0;
}

/* 
This function returns a pointer to an array of the dictionary 
structure that stores the letter and its corresponding score 
*/
Dict * createLetterScoreDict() {
    static Dict letterScores[26];

    letterScores[0].key = 'A';
    letterScores[0].value = 1;

    letterScores[1].key = 'B';
    letterScores[1].value = 3;

    letterScores[2].key = 'C';
    letterScores[2].value = 3;

    letterScores[3].key = 'D';
    letterScores[3].value = 2;

    letterScores[4].key = 'E';
    letterScores[4].value = 1;

    letterScores[5].key = 'F';
    letterScores[5].value = 4;

    letterScores[6].key = 'G';
    letterScores[6].value = 2;

    letterScores[7].key = 'H';
    letterScores[7].value = 4;

    letterScores[8].key = 'I';
    letterScores[8].value = 1;

    letterScores[9].key = 'J';
    letterScores[9].value = 8;

    letterScores[10].key = 'K';
    letterScores[10].value = 5;

    letterScores[11].key = 'L';
    letterScores[11].value = 1;

    letterScores[12].key = 'M';
    letterScores[12].value = 3;

    letterScores[13].key = 'N';
    letterScores[13].value = 1;

    letterScores[14].key = 'O';
    letterScores[14].value = 1;

    letterScores[15].key = 'P';
    letterScores[15].value = 3;

    letterScores[16].key = 'Q';
    letterScores[16].value = 10;

    letterScores[17].key = 'R';
    letterScores[17].value = 1;

    letterScores[18].key = 'S';
    letterScores[18].value = 1;

    letterScores[19].key = 'T';
    letterScores[19].value = 1;

    letterScores[20].key = 'U';
    letterScores[20].value = 1;

    letterScores[21].key = 'V';
    letterScores[21].value = 4;

    letterScores[22].key = 'W';
    letterScores[22].value = 4;

    letterScores[23].key = 'X';
    letterScores[23].value = 8;

    letterScores[24].key = 'Y';
    letterScores[24].value = 4;

    letterScores[25].key = 'Z';
    letterScores[25].value = 10;

    return letterScores;
    //This doesn't return the array itself but instead returns a pointer to
    //the first element in the array, hence the return type of the function.
}

 /*
This function takes as paramters a pointer to an array of the dictionary 
structure that stores letters and their corresponding scores, and the letter
being queried.
 */
int getLetterScore(Dict * letterScoresP, char letter) {
    Dict letterScore; //creates an instance of the dictionary structure
    int size = 26;
    for(int i = 0; i < size; i++) {

        letterScore = * (letterScoresP + i); 
        //assigns the key, value pair of the array element stored and address being pointed to
        //in the letterScore variable
        //NB: This works since the elements of the letterScores array are stored in contigious blocks
        //    in memory. So, incrementing the address stored in the pointer by the value stored in i
        //    results in the overall sum pointing to the next element of the dictionary structure array.

        if(letterScore.key == letter) {
            return letterScore.value;
        }
    }
}