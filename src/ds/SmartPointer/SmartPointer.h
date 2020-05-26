#include <iostream>
namespace ds{
    template <typename T>
    struct SmartPointer{
        explicit SmartPointer(T* ptr): obj_(ptr){
            refCount = new uint32_t(1);
        }

        SmartPointer(SmartPointer& ref){
           refCount = ref.refCount;
           (*refCount)++;
           obj_ = const_cast<T*>(ref.get());
        }

        ~SmartPointer(){
           (*refCount)--;
           if(*refCount == 0) (*obj_).~T();
        }

        SmartPointer& operator=(SmartPointer& ref){
            if(&ref == this) return *this; 
            refCount = ref.refCount;
            (*refCount)++;
            obj_ = const_cast<T*>(ref.get());
            return *this;
        }
        
        const T* get(){return obj_;} 
        uint32_t refcount() {return *refCount;} 
        private:
        uint32_t* refCount;
        T*  obj_;
    };
}
