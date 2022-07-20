#include <iostream>
using namespace std;

int curve(int x, int w) {
if (x <= w) x + (100 - w);                 // function to curve grades
else return x;
return x + (100 - w);
}      

int main () {
int x, y, w, students, strikes; 
string name, lastname;

cout << "Welcome to the curve machine!\nWhat would you like to do?\nTo curve press 1 to quit press 2: ";
cin >> y;

if (y == 2) 

return 0;

cout << "Great, Enter the class size: ";
cin >> students;                                              // Sets limit for while loop 
cout << "Thanks! Please enter the highest score: ";
cin >> w;
cout << "The highest score in the class was " << w << "." << endl;

while (strikes < students) {                                          // while loop to input grades for students

cout << "Enter a score followed by the first and last name of the student: ";
cin >> x >> name >> lastname;
cout << name << " " << lastname << "'s score is now: " << curve(x, w) << endl; 
strikes++ ;

cout << "Thanks for using the curve machine! " << endl;

return 0; 

}
