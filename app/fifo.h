#ifndef _FIFO_H_
#define _FIFO_H_

template<int N>

class FIFO{
private:
    char data[N];
    int in; 
    int out;
    int size;
    int count;

public:
    FIFO(int size){
        this->size = size;
        this->in = 0;
        this->out = 0;
        this->count = 0;
    }

    bool put(char c){
        if(in == size){
            in = 0;
        }
        if(in == out){
            return false;
        }
        data[in] = c;
        in++;
        count++;
        return true;
    }

    char get(){
        if(out == size){
            out = 0;
        }
        if(in == out){
            return 0;
        }
        char c = data[out];
        out++;
        count--;
        return c;
    }

    int getCount(){
        return count;
    }
};

#endif