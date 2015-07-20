#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	// your code goes here
	int n,tmp,size_even,size_odd;
	cin>>n;
	int a[n];
	vector<int> even,odd;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]%2 == 0){
			even.push_back(a[i]);
		}
		else{
			odd.push_back(a[i]);
		}
	}
	
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	vector<int> final;
	int sum_even = accumulate(even.begin(), even.end(), 0);
	int sum_odd = accumulate(odd.begin(), odd.end(), 0);
	
	for(int i = 0;i<even.size();i++){
		if(i==even.size()-1){
			final.push_back(even[i]);
			final.push_back(sum_even);
			break;
		}
		
		final.push_back(even[i]);
	}
	
	for(int i = 0;i<odd.size();i++){
		if(i==odd.size()-1){
			final.push_back(odd[i]);
			final.push_back(sum_odd);
			break;
		}
		final.push_back(odd[i]);
	}
	for(int i=0;i<final.size();i++){
		cout<<final[i]<<" ";
	}

	return 0;
	
}