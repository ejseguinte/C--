
/*
 *Filename: students.cpp
 *Name: E Seguinte
 *Company: Sacramento City College
 *Data:Mar 27, 2014
 *This program takes names and 3 rounds of golf scores finds total and average
 *History
 *Date		Initials		Action
 *=============================================
 *03/20/2014	ES			Wrote Program/Compiled
 * 
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>
#define SIZE 35
	using namespace std;
void telluser();												//Explains Program use
void calc(int [],int [],int [],int[],int [],int,int[],double[],char []);			//Calculates the Total, average and grade
bool flag;														//True when user wants to run again
void clearscreen(int);											//Clears the screen
void bsort (string[],string[],int[],int[],int[],int[],int[],int[],double[],int,char[]);	//sorts the arrays highest first
int print (string[],string[],int[],int[],int[],int[],int[],int[],double[],int,char[]);	//Prints information to file and screen
int input (int[],int[],int[],int[],int[],string[],string[]);	//reads the file
int main ()
{
	int score1[SIZE], score2[SIZE], score3[SIZE], score4[SIZE],score5[SIZE]; //Scores of 3 round of golf
	int x=0,numgolf;										//flags
	char grade[SIZE];										//array of grades
	double avg[SIZE];										//Average Score
	int total[SIZE];									//Total Score
	string firstname[SIZE], lastname[SIZE];			//First and Last Name of golfer	
	telluser();
do{
clearscreen(20);
	numgolf = input (score1,score2,score3,score4,score5,firstname,lastname);
	//Processing
	calc(score1,score2,score3,score4,score5,numgolf,total,avg,grade);
	bsort (firstname,lastname,score1,score2,score3,score4,score5,total,avg,numgolf,grade);
	//Output
	print (firstname,lastname,score1,score2,score3,score4,score5,total,avg,numgolf,grade);
cout<<"Is there another file? (1 for yes,0 for no): ";
cin>>flag;
cin.get();
}while (flag);									//end of do
return 0; 
}													//end of function
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
	cout<<"This program allows users to enter Student names and";
	cout<<" 5 test scores, then stores them all. It then finds the total of those\nscores and the average,";
	cout<<" then prints to a file.\n\n";
}
/*******************************************************************
*Function: Read
*This function prints to file all the data accumulated
*Input:None
*Output: writes to file 
*Parameter:list of arrays
*Return:1 or 0
********************************************************************/
int input (int score1[],int score2[],int score3[],int score4[],int score5[],string firstname[],string lastname[])
{
	ifstream inputfile;
	int x=0;	//counter
	inputfile.open("students.txt");
		if (inputfile.fail())
		{
			cout<<"Error opening file students.txt\n\n";
			cout<<"Ending Program\n\n";
			return 0;
		}
		else
		{
			cout<<"Input file input and reading data\n";
			while (inputfile>>score1[x])			//There is a line of data to read
			{
				//Input
				inputfile>>score2[x];
				inputfile>>score3[x];
				inputfile>>score4[x];
				inputfile>>score5[x];
				inputfile>>firstname[x];
				inputfile>>lastname[x];	
				x++;
			if (x > SIZE)
				{
					cout<< "\nProgram is ending, too many inpputs values. Please wait for printout and re-start\nprogram.\n";
				}
			}											//End of While loop
			cout<<"\nThere were "<<x<<" Students inputted into program\n";
		}												//End of input else loop
	inputfile.close();						//close the file after reading it
	return x;
}

