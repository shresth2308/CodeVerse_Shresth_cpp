#include<iostream>
using namespace std;

class Flower;
class ChocolateBox;
class LoveLetter;

class RomanticGift{
    protected:
    string sname;
    string rname;
    int price;
    public:
    void input(){
        cout<<"\n*Enter Details*\n";
        cout<<"Sender's Name: ";
        getline(cin,sname);
        cout<<"Receiver's Name: ";
        getline(cin,rname);
        cout<<"Price: $";
        cin>>price;
        cout<<endl;
    }
    void display(){
        cout<<"\n***Displaying Details***\n\n";
        cout<<"Sender's Name: "<<sname<<endl;
        cout<<"Receiver's Name: "<<rname<<endl;
        cout<<"Price: $"<<price<<endl;
    }
    
    friend void printGiftDetails(RomanticGift, Flower, ChocolateBox, LoveLetter);
};

class Flower : public RomanticGift{
    private:
    string type, colour, style;
    public:
    void inputDetails(){
        cout<<"\nEnter Details for Flower:\n";
        cout<<"Type: ";
        getline(cin,type);
        cout<<"Colour: ";
        getline(cin,colour);
        cout<<"Stored Sucessfully!"<<endl;
    }
    void displayDetails(){
        if(!type.empty() && !colour.empty()){
            cout<<"\nDisplaying Details for Flower:\n";
            cout<<"Type: "<<type<<endl;
            cout<<"Colour: "<<colour<<endl;
        }
    }
};

class ChocolateBox : public RomanticGift{
    private:
    string type, flavour;
    int quantity;
    public:
    void inputDetails(){
        cout<<"\nEnter Details for Chocolate Box:\n";
        cout<<"Type: ";
        getline(cin,type);
        cout<<"Flavour: ";
        getline(cin,flavour);
        cout<<"Quantity: ";
        cin>>quantity;
        cout<<"Stored Sucessfully!"<<endl;
    }
    void displayDetails(){
        if(!type.empty() && !flavour.empty() && quantity>0){
            cout<<"\nDisplaying Details for Chocolate Box:\n";
            cout<<"Type: "<<type<<endl;
            cout<<"Flavour: "<<flavour<<endl;
            cout<<"Quantity: "<<quantity<<endl;
        }
    }
};

class LoveLetter : public RomanticGift{
    private:
    string content, style;
    public:
    void inputDetails(){
        cout<<"\nEnter Details for Love Letter:\n";
        cout<<"Content: ";
        getline(cin,content);
        cout<<"Style: ";
        getline(cin,style);
        cout<<"Stored Sucessfully!"<<endl;
    }
    void displayDetails(){
        if(!content.empty() && !style.empty()){
            cout<<"\nDisplaying Details for Love Letter:\n";
            cout<<"Content: "<<content<<endl;
            cout<<"Style: "<<style<<endl;
        }
    }
};

void printGiftDetails(RomanticGift a, Flower f, ChocolateBox cb, LoveLetter ll){
    a.display();
    f.displayDetails();
   cb.displayDetails();
   ll.displayDetails(); 
}

int main(){
    cout<<"\n*******VALENTINE'S DAY GIFT*******"<<endl;

    RomanticGift a;
    Flower f;
    ChocolateBox cb;
    LoveLetter ll;
    a.input();
    int s=1;
    
    while(s){
        cout<<endl<<"*Enter Gift Item*\n";
        cout<<"1: Flower"<<endl;
        cout<<"2: Chocolate Box"<<endl;
        cout<<"3: Love Letter"<<endl;
        cout<<"4: Display Details"<<endl;
        cout<<"0: Exit"<<endl;
        cin>>s;
        cin.ignore();
        switch(s){
            case 0:
            cout<<"Exiting...\n";
            break;
            case 1:
            f.inputDetails();
            break;
            case 2:
            cb.inputDetails();
            break;
            case 3:
            ll.inputDetails();
            break;
            case 4:
            cout<<endl;
            printGiftDetails(a, f, cb, ll);
            break;
            default:
            cout<<"Invalid Choice! Try Again..."<<endl;
        }
    }

    return 0;
}