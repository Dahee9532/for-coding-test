#include<bits/stdc++.h>

using namespace std;

class Student{
    public:
        string name;
        int score;
        Student(string name, int score){
            this->name = name;
            this->score = score;
        }
        //점수가 낮은 순서
        bool operator<(Student &other){
            return this->score < other.score;
        }
};

int n;
vector<Student> v;

int main(void){
    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        int score;
        cin >> name >> score;
        v.push_back(Student(name, score));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        cout << v[i].name << ' ';
    }
}