/*******************************************************************
*Function: Print
*This function prints to file all the data accumulated
*Input:None
*Output: writes to file 
*Input Parameter:list of arrays
*Return:1 or 0
********************************************************************/
int print(string firstname[],string lastname[],int score1[],int score2[],int score3[],int score4[],int score5[],int total[],double avg[],int numg,char grade[])
{
	ofstream outputfile;
	int x;	//counter
	outputfile.open("report.txt");
		if (outputfile.fail())
		{
			cout<<"Error opening file report.txt\n\n";
			cout<<"Ending Program\n\n";
			return 1;						//no report will be written
		}
		else
		{
			outputfile<<"\n\nStudents Name            T1    T2    T3    T4    T5    Total   Average Grade\n";
			outputfile<<"================================================================================"<<endl;
		}
	cout<<"\n\nStudents Name             T1    T2    T3    T4    T5    Total   Average Grade\n";
	cout<<"================================================================================"<<endl;
	//Output
	for(x=0;x<numg;x++)
	{
		cout<<right<<setw(10)<<firstname[x]<<"  "<<left<<setw(14)<<lastname[x];
		cout<<setw(4)<<score1[x]<<"  "<<setw(4)<<score2[x]<<"  "<<setw(4)<<score3[x]<<"  ";
		cout<<setw(4)<<score5[x]<<"  "<<setw(4)<<score4[x]<<"  "<<setw(4)<<total[x]<<"    "<<fixed<<setprecision(2)<<right<<setw(6)<<avg[x]<<"  "<<grade[x]<<"\n";
		outputfile<<right<<setw(10)<<firstname[x]<<" "<<left<<setw(14)<<lastname[x];
		outputfile<<setw(4)<<score1[x]<<"  "<<setw(4)<<score2[x]<<"  "<<setw(4)<<score3[x]<<"  ";
		outputfile<<setw(4)<<score4[x]<<"  "<<setw(4)<<score5[x]<<"  "<<setw(4)<<total[x]<<"    "<<fixed<<setprecision(2)<<right<<setw(6)<<avg[x]<<"  "<<grade[x]<<"\n";
	}											//End of for loop
	outputfile.close();					//close the file after reading it
	cout<<"\nFile Closed\n\n";	
	return 0;
}
/*******************************************************************
*Function: calc
*This function takes scores gives averages,totals and grades
*Input:None
*Output: None
*Parameter:arrays scores 
*Output Parameter: Total, average score,letter grade for each student
*Return:array of totals and averages or all students
********************************************************************/
void calc(int score1[],int score2[],int score3[],int score4[],int score5[], int numg,int sum[],double avg[],char grade[])
{
	int j;	//counter
	for(j=0;j<numg;j++)
	{
	sum[j]=score1[j]+score2[j]+score3[j]+score4[j]+score5[j];	//add all scores
	avg[j]=static_cast<double>(sum[j])/(5.0);					//finds avg
	if(avg[j] >= 90.0)											//finds corresponding avg to give grade
		grade[j]='A';
	else if(avg[j] >=80.0)
		grade[j]='B';
	else if(avg[j] >=70.0)
		grade[j]='C';
	else if(avg[j] >=60.0)
		grade[j]='D';
	else
		grade[j]='F';
	}
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
	int y=0;	//counter
	for(y=0;y<=x;y++)
	cout<<endl;
}
/*******************************************************************
*Function: sort
*This function sorts the inputs to place the highest at the top
*Input:None
*Output: int number of lines
*Parameter:5 scores, names, totals and avg
*Return:None
********************************************************************/
void bsort(string firstname[],string lastname[],int score1[],int score2[],int score3[],int score4[],int score5[],int total[],double avg[],int numg,char grade[])
{
    int i, j, flag = 1;    // set flag to 1 to start first pass
    int temp1,temp2,temp3,temp4,temp5,temptot;             // holding variable
	string tempf,templ;			//holding varible
	char tempg;					//holding varible
	double tempa;				//holding varible
    for(i = 1; (i <= numg) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (numg -1); j++)
        {
            if (total[j+1] > total[j])      // ascending order simply changes to <
            { 
                tempa = avg[j];             // swap elements
				temptot = total[j];
				temp5 = score5[j];
				temp4 = score4[j];
				temp3 = score3[j];
				temp2 = score2[j];
				temp1 = score1[j];
				tempg = grade[j];
				tempf = firstname[j];
				templ = lastname[j];
                avg[j] = avg[j+1];
				total[j]= total[j+1];
				score5[j]= score5[j+1];
				score4[j] = score4[j+1];
				score3[j] = score3[j+1];
				score2[j] = score2[j+1];
				score1[j] = score1[j+1];
				grade[j] = grade[j+1];
				firstname[j] = firstname[j+1];
				lastname[j] = lastname[j+1];
                avg[j+1] = tempa;
				total[j+1]=temptot;
				score5[j+1]=temp5;
				score4[j+1]=temp4;
				score3[j+1]=temp3;
				score2[j+1]=temp2;
				score1[j+1]=temp1;
				grade[j+1]=tempg;
				firstname[j+1]=tempf;
				lastname[j+1]=templ;
                flag = 1;               // indicates that a swap occurred.
            }
        }
    }
}