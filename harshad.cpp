#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>

using namespace std;

void cluster_down(int, vector<int>&);
void cluster_up(int, vector<int>&);
vector<int> harshad(int);
bool is_harshad(int);

void cluster_down(int n, vector<int>& cluster){
	if(!n) return;
	
	if(is_harshad(n)){
		cluster.push_back(n);
		cluster_down(n-1, cluster);
	}
}

void cluster_up(int n, vector<int>& cluster){
	if(!n) return;
	
	if(is_harshad(n)){
		cluster.push_back(n);
		cluster_up(n+1, cluster);
	}
}

vector<int> harshad(int n){
	vector<int> ret(2);
	vector<int> cluster;
	ret[0] = 0;
	
	if(is_harshad(n)){
		cluster_down(n, cluster);
		cluster_up(n, cluster);
		
		cluster.erase(cluster.begin());
		sort(cluster.begin(), cluster.end());
		for(int i = 0; i < cluster.size(); i++){
			cout << cluster[i] << ' ';
		}
		cout << '\n';
		ret[0] = cluster.size();
	}
	
	return ret;
}

bool is_harshad(int n){
	if(!n) return false;
	
	vector<int> digits;
	int in = n;

	for(int mag = log10(n)+1; mag != 0; mag--){
		int q = n/(int)pow(10, (double)mag-1);
		digits.push_back(q);
		n-=(q*(int)pow(10, (double)mag-1));
	}

	int sum = accumulate(digits.begin(), digits.end(), 0);

	return(!(in%sum));
}

int main(int argc, char** argv){
	harshad(atoi(argv[1]));
	//vector<int> dist(10, 0);	

	/*
	vector<int> temp;
	for(int i = 0; i < 1000000;){
		temp = harshad(i);
		i+=temp[0]+1;
		//dist[temp[0]]++;
	}
	
	for(int i = 0; i < dist.size(); i++){
		cout << dist[i] << ' ';
	}
	cout << '\n';
	*/
	
	return 0;
}
