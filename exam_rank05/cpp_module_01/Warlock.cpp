#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock &copy) {
    operator=(copy);
}

Warlock &Warlock::operator=(const Warlock &warlock) {
    if (this != &warlock) {
        this->_name = warlock._name;
        this->_title = warlock._title;
    }
    return *this;
}

void Warlock::introduce() const {
    std::cout << "I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::setTitle(std::string const &title) {
    _title = title;
}
std::string const &Warlock::getName() const {
    return _name;
}
std::string const &Warlock::Warlock::getTitle() const {
    return _title;
}

void Warlock::learnSpell(ASpell *spell) {
    for (unsigned i = 0; i < _spells.size(); i++) {
        if (_spells[i] == spell) {
            return ;
        }
    }
    _spells.push_back(spell);
}

void Warlock::forgetSpell(std::string spellName) {
    for (unsigned i = 0; i < _spells.size(); i++) {
        if (_spells[i]->getName() == spellName) {
            _spells.erase(_spells.begin() + i);
            break;
        }
    }
}

void Warlock::launchSpell(std::string spellName, ATarget &target) const {
    for (unsigned i = 0; i < _spells.size(); i++) {
        if (_spells[i]->getName() == spellName) {
            target.getHitBySpell(*_spells[i]);
            break;
        }
    }
}