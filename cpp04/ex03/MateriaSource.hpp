#pragma once 

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria* _materias[4];
    public:
        MateriaSource();
        ~MateriaSource();

        MateriaSource( MateriaSource const& other );
        MateriaSource& operator=( MateriaSource const& other );

        void learnMateria( AMateria* m ); // store the pointer
        AMateria* createMateria( std::string const & type ); // clone matching type
};