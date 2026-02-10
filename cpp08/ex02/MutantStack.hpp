#pragma once

class MutantStack {
    private:

    public:
        MutantStack();
        MutantStack( const MutantStack& other );
        MutantStack& operator=( const MutantStack& other );
        ~MutantStack();
};