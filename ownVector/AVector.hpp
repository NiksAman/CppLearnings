#include <iostream>
#include <string>

template <typename T>
class aVector
{
    T* ptr;
    int maxSize = 256;
    int currentSize = 0;
    public:
        aVector()
        {
            ptr = new T[maxSize];
        }

        aVector(const T &value)
        {
            ptr = new T[maxSize];
            ptr[0] = value;
        }

        aVector(const aVector& obj)
        {
            ptr = new T[maxSize];
            this->currentSize = obj.currentSize;
            for(int i = 0; i < currentSize; i++)
            {
                ptr[i] = obj.ptr[i];
            }
        }

        ~aVector()
        {
            if(ptr)
                delete ptr;
        }

        void push_back(const T &value)
        {
            if(currentSize < maxSize)
            {
                ptr[currentSize] = value;
            }
            else
            {
                std::cout << "Vector is full!" << std::endl;
                ptr = new T[maxSize * 2];
                maxSize *= 2;
                ptr[currentSize] = value;
            }
            currentSize++;
        }

        void pop()
        {
            if(currentSize > 0)
            {
                ptr[currentSize] = 0;
                std::cout << "Removing element: " << ptr[currentSize - 1] << std::endl;
                currentSize--;
            }
            else
            {
                std::cout << "Vector is empty!" << std::endl;
            }
        }

        int size()
        {
            return currentSize;
        }

        int capacity()
        {
            return maxSize;
        }

        void eraseByIndex(int index)
        {
            if(index < 0 || index >= currentSize)
            {
                std::cout << "Index out of bounds!" << std::endl;
                return;
            }
            for(int i = index; i < currentSize - 1; i++)
            {
                ptr[i] = ptr[i + 1];
            }
            currentSize--;
        }

        void clear()
        {
            for(int i = 0; i < currentSize; i++)
            {
                ptr[i] = 0;
            }
            currentSize = 0;
        }

        void erase(const T &value)
        {
            for(int i = 0; i < currentSize; i++)
            {
                if(ptr[i] == value)
                {
                    eraseByIndex(i);
                    return;
                }
            }
            std::cout << "Value not found!" << std::endl;
        }

};