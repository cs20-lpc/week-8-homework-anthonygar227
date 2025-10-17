template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    // delete all nodes and reset the stack
    if (this->length == 0) {
        top = nullptr;
        return;
    }

    Node<T>* curr = top;
    while (curr != nullptr) {
        Node<T>* next = curr->next;
        delete curr;
        curr = next;
    }
    top = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    // create a copy of another stack
    top = nullptr;
    this->length = 0;

    if (copyObj.top == nullptr) return;

    Node<T>* current = copyObj.top;

    // copy first node
    Node<T>* newHead = new Node<T>(current->data);
    Node<T>* tail = newHead;
    this->length++;
    current = current->next;

    // copy the rest of the nodes
    while (current != nullptr) {
        tail->next = new Node<T>(current->data);
        tail = tail->next;
        this->length++;
        current = current->next;
    }
    top = newHead;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    // return top value without removing it
    if (isEmpty()) {
        throw string("peek: error, stack is empty, avoiding underflow");
    }
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    // remove top element from the stack
    if (isEmpty()) {
        throw string("pop: error, stack is empty, avoiding underflow");
    }
    Node<T>* oldTop = top;
    top = top->next;
    delete oldTop;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    // add new element to the top
    Node<T>* n = new Node<T>(elem); 

    if (isEmpty()) {
        n->next = nullptr;
    } else {
        n->next = top;
    }

    top = n;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    // move top to bottom or bottom to top
    if (this->length <= 1) return; // 

    if (dir == Stack<T>::RIGHT) {
        // top -> bottom
        Node<T>* oldTop = top;
        top = top->next;           
        oldTop->next = nullptr;    

        Node<T>* curr = top;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = oldTop;

    } else { 
        // bottom -> top
        Node<T>* prev = nullptr;
        Node<T>* curr = top;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        curr->next = top;
        top = curr;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
