/*
Filename:payroll2.cpp
Name:Michael Estrada
Company: Sacramento City College
Date:March 25th , 2014
This program will calculate a payroll using input rates of pay and hours
History
Date	   Initials	  Action

===========================================
03/25/2014	MKE	  Wrote/compiled
03/27/2014      MKE       revised second version
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
void writePRT(string,string,double,double,double,double,double,double,ofstream &);
double calcRPT(double, double,double, double&);
double getPayRate();
double payCalc (double,double);
double getHours();
void tellUser();
void clearScreen(int);
const int SIZE = 30;
const double MIN_WAGE= 8.75;
int main()
{
bool report;
int i, code=0, numst;		// counter variable, number of employees
string firstname, lastname; // first and last names of the employees
double ratePay;    //the rate the employee is paid
double hoursWork;    //the number of hours the employee worked
double ovtHours, ovtPay;  //overtime hours and pay
double regPay, totPay;  //regular hours pay and total pay
ofstream outputFile;    //report is written to this file
   clearScreen(24);
   tellUser();           //function to tell user what program does
  outputFile.open("employrpt.txt");
  if (outputFile.fail())
 {
  cout<<"Unable to open report file\n";
  code=1;                    //error report not written
 }
 else
 {
 outputFile<<"Employee    Work     Pay   Overtime    Overtime   total\n";
 outputFile<<"Full Name   Hours    rate   hours        pay \n";
 outputFile<<"==========================================================\n";
 }
 do
 {
   cout<<"What is the first name of this employee? ";
   getline(cin, firstname);
   cout<<"What is the the last name of this employee? ";
   getline(cin, lastname);
  hoursWork=getHours();
  cout<<"hours worked "<<hoursWork<<endl;
  ratePay=getPayRate();
  ovtHours=getOvt(hoursWork,ratePay,ovtPay);
  regPay=calcRPT(ratePay,hoursWork,ovtPay, totPay);
   if(code==0)
   {
   writePRT(firstname,lastname,hoursWork,ratePay,ovtHours,ovtPay,
               regPay,totPay,outputFile);
   }
  cout<<firstname<<" "<<lastname<<endl;
  cout<<setprecision(2)<<fixed;
  cout<<"Hours worked:   "<<setw(7)<<hoursWork<<endl;
  cout<<"Rate of Pay:    "<<setw(7)<<ratePay<<endl;
  cout<<"overtime hours: "<<setw(7)<<ovtHours<<endl;
  cout<<"overtime pay:   "<<setw(7)<<ovtPay<<endl;
  cout<<"regular pay:    "<<setw(7)<<regPay<<endl;
  cout<<"total pay:      "<<setw(7)<<totPay<<endl;
  cout<<"Are there more employees? (1=yes, 0=no) ";
  cin>>report;  
  cin.get();  //reads tje newline from input buffer
 }
 while(report);
if (code==0)
 {
  outputFile.close();  //close report file
  cout<<"\nReport written to employrpt.txt\n\n";
 }
return 0;
}
/****************************************************
 *
 * *************************************************/
void writePRT(string firstname,string lastname,double hoursWork,double ratePay,double ovtHours,double ovtPay,double regPay,double totPay ,ofstream &outputFile)
{
  outputFile<<firstname<<" "<<lastname<<endl;
  outputFile<<setprecision(2)<<fixed;
  outputFile<<"Hours worked:   "<<setw(7)<<hoursWork<<endl;
  outputFile<<"Rate of Pay:    "<<setw(7)<<ratePay<<endl;
  outputFile<<"overtime hours: "<<setw(7)<<ovtHours<<endl;
  outputFile<<"overtime pay:   "<<setw(7)<<ovtPay<<endl;
  outputFile<<"regular pay:    "<<setw(7)<<regPay<<endl;
  outputFile<<"total pay:      "<<setw(7)<<totPay<<endl;
}
/*******************************************************************
 *function calcRPT calculates the regular pay plus overtime pay
 *to get a total for each employee
 *input:none
 *output:none
 *input parameters: ratpay=rateof pay, hrswk=hours worked, ovtpay= overtime pay
 *output parameter: total= the total value of the employees work hours
 *return:regpay=regular pay for the week
 *******************************************************************/
double calcRPT(double ratpay, double hrswk,double ovtp, double &total)
{
    double regpay;  //regular pay
  if (hrswk>40)
    regpay=40.0*ratpay;
  else
    regpay=hrswk*ratpay;
 total=regpay+ovtp;   
return regpay;
}
/**************************************************************
 *This function will take the number of hours worked
 *and calculate the amount of overtime hours and pay.
 *input:none
 *outut:none
 *input parameters:the number of hours worked, rate of pay per hour
 *and the memory address for overtime pay
 *output parameters:otpay=overtime pay for everyone
 *return: othrs=the number of hours overtime
 * ************************************************************/
double getOvt(double hrswk, double rate, double &otpay)
{
  double othrs=0.0;  //the number of overtime hours worked
  otpay =0.0;        //overtime pay
  if(hrswk>40.0)
  {
    othrs=hrswk-40.0;
    otpay=othrs*rate*1.5;
  }
return othrs;
}
/**************************************************************
 *function getPayrate asks the user to enter a payrate between
 *minimum wage and $100.00 per hour
 *input:user enters pay rate
 *output:prompts the user to enter pay rate and gives error messages
 *input paremeters: none
 *output parameters:none
 *return:rate of pay 
 *************************************************************/
double getPayRate()
{
    double rateofPay;  //number of pay 8.75 to 100.00/hour
  do
  {
  cout<<"please enter the rate of pay for\n this employee";
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
 *This function will ask the user to imput how many hours they
 *worked this week and return that value
 *input:hours worked
 *output:prompts for how many hours were worked
 *input paremeters: none
 *output parameters: the number of hours 
 *************************************************************/
double getHours()
{
    double numHours;  //number of hours worked in 1 week 0 to 60
  do
  {
  cout<<"please enter the number of hours worked this week\n";
  cout<<"between 0 and 60 hours ";
  cin>>numHours;
    if(numHours>60.0)
      cout<<"You cannot work more than 60 hours in a week\n";
    else if (numHours<0.0)
      cout<<"You cannot work less than 0 hours in a week\n";
  }
  while(numHours<0.0||numHours>60.0);
  return numHours;
}
/*****************************************************************
 *This function tells the user what the program does  //
 *input:none
 *output:what the program does
 *output parameters:none
 *input parameters:none
 *return:none
 * ***************************************************************/
void tellUser()
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

