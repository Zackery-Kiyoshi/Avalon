
#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "Player.h"

using std::vector;

class Agent: public Player{
private:
	int impulse = 0;
	char role = ' ';
	int playerNum = 0;
	//	Game* game;
	// Currently only use Vector[0]
	vector<vector<double>> trustMatrix; 
	vector<double> roleTheory;
	vector<vector<int>> perciTheory; 
	bool isPerciNeeded = 0;
	
	//	/*
	string name = "";
	Role roles;
	bool AI = 1;
	bool leader = 0;
	bool onTeam = 0;
	// unnecessary currently
	bool lady = 0;
	bool wasLady = 0;
	//	*/

	//	 why not just constructior??
	void setDefualt(){
		vector<double> tmp(0);
		roleTheory = tmp;
		for (int i = 0; i < 0; ++i){
			trustMatrix.push_back(tmp);
		}
	}
public:

	//	constructors from Player
	Agent(string n){
		name = n;
	}
	Agent(string n, Role r){
		name = n;
		roles = r;
	}
	Agent(string n, Role r, bool l, bool o, bool l2, bool wl){
		name = n;
		roles = r;
		leader = l;
		onTeam = o;
		lady = l2;
		wasLady = wl;
	}

	Agent(){ setDefualt(); }
	Agent(int sz){
		vector<double> tmp(sz);
		roleTheory = tmp;
		for (int i = 0; i < sz; ++i){
			trustMatrix.push_back(tmp);
		}
	}

	void setRole(char r);
	void setKnowledge(vector<double> info);
	void setKnowledgePerci(vector<vector<int>> info);

	// For use w/ Game deliberate() 
	void analyze();
	void argue();

	// For use w/ Game phase 
	vector<int> createParty();
	void reviewParty();
	bool voteParty();
	void reviewPartyResults(vector<bool> votes);
	bool voteMission();
	void reviewMissionResults(vector<int> votes, vector<bool> pVotes);


	//	Player methods
	void changeRole(Role r);
	void changeLeader();
	void printStatus();
	bool teamV(bool s);
	bool questV(bool s);

};

void Agent::setRole(char r){
	role = r;
}

void Agent::setKnowledge(vector<double> info){
	roleTheory = info;
}
void Agent::setKnowledgePerci(vector<vector<int>> info){

}

// For use w/ Game deliberate() 
void Agent::analyze(){
	// not implementing yet
}
void Agent::argue(){
	// not implementing yet
}

// For use w/ Game phase 
vector<int> Agent::createParty(){
	vector<int> ret{};



	return ret;
}
void Agent::reviewParty(){

}
bool Agent::voteParty(){
	bool ret = 0;

	return ret;
}
void Agent::reviewPartyResults(vector<bool> votes){

}
bool Agent::voteMission(){
	bool ret = 0;

	return ret;
}
void reviewMissionResults(vector<int> votes, vector<bool> pVotes){

}
// v[0] = # Success, v[1] = # Fail

// Player methods
void Agent::changeRole(Role r){
	roles.name = r.name;
	roles.desctiption = r.desctiption;
	roles.good = r.good;
	
	char ret;
	if (roles.name == "Loyal Servant of Arthur") ret = 'G';
	else if (roles.name == "Minion of Mordred") ret = 'E';
	else if (roles.name == "Merlin") ret = 'M';
	else if (roles.name == "Percival") ret = 'P';
	else if (roles.name == "Morgana") ret = 'R';
	else if (roles.name == "Mordred") ret = 'D';
	else if (roles.name == "Oberon") ret = 'O';
	else if (roles.name == "Assassian") ret = 'A';

	setRole(ret);
}
void Agent::changeLeader(){
	leader = !leader;
}
void Agent::printStatus(){
	cout << endl;
	cout << "Name: " << name << endl;
	roles.print();
	if (leader){
		cout << "Leader Status: " << "Yes" << endl;
	}
	else cout << "Leader Status: " << "No" << endl;
	if (lady){
		cout << "  You are the lady of the lake" << endl;
	}
	if (wasLady){
		cout << "You have been lady of the lake" << endl;
	}
	cout << endl;
}
bool Agent::teamV(bool s){
	bool ret = 0;
	ret = voteParty();
	return ret;
}
bool Agent::questV(bool s){
	bool ret = 0;
	ret = voteMission();
	return ret;
}

#endif 
