#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        std::string getIdea(int index) const;
        void setIdea(const std::string& idea, int index);
};

#endif