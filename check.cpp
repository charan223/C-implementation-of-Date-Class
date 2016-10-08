#include <iostream>
#include "assignment.cpp"


//checkformat2 function

void checkformat2(ostream& fo,string a,string b,string c)
{
    string d,e,f;
    if(a.length()>0)
    {
        fo<<a;
        d=a;
    }
    else
    {
        fo<<"NULL";
        d=string("NULL");
    }

    fo<<"-";

    if(b.length()>0)
    {
        fo<<b;
        e=b;
    }
    else
    {
        fo<<"NULL";
        e=string("NULL");
    }

    fo<<"-";

    if(c.length()>0)
    {
        fo<<c;
        f=c;
    }
    else
    {
        fo<<"NULL";
        f=string("NULL");
    }
    fo<<"\n";
}

DateFormat* checkformat1(ostream&fo,string a)
{

    try
    {
        DateFormat *newdateformatvariable=new DateFormat(a.c_str());
        fo<<a;
        return newdateformatvariable;
    }
    catch(exception &e)
    {
        fo<<"Error"<<endl;
    }
    catch(...)
    {
        fo<<"Error Unknown"<<endl;
    }
    return NULL;
}


void checkdate2(ostream &fo)
{
    string g[]= {"31-02-2016","10-03-2016","06-Sep-1996","02-Mar-23"};
    for(int k=0; k<4; k++)
    {

        try
        {
            fo<<g[k]<<"\n"<<endl;
            Date j(g[k].c_str());
        }
        catch(exception &e)
        {
            fo<<e.what()<<"\n"<<endl;
        }
    }
}

//checkdate1 function

void checkdate1(ostream&fo)
{
    Day da[5]= {D10,D30,D29,D31,D15};
    Month mn[5]= {Feb,Jan,Mar,Sep,Nov};
    Year ye[5]= {2016,23,2045,1996,78};
    for(int k=0; k<5; k++)
    {
        try
        {
            fo<<"Initialising "<<da[k]<<"-"<<mn[k]<<"-"<<ye[k]<<endl;
            fo<<"\n";
        }
        catch(exception &e)
        {
            fo<<"Error"<<endl;
        }
    }

}



