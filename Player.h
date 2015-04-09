#ifndef PLAYER
#define PLAYER

#include<iostream>
#include<algorithm>
#include<utility>
#include<tuple>
#include<vector>
#include<string>
#include<queue>
#include <functional>

#include <chrono>
#include <random>

using std::vector;
using std::pair;
using std::tuple;
using std::string;

using std::make_pair;

using std::cout;
using std::endl;
using std::cin;


struct Role{
	string name = "";
	string desctiption = "";
	bool good = 1;

	Role(){}

	Role(const string n){
		name = n;
	}

	Role(string n, string d, bool g){
		name = n;
		desctiption = d;
		good = g;
	}

	void print(){
		cout << "Role: " << name << endl;
		for (int t = 0; t < 6; ++t){ cout << " "; }
		cout << desctiption << endl;
		if (good){
			for (int t = 0; t < 6; ++t){ cout << " "; }
			cout << "good" << endl;
		}
		else{
			for (int t = 0; t < 6; ++t){ cout << " "; }
			cout << "bad" << endl;
		}
	}

};

struct Player{
	string name = "";
	Role role;
	bool AI = 1;
	bool leader = 0;
	bool onTeam = 0;
	// unnecessary currently
	bool lady = 0;
	bool wasLady = 0;

	Player(){}

	Player(string n){
		name = n;
	}

	Player(string n, Role r){
		name = n;
		role = r;
	}

	Player(string n, Role r, bool l, bool o, bool l2, bool wl){
		name = n;
		role = r;
		leader = l;
		onTeam = o;
		lady = l2;
		wasLady = wl;
	}

	void changeRole(Role r);
	void changeLeader();
	void printStatus();
	bool teamV(bool s);
	bool questV(bool s);

};



void Player::changeRole(Role r){
	role.name = r.name;
	role.desctiption = r.desctiption;
	role.good = r.good;
}

void Player::changeLeader(){
	leader = !leader;
}

void Player::printStatus(){
	cout << endl;
	cout << "Name: " << name << endl;
	role.print();
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

bool Player::teamV(bool s){
	bool ret;
	cout << endl;
	cout << "do you aprove or reject this team" << endl;
	cout << "Approve:" << 1 << endl;
	cout << "Reject:" << 0 << endl;
	cin >> ret;
	cout << endl;
	cout << "You voted: " << ret << endl;
	cout << endl;
	return ret;
}

bool Player::questV(bool s){
	bool ret = 1;
	cout << endl;
	cout << "do you want this quest to succeed or fail" << endl;
	cout << "Success:" << 1 << endl;
	cout << "Fail:" << 0 << endl;
	if (role.good){
		cout << endl;
		cout << "the good always vote Success" << endl;
		cout << endl;
		system("Pause");
		cout << endl;
		return true;
	}
	else{
		cin >> ret;
		cout << endl;
		cout << "You voted: " << ret << endl;
		cout << endl;
		return ret;
	}
}



#endif
