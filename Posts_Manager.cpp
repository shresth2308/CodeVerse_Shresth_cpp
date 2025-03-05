#include<iostream>
using namespace std;


class SocialMediaPost{
    protected:
    string aname;
    int pid, likes;
    public:
    virtual void displayPost()=0;
    virtual void input(){
        cout<<"\n*Enter Author Details*\n";
        cout<<"Authour Name: ";
        cin>>aname;
        cout<<"Post ID: ";
        cin>>pid;
        cout<<"Likes: ";
        cin>>likes;
    }
};


class ImagePost:public SocialMediaPost{
    private:
    int img_res,f_size;
    public:

    void input(){
        SocialMediaPost::input();
        cout<<"\n*Enter Image Details:*\n";
        cout<<"Image Resolution: ";
        cin>>img_res;
        cout<<"File Size (kb): ";
        cin>>f_size;
    }

    void displayPost(){
        cout<<"\n\n*IMAGE POST DETAIL*";
        cout<<"\nAuthour Name: "<<aname<<endl;
        cout<<"Post ID: "<<pid<<endl;
        cout<<"Likes: "<<likes<<endl;
        cout<<"Image Resolution: "<<img_res<<endl;
        cout<<"File Size (kb): "<<f_size<<endl<<endl;
    }
};


class VideoPost:public SocialMediaPost{
    private:
    int duration,fps;
    public:

    void input(){
        SocialMediaPost::input();
        cout<<"\n*Enter Video Details:*\n";
        cout<<"Duration(sec): ";
        cin>>duration;
        cout<<"Framerate: ";
        cin>>fps;
    }

    void displayPost(){
        cout<<"\n\n*VIDEO POST DETAIL*";
        cout<<"\nAuthour Name: "<<aname<<endl;
        cout<<"Post ID: "<<pid<<endl;
        cout<<"Likes: "<<likes<<endl;
        cout<<"Video Duration(sec): "<<duration<<endl;
        cout<<"Framerate: "<<fps<<endl<<endl;
    }
};


int main(){
    cout<<"\n***IMAGE POST***\n";
    SocialMediaPost *iptr = new ImagePost;
    iptr->input();              //Directly calling with a pointer 
    iptr->displayPost();             //showing polymorphism

    cout<<"***VIDEO POST***\n";
    SocialMediaPost *vptr;
    VideoPost vv;
    iptr=&vv;                   //Making an onject and then calling
    vv.input();
    vv.displayPost();

    return 0;
}