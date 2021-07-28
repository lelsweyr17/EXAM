#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include "ATarget.hpp"
# include <vector>

class TargetGenerator {
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(std::string const &targetName);
        ATarget *createTarget(std::string const &targetName);

    private:
        TargetGenerator(ATarget const &copy);
        TargetGenerator &operator=(ATarget const &target);
        std::vector<ATarget *> _targets;
};

#endif