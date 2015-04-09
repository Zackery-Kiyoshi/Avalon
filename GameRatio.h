#ifndef GAMERATIO
#define GAMERATIO

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

#include"Player.h"

using std::vector;
using std::pair;
using std::tuple;
using std::string;

using std::make_pair;

using std::cout;
using std::endl;
using std::cin;


struct GameRatio{
	pair<int, int> ratio = make_pair(0, 0);
	int good = 0;
	int bad = 0;
	bool Merlin = 0;
	bool Percival = 0;
	bool Morgana = 0;
	bool Mordred = 0;
	bool Oberon = 0;
	bool Assassian = 0;
	vector<int> quests;

	GameRatio(){}

	GameRatio(pair<int, int> r, int g, int b, bool M1, bool P, bool M2, bool M3, bool O, bool A){
		ratio = r;
		good = g;
		bad = b;
		Merlin = M1;
		Percival = P;
		Morgana = M2;
		Mordred = M3;
		Oberon = O;
		Assassian = A;
	}

};


/*

Number of Good and Evil players
Players	5	6	7	8	9	10
Good	3	4	4	5	6	6
Evil	2	2	3	3	3	4

*/

	/*

Number of people on each quest
Players	5	6	7	8	9	10
1st Q	2	2	2	3	3	3
2nd Q	3	3	3	4	4	4
3rd Q	2	4	3	4	4	4
4th Q * 3	3	4	5	5	5
5th Q	3	4	4	5	5	5

but in games of 7 or more the 4th Quest requires two fails to be failed
//	*/

GameRatio makeGameRatio(int p){
	if (p < 5){
		GameRatio g;
		cout << "not enough players" << endl;
		return g;
	}
	else if (p > 10){
		GameRatio g;
		cout << "too many players" << endl;
		return g;
	}
	else if (p == 5){
		vector<int> p5{ 2, 3, 2, 3, 3 };




	}
	else if (p == 6){
		vector<int> p6{ 2, 3, 4, 3, 4 };



	}
	else if (p == 7){
		vector<int> p7{ 2, 3, 3, 4, 4 };



	}
	else if (p >= 8){
		vector<int> p8{ 3, 4, 4, 5, 5 };
		


	}
}

#endif
