#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

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

    ICharacter* bob = new Character("bob"); me->use(0, *bob);

    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "===== MORE TESTs =====" << std::endl;
    std::cout << "===== MATERIA SOURCE TEST =====" << std::endl;
    
    // Create a MateriaSource and teach it some Materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n===== CHARACTER CREATION =====" << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    std::cout << "\n===== EQUIP MATERIAS =====" << std::endl;
    AMateria* tmp;

    tmp = src->createMateria("ice"); // clone Ice
    me->equip(tmp);

    tmp = src->createMateria("cure"); // clone Cure
    me->equip(tmp);

    std::cout << "\n===== USE MATERIAS =====" << std::endl;
    me->use(0, *bob); // Ice effect
    me->use(1, *bob); // Cure effect

    std::cout << "\n===== UNEQUIP TEST =====" << std::endl;
    // Save pointer before unequip to avoid memory leak
    AMateria* dropped = tmp;
    me->unequip(0); // removes Ice from inventory
    delete dropped; // safely delete unequipped Materia

    std::cout << "\n===== COPY CONSTRUCTOR TEST =====" << std::endl;
    Character* cloneMe = new Character(*(dynamic_cast<Character*>(me)));
    cloneMe->use(1, *bob); // ensure deep copy works

    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
    Character assignTest("temp");
    assignTest = *(dynamic_cast<Character*>(me));
    assignTest.use(1, *bob);

    std::cout << "\n===== CLEANUP =====" << std::endl;
    delete bob;
    delete me;
    delete cloneMe;
    delete src;


    return 0;
}
