#include "header.hpp"

Contact::Contact(){
	std::cout << "New Contact added" << std::endl;
}

Contact::~Contact(){

	std::cout << "Contact removed succesfully" << std::endl;
}

void	Contact::set_first(std::string first){
	this->first_name = first;
}

void	Contact::set_last(std::string last){
	this->last_name = last;
}

void	Contact::set_nickname(std::string nick){
	this->nickname = nick;
}

void	Contact::set_secret(std::string secret){
	this->secret = secret;
}

void	Contact::set_phone(std::string phone){
	this->phone = phone;
}


std::string	Contact::get_first(void){
	return this->first_name;
}

std::string	Contact::get_last(void){
	return this->last_name;
}

std::string	Contact::get_nickname(void){
	return this->nickname;
}

std::string	Contact::get_secret(void){
	return this->secret;
}

std::string	Contact::get_phone(void){
	return this->phone;
}
