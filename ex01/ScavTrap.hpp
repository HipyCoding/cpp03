/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:42:14 by candrese          #+#    #+#             */
/*   Updated: 2025/02/11 08:00:28 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		// Orthodox Canonical Form
		ScavTrap();
		ScavTrap(std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap();

		// Memberfunctions
		void 		attack(const std::string& target);
		void 		guardGate(void);
};

#endif
