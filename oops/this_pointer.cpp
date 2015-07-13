#include <iostream>
using namespace std;

class What{
	private:
		int alpha;
		
	public:
		void tester(){
			this->alpha=11;
			cout<<alpha<<endl;
		}
		void reveal(){
			cout<<"current object address is: "<<this<<endl;
		}
		~What(){
		}
};

int main(){
	What w1,w2,w3;
	w1.tester();
	w1.reveal();
	w2.reveal();
	w3.	reveal();
	return 0;
}
