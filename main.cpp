#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

class Address
{
protected:
    string name;
    string father_name;
    string mother_name;
    int postal_code;
    string upozilla;
    string district;
    string mobile;
    string email;

public :

    Address(){}
    Address(string a, string b, string c, int d, string e, string f, string g, string h)
    {
        name = a;
        father_name = b;
        mother_name = c;
        postal_code = d;
        upozilla = e;
        district = f;
        mobile = g;
        email = h;
    }

};

class Academic
{
private:
    string school;
    string college;
    float ssc_gpa;
    float hsc_gpa;
    float HSC_PCME_GP;
public:
    Academic(){}
    void input(string a, string b, float c, float d, float e)
    {
        school = a ;
        college = b ;
        ssc_gpa = c ;
        hsc_gpa = d ;
        HSC_PCME_GP = e ;

    }
   friend istream& operator>>(istream& in,Academic &m)
   {
       char a;
       cout << "School : "; cin >> a;
       getline(in,m.school);
       cout << "College : ";
       getline(in,m.college);
       cout << "SSC GPA : ";
       in >> m.ssc_gpa;
       cout << "HSC GPA : ";
       in >> m.hsc_gpa;
       cout << "HSC PHY, CHEM, MATH, ENG total GP : ";
       in >> m.HSC_PCME_GP;

       cout  << "\nForm Fill Up is Completed\n\n";
       return in;
   }

   float get_point();

};

 float Academic :: get_point()
 {
     return HSC_PCME_GP;
 }

class Student : public Address
{
protected:
    Academic stdnt;
    int roll_no;
    int form_no;
public:

    Student(){}

    Student(string m, string n, string o, int p, string q, string r, string s, string t, int i, int j, string a, string b, float c, float d, float e) :
        Address(m,  n,  o,  p,  q,  r,  s,  t)
    {
        roll_no = i ;
        form_no = j ;
        stdnt.input(a,b,c,d,e);

    }
    friend istream& operator>>(istream& in, Student& M)
    {
        //char a;

        cout << "\nEnter Applicant Name : "; getchar();//cin >> a;
        getline(in,M.name);
        cout << "Enter Father's Name : ";
        getline(in,M.father_name);
        cout << "Enter mother's Name : ";
        getline(in,M.mother_name);
        cout << "Enter Postal Code(Integer) : ";
        in >> M.postal_code;
        cout << "Enter Upozilla : ";getchar();//cin >> a;
        getline(in,M.upozilla);
        cout << "Enter Distric : ";
        getline(in,M.district);
        cout << "Enter  Mobile No. : ";
        getline(in,M.mobile);
        cout << "Enter  Email ID : ";
        getline(in,M.email);
        cout << "Enter  Admission Roll No.(4 digit) : ";
        in >> M.roll_no;
        cout << "Enter  Form No.(6 digit) : ";
        in >> M.form_no;

        cout << "\n\n ************  Applicant's Academic Information **************\n";
        cout << "_______________________________________________________________\n\n";
        in >> M.stdnt;

        return in;

    }

     string get_name();
     int get_roll();
     int get_form_no();
    float getp();
};

string Student :: get_name()
{
    return name;
}

int Student :: get_roll()
{
    return roll_no;
}

int Student :: get_form_no()
{
    return form_no;
}

float Student :: getp()
{
    return stdnt.get_point();
}

class Eligible_List
{
private:
    string name;
    int roll_no;
    int form_no;
public:
    friend ostream& operator<<(ostream &out,Eligible_List &E)
    {
        out << E.name << "      " << E.roll_no << "         " << E.form_no << "\n\n";

        return out;
    }
    bool check_point(Student&);

    bool searching(int R,Eligible_List &G)
    {
        if(R==G.roll_no)
        {
            cout << " Name" << "       Roll " << "        Form No\n\n";
             cout << G.name << "      " << G.roll_no << "         " << G.form_no << "\n\n";
             return true;
        }
        else
            return false;

    }

string get_name()
{
    return name;
}

int get_roll()
{
    return roll_no;
}

int get_form_no()
{
    return form_no;
}


};

bool Eligible_List :: check_point(Student &S)
{
      if(S.getp()>=19)
      {
            name=S.get_name();
            roll_no=S.get_roll();
            form_no=S.get_form_no();

            return true;
      }

    else return false;

}
void disp(int c)
{
    switch(c)
    {
    case 1:
        cout << "\nYou chose Khulna University of Engineering & Technology(KUET)\n";
        break;
    case 2:
        cout << "\nYou chose Bangladesh University of Engineering & Technology(BUET)\n";
        break;
        case 3:
        cout << "\nYou chose Rajshahi University of Engineering & Technology(RUET)\n";
        break;
        case 4:
        cout << "\nYou chose Chitagong University of Engineering & Technology(CUET)\n";
        break;

        default:
            cout << "Code Error\n";
            break;
    }
}


class Result
{
private:
    string name;
    int roll_no;
    int form_no;
    float mark;
    int merit;
public:
    void put_value(float m,int n,Eligible_List &S)
    {
        name=S.get_name();
        roll_no=S.get_roll();
        form_no=S.get_form_no();
        mark=m;
        merit=n;


    }

    bool search_result(int R,Result &Res);

