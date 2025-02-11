/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:00:23 by christian         #+#    #+#             */
/*   Updated: 2025/02/11 08:33:41 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main() {
	std::cout << "\n=== Testing ScavTrap Constructors ===" << std::endl;
	std::string name1 = "ST-1";
	std::string name2 = "Enemy-ST";
	ScavTrap scav(name1);
	ScavTrap enemy(name2);
	ScavTrap default_scav;
	ScavTrap copy_scav(scav);
	
	// Test initial status
	std::cout << "\n=== Initial Status ===" << std::endl;
	scav.displayStatus();
	enemy.displayStatus();
	default_scav.displayStatus();
	copy_scav.displayStatus();
	
	// Test copy assignment
	std::cout << "\n=== Testing Copy Assignment ===" << std::endl;
	copy_scav = default_scav;
	copy_scav.displayStatus();

	std::cout << "\n=== Testing Attack and Damage ===" << std::endl;
	scav.attack("Enemy-ST");
	enemy.takeDamage(20);
	enemy.displayStatus();
	
	std::cout << "\n=== Testing Repair ===" << std::endl;
	enemy.beRepaired(10);
	enemy.displayStatus();
	
	std::cout << "\n=== Testing Guard Gate Mode ===" << std::endl;
	scav.guardGate();
	
	std::cout << "\n=== Testing Energy Points Depletion ===" << std::endl;
	for (int i = 0; i < 49; ++i) {
		scav.attack("Enemy-ST");
	}
	scav.displayStatus();
	scav.attack("Enemy-ST");  // Should fail due to no energy
	scav.beRepaired(5);      // Should fail due to no energy
	
	std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
	enemy.takeDamage(200);    // More than max HP
	enemy.displayStatus();     // Should show 0 HP
	enemy.attack("ST-1");     // Should fail due to no hit points
	enemy.beRepaired(50);     // Should fail due to no hit points
	enemy.guardGate();        // Should still work even with 0 HP
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	
	return 0;
}
