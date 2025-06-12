/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:24:21 by tcarlier          #+#    #+#             */
/*   Updated: 2025/06/12 20:07:09 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>
# include "Zombie.hpp"

typedef std::string str;



class Zombie {
	private :
		str name;

	public :
		Zombie(void);
		~Zombie(void);
		void	announce();
		void	setName(str name);
};
Zombie* zombieHorde(int n, str name);
	
#endif