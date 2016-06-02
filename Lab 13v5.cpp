/********************************************************************************************************
*Erwin Seguinte			October 24,2013					Lab 13v1.cpp									*
*This program ouput real estate commissions																*
*Input: start, id, price, category																		*
*Output: comm, tres, tcom, tapt, trescom, tcomcom, taptcom, total,tcomm	, great, least, avg				*
******************************* History *****************************************************************
*	Who				Date		Description																*
*********************************************************************************************************
*	ES				10/24/2013	Created Program															*
*	ES				10/31/2013	Included Arrays and Validation											*
*	ES				11/07/2013	Included Parallel Arrays												*
*	ES				11/19/2013	Included Functions														*
*	ES				12/03/2013	Included I/O
*******************************************************************************************************/
#include <iostream>
#include <iomanip> 
#include <fstream>
#define RCOM .10
#define CCOM .20
#define	ACOM .15
#define SIZE 50
	using namespace std;
double Gcomm (double, double);
		
int main ()
{
	char category[SIZE],
		temp3;
	int start=1,
		id[SIZE],
		tres=0,
		tcom=0,
		tapt=0,
		i=0,
		x=0,
		temp2,
		num=0,
		tcomm=0,
		last,
		exch;
	double sale[SIZE],
		comm [SIZE],
		temp1,
		temp4,
		tcomcom=0,
		trescom=0,
		taptcom=0,
		total=0,
		avg=0,
		great=0,
		least,
		mean=0;
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	output<<fixed<<setprecision(2);
	cout<<fixed<<setprecision(2);
cout<< "Seguinte's Commission Computer\n";	
	if(!input.is_open() || !output.is_open())
	{
		cout<<"\nUnable to open.\n";
	}
	else
	{
		while (!input.eof())
		{
			input >> id[i] >> category [i] >> sale[i];
			i++;
			x++;
		}
		for (i=0;i<(x);i++)
		{
			switch (category[i]) 
			{
			case 'R':
			case 'r':
				comm [i] = Gcomm (sale[i], RCOM);
				output<< "\nThe commission for this sale for Agent " <<id[i]<< " is: " <<setw(10)<<comm [i];
				trescom = trescom + comm [i];
				tres++;
				break;
			case 'C':
			case 'c':
				comm [i] = Gcomm (sale[i], CCOM);
				output<< "\nThe commission for this sale for Agent " <<id[i]<< " is: " <<setw(10)<<comm [i];
				tcomcom = tcomcom + comm [i];
				tcom++;
				break;
			case 'A':
			case 'a':
				comm [i] = Gcomm (sale[i], ACOM);
				output<< "\nThe commission for this sale for Agent " <<id[i]<< " is: " <<setw(10)<<comm [i];
				taptcom = taptcom + comm [i];
				tapt++;
				break;
			}
		}
		num = --x;
		for (x=0;x<(num); x++)
		{
			avg += comm[x];
			mean = avg/num;
		}
		for (x=0;x<(num); x++)
		{
			if (comm[x]>great)
				great = comm[x];
			else 
				great = great;
		}
		least = great;
		for (x=0;x<(num); x++)
		{ 
			if (comm[x]<least)
				least = comm[x];
			else 
				least = least;
		}
		last = num-2;
		num--;
		total = trescom + tcomcom + taptcom;
		tcomm= tapt+tcom+tres;
		output<<"\n**********End Of Run Report**********\n";
		output<< "Total number of Residential Commissions computed:        " <<setw(6)<<tres;
		output<< "\n";
		output<< "Total number of Commercial Commissions computed:         " <<setw(6)<<tcom;
		output<< "\n";
		output<< "Total number of Apartment Building Commissions computed: " <<setw(6)<<tapt;
		output<< "\n";
		output<< "Total number of Commissions computed:                    " <<setw(6)<<tcomm;
		output<< "\n\n";
		output<< "Total amount of Residential Commissions computed:       $" <<setw(15)<<trescom;
		output<< "\n";
		output<< "Total amount of Commercial Commissions computed:        $" <<setw(15)<<tcomcom;
		output<< "\n";
		output<< "Total amount of Apartment Building Commissions computed:$" <<setw(15)<<taptcom;
		output<< "\n";
		output<< "Total amount of all commissions computed:               $" <<setw(15)<<total;
		output<< "\n";
		output<<"\nThe Average Commission is:       $"<<setw(15)<< mean << "\nThe Greatest Commission is:      $" <<setw(15)<<great<< "\nThe Least Greatest Commssion is: $" <<setw(15)<<least;
		output<<"\n\nBefore Sorting: ";
	cout<< num;
		for (x=0; x<num; x++)
	{
		output<< "\n"<< id[x]<<setw(3)<<category[x] <<setw(15)<<sale[x] <<setw(15)<<comm[x];
	}
	do
	{
		exch = 0;
		for (i=0;i<last;i++)
		{
			if(comm[i] > comm[i+1])
			{
				temp1 = comm[i];
				comm[i] = comm[i+1];
				comm[i+1] = temp1;
				temp2 = id[i];
				id[i] =id[i+1];
				id[i+1] = temp2;
				temp3 = category[i];
				category[i] = category[i+1];
				category[i+1] = temp3;
				temp4 = sale[i];
				sale[i] = sale[i+1];
				sale[i+1] = temp4;
				exch =1;
			}
		}
		last--;
	}while ((last > 0) && (exch==1));
	output<< "\nAfter Sorting: ";
	for (x=0; x<num; x++)
	{
		output<< "\n"<< id[x]<<setw(3)<<category[x] <<setw(15)<<sale[x] <<setw(15)<<comm[x];
	}
	output<< "\n";
	return 0;
	}
}
/************************************************************************************************
*	Function: Gcomm																				*
*	This function calculate commision value														*
*	Input Parameter: sale, RCOM, CCOM, ACOM														*
*	Returns: comm																				*
************************************************************************************************/
double Gcomm (double sale, double rate)
{
	sale*= rate;
	return sale;
}