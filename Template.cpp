/**                 <------------------------------------------------>
                    |          ___                                   |
                    |         ^   ^                                  |
                    |        / _/\ \   *___*     Allah is Almighty   |
                    |        \/*.*\/   / *       Md. Sakib Uddin.    |
                    |        (  _  )  / /        RMSTU               |
                    |        _>---<__/ /         hi.sakib75@gmail.com|
                    |      /  sakib   /                              |
                    |     / \/      /                                |
                    |     \ :      :                                 |
                    |      \:______:                                 |
                    |       :  L   :                                 |
                    |       :__ :__:                                 |
                    |        : :: :                                  |
                    |        :_::_:                                  |
                    |       _:_::_:_                                 |
                    |      <___::___>                                |
                    <------------------------------------------------>**/
#include <bits/stdc++.h>
using namespace std;
#define     boost           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     ll              long long
#define     ull             unsigned long long
#define     ld              long double


#define     num_of_ones(n)  __builtin_popcount(n)
#define     parity(n)         __builtin_parity(n) // odd num of 1's or even num of 1's
#define     leading_zero(n)  __builtin_clz(n)
#define     traling_zero(n)  __builtin_ctz(n)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(d,min3(a,b,c))
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(d,max3(a,b,c))
#define     gcd(a,b)        __gcd(a,b)
#define     lcm(a,b)        (a/__gcd(a,b))*b
#define     vi              vector<int>
#define     vll             vector<ll>
#define     vc              vector<char>
#define     vs              vector<string>
#define     all(x)          x.begin(),x.end()
#define     reall(x)        x.rbegin(),x.rend()
#define     eb              emplace_back
#define     pb              push_back
#define     popb            pop_backh
#define     pf              push_front
#define     popf            pop_front
#define     mk              make_pair
#define     F               first
#define     S               second
#define     fori(i,b,e)     for(int (i)=(b); (i) <= (e); (i)++)
#define     for0(i,n)       for(int (i)=0; (i) < (n); (i)++)
#define     forrv(i,b,e)    for(int i=b;i>=e;i--)
#define     sp(a)           fixed<<setprecision(a)
#define     endl            '\n'
#define     yes             cout << "YES" << '\n'
#define     no              cout << "NO" << '\n'
#define     coutl(x)        cout << x << '\n'
#define     cout(x)         cout << x
#define     nl              cout << '\n'
#define     printv(v)       for(auto it:v) cout << it << " "
#define     CASE(t)         printf("Case %lld: ",++t)
#define     pi              3.141592653589793238 //2*acos(0)
#define     inf             0x3f3f3f3f
#define     E               2.71828182845904523536
#define     gamma           0.5772156649
#define     Consummation    int main(){int tt; cin >> tt;while(tt--){SakiBee();}return 0;}
#define     S_Consummation    int main(){SakiBee();return 0;}
#define     Tc_Consummation int main(){int tt,t=0;cin >> tt;while(tt--){cout << "Case " << ++t << ": "; SakiBee();}return 0;}



/**_____________________________________DEBUG____________________________________________________**/

template<typename T>void showSTL(T H);template<typename T,typename V>void showSTL(pair<T,V> H);
template<typename T>void showSTL(priority_queue<T> H);template<typename T>void showSTL(stack<T> H);
template<typename T,typename V>void showSTL(map<T,V> H);
template<typename T,typename V>void showSTL(multimap<T,V> H);template<typename T>void showSTL(vector<T> H);
template<typename T>void showSTL(set<T> H);template<typename T>void showSTL(multiset<T> H);
template<typename T>void showSTL(list<T> H);void showSTL(char *H);
template<typename T>void showSTL(deque<T> H);template<typename T>void showSTL(queue<T> H);
template<typename T>void showSTL(T H){stringstream ss;ss<<H;cerr<<ss.str();}
template<typename T,typename V>void showSTL(pair<T,V> H){cerr<<"(";showSTL(H.first);cerr<<"=>";showSTL(H.second);cerr<<")";}
template<typename T>void showSTL(priority_queue<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}cerr<<endl;}
template<typename T>void showSTL(stack<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}}
template<typename T,typename V>void showSTL(map<T,V> H){cerr<<"[ ";for(auto val:H){showSTL(val);cerr<<" ";}cerr<<"]";}
template<typename T,typename V>void showSTL(multimap<T,V> H){cerr<<"[ ";for(auto val:H){showSTL(val);cerr<<" ";}cerr<<"]";}
template<typename T>void showSTL(vector<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(set<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(multiset<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(list<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
void showSTL(char *H){for(int i=0;i<strlen(H);i++){showSTL(H[i]);};}
template<typename T>void showSTL(deque<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(queue<T> H){cerr<<"[ ";while(!H.empty()){showSTL(H.front());cerr<<' ';H.pop();}cerr<<"]";}
vector<string>vec_spltr(string s){s+=',';vector<string>res;while(!s.empty())
res.push_back(s.substr(0, s.find(','))),s=s.substr(s.find(',')+1);return res;}
void dbg_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,__attribute__((unused))int LINE_NUM)
{cerr<<endl;}template<typename Head,typename... Tail>
void dbg_out ( vector <string> args, int idx, int LINE_NUM, Head H, Tail... T)
{if(idx>0)cerr<<", ";else cerr << "Line(" << LINE_NUM << "):";
cerr<<" "<<args[idx]<<" = ";showSTL(H);dbg_out(args,idx+1,LINE_NUM, T...);}
#define debug(...) dbg_out(vec_spltr(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)


bool Check_ll_prime(ll n)
{
   int odd = 0, even = 0, both = 0;
   if(n&1){
      while(n){
         int tm = n%10; n/=10;
         tm&1 ? odd += tm : even += tm; both += tm;
      }
      if(both < 10 and both%3 == 0) return false;
      else if(abs(odd-even)%11 == 0) return false;
      else return true;
   }
   else return false;
}



// const int N = 1e4+7;
// vector<int>primes;
// bool pri[N];

// void sieve()
// {
//     memset(pri, 1, sizeof(pri));
//     for(int i=4; i<N; i+=2) pri[i] = 0;
//     primes.pb(2);
//     for(int i=3; i*i < N; i+=2)
//     {
//         if(pri[i])
//         {
//             primes.pb(i);
//             for(int j=i*i; j<N; j+=i) pri[j] = 0;
//         }
//     }
// }


void SakiBee()
{ 
   ll p; cin >> p;
   cout << Check_ll_prime(p) << endl;
}
//1000004249
Consummation
//S_Consummation
//Tc_Consummation
//Wrong doesn't mean bad


