#include <iostream>
#include <cstring> //Most of the commands used on arrays.
#include <cstdlib>
#include <time.h> //Random Numbers

using namespace std;
//************************************************************************
// Declare Prototypes.                                                   *
//                                                                       *
//                                                                       *
//                                                                       *
//************************************************************************
void getUserInput(string&, string&, int&);
void displayData(string, string, int, int[]);
void locateString(string, string, int, int, int[]);
void patternMatching();
void bubbleSort();
void selectionSort();
int sortBubble(int[]);
int sortSelection(int[]);
int arrayCount(int[], int);
//************************************************************************
//                                                                       *
//                                                                       *
//                                                                       *
//                                                                       *
//************************************************************************

int main()
{
    //Display Header Documentation
    cout << "Programmer: Christopher Stump" << endl;

    cout << "User ID: cstump1" << endl;

    cout << "Section: 001" << endl;

    cout << "Assignment: Program 5 Optional" << endl;

    cout << "Purpose: Test knowledge of arrays and sorting." << endl;

    cout << "Press enter to continue..." << endl;

    cin.ignore();

    //Allow the user to choose which program to use or exit out of the entire program.
    char selection, otherSelection;
    FirstMenu:
    cout << "Choose from the menu below: " << endl;
    cout << "A. Pattern Matching" << endl;
    cout << "B. Sorting Techniques" << endl;
    cout << "C. Exit Entire Program" << endl;
    cout << "Choice: ";
    cin >> selection;
    cin.ignore();
    cout << "****************************************************" << endl;
    //Allows the program to ignore end line characters.

    //The switch statement executes one or the other program.
    switch(selection)
    {
        case 'a':
        case 'A':
            patternMatching(); //Initiate assignment part A
            break;
        case 'b':
        case 'B':
            {
                SecondMenu:
                cout << "Choose from the menu below: " << endl; //Allow a second menu for the different sorting options.
                cout << "A. Bubble Sort" << endl;
                cout << "B. Selection Sort" << endl;
                cout << "C. Exit To Menu" << endl;
                cout << "Choice: ";
                cin >> otherSelection;
                cin.ignore();
                cout << "****************************************************" << endl;

                switch(otherSelection) //Entirely different switch statement.
                {
                    case 'a':
                    case 'A':
                        bubbleSort();
                        break;
                    case 'b':
                    case 'B':
                        selectionSort();
                        break;
                    case 'c':
                    case 'C':
                        goto FirstMenu; //Use goto statements to revert back to the first menu if they want to.
                    default:
                        cout << "That is not a valid menu choice." << endl;
                        cout << "****************************************************" << endl;
                        goto SecondMenu; //Return to the second menu if they don't enter a valid value.
                }
            }
            break;
        case 'c':
        case 'C':
            return 0; //Exit out of the function.
            break;
        default:
            cout << "That is not a valid menu choice."; //If the user did not enter in A or B
            goto FirstMenu;
    }
    return 0;
}

//************************************************************************
// This is the start to all the functions for the pattern matching part. *
//                                                                       *
//                                                                       *
//                                                                       *
//************************************************************************

void patternMatching()
{
    string userText, searchText;
    char patternMenu;
    int const x = 100; //C++ needs a numeric value for the array.
    int stringSize, numOccurrences, i = 0, posArray[x] = {};

    PatternMatching:
    getUserInput(userText, searchText, stringSize); //Calls function to gather user input.

    locateString(userText, searchText, i, stringSize, posArray); //Calls function to find where the searches occur.

    numOccurrences = arrayCount(posArray, x); //Counts how many times the search occurs.

    displayData(userText, searchText, numOccurrences, posArray); //Displays the user data.

    //Initiate a menu that asks the user whether or not the want to search again. If no, go back to main.
    PatternMenu:
    cout << "Would you like to search again?" << endl;
    cout << "A. Yes" << endl;
    cout << "B. No" << endl;
    cout << "Choice: ";
    cin >> patternMenu;
    cin.ignore();
    cout << "****************************************************" << endl;

    switch(patternMenu)
    {
        case 'a':
        case 'A':
            goto PatternMatching;
            break;
        case 'b':
        case 'B':
            main();
            break;
        default:
            cout << "That is not a valid choice." << endl;
            cout << "****************************************************" << endl;
            goto PatternMenu;
    }

}


void getUserInput(string &userText, string &searchText, int &stringSize)
{
    cout << "Enter text: "; //Get the user text.
    getline(cin, userText);

    cout << "Search for text: "; //What they want to search for.
    getline(cin, searchText);

    stringSize = userText.size(); //Get the size of the text the user enters and store it as an integer value.

    cout << endl;
}


void displayData(string userText, string searchText, int numOccurrences, int posArray[])
{
    cout << "****************************************************" << endl;

    cout << "Entered Text: \"" << userText << "\"" << endl; //Display what the user entered at first.

    cout << "String to search : \"" << searchText << "\"" << endl; //Display what they wanted to search for originally.

    cout << "Number of Occurrences: " << numOccurrences << endl; //Display how many times their search occurred.

    cout << "Position Found: "; //Display the position at which these searches were found.
    for(int index = 0; index < numOccurrences ; index++)
    {
        if(index != numOccurrences - 1)
        {
            cout << posArray[index] << ", ";
        }
        else //This allows the "," not to be shown at the last integer.
        {
            cout << posArray[index] << endl;
        }

    }

    cout << "****************************************************" << endl;
}


