// Jeremy Jefferson

// program to calculate the min, max, mean, median, mode, and if palindrome

#include <iostream>

using namespace std;

void welcome();
void readInput(int list[], int &count);
void maxmin(int list[], int count, int &max, int &min);
double avgArray(int list[], int count);
bool isPalindrome(int list[], int count);
void sort(int list[], int count);
double median(int list[], int count);

int main() {
   int list[50];
   int count = 0;
   int max;
   int min;
   
   welcome();
   readInput(list, count);
   double mean = avgArray(list, count);
   bool palindrome = isPalindrome(list, count);
   
   maxmin(list, count, max, min);
   cout << "Maximum: " << max <<endl;;
   cout << "Minimum: " << min <<endl;;
   cout << "Mean: " << mean << endl;
   cout << "Palindrome: ";
   if (palindrome == 1){
      cout << "True" << endl;
   } else {
      cout << "False" << endl;
   }
   cout << "Median " << median(list, count) << endl;
   return 0;
}

// welcome message
void welcome () {
   cout << "Welcome to my Array Statistics program!" << endl;
}
// this function is called for user to input data 
void readInput(int list[], int &count) {
   cout << "Please enter the values for the array (negative number to end input:)" << endl;
   int input;
   for(int i = 0;i < 20;i++) {
      cin >> input;
      if (input < 0 ) {
         break;
      }
      
      list[i] = input;
      count++;
   }
}
// finds the maximum and minimum of the list
void maxmin(int list[], int count, int &max, int &min) {
   max = list[0];
   min = list[0];
   
   
   for (int i = 1; i < count; i++) {
      int elem = list[i];
      if (max < elem) {
         max = elem;
      }
      if (min > elem) {
         min = elem;
      }
   }
}
// find average of the list 
double avgArray(int list[], int count) {
   double mean = 0;
   int sum = 0;
   int i = 0;
   for (i = 0; i < count; i++) {
      sum += list[i];
   }
   
   mean = sum / count;
   return mean;
}
// see if array is a palindrome return false if not true
bool isPalindrome(int list[], int count) {
   int i = 0;
   int j = count-1;
   
   while (i < j) {
      int left = list[i];
      int right = list[j];
      if (left != right) {
         return false;
      }
      i++;
      j--;
   }
   
   return true;
}
// sort the list uses a temp var to store place of smaller number
void sort (int list[], int count) {
   int min = 0;
   int i;
   int j;
   for (i = 1; i < count - 1; i++) {
      min = i;
      for (j = i + 1; j < count; j++){
         if (list[j] < list[min]) {
            min = j;
         }
      }
      if (min != i) {
         int temp = list[i];
         list[i] = list[min];
         list[min] = temp;
      }
   }
   
}
// find the median of the list 
double median (int list[], int count) {

      sort(list, count);
      if (count % 2 != 0)
         return (double)list[count/2];
      return (double)(list[(count-1)/2] + list[count/2])/2.0;
}
