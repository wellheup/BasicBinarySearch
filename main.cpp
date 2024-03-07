#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// finds the index of the first occurrence of the target element in the vector
int binarySearch(std::vector<int> arr, int target){
	int l = 0, r = arr.size() - 1;
	while (l+1 <r){
		int mid = l +(r-l)/2;// this instead of (l+r)/2 prevents overflow on large array size
		if (arr[mid] == target) //if you found target, shift window to the left, there might be some duplicates earlier in list
			r = mid;

		else if (arr[mid] < target) //if mid is smaller than target, shift window to the right
			l = mid;

		else //if mid is larger than target, shift window to the left
			r = mid;
	}
	if (arr[l] == target) // in case both l and r are equal to target, return l
		return l;
	if (arr[r] == target)
		return r;

	return -1;
}

std::vector<int> scramble(std::vector<int> arr){
	for (int i = 0; i < arr.size(); i++){
		int j = std::rand() % arr.size();
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	return arr;
}

std::vector<int> mergeSort(std::vector<int> arr){
	if (arr.size() <= 1){
		return arr;
	} 
	int mid = arr.size()/2;
	std::vector<int> left(arr.begin(), arr.begin() + mid);
	std::vector<int> right(arr.begin() + mid, arr.end());
	left = mergeSort(left);
	right = mergeSort(right);
	std::vector<int> result;
	int i = 0, j = 0;
	while (i < left.size() && j < right.size()){
		if (left[i] < right[j]){
			result.push_back(left[i]);
			i++;
		}
		else {
			result.push_back(right[j]);
			j++;
		}
	}
	while (i < left.size()){
		result.push_back(left[i]);
		i++;
	}
	while (j < right.size()){
		result.push_back(right[j]);
		j++;
	}
	return result;
}

std::string stringifyArr(std::vector<int> arr){
	std::string result = "[";
	for (int i = 0; i < arr.size(); i++){
		result = result + std::to_string(arr[i]);
		if(i == arr.size() - 1){
			result = result + "]";
		}
		else {
			result = result + ", ";
		}
	}
	return result;
}

int main() {
  	std::cout << "Scrambles then unscrambles a provided array into ascending order then finds the index of the first occurrence of the target element in the vector" << std::endl;
	std::vector<int> arr = std::vector<int>{1,2,3,4,5,5,5,5,6,7,8,9,10};
	std::cout << "Original Array: " + stringifyArr(arr) << std::endl;
	std::vector<int> scrambledArr = scramble(arr);
	std::cout << "Scrambled Array: " + stringifyArr(scrambledArr) << std::endl;
	std::vector<int> unscrambledArr = mergeSort(scrambledArr);
	std::cout << "Unscrambled Array: " + stringifyArr(unscrambledArr) << std::endl;
	std::cout << std::to_string(binarySearch(unscrambledArr, 5)) + " is the index of the first occurrence of the target element in the vector" << std::endl;
}