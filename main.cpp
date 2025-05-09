/******************************************************************************
# Author:            Ari P.
# Assignment:        Assignment 5
# Date:              May 10, 2025
# Description:       This program will calculate the total cost of at least one
                     pizza party, given several different factors.
# Input:             numPeople (int), pizzaPrice (double), avgSlices (double),
                     enterMore (char)
# Output:            numPizzas (int), costPizzas (double), costTax (double),
                     costDelivery (double), totalCost (double), numEntries
                     (int), totalPizzas (int), avgPizzas (double), maxPeople
                     (int), maxTotalCost (double)
# Sources:           Assignment 5 specifications, zyBooks reference
#*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Declare and initialize constant variables
const int SLICES_PER_PIZZA = 8;
const double TAX_RATE = 0.07;
const double DELIVERY_CHARGE = 0.20;

int main() {
   // Declare variables for input and output
   int numPeople = 0;
   double avgSlices = 0.00;
   double pizzaPrice = 0.00;
   char enterMore = 'n';
   int numPizzas = 0;
   double costPizzas = 0.00;
   double costTax = 0.00;
   double costDelivery = 0.00;
   double totalCost = 0.00;
   int numEntries = 0;
   int totalPizzas = 0;
   double avgPizzas = 0.00;
   int maxPeople = 0;
   double maxTotalCost = 0.00;

   // Set floating point precision to 2 decimal places for output
   cout << fixed << setprecision(2);

   // Print a welcome message
   cout << "Based on several factors, this program will calculate the total \
cost of one or more pizza parties." << endl << endl;

   // Prompt for input and repeat until they're finished
   do {
      cout << "Enter the number of people, average number of slices per \
person, and the cost of a pizza (separated by one space each): ";
      cin >> numPeople;
      cin >> avgSlices;
      cin >> pizzaPrice;
      cout << endl;

      // Calculate values
      numPizzas = ceil((static_cast<double>(numPeople) * avgSlices) \
/ static_cast<double>(SLICES_PER_PIZZA));
      costPizzas = static_cast<double>(numPizzas) * pizzaPrice;
      costTax = costPizzas * TAX_RATE;
      costDelivery = (costPizzas + costTax) * DELIVERY_CHARGE;
      totalCost = costPizzas + costTax + costDelivery;

      // Update accumulators
      numEntries += 1;
      totalPizzas += numPizzas;
      if (numPeople > maxPeople) {
         maxPeople = numPeople;
      }
      if (totalCost > maxTotalCost) {
         maxTotalCost = totalCost;
      }
      
      // Display the results
      cout << setw(18) << left << "Number of pizzas:" << right << " " << \
numPizzas << endl;
      cout << setw(18) << left << "Cost of pizzas:" << right << "$" << \
costPizzas << endl;
      cout << setw(18) << left << "Tax:" << right << "$" << costTax << endl;
      cout << setw(18) << left << "Delivery Charge:" << right << "$" << \
costDelivery << endl;
      cout << setw(18) << left << "Total Cost:" << right << "$" << totalCost \
<< endl << endl;

      // Ask the user if they want to enter more
      cout << "Do you want to enter more (y/n)? ";
      cin >> enterMore;
      cout << endl;
   } while (enterMore == 'Y' || enterMore == 'y');

   // Calculate average number of pizzas per entry using accumulators
   avgPizzas = static_cast<double>(totalPizzas) \
/ static_cast<double>(numEntries);

   // Display final statistics
   cout << "Number of entries: " << numEntries << endl;
   cout << "Total number of pizzas: " << totalPizzas << endl;
   cout << "Average number of pizzas: " << avgPizzas << endl;
   cout << "Maximum number of people: " << maxPeople << endl;
   cout << "Maximum total cost of pizzas: $" << maxTotalCost << endl << endl;

   // Print a goodbye message
   cout << "Thank you for using the Pizza Party Calculator." << endl;
   return 0;
}