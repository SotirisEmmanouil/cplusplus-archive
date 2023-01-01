/* Towers of Hanoi puzzle solver using vector data structure implementation. Works for both even and odd number of rings. Created while taking CSCI211 
"Object Oriented Programming in C++" with Dr.Jerry Waxman in the Fall 2021 semester. 
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
                vector<int> t[3];                           //initialize an empty vector 
                int n;
                cout << "Enter the number of rings: ";
                cin >> n;                                   //enter the number of rings 
                int from = 0;           
                int candidate = 1;
                int to, move = 0;
  
                if ( n % 2 == 0)                           //if rings are even, to tower is tower 2
                   to = 2;  
                else
                        to = 1;                           // else to tower is tower 1

            for ( int i =  n + 1 ; i >= 1; i-- )          //initialize the three towers 
              t[0].push_back(i);
            t[1].push_back(n+1);  
            t[2].push_back(n+1); 

                
                if ( n % 2  ==  0 )                     // if the rings are even
                {   
                        
                  while ( t[1].size() < (n+1) ) {                         //while there are still rings to move 
            
cout << "move:" << ++move << " Move candidate " << candidate;
                        cout << " from tower " << (char) (from + 'A');
                        cout << " to tower " << (char)(to + 'A') << endl;

                        t[to].push_back(t[from].back());                             // move the ring
                        t[from].pop_back();                                         // remove it completely from the "from" tower
                        if (t[(to+2)%3].back() < t[(to+1)%3].back())                // determine the "from" tower
                                from = (to + 2)%3;
                        else
                                from = (to + 1)%3;

                        if (t[(from)%3].back() < t[(from+2)%3].back())              //determine the "to" tower (modulo is needed to go around)
                                to = (from + 2)%3;
                        else
                                to = (from + 1)%3;
                        candidate = t[from].back();                                   // set candidate (ring to move)
}
                        return 0;
                        
                }   
                  else {                                                                 //if the total numbers of rings are odd 
                                
                  while ( t[1].size() < ( n+1 )   ) {
                        cout << "move:" << ++move << " Move candidate " << candidate;
                        cout << " from tower " << (char) (from + 'A');
                        cout << " to tower " << (char)(to + 'A') << endl;
                        t[to].push_back(t[from].back());
                        t[from].pop_back();
                        if (t[(to+1)%3].back() < t[(to+2)%3].back())
                                from = ( to + 1 )%3;

else
                                from = ( to + 2 )%3;
                        if (t[(from)%3].back()  <  t[(from+1)%3].back())
                                to = (from + 1)%3;
                        else
                                to = (from + 2)%3;
                        
                        candidate = t[from].back();
                        }
                        return 0;
                }

                   return 0;
        }
