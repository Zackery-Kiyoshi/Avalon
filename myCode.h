#ifndef MINE
#define MINE



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

#include"GameRatio.h"
#include"Player.h"



using std::vector;
using std::pair;
using std::tuple;
using std::string;
using std::make_pair;
using std::cout;
using std::endl;
using std::cin;



int sum(vector<int> t){
	int ret = 0;
	for (auto i : t){
		ret += i;
	}
	return ret;
}


void runSetup(GameRatio game, vector<Player> &players){
	cout << "Running setup" << endl;

	Role g("Loyal Servant of Arthur", "Useless", 1);
	Role b("Minion of Mordred", "Useless", 0);
	Role mer("Merlin", "Knows evil, must remain hidden", 1);
	Role p("Percival", "Knows Merlin", 1);
	Role morg("Morgana", "Appears as Merlin", 0);
	Role mord("Mordred", "Unknown to Merlin", 0);
	Role o("Oberon", "Unknown to Evil", 0);
	Role as("Assassian", "Has ", 0);

	vector<Role> role;
	int roleT = 0;

	for (int i = 0; i < game.good; ++i){
		role.push_back(g);
		roleT += 1;
	}
	for (int i = 0; i < game.bad; ++i){
		role.push_back(b);
		roleT += 1;
	}
	if (game.Merlin){
		role.push_back(mer);
		roleT += 1;
	}
	if (game.Assassian){
		role.push_back(as);
		roleT += 1;
	}
	if (game.Percival){
		role.push_back(p);
		roleT += 1;
	}
	if (game.Morgana){
		role.push_back(morg);
		roleT += 1;
	}
	if (game.Mordred){
		role.push_back(mord);
		roleT += 1;
	}
	if (game.Oberon){
		role.push_back(o);
		roleT += 1;
	}

	int disi = 10;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, disi);
	int sz = role.size();
	int i = 0;

	cout << (roleT == 0) << endl;
	// assigns random role
	while (roleT != 0){
		int x = abs((distribution(generator) % sz));
//		if (roleT[x]){
			(players[i]).changeRole(role[x]);
			cout << "printed: " << endl;
			role[x].print();
			roleT -= 1;
			++i;
//		}
	}


	cout << endl;

	// prints out what roles are in the game
//	/*
	for (auto i : role){
	cout << "Role: " << i.name << endl;
	for (int t = 0; t < 6; ++t){
	cout << " ";
	}
	cout << i.desctiption << endl;
	i.print();
	}
	cout << endl;
//	*/

	cout << "setup complete" << endl;

}

void explainGame(GameRatio g){
	cout << endl;
	cout << "" << endl;
	cout << endl;
	cout << "There are " << g.good << "normal good people" << endl;
	cout << "There are " << g.bad << "normal bad people" << endl;
	cout << "and: " << endl;
	if (g.Merlin){
		cout << endl;
		cout << "   Merlin" << endl;
		cout << "" << endl;
		cout << endl;
	}
	if (g.Assassian){
		cout << endl;
		cout << "   Assassian" << endl;
		cout << "" << endl;
		cout << endl;
	}
	if (g.Percival){
		cout << endl;
		cout << "   Percival" << endl;
		cout << "Percival is an optional Character on the side of Good. " << endl;
		cout << "Percival's special power is knowledge of Merlin at the start of the game. " << endl;
		cout << "Using Percival's knowledge wisely is key to protecting Merlin's idenity. " << endl;
		cout << "Adding Percvial into a game will make the Good side more powerful and win more often." << endl;
		cout << "Note: For games of 5, be sure to add either Mordred or Morgana when playing with Percival." << endl;
		cout << endl;
	}
	if (g.Morgana){
		cout << endl;
		cout << "   Morgana" << endl;
		cout << "Morgana is an optional Character on the side of Evil. " << endl;
		cout << "Morgana's special power is that she appears to be Merlin - revealing herself to Percival as Merlin. " << endl;
		cout << "Adding Morgana into a game will make the Evil side more powerful and win more often." << endl;
		cout << endl;
	}
	if (g.Mordred){
		cout << endl;
		cout << "   Mordred" << endl;
		cout << "Mordred is an optional Character on the side of Evil. " << endl;
		cout << "Mordred's special power is that his identity is not revaled to Merlin at the start of the game. " << endl;
		cout << "Adding Mordred into a game will make the Evil side more powerful and win more often." << endl;
		cout << "" << endl;
		cout << endl;
	}
	if (g.Oberon){
		cout << endl;
		cout << "   Oberon" << endl;
		cout << "Oberon is an optional Character on the side of Evil. " << endl;
		cout << "Oberon's special power is that he does not reveal himself to the other Evil players, nor does he gain knowledge of teh other Evil players at the start of the game." << endl;
		cout << "Oberon is not a 'Minion of Mordred' and does not open his eyes during the reveal at the start of the game. " << endl;
		cout << "Adding Oberon into a game will make the Good side more powerful and win more often." << endl;
		cout << "" << endl;
		cout << endl;
	}
	cout << endl;

	cout << "Yes : 1" << endl;
	cout << "No : 0" << endl;
	cout << "Does everyone understand? ";
	bool a = 1;
	cin >> a;
	if (!a) explainGame(g);

	cout << endl;

}

