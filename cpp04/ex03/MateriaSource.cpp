#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for(int i = 0; i < 4; i++)
        _materias[i] = NULL;
    std::cout << "MateriaSource default constructor called!" << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const& other ) {
    for(int i = 0; i < 4; i++) {
        if(other._materias[i])
            _materias[i]  = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=( MateriaSource const& other ) {
    if(this != &other) {
        for(int i = 0; i < 4; i++) {
            delete _materias[i];
            if(other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for(int i = 0; i < 4; i++)
        delete _materias[i];
    std::cout << "MateriaSource destructor called!" << std::endl;
}

void MateriaSource::learnMateria( AMateria* m ) {
    if(!m)
        return;
    for(int i = 0; i < 4; i++) {
        if(_materias[i] == NULL) {
            _materias[i] = m;
            return;
        }
    }

}
AMateria* MateriaSource::createMateria( std::string const & type ) {
    for(int i = 0; i < 4; i++) {
        if(_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}