/*
PSEUDOCODE
1. Create variables and appropriate the correct type. Have to set certain values to 0 or else they will get random numbers.
2. Display header documentation.
3. Ask the user if they need any books. If yes, then the while statement is initiated.
4. In the while function.
    a. Ask for user input.
    b. Calculate the profit and price of the order.
    c. Use an accumulator to update the total profit and price for each order.
    d. Use another cout statement asking if they need any books. If the user inputs 'N,' this acts as the sentinel and it will exit the while statement.
5. Display the total profit and price of all the orders combined.
*/
#include <iostream>
#include <iomanip> //set precision
#include <math.h> //round and ceil

using namespace std;
//Declare Prototypes.
void displayOutput(int, int, int, double, char, char, double, float, double);
void bookAccumulate(float, int, double, char, char, double&, double&, float&);
void userInput(int&, float&, int&, double&, char&, char&);

/*
********************************************************************************************************
*                                                                                                      *
*                                                                                                      *
*                                                                                                      *
********************************************************************************************************
*/

int main()
{
    //Declare are variables needed.
    float studentsTotal, booksNeeded;
    int bookCode, booksOnHand;
    double priceBook, totalPrice = 0, totalProfit = 0, storeProfit = 0, priceOrder = 0;
    char bookRequired, bookUsed, needBook;

    //Display Header Documentation
    cout << "Programmer: Christopher Stump" << endl;

    cout << "User ID: cstump1" << endl;

    cout << "Section: 001" << endl;

    cout << "Assignment: Program 3" << endl;

    cout << "Purpose: Test knowledge of functions and loops." << endl;

    cout << "Press enter to continue..." << endl;

    cin.ignore();


    //This is the part that will initiate the while statement. If the user needs books.
    cout << "Do you need any books? (Enter 'Y' or 'N'): ";
    cin >> needBook;
    cout << "\n\n";


    while (needBook == 'Y' || needBook == 'y')
    {
        userInput(bookCode, studentsTotal, booksOnHand, priceBook, bookRequired, bookUsed); //Call function for user input.

        bookAccumulate(studentsTotal, booksOnHand, priceBook, bookRequired, bookUsed, storeProfit, priceOrder, booksNeeded); //Call function to calculate price of each order and the profit.

        displayOutput(bookCode, studentsTotal, booksOnHand, priceBook, bookRequired, bookUsed, priceOrder, booksNeeded, storeProfit); //Call function to display input after each order.

        totalProfit += storeProfit; //Accumulates the profit.

        totalPrice += priceOrder; //Accumulates the price.

        cout << "Do you need any more books? (Enter 'Y' or 'N'): "; //This is the sentinel. Updates. If no books needed, then the "while" ends.
        cin >> needBook;
        cout << "\n\n";
    }

    //When the user does not need any more books, display the total price and profit.
    if (needBook == 'N' || needBook == 'n')
    {
        cout << "The total cost of all orders is: $" << fixed << setprecision(2) << totalPrice << endl;
        cout << "The expected profit is: $" << fixed<< setprecision(2) << totalProfit << endl;
    }
    //If the user does not enter 'Y' or 'N'
    else
        cout << "That is not a valid input. Please rerun the program.";
}

/*
********************************************************************************************************
*                                                                                                      *
*                                                                                                      *
*                                                                                                      *
********************************************************************************************************
*/
//This function gathers information from the user.
void userInput(int &bookCode, float &studentsTotal, int &booksOnHand, double &priceBook, char &bookRequired, char &bookUsed)
{
    cout << "Enter the code of your book: ";
    cin >> bookCode;

    cout << "Enter the single cost of the book: ";
    cin >> priceBook;

    cout << "Enter the number of books already on hand: ";
    cin >> booksOnHand;

    cout << "How many students are in the class: ";
    cin >> studentsTotal;

    cout << "Is the book required? (Enter 'Y' or 'N'): ";
    cin >> bookRequired;

    cout << "Has the book been used in a previous class? (Enter 'Y' or 'N'): ";
    cin >> bookUsed;

    cout << "\n\n";
}

/*
********************************************************************************************************
*                                                                                                      *
*                                                                                                      *
*                                                                                                      *
********************************************************************************************************
*/
//This function calculates the price of each order and the profit depending on if the book is required and or optional.
void bookAccumulate(float studentsTotal, int booksOnHand, double priceBook, char bookRequired, char bookUsed,
                    double &storeProfit, double &priceOrder, float &booksNeeded)
{
    float peopleWhoBuy = 0; //How many people will buy the book.

    //If the book is required, but has not been used before.
    if ((bookRequired == 'Y' || bookRequired == 'y') && (bookUsed == 'N' || bookUsed == 'n'))
    {
        peopleWhoBuy = studentsTotal * .90;
        round(peopleWhoBuy); //Rounds to the nearest integer because we can't have 1.5 people.
        booksNeeded = peopleWhoBuy - booksOnHand;
        priceOrder = ceil(booksNeeded) * priceBook; //Calculates price of the order. Ceil is used because if it calls for 4.6 books needed, it really means 5.
        storeProfit = priceOrder * .20; //Bookstore gains a profit of 20% on all orders.
    }

    //If the book is required and it has been used in a previous class.
    else if ((bookRequired == 'Y' || bookRequired == 'y') && (bookUsed == 'Y' || bookUsed == 'y'))
    {
        peopleWhoBuy = studentsTotal * .65;
        round(peopleWhoBuy);
        booksNeeded = peopleWhoBuy - booksOnHand;
        priceOrder = ceil(booksNeeded) * priceBook;
        storeProfit = priceOrder * .20;
    }

    //If the book is not required and it has not been used before.
    else if ((bookRequired == 'N' || bookRequired == 'n') && (bookUsed == 'N' || bookUsed == 'n'))
    {
        peopleWhoBuy = studentsTotal * .40;
        round(peopleWhoBuy);
        booksNeeded = peopleWhoBuy - booksOnHand;
        priceOrder = ceil(booksNeeded) * priceBook;
        storeProfit = priceOrder * .20;
    }

    //If the book is not required and it has been used before.
    else if ((bookRequired == 'N' || bookRequired == 'n') && (bookUsed == 'Y' || bookUsed == 'y'))
    {
        peopleWhoBuy = studentsTotal * .20;
        round(peopleWhoBuy);
        booksNeeded = peopleWhoBuy - booksOnHand;
        priceOrder = ceil(booksNeeded) * priceBook;
        storeProfit = priceOrder * .20;
    }
    else
    {
        cout << "You entered something wrong. Please rerun the program.\n\n"; //If the user entered in an invalid value in the above function.
    }
}

/*
********************************************************************************************************
*                                                                                                      *
*                                                                                                      *
*                                                                                                      *
********************************************************************************************************
*/

//This function is the best! It outputs all the information. HUZZAH!
void displayOutput(int bookCode, int studentsTotal, int booksOnHand, double priceBook, char bookRequired,
                   char bookUsed, double priceOrder, float booksNeeded, double storeProfit)
{
    cout << "Book Code: " << bookCode << endl;

    cout << "Single Book: $" << priceBook << endl;

    cout << "Books On Hand: " << booksOnHand << endl;

    cout << "Students In Class: " << studentsTotal << endl;

    cout << "Book Required? " << bookRequired << endl;

    cout << "Previous Book? " << bookUsed << endl;

    cout << "Books to be ordered: " << ceil(booksNeeded) << endl;

    cout << "Cost of this order: $" << fixed << setprecision(2) << priceOrder << endl;

    cout << "The profit for this order is: $" << fixed << setprecision(2) << storeProfit << "\n\n";
}
