// SortingC++(Lab3).cpp: определяет точку входа для приложения.
//

#include "SortingC++(Lab3).h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   /* const vector<size_t> vector_lengths = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };

     for (size_t length : vector_lengths) {

         stats selection_random_stats_sum{ 0, 0 };

         stats quick_random_stats_sum{ 0, 0 };

         stats merge_random_stats_sum{ 0, 0 };

         for (int i = 0; i < 100; ++i) {
             vector<int> random_vector = RandomVec<int>(length);

             vector<int> selection_random_vector = random_vector;
             stats selection_random_stats = SelectionSort(selection_random_vector);
             selection_random_stats_sum.comparison_count += selection_random_stats.comparison_count;
             selection_random_stats_sum.copy_count += selection_random_stats.copy_count;

             vector<int> quick_random_vector = random_vector;
             stats quick_random_stats = Quicksort(quick_random_vector, 0, length - 1);
             quick_random_stats_sum.comparison_count += quick_random_stats.comparison_count;
             quick_random_stats_sum.copy_count += quick_random_stats.copy_count;

             vector<int> merge_random_vector = random_vector;
             stats merge_random_stats = merge_sort(merge_random_vector);
             merge_random_stats_sum.comparison_count += merge_random_stats.comparison_count;
             merge_random_stats_sum.copy_count += merge_random_stats.copy_count;
         }

         vector<int> sorted_vector = SortedVec<int>(length);

         vector<int> selection_sorted_vector = sorted_vector;
         stats selection_sorted_stats = SelectionSort(selection_sorted_vector);

         vector<int> quick_sorted_vector = sorted_vector;
         stats quick_sorted_stats = Quicksort(quick_sorted_vector, 0, length - 1);

         vector<int> merge_sorted_vector = sorted_vector;
         stats merge_sorted_stats = merge_sort(merge_sorted_vector);

         vector<int> reverse_sorted_vector = ReverseSortedVec<int>(length);

         vector<int> selection_reverse_sorted_vector = reverse_sorted_vector;
         stats selection_reverse_sorted_stats = SelectionSort(selection_reverse_sorted_vector);

         vector<int> quick_reverse_sorted_vector = reverse_sorted_vector;
         stats quick_reverse_sorted_stats = Quicksort(quick_reverse_sorted_vector, 0, length - 1);

         vector<int> merge_reverse_sorted_vector = reverse_sorted_vector;
         stats merge_reverse_sorted_stats = merge_sort(merge_reverse_sorted_vector);

         stats selection_random_mean_stats{
             selection_random_stats_sum.comparison_count / 100,
             selection_random_stats_sum.copy_count / 100
         };

        stats quick_random_mean_stats{
             quick_random_stats_sum.comparison_count / 100,
             quick_random_stats_sum.copy_count / 100
         };

         stats merge_random_mean_stats{
             merge_random_stats_sum.comparison_count / 100,
             merge_random_stats_sum.copy_count / 100
         };

         ofstream selection_random_stats_file;
         selection_random_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/selection_random_stats.txt", ios::app | ios::out);
         selection_random_stats_file << selection_random_mean_stats;
         selection_random_stats_file.close();

         ofstream quick_random_stats_file;
         quick_random_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/quick_random_stats.txt", ios::app | ios::out);
         quick_random_stats_file << quick_random_mean_stats;
         quick_random_stats_file.close();

         ofstream merge_random_stats_file;
         merge_random_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/merge_random_stats.txt", ios::app | ios::out);
         merge_random_stats_file << merge_random_mean_stats;
         merge_random_stats_file.close();

         ofstream selection_sorted_stats_file;
         selection_sorted_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/selection_sorted_stats.txt", ios::app | ios::out);
         selection_sorted_stats_file << selection_sorted_stats;
         selection_sorted_stats_file.close();

         ofstream quick_sorted_stats_file;
         quick_sorted_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/quick_sorted_stats.txt", ios::app | ios::out);
         quick_sorted_stats_file << quick_sorted_stats;
         quick_sorted_stats_file.close();

         ofstream merge_sorted_stats_file;
         merge_sorted_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/merge_sorted_stats.txt", ios::app | ios::out);
         merge_sorted_stats_file << merge_sorted_stats;
         merge_sorted_stats_file.close();

         ofstream selection_reverse_sorted_stats_file;
         selection_reverse_sorted_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/selection_reverse_sorted_stats.txt", ios::app | ios::out);
         selection_reverse_sorted_stats_file << selection_reverse_sorted_stats;
         selection_reverse_sorted_stats_file.close();
      
         ofstream quick_reverse_sorted_stats_file;
         quick_reverse_sorted_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/quick_reverse_sorted_stats.txt", ios::app | ios::out);
         quick_reverse_sorted_stats_file << quick_reverse_sorted_stats;
         quick_reverse_sorted_stats_file.close();

         ofstream merge_reverse_sorted_stats_file;
         merge_reverse_sorted_stats_file.open("C://Users/Роллсройсилиройсролс/source/repos/SortingC++(Lab3)/merge_reverse_sorted_stats.txt", ios::app | ios::out);
         merge_reverse_sorted_stats_file << merge_reverse_sorted_stats;
         merge_reverse_sorted_stats_file.close();
     }*/

    vector<string> selection_string_vec = { "n", "e", "s", "m", "d", "f", "c" , "v", "a", "r" , "j", "a", "x", "t", "y" , "u", "b", "e" , "q", "k", "l", "g", "b", "r" };
    vector<string> quick_string_vec = { "n", "e", "s", "m", "d", "f", "c" , "v", "a", "r" , "j", "a", "x", "t", "y" , "u", "b", "e" , "q", "k", "l", "g", "b", "r" };
    vector<string> merge_string_vec = { "n", "e", "s", "m", "d", "f", "c" , "v", "a", "r" , "j", "a", "x", "t", "y" , "u", "b", "e" , "q", "k", "l", "g", "b", "r" };
    stats selection_string_stats = SelectionSort(selection_string_vec);
    stats quick_string_stats = Quicksort(quick_string_vec, 0, quick_string_vec.size() - 1);
    /*stats merge_string_stats = merge_sort(merge_string_vec);*/
    cout << selection_string_vec << selection_string_stats << endl;
    cout << quick_string_vec << quick_string_stats << endl;
    /*cout << merge_string_vec << merge_string_stats << endl;*/

    vector<MyClass> v1;
    vector<MyClass> v2;
    vector<MyClass> v3;


    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v1.push_back(rand() % 100);
    }
    cout << v1 << "--------" << endl;
    stats selection_my_stats = SelectionSort(v1);
    cout << v1 << endl << "~~~~~~~~~~~~~~" << endl;


    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v2.push_back(rand() % 100);
    }
    cout << v2 << "--------" << endl;
    stats quick_my_stats = Quicksort(v2, 0, v2.size() - 1);
    cout << v2 << endl << "~~~~~~~~~~~~~~" << endl;


    //srand(static_cast<unsigned int>(time(0)));
    //for (size_t i = 0; i < 50; ++i) {
    //    v3.push_back(rand() % 100);
    //}
    //cout << v3 << "--------" << endl;
    //stats merge_my_stats = merge_sort(v3);
    //cout << v3 << endl << "~~~~~~~~~~~~~~" << endl;
}
