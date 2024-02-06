// Priority :
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define clr(c,val) memset(c,val,sizeof(c))


int main(){
    vector<pair<string, pair<int, int>>> pairvec;
    int numberofpairs = 4;
    string firstElement;
    int secondElement, thirdElement;
    for(int i=0; i<numberofpairs; i++){
        cin>> firstElement >> secondElement >> thirdElement ;
        pairvec.push_back({firstElement,{secondElement,thirdElement}});
       
    }
    // for(const auto&pair: pairvec){
    //     cout<<pair.first <<" "<<pair.second.first<<" "<<pair.second.second<<endl;
    // }
   
    sort(pairvec.begin(),pairvec.end(),[] (const auto& a,const auto& b){
        return a.second.second < b.second.second;
    });
    // for(const auto&pair: pairvec){
    //     cout<<pair.first <<" "<<pair.second.first<<" "<<pair.second.second<<endl;
    // }
   
    int prefixsum = 0,totalTime =0;
    string s= {"0 "};
    for(int i=0; i<numberofpairs; i++){
        prefixsum += pairvec[i].second.first;
        s+=" "+pairvec[i].first+ " " +to_string(prefixsum);
        if(i == numberofpairs-1){
            continue;
        }else{
            totalTime += prefixsum;
        }
    }
    
   
    double avg = double(totalTime)/numberofpairs;
    cout <<"The Average time will be : "<< avg << endl;

    return 0;
}