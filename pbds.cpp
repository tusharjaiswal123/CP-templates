#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;



//1. using it as ordered set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
// find_by_order, order_of_key
// any.erase(val)


//2.using it as ordered multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

// Some points to take care for ordered multiset

1. don't use any.find() // it will always return end
2. lower_bound works like upper_bound
3. upper_bound works like lower bound
4. any.erase(any.find_by_order(any.order_of_key(val))); // use this for deleting