/*
Filename:payroll1.cpp
Name:Erwin Seguinte
Company: Sacramento City College
Date:March 25th , 2014
This program will calculate a payroll using input rates of pay and hours
History
Date	   Initials	  Action
===========================================
03/25/2014	ES	  Wrote/compiled
*/
#include<string>
#include<fstream>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
double getOvt(double,double, double &);
void writert(string,string,double,double,double,double,double,double,ofstream &);
double calc(double, double,double, double&);
double getPayRate();
double payCalc (double,double);
double gethours();
void telluser();
void clearScreen(int);
const int SIZE = 30;
const double MIN_WAGE= 8.75;
int main()
{
bool flag;
int i, flag1, numst;		// counter variable, number of employees
string first, last;         // first and last names of the employees
double ratepay;	            //the rate the employee is paid
double hours;               //the number of hours the employee worked
double ohours, opay;        //overtime hours and pay
double rpay, tpay;          //regular hours pay and total pay
ofstream outputFile;        //report is written to this file
   clearScreen(24);			//Clears the screen
   telluser();              //function to tell user what program does
  outputFile.open("report.txt");
  if (outputFile.fail())
 {
  cout<<"Unable to open report file\n";
  flag1=1;                    //error report not written
 }
 else
 {
 outputFile<<"Employee    Work     Pay   Overtime    Overtime   total\n";
 outputFile<<"Full Name   Hours    Rate   Hours        Pay \n";
 outputFile<<"==========================================================\n";
 }
 do
 {
   cout<<"What is the first name of this employee? ";
   getline(cin, first);
   cout<<"What is the the last name of this employee? ";
   getline(cin, last);
  hours=gethours();
  cout<<"Hours Worked "<<hours<<endl;
  ratepay=getPayRate();
  ohours=getOvt(hours,ratepay,opay);
  rpay=calc(ratepay,hours,opay, tpay);
   if(flag1==0)
   {
   writert(first,last,hours,ratepay,ohours,opay,rpay,tpay,outputFile);
   }
  cout<<first<<" "<<last<<endl;
  cout<<setprecision(2)<<fixed;
  cout<<"Hours worked:   "<<setw(7)<<hours<<endl;
  cout<<"Rate of Pay:    "<<setw(7)<<ratepay<<endl;
  cout<<"Overtime hours: "<<setw(7)<<ohours<<endl;
  cout<<"Overtime pay:   "<<setw(7)<<opay<<endl;
  cout<<"Regular pay:    "<<setw(7)<<rpay<<endl;
  cout<<"Total pay:      "<<setw(7)<<tpay<<endl;
  cout<<"Are there more employees? (1=yes, 0=no) :";
  cin>>flag;  
  cin.get();           //reads blank from input buffer
 }
 while(flag);
if (flag1==0)
 {
  outputFile.close();  //close report file
  cout<<"\nReport written to Report.txt\n\n";
 }
return 0;
}/****************************************************
 *Function: writert 
 *This function ouputs hours worked, rate of pay,overtime,regular pay and total pay
 *Input:none
 *Output:none
 *Input parameters: first,last, hours,rapay,ohours,opay,ratepay,tpay, output file
 *Output parameter: first,last, hours,rapay,ohours,opay,ratepay,tpay, output file
 *Return:none
 * *************************************************/
void writert(string first,string last,double hours,double rpay,double ohours,double opay,double ratepay,double tpay ,ofstream &outputFile)
{
  outputFile<<first<<" "<<last<<endl;
  outputFile<<setprecision(2)<<fixed;
  outputFile<<"Hours worked:   "<<setw(7)<<hours<<endl;
  outputFile<<"Rate of Pay:    "<<setw(7)<<ratepay<<endl;
  outputFile<<"Overtime Hours: "<<setw(7)<<ohours<<endl;
  outputFile<<"Overtime Pay:   "<<setw(7)<<opay<<endl;
  outputFile<<"Regular Pay:    "<<setw(7)<<rpay<<endl;
  outputFile<<"Total Pay:      "<<setw(7)<<tpay<<endl;
}
/*******************************************************************
 *Function: calc
 *This function calculates the regular pay plus overtime pay to get a total for each employee
 *Input:none
 *Output:none
 *Input parameters: ratepay, hours, opay, total
 *Return:rpay
 *******************************************************************/
double calc(double ratepay, double hours,double opay, double &total)
{
    double rpay;  //regular pay
  if (hours>40)
    rpay=40.0*ratepay;
  else
    rpay=hours*ratepay;
 total=rpay+opay;   
return rpay;
}
/**************************************************************
 *Function: getOvt
 *This function will take the number of hours worked and calculate the amount of overtime hours and pay.
 *Input:none
 *Outut:none
 *Input parameters:hours, rate and &otpay
 *Output parameters:otpay
 *Return: othrs=the number of hours overtime
 * ************************************************************/
double getOvt(double hours, double rate, double &otpay)
{
  double othrs=0.0;  //the number of overtime hours worked
  otpay =0.0;        //overtime pay
  if(hours>40.0)
  {
    othrs=hours-40.0;
    otpay=othrs*rate*1.5;
  }
return othrs;
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
double getPayRate()
{
    double rateofPay;  //number of pay 8.75 to 100.00/hour
  do
  {
  cout<<"Please enter the rate of pay for\n this employee";
  cout<<" between $"<<MIN_WAGE<<" and $100.00 ";
  cin>>rateofPay;
    if(rateofPay>100.0)
      cout<<"You cannot be paid more than $100.00 per hour\n";
    else if (rateofPay<MIN_WAGE)
      cout<<"You cannot be paid less than $8.75 per hour\n";
  }
  while(rateofPay<MIN_WAGE||rateofPay>100.00);
  return rateofPay;
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
double gethours()
{
    double numhours;  //number of hours worked in 1 week 0 to 60
  do
  {
  cout<<"Please enter the number of hours worked this week\n";
  cout<<"between 0 and 60 hours ";
  cin>>numhours;
    if(numhours>60.0)
      cout<<"You cannot work more than 60 hours in a week\n";
    else if (numhours<0.0)
      cout<<"You cannot work less than 0 hours in a week\n";
  }
  while(numhours<0.0||numhours>60.0);
  return numhours;
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
	cout << "This program asks the user to enter employees name,";
	cout << "hours worked \n and rate of pay and breaks down their ";
	cout << "total pay by hours of regular and overtime pay\n";
	
}
/*****************************************************************
 *This function clears the screen as many times as the programmer 
 *wants it to
 *input:none
 *output:blank lines
 *input parameters:the numbers of cleared lines desired
 *output parameters:none
 *return:none
 * *************************************************************/
void clearScreen(int h)
{
double i;
 for (i=0;i<=h;i++)
    cout<<"\n";
}

