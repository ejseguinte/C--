/*
 *Filename: Drill.cpp
 *Name: E Seguinte
 *Company: Sacramento City College
 *Data:April 25, 2014
 *This program takes user input to create drill coordinates
 *History
 *Date		Initials		Action
 *=============================================
 *04/25/2014	ES			Wrote Program/Compiled
 * 
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#define SIZE 200
#define FH 32
#define BH 52
#define SP 22.5
	using namespace std;
struct Drill
{
	double 
		SFB,			//Steps from hash
		HFB,			//Halfway point in front or behind hash
		HS2S,			//Halfway point Side to Side distance
		S2S,			//Distance from yard line
		StepSize,		//Step Size of the set
		SSteps,			//Number of steps from Front Side Line
		Steps,			//Number of steps from Side 1 endzone
		SHash,
		HStep,
		HSStep;
	int 
		FB,				//in front or behind hash
		YD,				//Yardline set is based off of
		HYD,			//Halfway point of Yardline
		SD,				//Which side of the Field
		IO,				//Inside or Outside of Yard line
		set,			//Set number
		Hash,			//Which Hash Set is Based off of
		count;			//Counts in Set
	string 
		WHIO,
		WIO,
		WHash,
		WHHash,
		WFB,
		WHFB,
		WHSD,
		WSD;
};
/************Prototypes************/
void telluser();
void calc(Drill[],int);
void hcalc(Drill[],int);
int input(Drill[]);
void output(Drill[],int);
string switch0(Drill);
string switch1(Drill);
string switch2(Drill);
string switch3(Drill);
int main()
{
	int x;
	Drill drill[SIZE];
	//telluser();
	x=input(drill);
	if (x>0)
	{
		//calc(drill,x);
		//hcalc(drill,x);
		output(drill,x);
	}
	return 0;
}
/*******************************************************************
*Function: input
*This function prints to file all the data accumulated
*Input:from file
*Output: writes to arrays
*Parameter:firstname,lastname,employee ID,rate, hours
*Return: number of employees
********************************************************************/
int input (Drill drill [])
{
	int x=0;
	bool flag;
	do
	{
		cout<<"How many counts?"<<endl;
		cin>>drill[x].count;
		cout<<"What Side are you on? (SDA=1,SDB=2): "<<endl;
		cin>>drill[x].SD;
		cout<<"How many steps from the Yardline?"<<endl;
		cin>>drill[x].S2S;
		cout<<"On, Inside or Outside the Yardline? (On=0;In=1;Out=2): "<<endl;
		cin>>drill[x].IO;
		cout<<"What Yard Line?"<<endl;
		cin>>drill[x].YD;
		cout<<"How many steps Front to back?"<<endl;
		cin>>drill[x].SFB;
		cout<<"On, In front or behind hash? (On=0;F=1,B=2): "<<endl;
		cin>>drill[x].FB;
		cout<<"What hash? (FSL=1,FH=2,BH=3,BSL=4): "<<endl;
		cin>>drill[x].Hash;
	  if(drill[x].IO=2)
		drill[x].S2S=-(drill[x].S2S);
	  cout<<"\nIs there another set? "<<endl;
	cout<<"(1 for yes, 0 for no): ";
	cin>>flag;
	cin.get();
	x++;
	}while(flag);
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
void calc(Drill drill[],int x)
{
	bool flag;
	int j,num;
	double HStep2,HSStep2,dis,dis2,dy;
	cout<<"\nDo the Coordinates not start at zero? "<<endl;
	cout<<"(1 for yes, 0 for no): ";
	cin>>flag;
	if (flag)
	{
		cout<<"\nWhat does it start at?: ";
		cin>>num;
		for(j=0;j<x;j++)
		{
			drill[j].set=j+num;
		}
	}
	else
	{
		for(j=0;j<x;j++)
		{
			drill[j].set=j;
		}
	}
	cout<<"\nCalculation is Starting.\n";
	for(j=0;j<x;j++)
	{
	  if(drill[j].SD==1)							//Calculates the steps from 0 yardline SD1
		{
		drill[j].Steps=((drill[j].YD/5)*8)+drill[j].S2S;
		}
		else if (drill[j].SD==2)					//Calculates the steps from 0 yardline SD1
		{
		drill[j].YD=((drill[j].YD-50)*(-1))+50;		
		drill[j].Steps=((drill[j].YD/5)*8.0)+drill[j].S2S;
		}
    if (drill[j].FB==2 && drill[j].Hash==1)         //Calculation of steps for behind Front Side Line
    {
      drill[j].SSteps=drill[j].SFB;
    }
	else if (drill[j].FB== 0 && drill[j].Hash==1)    //Calcultaion of steps for being on Front Side Line
    {
      drill[j].SSteps=drill[j].SFB;
    }
	else if (drill[j].FB== 0 && drill[j].Hash==1)    //Calcultaion of steps for being on Front Hash
    {
      drill[j].SSteps=FH+drill[j].SFB;
    }
    else if (drill[j].FB== 1 && drill[j].Hash==2)    //Calcultaion of steps for front of front hash
    {
      drill[j].SSteps=FH-drill[j].SFB;
    }
    else if (drill[j].FB==2 && drill[j].Hash==2)    //Calcultaion of steps for behind front hash
    {
      drill[j].SSteps=FH+drill[j].SFB;
    }
	  else if (drill[j].FB==0 && drill[j].Hash==3)    //Calcultaion of steps for being on backhash
    {
      drill[j].SSteps=BH+drill[j].SFB;
    }
    else if (drill[j].FB==1 && drill[j].Hash==3)    //Calcultaion of steps for front of backhash
    {
      drill[j].SSteps=BH-drill[j].SFB;
    }
    else if (drill[j].FB==2 && drill[j].Hash==3)    //Calcultaion of steps for behind back hash
    {
      drill[j].SSteps=BH+drill[j].SFB;
    }
    else if (drill[j].FB==1 && drill[j].Hash==4)    //Calcultaion of steps for front of back side line
    {
      drill[j].SSteps=drill[j].SFB;
    }
	}
	for (j=0;j<(x);j++)
	{
		drill[j].HStep=abs(drill[j].Steps-drill[j+1].Steps);
		drill[j].HSStep=abs(drill[j].SSteps-drill[j+1].SSteps);
		HStep2=pow(drill[j].HStep,2);
		HSStep2=pow(drill[j].HSStep,2);
		dis=HSStep2+HStep2;
		dis2=pow((dis),.5);
		dy=dis2*SP;
		dy/=12;
		dy/=3;
		drill[j].StepSize=(drill[j].count/dy)*(5);
		drill[j].WFB=switch0(drill[j]);
		drill[j].WIO=switch1(drill[j]);
		drill[j].WHash=switch2(drill[j]);
		drill[j].WSD=switch3(drill[j]);
	}
	
}
/*******************************************************************
*Function: output
*This function sorts the inputs to place the highest at the top
*Input:None
*Output: int number of lines
*Parameter:firstname,lastname,id,rate,hour,overtime hour, pay, overtime pay, total, # of employee's
*Return:None
********************************************************************/
void output (Drill drill [],int x)
{
	int j;
	bool flag=1;
	ofstream outputfile;
	do{
	outputfile.open("Corrdinates.txt");
	if (outputfile.fail())		//Checks for output file to open
		{
			cout<<"Error opening file Report.txt\n\n";
			cout<<"Ending Program\n\n";
			flag=0;						//no report will be written
		}
		else
		{
			for(j=0; j<x && j<SIZE;j++)
			{
				cout<<drill[j].WIO<<endl;
				outputfile<<"Set: "<<setw(3)<<drill[j].set;
				outputfile<<"  Cts: "<<setw(3)<<drill[j].count<<endl;
				outputfile<<abs(drill[j].S2S)<<" Stps "<<drill[j].WIO<<" "<<drill[j].WSD<<" "<<drill[j].YD<<"YD"<<endl;
				outputfile<<drill[j].SFB<<" Stps "<<drill[j].WFB<<" "<<drill[j].WHash<<endl;
				if (j<(x-1))
				{
				outputfile<<abs(drill[j].HS2S)<<" Stps "<<drill[j].WHIO<<" "<<drill[j].WHSD<<" "<<drill[j].HYD<<"YDS-"<<endl;
				outputfile<<drill[j].HFB<<" Stps "<<drill[j].WHFB<<" "<<drill[j].WHHash<<endl;
				}
				outputfile<<"\n\n\n\n\n\n";
				cout<<"Set: "<<setw(3)<<drill[j].set;
				cout<<"  Cts: "<<setw(3)<<drill[j].count<<endl;
				cout<<abs(drill[j].S2S)<<" Stps "<<drill[j].WIO<<" "<<drill[j].WSD<<" "<<drill[j].YD<<"YDS-"<<endl;
				cout<<drill[j].SFB<<" Stps "<<drill[j].WFB<<" "<<drill[j].WHash<<endl;
				if (drill[j].StepSize>0 && drill[j].StepSize<6)
				{
				cout<<drill[j].StepSize<<endl;
				}
				if (j<(x-1))
				{
					cout<<abs(drill[j].HS2S)<<" Stps "<<drill[j].WHIO<<" "<<drill[j].WHSD<<" "<<drill[j].HYD<<"YD"<<endl;
					cout<<drill[j].HFB<<" Stps "<<drill[j].WHFB<<" "<<drill[j].WHHash<<endl;
				}
				cout<<"\n";
			}
		}
	cout<<"\n\nCorrdinates written to Corrdinates.txt\n\n";
	flag=0;	
	}while(flag);
}