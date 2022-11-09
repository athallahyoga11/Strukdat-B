#include <iostream>
using namespace std;

class MHS
{
    //Access specifier
    public:

    //Data Member
    string MHSname;

    //Member Functions
    void printname()
    {
        cout<<"MHS name is"<<MHSname;
    }
};

int main(){
    //Declare an object of class geeks
    MHS mhs1;

    //accessing data member
    mhs1.MHSname="Rahmat Budi";

    //accessing member function
    mhs1.printname();
    return 0;
}