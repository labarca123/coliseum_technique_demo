/**
@file characters.cpp
@brief Definition of the class and functions of characters.h
*/
#include "characters_class.h"

/**
 @brief Constructor by default
*/
character::character() {

	this->id = "Generic character";
	this->vit = 100;
	this->str = 50;
	this->res = 50;
	this->agi = 50;
	this->know = 50;
	this->bless = 50;
	this->luck = rand() % 5 + 1;
	this->talent = "";
	this->class_type = "";
	this->location = "";
	return;

}

/**
 @brief Copy constructor
*/
character::character(character &Ed){
	this->id = Ed.id;
	this->vit = Ed.vit;
	this->str = Ed.str;
	this->res = Ed.res;	
	this->agi = Ed.agi;
	this->know = Ed.know;	
	this->bless = Ed.bless;
	this->luck = Ed.luck;
	this->talent = Ed.talent;
	this->class_type = Ed.class_type;
	this->location = Ed.location;

}

/**
@brief Changes the id of the Object
@param A string with the new id of the object
*/
int character::change_id(std::string &name){

	this->id = name;
	return 0;

}

/**
@brief Changes the vitality or Hp of the object
@param Integer with the new vitality value
@return 0 if it could change the value
@return -1 if it couldn't change the value
*/
int character::change_vit(int hp){

	if(hp >= 0){
		
		this->vit = hp;
		return 0;

	}else{

		return -1;

	}

}

/**
@brief Changes the strenght of the object
@param Integer with the new strenght value
@return 0 if it could change the value
@return -1 if it couldn't change the value
*/
int character::change_str(int atck){

	if(atck >= 0){
	
		this->str = atck;
		return 0;
	
	}else{
	
		return -1;

	}

}

/**
@brief Changes the resistance of the object
@param Integer with the new resistance value
@return 0 if it could change the value
@return -1 if it couldn't change the value
*/
int character::change_res(int def){

	if(def >= 0){

		this->res = def;
		return 0;

	}else{

		return -1;

	}

}

/**
@brief Changes the agility of the object
@param Integer with the new agility value
@return 0 if it could change the value
@return -1 if it couldn't change the value
*/
int character::change_agi(int agy){

	if(agy >= 0){
		
		this->agi = agy;
		return 0;

	}else{

		return -1;

	}

}

/**
@brief Changes the knowledge of the object
@param Integer with the new knowledge value
@return 0 if it could change the value
@return -1 if it couldn't change the value
*/
int character::change_know(int mag){

	if(mag >= 0){
		
		this->know = mag;
		return 0;

	}else{

		return -1;

	}

}

/**
@brief Changes the blessing of the object
@param Integer with the new blessing value
@return 0 if it could change the value
@return -1 if it couldn't change the value
*/
int character::change_bless(int magDef){

	if(magDef >= 0){
		
		this->bless = magDef;
		return 0;

	}else{

		return -1;

	}

}

/**
@brief Defines the luck value of the object
*/
int character::define_luck(){

	this->luck = rand() % 100 + 1;

}

/**
@brief Derfines the object talent or afinity to an attribute
*/
int character::define_talent(){

	int a = rand() % 7 + 1;
	switch (a){
		case 1:{

			this->talent = "vit";
			this->vit += 50;
			break;

		}
		case 2:{

			this->talent = "str";
			this->str += 25;
			break;

		}
		case 3:{

			this->talent = "res";
			this->res += 25;
			break;

		}
		case 4:{

			this->talent = "agi";
			this->agi += 25;
			break;

		}
		case 5:{

			this->talent = "know";
			this->know += 25;
			break;

		}
		case 6:{

			this->talent = "bless";
			this->bless += 25;
			break;

		}
		default:{

			this->talent = "luck";
			this->luck += 25;
			break;

		}

	}

}

/**
@brief Defines the class of the object, it's designed to be used with a complementary function.
@param Recieves a string with the name of the class
*/
void character::define_class_type(std::string type){

	this->class_type = type;
	return;

}

/**
@brief Defines the location of the object within the "world's" map.
@param Recieves a string with the name of the location.
*/
void character::change_location(std::string place){

	this->location = place;
	return;

}

/**
@brief Method that calculates the integer value of the attack abstraction
@param An integer that represents the attack option (Melee or magic attack, defence or run)
@return The integer of the attack abstraction
@return -1 if the user decides to run away
*/
int character::attack(int a){

	int atk = 0;
	switch (a){

		case 1:{

			atk = this->str + ((this->agi+3)/4) - (this->res/2);
			break;

		} 
		case 2:{

			atk = this->know + ((this->agi+3)/4) - (this->bless/2);
			break;

		}
		case 3:{

			atk = 0;
			this->res += (this->res/2);
			break;

		}
		
		return atk;

	}

}

/**
@brief Method to recieve the attack
@param an integer with the attack value
*/
int character::recieve_attack(int dmg, int type){

	if(dmg == -1){

		return -1;

	}else{

		this->vit = this->vit - dmg;

	}

}
