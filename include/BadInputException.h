#ifndef BADINPUTEXCEPTION_H
#define BADINPUTEXCEPTION_H

#include <stdexcept>


class BadInputException : public invalid_argument
{
    public:
        BadInputException(string input) : invalid_argument(("Error: " + input + " is an invalid input. Have you tried entering \"help\"?\n").c_str()) {}

    protected:

    private:
};

#endif // BADINPUTEXCEPTION_H