void locateString(string userText, string searchText, int i, int stringSize, int posArray[])
{
    int position = 0;
    int posFound = 0;
    int lastFind = 0;

    lastFind = userText.rfind(searchText, userText.size()); //Calculates the last position in which the search is found.

    while(position <= lastFind) //Once the search reaches the last place found, it will end.
    {
        posFound = userText.find(searchText, position); //The integer position is updated each time, so it does not find the same thing over again.

        if(posFound < stringSize)
        {
            posArray[i] = posFound +1;
            i++;
            position = (searchText.size()) + posFound; //Updates position.

        }
    }
}


int arrayCount(int posArray[], int x)
{
    int counter = 0; //This function calculates how many times a search is found.
    for(int y = 0; y < x; y++)
    {
        if(posArray[y] != 0) //If there are no more findings, the rest of the array is initialized to 0, so if that is so, there is not more occurrences.
        {
            counter++;
        }
    }
    return counter;
}

//************************************************************************
// This is the beginning to the bubble sorting functions.                *
//                                                                       *
//                                                                       *
//                                                                       *
//************************************************************************

void bubbleSort()
{
    int randomArray[10]; //The array size is 10.
    char bubbleChoice;

    BubbleSort:
    cout << "This program will generate 10 random numbers from 1-100." << endl;
    cout << "Then, I will sort them using the bubble sort method." << endl;

    RerunRandomizer:
    srand(time(0)); //Part of the random numbers.


    for(int i = 0; i < 10; i++) //Generate random numbers into the array.
    {
        randomArray[i] = (rand() % 100) + 1;
    }


    randomArray[10] = sortBubble(randomArray); //Set the array equal to the function that will return a sorted array.

    //****************************************************
    //If the the program finds two numbers to be the same, it will rerun the random generator.
    for(int i = 0; i < 9; i++)
    {
        if(randomArray[i] == randomArray[i+1])
            goto RerunRandomizer;
    }
    //****************************************************

    cout << "****************************************************" << endl; //Display the data.
    for(int i = 0; i < 10; i++)
    {
        if(i < 9)
            cout << randomArray[i] << ", ";
        else
            cout << randomArray[i] << endl;
    }
    cout << "****************************************************" << endl;

    //Initiate a menu that asks the user if they want to program to sort more numbers using the bubble method.
    BubbleMenu:
    cout << "Would you like to search again?" << endl;
    cout << "A. Yes" << endl;
    cout << "B. No" << endl;
    cout << "Choice: ";
    cin >> bubbleChoice;
    cin.ignore();
    cout << "****************************************************" << endl;

    switch(bubbleChoice)
    {
        case 'a':
        case 'A':
            goto BubbleSort;
            break;
        case 'b':
        case 'B':
            main();
            break;
        default:
            cout << "That is not a valid choice." << endl;
            cout << "****************************************************" << endl;
            goto BubbleMenu;
    }
}


int sortBubble(int randomArray[])
{
    bool swap;
	int temp;


	do
	{
        swap = false;
		for (int i = 0; i < 9; i++) //One less because it only needs to swap items 9 times.
		{
            if (randomArray[i] > randomArray[i + 1])
            {
                temp = randomArray[i];
                randomArray[i] = randomArray[i + 1]; //If the integer in front is larger than the one behind, they will swap.
                randomArray[i + 1] = temp;
                swap = true;
            }
		}
	}
    while (swap);


    return randomArray[10]; //Returns the sorted array.
}


//************************************************************************
// This is the beginning to the selection sort functions.                *
//                                                                       *
//                                                                       *
//                                                                       *
//************************************************************************


void selectionSort()
{
    int randomArray[10]; //The array size is 10.
    char selectionMenu;

    SSort:
    cout << "This program will generate 10 random numbers from 1-100." << endl;
    cout << "Then, I will sort them using the selection sort method." << endl;

    RerunRandomizer:
    srand(time(0)); //Part of the random numbers.


    for(int i = 0; i < 10; i++) //Generate random numbers into the array.
    {
        randomArray[i] = (rand() % 100) + 1;
    }


    randomArray[10] = sortSelection(randomArray); //Set the array equal to the function that will return a sorted array.


    //****************************************************
    //If the the program finds two numbers to be the same, it will rerun the random generator.
    for(int i = 0; i < 9; i++)
    {
        if(randomArray[i] == randomArray[i+1])
            goto RerunRandomizer;
    }
    //****************************************************


    cout << "****************************************************" << endl; //Display the data.
    for(int i = 0; i < 10; i++)
    {
        if(i < 9)
            cout << randomArray[i] << ", ";
        else
            cout << randomArray[i] << endl;
    }
    cout << "****************************************************" << endl;

    //Initiate a menu that prompts the user to decide whether they want to program to sort using the selection sort method.
    SMenu:
    cout << "Would you like to search again?" << endl;
    cout << "A. Yes" << endl;
    cout << "B. No" << endl;
    cout << "Choice: ";
    cin >> selectionMenu;
    cin.ignore();
    cout << "****************************************************" << endl;

    switch(selectionMenu)
    {
        case 'a':
        case 'A':
            goto SSort;
            break;
        case 'b':
        case 'B':
            main();
            break;
        default:
            cout << "That is not a valid choice." << endl;
            cout << "****************************************************" << endl;
            goto SMenu;
    }
}


int sortSelection(int randomArray[])
{
	int startScan = 0, minIndex, minValue;

	for (startScan; startScan < 9; startScan++)
	{
	     minIndex = startScan;
	     minValue = randomArray[startScan];
	     for (int index = startScan + 1; index < 10; index ++)
	     {
            if (randomArray[index] < minValue)
            {
                minValue = randomArray[index]; //Finds the minimum value of the array and brings it forward.
                minIndex = index;              //This swaps their spots and it searches for the second lowest.
            }
	     }
        randomArray[minIndex] = randomArray[startScan];
	    randomArray[startScan] = minValue;
	}
}
