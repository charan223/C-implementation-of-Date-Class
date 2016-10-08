#include "C:\Users\CHARAN\Desktop\C_Files\assignment.h"
using namespace std;

//DATE CLASS MEMBERS AND CONSTRUCTORS

Date::Date(Day d,Month m,Year y) throw(invalid_argument,domain_error,out_of_range)
{
    day=d;
    month=m;
    year=y;

    if(month>12||month<1) throw invalid_argument("invalid arguments\t");
    else
    {
        if(month==1||month==3||month==5||month==12||month==7||month==8||month==10)
        {
            if(day>31||day<1) throw domain_error("domain errors\t");
        }
        else if(month==4||month==6||month==9||month==11)
        {
            if(day>30||day<1) throw domain_error("domain errors\t");
        }
        else
        {
            if(leap(year)==true)
            {
                if(day>29||day<1) throw domain_error("domain errors\t");
            }
            else
            {
                if(day>28||day<1) throw domain_error("domain errors\t");
            }
        }
    }

    //out of range check
    if(year>2049||year<1950) throw out_of_range("out of range error\t");



}


Date::Date(const char* date) throw(invalid_argument, domain_error, out_of_range)
{
    DateFormat charan(date);
    int da,mn,ye;
    da=atoi(charan.getdate());
    mn=atoi(charan.getmonth());
    ye=atoi(charan.getyear());

    if(mn>12||mn<1) throw invalid_argument("invalid arguments\t");
    else
    {
        if(mn==1||mn==3||mn==5||mn==12||mn==7||mn==8||mn==10)
        {
            if(da>31||da<1) throw domain_error("domain errors\t");
        }
        else if(mn==4||mn==6||mn==9||mn==11)
        {
            if(da>30||da<1) throw domain_error("domain errors\t");
        }
        else
        {
            if(leap(ye)==true)
            {
                if(da>29||da<1) throw domain_error("domain errors\t");
            }
            else
            {
                if(da>28||da<1) throw domain_error("domain errors\t");
            }
        }
    }

    //out of range check
    if(ye>2049||ye<1950) throw out_of_range("out of range error\t");

    this->day=da;
    this->month=mn;
    this->year=ye;
}
Date::Date() throw(invalid_argument, domain_error, out_of_range)
{
    time_t t=time(0);
    struct tm*a=localtime(&t);
    *this=Date((Day)(a->tm_mday),(Month)(a->tm_mon+1),(Year)(a->tm_year+1900));
}

Date::Date(const Date&date1)
{
    this->day=date1.day;
    this->month=date1.month;
    this->year=date1.year;
}

Date::~Date()
{

}


Date& Date::operator=(const Date&newdate)
{
    if(*this!=newdate)
    {
        day=newdate.day;
        month=newdate.month;
        year=newdate.year;
    }
    return *this;
}

//displays next day
Date& Date:: operator++()
{
    if(month==12)
    {
        if(day==31)
        {
            day=1;
            month=1;
            year++;
        }
        else day++;
    }
    else if(month==2)
    {
        if(leap(year)==true)
        {
            if(day==29)
            {
                day=1;
                month++;
            }
            else
            {
                day++;
            }
        }
        else
        {
            if(day==28)
            {
                day=1;
                month++;
            }
            else
            {
                day++;
            }
        }
    }

    else if(month==1|month==3|month==5|month==7|month==8|month==10)
    {
        if(day==31)
        {
            day=1;
            month++;
        }
        else
        {
            day++;
        }
    }
    else
    {
        if(day==30)
        {
            day=1;
            month++;
        }
        else
        {
            day++;
        }
    }

    return *this;
}

//postfix++ operator displays same day of next week
Date& Date:: operator++(int)
{
    if(month==12)
    {
        day=(day+7)%31;
        if((day+7)/31==1)
        {
            month=1;
            year++;
        }

    }
    else if(month==2)
    {
        if(leap(year)==true)
        {
            day=(day+7)%29;
            if((day+7)/29==1)
            {
                month++;
            }
        }
        else
        {
            day=(day+7)%28;
            if((day+7)/28==1)
            {
                month++;
            }
        }
    }

    else if(month==1|month==3|month==5|month==7|month==8|month==10)
    {
        day=(day+7)%31;
        if((day+7)/31==1)
        {
            month++;
        }
    }
    else
    {
        day=(day+7)%30;
        if((day+7)/30==1)
        {
            month++;
        }
    }
    return *this;
}

