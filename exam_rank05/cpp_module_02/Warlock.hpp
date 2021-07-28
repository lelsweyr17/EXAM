#ifndef WARLOCK_HPP
# define WARLOCK_HPP


# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"
# include <vector>

class Warlock {
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        Warlock(const Warlock &copy);
        Warlock &operator=(const Warlock &warlock);

        void    introduce() const;
        void    setTitle(std::string const &title);
        std::string const   &getName() const;
        std::string const   &getTitle() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, ATarget &target);

    private:
        std::string _name;
        std::string _title;
        SpellBook book;
};

#endif
