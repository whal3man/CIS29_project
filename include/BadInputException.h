#ifndef BADINPUTEXCEPTION_H
#define BADINPUTEXCEPTION_H

#include <stdexcept>
using namespace std;

class BadInputException : public invalid_argument
{
public:
    BadInputException(string msg) : invalid_argument(msg.c_str()) {}

protected:

private:
};

#endif // BADINPUTEXCEPTION_H
