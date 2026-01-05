#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {

    std::cout << "===== SUBJECT TESTs =====" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n===== MORE TESTs =====" << std::endl;
    std::cout << "===== MATERIA SOURCE TEST =====" << std::endl;
    
    // Create a new MateriaSource and teach it some Materias
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());

    std::cout << "\n===== CHARACTER CREATION =====" << std::endl;
    ICharacter* me2 = new Character("me");
    ICharacter* bob2 = new Character("bob");

    std::cout << "\n===== EQUIP MATERIAS =====" << std::endl;
    AMateria* ice = src2->createMateria("ice");
    me2->equip(ice);

    AMateria* cure = src2->createMateria("cure");
    me2->equip(cure);

    std::cout << "\n===== USE MATERIAS =====" << std::endl;
    me2->use(0, *bob2);
    me2->use(1, *bob2);

    std::cout << "\n===== UNEQUIP TEST =====" << std::endl;
    // Unequip Ice safely
    me2->unequip(0); // remove Ice from inventory
    delete ice;      // safe: only delete pointer no longer in inventory

    std::cout << "\n===== COPY CONSTRUCTOR TEST =====" << std::endl;
    Character* cloneMe = new Character(*(dynamic_cast<Character*>(me2)));
    cloneMe->use(1, *bob2); // ensure deep copy works


    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
    Character assignTest("temp");
    assignTest = *(dynamic_cast<Character*>(me2));
    assignTest.use(1, *bob2);

    std::cout << "\n===== CLEANUP =====" << std::endl;
    delete bob2;
    delete me2;
    delete cloneMe;
    delete src2;

    return 0;
}