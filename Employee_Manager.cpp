#include<iostream>
using namespace std;
class employee{
    protected:
    int e_id;
    float salary;
    string name;
    public:
    virtual void display()=0;
    virtual void input(){
        cout<<"\nEnter Employee details:\n";
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter Id: ";
        cin>>e_id;
        cout<<"Enter salary (LPA): ";
        cin>>salary;
    }
};

class teacher:public employee{
    private:
    string subject;
    public:
    void input(){
            employee::input();
            cout<<"Enter subject: ";
            cin>>subject;
        }
        void display(){
            if(!subject.empty()){
                cout<<"\nDisplaying teacher's details:\n";
                cout<<"Name: "<<name<<endl;
                cout<<"Id: "<<e_id<<endl;
                cout<<"Salary: "<<salary<<"(LPA)"<<endl;
                cout<<"Subject: "<<subject<<endl;
            }    
        }
};

class professor:public employee{
    private:
    string department;
    public:
    void input(){
            employee::input();
            cout<<"Enter department: ";
            cin>>department;
        }
        void display(){
            if(!department.empty()){
                cout<<"\nDisplaying professor's details:\n";
                cout<<"Name: "<<name<<endl;
                cout<<"Id: "<<e_id<<endl;
                cout<<"Salary: "<<salary<<"(LPA)"<<endl;
                cout<<"Department: "<<department<<endl;
            }
        } 
};

class staff:public employee{
    private:
    int clas=0;
    public:
    void input(){
            employee::input();
            cout<<"Enter class: ";
            cin>>clas;
        }
        void display(){
            if(clas!=0){
                cout<<"\nDisplaying staff's details:\n";
                cout<<"Name: "<<name<<endl;
                cout<<"Id: "<<e_id<<endl;
                cout<<"Salary: "<<salary<<"(LPA)"<<endl;
                cout<<"Class: "<<clas<<endl;
            }
        }
};

int main(){
    employee* tptr = new teacher;
    employee* pptr = new professor;
    employee* sptr = new staff;
    int c=1;
    while (c){
        int s=1;
        cout<<"Enter your choice:\n";
        cout<<"1: Input details\n";
        cout<<"2: Display details\n";
        cout<<"3: Exit\n";
        cout<<"Choice: ";
        cin>>c;
        switch(c){
        case 1:
        
        
            cout<<"Select employee type:\n";
            cout<<"1: Teacher\n";
            cout<<"2: Professor\n";
            cout<<"3: Staff\n";
            cin>>s;
          switch(s){
            case 1:
            tptr->input();
            break;
            case 2:
            pptr->input();
            break;
            case 3:
            sptr->input();
            break;
            default:
            s=0;
        }
        break;
        case 2:
        tptr->display();
        pptr->display();
        sptr->display();
        break;
        case 3:
        c=0;
        break;
        default:
        cout<<"Enter another choice!\n";
    }}
}