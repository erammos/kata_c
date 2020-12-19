#include <stdio.h>
#include <stdlib.h>
struct _retire_info
{
int months;
double contribution;
double rate_of_return;
};

typedef struct _retire_info retire_info;

double  calc_balance(retire_info info,int startAge, double initial)
{

 double balance = initial;
 int months = startAge;
 for(int i = 0; i< info.months; i++)
{
   int  years = months / 12;
   int  month = months % 12;
   printf( "Age %3d month %2d you have $%.2lf\n", years,month,balance);
  balance = balance * (1.0f + info.rate_of_return) + info.contribution;
  months++;
}
return balance;

}
 void retirement (int startAge,   //in months
                       double initial, //initial savings in dollars
                       retire_info working, //info about working
                       retire_info retired) //info about being retired
{

double balance = calc_balance(working,startAge,initial);
calc_balance(retired,startAge + working.months,balance);
}

int main()
{
/* Working:
     --------
      Months: 489
      Per Month Savings: $1000
      Rate of Return:  4.5% per year ( 0.045/12 per month) 
                       [above inflation]
    Retired:
    --------
      Months: 384
      Per Month Spending: -4000
      Rate of Return: 1% per year ( 0.01/12 per month) 
                      [above inflation]
    Starting conditions:
    -------------------
       Age: 327 months (27 years, 3 months)
       Savings: $21,345*/

  retire_info working;
  working.months = 489;
  working.contribution = 1000.0;
  working.rate_of_return = 0.045/ (float)12;

  retire_info retired; 
  retired.months = 384;
  retired.contribution = -4000.0;
  retired.rate_of_return = 0.01/ (float)12;
 

 retirement(327,21345.0,working,retired);
 
 return 0;
}
