
//https://usaco.org/index.php?page=viewproblem2&cpid=689
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("cowtip.in", "r", stdin);
    //freopen("cowtip.out", "w", stdout);
    int N;
    //use dyanamic array, weird habit.
    char arr[50][50]; //no whitespace b/w problem input, so we read as char. 
    int ans = 0;
    cin >> N;
    for(int i=0; i< N; i++){
        for(int j= 0; j< N; j++){
            cin >> arr[i][j];
        }
    }

    //find the ones tipped over, starting from the bottom right. 
    for(int i= N-1; i >= 0; i--){
        for(int j= N-1; j >= 0; j--){
            if(arr[i][j] == '1'){ 
                ans++;
                //unnecessary
                int y_dist = i;
                int x_dist = j;
                for(int a = 0; a <= y_dist; a++){
                    for(int b = 0; b <= x_dist; b++){
                        if(arr[a][b] == '1'){
                            arr[a][b] = '0';
                        }else arr[a][b] = '1';
                    }
                }
            }
        }
    }
    cout << ans << endl;
}



// 5/12. rewrite with a vector
//https://usaco.org/index.php?page=viewproblem2&cpid=1301
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N, K;
    ll arr[100];
    cin >> N >> K;
    for (ll i=0; i< N; ++i){
        cin >> arr[i];
    }
    ll cost = 1 + K;
    ll last_sub = arr[0]; //holds previous sub date
    for(ll i=0; i< N; ++i){
        //only a good idea to extend when it is less than renewing (1+K)
        if((arr[i] - last_sub) < (1 + K)){
            //extending the sub is a matter adding the difference in days
            //to d + k;
            cost += arr[i] - last_sub;  
        }else{
            cost += 1 + K; 
        }

        last_sub = arr[i];
    }
    
    cout << cost << endl;
}



//
#include <algorithm>
#include <cstdio>
#include <vector>

using std::vector;

int main() {
    //highest possible score means every guess was correct.
	freopen("shell.in", "r", stdin);

	int n;
	scanf("%d", &n);

	// shell_at_pos[i] stores the label of the shell located at position i
	vector<int> shell_at_pos(3);
	// Place the shells down arbitrarily
	for (int i = 0; i < 3; i++) { shell_at_pos[i] = i; }

	// counter[i] stores the number of times the shell with label i was picked
	vector<int> counter(3);
	for (int i = 0; i < n; i++) {
		int a, b, g;
		scanf("%d %d %d", &a, &b, &g);
		// Zero indexing: offset all positions by 1
		a--, b--, g--;

		// Perform Bessie's swapping operation
		std::swap(shell_at_pos[a], shell_at_pos[b]);
		// Count the number of times Elsie guesses each particular shell
		counter[shell_at_pos[g]]++;
	}

	freopen("shell.out", "w", stdout);
	printf("%d\n", std::max({counter[0], counter[1], counter[2]}));
}

// 5/10 passed
#include <bits/stdc++.h>
using namespace std;

//see in segment, run check and update counter.
int main() {
    freopen("speeding.in", "r", stdin);
    int N, M;
    cin >> N >> M;
    int counter[3]; 

    int seg[N];
    int seg_len[N];
    for(int i = 0; i < N; i++){
        int d , s;
        cin >> d >> s;
        seg_len[i] = d;
        seg[i] = s;
    }
    int bessie_seg[M];
    int bessie_seg_len[M];
    for (int i = 0; i < M ; i++){
        int d, s;
        cin >> d >> s;
        bessie_seg_len[i] = d;
        bessie_seg[i] = s;
    }

    for(int i = 0; i < N; i++){
        if (bessie_seg_len[i] > seg_len[i]){
            counter[i] = std::min(bessie_seg[i], (bessie_seg[i] - seg[i-1]));
        } else counter[i] = 0;
        //cout << counter[i] << endl;
    }
    int *pointer = std::max_element(counter, counter + N);
    freopen("speeding.out", "w", stdout);
    cout << *pointer;
}

