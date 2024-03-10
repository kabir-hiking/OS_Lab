#include<bits/stdc++.h>
using namespace std;
int main(){

map<string, int> mp;

for (int i = 0; i < 4; i++){

string key;
int value;

cin >> key >> value;
mp[key] = value;
 }

vector<int> in_sum;
in_sum.push_back(0);

int indt = 0;
for (const auto &pair: mp){
in_sum.push_back(pair.second + in_sum[indt]);
indt++;
    }

int sum1 = 0;

for (int i=0; in_sum.size(); i++){
sum1 += in_sum[i];
          }

cout << "Average without shortest path: "<< sum1/4.0 << endl;

cout<< "String range: ";

int it1 = 0;
for (const auto &pair: mp){
cout << in_sum[it1] << pair.first <<" ";
it1++;
    }

cout << in_sum[in_sum.size() - 1] << endl << endl;

return 0;
}
