#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<time.h>
#include<ctime>
#include "md5.h"
#include<string>
#include<string.h>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<math.h>
#include<mysql.h>
#include<stdlib.h>
#include "passwordInput.h"
using namespace std;


int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;



class Bank
{
    string adminUsername;
    int found;
    string bankname;
    static int count;
    static int acount;


public:



    static int countt()
    {
        count++;
        return count;
    }

    static int acountt()
    {
        acount++;
        return acount;
    }

    Bank()
    {


        FILE *file;
        if ((file = fopen("isExist.txt", "r")))
        {
            found=1;
            fclose(file);

        }
        else
            found=0;

    }

    void fileCreation();
    void loginScreen();
    void guideScreen();
    void moreOption();
    void operationScreen();
    void welcomeScreen();
    void depositBalance();
    void withDrawal();
    void transferBalance();
    void resultantScreen(int,string,string,string,string);
    void searchAccount();
    void addAccount();
    void deleteAccount();
    void viewAllAccount();
    void changeOwnPassword();
    void addAdmin();
    void interestCalculation();
    void viewAllDelAccount();
    void seeReport();
   void saveReport(int ch0,string branchaddress,string loginuname,int damount,string dname,string daccount,int wamount,string wname,string waccount,int tamount,string froma,string toa,string aaccountno,string daccountno,string apasschange,string aadded);
};
int Bank::count = 0;
int Bank::acount = 0;
COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



string getpassword()
{

    char password[15];
    char ch;
    int characterpostion=0;
    while(1)
    {
        ch=_getch();
        if(ch==13)
        {
            break;
        }
        else if(ch==8)
        {

            if(characterpostion>0)
            {

                characterpostion--;
                password[characterpostion]='\0';
                cout<<"\b \b";




            }

        }
        else if(ch==32||ch==9)
        {
            continue;





        }

        else
        {




            password[characterpostion]=ch;
            characterpostion++;
            printf("*");
        }




    }

    MD5 md ;



    return(md.digestString(password) );

}



void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void loaderanim()
{
    int loader;
    system("cls");
    gotoxy(20,10);
    printf("LOADING........");
    printf("\n\n");
    gotoxy(22,11);
    string date,months,years;
    bool found5=false;
    for(loader=1; loader<20; loader++)
    {
        delay(100);
        printf("%c",219);
    }
 string fbalance,finterest;
                long int ifbalance,ifinterest;

    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from last_interest");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {




                    date=row[0];
                    months=row[1];
                    years=row[2];

                    found5=true;

                    break;


                }

            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);

            }
        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);

        }

    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }




    if(found5)
    {


        stringstream change1(date);
        int idate;
        change1>>idate;
        stringstream change2(months);
        int imonth;
        change2>>imonth;
        stringstream change3(years);
        int iyear;
        change3>>iyear;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int tday=(ltm->tm_mday);
        int tmonth= ((ltm->tm_mon)+1);
        int tyear=(ltm->tm_year+1900);

        if(idate==0&&imonth==0&&iyear==0)
        {


            ostringstream str8;
            str8 << tday;
            string update1 = str8.str();


            ostringstream str9;
            str9 << tmonth;
            string upmonth = str9.str();

            ostringstream str10;
            str10 << tyear;
            string upyear = str10.str();


            conn=mysql_init(0);
            if(conn)
            {
               conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                if(conn)
                {

                    string query="update last_interest set date='"+update1+"',month='"+upmonth+"',year= '"+upyear+"' where year='"+years+"'";


                    const char* q = query.c_str();

                    qstate = mysql_query(conn,q);

                    if(!qstate)
                    {





                    }


                    else
                    {

                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,28);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);

                        cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);





                    }




                }
                else
                {


                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);



                }


            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);


            }

        }



        else
        {


            if((tday-idate+(tmonth-imonth)*30+(tyear-iyear)*365)>30)
            {

                system("cls");
                gotoxy(36,10);
                cout<<"Interest is updating. Just wait.....";




                conn=mysql_init(0);
                if(conn)
                {

                   conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                    if(conn)
                    {


                        qstate=mysql_query(conn,"select * from customer_detail");
                        if(!qstate)
                        {
                            res=mysql_store_result(conn);
                            while(row=mysql_fetch_row(res))
                            {

                                stringstream change1(row[1]);
                                long int stbalance;
                                change1>>stbalance;
                                if(stbalance>100000)
                                {
                                    ifinterest=stbalance*0.00833;
                                    ifbalance=stbalance+ifinterest;


                                    ostringstream str13;
                                    str13 << ifbalance;
                                    fbalance = str13.str();
                                    ostringstream str14;
                                    str14 << ifinterest;
                                    finterest = str14.str();

                                }
                                else
                                {


                                    fbalance=row[1];

                                }





                                conn=mysql_init(0);
                                if(conn)
                                {
                                   conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                                    if(conn)
                                    {

                                        string query="update customer_detail set balance= '"+fbalance+"' where account_number='"+row[0]+"'";


                                        const char* q = query.c_str();

                                        qstate = mysql_query(conn,q);

                                        if(!qstate)
                                        {





                                        }


                                        else
                                        {

                                            system("cls");
                                            gotoxy(0,0);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,28);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,0);

                                            cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                            cout<<"\n\n\t\t\t\tExiting...................";
                                            delay(2000);





                                        }




                                    }
                                    else
                                    {


                                        system("cls");
                                        gotoxy(0,0);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,29);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,0);
                                        cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                        cout<<"\n\n\t\t\t\tExiting...................";
                                        delay(2000);
                                        exit(0);



                                    }


                                }
                                else
                                {

                                    system("cls");
                                    gotoxy(0,0);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,29);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,0);
                                    cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                                    cout<<"\n\n\t\t\t\tExiting...................";
                                    delay(2000);
                                    exit(0);


                                }



                                conn=mysql_init(0);
                                if(conn)
                                {
                                   conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                                    if(conn)
                                    {

                                        string query="update customer_detail set interest= '"+finterest+"' where account_number='"+row[0]+"'";


                                        const char* q = query.c_str();

                                        qstate = mysql_query(conn,q);

                                        if(!qstate)
                                        {





                                        }


                                        else
                                        {

                                            system("cls");
                                            gotoxy(0,0);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,28);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,0);

                                            cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                            cout<<"\n\n\t\t\t\tExiting...................";
                                            delay(2000);





                                        }




                                    }
                                    else
                                    {


                                        system("cls");
                                        gotoxy(0,0);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,29);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,0);
                                        cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                        cout<<"\n\n\t\t\t\tExiting...................";
                                        delay(2000);
                                        exit(0);



                                    }


                                }
                                else
                                {

                                    system("cls");
                                    gotoxy(0,0);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,29);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,0);
                                    cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                                    cout<<"\n\n\t\t\t\tExiting...................";
                                    delay(2000);
                                    exit(0);


                                }








                            }

                        }
                        else
                        {

                            system("cls");
                            gotoxy(0,0);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,28);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,0);

                            cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                            cout<<"\n\n\t\t\t\tExiting...................";
                            delay(2000);

                        }
                    }
                    else
                    {


                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,29);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);
                        cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);
                        exit(0);

                    }

                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);
                }


















                ostringstream str8;
                str8 << tday;
                string update1 = str8.str();


                ostringstream str9;
                str9 << tmonth;
                string upmonth = str9.str();

                ostringstream str10;
                str10 << tyear;
                string upyear = str10.str();


                conn=mysql_init(0);
                if(conn)
                {
                   conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                    if(conn)
                    {

                        string query="update last_interest set date='"+update1+"',month='"+upmonth+"',year= '"+upyear+"' where year='"+years+"'";


                        const char* q = query.c_str();

                        qstate = mysql_query(conn,q);

                        if(!qstate)
                        {





                        }


                        else
                        {

                            system("cls");
                            gotoxy(0,0);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,28);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,0);

                            cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                            cout<<"\n\n\t\t\t\tExiting...................";
                            delay(2000);





                        }




                    }
                    else
                    {


                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,29);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);
                        cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the database. Connect Your Pc to Interenet"<<endl;
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);
                        exit(0);



                    }


                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);


                }



            }















        }


















    }










}




int t(void) //for time
{

    time_t t;
    time(&t);
    printf("%s\n",ctime(&t));

    return 0 ;
}






void Bank::saveReport(int ch0,string branchaddress,string loginuname,int damount,string dname,string daccount,int wamount,string wname,string waccount,int tamount,string froma,string toa,string aaccountno,string daccountno,string apasschange,string aadded)
{

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int tday=(ltm->tm_mday);
    int tmonth= ((ltm->tm_mon)+1);
    int tyear=(ltm->tm_year+1900);



    ostringstream str8;
    str8 << tday;
    string update1 = str8.str();


    ostringstream str9;
    str9 << tmonth;
    string upmonth = str9.str();

    ostringstream str10;
    str10 << tyear;
    string upyear = str10.str();


    char app[200];
        string m;

    if(ch0==0)
    {
        char j[200];

        strcpy(app,"Software is installed in ");
        strcpy(j, branchaddress.c_str());


        strcat(app,j);

       m=app;


    }
    else if(ch0==1)
    {
        char comma[50];

        strcpy(comma,"@");
         strcpy(comma, loginuname.c_str());
         char comma1[50];
         strcpy(comma1,"'");
        strcpy(comma1," is logged in ");


        strcat(comma,comma1);
       m=comma;










    }

    else if(ch0==2)
    {
    ostringstream str18;
    str18 << damount;
    string damount1 = str18.str();

       char u[50];
        char t[50];

    strcpy(t,damount1.c_str());

    strcpy(u," is deposited in ");
    strcat(t,u);

    strcat(t,daccount.c_str());
    strcat(t," by ");
    strcat(t,dname.c_str());
    m=t;




    }
    else if(ch0==3)
    {

   ostringstream str19;
    str19 << wamount;
    string wamount1 = str19.str();

       char u1[50];
        char t1[50];

    strcpy(t1,wamount1.c_str());

    strcpy(u1," is deposited in ");
    strcat(t1,u1);

    strcat(t1,waccount.c_str());
    strcat(t1," by ");
    strcat(t1,wname.c_str());
    m=t1;




    }
    else if(ch0==4)
    {


        ostringstream str23;
    str23 << tamount;
    string tamount1 = str23.str();
        char ha[50];
        strcat(ha,tamount1.c_str());
        strcat(ha," transfer from ");
        strcat(ha,froma.c_str());
        strcat(ha," to ");
        strcat(ha,toa.c_str());
        m=ha;




    }
    else if(ch0==5)
    {
    char hi[60];
    strcat(hi,"New ");
    strcat(hi,aaccountno.c_str());
    strcat(hi," is created");
    m=hi;


    }
    else if(ch0==6)
    {
          char hk[60];

    strcat(hk,daccountno.c_str());
    strcat(hk," is deleted");
    m=hk;


    }
    else if(ch0==7)
    {

      char hp[60];

    strcat(hp,apasschange.c_str());
    strcat(hp," change password");
    m=hp;


    }
    else if(ch0==8)
    {

       char hs[60];
         strcat(hs,"New admin.. ");

    strcat(hs,aadded.c_str());
    strcat(hs," ..is added");
    m=hs;


    }
    else
    {



    }



    conn=mysql_init(0);
    if(conn)
    {
       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {

            string query="insert into report(date,month,year,action) values('"+update1+"','"+upmonth+"','"+upyear+"','"+m+"')";


            const char* q = query.c_str();

            qstate = mysql_query(conn,q);

            if(!qstate)
            {





            }


            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);





            }




        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);



        }


    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);


    }











}




