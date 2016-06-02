
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
int Ainput(Drill[]);
void output(Drill[],int);
string switch0(Drill);
string switch1(Drill);
string switch2(Drill);
string switch3(Drill);
int main()
{
	int x;
	Drill drill[SIZE];
	telluser();
	//x=Ainput(drill);
	x=input(drill);
	if (x>0)
	{
		calc(drill,x);
		hcalc(drill,x);
		output(drill,x);
	}
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
	cout<<"Erwin Seguinte Dot Calculator";
	cout<<"\nThis program takes user input to produce coordinate's in short hand form";
	cout<<"\nPress <Enter> to Continue...";
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
int input (Drill drill [])
{
	int x=0,j=0;
	bool flag;
	int num;
	do
	{
		cout<<"How many counts?"<<endl;
		cin>>drill[x].count;
		cout<<"What Side are you on? (SDA=1,SDB=2): "<<endl;
		cin>>drill[x].SD;
		cout<<"How many steps from the Yardline?"<<endl;
		cin>>drill[x].S2S;
			if(drill[x].S2S==0)
			{
			drill[x].IO=0;
			}
			else 
			{
			cout<<"On, Inside or Outside the Yardline? (On=0;In=1;Out=2): "<<endl;
			cin>>drill[x].IO;
			}
		cout<<"What Yard Line?"<<endl;
		cin>>drill[x].YD;
		cout<<"How many steps Front to back?"<<endl;
		cin>>drill[x].SFB;
		if(drill[x].SFB==0)
			{
			drill[x].FB=0;
			}
			else 
			{
			cout<<"On, In front or behind hash? (On=0;F=1,B=2): "<<endl;
			cin>>drill[x].FB;
			}
		cout<<"What hash? (FSL=1,FH=2,BH=3,BSL=4): "<<endl;
		cin>>drill[x].Hash;
	  if(drill[x].IO==2)
		drill[x].S2S=-(drill[x].S2S);
	  cout<<"\nIs there another set? "<<endl;
	cout<<"(1 for yes, 0 for no): ";
	cin>>flag;
	cin.get();
	x++;
	}while(flag);
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
	};
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
	double HStep2,HSStep2,dis,dis2,dy;
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
*Function: hcalc
*This function takes rate,hour,pay,overtime hour, overtime pay, total and number of employees
*Input:None
*Output: None
*Parameter:rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Output Parameter: rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Return:None
********************************************************************/
void hcalc(Drill drill[],int x)
{
	int j=0;
	for (j=0;j<(x);j++)
	{
	drill[j].HStep/=2;
	drill[j].HSStep/=2;
	drill[j].HStep+=drill[j].Steps;
	drill[j].HSStep+=drill[j].SSteps;
	drill[j].HYD=static_cast<int>(drill[j].HStep)/8*5;
	if(drill[j].HYD>50 && drill[j].SD==1)
	{
		drill[j].HYD=abs(drill[j].HYD-100);
		drill[j].WHSD="SD:2";
	}
	else if(drill[j].HYD>50 && drill[j].SD==2)
	{
		drill[j].HYD=abs(drill[j].HYD-100);
		drill[j].WHSD="SD:2";
	}
	else if (drill[j].HYD<50 && drill[j].SD==2)
	{
		drill[j].WHSD="SD:1";
	}
	else if (drill[j].HYD<50 && drill[j].SD==1)
	{
		drill[j].WHSD="SD:1";
	}
	drill[j].HS2S=static_cast<int>(drill[j].HStep) % 5;
	if (drill[j].HS2S>4)
	{
		drill[j].HS2S-=4;
		drill[j].HYD+=5;
		drill[j].WHIO="OT";
	}
	else
	{
		drill[j].WHIO="IN";
	}
	if(drill[j].HSStep<=16)
	{
		drill[j].WHHash="FSL";
		drill[j].HFB=drill[j].HSStep;
		drill[j].WHFB="BD";
		
	}
	else if(drill[j].HSStep<=16)
	{
		drill[j].WHHash="FSL";
		drill[j].HFB=0;
		drill[j].WHFB="ON";
		
	}
	else if(drill[j].HSStep=FH)
	{
		drill[j].WHHash="FH";
		drill[j].HFB=0;
		drill[j].WHFB="BD";
		
	}
	else if (drill[j].HSStep>16 && drill[j].HSStep<42)
	{
		drill[j].WHHash="FH";
		if(drill[j].HSStep<FH)
		{
		drill[j].HFB=drill[j].HSStep-16;
		drill[j].WHFB="FT";
		}
		else 
		{
		drill[j].HFB=drill[j].HSStep-FH;
		drill[j].WHFB="BD";
		}
	}
	else if(drill[j].HSStep=BH)
	{
		drill[j].WHHash="BH";
		drill[j].HFB=0;
		drill[j].WHFB="BD";
	}
	else if (drill[j].HSStep>=42 && drill[j].HSStep<68)
	{
		drill[j].WHHash="BH";
		drill[j].HSStep;
		if(drill[j].HSStep<BH)
		{
		drill[j].HFB=drill[j].HSStep-42;
		drill[j].WHFB="FT";
		}
		else 
		{
		drill[j].HFB=drill[j].HSStep-BH;
		drill[j].WHFB="BD";
		}

	}
	else if (drill[j].HSStep>=68 && drill[j].HSStep<84)
	{
		drill[j].WHHash="BSL";
		drill[j].HFB=drill[j].HSStep-68;
		drill[j].WHFB="FT";
	}
	else if(drill[j].HSStep=84)
	{
		drill[j].WHHash="BSL";
		drill[j].HFB=0;
		drill[j].WHFB="on";
		
	}
		if(drill[j].YD>50)
		{
			drill[j].YD=abs(drill[j].YD-100);
		}
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
				//cout<<drill[j].WIO<<endl;
				outputfile<<"Set: "<<setw(3)<<drill[j].set;
				outputfile<<"  Cts: "<<setw(3)<<drill[j].count<<endl;
				outputfile<<abs(drill[j].S2S)<<" Stps "<<drill[j].WIO<<" "<<drill[j].WSD<<" "<<drill[j].YD<<" YD"<<endl;
				outputfile<<drill[j].SFB<<" Stps "<<drill[j].WFB<<" "<<drill[j].WHash<<endl;
				if (j<(x-1))
				{
				outputfile<<abs(drill[j].HS2S)<<" Stps "<<drill[j].WHIO<<" "<<drill[j].WHSD<<" "<<drill[j].HYD<<" YD"<<endl;
				outputfile<<drill[j].HFB<<" Stps "<<drill[j].WHFB<<" "<<drill[j].WHHash<<endl;
				}
				outputfile<<"\n\n\n\n\n\n";
				cout<<"Set: "<<setw(3)<<drill[j].set;
				cout<<"  Cts: "<<setw(3)<<drill[j].count<<endl;
				cout<<abs(drill[j].S2S)<<" Stps "<<drill[j].WIO<<" "<<drill[j].WSD<<" "<<drill[j].YD<<" YD"<<endl;
				cout<<drill[j].SFB<<" Stps "<<drill[j].WFB<<" "<<drill[j].WHash<<endl;
				if (drill[j].StepSize>0 && drill[j].StepSize<6)
				{
				//cout<<drill[j].StepSize<<endl;
				}
				if (j<(x-1))
				{
					cout<<abs(drill[j].HS2S)<<" Stps "<<drill[j].WHIO<<" "<<drill[j].WHSD<<" "<<drill[j].HYD<<" YD"<<endl;
					cout<<drill[j].HFB<<" Stps "<<drill[j].WHFB<<" "<<drill[j].WHHash<<endl;
				}
				cout<<"\n";
			}
		}
	cout<<"\n\nCorrdinates written to Corrdinates.txt\n\n";
	flag=0;	
	}while(flag);
}
/*******************************************************************
*Function: switch0
*This function takes rate,hour,pay,overtime hour, overtime pay, total and number of employees
*Input:None
*Output: None
*Parameter:rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Output Parameter: rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Return:None
********************************************************************/
string switch0(Drill drill)
{
	string WFB;
		switch(drill.FB)
		{
			case 0: 
				WFB="On"; 
				break;
			case 1:
				WFB="FT"; 
				break;
			case 2:
				WFB="BD"; 
				break;
		}
	return WFB;
}
/*******************************************************************
*Function: switch1
*This function takes rate,hour,pay,overtime hour, overtime pay, total and number of employees
*Input:None
*Output: None
*Parameter:rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Output Parameter: rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Return:None
********************************************************************/
string switch1(Drill drill)
{
	string WIO;
		switch(drill.IO)
			{
			case 0: 
				WIO="On"; 
				break;
			case 1:
				WIO="IN"; 
				break;
			case 2:
				WIO="OT"; 
				break;
			}
		return WIO;
}
/*******************************************************************
*Function: switch1
*This function takes rate,hour,pay,overtime hour, overtime pay, total and number of employees
*Input:None
*Output: None
*Parameter:rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Output Parameter: rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Return:None
********************************************************************/
string switch2(Drill drill)
{
	string WHash;
		switch(drill.Hash)
			{
			case 1: 
				WHash="FSL"; 
				break;
			case 2:
				WHash="FH"; 
				break;
			case 3:
				WHash="BH"; 
				break;
			case 4:
				WHash="BSL"; 
				break;
			}
	return WHash;
}
/*******************************************************************
*Function: switch3
*This function takes rate,hour,pay,overtime hour, overtime pay, total and number of employees
*Input:None
*Output: None
*Parameter:rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Output Parameter: rate, hours, pat, overtime hour, overtime pay, total and # of employee's
*Return:None
********************************************************************/
string switch3(Drill drill)
{
	string WSD;	
		switch(drill.SD)
		{
			case 1:
				WSD="SD:1"; 
				break;
			case 2:
				WSD="SD:2"; 
				break;
		}
	return WSD;
}
/*******************************************************************
*Function: Ainput
*This function prints to file all the data accumulated
*Input:from file
*Output: writes to arrays
*Parameter:firstname,lastname,employee ID,rate, hours
*Return: number of employees
********************************************************************/
int Ainput (Drill drill [])
{
	ifstream inputfile;
	int x=0;	//counter
	//Checking file open
	inputfile.open("dots.txt");
		if (inputfile.fail())
		{
			cout<<"Error opening file dots.txt\n\n";
			cout<<"Ending Program\n\n";
			x= 0;
		}
		else
		{
			//begins reading File
			cout<<"\nInput file (dots.txt) open and reading data\n";
			while (inputfile>>(drill[x].set)&& x<SIZE)			//There is a line of data to read
			{
				//Input
				inputfile >> drill[x].count;
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