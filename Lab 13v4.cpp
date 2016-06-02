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
*******************************************************************************************************/
#include <iostream>
#include <iomanip> 
#define RCOM .10
#define CCOM .20
#define	ACOM .15
#define SIZE 50
	using namespace std;
void Dashes (void);
void Print (double, double, double);
int Vid	();
char Vcategory	();
double Vsale ();
int Vstart ();
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
		x,
		temp2,
		num=0,
		tcomm,
		last,
		exch;
	double sale[SIZE],
		comm [SIZE],
		temp1,
		temp4,
		tcomcom=0,
		trescom=0,
		taptcom=0,
		total,
		avg=0,
		great=0,
		least,
		mean=0;
	cout<<fixed<<setprecision(2);
	cout<< "Seguinte's Commission Computer";
	while (Vstart () == 1)
	{
		Dashes ();
		id[i]= Vid() ;
		category[i]= Vcategory ();
		sale[i]= Vsale ();
		switch (category[i]) 
		{
		case 'R':
		case 'r':
			comm [i] = Gcomm (sale[i], RCOM);
			cout<< "The commission for this sale for Agent " <<id[i]<< " is: " <<setw(10)<<comm [i];
			trescom = trescom + comm [i];
			tres++;
			i++;
			break;
		case 'C':
		case 'c':
			comm [i] = Gcomm (sale[i], CCOM);
			cout<< "The commission for this sale for Agent " <<id[i]<< " is: " <<setw(10)<<comm [i];
			tcomcom = tcomcom + comm [i];
			tcom++;
			i++;
			break;
		case 'A':
		case 'a':
			comm [i] = Gcomm (sale[i], ACOM);
			cout<< "The commission for this sale for Agent " <<id[i]<< " is: " <<setw(10)<<comm [i];
			taptcom = taptcom + comm [i];
			tapt++;
			i++;
			break;
		}
		if (i >= SIZE)
		{
		cout<< "\nProgram is ending, too many commissions. Please wait for printout and re-start program.\n";
		start = 0;
		}
	}
	num = i;
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
	last = num-1;
	total = trescom + tcomcom + taptcom;
	tcomm= tapt+tcom+tres;
	cout<<"\n**********End Of Run Report**********\n";
	cout<< "Total number of Residential Commissions computed:        " <<setw(6)<<tres;
	cout<< "\n";
	cout<< "Total number of Commercial Commissions computed:         " <<setw(6)<<tcom;
	cout<< "\n";
	cout<< "Total number of Apartment Building Commissions computed: " <<setw(6)<<tapt;
	cout<< "\n";
	cout<< "Total number of Commissions computed:                    " <<setw(6)<<tcomm;
	cout<< "\n\n";
	cout<< "Total amount of Residential Commissions computed:       $" <<setw(15)<<trescom;
	cout<< "\n";
	cout<< "Total amount of Commercial Commissions computed:        $" <<setw(15)<<tcomcom;
	cout<< "\n";
	cout<< "Total amount of Apartment Building Commissions computed:$" <<setw(15)<<taptcom;
	cout<< "\n";
	cout<< "Total amount of all commissions computed:               $" <<setw(15)<<total;
	cout<< "\n";
	Print (mean,great,least);
	cout<< "\n\nBefore Sorting: ";
	for (x=0; x<num; x++)
	{
		cout<< "\n"<< id[x]<<setw(3)<<category[x] <<setw(15)<<sale[x] <<setw(15)<<comm[x];
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
	cout<< "\nAfter Sorting: ";
	for (x=0; x<num; x++)
	{
		cout<< "\n"<< id[x]<<setw(3)<<category[x] <<setw(15)<<sale[x] <<setw(15)<<comm[x];
	}
	cout<< "\n";
	return 0;
}
/************************************************************************************************
*	Function: Dashes																				*
*	This function prints a number of dashed lines onto the screen.								*
*	Input Parameter: Nothing																	*
*	Returns: Nothing																			*
************************************************************************************************/
void Dashes (void)
{
	cout<<"________________________________________________________________________________";
	return;
}
/************************************************************************************************
*	Function: Print																				*
*	This function prints the values of mean, great and least									*
*	Input Parameter: mean, great, least															*
*	Returns: Nothing																			*
************************************************************************************************/
void Print (double tmean,double tgreat,double tleast)
{
	cout<<"\nThe Average Commission is:       $"<<setw(15)<< tmean << "\nThe Greatest Commission is:      $" <<setw(15)<<tgreat<< "\nThe Least Greatest Commssion is: $" <<setw(15)<<tleast;
	return ;
}
/************************************************************************************************
*	Function: Vid																				*
*	This function validates the agent id														*
*	Input Parameter: id																			*
*	Returns: id																					*
************************************************************************************************/
int Vid	()
{
	int id;
	cout<< "\nPlease Enter Agent ID: ";
	cin>> id;
	while ((id < 10000)||(id >99999))
		{
			cout<< "\nError: Agent ID is not between 10000 and 99999.";
			cout<< "\nPlease re-enter Agent ID: ";
			cin>> id;
		}
	return id;
}
/************************************************************************************************
*	Function: Vcategory																			*
*	This function validates the category														*
*	Input Parameter: category																	*
*	Returns: category																			*
************************************************************************************************/
char Vcategory	()
{
	char category;
	cout<< "\nPlease enter type of property sold\n ";
	cout<< "(R = Residential, C = Commercial, A = Aprtment Building: ";
	cin>> category;
	while (((category != 'r') && (category != 'R')) && ((category != 'C') && (category != 'c')) && ((category != 'a') && (category != 'A')))
		{
			cout<< "\nError: Chosen category does not exist.";
			cout<< "\nPlease re-enter type of property sold\n ";
			cout<< "(R = Residential, C = Commercial, A = Aprtment Building: ";
			cin>> category;
		}
	return category;
}
/************************************************************************************************
*	Function: Vsale																				*
*	This function validates the selling price													*
*	Input Parameter: sale																		*
*	Returns: sale																				*
************************************************************************************************/
double Vsale ()
{
	double sale;
	cout<< "\nPlease enter selling price: "; 
	cin>> sale;
	while (sale <= 0)
		{
			cout<< "\nError: Value entered is not greater than 0.";
			cout<< "\nPlease re-enter Selling Price: ";
			cin>> sale;
		}
	return sale;
}
/************************************************************************************************
*	Function: Vstart																			*
*	This function validates the users answer													*
*	Input Parameter: start																		*
*	Returns: tstart																				*
************************************************************************************************/
int Vstart ()
{
	int tstart;
	cout<< "\nDo you have a commision to compute? (1=Yes, 0=No): "; 
	cin>> tstart;
	while ((tstart != 1) && (tstart != 0))
	{
		cout<< "\nError: Value entered is neither a 1 or a 0.";
		cout<< "\nPlease re-enter selection (1=Yes, 0=No): ";
		cin>> tstart;
	}
	return tstart;
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