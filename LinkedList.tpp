template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);
    if (head == nullptr) {
        head = n;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = n;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    clear();
    if (!copyObj.isEmpty()) {
        head = new Node(copyObj.head->value);
        Node* current = head;
        Node* current2 = copyObj.head->next;
        while(current2 != nullptr) {
            Node* newNode = new Node(current2->value);
            current->next = newNode;
            current = current->next;
            current2 = current2->next;
        }
    }
    this->length = copyObj.getLength();

}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length+1) {
        throw string("insert: error, position out of bounds");
    }
    Node* newNode = new Node(elem);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < position-1; i++) {
            current = current->next;
        }
        Node* after = current->next;
        current->next = newNode;
        newNode->next = after;
    }
    this->length++;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }
    if (position == 0) {
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
    } else {
        Node* current = head;
        for (int i = 0; i < position-1; i++) {
            current = current->next;
        }
        Node* toDelete = current->next;
        if (toDelete->next != nullptr) {
            current->next = current->next->next;
        } else {
            current->next = nullptr;
        }
        delete toDelete;
    }
    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}


template <typename T>
T* LinkedList<T>::retrieveElement(function<bool(T)> f) {
    cout << "RETRIEVE ELEMENT" << endl;
    Node* curr = head;
    cout << curr->value << endl;

    while(curr != nullptr && !f(curr->value)) {
        cout << curr->value << endl;

        curr = curr->next;
        
    }  

    cout << "Hey";
    // simplePrint(cout);
    

    if (curr == nullptr) {
        return nullptr;
    } else {
        return &(curr->value);
    }
};

template <typename T>
T* LinkedList<T>::removeElement(function<bool(T)> f) {
    if (getLength() == 0) {
        return nullptr;
    }
    if (f(head->value)) {
        cout << "here" << endl;
        T* result = &(head->value);
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        oldHead = nullptr;
        this->length -= 1;
        return result;
    }

    Node* prev = head;
    Node* curr = head->next;
    while(curr != nullptr && !f(curr->value)) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        return nullptr;
    } else { 
        T* result = &(curr->value);
        prev->next = curr->next;
        delete curr;
        curr = nullptr;
        this->length -= 1;
        return result;
    }

}


template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}

template <typename T>
void LinkedList<T>::simplePrint(ostream& outStream) {
    Node* curr = head;
    while(curr != nullptr) {
        outStream << (curr->value) << endl;
        curr = curr->next;
    }
}