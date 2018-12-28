#include <iostream>
using namespace std;
//There is no hard coding and the program works for all input values.
//It converts the even inputs into odd values by adding 1 
//to them because flower with corners can only be produced by odd values.
int main()
{
	int height=0, width=0; //arguements to be input by user
	int master=1, i=1, j=1, k=1, l=1; // all these are loop control variables
	int left=0, right=0; // controls the printing stars in upper and lower triangles by limiting the printing range
	int leftcen=0, rightcen=0; // controls the printing stars in right and left triangles by limiting the printing range
	int limit=0; //controls the end point of the inner servent loop
	cout<<"Please input the height of the central rectangle."<<endl;
	cin>>height;
	cout<<"Please input the width of the central rectangle."<<endl;
	cin>>width;
	//convert even values into odd
	if(width%2==0)
	{
		width++;
	}
	if(height%2==0)
	{
		height++;
	}
	//initialization of all limits
	left=(width/2)+1; 
	right=left;
	leftcen=(height/2)+1;
	rightcen=1;
	while(master<=3) //master loop, divides the printing in three parts: upper, middle and lower
	{
		i=0;
		if(master==2)
		{
			limit=height; //because the left and right triangles are a function of the height of rectangle
		}
		else
		{
			limit=(width/2)+1; //because the upper and lower triangles depend on the width of rectangle
		}
		while(i<limit) //servent loop, mainly changes rows by incrementing
		{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			j=1; 
			while(j<=(height/2)+1) //slave loop 1, controls the left side of all three parts
			{
				if(master==1 || master==3)
				{	
					cout<<"  ";
				}
				else
				{
					if(j>=leftcen)
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				j++;
			}
			cout<<"  ";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			k=1;
			while(k<=width) // slave loop 2, controls the middle side of all three parts
			{
				if(k>=left && k<=right)
				{
					cout<<"*";
				}
				else
				{
					cout<<" ";
				}
				k++;
			}
			cout<<"  ";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			l=1;
			while(l<=(height/2)+1) // slave loop 3, controls the right side of all three parts
			{
				if(master==1 || master==3)
				{	
					cout<<"  ";
				}
				else
				{
					if(l<=rightcen)
					{
						cout<<" *";
					}
					else
					{
						cout<<"  ";
					}
				}
				l++;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////this portion controls all the limits of all four triangles/////////////////////
			if(master==1)
			{
				left--;
				right++;
			}
			else if(master==3)
			{
				left++;
				right--;
			}
			else
			{
				if(i<limit/2) //because length of triangle increases till the middle of base and then starts decreasing
				{
					leftcen--;
					rightcen++;
				}
				else
				{
					leftcen++;
					rightcen--;
				}
			}
			cout<<endl;
			i++;
		}
		if(master==2) //this is done to contract the width of rectangle so that it becomes equal to original value(since the width was extended by 1 when master was equal to 1)
		{
			left++;
			right--;
		}
		cout<<endl<<endl;
		master++;
	}
	//system ("pause");
	return 0;
}