Date& Date:: operator--()
{
    if(month==1)
    {
        if(1<day<=31) day--;
        else
        {
            day=31;
            year--;
            month=12;
        }
    }
    else if(month==2|month==4|month==6|month==8|month==9|month==11)
    {
        if(1<day<=30) day--;
        else
        {
            day=31;
            month--;
        }
    }
    else if(month==3)
    {
        if(1<day<=31) day--;
        else
        {
            if(leap(year)==true)
            {
                day=29;
                month--;
            }
            else
            {
                day=28;
                month--;
            }
        }
    }
    else
    {
        if(1<day<=31) day--;
        else
        {
            day=30;
            month--;
        }
    }

    return *this;
}
Date& Date::operator--(int)
{
    if(month==1)
    {
        if(7<day<=31) day=day-7;
        else
        {
            day=24+day;
            year--;
            month=12;
        }
    }
    else if(month==2|month==4|month==6|month==8|month==9|month==11)
    {
        if(7<day<=30) day=day-7;
        else
        {
            day=24+day;
            month--;
        }
    }
    else if(month==3)
    {
        if(7<day<=31) day=day-7;
        else
        {
            if(leap(year)==true)
            {
                day=22+day;
                month--;
            }
            else
            {
                day=21+day;
                month--;
            }
        }
    }

    else
    {
        if(7<day<=31) day=day-7;
        else
        {
            day=23+day;
            month--;
        }
    }
    return *this;
}


const int Date:: monthDays[12] = {31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31
                                 };


// This function counts number of leap years before the
// given date
int Date:: countLeapYears(const Date& d)
{
    unsigned int years = d.year;

    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.month <= 2)
        years--;

    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}

unsigned int Date :: operator-(const Date& dt1)
{
// COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
//cout<<endl<<(*this)<<endl<<dt1;
    // initialize count using years and day
    long int n1 = (dt1.year-1950)*365 + dt1.day;

    // Add days for months in given date
    for (int i=0; i<dt1.month - 1; i++)
        n1 =n1+ monthDays[i];


    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

        cout<<n1<<endl;
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

    long int n2 = (this->year-1950)*365 + this->day;
    for (int i=0; i<this->month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(*this);

        cout<<n2<<endl;
    // return difference between two counts
    if(n2>n1)
        return (unsigned int)(n2 - n1);
    else return (unsigned int)(n1-n2);
} // Number of days between otherDate and current date


Date Date::operator+(int noOfDays)  throw(domain_error,out_of_range)
{
    Date temp(Day(this->day),Month(this->month),Year(this->year));
    if(noOfDays>0)
    {
        while(noOfDays--)
            ++(temp);
    }

    else if(noOfDays<0)
    {
        while(noOfDays++)
            --(temp);
    }
    return temp;
} // Day noOfDays after (before) the current date
// (sign of noOfDays decides ahead or behind)

// CAST OPERATORS
Date::operator WeekNumber() const
{
    Date qwer(D01,Jan,(Year)this->year);
   if((WeekDay)qwer<=Thr){
        int count=(int)(WeekDay)qwer;
         count+=this->day;
        for(int i=0;i<this->month-1;i++)
            count+=monthDays[i];
        count+=5;
        count=count/7;
        if(count==53)
        {
            Date d1(D31,Dec,(Year)this->year);
            if((WeekDay)d1>=Thr)
                return static_cast<WeekNumber>(53);
            else
                 return static_cast<WeekNumber>(1);
        }
        return static_cast<WeekNumber>(count);
    }
    else{
         int count=(int)(WeekDay)qwer;
         count+=this->day;
        for(int i=0;i<this->month-1;i++)
            count+=monthDays[i];
        count+=5;
        count=count/7;

        if(count==0)
         if(this->year!=1950)
            {Date d(D31,Dec,(Year)this->year-1);
            return (WeekNumber) d;}
         else
            return static_cast<WeekNumber>(52);
        return static_cast<WeekNumber>(count);
    }
  /*  for(; qwer!=Thr; qwer++);
    for(; qwer!=Mon; qwer--);

    if(qwer>*this)
    {
        if(this->year!=1950)
        {
            qwer=Date(D01,Jan,(Year)(this->year-1));
            while(qwer!=Thr) qwer++;
            while(qwer!=Mon) qwer--;
            int a=qwer-*this;
            return (WeekNumber) (a/7+1);
        }
        else
        {
            if(Date(D01,Jan,1950)==*this) return W52;
            else
            {
                qwer=Date(D02,Jan,1950);
                int a=qwer-*this;
                return (WeekNumber) (a/7+1);
            }
        }

    }
    else
    {
        Date temp(*this);
        for(; temp!=Thr; temp++);
        if(temp.year!=this->year) return (WeekNumber)1;
        int a=qwer-*this;
        return (WeekNumber) (a/7+1);
    }*/
} // Cast to the week number of the year in which the current date falls


Date::operator Month() const
{
    return (Month)this->month;
} // Cast to the month of the year in which the current date falls

Date::operator WeekDay() const
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int j=year;
    int k=(this->year-1928 +(this->year-1928)/7);
     k+=this->day;
        for(int i=0;i<this->month-1;i++)
            k+=monthDays[i];
            k+=3;
            k=k%7;

    if(k==1) return Mon;
    else if(k==2) return Tue;
    else if(k==3) return Wed;
    else if(k==4) return Thr;
    else if(k==5) return Fri;
    else if(k==6) return Sat;
    else if(k==0) return Sun;

}
// Cast to the day of the week of the current date


