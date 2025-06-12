/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:02:06 by tcarlier          #+#    #+#             */
/*   Updated: 2025/06/13 01:18:39 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

typedef std::string str;

class Weapon{
	private :
		str type;
	
	public :
		Weapon();
		Weapon(str type);
		~Weapon();
		const str& getType();
		void setType(str type);
};

#endif