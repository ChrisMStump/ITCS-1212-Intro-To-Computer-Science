/*
Programmer: Christopher Stump
User ID: cstump1
Section: 001
Assignment: Program 2
Purpose: Demonstrate understanding of decision structures. The program allows the user to input financial data to calculate if the user is eligible for a home loan.

Pseudocode:
1) State basic information about the programmer: Name, ID, Section, Assignment, Purpose.
2) Declare Variables
3) Allow the user to choose which county they reside in.
4) Get information from the user. Purchase price, Down Payment, Other Expenses, Annual Income...
5) Calculate monthly compounded price.
6) Calculate monthly tax.
7) Calculate monthly insurance.
8) If the down payment is less than 20% of the purchase price then private mortgage of 1% of price per month.
9) Calculate monthly income.
10) DTIR = (Monthly: Compounded Price, Tax, Insurance, Private Mortgage + Monthly Expenses) all divided by Monthly Income
11) Display the user's DTIR and whether or not they qualify for a home loan. (Must be less than 28% to qualify).
12) These steps are repeated for both counties and the senior/militant discount.
13) Return the program to 0 and end.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        //Declare ALL THE VARIABLES!
        int county, purchasePrice, downPayment, principle, specialDiscount;
        double debtIncomeRatio, insurance, annualIncome, otherExpenses, compoundedPrice, cruelTax, privateMortgage;
        const double MECK_TAX = .015, CAB_TAX = .012, CAB_DISCOUNT = .01, DIR_ABLE = 28, CAB_BOTHDISCOUNT = .008;
        const int MECKLENBURG = 1, CABARRUS = 2;
        char senior, militant;

        //Display the purpose of the program.
        cout << "Are you eligible for the Home Loans Made Easy Bank Loan?\n\n";
        //This is the list where the user will select their county.
        cout << "Here is a listing of the counties in which this Bank serves.\n\n"; \
        cout << "1. Mecklenburg County\n"
             << "2. Cabarrus County\n\n";
        //The county number is saved in county variable.
        cout << "Please enter the number next to the county in which you reside: ";
        cin >> county;
        cout << endl;
        //If the user enters anything other than 1 or 2 the user will be prompted to rerun the program.
        if (county != 1 && county != 2)
        {
          cout << "You did not enter a valid value.\n";
          cout << "Please rerun the program...\n";
          return 0;
        }

        //Get the purchase price of the house.
        cout << "Please enter the price of the house you wish to buy: ";
        cin >> purchasePrice;
        cout << endl;
        //Get the amount of the down payment.
        cout << "Please enter the down payment on the house: ";
        cin >> downPayment;
        cout << endl;
        //Get the users annual income.
        cout << "Please enter your annual income: ";
        cin >> annualIncome;
        cout << endl;
        //Get the users other monthly expenses
        cout << "Please enter your existing monthly expenses: ";
        cin >> otherExpenses;
        cout << endl;
        //Calculate the principle amount.
        principle = purchasePrice - downPayment;
        //If the user chose Mecklenburg do the following.
        if (county == MECKLENBURG)
        {
            //Calculate the monthly compounded price.
            compoundedPrice = (principle * pow(1.05, 20)) / 240;
            //Calculate monthly tax.
            cruelTax = (purchasePrice * MECK_TAX) / 12;
            //Calculate monthly insurance.
            insurance = (((purchasePrice / 50000) + (purchasePrice % 50000)) * 250) / 12;
            {
            if (downPayment <= (.20 * purchasePrice))   //If down payment < 20% then 1% of principle needs to be paid monthly.
                privateMortgage = (.01 * (principle)) / 12;
            else
                privateMortgage = 0;
            }
            //Calculate debt to income ratio.
            debtIncomeRatio = ((compoundedPrice + cruelTax + insurance + privateMortgage + otherExpenses) / (annualIncome / 12)) * 100;
            //If the DTIR is <= 28% then they qualify if not they don't.
            if (debtIncomeRatio <= DIR_ABLE)
            {
                cout << "Your Debt-to-Income-Ratio is: " << debtIncomeRatio << "% " << endl;
                cout << "Congratulations, you qualify for a home loan!\n";
            }
            else
            {
                cout << "Your Debt-to-Income-Ratio is: " << debtIncomeRatio << "% " << endl;
                cout << "You do not qualify for a home loan.\n";
            }

        }
        //If the user chose Cabarrus county, do the following.
        else if (county == CABARRUS)
        {
            cout << "Enter 1 if you are a senior or militant. Otherwise, enter 0: ";
            cin >> specialDiscount; //Is the user a senior or militant?
            cout << endl;

            if (specialDiscount != 1 && specialDiscount != 0)
            {
              cout << "You did not enter a valid value.\n";
              cout << "Please rerun the program\n";
              return 0; //Ask the user to rerun the program if they did not enter a valid value.
            }

            if (specialDiscount == 1) //If they are a senior or militant.
            {
                //Ask which one they are to see if they can get a double discount.
                cout << "Enter 'Y' if you are senior (65+) or 'N' if you are not: ";
                cin >> senior;
                cout << endl;
                cout << "Enter 'Y' if you are a militant or 'N' if you are not: ";
                cin >> militant;
                cout << endl;

                //Calculate monthly tax. Have to put before if statement just in case they have both discounts.
                cruelTax = (purchasePrice * CAB_DISCOUNT) / 12;

                //If the user answered yes to both they get twice the discount.
                if ((senior == 'Y' || senior == 'y') && (militant == 'Y' || militant == 'y'))
                {
                    cout << "Congrats you qualify for both discounts!" << endl;
                    cruelTax = (purchasePrice * CAB_BOTHDISCOUNT) / 12;
                }


                //Calculate monthly compounded price.
                compoundedPrice = (principle * pow(1.05, 20)) / 240;

                //Calculate monthly insurance.
                insurance = (((purchasePrice / 50000) + (purchasePrice % 50000)) * 250) / 12;

                if (downPayment <= (.20 * purchasePrice)) //If down payment < 20% then 1% of principle needs to be paid monthly.
                    privateMortgage = (.01 * principle) / 12;
                else
                    privateMortgage = 0;
               //Calculate debt to income ratio.
                debtIncomeRatio = ((compoundedPrice + cruelTax + insurance + privateMortgage + otherExpenses) / (annualIncome / 12)) * 100;
               //If the DTIR is <= 28% then they qualify if not they don't.
                if (debtIncomeRatio <= DIR_ABLE)
                {
                    cout << "Your Debt-to-Income-Ratio is: " << debtIncomeRatio << "% " << endl;
                    cout << "Congratulations, you qualify for a home loan!\n";
                }
                else
                {
                    cout << "Your Debt-to-Income-Ratio is: " << debtIncomeRatio << "% " << endl;
                    cout << "You do not qualify for a home loan.\n";
                }
            }
            else if (specialDiscount == 0) //If the user is not a senior or militant.
            {
                //Calculate monthly compounded price.
                compoundedPrice = (principle * pow(1.05, 20)) / 240;
                //Calculate monthly tax.
                cruelTax = (purchasePrice * CAB_TAX) / 12;
                //Calculate monthly insurance.
                insurance = (((purchasePrice / 50000) + (purchasePrice % 50000)) * 250) / 12;

                if (downPayment <= (.20 * purchasePrice)) //If down payment < 20% then 1% of principle needs to be paid monthly.
                    privateMortgage = (.01 * principle) / 12;
                else
                    privateMortgage = 0;

                debtIncomeRatio = ((compoundedPrice + cruelTax + insurance + privateMortgage + otherExpenses) / (annualIncome / 12)) * 100;
                //If the DTIR is <= 28% then they qualify if not they don't.
                if (debtIncomeRatio <= DIR_ABLE)
                {
                    cout << "Your Debt-to-Income-Ratio is: " << debtIncomeRatio << "% " << endl;
                    cout << "Congratulations, you qualify for a home loan!\n";
                }
                else
                {
                    cout << "Your Debt-to-Income-Ratio is: " << debtIncomeRatio << "% " << endl;
                    cout << "You do not qualify for a home loan.\n";
                }
            }

        }
        return 0;

}
