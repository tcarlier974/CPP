#ifndef CONTACT_H
# define CONTACT_H

# include "header.hpp"

class Contact {
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string secret;
		str phone;
	
	public :
		
		void set_first(std::string first);
		void set_last(std::string last);
		void set_nickname(std::string nick);
		void set_secret(std::string secret);
		void set_phone(str phone);

		std::string get_first();
		std::string get_last();
		std::string get_nickname();
		std::string get_secret();
		str get_phone();
		Contact();
		~Contact( void );

};
#endif
