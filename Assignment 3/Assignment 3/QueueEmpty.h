#include <exception>
#include <string>

using namespace std;

class QueueEmpty : public exception {

std::string error_message;  

public:

explicit 
QueueEmpty(const std::string& msg = "The given queue is empty ! "): error_message(msg) {}

virtual const char* what() const throw () {
       return error_message.c_str();
    }

virtual ~QueueEmpty() throw () {}
};


// Sample of how to throw, catch and print the message
/* try {
    throw(QueueEmpty("empty"));
} catch (const QueueEmpty& e) {
    std::cout<<e.what();
} */