void Bank::seeReport(){


    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,2);
    t();
    gotoxy(8,2);
    cout<<"View Report Section";




    gotoxy(50,3);
    cout<<"Sorting Report:";


    gotoxy(100,5);
    cout<<".";
    gotoxy(100,6);
    cout<<".";
    gotoxy(100,7);
    cout<<".";
    gotoxy(100,8);
    cout<<".";
    gotoxy(100,9);
    cout<<".";
    gotoxy(100,10);
    cout<<".";
    gotoxy(100,11);
    cout<<".";
    gotoxy(100,12);
    cout<<".";
    gotoxy(100,13);
    cout<<".";
    gotoxy(100,14);
    cout<<".";
    gotoxy(100,15);
    cout<<".";
    gotoxy(100,16);
    cout<<".";
    gotoxy(100,17);
    cout<<".";
    gotoxy(100,18);
    cout<<".";
gotoxy(100,19);
    cout<<".";
    gotoxy(100,20);
    gotoxy(35,5);
    cout<<".";
    gotoxy(35,6);
    cout<<".";
    gotoxy(35,7);
    cout<<".";
    gotoxy(35,8);
    cout<<".";
    gotoxy(35,9);
    cout<<".";
    gotoxy(35,10);
    cout<<".";
    gotoxy(35,11);
    cout<<".";
    gotoxy(35,12);
    cout<<".";
    gotoxy(35,13);
    cout<<".";
    gotoxy(35,14);
    cout<<".";
    gotoxy(35,15);
    cout<<".";
    gotoxy(35,16);
    cout<<".";
    gotoxy(35,17);
    cout<<".";
    gotoxy(35,18);
    cout<<".";
gotoxy(35,19);
    cout<<".";
    gotoxy(35,20);
    cout<<".";
    gotoxy(35,4);
    cout<<"..................................................................";
    gotoxy(35,21);
    cout<<"..................................................................";

gotoxy(45,9);
     cout<<"1. All reports";
    gotoxy(45,11);
    cout<<"2. Today Report";
    gotoxy(45,13);
    cout<<"3. Specific date";
    gotoxy(45,15);
    cout<<"4. Back";

xx:
    gotoxy(47,19);

    cout<<"__________";
    gotoxy(49,18);
    switch(_getch()){

case '1':

{



     system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,2);
    t();
    gotoxy(8,2);
   cout<<"View All Report Section";
     gotoxy(11,5);
    cout<<"Total Report Found: ";
    gotoxy(0,7);
    int i=1;

    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from report");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                printf("----------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-20s | %-20s | %-20s | %-20s \n", "Month", "Date", "Year", "Operations");


                    while(row=mysql_fetch_row(res))
                    {

                        printf("| %-20s | %-20s | %-20s | %-20s \n", row[1], row[0], row[2], row[3]);
                        i++;




                    }

            printf("----------------------------------------------------------------------------------------------------------------------\n");
                gotoxy(11,5);
                cout<<"Total Account Found: "<<i-1;
            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }












  _getch();
operationScreen();
    break;
    }

case '2' :
    {

     system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,2);
    t();
    gotoxy(8,2);
     cout<<"View Today Report Section";


time_t now = time(0);
    tm *ltm = localtime(&now);
    int tday=(ltm->tm_mday);
    int tmonth= ((ltm->tm_mon)+1);
    int tyear=(ltm->tm_year+1900);



    ostringstream str8;
    str8 << tday;
    string update1 = str8.str();


    ostringstream str9;
    str9 << tmonth;
    string upmonth = str9.str();

    ostringstream str10;
    str10 << tyear;
    string upyear = str10.str();
//cout<<update1<<upyear<<upmonth;_getch();
  gotoxy(11,5);
    cout<<"Total Report Found: ";
    gotoxy(0,7);
    int i=1;

    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from report");
            if(!qstate)
            {
                res=mysql_store_result(conn);
              printf("----------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-20s | %-20s | %-20s | %-20s \n", "Month", "Date", "Year", "Operations");


                    while(row=mysql_fetch_row(res))
                    {
                        if(row[0]==update1&&row[1]==upmonth&&row[2]==upyear){
                        printf("| %-20s | %-20s | %-20s | %-20s \n", row[1], row[0], row[2], row[3]);
                        i++;




                    }



            }
            printf("----------------------------------------------------------------------------------------------------------------------\n");
                gotoxy(11,5);
                cout<<"Total Account Found: "<<i-1;
            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }





















    _getch();
    operationScreen();
    break;
    }
 case '3' :
{

     system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,2);
    t();
    gotoxy(8,2);
    cout<<"View Specific date Section";


     gotoxy(30,4);cout<<"Enter month: ";string months;cin>>months;
      gotoxy(30,6);cout<<"Enter day: ";string days;cin>>days;
       gotoxy(30,8);cout<<"Enter year: ";string years;cin>>years;

 gotoxy(0,14);
    int i=1;

    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from report");
            if(!qstate)
            {
                res=mysql_store_result(conn);
              printf("----------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-20s | %-20s | %-20s | %-20s \n", "Month", "Date", "Year", "Operations");


                    while(row=mysql_fetch_row(res))
                    {
                        if(row[0]==days&&row[1]==months&&row[2]==years){
                        printf("| %-20s | %-20s | %-20s | %-20s \n", row[1], row[0], row[2], row[3]);
                        i++;




                    }



            }
            printf("----------------------------------------------------------------------------------------------------------------------\n");
                gotoxy(11,11);
                cout<<"Total Account Found: "<<i-1;
            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }

























    _getch();
    operationScreen();
    break;
}

 case '4':
    moreOption();
    break;
default:
    goto xx;



}





    }









void Bank::addAccount()
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;

    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"Add Account Section";

    gotoxy(35,3);
    cout<<"Enter the following information to register an account:";


    gotoxy(100,5);
    cout<<".";
    gotoxy(100,6);
    cout<<".";
    gotoxy(100,7);
    cout<<".";
    gotoxy(100,8);
    cout<<".";
    gotoxy(100,9);
    cout<<".";
    gotoxy(100,10);
    cout<<".";
    gotoxy(100,11);
    cout<<".";
    gotoxy(100,12);
    cout<<".";
    gotoxy(100,13);
    cout<<".";
    gotoxy(100,14);
    cout<<".";
    gotoxy(100,15);
    cout<<".";
    gotoxy(100,16);
    cout<<".";
    gotoxy(100,17);
    cout<<".";
    gotoxy(100,18);
    cout<<".";

    gotoxy(35,5);
    cout<<".";
    gotoxy(35,6);
    cout<<".";
    gotoxy(35,7);
    cout<<".";
    gotoxy(35,8);
    cout<<".";
    gotoxy(35,9);
    cout<<".";
    gotoxy(35,10);
    cout<<".";
    gotoxy(35,11);
    cout<<".";
    gotoxy(35,12);
    cout<<".";
    gotoxy(35,13);
    cout<<".";
    gotoxy(35,14);
    cout<<".";
    gotoxy(35,15);
    cout<<".";
    gotoxy(35,16);
    cout<<".";
    gotoxy(35,17);
    cout<<".";
    gotoxy(35,18);
    cout<<".";

    gotoxy(35,4);
    cout<<"..................................................................";
    gotoxy(35,19);
    cout<<"..................................................................";


    string name;
    string age,citizenship,balance;
    gotoxy(37,7);
    cout<<"Name: ";
    getline(cin,name);
    gotoxy(37,9);
    cout<<"Age: ";
    getline(cin,age);
    int intage;
    stringstream change3(age);
    change3>>intage;
    if(intage<18)
    {
        gotoxy(37,15);
        cout<<"under age. cannot create account";
        delay(3000);
        operationScreen();


    }
    if(intage>=120)
    {
        gotoxy(37,15);
        cout<<"Invalid age. cannot create account";
        delay(3000);
        operationScreen();

    }


    gotoxy(37,11);
    cout<<"Citizenship no. : ";
    getline(cin,citizenship);
    gotoxy(37,13);
    cout<<"Balance to be deposited: ";
    getline(cin,balance);
    bool found4;
    long int actualbalance;
    stringstream change(balance);
    change>>actualbalance;




    if(actualbalance<1000)
    {
        gotoxy(37,15);
        cout<<"need balance at least 1000";
        delay(3000);
        operationScreen();

    }

    conn=mysql_init(0);
    if(conn)
    {
       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {

            qstate=mysql_query(conn,"select * from customer_detail");

            if(!qstate)
            {


                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[4]==citizenship)
                    {

                        found4=true;

                    }
                    else
                    {

                        found4=false;
                    }





                }

            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);





            }




        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);



        }







    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);





    }


    if(found4)
    {

        gotoxy(37,15);
        cout<<"There is already a account with this citizenship no.";
        delay(3000);
        operationScreen();



    }





    conn=mysql_init(0);
    if(conn)
    {
       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            string query="insert into customer_detail(balance,name,age,citizenshipNo) values('"+balance+"','"+name+"','"+age+"','"+citizenship+"')";


            const char* q = query.c_str();

            qstate = mysql_query(conn,q);

            if(!qstate)
            {

                gotoxy(37,15);

                cout<<"Account Created Successfully..";
                delay(3000);


                system("cls");
                gotoxy(35,3);
                cout<<"Following is assigned the account number:";


                gotoxy(100,5);
                cout<<".";
                gotoxy(100,6);
                cout<<".";
                gotoxy(100,7);
                cout<<".";
                gotoxy(100,8);
                cout<<".";
                gotoxy(100,9);
                cout<<".";
                gotoxy(100,10);
                cout<<".";
                gotoxy(100,11);
                cout<<".";
                gotoxy(100,12);
                cout<<".";
                gotoxy(100,13);
                cout<<".";
                gotoxy(100,14);
                cout<<".";
                gotoxy(100,15);
                cout<<".";
                gotoxy(100,16);
                cout<<".";
                gotoxy(100,17);
                cout<<".";
                gotoxy(100,18);
                cout<<".";

                gotoxy(35,5);
                cout<<".";
                gotoxy(35,6);
                cout<<".";
                gotoxy(35,7);
                cout<<".";
                gotoxy(35,8);
                cout<<".";
                gotoxy(35,9);
                cout<<".";
                gotoxy(35,10);
                cout<<".";
                gotoxy(35,11);
                cout<<".";
                gotoxy(35,12);
                cout<<".";
                gotoxy(35,13);
                cout<<".";
                gotoxy(35,14);
                cout<<".";
                gotoxy(35,15);
                cout<<".";
                gotoxy(35,16);
                cout<<".";
                gotoxy(35,17);
                cout<<".";
                gotoxy(35,18);
                cout<<".";

                gotoxy(35,4);
                cout<<"..................................................................";
                gotoxy(35,19);
                cout<<"..................................................................";
                gotoxy(37,6);
                cout<<"Assigned Account: ";
                string accountno;
                conn=mysql_init(0);
                if(conn)
                {
                   conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                    if(conn)
                    {

                        qstate=mysql_query(conn,"select * from customer_detail");

                        if(!qstate)
                        {


                            res=mysql_store_result(conn);
                            while(row=mysql_fetch_row(res))
                            {

                                if(row[4]==citizenship)
                                {
                                    accountno=row[0];
                                    cout<<row[0];
                                    //saveReport(0,0,0,0,0,0,0,0,0,0,accountno,)
                                      saveReport(5,"","",0,"","",0,"","",0,"","",accountno,"","","");
                                      break;

                                }
                                else
                                {

                                    found4=false;
                                }





                            }

                        }
                        else
                        {

                            system("cls");
                            gotoxy(0,0);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,28);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,0);

                            cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                            cout<<"\n\n\t\t\t\tExiting...................";
                            delay(2000);





                        }




                    }
                    else
                    {


                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,29);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);
                        cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);
                        exit(0);



                    }







                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);





                }








                gotoxy(37,8);
                cout<<"Name: "<<name;
                gotoxy(37,10);
                cout<<"Age: "<<age;
                gotoxy(37,12);
                cout<<"Citizenship no. : "<<citizenship;
                gotoxy(37,14);
                cout<<"Balance to be deposited: "<<balance;





                delay(5000);
                operationScreen();







            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);





            }




        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);



        }







    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);





    }










    _getch();

















}


