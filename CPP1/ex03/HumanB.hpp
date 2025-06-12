/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:53:03 by tcarlier          #+#    #+#             */
/*   Updated: 2025/06/13 01:16:27 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB{
	private :
		str name;
		Weapon* weapon;
	public :
		HumanB(str name);
		~HumanB();
		void attack();
		void setWeapon(Weapon& weapon);
};

#endif