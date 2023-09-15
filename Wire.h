#ifndef _WIRE_H_
#define _WIRE_H_

#include <string>

class Wire {
public:
    explicit Wire(const std::string& wire_name);
    bool Value() const;
    void Assign(bool val);
    std::string Name() const;

private:
    std::string name;
    bool value = false;
};

#endif // _WIRE_H_
