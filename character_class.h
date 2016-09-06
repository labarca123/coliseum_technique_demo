/**
@file character_class.h
@brief Declarations of the class(and related functions of) characters for Ore no Fantasy demo.
@author Jorge Rodríguez & Luis Garcia
@date 6/10/2016 
*/
#ifndef CHARACTERS
#define CHARACTERS

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class character{
	private:
		std::string id;		//Identifier of the object
		int vit;			//vitality of the object (HP)
		int str;			//strenght
		int res;			//resistance
		int agi;			//agility
		int know;			//knowlegde
		int bless;			//blessings
		int luck;			//luck (dice)
		std::string talent;	//talent(Which it was born with)
		std::string class_type;	//Specialization (Which it decided to use)
		std::string location; //Place where the character is.

	public:
		character();			
		character(character &);

		~character(){}
	
		/**
		@brief id Observer
		*/
		std::string inline see_id()const{

			return(this->id);

		}

		/**
		@brief vitality Observer
		*/
		int inline see_vit()const{

			return(this->vit);

		}

		/**
		@brief strenght Observer
		*/
		int inline see_str()const{

			return(this->str);

		}

		/**
		@brief resistance Observer
		*/
		int inline see_res()const{

			return(this->res);

		}

		/**
		@brief agility Observer
		*/
		int inline see_agi()const{

			return(this->agi);

		}

		/**
		@brief knowledge Observer
		*/
		int inline see_know()const{

			return(this->know);

		}

		/**
		@brief blessing Observer
		*/
		int inline see_bless()const{

			return(this->bless);

		}

		/**
		@brief luck Observer
		*/
		int inline see_luck()const{

			return(this->luck);

		}

		/**
		@brief talent Observer
		*/
		std::string inline see_talent()const{

			return(this->talent);

		}

		/**
		@brief Class Observer
		*/
		std::string inline see_class_type()const{

			return(this->class_type);

		}

		/**
		@brief location observer
		*/
		std::string inline see_location() const{

			return(this->location);

		}

	//Modifiers:
		int change_id(std::string &);
		int change_vit(int);
		int change_str(int);
		int change_res(int);
		int change_agi(int);
		int change_know(int);
		int change_bless(int);
		int define_luck();
		void define_class_type(std::string);

	//Battle methods:
		int attack(int);
		int recieve_attack(int, int);	

};
#endif
