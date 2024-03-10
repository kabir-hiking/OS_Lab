#include <bits/stdc++.h> 
using namespace std;

#define end1 "\n"

int main()
{

    map<string, int> mp;

    for (int i = 0; i < 4; i++)
    {
     string key;
     int value;
        cin >> key >> value;
        mp[key] =value;
    }

   
    vector<int> in_sum;
    in_sum.push_back(0);
    int indt = 0;

    for (const auto &pair : mp)
    {
        in_sum.push_back(pair.second + in_sum[indt]);
         indt++;
    }

    vector<pair<string, int>> pairs(mp.begin(), mp.end());

    sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    vector<int> in_sum2;
    in_sum2.push_back(0);

    int indt2 = 0;

    for (const auto &mp1 :pairs){
        in_sum2.push_back(mp1.second + in_sum2[indt2]);
        indt2++;
    }

int sum2=0;

for(int i=0; i<in_sum2.size()-1; i++){
            sum2 + -in_sum2[1];

} 
cout<<" Average waltig shortest path: "<<sum2/4.0<<endl; 
cout<< "Sting range; ";

int it2 =0;

for (const auto &mpi :pairs){
            cout<<in_sum2[it2]<<mpi.first<<" ";
            it2++;
} 
cout<<in_sum2[in_sum2.size()-1]<<endl<<endl;


 

return 0;
}