bool Date:: leapYear() const
{
    if(leap(this->year)==true) return true;
    else false;
}
// True if the year of the current date is a leap year


// BINARY RELATIONAL OPERATORS
bool Date:: operator==(const Date& otherDate)
{
    if((day==otherDate.day)&&(month==otherDate.month)&&(year==otherDate.year)) return true;
    else false;
}

// != operator
bool Date:: operator!=(const Date& otherDate)
{
    if((day==otherDate.day)&&(month==otherDate.month)&&(year==otherDate.year)) return false;
    else true;
}

//< operator
bool Date:: operator<(const Date& otherDate)
{
    if(otherDate.year>year) return true;
    else if(otherDate.year==year)
    {
        if(otherDate.month>month) return true;
        else if(otherDate.month==month)
        {
            if(otherDate.day>day) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

//<= operator does opposite to >
bool Date:: operator<=(const Date& otherDate)
{
    if(otherDate.year>year) return true;
    else if(otherDate.year==year)
    {
        if(otherDate.month>month) return true;
        else if(otherDate.month==month)
        {
            if(otherDate.day>day) return true;
            else if(otherDate.day==day) return true;
            else return false;
        }
        else return false;
    }
    else return false;

}

//> operator
bool Date:: operator>(const Date& otherDate)
{
    if(otherDate.year<year) return true;
    else if(otherDate.year==year)
    {
        if(otherDate.month<month) return true;
        else if(otherDate.month==month)
        {
            if(otherDate.day<day) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

//>= operator gives whether given date is ahead or not
bool Date:: operator>=(const Date& otherDate)
{
    if(otherDate.year<year) return true;
    else if(otherDate.year==year)
    {
        if(otherDate.month<month) return true;
        else if(otherDate.month==month)
        {
            if(otherDate.day<day) return true;
            else if(otherDate.day==day) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
// BASIC I/O using FRIEND FUNCTIONS
// These functions use Date::format to write or read
ostream& operator<<(ostream& output, const Date& date)
{
    output<<date.day<<"-"<<date.month<<"-"<<date.year<<endl;
}
istream& operator>>(istream& input, Date& date)
{
    input>>date.day>>date.month>>date.year;
}
DateFormat Date::format("dd-mm-yyyy");
// Format Function
void Date::setFormat(DateFormat& p)
{
    Date::format=p;
}
DateFormat& Date::getFormat()
{
    return (Date::format);
}

//DATEFORMAT MEMBERS AND CONSTRUCTOR
DateFormat::DateFormat(const char* dateFormat, const char* monthFormat, const char* yearFormat)
{
    dateFormat=NULL;
    monthFormat=NULL;
    yearFormat=NULL;
    int k;
    k=strlen(dateFormat);
    dateFormat=new char[k+1];
    strcpy(this->dateFormat,dateFormat);
    k=strlen(monthFormat);
    monthFormat=new char[k+1];
    strcpy(this->monthFormat,monthFormat);
    k=strlen(yearFormat);
    yearFormat=new char[k+1];
    strcpy(this->yearFormat,yearFormat);
}

// Single C-string format where dateFormat, monthFormat, and yearFormat are separated by '-'
// Example: "dd-mmm-yy", "d-mm-yyyy", etc
DateFormat::DateFormat(const char* format)
{
    int i,count1=0,arr[2];
    for(i=0; i<strlen(format); i++)
    {
        if(format[i]=='-')
        {
            arr[count1]=i;
            count1++;
        }
    }
    strncpy(dateFormat, format, arr[0]);

    strncpy(monthFormat,format+arr[0]+1,arr[1]-arr[0]-1);

    strncpy(yearFormat,format+arr[1]+1,strlen(format)-arr[1]-1);

}

// Default DateFormat created as "dd-mmm-yy"
DateFormat::DateFormat()
{

    strcpy(dateFormat,"dd");
    strcpy(monthFormat,"mmm");
    strcpy(yearFormat,"yy");
}

DateFormat::~DateFormat()
{
    delete[] dateFormat;
    delete[] monthFormat;
    delete[] yearFormat;
}

char* DateFormat:: getdate()
{
    char*str=dateFormat;
    return str;
}
char* DateFormat::getmonth()
{
    char *str=monthFormat;
    return str;
}
char* DateFormat::getyear()
{
    char *str=yearFormat;
    return str;
}

