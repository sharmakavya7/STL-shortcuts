#include <iostream>
//#include<bits.stdc++>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using namespace std;

bool comp(int el1, int el2) {  // if we want to sort in descending if el1 is always before el2, return true else False
    if(el1 <= el2) { //they are already sorted
        return true;
    }
    return false;
}
// arr
// pair<int,int>arr[] = {{1,4},{5,2},{5,9}};
// I want to sort this in such a way that 
// the ele who have 1st ele in pair smaller appears first
// and if 1st is equal then sort according to 2nd and
// keep larger 2nd 
// meaning: o/p = {{1,4},{5,9},{5,2}} agr 1st same h to jiska 2nd bada h usko pehle print kro

bool cmp(pair<int, int>el1, pair<int,int>el2) {
    if(el1.first < el2.first) { //already in correct order
        return true;
    }
    if(el1.first == el2.first) {
        if(el1.second > el2.second) {
            return true;
        }
    }
    return false;
}


int main() {
	
    vector<vector<int>>t(10,(vector<int>(10,0)));

    // sorts the 2D array in decreasing order of their seconds
    // t = [[5,10],[2,5],[4,7],[3,9]]
    // after sorting: [[5,10],[3,9],[4,7],[2,5]]
    sort(t.begin(), t.end(), [](const vector<int>&a, vector<int>&b) {
            return b[1]>a[1];
    });
	
    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i=0; i<n;i++) {
        cin>>arr[i];
    }

    //STL 3

    sort(arr, arr+n);
    sort(arr+1, arr+3); //sorts from 1->3 index
    reverse(arr, arr+n);

    vector<int>vec(5,0);
    for(int i=0; i<n; i++) {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    sort(vec.begin()+1, vec.end()+4); //sorts from 1->3 index [1,4)
    reverse(vec.begin(),vec.end());

    //MAX/MIN element in range i=1 to j=4
    int maxi = INT_MIN;
    for(int k=1; k<=4; k++) {
        if(arr[k] > maxi) {
            maxi = arr[k];
        }
    }
    //STL in-built funtion
    int el = *max_element(arr,arr+n);
    int el = *max_element(vec.begin(),vec.end());
    int el = *min_element(vec.begin(),vec.end());

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum+=arr[i];
    }

    //from perticular funtion to another sum
    //int sum = accumulate(startIterator, edndIterator, initialize sum = 0);
    int sum = accumulate(arr, arr+n, 0);
    int sum = accumulate(vec.begin(), vec.end(), 0);

    //How many times 1 occur in arr
    //x = 1
    //arr[]: [1, 6, 7, 1, 2, 1, 3]
    int cnt = 0;
    int x = 1;
    for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            cnt++;
        }
    }
    cout<<cnt;
    // COMPLEXITY FOR ALL THESE ALGO IS ALWAYS THE SAME WHEN WE PUT A LOOP
    //count(1stIterator, lastIterator, x);
    int cnt = count(arr, arr+n, 1);
    int cnt = count(vec.begin(), vec.end(), 1);

    //arr[]: [1, 2, 5, 1, 2, 4, 4]
    //fimd 1st occurance of 2
    //it is in index 1

    int ind = -1;
    for(int  i=0; i<n; i++) {
        if(arr[i]==x) {
            ind = i;
            break;
        }
    }
    cout<<ind;

    auto it = find(arr, arr+n, 2);
    int ind = it - arr;  //How???? ans below:
    //IMPORTANT
    //returns an iterator pointing to the first instance of it
    //else return end() it is not there
    //   0    1    2    3    4    5
    // 
    //  102  103  104  105  106  107   // address
    //        |
    //        it
    // 'it' is gonna point tot he address, it will retern the address
    // to get the index from the addresses
    // we simply need to subtract begin() from 'it' 
    // 103 -> it; begin()-> 102 ;   *[it - begin() = index]*
    // 103-102 = 1;  //which is our index(answer)
    // REMEMBER: to get the index, we have to do currIterator - firstIterator

    
    auto it = find(vec.begin(), vec.end(),2);
    //int index = it - vec.begin();

    //BINARY SEARCH   (log n)
    // arr[]: [1,5,7,9,10]
    bool res = binary_search(arr, arr+n, 8);
    //it only gives you yes or no
    //if 8 is present->Yes, not present->No
    bool res = binary_search(vec.begin(), vec.end(), 8);


    //LOWER_BOUND FUNCTION  only in sorted arr/vec
    // returns an iteraror pointing to the first  element 
    // which is not less that x
    // arr[]: [1, 5, 7, 7, 8, 10, 10, 11, 11, 12]
    //x = 10;  ans-> 10 (as it is not lesser than 10)
    //x = 6;   ans->7
    //x = 13;  ans-> end()

    auto it = lower_bound(arr, arr+n, x);
    int ind = it - arr;
    auto it = lower_bound(vec.begin(), vec.end(), x);
    //int ind = it - vec.begin();

    //UPPER_BOUND FUNCTION
    // returns an iteraror pointing to the first  element 
    // which is just greater that x
    // arr[]: [1, 5, 7, 7, 8, 10, 10, 11, 11, 12]
    // x = 7;  ans-> 8
    // x = 6;  ans-> 7
    // x = 12; ans->end() iterator
    // x = 15; ans->end() iterator

    auto it = upper_bound(arr, arr+n, x);
    int ind = it - arr;
    auto it = upper_bound(vec.begin(), vec.end(), x);

    //Next Permutation
    string s = "abc";
    // all permutation are as follow:
    // abc, acb, bac, bca, cab, cba //lexicographically sorted
    
    // s = "bca"
    bool res = next_permutation(s.begin(),s.end()); 

    // COMPARATOR
    
    // sort(arr, arr+n); //sorts everything in ascending 
    sort(arr, arr+n, comp);  //sorts everything in descending 

    // Question
    // arr
    // pair<int,int>arr[] = {{1,4},{5,2},{5,9}};
    // I want to sort this in such a way that 
    // the ele who have 1st ele in pair smaller appears first
    // and if 1st is equal then sort according to 2nd and
    // keep larger 2nd 
    // meaning: o/p = {{1,4},{5,9},{5,2}} agr 1st same h to jiska 2nd bada h usko pehle print kro
    sort(arr, arr+3, cmp);  //TC: n(logn)

    // sort a 2D vec:
    vector<vector<int>> vec(n,vector<int>(n,0));
    // element 1: vector<int>el1
    // element 2: vector<int>el2
    // write cmp function




    // STL 2
    // no of unique elements in arr
    // SET (ALL FUNCTIONS ARE LOGn)
    int arr[] = {2, 5, 2, 1, 5};
    set<int>st;          //implementation: RED BLACK TREE
    
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        st.insert(x);  //TC: log(n) 
    }
    // how are values stored in set?
    // 1st ele in set is the SMALLEST element
    // 2nd is the 2nd smallest n so on
    // How to access these values?
    // 1st index: st.begin()   [use iterators]
    
    //erase function:
    //st-> {1,2,5}
    // 1
    st.erase(st.begin()); //o/p: st-> {2,5}
    // 2
    // st.erase(st.begin(),st.begin() + 2); //st-> {}
    // 3
    // st.erase(5);   //this deletes only 5
    // TC: logn
    set<int>st = {1, 5, 7, 8};
    // FIND function  TC: logn
    auto it = st.find(7);  //it points an iterator to 7
    //
    auto it = st.find(9);  //point to st.end()

    st.emplace(6); //same as st.insert(6) but emplace is faster

    set<int>st;
    st.insert(5);
    // print set
    for(auto it = st.begin(); it!=st.end(); it++) {
        cout<<*it<<" ";
    }
    // OR apply for each loop
    for(auto it : st) {
        cout<< it << endl;
    }

    // delete the entire set
    st.erase(st.begin(),st.end());

    unordered_set<int>set;
    st.insert(2);
    st.insert(3);
    st.insert(1);
    // order is not decided 
    // if you get TLE, switch to set
    // avg TC is O(1)
    // worst case TC: O(n)

    // store all the elements, use 
    // multiset (all operation TC: logn)
    multiset<int>ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    // st-> {1,1,2,3,3}
    // every ele is stored in sorted order
    auto it = ms.find(2);
    // fond how many times 2 occurs
    set.count(2);
    ms.clear();
    ms.erase(ms.begin(),ms.end());
    // SC: log n 
    
    // MAP key value  // TC: logn
    // raj -> 27
    // hima -> 31
    // sandy -> 67
    // tank ->89
    map<string,int>mpp;
    // only stores unique keys
    mpp["raj"] = 27;
    mpp["hima"] = 31; 
	mpp["praveer"] = 31;
	mpp["sandeep"] = 67; 
    // stores in an linearly increasing order
	mpp["tank"] = 89; 
	mpp["raj"] = 29; // overwrite krega
	mpp.emplace("raj", 45); // similar to insert but slight quicker
	mpp.erase("raj"); // mpp.erase(key) 
	mpp.erase(mpp.begin()); // mpp.erase(iterator)
	mpp.clear(); // entire map is cleaned up
	// mpp.erase(mpp.begin(), mpp.begin()+2); // cleans up a given range
	// first occurance of raj:
    auto it = mpp.find("raj"); // points to where raj lies 
	auto it = mpp.find("simran"); // points to end since she does not exists 

    if(mpp.empty()) {
		cout << "Yes it is empty"; 
	}
	mpp.count("raj"); // always returns 1 as it stores only 1 
	// instance of raj 

    // pair
    pair<int,int> pr;
	pr.first = 1; 
	pr.second = 10;

     // printing map 
     // auto it me vo pair bna deta h isliye it. use kr skte h
	for(auto it: mpp) { 
		cout << it.first << " " << it.second << endl; 
	}

    // idhar its an iterator isliye we use arrow
    for(auto it = mpp.begin(); it!=mpp.end();it++) {
		cout << it->first << " " << it->second << endl; 
	}
    
    // TC: O(1) in almost all cases
    // worst case O(n)
    unordered_map<int,int>mp;

    // Pair class 
	//pair<int,int> pr = {1,2}; 
	pair< pair<int,int>, int> pr = {{1,2}, 2}; 
    // access 2 of {1,2}
	cout << pr.first.second << endl;
	pair<pair<int,int>, pair<int,int>> pr = {{1,2},{2, 4}};
	cout << pr.first.first; // prints -> 1 
	cout << pr.second.second; // prints -> 4 
 
	vector<pair<int,int>> vec; 
	set<pair<int,int>> st; 
	map< pair<int,int>, int> mpp; 

    multimap<string, int> mpp;
	mpp.emplace("raj", 2); 
	mpp.emplace("raj", 5); 

    // STACK AND QUEUE

    stack<int>st;  // lifo ds 

    st.push(2); 
	st.push(4); 
	st.push(3); 
	st.push(1); 

    cout << st.top() // prints 1
	st.pop(); // deletes the last entered element ie. 1
	cout << st.top(); // prints 3 
	st.pop(); //deletes 3
	cout << st.top(); // prints 4

    bool flag = st.empty(); // returns true if stack is empty
    while(!st.empty()) {
        st.pop();
    }    

    cout<st.size()<<endl; //no of elements in st

    cout<< st.top() <<endl; //throw an error bcz stack is empty
    
    // REMEMBER: always have a check before implementing a check if st.empty

    // QUEUE  fifo 
    // all operations TC: O(1)
    // only deletion takes linear time

    queue<int>q;
    q.push(1);
    q.push(5);
    q.push(3);
    q.push(6);
    // q-> 1 5 3 6
    cout<<q.front(); // proints 1
    q.pop(); // removes 1
    cout<<q.front(); //prints 2

    // PRIORITY QUEUE
    // set -> log n
    // unordere_set -> O(1) nut worst case O(n)
    // PQ -> 
    // stores all in sorted order

    priority_queue<int>pq; //general declaration
    pq.push(1);
    pq.push(5);
    pq.push(2);
    pq.push(6);
    // pq-> 6,5,2,1
    // greatest element will be at the top
    cout<<pq.top()<<endl; // prints 6
    pq.pop();
    
    priority_queue<pair<int,int>>pq;
    pq.push(1,5);
    pq.push(1.6);
    pq.push(1,7);

    // what if i want smallest element at the top?
    // 1st naive technique
    priority_queue<int> pq;
	pq.push(-1); // pq.push(-1 * el); 
	pq.push(-5); 
	pq.push(-2); 
	pq.push(-6); 
 
	cout << -1 * pq.top() << endl; // prints 1

    // 2nd technique
    //min priority queue
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1); 
	pq.push(5); 
	pq.push(2); 
	pq.push(6); 
 
	cout << pq.top() << endl; // prints 1 
    
    // deque
    dequeue<int> dq; // dono taraf se operation can be performed
	// push_front() 
	// push_back() 
	// pop_front() 
	// pop_back()
	// begin, end, rbegin, rend 
	// size 
	// clear
	// empty 
	// at 

    list<int>ls;  // implements doubly linked list
    // push_front() 
	// push_back() 
	// pop_front() 
	// pop_back()
	// begin, end, rbegin, rend 
	// size 
	// clear
	// empty 
	// at 
	// remove -> TC: O(1) 
	ls.push_front(1); 
	ls.push_front(2); 
	ls.push_front(3);
	ls.remove(2); -> // O(1) operation 

    // QUESTION
    // given N elements, print the elements that occurs maximum 
	// number of times 
	// input 
	// 5 
	// 1 3 3 3 2 
 
	// output 
	// 3

	int n;
	cin >> n; 
	map<int,int> mpp;           // TC: O(n*logn)
	int maxi = 0; 
	for(int i = 0;i<n;i++) {    // O(n)
		int x;
		cin >> x;
		mpp[x]++;                 // logn
		if(mpp[x] > mpp[maxi]) {  // mpp[x]->logn; mpp[maxi]->logn
			maxi = x; 
		}
	}
	cout << x << endl; 

	unordered_map<int,int> mpp;  // TC: O(n*1)
	int maxi = 0; 
	for(int i = 0;i<n;i++) {     // O(n)
		int x;
		cin >> x;
		mpp[x]++;                 // O(1)
		if(mpp[x] > mpp[maxi]) {  // mpp[x]->O(1); mpp[maxi]-> O(1)
			maxi = x; 
		}
	}                  // but in worst case(TLE): TC: O(n*n)
	cout << x << endl; // in case of TLE, roll back to map

    // QUESTION(set)
    // given N elements, print all elements in sorted order 
	// input 
	// n = 6 
	/// 6 6 3 2 3 5 
 
	// output 
	// 2 3 3 5 6 6 
 
	int n;
	cin >> n;
	multiset<int> ms;        // TC: O(n*logn)
	for(int i=0;i<n;i++) {   // O(n)
		int x;
		cin >> x; 
		ms.insert(x);        // O(logn)
	}
 
	for(auto it : ms) {
		cout << it << endl; 
	}

}


