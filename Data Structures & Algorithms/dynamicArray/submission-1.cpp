class DynamicArray {
private:
    int * arr ;
    int capacity;
    int size;
public:


    DynamicArray(int capacity) : size(0) , capacity(capacity) {
        arr = new int [capacity];
        

    }

    int get(int i) {
        return arr[i];

    }

    void set(int i, int n) {
        arr[i] = n;

    }

    void pushback(int n) {
        if(capacity == size)
        {
            resize();
        }
        arr[size] = n;
        size++;

    }

    int popback() {
        if(size > 0)
        {
            size--;
        }
        return arr[size];

    }

    void resize() {
        capacity *= 2;
        int *newArr = new int [capacity];
        for(int i =0 ; i<size ; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;

    }

    int getSize() {
        return size;

    }

    int getCapacity() {
        return capacity;

    }
};
