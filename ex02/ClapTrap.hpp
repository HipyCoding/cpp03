/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:00:20 by christian         #+#    #+#             */
/*   Updated: 2025/02/11 11:53:31 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <string_view>
# include <iostream>

class ClapTrap {
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	// Orthodox Canonical Form
	ClapTrap();
	explicit ClapTrap(std::string_view name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	// Member functions
	void attack(std::string_view target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// getter Member functions
	void	displayStatus() const;
};

#endif
