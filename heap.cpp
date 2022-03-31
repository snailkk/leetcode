#include<bits/stdc++.h>
using namespace std;
vector<int> heap(1,-1);
//获得最大值
int top(){
    return heap[1];
}

//上浮
void swim(int pos){//父亲如何唯一确定
    while(pos > 1 && heap[pos] > heap[pos / 2]){
        swap(heap[pos],heap[pos/2]);
        pos /= 2;
    }
}

void sink(int pos){
    while(2*pos < heap.size()){
        int i = 2*pos;
        if(i + 1 < heap.size() && heap[i] < heap[i + 1]) i++;//保证儿子不越界
        if(heap[pos] >= heap[i]) break;
        swap(heap[pos],heap[i]);
        pos = i;
    }
}

//插入任意值：把新的数字放在最后一位，然后上浮
void push(int k){
    heap.push_back(k);
    swim(heap.size() - 1);
}

//删除最大值：把最后一个数字挪到开头，然后下沉
void pop(){
    heap[1] = heap.back();
    heap.pop_back();
    sink(1);
}

int main(){
    int a = 0;
    while(a != -1){
        cin >> a;
        if(a == -1) break;
        push(a);
    }

    while(heap.size() > 1){
        cout << top() << ' ';
        pop();
    }
}
