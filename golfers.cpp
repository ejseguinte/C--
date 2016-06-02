
/*
 *Filename: .cpp
 *Name: E Seguinte
 *Company: Sacramento City College
 *Data:Feb 27, 2014
 *This program takes names and 3 rounds of golf scores finds total and average
 *History
 *Date		Initials		Action
 *=============================================
 *02/27/2014	ES			Wrote Program/Compiled
 * 
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>
	using namespace std;
void telluser();								//Explains Program use
int calctotal(int,int,int,int);			//Calculates the Total
bool flag;										//True when user wants to run again
double calcavg(int);							//Calculates Average
void clearscreen(int);						//Clears the screen
int main ()
{
	int score1, score2, score3, score4;	//Scores of 3 round of golf
	double avg;									//Average Score
	int total;									//Total Score
	string firstname, lastname;			//First and Last Name of golfer
	ifstream inputfile;;						// input filename
	clearscreen(24);		
	telluser();
do{
	inputfile.open("golfers.txt");
	if (inputfile.fail())
	{
		cout<<"Error opening file golfers.txt\n\n";
		cout<<"Ending Program\n\n";
	}
	else
	{
		cout<<"Input file input and reading data\n";
		cout<<"\n\nRnd1 Rnd2 Rnd3 Rnd4 Total Average Golfers name\n";
		while (inputfile>>score1)			//There is a line of data to read
		{
			//Input
			inputfile>>score2;
			inputfile>>score3;
			inputfile>>score4;
			inputfile>>firstname;
			inputfile>>lastname;
			//Processing
			total= calctotal(score1,score2,score3,score4);
			avg= calcavg(total);
			//Output	
			cout<<setw(3)<<score1<<"  ";
			cout<<setw(3)<<score2<<"  ";
			cout<<setw(3)<<score3<<"  ";
			cout<<setw(3)<<score4<<"   ";
			cout<<setw(3)<<total<<"   ";
			cout<<fixed<<setprecision(2)<<setw(4)<<avg<<"   ";
			cout<<firstname<<" "<<lastname<<"\n";
		}											//End of While loop
	inputfile.close();						//close the file after reading it
	cout<<"File Closed\n\n";
	}
cout<<"Is there another file? (1 for yes,0 for no): ";
cin>>flag;
cin.get();
}while (flag);	
return 0; 
}
/*******************************************************************
*Function: telluser
*This function tells the user what the program does
*Input:None
*Output: writes to screen- what the program does
*Parameter:none
*Return:none
********************************************************************/
void telluser()
{
	cout<<"This program allows users to enter golers and";
	cout<<" 4 rounds of golf \nscores. it finds the total ";
	cout<<"of those scores and the average.\n\n";
}
/*******************************************************************
*Function: calctotal
*This function totals the score of 4 rounds
*Input:None
*Output: None
*Parameter:3 whole number golf scores
*Return:whole number total of scores
********************************************************************/
int calctotal(int score1,int score2,int score3,int score4)
{
	int sum;
	sum=score1+score2+score3+score4;
	return sum;
}
/*******************************************************************
*Function: calcavg
*This function averages the scores of 4 rounds
*Input:None
*Output: None
*Parameter:total of scores
*Return:avg score
********************************************************************/
double calcavg(int total)
{
	double avg;
	avg=static_cast<double>(total)/(4.0);
	return avg;
}
/*******************************************************************
*Function: clearscreen
*This function clears the screen
*Input:None
*Output: int number of lines
*Parameter:1 whole number
*Return:None
********************************************************************/
void clearscreen(int x)
{
	int y=0;
	for(y=0;y<=x;y++)
	cout<<endl;
}