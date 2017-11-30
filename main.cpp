/** Luke Deegan,
 *  Exercise 7,
 *  Coordinate Conversion Calculator,
 *  21/10/17
 */



#include <iostream>
#include <cmath>
#include <cstdio>
#include <windows.h>
using namespace std;

/** Declare all functions to be used within the program */
int main(void);
char displayMenu(void);
void cartPol(void);
void polCart(void);
void calcartPol(double real, double imag, double *magPtr, double *anglePtr);
void calpolCart(double angle, double mag, double *realPtr, double *imagPtr);


/** Main Function */
int main(void)

{

    char choice;

    do
    {

        choice = displayMenu();
        switch (choice)


{

    case 'c': polCart();
    break;

    case 'p': cartPol();
    break;

    case 'q': system("cls");
    cout << "Goodbye\n";
    break;

    default: cout << "\nInvalid input, press any key to continue...";
    fflush(stdin);
    getchar();
    break;
}}

    while (choice != 'q');


    return 0;

}



/** Display menu function, gives user instructions as to which
    keys should be pressed for which function */
    char displayMenu(void)
{

/** Declare local variables fo this function */
    char choice;

    system("cls");

    cout << "Coordinate Conversion";

    cout << "\n\nPress 'c' to convert from Polar to Cartesian ...";

    cout << "\nPress 'p' to convert from Cartesian to Polar ...";

    cout << "\nPress 'q' to quit ...\n\nChoice: ";

    fflush(stdin);

    choice = getchar();

    return choice;
}

/** Initial Cartesian to Polar conversion function */
void cartPol(void)
{

/** Declare all local variables to be used in the function */
    double real, imag, mag, angle;

/** Declare and initialse all pointers to be used in the function */
    double *magPtr = &mag, *anglePtr = &angle;
    system("cls");

    cout << "Cartesian to Polar Conversion\n\n";

    cout << "Enter real part:\t";
    cin >> real;

    cout << "Enter imaginary part:\t";
    cin >> imag;

/** Call the calculation subfunction */
    calcartPol(real, imag, magPtr, anglePtr);

/** Display the results to the user using the pointers returned from the sub fucntion */
    cout << "\nMagnitude: " << *magPtr;

    cout << "\nAngle:\t\t\t" << *anglePtr;

    cout << "\n\nPress any key to return to the main menu...";

    fflush(stdin); getchar();

    return;
}

/** Sub function used for the calculation of Cartesian to Polar,
    returning values through pointers */
void calcartPol(double real, double imag, double *magPtr, double *anglePtr)
{
    *magPtr = sqrt(pow(real, 2) + pow(imag, 2));

    *anglePtr = atan2(imag, real);

    return;
}

/** Initial polar to Cartesian function */
void polCart(void)

{

/** Declare all local variables to be used within the function */
    double real, imag, mag, angle;

/** Declare and initialise pointers to be used in the function */
    double *imagPtr = &imag, *realPtr = &real;
    system("cls");

    cout << "Polar to Cartesian Conversion\n\n";

    cout << "Enter magnitude:\t";
    cin >> mag;

    cout << "Enter angle (%c):\t";
    cin >> angle;

/** Call the calculation sub function */
    calpolCart(angle, mag, realPtr, imagPtr);

/** Display result to the user */
    cout << "\nReal part:\t\t" << *realPtr;

    cout << "\nImaginary part:\t\t" << *imagPtr;

    cout << "\n\nPress any key to return to the main menu...";

    fflush(stdin);
    getchar();

    return;
}

/** Sub function used for the calculation of Polar to Cartesian,
    returning values through pointers */
void calpolCart(double angle, double mag, double *realPtr, double *imagPtr)
{
    *realPtr = mag * cos(M_PI * angle /180);

    *imagPtr = mag * sin(M_PI * angle /180);

    return;
}
