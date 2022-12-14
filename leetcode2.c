typedef struct  {
    int arr[10];
    int front;
    int rear;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *m=(MyQueue *)malloc(sizeof(MyQueue));
    m->front=-1;
    m->rear=-1;
    return m;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->rear==9){
        return;
    }else if(obj->rear==-1||obj->front > obj->rear) {
        obj->front=0;
        obj->rear=0;
        obj->arr[obj->rear]=x;
    }else{
        obj->arr[++obj->rear]=x;
    }
}

int myQueuePop(MyQueue* obj) {
    if(obj->rear==-1||obj->front > obj->rear){
        return NULL;
    }else
  return obj->arr[obj->front++];
}

int myQueuePeek(MyQueue* obj) {
  return obj->arr[obj->front];
}

bool myQueueEmpty(MyQueue* obj) {
  if(obj->rear==-1||obj->front > obj->rear){
      return true;
  }
  else
   return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
