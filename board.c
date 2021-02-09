#include <stdio.h>
#include <string.h>

int main(){

int k,j;
int const NUM_RANGE=8;
//global declaration structure grid
char * grid[NUM_RANGE][NUM_RANGE];

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



    getNewBoard();
    drawBoard();
    //notice the use of spaces
    makePlay(3,7,"a");    
    makePlay(4,5,"b");    
    drawBoard();

    return 0;
}
