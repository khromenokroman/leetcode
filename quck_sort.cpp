#include <iostream>
#include <vector>
#include <list>

int sum_vec(std::vector<int> &arr){
   if(arr.size()==0){
       return 0;
   }
   int sum = arr[arr.size()-1];
   arr.pop_back();
   return sum + sum_vec(arr);
}

int sum_list(std::list<int> &arr){
    if(arr.size()==0){
        return 0;
    }
    int sum = arr.front();
    arr.pop_front();
    return sum + sum_list(arr);
}

int sum2(std::vector<int> const&arr){
    int sum=0;
    for(auto const& item:arr){
        sum+=item;
    }
    return sum;
}

int count_number(std::list<int>&list){
    if(list.size()==0){
        return 0;
    }
    int count=0;
    count += 1;
    list.pop_front();
    return count + count_number(list);
}

int max(std::vector<int> const&arr){
    if (arr.empty()){
        return -1;
    }
    int max=arr[0];
    for (auto const& item:arr){
        if(item>max){
            max = item;
        }
    }
    return max;
}

int main() {
    std::vector<int> arr{-5,1,2,3,4};
    std::cout << "max: " << max(arr) << std::endl;
    std::cout << "sum_vec: " << sum_vec(arr) << std::endl;
    arr.push_back(-5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    std::cout << "sum_vec: " << sum2(arr) << std::endl;
    std::list<int> list{0,1,2,3,4};
    std::cout << "sum_list: " << sum_list(list) << std::endl;
    std::list<int> list2{0,1,2,3,4};
    std::cout << "count_number: " << count_number(list2) << std::endl;
    return 0;}