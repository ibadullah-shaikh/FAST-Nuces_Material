#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int day,month,year,hour,mint,sec;
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	day=local_time->tm_mday;
	month=1+local_time->tm_mon;
	year=1900+local_time->tm_year;
	hour=0+local_time->tm_hour;
	mint=0+local_time->tm_min;
	sec=0+local_time->tm_sec;
	cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl;
	cout<<"Time: "<<hour<<":"<<mint<<":"<<sec<<endl;
}

