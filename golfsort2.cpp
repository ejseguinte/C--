/* s feder Oct 1, 2013  wgolf.cpp
* this program reads golfer data from a file women.txt stores all
* the golfers in an array of data. Writes a report womengolfreport.txt
* to a file.  Sorts the golfers from low ( winner) to high
* and writes their scores to a file
* Who    When        What
* SHF   01/23/2013  Created Program
********************************************************  */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
void tellUser();
double calcAvg(int,int,int,int,int&);
void swap(int &, int &);
void swap(double &, double &);
void swap(string &, string &);
int main()
{  
   const int SZ = 20;        // size of arrays to hold scores
   string firstname[SZ], lastname[SZ];  // name of golfer
   int i, lastpos;                      // counter
   int numgolf;                // total number of golfers
   int round1[SZ],round2[SZ],round3[SZ],round4[SZ]; //scores on 4 rounds of golf
   int total[SZ];                  // total of four rounds of golf
   double average[SZ]; // average for one player
   bool swapmade;
   ifstream inputFile;         // input filename in program
   ofstream outputFile;
   bool screenonly = false;    // only write output to screen when true
   tellUser();                 // tell user what program does
   //  open file and read input from file  golfers.txt
   inputFile.open("women.txt");
   if (inputFile.fail())
   {
       cout << "Error opening file women.txt \n\n";
       cout << "end of program\n\n";
   }
   else
   {
     i = 0;                        // golfer number for array
     while (inputFile >> round1[i])   // there is a line of data to read
     {
        inputFile >> round2[i];     // read golf score
        inputFile >> round3[i];     // read golf score
        inputFile >> round4[i];     // read golf score
        inputFile >> firstname[i];  // read first name of golfer
        inputFile >> lastname[i];   // read last name of golfer   
		i++;
     }   // end while
     cout << "There were " << i << " golfers\n\n";
     numgolf = i;           // number of golfers
     inputFile.close();     // close the file after reading it
     // *********************  close input file ************
     cout << "input file closed\n\n"; 
     // loop to calculate total and average for each golfer 
     cout << "calculating average and totals\n";
     for ( i=0; i < numgolf; i++)
     {
        average[i] = calcAvg(round1[i],round2[i],round3[i],round4[i],total[i]); 
     }
     //  sort the golfers with winner on top and loser on the bottom
     cout << "sorting golfers\n";
     lastpos = numgolf;
     do
     {
       lastpos--;
       swapmade = false;
       for ( i = 0 ;i < lastpos; i++)
       {
          if (total[i] < total[i+1])    // they are in the wrong order
          {    // swap all items here
            swap(lastname[i], lastname[i+1]);
            swap(total[i], total[i+1]);
            swap(round1[i], round1[i+1]);
            swap(round2[i], round2[i+1]);
            swap(round3[i], round3[i+1]);
            swap(round4[i], round4[i+1]);
            swapmade = true;
          }
       }  // end of for loop
      } while(swapmade);   // end of do loop
     // open report file and write output data ********************
     cout << "Report being written to file womengolfreport.txt \n";
     outputFile.open("womengolfreport.txt");  // output file
     if (outputFile.fail())
     {
         screenonly = true;
         cout << "output file did NOT open\n";   
         cout << "output will only be sent to the screen\n";
     }
     cout << "\n\nRnd1 Rnd2 Rnd3 Rnd4 Total Average Golfer Name\n";
	 outputFile<< "\n\nRnd1 Rnd2 Rnd3 Rnd4 Total Average Golfer Name\n";
	 // loop to print report of golfers  ********************
     for ( i=0; i < numgolf; i++)
     {
        cout << round1[i] << "   "  << round2[i] << "   ";     
        cout << round3[i] << "   "  << round4[i] << "   ";     
        cout << total[i] << "   " << fixed<<setprecision(2)<<average[i] << "   ";
        cout << firstname[i] << " " << lastname[i] << "\n";
        if (!screenonly)   // show firstname, lastname, then 4 scores, total and average
        {
           outputFile << round1[i] << "  "  << round2[i] << "  ";     
           outputFile << round3[i] << "  "  << round4[i] << "  ";     
           outputFile << total[i] << "  " << average[i] << "  ";
           outputFile << firstname[i] << " " << lastname[i] << "\n";
        }
     }  // end of forloop  that writes report
     if (!screenonly)
     {  outputFile.close(); cout << "Output file closed\n\n";} 
   }   // end else
   return 0;
} 
//  end of main **************************************
/* function tellUser
 * it tells the user what the program does 
 * it prints output to the screen
 ****************************************************** */
void tellUser()
{
   cout << "This program reads a file called golfers.txt,\n";
   cout << "and it calculates the total and average for each golfer.\n";
   cout << "golfers are sorted into order with winner first and loser last.\n";
   cout << "output is written to the screen. and to an output file \n\n";
}
/* *****************************************************
 * function calcAvg
 *  receives the 4 scores  and 
 * address of total.  Calculates total and stores it
 *  calculates the average and returns it
******************************************************* */
double calcAvg(int r1,int r2,int r3,int r4,int &tot)
{
	   double avg;         // calculated average
	   tot = r1 + r2 + r3 + r4;
	   avg = 1.0 * tot/4.0;
	   return avg;
}
/* *************************************************************
 * function swap
 *  swaps two items
 * input: 2 whole numbers
 * output: switches values of the 2 items
 * passed back: the 2 whole numbers are switched
 * returns: none
 */
void swap( int &num1, int &num2)
{
   int temp;   // temporary storage space to hold 1 of the numbers
   temp = num1;
   num1 = num2;
   num2 = temp;
}
/* *************************************************************
 * function swap
 *  swaps two double items
 * input: 2 double numbers
 * output: switches values of the 2 items
 * passed back: the 2 double numbers are switched
 * returns: none
 */
void swap(double &num1, double &num2)
{
   double temp;   // temporary storage space to hold 1 of the numbers
   temp = num1;
   num1 = num2;
   num2 = temp;
}
/* *************************************************************
 * function swap
 *  swaps two strings of characters
 * input: 2 strings of characters
 * output: switches values of the 2 strings
 * passed back: the 2 strings  are switched
 * returns: none
 */
void swap(string &num1,string &num2)
{
   string temp;   // temporary storage space to hold 1 of the strings
   temp = num1;
   num1 = num2;
   num2 = temp;
}
