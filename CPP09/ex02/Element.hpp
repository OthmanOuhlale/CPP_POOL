#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Element
{
    public:
        int value;
        int pair_id;
        
        bool operator<(const Element& other) const;
};


#endif