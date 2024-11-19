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