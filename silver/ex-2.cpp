//6/10. unoptimized soln.
//https://cses.fi/problemset/task/1662
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	int counter = 0;
	cin >> n;
	vector<int> val(n + 1);
	for (int i=1;i<=n;i++){
		cin >> val[i];
	}

	for(int i= 1; i<= n; i++){
		vector<int>hold(val.begin() + i, val.end());
		vector<int> acc(hold.size());
		partial_sum(hold.begin(), hold.end(), acc.begin());
		for (int x : acc){
			if(x%n == 0){
				counter++;
			}
		}
	}
	cout << counter;
}


//https://usaco.org/index.php?page=viewproblem2&cpid=572
#include <bits/stdc++.h>
using namespace std;
void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("bcount");
    int n, q;
    cin >> n >> q;

    vector<int>ones(n + 1);
    vector<int>twos(n + 1);
    vector<int> threes(n + 1);
    int a = 0; int b= 0; int c= 0;
    
    for(int i=1; i <= n; i++){
        int cow;
        cin >> cow;
        if(cow == 1){
            a++;
            ones[i] = a;
            twos[i] = b;
            threes[i] = c;
        }else if(cow == 2){
            b++;
            ones[i] = a;
            twos[i] = b;
            threes[i] = c;
        }else{
            c++;
            ones[i] = a;
            twos[i] = b;
            threes[i] = c;
            }
        }

    vector<int>ans;
    for(int i=0; i < q; i++){
        int q1, q2;
        cin >> q1 >> q2;
        cout << ones[q2] - ones[q1 - 1] << " ";
        cout << twos[q2] - twos[q1 - 1] << " ";
        cout << threes[q2] - threes[q1 - 1] << "\n";
    }
}



//https://codeforces.com/contest/1826/problem/D
#include <bits/stdc++.h>
using namespace std;

/*
void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
*/


/*Intuition for this ans: 
	given that we are asked to find the 3 max elements that maximize
	b1 + b2 + b3 - (r-l) in a sequence of numbers, it then follows that the 
	two max soln's will be at either side of this trio, thus reducing the problem
	to finding three indices l<m<r such that bl+bm+br−(r−l) is maximum. 

	bl + bm + br - (r-m + m-1) //midpoint "takes away" from the range sum(?)
	= (b1 - (m-l)) + bm + (br - r-m) where m is i from  1 to n.
*/
int main(){
	int test_case;
	cin >> test_case;
	for (int t=0; t < test_case; t++){ 
		int n;
		cin >> n;
		vector<int>L(n), b(n), R(n);
		for (auto &x: b) cin >> x;

		//computing L[i] and R[i] greedily.
		for(int i=1; i<n;i++){
			L[i] = max(L[i-1] -1, b[i-1] - 1);
		}

		for(int i= n-2; i>=0;i--){
			R[i] = max(R[i+1] -1, b[i+1] - 1);
		}

		int ans=0;
		for(int i=0; i<n-1; i++){
			ans = max(ans, L[i] + b[i] + R[i]);
		}

		cout << ans << "\n";

	}

}
