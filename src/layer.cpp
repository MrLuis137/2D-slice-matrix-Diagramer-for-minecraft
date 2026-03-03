//Includes if needed
#include <vector>
#include <stdexcept>


using namespace std;
class Layer{
private:

    vector<int> blocks;
    int rows;
    int columns;

    int getPosition(int r, int c){
        if(c> columns or r > rows){
            throw runtime_error("Unexpected dimentions");
        }
        return r * (rows - 1) + c;
    }

public:

    Layer(int rows, int colums){
        this->rows = rows;
        this->columns = columns;
        blocks.resize(rows * columns);
    }

    int get(int r, int c){
        
        return blocks.at(getPosition(r,c));
    }

    void set(int r, int c, int value){
        blocks.assign(getPosition(r,c),value);
    }

    void addColumnRight(){
        vector<int> newBlocks;
        newBlocks.reserve(rows*columns);
        for(int i = 0; i < (rows*(columns)); i++){
            newBlocks.push_back(blocks.at(i));    
            if((i+1) % columns){
                newBlocks.push_back(0);
            }
            
        }
        columns++;
    }

    void addColumnLeft(){
        vector<int> newBlocks;
        newBlocks.reserve(rows*columns+1);
        for(int i = 0; i < (rows*(columns)); i++){
            if((i) % columns){
                newBlocks.push_back(0);
            }
            newBlocks.push_back(blocks.at(i));    
            
        }
        columns++;
    }

    void addRowTop(){
        rows++;
        vector<int> newBlocks;
        newBlocks.reserve(rows*columns);
        for(int i = 0; i< (rows*columns+1); i++){
            if(i < columns){
                newBlocks.push_back(0);
                continue;
            } 
            newBlocks.push_back(blocks.at(i));
        }  
    }

    void addRowBottom(){
        rows++;
        vector<int> newBlocks;
        newBlocks.reserve(rows*columns);
        for(int i = 0; i< (rows*columns+1); i++){
            newBlocks.push_back(blocks.at(i));
            if(i >= (rows*columns)-columns){
                newBlocks.push_back(0);
                continue;
            }
        }  
    }

};
