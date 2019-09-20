#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> getPi(string p) {
	int m = (int)p.size(), j=0;
	vector<int> pi(m,0);

	for(int i=1; i<m; ++i) {
		while(j>0 && p[i] != p[j]) 
			j = pi[j-1];
		
		if(p[i] == p[j]) 
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size();
	int m = (int)p.size();
	int j=0;

	for(int i=0; i<n; ++i) {
		while(j>0 && s[i] != p[j])
			j = pi[j-1];
		if(s[i] == p[j]) {
			if(j==m-1) {
				ans.push_back(i-m+1);
				j = pi[j];
			}
			else {
				++j;
			}
		}
	}
	return ans;
}

int main() {
	string s,p;
	
    while(true) {
        getline(cin,s);
        if(s == ".") break;
        vector<int> fail = getPi(s);

        int sz = s.size();
        int ans = sz/(sz-fail[sz-1]);
        cout << ans << '\n';
    }
}
