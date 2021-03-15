#include <cstring>

template <int SIZE=128>
class MyString{
    explicit MyString(const char* input){
        size_t stringSize = strlen(input);
        size = stringSize +1;
        char buff[size];
        if( stringSize > SIZE){
            data.buffer = new char[stringSize+1];
            data.buffer[stringSize] = '\0';
            strncpy(data.buffer,input,stringSize);
        }else{
            strncpy(buff,input,stringSize);
            buff[stringSize] = '\0';
            data.buffer = &buff;
        } 
    }
    
    
    size_t getSize() {return size;}
     
  private:
    union data{
        char* buffer;
    }  
    size_t size;
};