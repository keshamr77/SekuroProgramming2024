#include <iostream>

class Counter
{
protected:
unsigned int count; // count

public:
Counter() : count(0) {} // Constructor
Counter(int count) : count(count) {} // Constructor
unsigned int getCount() { // return count
return count;
}
Counter operator++() { // increment (prefix)
++count; // increment count
Counter temp; // make a temporary Counter
temp.count = count; // give it same values as this obj
return temp; // return the copy
}
};
class CountDn : public Counter // derived class
{
public:
Counter operator--() { // decrement count (prefix)
return Counter(--count);
}
};