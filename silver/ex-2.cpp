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