void Testdata(ostream &fo)
{

    Date now;
    string p[]=
    {
        "--","d--","dd--","-m-",
        "d-m-","dd-m-","-mm-","d-mm-",
        "dd-mm-","-mmm-","d-mmm-","dd-mmm-",
        "--yy","d--yy","dd--yy","-m-yy",
        "d-m-yy","dd-m-yy","-mm-yy","d-mm-yy",
        "dd-mm-yy","-mmm-yy","d-mmm-yy","dd-mmm-yy",
        "--yyyy","d--yyyy","dd--yyyy","-m-yyyy",
        "d-m-yyyy","dd-m-yyyy","-mm-yyyy","d-mm-yyyy",
        "dd-mm-yyyy","-mmm-yyyy","d-mmm-yyyy","dd-mmm-yyyy"
    };

    //printing all the date formats

    fo<<"********************************************************************************"<<endl;
    fo<<"Printing all types formats"<<endl;

    DateFormat *format[36];
    for(int k=0; k<36; k++)
    {
        format[k]=checkformat1(fo,p[k]);
        fo<<"\n";
    }

    fo<<"********************************************************************************"<<endl;
    fo<<"Printing all types formats if given input in different format"<<endl;
    for(int k=0; k<36; k++)
    {
        int d=p[k].find_first_of("-",0);
        int y=p[k].find_first_of("-",d+1);
        string a,b,c;
        a=p[k].substr(0,d);
        b=p[k].substr(d+1,y-d-1);
        c=p[k].substr(y+1);
        checkformat2(fo,a,b,c);
    }

    fo<<"********************************************************************************"<<endl;
    checkdate1(fo);
    fo<<"********************************************************************************"<<endl;
    checkdate2(fo);
    fo<<"********************************************************************************"<<endl;
    Date now2(now);


    fo<<"Testing ++,++(int) operators"<<endl;
    fo<<++now<<"\n"<<endl;

    fo<<now++<<"\n"<<endl;

    fo<<"********************************************************************************"<<endl;
    fo<<"Testing --,--(int) operators"<<endl;
    fo<<--now<<"\n"<<endl;

    fo<<now--<<"\n"<<endl;

    Date datevar1("10-03-2019");

    fo<<"********************************************************************************"<<endl;
    fo<<"Testing + operator"<<endl;

    Date datevar2(D09,Mar,2016);

    fo<<datevar2+1<<"--> ITS MY BIRTHDAY!!!"<<endl;

    fo<<"Wish me at  https://www.facebook.com/sricharan6996 "<<"\n"<<endl;

    try
    {
        fo<<datevar2+100000<<"\n"<<endl;
    }
    catch(exception &e)
    {
        fo<<e.what()<<"\n"<<endl;
    }

    fo<<"********************************************************************************"<<endl;
    fo<<"Testing operator(-) "<<endl;
  Date dt1  (D15,Mar,2020),dt2(D30,Sep,2025);

    fo<<dt2-dt1<<"\n"<<endl;


   fo<<"********************************************************************************"<<endl;
    fo<<"Testing Weekday operators"<<endl;

    fo<<(WeekDay)dt2<<"\n"<<endl;

    fo<<(WeekDay)(dt2+1)<<"\n"<<endl;

    fo<<"********************************************************************************"<<endl;
    fo<<"Testing weeknumber operators"<<endl;

    fo<<(WeekNumber)dt2<<"\n"<<endl;

    fo<<(WeekNumber)(dt2+1)<<"\n" <<endl;

   fo<<"********************************************************************************"<<endl;
    fo<<"Testing month operators"<<endl;

    fo<<(Month)now<<"\n"<<endl;

    fo<<(Month)(now+365)<<"\n"<<endl;

    fo<<now.leapYear()<<"\n"<<endl;

    fo<<datevar2.leapYear()<<"\n"<<endl;

    fo<<"********************************************************************************"<<endl;
    fo<<"Testing == ,!=,<=,<,>=,> operators"<<endl;

    fo<<(datevar1==datevar2)<<"\n"<<endl;

    fo<<(datevar1!=datevar2)<<"\n"<<endl;

    fo<<(datevar1<=datevar2)<<"\n"<<endl;

    fo<<(datevar1<datevar2)<<"\n"<<endl;

    fo<<(datevar1>=datevar2)<<"\n"<<endl;

    fo<<(datevar1>datevar2)<<"\n"<<endl;

    fo<<"********************************************************************************"<<endl;
    fo<<"Testing set and get formats"<<endl;
    for(int k=0; k<36; k++)
    {
        Date::setFormat(*format[k]);

        fo<<Date::getFormat().getdate()<<"\n"<<endl;

        fo<<Date::getFormat().getmonth()<<"\n"<<endl;

        fo<<Date::getFormat().getyear()<<"\n"<<endl;

    }

    fo<<"********************************************************************************"<<endl;
    fo<<"Testing assignment operator"<<endl;
    datevar2=now;

    fo<<datevar2<<"\n"<<endl;
    fo<<"********************************************************************************"<<endl;
    fo<<"Testing operators"<<endl;
    for(int k=0; k<36; k++)
    {

        fo<<p[k];
        Date::setFormat(*format[k]);
        fo<<now<<"\n"<<endl;
    }

    delete [] format;

}


//Main function

int main()
{


    ofstream fo;
    fo.open("output.txt");
    try
    {
        Testdata(cout);
        Date d(D10,Mar,2016);
        cout<<d+20<<"\n"<<endl;
    }

    catch(exception& e)
    {
        fo<<"\n"<<e.what()<<endl;
    }
    fo.close();
    return 0;
}
