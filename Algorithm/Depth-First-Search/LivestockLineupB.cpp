#include<iostream>
#include<vector>
#include<string>

using namespace std;


void permuteRecursive(int cur,vector<bool> & used, vector<int>& res,vector<vector<int> > re,vector<vector<int> >& ans) {
	if (cur == 9) {
		ans.push_back(res);
		return;
	}
	for (int i = cur; i <= 8; i++) {
		if (cur == 1) {
			for (int j = 1; j <= 8; j++) {
				if (re[j].size() < 2 && !used[j]) {
					res.push_back(j);
					used[j] = true;
					permuteRecursive(cur+1, used, res, re,ans);
					res.pop_back();
					used[j] = false;
				}
			}
		}
		else {
			if (re[res[cur - 2]].size() == 0) {
				for (int j = 1; j <= 8; j++) {
					if (!used[j]) {
						res.push_back(j);
						used[j] = 1;
						permuteRecursive(cur+1, used, res, re,ans);
						res.pop_back();
						used[j] = false;
					}
				}
			}
			else {
				for (int j = 1; j <= 8; j++) {
					if (re[res[cur - 2]].size() == 1) {
						if (!used[j] && j == re[res[cur - 2]][0]) {
							res.push_back(j);
							used[j] = true;
							permuteRecursive(cur+1, used, res, re,ans);
							res.pop_back();
							used[j] = false;
						}
					}
					else {
						if (!used[j] && (j == re[res[cur - 2]][0] || j == re[res[cur - 2]][1])) {
							res.push_back(j);
							used[j] = 1;
							permuteRecursive(cur+1, used, res, re,ans);
							res.pop_back();
							used[j] = false;
						}
					}
				}
			}
		}
	}
}

vector<int> permute(vector<bool>& used,vector<vector<int> > re) {
	vector<int> res;
	vector<vector<int> > ans;
	permuteRecursive(1, used, res, re, ans);
	return ans[0];
}
int main() {
	vector<string> name(9);
	name[1] = "Beatrice";
	name[2] = "Bella";
	name[3] = "Bessie";
	name[4] = "Betsy";
	name[5] = "Buttercup";
	name[6] = "Belinda";
	name[7] = "Blue";
	name[8] = "Sue";
	int n;
	cin >> n;
	int t = n;
	vector<vector<int> > re(9);
	vector<bool> used(9,0);
	while (t--) {
		string name1, s2, s3, s4, s5, name2;
		cin >> name1 >> s2 >> s3 >> s4 >> s5 >> name2;
		int index1 = 0, index2 = 0;
		for (int i = 1; i <= 8; i++) {
			if (name1 == name[i])index1 = i;
			if (name2 == name[i])index2 = i;
		}
		re[index1].push_back(index2);
		re[index2].push_back(index1);
	}
	vector<vector<int> > ans;
	ans.push_back(permute( used,re));
	for (int i = 0; i < 8; i++) {
		cout << name[ans[0][i]];
	}
	return 0;
}