#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
        
    if (p1.first < p2.first) return true;
    else return false;
}

int main()
{
    /* Vectors */

    vector<int> vec; // Initializing vector of size 0
    vector<int> vec1 = {1, 2, 3, 4}; // Initializing vector mentioned at RHS
    vector<int> vec2(3, 4); // Initializes vector as {4, 4, 4}
    vector<int> vec3(vec); // Initializing a vector with values taken from another vector

    vec.push_back(1); // Adds 1 to the back of the vector
    vec.push_back(2); // Adds 2 to the back of the vector
    vec.push_back(3); // Adds 3 to the back of the vector

    vec.pop_back(); // Removes last value of the vector

    vec.emplace_back(3); //In-place object creation before appending it (See more at "pairs").

    // How values are appended to a vector in C++?
    // [] -> [1] -> [1,2] -> [1, 2, 3, ] -> [1, 2, 3, 4] -> [1, 2, 3, 4, 5, , , ]
    // v1 ->  v1 ->   v2  ->     v3      ->     v4       ->        v5

    int size_of_vec = vec.size(); // Gets size of vector; no. of entries it has (3 here).
    int capacity_of_vec = vec.capacity(); // Gets size of vector; no. of entries it can store (4 here).

    //To obtain each value of vector through a loop :
    //for (int val : vec) cout << val;

    //Another way to do that (through indexing) :
    // for (int i = 0; i < size_of_vec; i++)
    // {
    //     cout << vec[i]; //Accessing value at a particular index; can also use vec.at(i) here.
    // }

    int front_of_vec = vec.front(); //Accesses front value of vector
    int back_of_vec = vec.back(); //Accesses back value of vector

    vec.erase(vec.begin()+1); // Erases element of index 1; vec.begin() is an iterator just like vec.end().
    vec.erase(vec.begin(), vec.begin()+2); // Erases range of elements from 0th index to 1st index.

    vec.insert(vec.begin(), 1); // Inserts 1 at position 0;
    vec.insert(vec.begin()+1, 2); // Inserts 2 at position 1;
    vec.insert(vec.begin()+2, 3); // Inserts 3 at position 2;

    // vec.empty(); //Checks if vector is empty; false here.
    // vec.clear(); //Clears vector; capacity is remained.
    // vec.empty(); //Checks if vector is empty; true here.

    //Note : vec.begin(), and other iterators, are initialized as :
    vector<int>::iterator it;
    //vector<int>::reverse_iterator itr; //Not needed here, as "auto" automatically determines datatype of variable.

    //To obtain each value of vector (through iterator) :
    // for (it = vec.begin(); it!= vec.end(); it++) 
    // {
    //     cout << *(it) << "\n";
    // }

    // Instead of explicitly mentioning the type of variable, we can use "auto" as a datatype :
    // for (auto itr = vec.begin(); itr!= vec.end(); itr++) 
    // {
    //     cout << *(itr) << "\n";
    // }

    //Note : *(vec.begin()) returns value of first element of vec; 1 here.
    //Note : *(vec.end()) returns a random value [*(vec.end()-1) returns last value of vec; 3 here].
    //Note : *(vec.rbegin()) returns value of last element of vec; 3 here.
    //Note : *(vec.rend()) returns a random value [*(vec.end()-1) returns first value of vec; 1 here].


    /* Lists */

    //Works as a doubly linked list, so access through indexing is not possible.
    //Here, you can push/emplace/pop values from front as well (using push_front/emplace_front/pop_front).

    /* Deque */

    //Works as a dynamic array, so random access is possible.

    /* Pair */

    pair<int, int> p1 = {1, 2};
    pair<char, int> p2 = {'a', 1};

    int first_value_of_p1 = p1.first;
    int second_value_of_p1 = p1.second;

    pair<int, pair<char, int>> p3 = {7, {'c', 4}};

    int first_value_of_p3 = p3.first;
    int second_value_of_p3_first = p3.second.first;
    int second_value_of_p3_second = p3.second.second;

    vector<pair<int, int>> pair_vec = {{1, 2}, {3, 4}, {5, 6}};

    pair_vec.push_back({7, 8});
    pair_vec.emplace_back(9, 10);

    /* Stack */

    //LIFO principle; Last In First Out. (Assume that "1]" means that 1 is at the bottom of stack)
    //Elements are added as : ] -> 1] -> 2,1] -> 0,2,1]
    //Elements are removed as : 0,2,1] -> 2,1] -> 1] -> ]

    stack<int> s;

    s.push(1); //Adds 1 to the top of the stack.
    s.push(2); //Adds 2 to the top of the stack.

    s.emplace(0); //Emplaces 0 to the top of the stack.

    stack<int> s2;
    s2.swap(s); //Swaps the two stacks mentioned.
    s.swap(s2); //Swaps them again, thus retaining their value.

    int size_of_s = s.size(); //Contains size of the stack ('s' here).
    int size_of_s2 = s2.size(); //Contains size of the stack ('s2' here).

    while (!s.empty()) //Loop runs while the stack is not empty.
    {
        int top_of_s = s.top(); //Contains top value of stack.
        s.pop(); //Pops the top value of the stack.
    }

    /* Queue */

    //FIFO principle; First In First Out. (Assume that "1]" means that 1 is at the front of queue)
    //Elements are added as : ] -> 1] -> 2,1] -> 0,2,1]
    //Elements are removed as : 0,2,1] -> 0,2] -> 0] -> ]
    //Other functionalities remain the same as a stack (except that top() is replaced by front() here).

    /* Priority Queue */

    // Same as queue, except the elements are internally sorted in ascending/descending order.

    //To use this, (for ascending order) :
    priority_queue<int> pr_q;

    //For descending order :
    priority_queue<int, vector<int>, greater<int>> pr_q_desc;

    //Here, front value is accessed as top() instead of front().

    //Note : Time complexity in push(), emplace() and pop() will be O(log(n)) for containers that internally sort
    //elements, such as priority_queue, map and set [and O(1) for those who don't].

    /* Map */

    //Used to store key-value pairs (like dictionary in python).
    //Internally sorted in ascending order of their keys.

    //To initialize a map :
    map<string, int> m;

    //To insert/change key-value pair, write :
    m["abc"] = 150;

    //count() shows the number of instances of a key in a map.
    int no_of_abc = m.count("abc");

    //find() tell if a key exists in a map or not. If it doesn't, it returns <map_name>.end() here.
    // if (m.find("abc") != m.end()) cout << "Found";
    // else cout << "Not Found";

    //Note : multimap() is the same as map(), except that keys can be duplicate (insertion is done through 
    //<map_name>.insert({key_name, value_name}) and not <map_name>[<key_name>] = <value_name>).

    //Note : unordered_map() is the same as map(), except that the former does not internally sort the key_value
    //pairs (great for optimization since it uses O(1) time complexity for insertion and deleton of key_value pair).

    /* Set */

    //Similar to map(), except that it stores single values instead of key_value pairs.

    //To initialize a set :
    set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(4);

    //multiset() and unordered_set() are similar to multimap() and unordered_map().

    //lower_bound() : returns the number equal to or immediately larger than the number given.
    int lower_bound_of_set1 = *(set1.lower_bound(2));

    //lower_bound() : returns the number immediately larger than the number given.
    int upper_bound_of_set1 = *(set1.upper_bound(2));

    /* ----------------------------------------------------------------------------------------------------------- */

    /* Sorting Algorithms */

    int arr[5] = {1, 5, 3, 8, 2};
    vector<int> v = {6, 5, 3, 8, 4};

    //For an array, you can sort (in ascending order) using :
    sort(arr, arr + 5);

    //To sort it in descending order :
    sort(arr, arr+5, greater<int>());

    //Similarly, to sort a vector, use (use greater<int>() at the end to sort in descending order):
    sort(v.begin(), v.end());

    //Note : In a vector of pairs, sorting is done (by default) on the first value. It can be changed using
    //"comparators".

    /* Creating a custom comparator */

    //Say, we have to sort pairs based on their second values (and then check based on their first values) :
    vector<pair<int, int>> vec_pairs_to_be_sorted = {{3,1}, {5,2}, {2,2}, {7,1}};
    sort(vec_pairs_to_be_sorted.begin(), vec_pairs_to_be_sorted.end(), comparator);
    //[The function "comparator" is mentioned at the top]

    /* Reversing algorithm (same as sorting algorithm) */

    /* swap(<variable1>, <variable2>) : Swaps the two variables given. */

    /* max(<variable1>, <variable2>) : Returns the max of the two variables given. */
    /* min(<variable1>, <variable2>) : Returns the min of the two variables given. */
    /* max_element(<vector_name>.begin(), <vector_name>.end()) : Returns the max of the vector given. */
    /* min_element(<vector_name>.begin(), <vector_name>.end()) : Returns the min of the vector given. */

    return 0;
}