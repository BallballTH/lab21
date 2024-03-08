#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

class Monster{
 public:
 int hp;
 int atk;
 int def;
 vector<string> skills;
 Monster(double,double,double,vector<string>);
 Monster operator+(Monster);
};

Monster::Monster(double h,double a,double d,vector<string> s){
 hp = h; atk = a; def = d;
 skills = s;
}

Monster Monster::operator+(Monster M){
    int hpdiff,atkdiff,defdiff;
    hpdiff = abs(hp-M.hp);
    atkdiff = abs(atk-M.atk);
    defdiff = abs(def-M.def);
    vector<string> newM_skills;
    Monster newM = {0,0,0,newM_skills};
    newM.hp = (rand()%(hpdiff-1)+min(hp,M.hp));
    newM.atk = (rand()%(atkdiff-1)+min(atk,M.atk));
    newM.def = (rand()%(defdiff-1)+min(def,M.def));
    for(int i=0; i<skills.size(); i++){
        if(rand()%2 == 1)newM.skills.push_back(this->skills[i]);
    }
    for(int i=0; i<M.skills.size(); i++){
        if(rand()%2 == 1){
            if(M.skills[i] != newM.skills[i]) newM.skills.push_back(M.skills[i]);
        }
    }
    return newM;
}

int main(){
 srand(time(0));
 vector<string> Pikachu_skills;
 Pikachu_skills.push_back("Tail Whip");
 Pikachu_skills.push_back("Spark");
 Pikachu_skills.push_back("Thunder");
 Monster Pikachu(100,40,20,Pikachu_skills);

 vector<string> Nidoran_skills;
 Nidoran_skills.push_back("Tail Whip");
 Nidoran_skills.push_back("Double Kick");
 Nidoran_skills.push_back("Toxic Spikes");
 Nidoran_skills.push_back("Poison Fang");
 Monster Nidoran(200,25,50,Nidoran_skills);

 Monster Nidochu = Nidoran+Pikachu;
 cout << "HP = " << Nidochu.hp;
 cout << "\t ATK = " << Nidochu.atk;
 cout << "\t DEF = " << Nidochu.def << "\n";
 cout << "SKILLS: \n";
 for(int i = 0; i < Nidochu.skills.size();i++){
 cout << "\t" << Nidochu.skills[i] << "\n";
 }
 return 0;
}