void Bank::viewAllDelAccount()
{


    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,2);
    t();
    gotoxy(8,2);
    cout<<"View All Account Section";

    gotoxy(11,5);
    cout<<"Total Account Found: ";
    gotoxy(0,7);
    int i=1;

    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from passivecustomer");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                printf("---------------------------------------------------------------------------------------------\n");
                printf("| %-20s | %-20s | %-20s | %-20s |\n", "Account No", "Name", "Age", "CitizenshipNo");

                while ((row = mysql_fetch_row(res)))
                    while(row=mysql_fetch_row(res))
                    {

                        printf("| %-20s | %-20s | %-20s | %-20s |\n", row[0], row[1], row[2], row[3]);
                        i++;




                    }

                printf("---------------------------------------------------------------------------------------------\n");
                gotoxy(11,5);
                cout<<"Total Account Found: "<<i-1;
            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }



    _getch();

    operationScreen();

















}





void Bank::searchAccount()
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"Search Section";
    string accountNo;
    gotoxy(10,3);
    cout<<"Account No: ";
    getline(cin,accountNo);




    gotoxy(105,5);
    cout<<".";
    gotoxy(105,6);
    cout<<".";
    gotoxy(105,7);
    cout<<".";
    gotoxy(105,8);
    cout<<".";
    gotoxy(105,9);
    cout<<".";
    gotoxy(105,10);
    cout<<".";
    gotoxy(105,11);
    cout<<".";
    gotoxy(105,12);
    cout<<".";
    gotoxy(105,13);
    cout<<".";
    gotoxy(105,14);
    cout<<".";
    gotoxy(105,15);
    cout<<".";
    gotoxy(105,16);
    cout<<".";
    gotoxy(105,17);
    cout<<".";
    gotoxy(105,18);
    cout<<".";

    gotoxy(50,5);
    cout<<".";
    gotoxy(50,6);
    cout<<".";
    gotoxy(50,7);
    cout<<".";
    gotoxy(50,8);
    cout<<".";
    gotoxy(50,9);
    cout<<".";
    gotoxy(50,10);
    cout<<".";
    gotoxy(50,11);
    cout<<".";
    gotoxy(50,12);
    cout<<".";
    gotoxy(50,13);
    cout<<".";
    gotoxy(50,14);
    cout<<".";
    gotoxy(50,15);
    cout<<".";
    gotoxy(50,16);
    cout<<".";
    gotoxy(50,17);
    cout<<".";
    gotoxy(50,18);
    cout<<".";

    gotoxy(50,4);
    cout<<"........................................................";
    gotoxy(50,19);
    cout<<"........................................................";
string lastInterest;
    bool found4;
    string name;
    string age;
    string balance;
    conn=mysql_init(0);
    if(conn)
    {

      conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from customer_detail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==accountNo)
                    {

                        found4=true;
                        balance=row[1];
                        name=row[2];
                        age=row[3];
                        lastInterest=row[5];

                        break;
                    }
                    else
                    {

                        found4=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }



    if(found4)
    {
        gotoxy(54,9);
        cout<<"Account No:\t\t"<<accountNo;

        gotoxy(54,11);
        cout<<"Balance:\t\t\tRs. "<<balance;
        gotoxy(54,13);
        cout<<"Accout holder name:\t"<<name;

        gotoxy(54,15);
        cout<<"Last Month Interest:\t"<<lastInterest;

         gotoxy(54,17);
        cout<<"Account holder Age:\t"<<age;

        delay(5000);
        operationScreen();

    }

    else
    {
        gotoxy(65,12);
        cout<<"Account Not found";
        delay(4000);
        operationScreen();

    }




}
void Bank::resultantScreen(int chk,string account,string account1,string balance,string balance1)
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"Resultant Section";
    gotoxy(60,3);
    cout<<"|";
    gotoxy(60,4);
    cout<<"|";
    gotoxy(60,5);
    cout<<"|";
    gotoxy(60,6);
    cout<<"|";
    gotoxy(60,7);
    cout<<"|";
    gotoxy(60,8);
    cout<<"|";
    gotoxy(60,9);
    cout<<"|";
    gotoxy(60,10);
    cout<<"|";
    gotoxy(60,11);
    cout<<"|";
    gotoxy(60,12);
    cout<<"|";
    gotoxy(60,13);
    cout<<"|";
    gotoxy(60,14);
    cout<<"|";
    gotoxy(60,15);
    cout<<"|";
    gotoxy(60,16);
    cout<<"|";
    gotoxy(60,17);
    cout<<"|";
    gotoxy(60,18);
    cout<<"|";
    gotoxy(60,19);
    cout<<"|";
    gotoxy(60,20);
    cout<<"|";
    gotoxy(60,21);
    cout<<"|";
    gotoxy(60,22);
    cout<<"|";
    gotoxy(60,23);
    cout<<"|";
    gotoxy(60,24);
    cout<<"|";
    gotoxy(60,25);
    cout<<"|";
    gotoxy(60,26);
    cout<<"|";


    if(chk==0)
    {





        bool found4;
        string name;
        string age;
        string balance;
        conn=mysql_init(0);
        if(conn)
        {

           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

            if(conn)
            {


                qstate=mysql_query(conn,"select * from customer_detail");
                if(!qstate)
                {
                    res=mysql_store_result(conn);
                    while(row=mysql_fetch_row(res))
                    {

                        if(row[0]==account1)
                        {

                            found4=true;
                            balance=row[1];
                            name=row[2];
                            age=row[3];
                            break;
                        }
                        else
                        {

                            found4=false;
                        }





                    }



                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,28);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);

                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);



                }









            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);




            }





        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);
        }


        if(found4)
        {

            gotoxy(10,8);
            cout<<"Before Deposit: ";
            gotoxy(8,10);
            cout<<"-------------------------------------------";
            gotoxy(10,12);
            cout<<"Account No:\t\t"<<account1;

            gotoxy(10,14);
            cout<<"Balance:\t\tRs. "<<balance1;
            gotoxy(10,16);
            cout<<"Accout holder name:\t"<<name;

            gotoxy(10,18);
            cout<<"Accout holder age:\t"<<age;

            gotoxy(8,20);
            cout<<"-------------------------------------------";



            gotoxy(64,8);
            cout<<"After Deposit: ";
            gotoxy(64,10);
            cout<<"-------------------------------------------";
            gotoxy(64,12);
            cout<<"Account No:\t\t"<<account1;

            gotoxy(64,14);
            cout<<"Balance:\t\tRs. "<<balance;
            gotoxy(64,16);
            cout<<"Accout holder name:\t"<<name;

            gotoxy(64,18);
            cout<<"Accout holder age:\t"<<age;

            gotoxy(64,20);
            cout<<"-------------------------------------------";




            delay(5000);




        }

        else
        {


            gotoxy(10,5);
            cout<<"Something goes worong";



            delay(2000);
            operationScreen();




        }











    }

    else if(chk==1)
    {


        bool found4;
        string name;
        string age;
        string balance;
        conn=mysql_init(0);
        if(conn)
        {

           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

            if(conn)
            {


                qstate=mysql_query(conn,"select * from customer_detail");
                if(!qstate)
                {
                    res=mysql_store_result(conn);
                    while(row=mysql_fetch_row(res))
                    {

                        if(row[0]==account1)
                        {

                            found4=true;
                            balance=row[1];
                            name=row[2];
                            age=row[3];
                            break;
                        }
                        else
                        {

                            found4=false;
                        }





                    }



                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,28);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);

                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);



                }









            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);




            }





        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);
        }


        if(found4)
        {

            gotoxy(10,8);
            cout<<"Before Withdrawal: ";
            gotoxy(8,10);
            cout<<"-------------------------------------------";
            gotoxy(10,12);
            cout<<"Account No:\t\t"<<account1;

            gotoxy(10,14);
            cout<<"Balance:\t\tRs. "<<balance1;
            gotoxy(10,16);
            cout<<"Accout holder name:\t"<<name;

            gotoxy(10,18);
            cout<<"Accout holder age:\t"<<age;

            gotoxy(8,20);
            cout<<"-------------------------------------------";



            gotoxy(64,8);
            cout<<"After Withdrawal: ";
            gotoxy(64,10);
            cout<<"-------------------------------------------";
            gotoxy(64,12);
            cout<<"Account No:\t\t"<<account1;

            gotoxy(64,14);
            cout<<"Balance:\t\tRs. "<<balance;
            gotoxy(64,16);
            cout<<"Accout holder name:\t"<<name;

            gotoxy(64,18);
            cout<<"Accout holder age:\t"<<age;

            gotoxy(64,20);
            cout<<"-------------------------------------------";




            delay(5000);




        }

        else
        {


            gotoxy(10,5);
            cout<<"Something goes worong";



            delay(2000);
            operationScreen();




        }









    }
    else if(chk==2)
    {

        bool found4;
        bool found5;
        string name;
        string name1;
        string age;
        string balance3;
        string balance4;
        conn=mysql_init(0);
        if(conn)
        {

           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

            if(conn)
            {


                qstate=mysql_query(conn,"select * from customer_detail");
                if(!qstate)
                {
                    res=mysql_store_result(conn);
                    while(row=mysql_fetch_row(res))
                    {

                        if(row[0]==account)
                        {

                            found4=true;
                            balance3=row[1];
                            name=row[2];

                            break;
                        }
                        else
                        {

                            found4=false;
                        }





                    }



                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,28);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);

                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);



                }









            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);




            }





        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);
        }




        conn=mysql_init(0);
        if(conn)
        {

           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

            if(conn)
            {


                qstate=mysql_query(conn,"select * from customer_detail");
                if(!qstate)
                {
                    res=mysql_store_result(conn);
                    while(row=mysql_fetch_row(res))
                    {

                        if(row[0]==account1)
                        {

                            found5=true;
                            balance4=row[1];
                            name1=row[2];

                            break;
                        }
                        else
                        {

                            found5=false;
                        }





                    }



                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,28);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);

                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);



                }









            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);




            }





        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);
        }



















        if(found4&&found5)
        {

            gotoxy(10,8);
            cout<<"Before Transfer: ";
            gotoxy(8,10);
            cout<<"-------Person who want to transfer--------";
            gotoxy(10,12);
            cout<<"Account No:\t\t"<<account;

            gotoxy(10,14);
            cout<<"Balance:\t\tRs. "<<balance;
            gotoxy(10,16);
            cout<<"Accout holder name:\t"<<name;

            gotoxy(8,18);
            cout<<"----------Person who get balance----------";

            gotoxy(10,20);
            cout<<"Account No:\t\t"<<account1;

            gotoxy(10,22);
            cout<<"Balance:\t\tRs. "<<balance1;
            gotoxy(10,24);
            cout<<"Accout holder name:\t"<<name1;

            gotoxy(8,26);
            cout<<"------------------------------------------";

            gotoxy(64,8);
            cout<<"After Transfer: ";
            gotoxy(64,10);
            cout<<"-------Person who want to transfer--------";
            gotoxy(64,12);
            cout<<"Account No:\t\t"<<account;

            gotoxy(64,14);
            cout<<"Balance:\t\tRs. "<<balance3;
            gotoxy(64,16);
            cout<<"Accout holder name:\t"<<name;

            gotoxy(64,18);
            cout<<"----------Person who get balance----------";

            gotoxy(64,20);
            cout<<"Account No:\t\t"<<account1;

            gotoxy(64,22);
            cout<<"Balance:\t\tRs. "<<balance4;
            gotoxy(64,24);
            cout<<"Accout holder name:\t"<<name1;

            gotoxy(64,26);
            cout<<"------------------------------------------";


            delay(5000);



        }
        else
        {

            gotoxy(10,5);
            cout<<"Something goes worong";



            delay(2000);
            operationScreen();





        }


    }
    else
    {
        system("cls");
        cout<<"Something goes wrong..exiting"<<endl;
        delay(2000);
        exit(0);


    }







}

