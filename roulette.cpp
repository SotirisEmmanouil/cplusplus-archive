/* Created by Sotiris Emmanouil on 8/3/22. This C++ program simulates a roulette that one would find in a typical casino. It utlizies the "cstdlib" and 
"ctime" libraries to mimic the randomness that would occur when spinning a physical roulette.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rouletteSpin() {
    srand(time(NULL));
    int randomInt = rand() % 37;          // function that simulates the roulette wheel by genrating a random number from 0 to 36
    return randomInt;
}

int main(){
int decider,bet,number,bet1,balance;

cout << "Welcome to Roulette!\nEnter your balance. The list of different bet types include:\nOnly red, Enter 2\nOnly black,3\nOnly even,5\nOnly odd,4\nNumbers 1-18,6\nNumbers 19-36,7\n1st Twelve,8\n2nd Twelve,9\n3rd Twelve,10\nSingle number,1\nHere is a reference to what each number corresponds to on the roulette:\n0=0G\n1=1R\n2=2B\n3=3R\n4=4B\n5=5R\n6=6B\n7=7R\n8=8B\n9=9R\n10=10B\n11=11B\n12=12R\n13=13B\n14=14R\n15=15B\n16=16R\n17=17B\n18=18R\n19=19R\n20=20B\n21=21R\n22=22B\n23=23R\n24=24B\n25=25R\n26=26B\n27=27R\n28=28B\n29=29B\n30=30R\n31=31B\n32=32R\n33=33B\n34=34R\n35=35B\n36=36R\n";
cin >> balance;

roulette:
cout << "Enter the type of bet you want to do and the bet amount: "<< endl;
  cin >> decider >> bet1;
    if(bet1 > balance) {

cout<< "Sorry bet exceeds balance! Enter new bet" << endl;
      goto roulette;

     }

balance -= bet1;

switch (decider) {                                // swtich to branch to the type of bet selected by the player

case 1:
cout<<"Enter the number you want to bet on: "<< endl;
cin >> number;
if (rouletteSpin() == number)
      goto Win35to1;
          goto Lose;
 
case 2:
if((rouletteSpin() % 2 != 0 && rouletteSpin() <= 9) || (rouletteSpin() % 2 == 0 && (12 <= roulletteSpin() && rouletteSpin() <= 18)) || (rouletteSpin() % 2 != 0 && (19 <=rouletteSpin()&& rouletteSpin() <= 27)) || (rouletteSpin() % 2 == 0 && (30 <= rouletteSpin() && rouletteSpin() <= 36)))
      goto Win1to1;
          goto Lose;

case 3:
if(!((rouletteSpin() % 2 != 0 && rouletteSpin() <= 9) || (rouletteSpin() % 2 == 0 && (12 <= roulletteSpin() && rouletteSpin() <= 18)) || (rouletteSpin() % 2 != 0 && (19 <=rouletteSpin()&& rouletteSpin() <= 27)) || (rouletteSpin() % 2 == 0 && (30 <= rouletteSpin() && rouletteSpin() <= 36))))
      goto Win1to1;
         goto Lose;
case 4:

if(rouletteSpin() % 2 != 0)
   goto Win1to1;
      goto Lose;
 
case 5:
    if(rouletteSpin() % 2 == 0)
      goto Win1to1;
         goto Lose;   

case 6:
     if(1 <= rouletteSpin() && rouletteSpin() <= 18)
      goto Win1to1;
         goto Lose;
case 7:

if(19 <=rouletteSpin() && rouletteSpin() <= 36)
        goto Win1to1;
           goto Lose;

case 8:

if(1 <= rouletteSpin() && rouletteSpin() <= 12)
      goto Win2to1;
         goto Lose;
      
case 9:

if(13 <= rouletteSpin() && rouletteSpin() <= 24)
    goto Win2to1;
       goto Lose; 
    
case 10:

if(25 <= rouletteSpin() && rouletteSpin() <= 36)
     goto Win2to1;
        goto Lose;   

}     

Win1to1:
        bet = bet1 * 2;                           // labels that calculate earnings
        goto Prompt;

Win2to1:
        bet = bet1 * 3;
        goto Prompt;

Win35to1:
        bet = bet1 * 36;
        goto Prompt;
      
Prompt:
         balance += bet;
  cout<< "Congratulations, you won $" << bet - bet1 <<" and your balance is "<< balance <<"\nTo select bet type, enter 2. To quit enter anything else"<< endl;
  cin >> decider;

if (decider == 2)
        goto roulette;
else
        return 0;
        
Lose:
if (balance<=0) {
    cout<<"Insufficient funds! Game over!"<<endl;
     return 0;

    } 
cout<< "You lost $" << bet1 <<"! and your balance is "<<balance<<"\n"<< "Would you like to play again or quit?\nTo select bet type, enter 2,or to quit press any other key"<< endl;
cin >> decider;

    if (decider == 2)
        goto roulette;
    else
      cout << "Your balance of " << balance << "has been withdrawn!"<<endl;
              return 0;

}

   
    
    
    
