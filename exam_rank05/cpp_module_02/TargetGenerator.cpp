#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
}

TargetGenerator::~TargetGenerator() {
    std::vector<ATarget *>::iterator it_begin = _targets.begin();
    std::vector<ATarget *>::iterator it_end = _targets.end();

    while (it_begin != it_end)
    {
        delete *it_begin;
        ++it_begin;
    }
    _targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target) {
    for (unsigned i = 0; i < _targets.size(); i++) {
        if (_targets[i] == target) {
            return;
        }
    }
    _targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(std::string const &targetType) {
    for (unsigned i = 0; i < _targets.size(); i++) {
        if (_targets[i]->getType() == targetType) {
            _targets.erase(_targets.begin() + i);
            break;
        }
    }
}

ATarget *TargetGenerator::createTarget(std::string const &targetType) {
    for (int i = 0; i < _targets.size(); i++) {
        if (_targets[i]->getType() == targetType) {
            return (_targets[i]);
        }
    }
    return (NULL);
}
