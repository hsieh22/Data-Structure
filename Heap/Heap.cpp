#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

class minHeap {
    private:

        vector<int> heap;

        int getLeftChildIndex(int parentIndex) {    return parentIndex * 2 + 1; }
        int getRightChildIndex(int parentIndex){    return parentIndex *2 + 2;  }
        int getParentIndex(int childIndex){     return (childIndex - 1) / 2;    } 


        bool hasLeftChild(int index){   return (getLeftChildIndex(index) < heap.size());    }
        bool hasRightChild(int index){  return (getRightChildIndex(index) < heap.size());   }
        bool hasParent(int index){  return (getParentIndex(index) >= 0);    }

        int leftChild(int index){   return heap[getLeftChildIndex(index)];  }
        int rightChild(int index){  return heap[getRightChildIndex(index)]; }
        int parent(int index){  return heap[getParentIndex(index)]; }

        void swap(int indexOne, int indexTwo){
            int temp = heap[indexOne];
            heap[indexOne] = heap[indexTwo];
            heap[indexTwo] = temp;
        }

    public:
        minHeap(){}

        int size(){ return heap.size(); }

        void printHeap(){
            cout << endl;
            int layer = 1;
            for(int i = 0; i < heap.size(); ++i){
                cout << heap[i] << "    ";
                if(i + 1 == pow(2,layer) - 1){
                    cout << endl;
                    layer++;
                }
            }
            return;
        }

        int pop(){
            if(heap.size() == 0) {
                cout << "The heap is empty !";
                return 0;
            }
            int item = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown();
            return item;
        }

        void push(int item){
            heap.push_back(item);
            heapifyUp();
            return;
        }

        void heapifyUp(){
            int index = heap.size() - 1;
            while(hasParent(index) && heap[index] < parent(index)){
                swap(index, getParentIndex(index));
                index = getParentIndex(index);
            }
            return;
        }

        void heapifyDown(){
            int index = 0;
            while(hasLeftChild(index)){
                int smallerIndex = getLeftChildIndex(index);
                if(hasRightChild(index) && rightChild(index) < leftChild(index)){
                    smallerIndex = getRightChildIndex(index);
                }

                if(heap[index] > heap[smallerIndex]){
                    swap(index, smallerIndex);
                    index = smallerIndex;
                }
                else{
                    break;
                }
            }
            return;
        }

        
};

int main(){
    
    minHeap hp;
    //cout << hp.size() << endl;
    hp.push(10);
    hp.push(2);
    hp.push(7);
    hp.push(15);
    hp.push(5);
    hp.push(3);
    hp.push(24);
    hp.push(4);
    hp.printHeap();

    hp.pop();
    hp.pop();
    hp.printHeap();

    return 0;
}