void Bank::transferBalance()
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"Transfer Section";
    gotoxy(60,3);
    cout<<"|";
    gotoxy(60,4);
    cout<<"|";
    gotoxy(60,5);
    cout<<"|";
    gotoxy(60,6);
    cout<<"|";
    gotoxy(60,7);
    cout<<"|";
    gotoxy(60,8);
    cout<<"|";
    gotoxy(60,9);
    cout<<"|";
    gotoxy(60,10);
    cout<<"|";
    gotoxy(60,11);
    cout<<"|";
    gotoxy(60,12);
    cout<<"|";
    gotoxy(60,13);
    cout<<"|";
    gotoxy(60,14);
    cout<<"|";
    gotoxy(60,15);
    cout<<"|";
    gotoxy(60,16);
    cout<<"|";
    gotoxy(60,17);
    cout<<"|";
    gotoxy(60,18);
    cout<<"|";
    gotoxy(60,19);
    cout<<"|";
    gotoxy(60,20);
    cout<<"|";
    gotoxy(60,21);
    cout<<"|";
    gotoxy(60,22);
    cout<<"|";
    gotoxy(60,23);
    cout<<"|";
    gotoxy(60,24);
    cout<<"|";
    gotoxy(60,25);
    cout<<"|";
    gotoxy(60,26);
    cout<<"|";
    string accountNo;
    string accountNo1;
    gotoxy(3,2);
    cout<<"Enter the information on which balance to be transfer: ";

    gotoxy(10,4);
    cout<<"Account No who want to trasfer: ";
    getline(cin,accountNo);
    gotoxy(10,6);
    cout<<"Account No on which deposit: ";
    getline(cin,accountNo1);
    if(accountNo1==accountNo)
    {

        gotoxy(10,8);
        cout<<"Same account: cannot proceed";
        delay(3000);
        operationScreen();

    }
    long int actualbalance;
    long int citizenshipno;
    string personDeposit;
    long int amount;
    string phone_number;
    bool found4;
    bool found5;
    string name;
    string name1;
    string age;
    string balance;
    string balance1;
    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from customer_detail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==accountNo)
                    {

                        found4=true;
                        balance=row[1];
                        name=row[2];

                        break;
                    }
                    else
                    {

                        found4=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }




    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from customer_detail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==accountNo1)
                    {

                        found5=true;
                        balance1=row[1];
                        name1=row[2];

                        break;
                    }
                    else
                    {

                        found5=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }





















    if(found4&&found5)
    {

        gotoxy(10,8);
        cout<<"Both Account Found: ";
        gotoxy(8,10);
        cout<<"-------Person who want to transfer--------";
        gotoxy(10,12);
        cout<<"Account No:\t\t"<<accountNo;

        gotoxy(10,14);
        cout<<"Balance:\t\tRs. "<<balance;
        gotoxy(10,16);
        cout<<"Accout holder name:\t"<<name;

        gotoxy(8,18);
        cout<<"----------Person who get balance----------";

        gotoxy(10,20);
        cout<<"Account No:\t\t"<<accountNo1;

        gotoxy(10,22);
        cout<<"Balance:\t\tRs. "<<balance1;
        gotoxy(10,24);
        cout<<"Account holder name:\t"<<name1;

        gotoxy(8,26);
        cout<<"------------------------------------------";

        string gh;
        string gh1;
        stringstream change(balance);

        change>>actualbalance;


        if(actualbalance<=1000)
        {


            gotoxy(64,6);
            change>>actualbalance;
            cout<<"Cannot proceed tranfer because";
            gotoxy(64,7);
            cout<<"of balance less than 1000....";
            delay(5000);
            operationScreen();
        }

        gotoxy(64,6);
        cout<<"Do you want to proceed (Y, N): ";
ll:
        switch(_getch())
        {

        case 'y':
        case 'Y':

        {


            gotoxy(64,8);
            cout<<"Enter the amount to be withdrawal: ";
            cin>>amount;

            if(actualbalance-amount<=1000)
            {

                gotoxy(64,10);
                cout<<"Cannot proceed withdrawal";
                gotoxy(64,12);
                cout<<"the enter balance is more than account withdrawable";
                gotoxy(64,14);
                cout<<"balance";

                delay(4000);
                operationScreen();


            }





            if(amount<500)
            {
                gotoxy(64,8);
                cout<<"Cannot withdraw balance less than 500";
                delay(2000);
                operationScreen();


            }
        }
tt:
        conn=mysql_init(0);
        if(conn)
        {

           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

            if(conn)
            {


                qstate=mysql_query(conn,"select * from customer_detail");
                if(!qstate)
                {
                    res=mysql_store_result(conn);
                    while(row=mysql_fetch_row(res))
                    {

                        if(row[0]==accountNo)
                        {

                            /* stringstream change(row[1]);
                             long int actualbalance;
                             change>>actualbalance;*/


                            conn=mysql_init(0);

                           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                            if(conn)
                            {

                                qstate=mysql_query(conn,"select * from customer_detail");

                                if(!qstate)
                                {


                                    while(row=mysql_fetch_row(res))
                                    {

                                        if(row[0]==accountNo1)
                                        {

                                            actualbalance=actualbalance-amount;

                                            ostringstream str9;
                                            str9 << actualbalance;
                                            gh = str9.str();


                                            stringstream change1(row[1]);
                                            long int actualbalance2;
                                            change1>>actualbalance2;
                                            actualbalance2=actualbalance2+amount;

                                            ostringstream str10;
                                            str10 << actualbalance2;
                                            gh1 = str10.str();


                                            conn=mysql_init(0);
                                           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                                            if(conn)
                                            {


                                                string update_query = "update customer_detail set balance = '"+gh+"' where account_number = '"+accountNo+"'";

                                                const char* q = update_query.c_str();
                                                qstate = mysql_query(conn, q);

                                                if(!qstate)
                                                {

                                                    if(conn)
                                                    {
                                                        conn=mysql_init(0);

                                                       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                                                        if(conn)
                                                        {


                                                            string update_query = "update customer_detail set balance = '"+gh1+"' where account_number = '"+accountNo1+"'";

                                                            const char* q = update_query.c_str();
                                                            qstate = mysql_query(conn, q);

                                                            if(!qstate)
                                                            {
                                                             //   saveReport(0,0,0,0,0,0,0,amount,accountNo,accountNo1,)
                                                                saveReport(4,"","",0,"","",0,"","",amount,accountNo,accountNo1,"","","","");
                                                                gotoxy(64,11);
                                                                cout<<"Transfer Successful...";
                                                                delay(3000);
                                                                resultantScreen(2,accountNo,accountNo1,balance,balance1);

                                                            }
                                                            else
                                                            {

                                                                system("cls");
                                                                gotoxy(0,0);
                                                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                                gotoxy(0,28);
                                                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                                gotoxy(0,0);

                                                                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                                                cout<<"\n\n\t\t\t\tExiting...................";
                                                                delay(2000);



                                                            }









                                                        }
                                                        else
                                                        {


                                                            system("cls");
                                                            gotoxy(0,0);
                                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                            gotoxy(0,29);
                                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                            gotoxy(0,0);
                                                            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                                            cout<<"\n\n\t\t\t\tExiting...................";
                                                            delay(2000);
                                                            exit(0);




                                                        }





                                                    }
                                                    else
                                                    {

                                                        system("cls");
                                                        gotoxy(0,0);
                                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                        gotoxy(0,29);
                                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                        gotoxy(0,0);
                                                        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                                                        cout<<"\n\n\t\t\t\tExiting...................";
                                                        delay(2000);
                                                        exit(0);
                                                    }





                                                }
                                                else
                                                {

                                                    system("cls");
                                                    gotoxy(0,0);
                                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                    gotoxy(0,28);
                                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                    gotoxy(0,0);

                                                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                                    cout<<"\n\n\t\t\t\tExiting...................";
                                                    delay(2000);



                                                }









                                            }
                                            else
                                            {


                                                system("cls");
                                                gotoxy(0,0);
                                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                gotoxy(0,29);
                                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                gotoxy(0,0);
                                                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                                cout<<"\n\n\t\t\t\tExiting...................";
                                                delay(2000);
                                                exit(0);




                                            }







                                        }








                                    }










                                }
                                else
                                {

                                    system("cls");
                                    gotoxy(0,0);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,28);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,0);

                                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                    cout<<"\n\n\t\t\t\tExiting...................";
                                    delay(2000);




                                }


                            }
                            else
                            {


                                system("cls");
                                gotoxy(0,0);
                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                gotoxy(0,28);
                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                gotoxy(0,0);

                                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                cout<<"\n\n\t\t\t\tExiting...................";
                                delay(2000);


                            }






















                            break;
                        }






                    }



                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,28);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);

                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);



                }









            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);




            }





        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);
        }















        delay(3000);
        operationScreen();





        case 'n':
        case 'N':
            operationScreen();
        default:
            goto ll;



        }
    }
    else if(found4==true&&found5==false)
    {
        gotoxy(8,9);
        cout<<"-------------------------------------------------";
        gotoxy(8,11);
        cout<<"Sorry, The person in which balance to transferred";
        gotoxy(8,13);
        cout<<"we cannot get account";
        gotoxy(8,15);
        cout<<"-------------------------------------------------";
        delay(5000);
        operationScreen();


    }
    else if(found4==false&&found5==true)
    {
        gotoxy(8,9);
        cout<<"-------------------------------------------------";
        gotoxy(8,11);
        cout<<"Sorry, The person who want to transfer balance";
        gotoxy(8,13);
        cout<<"we cannot get account";
        gotoxy(8,15);
        cout<<"-------------------------------------------------";
        delay(5000);
        operationScreen();


    }
    else
    {
        gotoxy(8,9);
        cout<<"-------------------------------------------------";
        gotoxy(8,11);
        cout<<"Sorry, we cannot get both of the accounts";
        gotoxy(8,13);
        cout<<"-------------------------------------------------";

        delay(5000);
        operationScreen();

    }












}



