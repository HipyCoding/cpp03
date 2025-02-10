/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:00:17 by christian         #+#    #+#             */
/*   Updated: 2025/02/08 19:54:52 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap() : 
	_name("unnamed"), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0) 
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string_view name) : 
	_name(name), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0) 
{
	std::cout << "ClapTrap parameterized constructor called for " << _name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : 
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(std::string_view target) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't attack - no energy or hit points left!" << std::endl;
		return;
	}
	
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= amount) {
		_hitPoints = 0;
	} else {
		_hitPoints -= amount;
	}
	
	std::cout << "ClapTrap " << _name << " takes " << amount 
		<< " points of damage! Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't repair - no energy or hit points left!" << std::endl;
		return;
	}
	
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
		<< " points! Current HP: " << _hitPoints << std::endl;
}
