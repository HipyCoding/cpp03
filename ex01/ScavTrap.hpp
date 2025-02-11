/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:42:14 by candrese          #+#    #+#             */
/*   Updated: 2025/02/11 14:51:33 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		// Orthodox Canonical Form
		ScavTrap();
		ScavTrap(std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap();

		// Member functions
		void attack(std::string& target);
		void guardGate(void);
};

#endif
