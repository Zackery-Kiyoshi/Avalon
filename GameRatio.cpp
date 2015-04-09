
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


/*
Number of Good and Evil players
Players	5	6	7	8	9	10
Good	3	4	4	5	6	6
Evil	2	2	3	3	3	4
*/

//	GameRatio t(make_pair(3, 2), 3, 2, 0, 0, 0, 0, 0, 0);



//	3,2
/*
ratio:G, E	Good	Bad		Merlin	Percival	Morgana	Mordred	Oberon	Assassian
	  (make_pair(3, 2),3,2,0,0,0,0,0,0)
	  (make_pair(3, 2),2,2,1,0,0,0,0,0)
	  (make_pair(3, 2),2,2,0,1,0,0,0,0)
	  (make_pair(3, 2),1,2,1,1,0,0,0,0)

	  (make_pair(3, 2),3,1,0,0,1,0,0,0)
	  (make_pair(3, 2),3,1,0,0,0,1,0,0)
	  (make_pair(3, 2),3,1,0,0,0,0,1,0)
	  (make_pair(3, 2),3,1,0,0,0,0,0,1)
	  (make_pair(3, 2),2,1,1,0,1,0,0,0)
	  (make_pair(3, 2),2,1,1,0,0,1,0,0)
	  (make_pair(3, 2),2,1,1,0,0,0,1,0)
	  (make_pair(3, 2),2,1,1,0,0,0,0,1)
	  (make_pair(3, 2),2,1,0,1,1,0,0,0)
	  (make_pair(3, 2),2,1,0,1,0,1,0,0)
	  (make_pair(3, 2),2,1,0,1,0,0,1,0)
	  (make_pair(3, 2),2,1,0,1,0,0,0,1)
	  (make_pair(3, 2),1,1,1,1,1,0,0,0)
	  (make_pair(3, 2),1,1,1,1,0,1,0,0)
	  (make_pair(3, 2),1,1,1,1,0,0,1,0)
	  (make_pair(3, 2),1,1,1,1,0,0,0,1)
	  
	  (make_pair(3, 2),3,0,0,0,1,1,0,0)
	  (make_pair(3, 2),3,0,0,0,1,0,1,0)
	  (make_pair(3, 2),3,0,0,0,1,0,0,1)
	  (make_pair(3, 2),3,0,0,0,0,1,1,0)
	  (make_pair(3, 2),3,0,0,0,0,1,0,1)
	  (make_pair(3, 2),3,0,0,0,0,0,1,1)
	  (make_pair(3, 2),2,0,1,0,0,0,0,0)
	  (make_pair(3, 2),2,0,0,1,0,0,0,0)
	  (make_pair(3, 2),1,0,1,1,1,1,0,0)
	  (make_pair(3, 2),1,0,1,1,1,0,1,0)
	  (make_pair(3, 2),1,0,1,1,1,0,0,1)
	  (make_pair(3, 2),1,0,1,1,0,1,0,0)
	  (make_pair(3, 2),1,0,1,1,0,1,1,0)
	  (make_pair(3, 2),1,0,1,1,0,1,0,1)
	  (make_pair(3, 2),1,0,1,1,0,0,1,0)
	  (make_pair(3, 2),1,0,1,1,0,0,1,1)
*/

//	vector<GameRatio> n1;

