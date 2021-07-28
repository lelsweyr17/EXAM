#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
class ATarget;

class ASpell {
    public:
        ASpell(std::string name, std::string effects);
        virtual ~ASpell();
        ASpell(const ASpell &copy);
        ASpell &operator=(const ASpell &aSpell);

        std::string const &getName() const;
        std::string const &getEffects() const;

        virtual ASpell *clone() const = 0;
        void launchSpell(ATarget const &target) const;

    protected:
        std::string _name;
        std::string _effects;
};

#endif