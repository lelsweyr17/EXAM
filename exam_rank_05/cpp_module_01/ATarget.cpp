#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type) {
}

ATarget::~ATarget() {
}

ATarget::ATarget(const ATarget &copy) {
    operator=(copy);
}

ATarget &ATarget::operator=(const ATarget &target) {
    if (this != &target)
    {
        this->_type = target._type;
    }
    return *this;
}

std::string const &ATarget::getType() const {
    return _type;
}

void ATarget::getHitBySpell(ASpell const &spell) const {
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}