void Bank::withDrawal()
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"withDrawal Section";
    gotoxy(60,3);
    cout<<"|";
    gotoxy(60,4);
    cout<<"|";
    gotoxy(60,5);
    cout<<"|";
    gotoxy(60,6);
    cout<<"|";
    gotoxy(60,7);
    cout<<"|";
    gotoxy(60,8);
    cout<<"|";
    gotoxy(60,9);
    cout<<"|";
    gotoxy(60,10);
    cout<<"|";
    gotoxy(60,11);
    cout<<"|";
    gotoxy(60,12);
    cout<<"|";
    gotoxy(60,13);
    cout<<"|";
    gotoxy(60,14);
    cout<<"|";
    gotoxy(60,15);
    cout<<"|";
    gotoxy(60,16);
    cout<<"|";
    gotoxy(60,17);
    cout<<"|";
    gotoxy(60,18);
    cout<<"|";
    gotoxy(60,19);
    cout<<"|";
    gotoxy(60,20);
    cout<<"|";
    gotoxy(60,21);
    cout<<"|";
    gotoxy(60,22);
    cout<<"|";
    gotoxy(60,23);
    cout<<"|";
    gotoxy(60,24);
    cout<<"|";
    gotoxy(60,25);
    cout<<"|";
    gotoxy(60,26);
    cout<<"|";
    string accountNo;

    gotoxy(3,2);
    cout<<"Enter the information on which balance to be Withdrawal: ";

    gotoxy(10,3);
    cout<<"Account No: ";
    getline(cin,accountNo);

    long int actualbalance;
    long int citizenshipno;
    string personDeposit;
    long int amount;
    string phone_number;
    bool found4;
    string name;
    string age;
    string balance;
    conn=mysql_init(0);
    string gh ;
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from customer_detail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==accountNo)
                    {

                        found4=true;
                        balance=row[1];
                        name=row[2];
                        age=row[3];
                        break;
                    }
                    else
                    {

                        found4=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }



    if(found4)
    {

        gotoxy(10,6);
        cout<<"Account Found: ";
        gotoxy(8,7);
        cout<<"-------------------------------------------";
        gotoxy(10,9);
        cout<<"Account No:\t\t"<<accountNo;

        gotoxy(10,11);
        cout<<"Balance:\t\tRs. "<<balance;
        gotoxy(10,13);
        cout<<"Accout holder name:\t"<<name;

        gotoxy(10,15);
        cout<<"Accout holder age:\t"<<age;

        gotoxy(8,17);
        cout<<"-------------------------------------------";
        stringstream change(balance);

        change>>actualbalance;


        if(actualbalance<=1000)
        {

            stringstream change(row[1]);
            long int actualbalance;
            gotoxy(10,19);
            change>>actualbalance;
            cout<<"Cannot proceed withdrawal because";
            gotoxy(10,21);
            change>>actualbalance;
            cout<<"of balance less than 1000....";
            delay(5000);
            operationScreen();
        }

        gotoxy(10,19);
        cout<<"Do you want to proceed (Y, N): ";
ll:
        switch(_getch())
        {

        case 'y':
        case 'Y':

        {


            gotoxy(64,6);
            cout<<"Enter the amount to be withdrawal: ";
            cin>>amount;

            if(actualbalance-amount<1000)
            {

                gotoxy(64,9);
                cout<<"Cannot proceed withdrawal";
                gotoxy(64,10);
                cout<<"the enter balance is more than account withdrawable";
                gotoxy(64,11);
                cout<<"balance";

                delay(4000);
                operationScreen();


            }





            if(amount>100000)
            {
                gotoxy(64,8);
                cout<<"The amount is greater than 100000";
                gotoxy(64,9);
                cout<<" so need citizenship no:";
                gotoxy(64,12);
                cout<<"Do u want to proceed:(Y, N): ";
mm:
                switch(_getch())
                {
                case 'y':
                case 'Y':
                    gotoxy(62,13);

                    cout<<"-------------------------------------";
                    gotoxy(64,15);
                    cout<<"Enter the citzenship number: ";
                   // cin>>citizenshipno;cin.clear();
                    gotoxy(64,17);
                    cout<<"Enter name of person who want to deposit: ";
                    gotoxy(67,18);
                    cin>>personDeposit;

                    gotoxy(64,20);
                    cout<<"Enter person's phone number: ";
                    gotoxy(67,21);
                    cin>>phone_number;
                    gotoxy(62,23);
                    cout<<"-------------------------------------";
                    gotoxy(64,25);
                    goto tt;

















                case 'n':
                case 'N':
                    operationScreen();
                    break;
                default:
                    goto mm;

                }


            }
            else if(amount<=10000&&amount>=500)
            {

                gotoxy(62,13);

                cout<<"----------------------------------------";


                gotoxy(64,15);
                cout<<"Enter name of person who want to withdrawal: ";
                gotoxy(67,16);
                cin>>personDeposit;

                gotoxy(64,18);
                cout<<"Enter person's phone number: ";
                gotoxy(67,19);
                cin>>phone_number;
                gotoxy(62,21);
                cout<<"---------------------------------------";
                gotoxy(64,23);








            }
            else
            {
                gotoxy(64,8);
                cout<<"Cannot withdraw balance less than 500";
                delay(2000);
                operationScreen();


            }
        }
tt:
        conn=mysql_init(0);
        if(conn)
        {

           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

            if(conn)
            {


                qstate=mysql_query(conn,"select * from customer_detail");
                if(!qstate)
                {
                    res=mysql_store_result(conn);
                    while(row=mysql_fetch_row(res))
                    {

                        if(row[0]==accountNo)
                        {

                            stringstream change(row[1]);
                            long int actualbalance;
                            change>>actualbalance;


                            actualbalance=actualbalance-amount;

                            ostringstream str9;
                            str9 << actualbalance;
                            gh= str9.str();

                            if(conn)
                            {

                               conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                                if(conn)
                                {


                                    string update_query = "update customer_detail set balance = '"+gh+"' where account_number = '"+accountNo+"'";

                                    const char* q = update_query.c_str();
                                    qstate = mysql_query(conn, q);

                                    if(!qstate)
                                    {

                                        if(conn)
                                        {

                                           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                                            if(conn)
                                            {


                                                string update_query = "update customer_detail set balance = '"+gh+"' where account_number = '"+accountNo+"'";

                                                const char* q = update_query.c_str();
                                                qstate = mysql_query(conn, q);

                                                if(!qstate)
                                                {

                                                    //saveReport(0,0,0,0,0,amount,personDeposit)
                                                    saveReport(3,"","",0,"","",amount,personDeposit,accountNo,0,"","","","","","");
                                                    cout<<"withdrawal Successful...";
                                                    delay(3000);
                                                    //resultantScreen(1,"c",accountNo,"0",balance);
                                                }
                                                else
                                                {

                                                    system("cls");
                                                    gotoxy(0,0);
                                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                    gotoxy(0,28);
                                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                    gotoxy(0,0);

                                                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                                    cout<<"\n\n\t\t\t\tExiting...................";
                                                    delay(2000);



                                                }









                                            }
                                            else
                                            {


                                                system("cls");
                                                gotoxy(0,0);
                                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                gotoxy(0,29);
                                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                                gotoxy(0,0);
                                                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                                cout<<"\n\n\t\t\t\tExiting...................";
                                                delay(2000);
                                                exit(0);




                                            }





                                        }
                                        else
                                        {

                                            system("cls");
                                            gotoxy(0,0);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,29);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,0);
                                            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                                            cout<<"\n\n\t\t\t\tExiting...................";
                                            delay(2000);
                                            exit(0);
                                        }





                                    }
                                    else
                                    {

                                        system("cls");
                                        gotoxy(0,0);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,28);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,0);

                                        cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                        cout<<"\n\n\t\t\t\tExiting...................";
                                        delay(2000);



                                    }









                                }
                                else
                                {


                                    system("cls");
                                    gotoxy(0,0);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,29);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,0);
                                    cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                    cout<<"\n\n\t\t\t\tExiting...................";
                                    delay(2000);
                                    exit(0);




                                }





                            }
                            else
                            {

                                system("cls");
                                gotoxy(0,0);
                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                gotoxy(0,29);
                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                gotoxy(0,0);
                                cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                                cout<<"\n\n\t\t\t\tExiting...................";
                                delay(2000);
                                exit(0);
                            }









                            break;
                        }






                    }



                }
                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,28);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);

                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);



                }









            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);




            }





        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);
        }















        delay(3000);
        operationScreen();





        case 'n':
        case 'N':
            operationScreen();
        default:
            goto ll;



        }
    }
    else
    {

        gotoxy(10,5);
        cout<<"Sorry, Account not found";



        delay(2000);
        operationScreen();


    }






}

