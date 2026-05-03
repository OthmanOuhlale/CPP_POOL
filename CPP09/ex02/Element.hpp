#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <vector>

class Element
{
    public:
        int value;
        std::vector<int> pair_ids;

        static int comparisons;

        void addItem(int idx);
        int getItem();
        
        bool operator<(const Element& other) const;
};


#endif
