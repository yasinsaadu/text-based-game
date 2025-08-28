#include <iostream>
#include <string>
using namespace std;

void namerequest(){
  cout<<"Welcome, adventurer. What would you like to be called? ";
}

void questreport(){
  cout<<"The Demon King has just raised his army of the undead and he reigning terror upon the Continent."<<endl;
  cout<<"The Continent is in dire need of a great band of heroes to stop this army of destruction and terror."<<endl;
  cout<<"Before we continue, I must warn you, death awaits all who choose to fight, but we believe that there will be light of hope at the end of the tunnel that would deem us victorious in our pursuit for glory and freedom."<<endl;
}

int main(){
  string name;
  namerequest();
  getline(cin, name);
  cout<<"\nAlright! Adventurer " << name << ", you will be briefed about the quest shortly."<<endl;
  questreport();

  return 0;
}