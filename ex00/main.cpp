/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:00:23 by christian         #+#    #+#             */
/*   Updated: 2025/02/11 07:06:46 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


int	main() {

	std::cout << "\n=== Testing Constructors ===" << std::endl;
	ClapTrap	clap("CT-1");
	ClapTrap	enemy("Enemy-1");
	ClapTrap	enemyb("Enemy-2");
	ClapTrap	default_clap;
	ClapTrap	copy_trap(clap);
	clap.displayStatus();
	enemy.displayStatus();
	default_clap.displayStatus();
	copy_trap.displayStatus();
	copy_trap = default_clap;
	copy_trap.displayStatus();

	std::cout << "\n=== Testing Attack and Damage ===" << std::endl;
	clap.attack("Enemy-1");
	enemy.takeDamage(0);
	enemy.displayStatus();
	
	std::cout << "\n=== Testing Repair ===" << std::endl;
	enemy.beRepaired(5);
	enemy.displayStatus();

	std::cout << "\n=== Testing Energy Points Depletion ===" << std::endl;
	for (int i = 0; i < 9; ++i) {
		clap.attack("Enemy-1");
	}
	// Should fail due to no energy points
	clap.displayStatus();
	clap.attack("Enemy-2");
	clap.beRepaired(1);

	std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
	enemyb.takeDamage(20);  // More than max HP
	enemyb.displayStatus();
	enemyb.attack("CT-1");  // Should fail due to no hit points
	enemyb.beRepaired(5);  // should fail too
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	
	return 0;
}
