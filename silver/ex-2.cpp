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

//https://cses.fi/problemset/result/11618888/
//soln: kadane. can be solved with  prefix sums or kadane's greedy algo.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<long long>a(n);
	for(int i=0; i<n;i++) cin >> a[i];

	ll sum = a[0]; //accounts for -ve numbers
	ll best = a[0];
	for(int i=1 ; i <n; i++){
		//greedily constructs the subarray sum and compares
		sum = max(sum + a[i], a[i]);
		best = max(best, sum);
	}

	cout << best << "\n";
}



//https://usaco.org/index.php?page=viewproblem2&cpid=919
//p class: prefix sums
/*
	     grid[x][y]:        prefsum[x][y]:
		1  0  0  0 -1       1  1  1  1  0     
		0  0  0  0  0       1  1  1  1  0 
	    0  0  0  0  0       1  1  1  1  0 
	    0  0  0  0  0  ->   1  1  1  1  0 
	    0  0  0  0  0       1  1  1  1  0 
	    0  0  0  0  0       1  1  1  1  0 
	   -1  0  0  0  1       0  0  0  0  0
*/


#include <bits/stdc++.h>

using namespace std;

const int WIDTH = 1000;

int main() {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	int rect_num, paint_req;
	cin >> rect_num >> paint_req;

	int barn[WIDTH + 1][WIDTH + 1];
	for (int i = 0; i < rect_num; i++) {
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y >> end_x >> end_y;
		// Set up the prefix sums array with all the corners of the given
		// rectangle
		barn[start_x][start_y]++;
		barn[start_x][end_y]--;
		barn[end_x][start_y]--;
		barn[end_x][end_y]++;
	}

	int valid_area = 0;
	// Run 2D prefix sums on the array
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < WIDTH; y++) {
			if (x > 0) barn[x][y] += barn[x - 1][y];
			if (y > 0) barn[x][y] += barn[x][y - 1];
			if (x > 0 && y > 0) barn[x][y] -= barn[x - 1][y - 1];
			valid_area += barn[x][y] == paint_req;
		}
	}
	cout << valid_area << endl;
}


//passed 5/10 XD written half asleep how does this even work
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, l, r;
  cin >> n;
  vector<int>diff(n*2, 0);
  int updateValue = 1;


  for(int i=1; i<=n;i++){
    cin >> l >> r;
    diff[l] += updateValue;
    diff[r+1] -= updateValue;
  }

  for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

  
  cout << *max_element(diff.begin(), diff.end()) << "";

}


//twosum
//https://cses.fi/problemset/task/1640
#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n , x;
	cin >> n  >> x;
	vector<pair<int,int>>arr;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back({num, i + 1});
	}

	sort(arr.begin(), arr.end());
	int left = 0; int right = n-1;
	while(left < right){
		if(arr[left].first + arr[right].first > x){
			right--;
		}else if(arr[left].first + arr[right].first < x){
			left++;
		}else if(arr[left].first + arr[right].first == x){
			cout << arr[left].second << " " << arr[right].second;
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
}