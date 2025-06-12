/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:52:27 by tcarlier          #+#    #+#             */
/*   Updated: 2025/06/13 01:16:37 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA{
	private :
		str name;
		Weapon& weapon;
	public :
		HumanA(str name, Weapon& weapon);
		~HumanA();
		void attack();
};

#endif