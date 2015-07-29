#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

typedef vector<int> ivec;

void print_fail_func(const ivec& idx)
{
	for (ivec::size_type i = 0; i < idx.size(); ++i){
		printf("idx: %-2d len: %-2d\n", i, idx[i]);
	}
}

vector<int> compute_prefix_function(const string& s)
{
	int len = s.length();
	vector<int> p(len);
	p[0] = 0; 

	int k = 0;
	for(int i = 1; i < len; i++) {          
		while ( (k > 0) && (s[k] != s[i]) ) 
			k = p[k-1]; 
		if (s[k] == s[i])
			k++;
		p[i] = k;
	}
	return p;
}

void do_kmp_search(const string& txt, const string& pat, const ivec& idx)
{
	int i = 0, j = 0, m = 0;
	int ls = txt.length();
	int lp = pat.length();
	int cmpcount = 0;

	while(i < ls){
		if (txt[i] == pat[m]) {
			++i;
			++m;

			++cmpcount;

			// check if we have a match here
			if (m == lp) {
				printf("MATCH at: %d\n", i - lp);
				m = 0;
				continue;
			}
		}
		else { // the current chars do not match
			int shft = 0;
			if (m > 0)
				shft = idx[m - 1];

			if (shft > 0) { // we have previous shorter matching prefix of the pattern
				m = shft + 0;
			}
			else { // no previous prefix of pattern matching the string
				++i;
				m = 0; // reset the pattern index to its beginning
			}
		}
	}

	printf("Count of comparisons: %d\n", cmpcount);
}

int main(int argc, char* argv[])
{
	string txt = "abc abcdab abcdabcdabde abcdabdu";
	string pat = "abcdabd";

	//string txt = "AABAACAADAABAAABAA";
	//string pat = "AABA";
	
	ivec idx;

	printf("TEXT   : %-40s LEN: %d\n", txt.data(), txt.length());
	printf("PATTERN: %-40s LEN: %d\n\n", pat.data(), pat.length());
	
	idx = compute_prefix_function(pat);
	print_fail_func(idx);
	printf("\n");
	do_kmp_search(txt, pat, idx);
	return 0;
}