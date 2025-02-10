/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:00:23 by christian         #+#    #+#             */
/*   Updated: 2025/02/08 19:55:38 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
	// Test constructors
	std::cout << "\n=== Testing Constructors ===" << std::endl;
	ClapTrap default_trap;
	ClapTrap named_trap("CT-1");
	ClapTrap copy_trap(named_trap);

	// Test attack and damage
	std::cout << "\n=== Testing Attack and Damage ===" << std::endl;
	named_trap.attack("Enemy-1");
	named_trap.takeDamage(5);
	
	// Test repair
	std::cout << "\n=== Testing Repair ===" << std::endl;
	named_trap.beRepaired(3);
	
	// Test energy points depletion
	std::cout << "\n=== Testing Energy Points Depletion ===" << std::endl;
	for (int i = 0; i < 9; ++i) {
		named_trap.attack("Enemy-2");
	}
	// Should fail due to no energy points
	named_trap.attack("Enemy-3");
	named_trap.beRepaired(1);
	
	// Test fatal damage
	std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
	named_trap.takeDamage(20);  // More than max HP
	named_trap.attack("Enemy-4");  // Should fail due to no hit points
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
}
