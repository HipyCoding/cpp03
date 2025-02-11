/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:00:23 by christian         #+#    #+#             */
/*   Updated: 2025/02/11 15:02:08 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "\n=== Testing Constructors ===" << std::endl;
	std::string name1 = "FT-1";
	std::string name2 = "FT-2";
	std::string name3 = "Enemy-1";
	
	FragTrap	frag1(name1);
	FragTrap	frag2(name2);
	FragTrap	enemy1(name3);
	FragTrap	default_frag;
	FragTrap	copy_frag(frag1);

	std::cout << "\n=== Testing Copy Assignment ===" << std::endl;
	copy_frag = default_frag;
	
	std::cout << "\n=== Testing Basic Functions ===" << std::endl;
	frag1.attack(name3);
	enemy1.takeDamage(30);
	enemy1.displayStatus();
	frag1.displayStatus();
	frag1.beRepaired(20);
	frag1.displayStatus();
	frag1.highFivesGuys();
	
	std::cout << "\n=== Testing High Damage ===" << std::endl;
	frag2.takeDamage(200);  // Should deplete all HP
	frag2.displayStatus();
	frag2.attack(name3); // Should fail - no HP
	frag2.beRepaired(50);   // Should fail - no HP
	frag2.highFivesGuys();  // Should show no HP message
	
	// std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
	// // FragTrap has 100 energy points, let's use them all
	// for (int i = 0; i < 50; ++i) {
	// 	frag1.attack("Dummy Target");
	// 	frag1.beRepaired(1);
	// }
	// // These should fail due to no energy
	// frag1.attack("Enemy-3");
	// frag1.beRepaired(10);
	// But high five should still work!
	// frag1.highFivesGuys();
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	
	return 0;
}

