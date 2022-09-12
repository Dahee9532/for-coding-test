#include<iostream>
#include<bits/stdc++.h>


using namespace std;
int T;
int digit[10][7]={{1,1,1,1,1,1,0},{0,0,1,1,0,0,0},
					{0,1,1,0,1,1,1},{0,1,1,1,1,0,1},	
					{1,0,1,1,0,0,1},{1,1,0,1,1,0,1},
					{1,1,0,1,1,1,1},{1,1,1,1,0,0,0},
					{1,1,1,1,1,1,1},{1,1,1,1,1,0,1}};

int main(int argc, char** argv)
{
	cin >> T;
	vector<pair<string, string> > number;

	for(int i = 0; i < T; i++){
		string x, y;
		cin >> x >> y;
		number.push_back(make_pair(x,y));
	}

	int diff = 0;

	for(int i = 0; i < T; i++){
		diff = 0;
		int firInd = 0;
		int secInd = 0;
		if(number[i].first.size() == number[i].second.size()){
			for(int j = 0; j < number[i].first.size(); j++){
				for(int k = 0; k < 7; k++){
					if(digit[number[i].first[j]-'0'][k] != digit[number[i].second[j]-'0'][k]) diff++;
					else continue;
				}
			}
			cout << diff << '\n';
			continue;
		}
		else if(number[i].first.size() > number[i].second.size()){
			for(int j = 0; j < number[i].first.size()-number[i].second.size(); j++){
				for(int k = 0; k < 7; k++){
					if(digit[number[i].first[j]-'0'][k] == 1) diff++;
				}	
				firInd++;
			}
		}
		else if(number[i].first.size() < number[i].second.size()){
			for(int j = 0; j < number[i].second.size()-number[i].first.size(); j++){
				for(int k = 0; k < 7; k++){
					if(digit[number[i].second[j]-'0'][k] == 1) diff++;
				}
				secInd++;	
			}
		}
		for(int j = 0; j < min(number[i].first.size(), number[i].second.size()); j++){
			for(int k = 0; k < 7; k++){
				if(digit[number[i].first[j+firInd]-'0'][k] != digit[number[i].second[j+secInd]-'0'][k]) diff++;
				else continue;
			}
		}
		cout << diff << '\n';
	}

	return 0;
}
