#include <bits/stdc++.h>

using namespace std;
vector<int> ans;
vector<vector<int>> allAns;

void subsetSum(vector<int>& v, int pos, int sum, int total, int totalSum){
  if(sum == total){
    allAns.push_back(ans);
    return;
  }

  if(pos >= v.size()){
    return;
  }

  if(sum + totalSum < total){
    return;
  }
  
  int next = pos + 1;
  while(next < v.size() and v[pos] == v[next]){
    ++next;
  }
  totalSum -= v[pos] * (next - pos); 

  int aux = 0;
  for(int i = pos; i < next; ++i){
    if(sum + (v[i] * (aux + 1)) <= total){
      ++aux;
      ans.push_back(v[i]);
      // With the current element
      subsetSum(v, next, sum + (v[i] * aux), total, totalSum);
    } else {
      break;
    }
  }

  for(int i = 0; i < aux; ++i){
    ans.pop_back();
  }

  // Without the current element
  subsetSum(v, next, sum, total, totalSum);
}

int main() {
  int total, n;
  cin >> total >> n;

  while (n) {
    vector<int> subset(n);
    vector<int> ans;
    int totalSum = 0;
    
    for (int i = 0; i < n; ++i) {
      cin >> subset[i];
      totalSum += subset[i];
    }

    cout << "Sums of " << total << ":\n";
    subsetSum(subset, 0, 0, total, totalSum);

    if(allAns.empty()){
      cout << "NONE\n";
    } else {
      sort(allAns.begin(), allAns.end(), greater<vector<int>>());
      for(int i = 0; i < allAns.size(); ++i){
        for(int j = 0; j < allAns[i].size(); ++j){
          cout << allAns[i][j] << (j < allAns[i].size() - 1 ? "+" : "\n");
        }
      }
      allAns.clear();
    }
    cin >> total >> n;
  }
  return 0;
}