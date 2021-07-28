#include "SpellBook.hpp"

SpellBook::SpellBook() {
}

SpellBook::~SpellBook() {
    std::vector<ASpell *>::iterator it_begin = _spells.begin();
    std::vector<ASpell *>::iterator it_end = _spells.end();

    while (it_begin != it_end) {
        delete *it_begin;
        ++it_begin;
    }
    _spells.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
    for (unsigned i = 0; i < _spells.size(); i++) {
        if (_spells[i] == spell) {
            return ;
        }
    }
    _spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &spellName) {
    for (unsigned i = 0; i < _spells.size(); i++) {
        if (_spells[i]->getName() == spellName) {
            _spells.erase(_spells.begin() + i);
            break;
        }
    }
}

ASpell *SpellBook::createSpell(std::string const &spellName) {
    for (int i = 0; i < _spells.size(); i++) {
        if (_spells[i]->getName() == spellName) {
            return (_spells[i]);
        }
    }
    return (NULL);
}