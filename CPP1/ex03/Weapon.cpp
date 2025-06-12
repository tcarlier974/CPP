#include "Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon(str type){
	this->type = type;
}

Weapon::~Weapon(){

}

void	Weapon::setType(str type){
	this->type = type;
}

const str& Weapon::getType(){
	return this->type;
}