//10/10
#include <iostream>
#include <fstream>
using namespace std;
 
int N, K;
int data[10][20];
 
bool better(int a, int b, int session)
{
  int apos, bpos;
  for (int i=0; i<N; i++) {
  //implementation of "indexOf" fn, assuming cows are numbered non-arbitrarily.
    if (data[session][i] == a) apos = i;
    if (data[session][i] == b) bpos = i;
  }
  return apos < bpos;
}
 
int Nbetter(int a, int b)
{
  int total = 0;
  for (int session=0; session<K; session++)
    if (better(a,b,session)) total++;
  return total;
}
 
int main(void)
{
  freopen("gymnastics.in", "r",stdin);
  
  cin >> K >> N;
  for (int k=0; k<K; k++)
    for (int n=0; n<N; n++) 
      cin >> data[k][n];
  int answer = 0;
  for (int a=1; a<=N; a++)
    for (int b=1; b<=N; b++)
      if (Nbetter(a,b) == K) answer++;
  freopen("gymnastics.cpp", "w", stdout);
  cout << answer << "\n";
}

//usaco bronze: diamond-collector
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> diamonds(n);
	for (int &d : diamonds) { cin >> d; }

	int most = 0;
	/*
	 * Iterate through all diamonds and test setting them
	 * as the smallest diamond in the case.
	 */
	for (int x : diamonds) {
		int fittable = 0;
		/*
		 * Get all diamonds at least as large as x (including x itself)
		 * that differ from it by no more than k.
		 */
		for (int y : diamonds) {
			if (x <= y && y <= x + k) { fittable++; }
		}
		most = max(most, fittable);
	}

	freopen("diamond.out", "w", stdout);
	cout << most << endl;
}

//genomics__normal bf 
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int N, M;
string spotty[100], plain[100];

bool test_location(int j)
{
  // found_cow[0] refers to spotty cows, and found_cow[1]
  // refers to non-spotty cows.
  bool found_cow[2][4] = {0};
  // for cow[0][0], test for base A,G,C,T in spotty cow, and in plain cow
  //if both cows show same base, return false, if not, position is usable.increment.
    for (int i=0; i<N; i++) {
    if (spotty[i][j] == 'A') found_cow[0][0] = true;
    if (spotty[i][j] == 'C') found_cow[0][1] = true;
    if (spotty[i][j] == 'G') found_cow[0][2] = true;
    if (spotty[i][j] == 'T') found_cow[0][3] = true;
  }
  for (int i=0; i<N; i++) {
    if (plain[i][j] == 'A') found_cow[1][0] = true;
    if (plain[i][j] == 'C') found_cow[1][1] = true;
    if (plain[i][j] == 'G') found_cow[1][2] = true;
    if (plain[i][j] == 'T') found_cow[1][3] = true;
  }
  for (int i = 0; i < 4; ++i) {
    if (found_cow[0][i] && found_cow[1][i]) return false;
  }
  return true;
}

int main(void)
{
  ifstream fin ("cownomics.in");
  ofstream fout ("cownomics.out");
  fin >> N >> M;
  for (int i=0; i<N; i++) fin >> spotty[i];
  for (int i=0; i<N; i++) fin >> plain[i];
  int answer = 0;
  for (int j=0; j<M; j++) 
    if (test_location(j)) answer++;
  fout << answer << "\n";
  return 0;
}

//distinct values of arr n;

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int arr[20];
    for (int i=0;i< N; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int counter = 0;
    for (int i=0; i< N; ++i){
        while( i < N-1 && arr[i] == arr[i+1])i++;
        counter++;
    }
    cout << counter;
    return 0;
}

