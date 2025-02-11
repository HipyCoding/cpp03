/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:00:23 by christian         #+#    #+#             */
/*   Updated: 2025/02/11 14:48:04 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "\n=== Testing Constructors ===" << std::endl;
	std::string name1 = "ST-1";
	std::string name2 = "ST-2";
	std::string enemyName = "Enemy-ST";
	
	ScavTrap	scav(name1);
	ScavTrap	enemy(name2);
	ScavTrap	default_scav;
	ScavTrap	copy_scav(scav);

	std::cout << "\n=== Testing Copy Assignment ===" << std::endl;
	copy_scav = default_scav;

	std::cout << "\n=== Testing Basic Functions ===" << std::endl;
	scav.attack(enemyName);
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n=== Testing High Damage ===" << std::endl;
	enemy.takeDamage(200);  // Should deplete all HP
	enemy.attack(name1);    // Should fail - no HP
	enemy.beRepaired(50);   // Should fail - no HP
	enemy.guardGate();      // Should still work with no HP

	// std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
	// // ScavTrap has 50 energy points, let's use them all
	// for (int i = 0; i < 25; ++i) {
	// 	scav.attack(enemyName);
	// 	scav.beRepaired(1);
	// }
	// // These should fail due to no energy
	// scav.attack(name2);
	// scav.beRepaired(10);
	// // But guard gate should still work!
	// scav.guardGate();

	std::cout << "\n=== End of Tests ===" << std::endl;

	return 0;
}