void Bank::changeOwnPassword()
{
    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,27);
    t();
    gotoxy(8,27);
    cout<<"Change own password Section";





    gotoxy(100,5);
    cout<<".";
    gotoxy(100,6);
    cout<<".";
    gotoxy(100,7);
    cout<<".";
    gotoxy(100,8);
    cout<<".";
    gotoxy(100,9);
    cout<<".";
    gotoxy(100,10);
    cout<<".";
    gotoxy(100,11);
    cout<<".";
    gotoxy(100,12);
    cout<<".";
    gotoxy(100,13);
    cout<<".";
    gotoxy(100,14);
    cout<<".";
    gotoxy(100,15);
    cout<<".";
    gotoxy(100,16);
    cout<<".";
    gotoxy(100,17);
    cout<<".";
    gotoxy(100,18);
    cout<<".";

    gotoxy(35,5);
    cout<<".";
    gotoxy(35,6);
    cout<<".";
    gotoxy(35,7);
    cout<<".";
    gotoxy(35,8);
    cout<<".";
    gotoxy(35,9);
    cout<<".";
    gotoxy(35,10);
    cout<<".";
    gotoxy(35,11);
    cout<<".";
    gotoxy(35,12);
    cout<<".";
    gotoxy(35,13);
    cout<<".";
    gotoxy(35,14);
    cout<<".";
    gotoxy(35,15);
    cout<<".";
    gotoxy(35,16);
    cout<<".";
    gotoxy(35,17);
    cout<<".";
    gotoxy(35,18);
    cout<<".";

    gotoxy(35,4);
    cout<<"..................................................................";
    gotoxy(35,19);
    cout<<"..................................................................";


    string oldpass,newpass,newpass1;
    int i=0;
    int j=0;
ss:
    gotoxy(37,7);
    cout<<"Enter the old password:";
    oldpass=getpassword();

    bool found4;

    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from admindetail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==adminUsername&&row[1]==oldpass)
                    {

                        found4=true;

                        break;
                    }
                    else
                    {

                        found4=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }






    if(found4)
    {


kk:
        gotoxy(37,12);
        cout<<"Enter the new password:";
        newpass=getpassword();

        gotoxy(37,14);
        cout<<"Re-Enter the new password:";
        newpass1=getpassword();

        if(newpass1==newpass)
        {


            conn=mysql_init(0);

            if(conn)
            {

               conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                if(conn)
                {


                    string update_query = "update admindetail set password = '"+newpass1+"' where user_name = '"+adminUsername+"'";

                    const char* q = update_query.c_str();
                    qstate = mysql_query(conn, q);

                    if(!qstate)
                    {
                          saveReport(7,"","",0,"","",0,"","",0,"","","","",adminUsername,"");
                        //saveReport(0,0,0,0,0,0,0,0,0,0,0,0,adminUsername)

                        gotoxy(37,16);
                        cout<<"Password changed Successful...";
                        delay(2000);
                        operationScreen();
                    }







                    else
                    {

                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,28);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);

                        cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);



                    }









                }
                else
                {


                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);




                }
            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);






            }



        }

        else
        {

            j=j+1;

            if(2-j>=0)
            {

                gotoxy(70,11);
                cout<<"Enter the same password..";

                gotoxy(70,12);
                cout<<"( Remaining attempt: "<<2-j<<" )";
                goto kk;
            }
            else
            {
                gotoxy(37,14);
                cout<<"Sorry cannot change password";
                delay(3000);
                operationScreen();



            }
        }


    }
    else
    {
        i=i+1;

        if(3-i>=0)
        {

            gotoxy(37,6);
            cout<<"Wrong entery of old password..";



            gotoxy(68,6);
            cout<<"Re enter the password";
            gotoxy(70,7);
            cout<<"( Remaining attempt: "<<3-i<<" )";

            goto ss;

        }
        else
        {


            gotoxy(37,9);
            cout<<"You have entered 3 times wrong old password";
            delay(3000);
            operationScreen();
        }

    }











}

void Bank::depositBalance()
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"Deposit Section";
    gotoxy(60,3);
    cout<<"|";
    gotoxy(60,4);
    cout<<"|";
    gotoxy(60,5);
    cout<<"|";
    gotoxy(60,6);
    cout<<"|";
    gotoxy(60,7);
    cout<<"|";
    gotoxy(60,8);
    cout<<"|";
    gotoxy(60,9);
    cout<<"|";
    gotoxy(60,10);
    cout<<"|";
    gotoxy(60,11);
    cout<<"|";
    gotoxy(60,12);
    cout<<"|";
    gotoxy(60,13);
    cout<<"|";
    gotoxy(60,14);
    cout<<"|";
    gotoxy(60,15);
    cout<<"|";
    gotoxy(60,16);
    cout<<"|";
    gotoxy(60,17);
    cout<<"|";
    gotoxy(60,18);
    cout<<"|";
    gotoxy(60,19);
    cout<<"|";
    gotoxy(60,20);
    cout<<"|";
    gotoxy(60,21);
    cout<<"|";
    gotoxy(60,22);
    cout<<"|";
    gotoxy(60,23);
    cout<<"|";
    gotoxy(60,24);
    cout<<"|";
    gotoxy(60,25);
    cout<<"|";
    gotoxy(60,26);
    cout<<"|";
    string accountNo;
    string gh ;
    gotoxy(3,2);
    cout<<"Enter the information on which balance to be deposit: ";

    gotoxy(10,3);
    cout<<"Account No: ";
    getline(cin,accountNo);

//delay(2000);
    long int citizenshipno;
    string personDeposit1;
    long int amount;
    string phone_number;
    bool found4;
    string name;
    string age;
    string balance;
    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from customer_detail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==accountNo)
                    {

                        found4=true;
                        balance=row[1];
                        name=row[2];
                        age=row[3];
                        break;
                    }
                    else
                    {

                        found4=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }



    if(found4)
    {

        gotoxy(10,6);
        cout<<"Account Found: ";
        gotoxy(8,7);
        cout<<"-------------------------------------------";
        gotoxy(10,9);
        cout<<"Account No:\t\t"<<accountNo;

        gotoxy(10,11);
        cout<<"Balance:\t\tRs. "<<balance;
        gotoxy(10,13);
        cout<<"Accout holder name:\t"<<name;

        gotoxy(10,15);
        cout<<"Accout holder age:\t"<<age;

        gotoxy(8,17);
        cout<<"-------------------------------------------";


        gotoxy(10,19);
        cout<<"Do you want to proceed (Y, N): ";
ll:
        switch(_getch())
        {

        case 'y':
        case 'Y':

        {


            gotoxy(64,6);
            cout<<"Enter the amount to be deposit: ";
            cin>>amount;

            if(amount>100000)
            {
                gotoxy(64,8);
                cout<<"The amount is greater than 100000";
                gotoxy(64,9);
                cout<<" so need citizenship no:";
                gotoxy(64,12);
                cout<<"Do u want to proceed:(Y, N): ";
mm:
                switch(_getch())
                {
                case 'y':
                case 'Y':
                    gotoxy(62,13);

                    cout<<"-------------------------------------";
                    gotoxy(64,15);
                    cout<<"Enter the citzenship number: ";
                    cin>>citizenshipno;cin.clear();
                    gotoxy(64,17);
                    cout<<"Enter name of person who want to deposit: ";
                    gotoxy(67,18);
                    cin>>personDeposit1;cin.clear();

                    gotoxy(64,20);
                    cout<<"Enter person's phone number: ";
                    gotoxy(67,21);
                    getline(cin,phone_number);
                    gotoxy(62,23);
                    cout<<"-------------------------------------";
                    gotoxy(64,25);












                    break;





                case 'n':
                case 'N':
                    operationScreen();
                    break;
                    break;
                default:
                    goto mm;

                }


            }
            else if(amount<=10000&&amount>=1000)
            {

                gotoxy(62,13);

                cout<<"----------------------------------------";


                gotoxy(64,15);
                cout<<"Enter name of person who want to deposit: ";
                gotoxy(67,16);
                 cin>>personDeposit1;

                gotoxy(64,18);
                cout<<"Enter person's phone number: ";
                gotoxy(67,19);
                cin>>phone_number;
                gotoxy(62,21);
                cout<<"---------------------------------------";
                gotoxy(64,23);








            }
            else
            {
                gotoxy(64,8);
                cout<<"Cannot deposit balance less than 1000";
                delay(2000);
                operationScreen();


            }

tt:
            string gh;
            conn=mysql_init(0);
            if(conn)
            {

               conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                if(conn)
                {


                    qstate=mysql_query(conn,"select * from customer_detail");
                    if(!qstate)
                    {
                        res=mysql_store_result(conn);
                        while(row=mysql_fetch_row(res))
                        {

                            if(row[0]==accountNo)
                            {










                                stringstream change(row[1]);
                                long int actualbalance;
                                change>>actualbalance;


                                actualbalance=amount+actualbalance;

                                ostringstream str9;
                                str9 << actualbalance;
                                gh= str9.str();
                                conn=mysql_init(0);
                                if(conn)
                                {


                                   conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                                    if(conn)
                                    {


                                        string update_query = "update customer_detail set balance = '"+gh+"' where account_number = '"+accountNo+"'";

                                        const char* q = update_query.c_str();
                                        qstate = mysql_query(conn, q);

                                        if(!qstate)
                                        {

                                            saveReport(2,"","",amount,personDeposit1,accountNo,0,"","",0,"","","","","","");
                                            //saveReport(0,0,0,amount,personDeposit)

                                            cout<<"Deposit Successful...";
                                            delay(2000);
                                            resultantScreen(0,"c",accountNo,"2",balance);
                                        }

                                        else
                                        {

                                            system("cls");
                                            gotoxy(0,0);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,28);
                                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                            gotoxy(0,0);

                                            cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                            cout<<"\n\n\t\t\t\tExiting...................";
                                            delay(2000);



                                        }



                                    }
                                    else
                                    {


                                        system("cls");
                                        gotoxy(0,0);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,29);
                                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                        gotoxy(0,0);
                                        cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                        cout<<"\n\n\t\t\t\tExiting...................";
                                        delay(2000);
                                        exit(0);




                                    }



                                }




                                else
                                {

                                    system("cls");
                                    gotoxy(0,0);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,29);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,0);
                                    cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                                    cout<<"\n\n\t\t\t\tExiting...................";
                                    delay(2000);
                                    exit(0);
                                }
                                break;
                            }


                        }

                    }


                    else
                    {

                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,28);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);

                        cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);



                    }
                }

                else
                {


                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);



                }
            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);


            }



            delay(3000);
            operationScreen();
            break;
        }

        case 'n':
        case 'N':
            operationScreen();
            break;
        default:
            goto ll;




        }
    }
    else
    {

        gotoxy(10,5);
        cout<<"Sorry, Account not found";

        delay(2000);
        operationScreen();


    }



}


