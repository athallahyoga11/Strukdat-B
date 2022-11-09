#include <iostream>
using namespace std;

class MHS {
	
	
	public:

	void printname() {
		cout << "MHS name is : "<< MHSname; 
	}
	
	string getNama() {
	 return MHSname;
	}
	
	MHS (string nama){
		MHSname = nama;
	}
	
	private:
	string MHSname; 
};

int main() {\
	
	MHS mhs1("ali");

	
	
	mhs1.printname();
	
	cout<<mhs1.getNama();
	
	return 0;
}