#include <iostream>
using namespace std;

class Sample
{
private:
	static int count;
public:
	Sample()
	{
		count++;
	
	}

	static int get_count(){
		return count;
	}
};
int Sample::count=0;
int main(){
	Sample c1, c2, c3;
	cout<<c1.get_count();
	Sample c4,c5;
	cout<<c4.get_count();
	return 0;
}
