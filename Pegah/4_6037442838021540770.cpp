#include<bits/stdc++.h>
#include<algorithm>
#include<set>
using namespace std;

int main(){
	int n , q , a , b , c;
	cin>>n>>q;
	int data[n+1][4];
	for(int i=1 ; i<= n ; i++){
		data[i][0] = i;
		data[i][1] = i;
		data[i][2] = i;
		data[i][3] = 1;
	}
	while(q--){
		cin>>a;
		if(a == 1){
            set<int> st;
			cin>>b>>c;
			while(data[b][0] != b){
			    st.insert(b);
				b = data[b][0];
			}
			while(data[c][0] != c){
			    st.insert(c);
				c = data[c][0];
			}
            st.insert(c);
			if(b!= c){
                data[c][0] = b;
                data[b][1] = min(data[b][1] , data[c][1]);
                data[b][2] = max(data[b][2] , data[c][2]);
                data[b][3] = data[b][3] + data[c][3];
                for(auto x : st){
                    data[x][0] = b;
                }
			}
		}
		else{
			cin>>b;
			while(data[b][0] != b){
				b = data[b][0];
			}
			cout<<data[b][3]<<" "<<data[b][1]<<" "<<data[b][2]<<endl;
		}
	}
}
