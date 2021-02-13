#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(const string&);
vector<int> kmp(const string&, const string&);

int main() {
	string T, P;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // include <string> header
	getline(cin, T);
	getline(cin, P);

    auto ans = kmp(T, P);

    cout << ans.size() << "\n";
    for (int idx : ans) {
        cout << idx << "\n";
    }

	return 0;
}

vector<int> getPi(const string &p) { 
    int m = p.size();
	vector<int> pi(m); 
	for (int i = 1, j = 0; i < m; i++) { 
        // prefix == suffix였던 prefix + 1(=prefix 길이) 인덱스로 이동, prefix == suffix인 부분 탐색 x
		while (j > 0 && p[i] != p[j]) 
			j = pi[j - 1];  

        // prefix == suffix이면, 현재 인덱스의 pi배열에 prefix 길이 저장
		if (p[i] == p[j]) pi[i] = ++j;  
	} 
	return pi; 
}

vector<int> kmp(const string &s, const string &p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = s.size(), m = p.size();
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];

        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 2);
                j = pi[j];
            }
            else j++;        
        }
    }
    return ans;
}