//	4,2
/*

  ratio:G, E	Good	Bad		Merlin	Percival	Morgana	Mordred	Oberon	Assassian
		NTF
		(make_pair(4, 2),4,2,0,0,0,0,0,0)
		(make_pair(4, 2),3,2,1,0,0,0,0,0)
		(make_pair(4, 2),3,2,0,1,0,0,0,0)
		(make_pair(4, 2),2,2,1,1,0,0,0,0)


		(make_pair(4, 2),4,1,0,0,1,0,0,0)
		(make_pair(4, 2),4,1,0,0,0,1,0,0)
		(make_pair(4, 2),4,1,0,0,0,0,1,0)
		(make_pair(4, 2),4,1,0,0,0,0,0,1)
		(make_pair(4, 2),3,1,1,0,1,0,0,0)
		(make_pair(4, 2),3,1,1,0,0,1,0,0)
		(make_pair(4, 2),3,1,1,0,0,0,1,0)
		(make_pair(4, 2),3,1,1,0,0,0,0,1)
		(make_pair(4, 2),3,1,0,1,1,0,0,0)
		(make_pair(4, 2),3,1,0,1,0,1,0,0)
		(make_pair(4, 2),3,1,0,1,0,0,1,0)
		(make_pair(4, 2),3,1,0,1,0,0,0,1)
		(make_pair(4, 2),2,1,1,1,1,0,0,0)
		(make_pair(4, 2),2,1,1,1,0,1,0,0)
		(make_pair(4, 2),2,1,1,1,0,0,1,0)
		(make_pair(4, 2),2,1,1,1,0,0,0,1)

		(make_pair(4, 2),4,0,0,0,1,1,0,0)
		(make_pair(4, 2),4,0,0,0,1,0,1,0)
		(make_pair(4, 2),4,0,0,0,1,0,0,1)
		(make_pair(4, 2),4,0,0,0,0,1,1,0)
		(make_pair(4, 2),4,0,0,0,0,1,0,1)
		(make_pair(4, 2),4,0,0,0,0,0,1,1)
		(make_pair(4, 2),3,0,1,0,1,1,0,0)
		(make_pair(4, 2),3,0,1,0,1,0,1,0)
		(make_pair(4, 2),3,0,1,0,1,0,0,1)
		(make_pair(4, 2),3,0,1,0,0,1,1,0)
		(make_pair(4, 2),3,0,1,0,0,1,0,1)
		(make_pair(4, 2),3,0,1,0,0,0,1,1)
		(make_pair(4, 2),3,0,0,1,1,1,0,0)
		(make_pair(4, 2),3,0,0,1,1,0,1,0)
		(make_pair(4, 2),3,0,0,1,1,0,0,1)
		(make_pair(4, 2),3,0,0,1,0,1,1,0)
		(make_pair(4, 2),3,0,0,1,0,1,0,1)
		(make_pair(4, 2),3,0,0,1,0,0,1,1)
		(make_pair(4, 2),2,0,1,1,1,1,0,0)
		(make_pair(4, 2),2,0,1,1,1,0,1,0)
		(make_pair(4, 2),2,0,1,1,1,0,0,1)
		(make_pair(4, 2),2,0,1,1,0,1,1,0)
		(make_pair(4, 2),2,0,1,1,0,1,0,1)
		(make_pair(4, 2),2,0,1,1,0,0,1,1)
		*/
//	vector<GameRatio> n2;