void revealStage(GameRatio g){
	cout << endl;
	cout << "Reveal Stage" << endl;
	cout << endl;
	cout << "Everyone close your eyes and extend your hand into a fist in front of you" << endl;
	cout << "Minons of Mordred,";
	if (g.Oberon){
		cout << " not Oberon - ";
	}
	cout << " open your eyes and look around so that you know all agents of Evil" << endl;
	cout << "Minions of Mordred close your eyes" << endl;
	cout << "All players should have their eyes closed and hands in a fist in front of them" << endl;
	cout << "Minions of Mordred,";
	if (g.Mordred){
		cout << " not Mordred himself -";
	}
	cout << " extend your thumb so that Merlin will know of you" << endl;
	cout << "Merlin, open your eyes and see the agents of Evil" << endl;
	cout << "Minions of Mordred - put your thumbs down and re-form your hand into a fist" << endl;
	cout << "Merlin, close your eyes" << endl;
	cout << "All players should have their eyes closed and hands in a fist in front of them" << endl;
	if (g.Percival){
		cout << "Merlin and Morgana - extend your thumb so that Percibal may know of you" << endl;
		cout << "Percival, open your eyes so you may know Merlin and Morgana" << endl;
		cout << "Merlin and Morgana - put your thumbs down and form your hand into a fist" << endl;
		cout << "Percival, close your eyes" << endl;
	}
	cout << "All players should have their eyes closed and hands in a fist in front of them" << endl;
	cout << "Everyone open your eyes" << endl;
	cout << endl;
	cout << endl;
}

bool playFirstRound(vector<Player> &p, int count){

	// find leader
	cout << "Find leader" << endl;
	int disi = 10;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, disi);
	int numPlayers = abs((distribution(generator) % 5)) + 5;
	int t = distribution(generator) % numPlayers;

	int leader = distribution(generator);
	cout << leader << endl;
	p[leader].changeLeader();

	// leader makes the team
	cout << "Leader makes the team" << endl;

	// diesuccion about team
	cout << "Diesuccion about team" << endl;

	// vote for the team
	cout << "Vote for the team" << endl;
	for (auto i : p){
		cout << endl;
		i.teamV(0);
		cout << endl;
		cout << "when next player is ready" << endl;
		system("Pause");
		cout << endl;
	}

	// either team passes vote or passes to next leader
	cout << "either team passes vote or passes to next leader" << endl;
	cout << endl;
	unsigned int vote = 0;
	for (auto i : p){
		vote += i.teamV(0);
	}

	if (vote > p.size()){
		for (auto i : p){
			if (i.onTeam){
				cout << endl;
				i.questV(0);
				cout << "when next player is ready" << endl;
				system("Pause");
			}
		}

		for (auto i : p){
			if (i.onTeam){
				if (!i.questV(0)) return false;
			}
		}
		return true;
	}
	else{
		count += 1;
		if (count != 5){
			return playFirstRound(p, count);
		}
		else{
			return false;
		}
	}
}


bool playRound( vector<Player> &p, int count ){
	// count how many times vote for this quest have failed

	// find leader
	cout << "Find leader" << endl;
	int disi = 10;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, disi);
	int numPlayers = abs((distribution(generator) % 5)) + 5;
	int t = distribution(generator) % numPlayers;

	int leader = distribution(generator);
	cout << leader << endl;
	p[leader].changeLeader();


	// leader makes the team
	cout << "Leader makes the team" << endl;


	// everyone reviews the team

	// diesuccion about team
	cout << "Diesuccion about team" << endl;



	// vote for the team
	cout << "Vote for the team" << endl;
	for (auto i : p){
		cout << endl;
		i.teamV(0);
		cout << endl;
		cout << "when next player is ready" << endl;
		system("Pause");
		cout << endl;
	}

	// either team passes	 vote or passes to next leader
	cout << "either team passes vote or passes to next leader" << endl;
	cout << endl;
	unsigned int vote = 0;
	for (auto i : p){
		vote += i.teamV(0);
	}

	if (vote > p.size()){
		for (auto i : p){
			if (i.onTeam){
				cout << endl;
				i.questV(0);
				cout << "when next player is ready" << endl;
				system("Pause");
			}
		}

		for (auto i : p){
			if (i.onTeam){
				if (!i.questV(0)) return false;
			}
		}
		return true;
	}
	else{
		count += 1;
		if (count != 5){
			return playFirstRound(p, count);
		}
		else{
			return false;
		}
	}
}


#endif
