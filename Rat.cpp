/* A class for Rational Numbers. This class has constructors which create rational numbers in the form of fractions, arithmetic operators
to perform different arithemtic operations on the RATS, and a simplification function to simplify the RATS. This program was built 
while taking CS211 "Object Oriented Programming in C++" with Dr. Jerry Waxman. 
*/

#include <iostream>
using namespace std;

class Rat{

private:

int n;                               // private variables 
int d;   

public:

Rat(){                              //no paremeter RAT constructor which automatically constructs a RAT with 0 as numerator and 1 as the denominator 
n=0;  
d=1;  
}

Rat(int i, int j){                  // two parameter RAT constructor to set numerator and denominator of the RAT
n = i;   
d = j;
   }   

Rat(int i){                         //one parameter RAT constructor so that denominator is 1
n = i;
d = 1;
}

int getN(){                         //get function for numerator 
return n;
}

int getD(){                         //get function for denominator
return d;  
}

void setN(int i){                   //set function for numerator 
n = i;
}
  
void setD(int i){                   //set function for denominator
d = i;
}
  
Rat operator+(Rat r){               //addition operator for RATS
Rat t;
t.n = n*r.d+d*r.n;
t.d = d*r.d;
simplify(t);
return t;
}
  
Rat operator-(Rat r){               //substraction operator for RATS
Rat t;
t.n = n *r.d - d*r.n;
t.d = d*r.d;
simplify(t);
return t;   
}
  
Rat operator/(Rat r){               //division operator for RATS
Rat t;
t.n = n*r.d;
t.d = d*r.n;
simplify(t);
return t;   
}
  
Rat operator*(Rat r){                                   //multiplication operator for RATS
Rat t;
t.n= n*r.n;
t.d= d*r.d;
simplify(t);
return t;   
}

friend ostream& operator<<(ostream& os, Rat r){      //overloaded friend operator to output RATS
os<< r.n<< "/"<< r.d<< endl;
return os;
}
  
friend istream& operator>>(istream& is, Rat& r){     //overloaded friend operator to enter RATS
is>> r.n >> r.d;
return is;  
}
  
int gcd(int a, int b) {                             //function to get GCD so that the fractions can be simplified
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

void simplify(Rat& r){                              //function to simplify the fractions
int f = r.gcd(r.getN(),r.getD());
r.n = r.n / f;
r.d = r.d / f;
}
   
};

int main(){             //test to see if constructors and functions are working properly
int a,b,c,d,g;
cout<<"Enter the numerator and denominator for RAT1 followed by numerator and denominator for RAT2: ";
cin>> a >> b >> c >> d;
Rat rat1(a,b), rat2(c,d),q,z,w,r,e;
q = rat1+rat2;
z = rat1/rat2;
w = rat1-rat2;
r = rat1*rat2;
cout<<"rat1 + rat2 =" << q<< endl;
cout<<"rat1 / rat2 =" << z<< endl;
cout<<"rat1 - rat2 =" << w<< endl;
cout<<"rat1 * rat2 =" << r<< endl;
cout<<"The denominator of rat1 * rat2 is "<< r.getD()<< endl;
cout<<"The numerator for rat1 is now 7\n";
rat1.setN(7); 
e = rat1+rat2;
cout<< "rat1 + rat2 now is " << e << endl;
return 0;
}