//	4,3
/*
	ratio:G, E	Good	Bad		Merlin	Percival	Morgana	Mordred	Oberon	Assassian
		  NTF
		  (make_pair(4, 3),4,3,0,0,0,0,0,0)
		  (make_pair(4, 3),3,3,1,0,0,0,0,0)
		  (make_pair(4, 3),3,3,0,1,0,0,0,0)
		  (make_pair(4, 3),2,3,1,1,0,0,0,0)

		  (make_pair(4, 3),4,2,0,0,1,0,0,0)
		  (make_pair(4, 3),4,2,0,0,0,1,0,0)
		  (make_pair(4, 3),4,2,0,0,0,0,1,0)
		  (make_pair(4, 3),4,2,0,0,0,0,0,1)
		  (make_pair(4, 3),3,2,1,0,1,0,0,0)
		  (make_pair(4, 3),3,2,1,0,0,1,0,0)
		  (make_pair(4, 3),3,2,1,0,0,0,1,0)
		  (make_pair(4, 3),3,2,1,0,0,0,0,1)
		  (make_pair(4, 3),3,2,0,1,1,0,0,0)
		  (make_pair(4, 3),3,2,0,1,0,1,0,0)
		  (make_pair(4, 3),3,2,0,1,0,0,1,0)
		  (make_pair(4, 3),3,2,0,1,0,0,0,1)
		  (make_pair(4, 3),2,2,1,1,1,0,0,0)
		  (make_pair(4, 3),2,2,1,1,0,1,0,0)
		  (make_pair(4, 3),2,2,1,1,0,0,1,0)
		  (make_pair(4, 3),2,2,1,1,0,0,0,1)

		  (make_pair(4, 3),2,1,1,1,1,1,0,0)
		  (make_pair(4, 3),2,1,1,1,1,0,1,0)
		  (make_pair(4, 3),2,1,1,1,1,0,0,1)
		  (make_pair(4, 3),2,1,1,1,0,1,1,0)
		  (make_pair(4, 3),2,1,1,1,0,1,0,1)
		  (make_pair(4, 3),2,1,1,1,0,0,1,1)
		  (make_pair(4, 3),2,1,1,0,1,1,0,0)
		  (make_pair(4, 3),2,1,1,0,1,0,1,0)
		  (make_pair(4, 3),2,1,1,0,1,0,0,1)
		  (make_pair(4, 3),2,1,1,0,0,1,1,0)
		  (make_pair(4, 3),2,1,1,0,0,1,0,1)
		  (make_pair(4, 3),2,1,1,0,0,0,1,1)
		  (make_pair(4, 3),2,1,0,1,1,1,0,0)
		  (make_pair(4, 3),2,1,0,1,1,0,1,0)
		  (make_pair(4, 3),2,1,0,1,1,0,0,1)
		  (make_pair(4, 3),2,1,0,1,0,1,1,0)
		  (make_pair(4, 3),2,1,0,1,0,1,0,1)
		  (make_pair(4, 3),2,1,0,1,0,0,1,1)
		  (make_pair(4, 3),2,1,1,1,1,1,0,0)
		  (make_pair(4, 3),2,1,1,1,1,0,1,0)
		  (make_pair(4, 3),2,1,1,1,1,0,0,1)
		  (make_pair(4, 3),2,1,1,1,0,1,1,0)
		  (make_pair(4, 3),2,1,1,1,0,1,0,1)
		  (make_pair(4, 3),2,1,1,1,0,0,1,1)

		  (make_pair(4, 3),4,0,0,0,0,1,1,1)
		  (make_pair(4, 3),4,0,0,0,1,0,1,1)
		  (make_pair(4, 3),4,0,0,0,1,1,0,1)
		  (make_pair(4, 3),4,0,0,0,1,1,1,0)
		  (make_pair(4, 3),2,0,1,0,0,1,1,1)
		  (make_pair(4, 3),2,0,1,0,1,0,1,1)
		  (make_pair(4, 3),2,0,1,0,1,1,0,1)
		  (make_pair(4, 3),2,0,1,0,1,1,1,0)
		  (make_pair(4, 3),2,0,0,1,0,1,1,1)
		  (make_pair(4, 3),2,0,0,1,1,0,1,1)
		  (make_pair(4, 3),2,0,0,1,1,1,0,1)
		  (make_pair(4, 3),2,0,0,1,1,1,1,0)
		  (make_pair(4, 3),2,0,1,1,0,1,1,1)
		  (make_pair(4, 3),2,0,1,1,1,0,1,1)
		  (make_pair(4, 3),2,0,1,1,1,1,0,1)
		  (make_pair(4, 3),2,0,1,1,1,1,1,0)


// vector<GameRatio> n3;

//	5,3
/*

	  ratio:G, E	Good	Bad		Merlin	Percival	Morgana	Mordred	Oberon	Assassian

			(make_pair(5, 3),5,3,0,0,0,0,0,0)
			(make_pair(5, 3),4,3,1,0,0,0,0,0)
			(make_pair(5, 3),4,3,0,1,0,0,0,0)
			(make_pair(5, 3),3,3,1,1,0,0,0,0)

			(make_pair(5, 3),5,2,0,0,1,0,0,0)
			(make_pair(5, 3),5,2,0,0,0,1,0,0)
			(make_pair(5, 3),5,2,0,0,0,0,1,0)
			(make_pair(5, 3),5,2,0,0,0,0,0,1)
			(make_pair(5, 3),4,2,1,0,1,0,0,0)
			(make_pair(5, 3),4,2,1,0,0,1,0,0)
			(make_pair(5, 3),4,2,1,0,0,0,1,0)
			(make_pair(5, 3),4,2,1,0,0,0,0,1)
			(make_pair(5, 3),4,2,0,1,1,0,0,0)
			(make_pair(5, 3),4,2,0,1,0,1,0,0)
			(make_pair(5, 3),4,2,0,1,0,0,1,0)
			(make_pair(5, 3),4,2,0,1,0,0,0,1)
			(make_pair(5, 3),3,2,1,1,1,0,0,0)
			(make_pair(5, 3),3,2,1,1,0,1,0,0)
			(make_pair(5, 3),3,2,1,1,0,0,1,0)
			(make_pair(5, 3),3,2,1,1,0,0,0,1)

			(make_pair(5, 3),5,1,0,0,1,1,0,0)
			(make_pair(5, 3),5,1,0,0,1,0,1,0)
			(make_pair(5, 3),5,1,0,,0,1,0,0,1)
			(make_pair(5, 3),5,1,0,0,0,1,1,0)
			(make_pair(5, 3),5,1,0,0,0,1,0,1)
			(make_pair(5, 3),5,1,0,0,0,0,1,1)
			(make_pair(5, 3),4,1,1,0,1,1,0,0)
			(make_pair(5, 3),4,1,1,0,1,0,1,0)
			(make_pair(5, 3),4,1,1,0,1,0,0,1)
			(make_pair(5, 3),4,1,1,0,0,1,1,0)
			(make_pair(5, 3),4,1,1,0,0,1,0,1)
			(make_pair(5, 3),4,1,1,0,0,0,1,1)
			(make_pair(5, 3),4,1,0,1,1,1,0,0)
			(make_pair(5, 3),4,1,0,1,1,0,1,0)
			(make_pair(5, 3),4,1,0,1,1,0,0,1)
			(make_pair(5, 3),4,1,0,1,0,1,1,0)
			(make_pair(5, 3),4,1,0,1,0,1,0,1)
			(make_pair(5, 3),4,1,0,1,0,0,1,1)
			(make_pair(5, 3),3,1,1,1,1,1,0,0)
			(make_pair(5, 3),3,1,1,1,1,0,1,0)
			(make_pair(5, 3),3,1,1,1,1,0,0,1)
			(make_pair(5, 3),3,1,1,1,0,1,1,0)
			(make_pair(5, 3),3,1,1,1,0,1,0,1)
			(make_pair(5, 3),3,1,1,1,0,0,1,1)

			(make_pair(5, 3),5,0,0,0,0,1,1,1)
			(make_pair(5, 3),5,0,0,0,1,0,1,1)
			(make_pair(5, 3),5,0,0,0,1,1,0,1)
			(make_pair(5, 3),5,0,0,0,1,1,1,0)
			(make_pair(5, 3),4,0,1,0,0,1,1,1)
			(make_pair(5, 3),4,0,1,0,1,0,1,1)
			(make_pair(5, 3),4,0,1,0,1,1,0,1)
			(make_pair(5, 3),4,0,1,0,1,1,1,0)
			(make_pair(5, 3),4,0,0,1,0,1,1,1)
			(make_pair(5, 3),4,0,0,1,1,0,1,1)
			(make_pair(5, 3),4,0,0,1,1,1,0,1)
			(make_pair(5, 3),4,0,0,1,1,1,1,0)
			(make_pair(5, 3),3,0,1,1,0,1,1,1)
			(make_pair(5, 3),3,0,1,1,1,0,1,1)
			(make_pair(5, 3),3,0,1,1,1,1,0,1)
			(make_pair(5, 3),3,0,1,1,1,1,1,0)

			*/

