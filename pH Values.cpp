
/*
 *Filename: pH Values.cpp
 *Name: E Seguinte
 *Company: Sacramento City College
 *Data: Febuary 28, 2014
 *This program takes mL values of HCl and NaOh and calculates pH
 *History
 *Date		Initials		Action
 *=============================================
 *02/28/2014	ES			Wrote Program/Compiled
 * 
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#define KW 1.0*(pow(10,-14))
#define MHCL .01
#define MNAOH .250
#define HCL .050
	using namespace std;
int main ()
{
	int x;
	double ph,naoh,lnaoh,mol,molh,l,h,kwh;
	cout<<"This program takes mL values of HCl and NaOh and calculates pH"<<endl;
	//Input
do{
	cout<<"Enter the amount of NaOh in mL: ";
	cin>>naoh;
	//Processing
	lnaoh=naoh/1000;
	mol=lnaoh*MNAOH;
	l=HCL+lnaoh;
	if (mol<MHCL)
	{
		molh=MHCL-mol;
		h=molh/l;
		ph=-log10(h);
		cout<<fixed<<setprecision(4);
		cout<<"\nMoles of HCL left: "<<endl;
		cout<<" "<<MHCL<<"\n-"<<mol<<"\n---------\n "<<molh<<endl;
		cout<<"\nNew molarity of HCL: "<<endl;
		cout<<molh<<"\n------ = "<<h<<"\n"<<l<<endl;
		cout<<fixed<<setprecision(2);
		cout<<"\nThis pH is "<<ph<<endl;
		cout<<"The amount of NaOh used is: "<<naoh<<endl;
	}
	else
	{
		molh=mol-MHCL;
		h=molh/l;
		kwh=KW/h;
		ph=-log10(kwh);
		cout<<fixed<<setprecision(4);
		cout<<"\nMoles of NaOH left: "<<endl;
		cout<<" "<<mol<<"\n-"<<MHCL<<"\n---------\n "<<molh<<endl;
		cout<<"\nNew molarity of NaOH: "<<endl;
		cout<<" "<<molh<<"\n------ = "<<h<<"\n "<<l<<endl;
		cout<<fixed<<setprecision(15);
		cout<<"\nHydrogen concentration: "<<endl;
		cout<<" "<<KW<<"\n------ = "<<kwh<<"\n "<<h<<endl;
		cout<<fixed<<setprecision(2);
		cout<<"\nThe pH is "<<ph<<endl;
		cout<<"The amount of NaOh used is: "<<naoh<<endl;
	}
	cout<<"Is there a another pH calculation? (yes = 1, no = 0)"<<endl;
	cin>>x;
	while (x!=1 && x!=0)
	{
		cout<<"Value enter is neither a 1 or a 0"<<endl;
		cout<<"Is there a another pH calculation? (yes = 1, no = 0)"<<endl;
		cin>>x;
	}
}while(x==1);
	//Output
	return 0; 
}