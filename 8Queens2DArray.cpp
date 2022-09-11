/* A solution to the 8 of Queens problem using a 2D array to mimic a 2D chess Board and goto statements to implement backtracking, 
 and iteration through the rows and columns. This program was created while taking CS211 "Object Oriented Programming in C++" with 
 Dr.Jerry Waxman in the FALL 2021 semester.
 */

 #include <iostream>
 using namespace std;

 int main() {
   int b[8][8] = {}, r, c = 0;  //initilaize an empty chess board,row and columns counter

   b[0][0] = 1;                  //place the queen at position [0][0]

   NewColumn:
     c++;
     if (c == 8) goto print;   //once all the columns have been iterated,print
     r = -1;                   //sentinel value to not go beyond board limits

   NewRow:
     r++;
     if (r == 8) goto backtrack;
     for (int i = 0; i < c; i++) {                         // if a queen exists, move to the next row
       if (b[r][i] == 1) goto NewRow;
     }
     for (int i = 1; ((r-1)>0 && (c-i)>=0); i++) {        //up diagonal test
       if (b[r-i][c-i] == 1) goto NewRow;
     }
     for (int i = 1; ((r+i)<=7 && (c-i)>=0); i++) {      // down diagonal test
       if (b[r+i][c-i] == 1) goto NewRow;
     }
 b[r][c] = 1;
     goto NewColumn;

   backtrack:
     c--;
     if (c == -1) {
       cout << "No more solutions.\n";                             //once you go through the all the solutions, end the program
       return 0;
     }
     r = 0;
     while (b[r][c] != 1) {                                       //while there is no queen, iterate through the rows
       r++;
     }
  b[r][c] = 0;
     goto NewRow;   

   print:                                                         //print the solutions
     static int numberSolutions = 0;
     cout << "Solution #" << ++numberSolutions << ":\n";
     for (int i = 0; i < 8; i++) {
       for (int j = 0; j < 8; j++) {
         cout << b[i][j] << " ";
       }   
       cout << endl;
     }
     cout << endl;
        goto backtrack;
 }