//	vector<GameRatio> n4;

//	6,3
/*
		ratio:G, E	Good	Bad		Merlin	Percival	Morgana	Mordred	Oberon	Assassian

			  (make_pair(6, 3),6,3,0,0,0,0,0,0)
			  (make_pair(6, 3),5,3,1,0,0,0,0,0)
			  (make_pair(6, 3),5,3,0,1,0,0,0,0)
			  (make_pair(6, 3),4,3,1,1,0,0,0,0)

			  (make_pair(6, 3),6,2,0,0,1,0,0,0)
			  (make_pair(6, 3),6,2,0,0,0,1,0,0)
			  (make_pair(6, 3),6,2,0,0,0,0,1,0)
			  (make_pair(6, 3),6,2,0,0,0,0,0,1)
			  (make_pair(6, 3),5,2,1,0,1,0,0,0)
			  (make_pair(6, 3),5,2,1,0,0,1,0,0)
			  (make_pair(6, 3),5,2,1,0,0,0,1,0)
			  (make_pair(6, 3),5,2,1,0,0,0,0,1)
			  (make_pair(6, 3),5,2,0,1,1,0,0,0)
			  (make_pair(6, 3),5,2,0,1,0,1,0,0)
			  (make_pair(6, 3),5,2,0,1,0,0,1,0)
			  (make_pair(6, 3),5,2,0,1,0,0,0,1)
			  (make_pair(6, 3),4,2,1,1,1,0,0,0)
			  (make_pair(6, 3),4,2,1,1,0,1,0,0)
			  (make_pair(6, 3),4,2,1,1,0,0,1,0)
			  (make_pair(6, 3),4,2,1,1,0,0,0,1)

			  (make_pair(6, 3),6,1,0,0,1,1,0,0)
			  (make_pair(6, 3),6,1,0,0,1,0,1,0)
			  (make_pair(6, 3),6,1,0,0,1,0,0,1)
			  (make_pair(6, 3),6,1,0,0,0,1,1,0)
			  (make_pair(6, 3),6,1,0,0,0,1,0,1)
			  (make_pair(6, 3),6,1,0,0,0,0,1,1)
			  (make_pair(6, 3),5,1,1,0,1,1,0,0)
			  (make_pair(6, 3),5,1,1,0,1,0,1,0)
			  (make_pair(6, 3),5,1,1,0,1,0,0,1)
			  (make_pair(6, 3),5,1,1,0,0,1,1,0)
			  (make_pair(6, 3),5,1,1,0,0,1,0,1)
			  (make_pair(6, 3),5,1,1,0,0,0,1,1)
			  (make_pair(6, 3),5,1,0,1,1,1,0,0)
			  (make_pair(6, 3),5,1,0,1,1,0,1,0)
			  (make_pair(6, 3),5,1,0,1,1,0,0,1)
			  (make_pair(6, 3),5,1,0,1,0,1,1,0)
			  (make_pair(6, 3),5,1,0,1,0,1,0,1)
			  (make_pair(6, 3),5,1,0,1,0,0,1,1)
			  (make_pair(6, 3),4,1,1,1,1,1,0,0)
			  (make_pair(6, 3),4,1,1,1,1,0,1,0)
			  (make_pair(6, 3),4,1,1,1,1,0,0,1)
			  (make_pair(6, 3),4,1,1,1,0,1,1,0)
			  (make_pair(6, 3),4,1,1,1,0,1,0,1)
			  (make_pair(6, 3),4,1,1,1,0,0,1,1)

			  (make_pair(6, 3),6,0,0,0,0,1,1,1)
			  (make_pair(6, 3),6,0,0,0,1,0,1,1)
			  (make_pair(6, 3),6,0,0,0,1,1,0,1)
			  (make_pair(6, 3),6,0,0,0,1,1,1,0)
			  (make_pair(6, 3),5,0,1,0,0,1,1,1)
			  (make_pair(6, 3),5,0,1,0,1,0,1,1)
			  (make_pair(6, 3),5,0,1,0,1,1,0,1)
			  (make_pair(6, 3),5,0,1,0,1,1,1,0)
			  (make_pair(6, 3),5,0,0,1,0,1,1,1)
			  (make_pair(6, 3),5,0,0,1,1,0,1,1)
			  (make_pair(6, 3),5,0,0,1,1,1,0,1)
			  (make_pair(6, 3),5,0,0,1,1,1,1,0)
			  (make_pair(6, 3),4,0,1,1,0,1,1,1)
			  (make_pair(6, 3),4,0,1,1,1,0,1,1)
			  (make_pair(6, 3),4,0,1,1,1,1,0,1)
			  (make_pair(6, 3),4,0,1,1,1,1,1,0)

			  */