void Bank::viewAllAccount()
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,2);
    t();
    gotoxy(8,2);
    cout<<"View All Account Section";

    gotoxy(11,5);
    cout<<"Total Account Found: ";
    gotoxy(0,7);
    int i=1;

    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from customer_detail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "Account No", "Balance", "Name", "Age", "CitizenshipNo");
                while ((row = mysql_fetch_row(res)))
                    while(row=mysql_fetch_row(res))
                    {

                        printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", row[0], row[1], row[2], row[3], row[4]);
                        i++;




                    }

                printf("--------------------------------------------------------------------------------------------------------------------\n");
                gotoxy(11,5);
                cout<<"Total Account Found: "<<i;
            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }



    _getch();

    operationScreen();
}


void Bank::welcomeScreen()
{
    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(50,5);
    cout<<"Welcome";
    gotoxy(53,8);
    cout<<"To";
    gotoxy(35,11);
    cout<<"  Kantipur Banking Transcation System";

    gotoxy(38,14);
    long int code;
    FILE *fptr;
    fptr = fopen("bcode.txt","r");
    fscanf(fptr,"%li",&code);
    fclose(fptr);

    ostringstream str1;



    str1 << code;


    string stringcode = str1.str();

    string b;



    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from bankdetail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==stringcode)
                    {
                        bankname=row[2];
                        cout<<"Branch: "<<row[2];
                        break;
                    }





                }



            }
            else
            {

                system("cls");
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                gotoxy(0,40);




            }









        }
        else
        {


            system("cls");
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            gotoxy(0,28);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(30,20);
            delay(2000);

            exit(0);




        }





    }
    else
    {

        system("cls");
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }
























    gotoxy(35,20);
    cout<<"\n\t\t\t\t\t**********************************"<<endl;
    cout<<"\t\t\t\t\t*--->Press any key to continue.. *"<<endl;
    cout<<"\t\t\t\t\t**********************************"<<endl;
    gotoxy(72,22);
    _getch();
    system("cls");
    loginScreen();







}
void Bank::deleteAccount()
{

    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"Delete Section";
    gotoxy(60,3);
    cout<<"|";
    gotoxy(60,4);
    cout<<"|";
    gotoxy(60,5);
    cout<<"|";
    gotoxy(60,6);
    cout<<"|";
    gotoxy(60,7);
    cout<<"|";
    gotoxy(60,8);
    cout<<"|";
    gotoxy(60,9);
    cout<<"|";
    gotoxy(60,10);
    cout<<"|";
    gotoxy(60,11);
    cout<<"|";
    gotoxy(60,12);
    cout<<"|";
    gotoxy(60,13);
    cout<<"|";
    gotoxy(60,14);
    cout<<"|";
    gotoxy(60,15);
    cout<<"|";
    gotoxy(60,16);
    cout<<"|";
    gotoxy(60,17);
    cout<<"|";
    gotoxy(60,18);
    cout<<"|";
    gotoxy(60,19);
    cout<<"|";
    gotoxy(60,20);
    cout<<"|";
    gotoxy(60,21);
    cout<<"|";
    gotoxy(60,22);
    cout<<"|";
    gotoxy(60,23);
    cout<<"|";
    gotoxy(60,24);
    cout<<"|";
    gotoxy(60,25);
    cout<<"|";
    gotoxy(60,26);
    cout<<"|";
    string accountNo;

    gotoxy(3,2);
    cout<<"Enter the information which you want to delete account: ";

    gotoxy(10,3);
    cout<<"Account No: ";
    getline(cin,accountNo);

    long int actualbalance;
    string citizenshipno;
    string personDeposit;
    long int amount;
    string phone_number;
    bool found4;
    string name;
    string age;
    string balance;
    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from customer_detail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==accountNo)
                    {

                        found4=true;
                        balance=row[1];
                        name=row[2];
                        age=row[3];
                        citizenshipno=row[4];
                        break;
                    }
                    else
                    {

                        found4=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }



    if(found4)
    {

        gotoxy(10,6);
        cout<<"Account Found: ";
        gotoxy(8,7);
        cout<<"-------------------------------------------";
        gotoxy(10,9);
        cout<<"Account No:\t\t"<<accountNo;

        gotoxy(10,11);
        cout<<"Balance:\t\tRs. "<<balance;
        gotoxy(10,13);
        cout<<"Accout holder name:\t"<<name;

        gotoxy(10,15);
        cout<<"Accout holder age:\t"<<age;

        gotoxy(8,17);
        cout<<"-------------------------------------------";

        gotoxy(10,19);
        cout<<"Do you want to proceed to delete(Y, N): ";
ll:
        switch(_getch())
        {

        case 'y':
        case 'Y':



            gotoxy(64,6);
            cout<<"Just wait...account is deleting.. ";







            gotoxy(62,13);

            cout<<"-------------------------------------";
            gotoxy(64,15);

            gotoxy(62,23);
            cout<<"-------------------------------------";

            conn=mysql_init(0);

            if(conn)
            {

               conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                if(conn)
                {


                    string update_query = "delete from customer_detail where account_number = '"+accountNo+"'";

                    const char* q = update_query.c_str();
                    qstate = mysql_query(conn, q);

                    if(!qstate)
                    {

                        conn=mysql_init(0);
                        if(conn)
                        {
                           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                            if(conn)
                            {

                                string query="insert into passivecustomer(account_number,name,age,citizenshipNo) values('"+accountNo+"','"+name+"','"+age+"','"+citizenshipno+"')";


                                const char* q = query.c_str();

                                qstate = mysql_query(conn,q);

                                if(!qstate)
                                {





                                }


                                else
                                {

                                    system("cls");
                                    gotoxy(0,0);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,28);
                                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                    gotoxy(0,0);

                                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                                    cout<<"\n\n\t\t\t\tExiting...................";
                                    delay(2000);





                                }




                            }
                            else
                            {


                                system("cls");
                                gotoxy(0,0);
                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                gotoxy(0,29);
                                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                                gotoxy(0,0);
                                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                                cout<<"\n\n\t\t\t\tExiting...................";
                                delay(2000);
                                exit(0);



                            }


                        }
                        else
                        {

                            system("cls");
                            gotoxy(0,0);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,29);
                            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                            gotoxy(0,0);
                            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                            cout<<"\n\n\t\t\t\tExiting...................";
                            delay(2000);
                            exit(0);


                        }







                        //saveReport(0,0,0,0,0,0,0,0,0,0,0,accountNo,)
                          saveReport(6,"","",0,"","",0,"","",0,"","","",accountNo,"","");

                        gotoxy(64,17);
                        cout<<"Account deleted Successful...";

                    }







                    else
                    {

                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,28);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);

                        cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);



                    }









                }
                else
                {


                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);




                }
            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);






            }








            delay(3000);
            operationScreen();


            break;


        case 'n':
        case 'N':
            operationScreen();
        default:
            goto ll;



        }
    }
    else
    {

        gotoxy(10,5);
        cout<<"Sorry, Account not found";



        delay(2000);
        operationScreen();


    }
















}

void Bank::addAdmin()
{



    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;

    gotoxy(87,27);
    t();
    gotoxy(10,27);
    cout<<"Add Admin Section";

    gotoxy(35,3);
    cout<<"Enter the following information to register an account:";


    gotoxy(100,5);
    cout<<".";
    gotoxy(100,6);
    cout<<".";
    gotoxy(100,7);
    cout<<".";
    gotoxy(100,8);
    cout<<".";
    gotoxy(100,9);
    cout<<".";
    gotoxy(100,10);
    cout<<".";
    gotoxy(100,11);
    cout<<".";
    gotoxy(100,12);
    cout<<".";
    gotoxy(100,13);
    cout<<".";
    gotoxy(100,14);
    cout<<".";
    gotoxy(100,15);
    cout<<".";
    gotoxy(100,16);
    cout<<".";
    gotoxy(100,17);
    cout<<".";
    gotoxy(100,18);
    cout<<".";

    gotoxy(35,5);
    cout<<".";
    gotoxy(35,6);
    cout<<".";
    gotoxy(35,7);
    cout<<".";
    gotoxy(35,8);
    cout<<".";
    gotoxy(35,9);
    cout<<".";
    gotoxy(35,10);
    cout<<".";
    gotoxy(35,11);
    cout<<".";
    gotoxy(35,12);
    cout<<".";
    gotoxy(35,13);
    cout<<".";
    gotoxy(35,14);
    cout<<".";
    gotoxy(35,15);
    cout<<".";
    gotoxy(35,16);
    cout<<".";
    gotoxy(35,17);
    cout<<".";
    gotoxy(35,18);
    cout<<".";

    gotoxy(35,4);
    cout<<"..................................................................";
    gotoxy(35,19);
    cout<<"..................................................................";


    string usname,password;
    gotoxy(37,7);
    cout<<"Enter the user_name: ";
    getline(cin,usname);
    gotoxy(37,9);
    cout<<"Enter the password: ";
    password=getpassword();
    bool found5=false;
    bool found7;
    bool found4;
    conn=mysql_init(0);
    if(conn)
    {
       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {

            qstate=mysql_query(conn,"select * from admindetail");

            if(!qstate)
            {


                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==usname)
                    {

                        found4=true;

                    }
                    else
                    {

                        found4=false;
                    }





                }

            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);





            }




        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);



        }







    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);





    }

    if(found4)
    {

        string usname2;
        gotoxy(37,11);
        cout<<"Already existing user name...re-enter unique uname";
        gotoxy(37,13);
        cout<<"Enter the user_name: ";
        getline(cin,usname2);

            conn=mysql_init(0);
    if(conn)
    {
       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {

            qstate=mysql_query(conn,"select * from admindetail");

            if(!qstate)
            {


                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==usname2)
                    {

                      found7=true;

                    }





                }

            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);





            }




        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);



        }







    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);





    }












        if(found7)
        {


            gotoxy(37,14);
            cout<<"Cannot create account.. ";
            delay(3000);
            operationScreen();






        }
        else
        {







            conn=mysql_init(0);
            if(conn)
            {
               conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

                if(conn)
                {

                    string query="insert into admindetail(user_name,password) values('"+usname2+"','"+password+"')";


                    const char* q = query.c_str();

                    qstate = mysql_query(conn,q);

                    if(!qstate)
                    {
                        //saveReport(0,0,0,0,0,0,0,0,0,0,0,0,0,usname2)
                        saveReport(8,"","",0,"","",0,"","",0,"","","","","",usname2);

                        gotoxy(37,15);
                        cout<<"Account created successfully";

                        delay(3000);
                        operationScreen();


                    }


                    else
                    {

                        system("cls");
                        gotoxy(0,0);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,28);
                        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                        gotoxy(0,0);

                        cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                        cout<<"\n\n\t\t\t\tExiting...................";
                        delay(2000);





                    }




                }
                else
                {


                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,29);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);
                    cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);
                    exit(0);



                }







            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);





            }





        }
    }
    else
    {



        conn=mysql_init(0);
        if(conn)
        {
           conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

            if(conn)
            {

                string query="insert into admindetail(user_name,password) values('"+usname+"','"+password+"')";


                const char* q = query.c_str();

                qstate = mysql_query(conn,q);

                if(!qstate)
                {
                     saveReport(8,"","",0,"","",0,"","",0,"","","","","",usname);

                    gotoxy(37,11);
                    cout<<"Account created successfully";

                    delay(3000);
                    operationScreen();


                }


                else
                {

                    system("cls");
                    gotoxy(0,0);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,28);
                    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                    gotoxy(0,0);

                    cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                    cout<<"\n\n\t\t\t\tExiting...................";
                    delay(2000);





                }




            }
            else
            {


                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);
                exit(0);



            }







        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);





        }












    }





}


