#ifndef __PLAYER_H_
#define __PLAYER_H_


#include "Creature.h"

using namespace std;


class Player : public Creature
{

	public:
			Player(char*, char*, Room*);
			~Player();

			void Look(const vector<string> & ) const;
			void Inventory() const;
			bool Go(const vector<string> & );
			bool Take(const vector<string> &);
			bool Drop(const vector<string> &);
			bool Use(const vector<string> &);




};

#endif