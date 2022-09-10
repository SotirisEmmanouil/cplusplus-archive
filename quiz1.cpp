#include <iostream>
using namespace std;

void print( int grades[ ], int cap) {
for (int i = cap - 1; i >= 0; i--)
cout << grades[i] << " ";
}

double avg( int grades[ ] , int cap ) {
double total;
for (int i = 0; i <= cap - 1; i++)
total += grades[i];
return total / 4;
}

int main () {

string name;
int grades[4];

cout << " Enter the name of the student: ";
cin >> name;
cout << "Enter the grades for " << name << ": ";

for (int i = 0; i <= 3; i++){
cin >> grades[i];
}
cout << name << endl;
cout << name << "'s" " grade for each exam: ";
print(grades, 4);
cout << endl;
cout << "Average of the four grades: " << avg(grades, 4)<< endl;
return 0;
}
