#include <iostream>
#include <stdexcept>			// Header file for handling run time exceptions
#include <cmath>				// For performing floor operation (modulo operation)
using namespace std;

template <typename T>			// Template's used inorder to handle different datatypes inputted from User

T add(T a, T b) 
{
    return a + b;
}

template <typename T>

T subtract(T a, T b)
{
    return a - b;
}

template <typename T>

T multiply(T a, T b)
{
    return a * b;
}

template <typename T>

T divide(T a, T b) 
{
    if (b == 0) 				// To Ensure the denominator is non-zero(always)
	{
        throw invalid_argument("Division by zero is not allowed !");
    }
    
    return a / b;
}

template <typename T>			// To Ensure the denominator is non-zero(always)

T remainder (T a, T b)
{
	if (b == 0)
	{
		throw invalid_argument("Division by zero is not allowed !");
	}
	
	return a - b * floor(a/b);
}

int main() 
{
	cout << " \t\t\t\t\t ##### CODSOFT INTERNSHIP ##### \n" ;
	
	cout << " \n +-*/ || SIMPLE CALCULATOR || +-*/  \n";
	cout << " It performs basic Arithmetic Operations  \n";
	
    char op;
    double num1, num2;
    double Result;
  
  while(1)  
  {
    cout << "\n Enter two operands: \n ";
    cin >> num1;
	cin >> num2;

    cout << "\n Enter any operator: ";
    cin >> op;
	
    switch (op) 
	{
        case '+':
              cout << "\n Sum => \t" << add(num1,num2);
              break;
            
        case '-':
              cout << "\n Difference => \t" <<  subtract(num1,num2);
              break;
            
        case '*':
              cout << "\n Product => \t" <<  multiply(num1,num2);       
			  break;
            
        case '/':
              try 
			  {
                cout << "\n Quotient => \t" << divide(num1,num2); 
              } 
            
			  catch (const invalid_argument& e) 
			  {
                 cerr << e.what() << endl;			// Explains the exception
              }
              break;
        
		case '%':
			  try
			  {
			    cout << "\n Remainder => \t" << remainder(num1,num2);
			  }
			  
			  catch (const invalid_argument& e) 
			  {
                 cerr << e.what() << endl;		   // Explains the exception
              }
              break;
        
		default:
              cout << "Invalid Operand !! Please enter again properly ! "<< endl;
            break;
   }
 }
    return 0;
}
