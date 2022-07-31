#include<bits/stdc++.h>
using namespace std;

std::vector<int> lps(string s)
{
	int n = s.size(),idx=0,cnt=0;
	std::vector<int> v(n,0);

	for(int i=1; i<n; )
	{
		if(s[i] == s[idx]) v[i] = idx+1, idx++,i++;
		else
		{
			if(idx != 0) idx = v[idx-1];
			else v[i] = idx,i++;
		}
	}
	return v;
}
void kmp(string s, string ss)
{
	vector<int> lp = lps(ss);
	int i=0,j=0,f=0;
	while(i<s.size())
	{
		if(s[i] == ss[j]) ++i,++j;
	    else{
	    	if(j!=0) j = lp[j-1];
	    	else ++i;
	    }
	    if(j==s.size()){
		cout << "found" << endl;
		f = 1;
		break;
	   }
	}
	if(f==0) cout << "not found" << endl;
}

int main()
{
	string s,ss,s2;
	int n;
	cin >> n;
	vector<string>vs(n);
	for(int i=0; i<n; i++) cin >> vs[i];
	cin >> s;
	for(int i=0; i<n; i++) kmp(vs[i],s);
}