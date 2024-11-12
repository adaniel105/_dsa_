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

