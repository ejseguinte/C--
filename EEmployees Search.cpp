
/*
 *Filename: students.cpp
 *Name: E Seguinte
 *Company: Sacramento City College
 *Data:April 03, 2014
 *This program takes file input to enter employee's names,hours and rate of pay and find total pay and hours.
 *History
 *Date		Initials		Action
 *=============================================
 *04/03/2014	ES			Wrote Program/Compiled
 *04/22/2014	ES			Included structure
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#define SIZE 50
#define MIN 8.75
#define OT 1.5
	using namespace std;
struct EmpRecord
{
	double rate,				//Rate of pay
		hour,ohour,				//Regular hours and overtime hours
		pay,opay,				//Regular pay and overtime pay
		total;					//Total Pay						
	string first, last, name,	//First and Last Name of employee
		num;					//Employee Number
};
//**************Prototypes**************//
void telluser();								//Explains Program use
void calc(EmpRecord [],int);					//Calculates The hours overtime and pay
void clearscreen(int);							//Clears the screen
void ghours (EmpRecord [],int);					//Gets Hours of new Worker
void grates (EmpRecord [],int);					//Gets Rate of new Worker
void bsort (EmpRecord [],int);					//sorts the arrays highest first
int input (EmpRecord [],bool&);					//Takes input
void output(EmpRecord [],int);					//Outputs to screen and file
void add(EmpRecord [],int&);					//Adds new worker information
void Search(EmpRecord [],int);					//Searchs structure for...
int main ()
{
	EmpRecord  emp [SIZE];
	bool flag1=0;
	int x=0,count;					//flags	
	clearscreen(20);				//Clears screen
	telluser();						//Tell User function
	//Input
	count = input (emp,flag1);		//Input from File
	add(emp,count);					//Extra Employee adding
	if(flag1==0)
	//Processing
	{
	calc(emp,count);
	bsort (emp,count);
	//Output
	output (emp,count);
	Search(emp,count);
	}
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
	cout<<"Erwin's Employee Hours and pay Calculator\n\n";
	cout<<"This program takes file input to enter employee's names, hours worked and \nrate of pay. Then finds hours of overtime and overtime";
	cout<<"\npay to print an information table.";
	cout<<"\n\nPress Enter To Continue...";
	cin.get();
}
/*******************************************************************
*Function: input
*This function prints to file all the data accumulated
*Input:from file
*Output: writes to arrays
*Parameter:firstname,lastname,employee ID,rate, hours
*Return: number of employees
********************************************************************/
int input (EmpRecord emp [],bool &flag)
{
	ifstream inputfile;
	int x=0;	//counter
	//Checking file open
	inputfile.open("employee2.txt");
		if (inputfile.fail())
		{
			cout<<"Error opening file employee2.txt\n\n";
			cout<<"Ending Program\n\n";
			flag= 1;
		}
		else
		{
			//begins reading File
			cout<<"\nInput file (employee2.txt) open and reading data\n";
			while (inputfile>>(emp[x].hour)&& x<SIZE)			//There is a line of data to read
			{
				//Input
				inputfile >> emp[x].rate;
				inputfile>> emp[x].num;
				inputfile>> emp[x].first;
				inputfile>> emp[x].last;
				emp[x].name= emp[x].first+ " " +emp[x].last;
				x++;
			if (x > SIZE)	//If file has too many input stop reading
				{
					cout<< "\nProgram is ending, too many inputs values. Please wait for printout and re-start\nprogram.\n";
				}
			}											//End of While loop
			cout<<"\nThere were "<<x<<" employees inputted into program.\n";
		}												//End of input else loop
	inputfile.close();									//Close the file after reading it
	return x;
}
/*******************************************************************
*Function: calc
*This function takes rate,hour,pay,overtime hour, overtime pay, total and number of employees
*Input:None
*Output: None
*Parameter:rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Output Parameter: rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Return:None
********************************************************************/
void calc(EmpRecord emp[],int j)
{
	int x;
	cout<<"\nCalculation is Starting.\n";
	for(x=0;x<j;x++)
	{
	if ((emp[x].hour) > 40.0) //Calculation for working overtime
	{
		emp[x].ohour = emp[x].hour- 40;
		emp[x].hour -= emp[x].ohour;
		emp[x].pay = emp[x].hour * emp[x].rate;
		emp[x].opay = emp[x].ohour * emp[x].rate* OT;
	}
	else			//Calculation for working less that or equal to 40 hours
	{
		emp[x].opay=0;
		emp[x].ohour=0;
		emp[x].pay=emp[x].hour*emp[x].rate;
		
	}
	emp[x].total=emp[x].pay+emp[x].opay;
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
*Function: output
*This function sorts the inputs to place the highest at the top
*Input:None
*Output: int number of lines
*Parameter:firstname,lastname,id,rate,hour,overtime hour, pay, overtime pay, total, # of employee's
*Return:None
********************************************************************/
void output (EmpRecord emp [],int count)
{
	int x;
	bool flag=1;
	ofstream outputfile;
	outputfile.open("Report.txt");
	do{
	if (outputfile.fail())		//Checks for output file to open
		{
			cout<<"Error opening file Report.txt\n\n";
			cout<<"Ending Program\n\n";
			flag=0;						//no report will be written
		}
		else
		{
		//prints header
		outputfile<<"Employee                   Work           Normal   Overtime  Overtime\n";
		outputfile<<"Full Name           ID     Hours  Rate    Pay      Hours     Pay          Total\n";
		outputfile<<"================================================================================";
		cout<<"\n";
		cout<<"Employee                   Work           Normal   Overtime  Overtime\n";
		cout<<"Full Name           ID     Hours  Rate    Pay      Hours     Pay          Total\n";
		cout<<"================================================================================";
		for (x=0;x<count;x++)
		{
		outputfile<<fixed<<setprecision(2);
		outputfile<<"\n"<<left<<setw(20)<<emp[x].name<<setw(7)<<emp[x].num;
		outputfile<<setw(5)<<emp[x].hour<<"  "<<setw(6)<<emp[x].rate<<"  "<<setw(7)<<emp[x].pay<<"  "<<setw(7)<<emp[x].ohour<<"   "<<setw(7)<<emp[x].opay<<" "<<setw(10)<<right<<emp[x].total;
		cout<<fixed<<setprecision(2);
		cout<<"\n"<<left<<setw(20)<<emp[x].name<<setw(7) <<emp[x].num;
		cout<<setw(5)<<emp[x].hour<<"  "<<setw(6)<<emp[x].rate<<"  "<<setw(7)<<emp[x].pay<<"  "<<setw(7)<<emp[x].ohour<<"   "<<setw(7)<<emp[x].opay<<" "<<setw(10)<<right<<emp[x].total;
		}
	cout<<"\n\nEmployee Report written to Report.txt\n\n";
	flag=0;	
	}
}while(flag);
}
/*******************************************************************
*Function: sort
*This function sorts the inputs to place the highest at the top
*Input:None
*Output: None
*Parameter:firstname,lastname,Employee ID,rate,hour,count
*Return:None
********************************************************************/
void bsort(EmpRecord emp [],int count)
{
    int i, x, flag = 1;    // set flag to 1 to start first pass
	EmpRecord temp;
    cout<<"\nSort is Starting.\n";
	for(i = 1; (i <= count) && flag; i++)
    {
        flag = 0;
        for (x=0; x < (count -1); x++)
        {
            if ((emp[x+1].last < emp[x].last) || ((emp[x+1].last == emp[x].last) && (emp[x+1].first < emp[x].first)))      // Dscending order  
            { 
				temp = emp[x];
				emp[x]=emp[x+1];
				emp[x+1]=temp;
                flag = 1;               // indicates that a swap occurred.
            }
        }
    }
}
/**************************************************************
 *Function: getPayrate 
 *This function asks the user to enter a payrate between minimum wage and $100.00 per hour
 *Input:user enters pay rate
 *Output:prompts the user to enter pay rate and gives error messages
 *Input paremeters: none
 *Output parameters:none
 *Return:rate of pay 
 *************************************************************/
void grates(EmpRecord emp [],int x)
{
  do
  {
  cout<<"Please enter the rate of pay for\n this employee";
  cout<<"between $"<<MIN<<" and $100.00: ";
  cin>>emp[x].rate;
    if(emp[x].rate>100.0)
      cout<<"You cannot be paid more than $100.00 per hour\n";
    else if (emp[x].rate<MIN)
      cout<<"You cannot be paid less than $8.75 per hour\n";
  }
  while(emp[x].rate<MIN||emp[x].rate>100.00);
}
/**************************************************************
 *Function gethours
 *This function will ask the user to imput how many hours they worked this week and return that value
 *Input:hours worked
 *Output:prompts for how many hours were worked
 *Input paremeters: none
 *Output parameters: the number of hours 
 *Return: numhours
 *************************************************************/
void ghours(EmpRecord emp [],int x)
{
  do
  {
  cout<<"Please enter the number of hours worked this week\n";
  cout<<"between 0 and 60 hours: ";
  cin>>emp[x].hour;
    if(emp[x].hour>60.0)
      cout<<"You cannot work more than 60 hours in a week\n";
    else if (emp[x].hour<0.0)
      cout<<"You cannot work less than 0 hours in a week\n";
  }
  while(emp[x].hour<0.0||emp[x].hour>60.0);
}
/**************************************************************
 *Function add
 *This function will ask the user to add another employee
 *Input:first,last,emp number
 *Output:Number of employee's added
 *Input paremeters: EmpRecord and number of total employee's
 *Output parameters: EmpRecord and number of total employee's
 *Return: none
 *************************************************************/
void add(EmpRecord emp [],int &x)
{	
	bool flag;						//Flag
	int y=x;						//Old Amount of employee's
	cout<<"\nIs there another employee to add? "<<endl;
	cout<<"(1 for yes, 0 for no): ";
	cin>>flag;
	while (flag && (x<SIZE-1))		//While for employee adding
	{
		cout<<"\nWhat is Employee's First name?: "<<endl;
		cin>>emp[x].first;
		cout<<"\nWhat is Employee's last name?: "<<endl;
		cin>>emp[x].last;
		emp[x].name= emp[x].first+ " " +emp[x].last;
		cout<<"\nWhat is Employee number?: "<<endl;
		cin>>emp[x].num;
		ghours(emp,x);
		grates(emp,x);
		++x;						//Increases the total number of employee's
		cout<<"\nIs there another employee to add? "<<endl;
		cout<<"(1 for yes, 0 for no): ";
		cin>>flag;
	}
	y=x-y;							//Tells amount of newly added employee's
	cout<<"\nThere was "<<y<<" Employee's added.";
	cout<<"\nThere are "<<x<<" Employee's total.";
	cout<<"\n\nPress Enter To Continue...";
	cin.get();						//Waits for enter key
	cin.get();						//Waits for enter key
}
/**************************************************************
 *Function Search
 *This function will ask the user to enter something to search by Last name
 *Input:Last name
 *Output:Employee info that corresponds to name
 *Input paremeters: EmpRecord and number of total employee's
 *Output parameters: EmpRecord and number of total employee's 
 *Return: None
 *************************************************************/
void Search(EmpRecord emp [],int count)
{
	string last,first;
	int x,found=-1,j=1;
	bool flag=0;
	cout<<"\n\nWould you like to search for an employee? "<<endl;
	cout<<"(1 for yes, 0 for no): ";
	cin>>flag;
	cin.get();
	while(flag)
	{
		cout<<"Please enter an Employee's last name to search for: "<<endl;
		getline(cin,last);
		last[0] =toupper(last[0]);		//Forces the first letter of the last name to be capital
		for (x=0; (found==-1 && x<count) ;x++)
		{
			if (last == emp[x].last)
			{
				found = x;
				if ((emp[x+1].last == emp[x].last))
					{
					
						cout<<"There are were multiple people with the lastname <<"<<last<<">>"<<endl;
						cout<<"Please enter an Employee's first name to search for: "<<endl;
						getline(cin,first);
						first[0] =toupper(first[0]);		//Forces the first letter of the first name to be capital
					}
				for (x=found;x<count;x++)
				{
					if (first == emp[x].first)
					{
						found = x;
					}
				}
			}
		}
		if( x=count)
			cout<<"Employee could not be found"<<endl;
		else
		{
			cout<<"\n";
		cout<<"Employee                   Work           Normal   Overtime  Overtime\n";
		cout<<"Full Name           ID     Hours  Rate    Pay      Hours     Pay          Total\n";
		cout<<"================================================================================";
		cout<<fixed<<setprecision(2);
		cout<<left<<setw(20)<<emp[found].name<<setw(7) <<emp[found].num;
		cout<<setw(5)<<emp[found].hour<<"  "<<setw(6)<<emp[found].rate<<"  "<<setw(7)<<emp[found].pay<<"  "<<setw(7)<<emp[found].ohour<<"   "<<setw(7)<<emp[found].opay<<" "<<setw(10)<<right<<emp[found].total;
		}
		cout<<"\n\nWould you like to search for another employee? "<<endl;
		cout<<"(1 for yes, 0 for no): ";
		cin>>flag;
		cin.get();
		found=-1;
	}
}
