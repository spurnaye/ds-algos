#include <cstring>

template <int SIZE=128>
class MyString{
public:
    explicit MyString(const char* input){
        size_t stringSize = strlen(input);
        size = stringSize +1;
        char buff[size];
        if( stringSize > SIZE){
            buffer = new char[stringSize+1];
            buffer[stringSize] = '\0';
            strncpy(buffer,input,stringSize);
        }else{
            strncpy(buff,input,stringSize);
            buff[stringSize] = '\0';
            buffer = buff;
        } 
    }
    
    size_t getSize() {return size;}
     
  private:
    union {
        char* buffer;
    };
    size_t size;
};