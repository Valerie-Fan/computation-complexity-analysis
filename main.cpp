#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
#include <vector>

// Node structure for the singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node at the end of the linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to read CSV into a linked list
Node* readCSV(const std::string& filename) {
    Node* head = nullptr;
    std::ifstream file(filename);
    std::string line;

    // Skip the header line
    std::getline(file, line);

    // Read the integer values
    while (std::getline(file, line)) {
        if (!line.empty()) {
            insert(head, std::stoi(line));
        }
    }

    return head;
}

// Function to print the first N elements of the linked list
void printList(Node* head, size_t N) {
    Node* temp = head;
    for (size_t i = 0; i < N && temp; ++i) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Insertion Sort for linked list
void insertionSort(Node*& head) {
    if (!head) return;
    Node* sorted = nullptr;
    Node* current = head;

    while (current) {
        Node* next = current->next;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

// Quick Sort for linked list
Node* getTail(Node* cur) {
    while (cur && cur->next) {
        cur = cur->next;
    }
    return cur;
}

Node* partition(Node* head, Node* end, Node*& newHead, Node*& newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (!newHead) newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if (!newHead) newHead = pivot;
    newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node* newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;
        newHead = quickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node*& head) {
    head = quickSortRecur(head, getTail(head));
}

// Helper function to get the node at a specific index
Node* getNodeAt(Node* head, int index) {
    Node* temp = head;
    for (int i = 0; i < index && temp; ++i) {
        temp = temp->next;
    }
    return temp;
}

// Heap Sort for linked list
void heapify(Node*& head, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    Node* largestNode = getNodeAt(head, largest);
    Node* leftNode = getNodeAt(head, left);
    Node* rightNode = getNodeAt(head, right);

    if (left < n && leftNode && leftNode->data > largestNode->data) {
        largest = left;
        largestNode = leftNode;
    }

    if (right < n && rightNode && rightNode->data > largestNode->data) {
        largest = right;
        largestNode = rightNode;
    }

    if (largest != i) {
        Node* iNode = getNodeAt(head, i);
        std::swap(iNode->data, largestNode->data);
        heapify(head, n, largest);
    }
}

void heapSort(Node*& head) {
    if (!head) return;

    int n = 0;
    Node* temp = head;
    while (temp) {
        ++n;
        temp = temp->next;
    }

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(head, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        Node* last = getNodeAt(head, i);
        std::swap(head->data, last->data);
        heapify(head, i, 0);
    }
}

// Merge Sort for linked list
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
}

// Binary Search for linked list
bool binarySearch(Node* head, int value) {
    Node* left = head;
    Node* right = nullptr;
    Node* mid = head;
    int len = 0;
    while (mid) {
        ++len;
        mid = mid->next;
    }

    int l = 0, r = len - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        mid = head;
        for (int i = 0; i < m; ++i) {
            mid = mid->next;
        }
        if (mid->data == value) {
            return true;
        } else if (mid->data < value) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

// Function to measure execution time
template<typename Func>
double measureTime(Func func, Node*& head) {
    auto start = std::chrono::high_resolution_clock::now();
    func(head);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    return diff.count();
}

// Main function
int main() {
    std::vector<std::string> sizes = {"1", "2", "3", "4", "5"};
    
    for (const std::string& size : sizes) {
        for (int set = 1; set <= 3; set++) {
            std::string sortFilename = "random_set_group" + size + "_set" + std::to_string(set) + "_sorting.csv";
            std::string searchFilename = "random_set_group" + size + "_set" + std::to_string(set) + "_searching.csv";
            
            Node* sortData = readCSV(sortFilename);
            Node* searchData = readCSV(searchFilename);
            
            // Sorting and timing
            Node* data;
            
            data = sortData;
            double insertionSortTime = measureTime(insertionSort, data);
            std::cout << "Insertion Sort Time for " << sortFilename << ": " << insertionSortTime << "s\n";
            
            data = sortData;
            double quickSortTime = measureTime(quickSort, data);
            std::cout << "Quick Sort Time for " << sortFilename << ": " << quickSortTime << "s\n";
            
            data = sortData;
            double heapSortTime = measureTime(heapSort, data);
            std::cout << "Heap Sort Time for " << sortFilename << ": " << heapSortTime << "s\n";
            
            data = sortData;
            double mergeSortTime = measureTime([&](Node*& head) { head = mergeSort(head); }, data);
            std::cout << "Merge Sort Time for " << sortFilename << ": " << mergeSortTime << "s\n";
            
            // Output first 10 sorted elements
            std::cout << "First 10 elements of sorted " << sortFilename << ": ";
            printList(data, 10);
            
            // Binary search and timing
            int foundCount = 0, notFoundCount = 0;
            Node* sortedData = mergeSort(data);
            auto searchStart = std::chrono::high_resolution_clock::now();
            Node* temp = searchData;
            while (temp) {
                if (binarySearch(sortedData, temp->data))
                    foundCount++;
                else
                    notFoundCount++;
                temp = temp->next;
            }
            auto searchEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> searchTime = searchEnd - searchStart;
            
            std::cout << "Binary Search Time for " << searchFilename << ": " << searchTime.count() << "s\n";
            std::cout << "Found: " << foundCount << ", Not Found: " << notFoundCount << "\n";
        }
    }
    
    return 0;
}
