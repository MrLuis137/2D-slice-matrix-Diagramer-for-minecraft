#ifndef LAYER_H
#define LAYER_H
#include <vector>



class Layer{  
    private:
        std::vector<int> blocks;
        int getPosition(int r, int c);
    public:
        int rows;
        int columns;
        Layer(int rows, int columns);
        int get(int r, int c);
        void set(int r, int c, int value);
        void addColumnRight();
        void addColumnLeft();
        void addRowTop();
        void addRowBottom();
        
};


#endif // LAYER_H