//kayaking soln
#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;

    int w[50];
    for (int i=0; i< 2 * N; i++){
        cin >> w[i];
    }

    sort(w, w + (2*N));

    int answer = 1e5;

    for(int i=0; i< 2 * N; ++i){
        for(int j=i+1; j< 2 * N; ++j){

        //place the first two on single kayaks.
        // read the rest into s
            vector<int> s;
            for (int k =0; k < 2 * N; ++k){
                if(k != i && k != j)s.push_back(w[k]);            
            }
            int temp = 0;

            //calculate minimum instability for the rest.
            // gotten by subtracting through sorted pairs.
            for(int k=0; k < 2 * N-2; k+=2){
                temp += s[k + 1] - s[k];   
            } 

            answer = min(temp, answer);
        }
    }
    cout << answer << endl;
}


//7https://usaco.org/index.php?page=viewproblem2&cpid=964
#include <bits/stdc++.h>
using namespace std;

int N;
string S;

//check through every subseq of mailbox seq
//iterate through until a subseq K is found unique.
bool unique(int len){
    set <string> X;
    for(int i=0; i<= N-len; ++i){
        if(X.count(S.substr(i, len)) > 0) return true;
        X.insert(S.substr(i, len));
    }
    return false;
}

int main(){
    int ans = 1;
    cin >> N >> S;
    //freopen("whereami.in", "r", stdin);
    //freopen("whereami.out", "w", stdout);
    while(unique(ans))ans++;
    cout << ans << endl;
}

//mad scientist: https://usaco.org/index.php?page=viewproblem2&cpid=1012
#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int N;
    string A, B;
    cin >> N >> A >> B;
    int ans = 0;
    bool flip = false;
    
    for(int i = 0; i< N; ++i){
        // ans is only incremented at the start of a mismatched
        //portion of the string, when our variable flip is false (!flip evaluates);
        if(A[i] != B[i]){
            if(!flip) { 
                flip = true;
                ans++;
            } 
        }else{ flip = false; }
    }

    cout << ans << endl;
}


//https://usaco.org/index.php?page=viewproblem2&cpid=965
//bruteforce soln.
#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	cin >> N;

    //extract cow names
	vector<pair<string, string>> restrictions;
	for (int i = 0; i < N; i++) {
		string a, t, b;
		cin >> a;
		cin >> t >> t >> t >> t;
		cin >> b;
		restrictions.push_back({a, b});
	}

	vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
	                       "Bella",  "Blue",      "Betsy",   "Sue"};
	sort(cows.begin(), cows.end());
	int count = 0;


    //go through all permutations of cows until the distance
    //between our specified cows is appropriate
	while (next_permutation(cows.begin(), cows.end())) {
		bool passed = true;
		for (auto p : restrictions) {
			string cow1 = p.first;
			string cow2 = p.second;
			auto a = find(cows.begin(), cows.end(), cow1);
			auto b = find(cows.begin(), cows.end(), cow2);
			if (abs(a - b) != 1) { passed = false; }
		}
		if (passed) { break; }
	}

	for (auto cow : cows) { cout << cow << endl; }
}


//https://usaco.org/index.php?page=viewproblem2&cpid=894
//NOTE: review dfs soln.
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("planting");
    int N;
    cin >> N;
    vector<int> degree(N + 1); //account for 1-indexing
    
    for (int i= 0; i < N - 1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        degree[node1]++;
        degree[node2]++;
    }

    int ans = 0;
    //for a given position i, you have to plant diff grass types for i and (i + 1) * 	N before repeating. 
    for(int j = 1 ; j <= N; j++){
      ans = max(ans, degree[j]);  
    }
    //grass type for i itself 
    cout << ans + 1 << endl;
}

//formatting
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
    //setIO("bcount");
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
        ans.push_back(ones[q2] - ones[q1 - 1]);
        ans.push_back(twos[q2] - twos[q1 - 1]);
        ans.push_back(threes[q2] - threes[q1 - 1]);
    }
    for(int i=0; i < ans.size(); i++){
      cout << ans[i] << " ";      
    }
}

