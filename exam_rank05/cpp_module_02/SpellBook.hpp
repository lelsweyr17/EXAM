#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <vector>
# include "ASpell.hpp"

class SpellBook {
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &spellName);
        ASpell *createSpell(std::string const &spellName);

    private:
        SpellBook(SpellBook const &copy);
        SpellBook &operator=(SpellBook const &spellBook);
        std::vector<ASpell *> _spells;
};

#endif