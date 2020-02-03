#include"Rational.h"
class Set
{
    private:
        Rational q[50];
        int count;
    public:
        Set()
        {

            count=-1;
        }
        Set union1(Set a);
        Set intersection(Set b);
        void remove(Rational x);
        void insert(Rational y);
        void duplicate_removal(Set c);
        void display_set();
};
