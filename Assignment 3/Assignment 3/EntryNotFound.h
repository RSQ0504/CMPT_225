#include <exception>
#include <string>

using namespace std;

class EntryNotFound : public exception {

std::string error_message;  

public:

explicit 
EntryNotFound(const std::string& msg = "The given entry is not found ! "): error_message(msg) {}

virtual const char* what() const throw () {
       return error_message.c_str();
    }

virtual ~EntryNotFound() throw () {}
};

// Sample of how to throw, catch and print the message
/* try {
    throw(EntryNotFound("empty"));
} catch (const EntryNotFound& e) {
    std::cout<<e.what();
} */