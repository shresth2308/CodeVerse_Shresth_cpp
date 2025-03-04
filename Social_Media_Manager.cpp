#include<iostream>
using namespace std;

class SocialMediaUser{
    protected:
    string uname,accstatus;
    int uid, followers;
    public:

    SocialMediaUser(){}

    SocialMediaUser(string a, int b, int c, string d){
        uname=a; uid=b; followers=c; accstatus=d;
    }

    virtual int isactive(){
        if(accstatus=="active" || accstatus=="Active"){
            return 1;
        }
        else{
            return 0;
        }
    }
    virtual void displayProfile()=0;
};

class ContentCreator:public SocialMediaUser{
    private:
    int vid,avgviews;
    public:
    ContentCreator(string uname, int uid, int followers, string accstatus, int vid1, int avgviews1):SocialMediaUser(uname,uid,followers,accstatus), vid(vid1), avgviews(avgviews1){}
    void displayProfile(){
        cout<<"\n*CONTENT CREATOR DETAIL*";
        cout<<"\nUser: "<<uname<<endl;
        cout<<"User ID: "<<uid<<endl;
        cout<<"Followers: "<<followers<<endl;
        cout<<"Account Status: "<<accstatus<<endl;
        cout<<"Total videos: "<<vid<<endl;
        cout<<"Views Per Video: "<<avgviews<<endl;
    }
};

class Moderator:public SocialMediaUser{
    private:
    int reports;
    string moderation;
    public:
    Moderator(string uname, int uid, int followers, string accstatus, int reports1, string moderation1):SocialMediaUser(uname,uid,followers,accstatus), reports(reports1), moderation(moderation1){}
    void displayProfile(){
        cout<<"\n*MODERATOR DETAIL*\n";
        cout<<"User: "<<uname<<endl;
        cout<<"User ID: "<<uid<<endl;
        cout<<"Followers: "<<followers<<endl;
        cout<<"Account Status: "<<accstatus<<endl;
        cout<<"Reports Handeled Per day: "<<reports<<endl;
        cout<<"Moderation: "<<moderation<<endl;
    }
};

int main(){
    
    ContentCreator aa("Shresth",240,1020,"Active",90,3400);
    if(aa.isactive()){
        aa.displayProfile();
    }
    else{
        cout<<"\nContent Creator Account is Disabled\n";
    }

    Moderator bb("Riya",693,0021,"Disable",4,"High");
    if(bb.isactive()){
        bb.displayProfile();
    }
    else{
        cout<<"\nModerator Account is Disabled\n";
    }

    return 0;
}