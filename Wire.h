#ifndef _WIRE_H_
#define _WIRE_H_

class Wire {
public:
    Wire();
    bool getSignal() const;  // Get the current signal on the wire
    void setSignal(bool signal);  // Set the signal on the wire

private:
    bool currentSignal;  // Represents the current signal on the wire (0 or 1)
};

#endif // _WIRE_H_
