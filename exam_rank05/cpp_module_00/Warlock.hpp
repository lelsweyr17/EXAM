#ifndef WARLOCK_HPP
# define WARLOCK_HPP


# include <iostream>

class Warlock {
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        void    introduce() const;
        void    setTitle(std::string const &title);
        std::string const   &getName() const;
        std::string const   &getTitle() const;

    private:
        Warlock(const Warlock &copy);
        Warlock &operator=(const Warlock &warlock);
        std::string _name;
        std::string _title;
};

#endif
