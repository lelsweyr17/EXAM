#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ATarget {
    public:
        ATarget(std::string type);
        virtual ~ATarget();
        ATarget(const ATarget &copy);
        ATarget &operator=(const ATarget &target);

        std::string const &getType() const;
        void getHitBySpell(ASpell const &spell) const;
        virtual ATarget *clone() const = 0;

    protected:
        std::string _type;
};

#endif