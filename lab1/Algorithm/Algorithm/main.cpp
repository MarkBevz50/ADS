#include <iostream>
#include <random>
void swap(int& first, int& second);
void BubbleSort(int arr[], size_t size);
void WriteArr(int arr[], size_t size);
void PrintArr(int arr[], size_t size);
void MergeSort(int arr[], int left,  int right);
void Merge(int arr[], int left, int right);
void initializeArr(int arr[], int size);
const int nmax = 1000;
int Count = 1;
int main()
{
	
	std::cout << " Enter array size: ";
	int size;
	std::cin >> size;
	int* arr = new int[size];
	/*std::cout << "\nEnter you array : ";
	WriteArr(arr, size);*/
	initializeArr(arr, size);
	std::cout << "What sorting algorithm you want to use? 1 - Bubble sort; 2 - Merge sort:" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: BubbleSort(arr, size);
		break;
		
	case 2:MergeSort(arr, 0, size - 1);
		break;
	}
			std::cout << "Your sorted Array: ";
			PrintArr(arr, size);
			return 0;
}

void swap(int &first, int &second)
{
	int temp;
	temp = first;
	first = second;
	second = temp;
	
}

void BubbleSort(int arr[], size_t size)
{
	int Counter = 1;
	bool isSorted = false;    
	do
	{
		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = 0; j < size - i - 1; ++j)
			{
				if (arr[j] > arr[j+1])
				{
					
					swap(arr[j], arr[j+1]);
					isSorted = false;
					std::cout << "Step[" << Counter << "]"; PrintArr(arr, size);
					std::cout << std::endl;
					++Counter;
				}
				
			}
			
		}

	} while (isSorted != false);
}

void PrintArr(int arr[], size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
    }
}

void WriteArr(int arr[], size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cin>> arr[i] ;
	}
}
void MergeSort(int arr[], int left, int right)
{
	if (left < right)
		if (right - left == 1)
		{
			if (arr[left] > arr[right])
				swap(arr[left], arr[right]);
		}
	
	else
	{
		MergeSort(arr, left, left + (right - left) / 2);
		MergeSort(arr, left + (right - left) / 2 + 1, right);
		Merge(arr, left, right);
		std::cout << "Step[" << Count << "]";
		PrintArr(arr, right + 1);
		std::cout << std::endl;
		++Count;
	}
}
void Merge(int arr[], int begin, int end)
{
	int i = begin;
	int mid = begin + (end - begin) / 2;
	int rightBord = mid + 1;
	int Counter = 0;
	int finalArray[nmax];

	while (i <= mid && rightBord <= end)
	{
		if (arr[i] <= arr[rightBord])
		{
			finalArray[Counter] = arr[i];
			++i;
		}
		else
		{
			finalArray[Counter] = arr[rightBord];
			++rightBord;
		}
		++Counter;
	}
	while (i <= mid)
	{
		finalArray[Counter] = arr[i];
		++Counter;
		++i;
	}
	while (rightBord <= end)
	{
		finalArray[Counter] = arr[rightBord];
		++Counter;
		++rightBord;
	}
	for (i = 0; i < Counter; ++i)
		arr[begin + i] = finalArray[i];
}
void initializeArr(int arr[], int size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);
	for (int i = 0; i < size; ++i) {
		arr[i] = dist(gen);
	}
}