//	vector<GameRatio> n5;

//	6,4
/*
		  ratio:G, E	Good	Bad		Merlin	Percival	Morgana	Mordred	Oberon	Assassian
				(make_pair(6, 4),6,4,0,0,0,0,0,0)
				(make_pair(6, 4),5,4,0,0,0,0,0,0)
				(make_pair(6, 4),4,4,0,0,0,0,0,0)

				(make_pair(6, 4),6,3,0,0,1,0,0,0)
				(make_pair(6, 4),6,3,0,0,0,1,0,0)
				(make_pair(6, 4),6,3,0,0,0,0,1,0)
				(make_pair(6, 4),6,3,0,0,0,0,0,1)
				(make_pair(6, 4),5,3,1,0,1,0,0,0)
				(make_pair(6, 4),5,3,1,0,0,1,0,0)
				(make_pair(6, 4),5,3,1,0,0,0,1,0)
				(make_pair(6, 4),5,3,1,0,0,0,0,1)
				(make_pair(6, 4),5,3,0,1,1,0,0,0)
				(make_pair(6, 4),5,3,0,1,0,1,0,0)
				(make_pair(6, 4),5,3,0,1,0,0,1,0)
				(make_pair(6, 4),5,3,0,1,0,0,0,1)
				(make_pair(6, 4),4,3,1,1,1,0,0,0)
				(make_pair(6, 4),4,3,1,1,0,1,0,0)
				(make_pair(6, 4),4,3,1,1,0,0,1,0)
				(make_pair(6, 4),4,3,1,1,0,0,0,1)
				
				(make_pair(6, 4),6,2,0,0,1,1,0,0)
				(make_pair(6, 4),6,2,0,0,1,0,1,0)
				(make_pair(6, 4),6,2,0,0,1,0,0,1)
				(make_pair(6, 4),6,2,0,0,0,1,1,0)
				(make_pair(6, 4),6,2,0,0,0,1,0,1)
				(make_pair(6, 4),6,2,0,0,0,0,1,1)
				(make_pair(6, 4),6,2,1,0,1,1,0,0)
				(make_pair(6, 4),6,2,1,0,1,0,1,0)
				(make_pair(6, 4),6,2,1,0,1,0,0,1)
				(make_pair(6, 4),6,2,1,0,0,1,1,0)
				(make_pair(6, 4),6,2,1,0,0,1,0,1)
				(make_pair(6, 4),6,2,1,0,0,0,1,1)
				(make_pair(6, 4),6,2,0,1,1,1,0,0)
				(make_pair(6, 4),6,2,0,1,1,0,1,0)
				(make_pair(6, 4),6,2,0,1,1,0,0,1)
				(make_pair(6, 4),6,2,0,1,0,1,1,0)
				(make_pair(6, 4),6,2,0,1,0,1,0,1)
				(make_pair(6, 4),6,2,0,1,0,0,1,1)
				(make_pair(6, 4),6,2,1,1,1,1,0,0)
				(make_pair(6, 4),6,2,1,1,1,0,1,0)
				(make_pair(6, 4),6,2,1,1,1,0,0,1)
				(make_pair(6, 4),6,2,1,1,0,1,1,0)
				(make_pair(6, 4),6,2,1,1,0,1,0,1)
				(make_pair(6, 4),6,2,1,1,0,0,1,1)
				
				(make_pair(6, 4),6,1,0,0,0,1,1,1)
				(make_pair(6, 4),6,1,0,0,1,0,1,1)
				(make_pair(6, 4),6,1,0,0,1,1,0,1)
				(make_pair(6, 4),6,1,0,0,1,1,1,0)
				(make_pair(6, 4),6,1,1,0,0,1,1,1)
				(make_pair(6, 4),6,1,1,0,1,0,1,1)
				(make_pair(6, 4),6,1,1,0,1,1,0,1)
				(make_pair(6, 4),6,1,1,0,1,1,1,0)
				(make_pair(6, 4),6,1,0,1,0,1,1,1)
				(make_pair(6, 4),6,1,0,1,1,0,1,1)
				(make_pair(6, 4),6,1,0,1,1,1,0,1)
				(make_pair(6, 4),6,1,0,1,1,1,1,0)
				(make_pair(6, 4),6,1,1,1,0,1,1,1)
				(make_pair(6, 4),6,1,1,1,1,0,1,1)
				(make_pair(6, 4),6,1,1,1,1,1,0,1)
				(make_pair(6, 4),6,1,1,1,1,1,1,0)
				
				(make_pair(6, 4),6,0,0,0,1,1,1,1)
				(make_pair(6, 4),5,0,1,0,1,1,1,1)
				(make_pair(6, 4),5,0,0,1,1,1,1,1)
				(make_pair(6, 4),4,0,1,1,1,1,1,1)


				*/
//	vector<GameRatio> n6;


//	vector<vector<GameRatio>> ratios{ n1,n2,n3,n4,n5,n6 };


//	
/*

				Rules:

				Number of Good and Evil players
				Players	5	6	7	8	9	10
				Good	3	4	4	5	6	6
				Evil	2	2	3	3	3	4



				

				One fail for any quest to fail
				but in games of 7 or more the 4th Quest requires two fails to be failed


				lady of the lake:
				given to first leaders right
				Immediately after the 2nd, 3rd, and 4th Quest is resolved
				then they get to reveal one person after the Quest and hand them the lady of the lake

				can't reveal what they are or the person they looked at.



				}
				
				
*/
