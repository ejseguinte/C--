
/*
 *Filename: VanDerWaal.cpp
 *Name: E Seguinte
 *Company: Sacramento City College
 *Data: March 03, 2014
 *This program computes non ideal gas problems
 *History
 *Date		Initials		Action
 *=============================================
 *03/03/2014	ES			Wrote Program/Compiled
 * 
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <math.h>
#include <fstream>
#define SIZE 1000
#define R .08205
double round(double);
double temp(double);
	using namespace std;
int main ()
{
	int x,flag;
	int y;
	double t,p,a,b,v;
	double m[SIZE];
	ofstream output;
	string name;
	output.open("hwk.rtf");
	cout<<fixed<<setprecision(3);
	cout<<"This program computes non ideal gas problems"<<endl; 
	//Input
	do{
	cout<<"Enter name of compound:"<<endl;
	getline(cin,name);
	cout<<"Enter pressure:"<<endl;
	cin>>p;
	cout<<"Enter Boiling Point:(in Celsius)"<<endl;
	cin>>t;
	cout<<"Enter Volume:"<<endl;	
	cin>>v;
	cout<<"Enter A value:"<<endl;	
	cin>>a;
	cout<<"Enter B value:"<<endl;	
	cin>>b;
	//Processing
	t=temp(t);
	x=0;
	m[x]=(p*v)/(R*t);
	do{
		x++;
		m[x]=((p+a*(pow((m[x-1]/a),2)))*(v-m[x-1]*b))/(R*t);
		m[x]=round(m[x]);
		if (x >= SIZE)
		{
		cout<< "\nProgram is ending, too many N values. Please wait for printout and re-start\nprogram.\n";
		m[x]=m[x-1];
		}
		cout<<"n= "<<m[x-1]<<endl;
	}while(m[x]!=m[x-1]);
	//Output
	output<<fixed<<setprecision(3);
	output<<"For the compound: "<<name<<endl;
	output<<"Pressure: "<<p<<endl;
	output<<"Boiling point + 200C (in K): "<<t<<endl;
	output<<"Volume: "<<v<<endl;
	output<<"A value: "<<a<<endl;
	output<<"B value: "<<b<<endl;
		for(y=0;y<x+1;y++)
		{
			if (y==0)
			{
			output<<"Ideal Gas Law";
			output<<"\n\t\t["<<p<<"]["<<v<<"]"<<endl;
			output<<left<<setw(7)<<m[y]<<"= ---------------------"<<endl;
			output<<"\t\t("<<R<<")("<<t<<")\n"<<endl;
			}
			else
			{
			output<<"Van Der Waal Equation: "<<y;
			output<<"\nInitial Moles="<<m[y-1]<<endl;
			output<<"\n\t\t["<<p<<"+"<<a<<"("<<m[y-1]<<"/"<<a<<")^2]["<<v<<"-"<<m[y-1]<<"("<<b<<")]"<<endl;
			output<<left<<setw(7)<<m[y]<<"= ----------------------------------------------------------------"<<endl;
			output<<"\t\t\t\t("<<R<<")("<<t<<")"<<endl;
			}
		}
		output<<"n= "<<m[x-1]<<endl;
	cout<<"Is there another chemical? (1 for yes,0 for no):";
	cin>>flag;
	cin.get();
	}while(flag==1);
	return 0; 
}
/*******************************************************************
*Function: round
*This function rounds values to 3 decimal places
*Input: a demical number
*Output: a decimal number rounded
*Parameter: double
*Return: rounded number
********************************************************************/
double round(double m)
{
		m*=100;
		m=floor(0.5+m);
		m/=100;
		return m;
}
/*******************************************************************
*Function: temp
*This function rounds values to 3 decimal places
*Input: a demical number
*Output: a decimal number rounded
*Parameter: double
*Return: rounded number
********************************************************************/
double temp(double t)
{
		t+=473.15;
		return t;
}