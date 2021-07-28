#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {
}

ASpell::~ASpell() {
}

ASpell::ASpell(const ASpell &copy) {
    operator=(copy);
}

ASpell &ASpell::operator=(const ASpell &spell) {
    if (this != &spell)
    {
        this->_name = spell._name;
        this->_effects = spell._effects;
    }
    return *this;
}

std::string const &ASpell::getName() const {
    return _name;
}

std::string const &ASpell::getEffects() const {
    return _effects;
}

void ASpell::launchSpell(ATarget const &target) const {
    target.getHitBySpell(*this);
}