void Bank::moreOption()
{



    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;



    gotoxy(24,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 OTHER OPTIONS");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(24,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Delete Account  ");
    gotoxy(24,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. View all account");
    gotoxy(24,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Change own password ");
    gotoxy(24,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Add Admin");
    gotoxy(24,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. See deleted account ");
    gotoxy(24,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. See report ");
    gotoxy(24,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Back to Main Menu");
    gotoxy(24,19);
    printf("\xDB\xDB\xDB\xDB\xB2 8. Close Application");
    gotoxy(24,20);
    printf("------------------------------------------");
    gotoxy(87,27);
    t();
    gotoxy(24,21);
    printf("Enter your choice:");
    switch(_getch())
    {
    case '1':
        deleteAccount();
        break;
    case '2':
        viewAllAccount();
        break;
    case '3':
        changeOwnPassword();
        break;
    case '4':
        addAdmin();
        break;
    case '5':
        viewAllDelAccount();
        break;
    case '6':
        seeReport();
        break;
    case '7':
        operationScreen();
        break;
    case '8':
    {
        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,28);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;


        gotoxy(16,3);
        printf("Thanks for using the Program..");
        gotoxy(10,7);
        printf("Exiting in 5 second...........>");
        //flushall();
        delay(3000);
        exit(0);
    }
    default:
    {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(_getch())
            moreOption();
    }

    }


}


void Bank::operationScreen()
{
    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;

    gotoxy(87,27);
    t();

    gotoxy(29,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(29,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Deposit");
    gotoxy(63,5);
    printf("\xDB\xDB\xDB\xDB\xB2");
    gotoxy(29,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Withdrawal");
    gotoxy(63,7);
    printf("\xDB\xDB\xDB\xDB\xB2");
    gotoxy(29,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Transfer");
    gotoxy(63,9);
    printf("\xDB\xDB\xDB\xDB\xB2");
    gotoxy(29,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Search Account");
    gotoxy(63,11);
    printf("\xDB\xDB\xDB\xDB\xB2");
    gotoxy(29,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Add Account");
    gotoxy(63,13);
    printf("\xDB\xDB\xDB\xDB\xB2");
    gotoxy(29,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. More...");
    gotoxy(63,15);
    printf("\xDB\xDB\xDB\xDB\xB2");
    gotoxy(29,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
    gotoxy(63,17);
    printf("\xDB\xDB\xDB\xDB\xB2");
    gotoxy(29,19);
    printf("------------------------------------------");

    gotoxy(29,22);
    printf("Enter your choice: _______________");
    gotoxy(50,21);
    switch(_getch())
    {
    case '1':
        depositBalance();
        break;
    case '2':
        withDrawal();
        break;
    case '3':
        transferBalance();
        break;
    case '4':
        searchAccount();
        break;
    case '5':
        addAccount();
        break;
    case '6':
        moreOption();
        break;
    case '7':
    {
        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,28);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;


        gotoxy(30,12);
        printf("Thanks for using the Program..");
        gotoxy(30,14);
        printf("Exiting in 5 second...........>");
        gotoxy(30,19);
        delay(3000);

        exit(0);
    }
    default:
    {
        gotoxy(24,25);
        printf("\aWrong Entry!!Please re-entered correct option.....");
        if(_getch())
            operationScreen();
    }

    }
























}


void Bank::loginScreen()
{
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,28);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,0);
    string ausername,apassword;

    bool found2;
    gotoxy(38,8);
    cout<<"Enter the following information:"<<endl;
    gotoxy(37,9);
    cout<<"*************************************";
    gotoxy(37,11);

    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t\t\tEnter the User name:"<<endl;
    cout<<"\n\n\n\t\t\t\t\t__________________";
    gotoxy(40,18);
    getline(cin,ausername); //cin.clear();
    cout<<"\n\n\n\t\t\t\t\tEnter the password of your bank: "<<endl;

    cout<<"\n\n\t\t\t\t\t__________________";
    gotoxy(40,24);

    apassword=getpassword();
    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select user_name,password from admindetail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==ausername&&row[1]==apassword)
                    {
                        adminUsername=ausername;
                        found2=true;
                        break;
                    }
                    else
                    {

                        found2=false;
                    }





                }



            }
            else
            {

                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,28);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);

                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);



            }









        }
        else
        {


            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);




        }





    }
    else
    {

        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);
    }


    if(found2)
    {

        saveReport(1,"",ausername,0,"","",0,"","",0,"","","","","","");
        loaderanim();
        operationScreen();
    }
    else
    {
        system("cls");
        int a=Bank::countt();
        gotoxy(4,2);
        cout<<"\t\t\t\tRe-enter Your Informations : ";
        gotoxy(40,18);
        cout<<"\t\t(Remaining attempt: "<<3-a<<")";


        if(a==3)
        {
            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\n\n\t\t\t\tyou have inputted 3 times worng information....exiting";
            gotoxy(30,20);
            delay(2000);
            exit(0);

        }
        else
        {

            loginScreen();

        }

    }
















}



void Bank::guideScreen()
{
    bool found1;
    string bcode,bpassword;
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,29);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,0);

    cout<<"\n\n\n\n\n\n"<<endl;
    cout<<"\t\t\t\t\t******************************************"<<endl;
    cout<<"\t\t\t\t\t Before Proceed\n\n\t\t\t\t\t Please enter the following information"<<endl;
    cout<<"\t\t\t\t\t******************************************"<<endl;

    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t\t\tEnter the code of your bank:"<<endl;
    cout<<"\n\n\t\t\t\t\t__________________";
    gotoxy(40,18);
    getline(cin,bcode);
    cout<<"\n\n\n\t\t\t\t\tEnter the password of your bank: "<<endl;

    cout<<"\n\n\t\t\t\t\t__________________";
    gotoxy(40,24);

    bpassword=getpassword();


    conn=mysql_init(0);
    if(conn)
    {

       conn = mysql_real_connect(conn,"sql12.freemysqlhosting.net","sql12238622","zfBpw2Ne8j","sql12238622",3306,NULL,0);

        if(conn)
        {


            qstate=mysql_query(conn,"select * from bankdetail");
            if(!qstate)
            {
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {

                    if(row[0]==bcode&&row[1]==bpassword)
                    {


                         saveReport(0,row[2],"",0,"","",0,"","",0,"","","","","","");

                        found1=true;
                        break;
                    }
                    else
                    {

                        found1=false;
                    }





                }



            }
            else
            {
                system("cls");
                gotoxy(0,0);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,29);
                cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
                gotoxy(0,0);
                cout<<"\n\n\n\n\n\t\t\t\tCannot execute query ";
                cout<<"\n\n\t\t\t\tExiting...................";
                delay(2000);

            }









        }
        else
        {

            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,28);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\t\t\t\tCannot connect to the Internet"<<endl;
            cout<<"\n\n\t\t\t\tExiting...................";
            delay(2000);
            exit(0);



        }





    }
    else
    {
        system("cls");
        gotoxy(0,0);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,29);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        gotoxy(0,0);
        cout << "\n\n\n\n\n\t\t\t\tCannot connect with the server! this error" << mysql_errno(conn) << endl;
        cout<<"\n\n\t\t\t\tExiting...................";
        delay(2000);
        exit(0);

    }


    if(found1)
    {
        ofstream myfile;
        myfile.open("isExist.txt");
        myfile.close();
        stringstream geek(bcode);
        long int x;
        geek >> x;
        FILE *fptr;
        fptr = fopen("bcode.txt","w");
        fprintf(fptr,"%li",x);
        fclose(fptr);




        system("cls");
        welcomeScreen();

    }
    else
    {
        system("cls");
        int a=Bank::countt();
        gotoxy(4,2);
        cout<<"\n\t\t\t\tRe-enter the Informations of bank: ";
        gotoxy(40,18);
        cout<<"\t\t( Remaining attempt: "<<3-a<<")";


        if(a==3)
        {
            system("cls");
            gotoxy(0,0);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,29);
            cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
            gotoxy(0,0);
            cout<<"\n\n\n\n\n\n\n\t\t\t\tyou have inputted 3 times worng information....exiting";
            delay(2000);
            exit(0);

        }
        else
        {

            guideScreen();

        }
    }

}

void Bank::fileCreation()
{
    system("cls");
    gotoxy(0,0);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,29);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Kantipur Banking Transcation Processing System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    gotoxy(0,0);
    if(found)
    {
        welcomeScreen();

    }
    else
    {

        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tHere you have installed \n\n\t\t\t\t\tthis software of kantipur banking transcation \n\n\t\t\t\t\tprocessing system for the first time"<<endl;

        cout<<"\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t**********************************"<<endl;
        cout<<"\t\t\t\t\t*--->Press any key to continue.. *"<<endl;
        cout<<"\t\t\t\t\t**********************************"<<endl;
        gotoxy(72,24);
        _getch();
        system("cls");
        guideScreen();

    }
}

int main()
{

    Bank bank;
//    bank.addAdmin();
//bank.seeReport();
    bank.fileCreation();
    return 0;
}