    friend ostream& operator<<(ostream &out,Result &E)
    {
        out << E.name << "      " << E.roll_no << "         " << E.form_no << "         " << E.merit << "      " << E.mark << "\n\n";

        return out;
    }

};

bool Result :: search_result(int R,Result &Res)
{
   if(R==Res.roll_no)
        {
            cout << " Name" << "       Roll " << "        Form No" << "       Merit" << "      Marks"<<"\n\n\n";
             cout << Res.name << "      " << Res.roll_no << "         " << Res.form_no << "      "<< Res.merit << "     " << Res.mark << "\n\n";
             return true;
        }
        else
            return false;
}


int main()
{

    Student student[20] ={
        Student("A.Aziz","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4698,101388,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,19.0),
        Student("Masum","Iasmin Akter","Abdur Rashid",2031,"Rangpur","Rangpur","01770900052","masumcpscr@gamil.com",4699,101389,"Cantonment high school","Canpublic college,Rangpur",5.0,5.0,20.0),
        Student("Dipto","Shamseara Begum","Mostafizar Rahman",2031,"Rangpur","Rangpur","01718268856","diptomontasir@gamil.com",4700,101390,"Cantonment high school","Canpublic college,Rangpur",5.0,5.0,20.0),
        Student("Shawon","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4701,101391,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,20.0),
        Student("Nafew","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4702,101392,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,19.0),
        Student("Shakib","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4703,101393,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,19.0),
        Student("Karim","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4704,101394,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,19.0),
        Student("Rahim","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4705,101395,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,20.0),
        Student("Tanim","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4706,101396,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,19.0),
        Student("Tomal","Sanowar Hosen","Sufia Begum",2030,"Dewngonj","Jamalpur","01753258105","kuet2012@gmail.com",4707,101397,"Hativanga A.B high school","Najrul college,Mymensingh",5.0,5.0,20.0),
    };


      int code,i=10;

         cout << "\n**************  WELCOME TO ADMISSION BATTLE FIELD  ******************\n\n\n";
         cout << "Code 1 : Khulna University of Engineering & Technology(KUET)\n";
         cout << "Code 2 : Bangladesh University of Engineering & Technology(BUET)\n";
         cout << "Code 3 : Rajshahi University of Engineering & Technology(RUET)\n";
         cout << "Code 4 : Chitagong University of Engineering & Technology(CUET)\n\n";
         cout << "\nEnter University code for fill up it's form : ";
         cin >> code ;
        disp(code);

         if(code==1||code==2||code==3||code==4)
         {

        int digit;
        do
        {
             cin >> student[i++];
             cout << "\nEnter 1 to fill up another form  Or Other Digit to exit from here\n\n";
             cin >> digit;
        }while(digit==1);


        Eligible_List Elist[20];
        int k=0;
        bool m;
        for(int j=0;j<i;j++)
        {
            m=Elist[k].check_point(student[j]);
            if(m==true)
                k++;
        }

        Result res[20];
        float mar=400.5;
        int merit=100;
        for(int d=0;d<k;d++)
        {
            res[d].put_value(mar,merit,Elist[d]);
            mar=mar-2.3*2.2;
            merit = merit +2*3;
        }

          cout << "\n    Description About Eligible List\n";
          cout << "   _________________________________\n\n";
          int b;
         do
         {
             cout << "Enter 1 to show Total Eligible List : \n";

             cout << "Enter 2 to search Eligible List : \n";

             cout << "Enter 3 to Exit from Here : \n";
             cin >> b;

             switch(b)
             {
             case 1:
                cout << "\n\n\tEligible List\n";
                cout << "     ______________\n\n";
                cout << " Name" << "       Roll " << "        Form No\n\n";
                for(int a=0;a<k;a++)
                      cout << Elist[a];
                break;

             case 2:
                 int R;
                 bool m;
                 Eligible_List P;
                cout << "\nEnter Roll Number : ";
                cin >> R;
                 for(int a=0;a<k;a++)
                 {
                     m=P.searching(R,Elist[a]);
                     if(m==true)
                        break;
                 }
                 if(m==false)
                    cout << "\nNot Found\n\n";
                break;

             }


         }while(b!=3);


         cout << "\n   Description About Result List\n";
         cout << "  ________________________________\n\n";

         do
         {
             cout << "Enter 1 to show Total Result List : \n";

             cout << "Enter 2 to search Result List : \n";

             cout << "Enter 3 to Exit from Here : \n";
             cin >> b;

             switch(b)
             {
             case 1:
                cout << "\n\n\t\tResult List\n";
                cout << "\t      ____________\n\n";
                cout << " Name" << "       Roll " << "        Form No" << "       Merit" << "      Marks"<<"\n\n\n";

                for(int a=0;a<k;a++)
                      cout << res[a];
                break;

             case 2:
                 int R;
                 bool m;
                 Result Q;
                cout << "\nEnter Roll Number : ";
                cin >> R;
                 for(int a=0;a<k;a++)
                 {
                     m=Q.search_result(R,res[a]);
                     if(m==true)
                        break;
                 }
                 if(m==false)
                    cout << "\nResult Not Found\n\n";
                break;

             }


         }while(b!=3);

    cout << "\n\nProgram Exited!\n" << endl;
         }
         else
         {
             main();
              //cout << "\nCode Error\n";
         }

    return 0;
}
