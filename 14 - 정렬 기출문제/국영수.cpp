// #include <iostream>
// #include <vector>
// #include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Student{
  public:
    string name;
    int kor;
    int eng;
    int mat;
    Student(string name, int kor, int eng, int mat){
      this->name = name;
      this->kor = kor;
      this->eng = eng;
      this->mat = mat;
    }
  bool operator<(Student &other){
    if(this->kor == other.kor && this->eng == other.eng && this->mat == other.mat){
      return this->name < other.name;
      }
    if(this->kor == other.kor && this->eng == other.eng){
      return this->mat > other.mat;
      }
    if(this->kor == other.kor == other.kor){
      return this->eng < other.eng;
    }
    return this->kor > other.kor;
  }
};

int n;
vector<Student> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    string name;
    int kor, eng, mat;
    cin >> name >> kor >> eng >> mat;
    v.push_back(Student(name, kor, eng, mat));
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++){
    cout << v[i].name << '\n';
  }
}