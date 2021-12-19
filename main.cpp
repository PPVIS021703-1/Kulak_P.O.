#include <iostream>
#include <vector>
#include <list>
#include "c.h"
using namespace std;
bool operator > (new_set c1, new_set c2)
{
    return ((c1.x1>c2.x1) || (c1.x1==c2.x1 && c1.x2>c2.x2) || (c1.x1==c2.x1 && c1.x2==c2.x2 && c1.x3>c2.x3));
}

template<class T>
void insertionSort(T first, T second)//сортировка вставками
{
    T i,j; for (i=first+1; i!=second; i++)
    {
        auto key = *i; j=i-1;
        while (j!=(first-1)&&(*j>key))
        {
            *(j+1) = *j; j=j-1;
        }
        *(j+1)=key;
    }
}

template <typename TP, typename T>
void countingSort(T first, T second) //сортировка подсчётом
{
    {
        TP Max = *max_element(first,second);
        TP Min = *min_element(first,second);

        int R=int(Max-Min)+1;
        T it;
        int N=0;
        for(it=first; it!=second; it++)N++;
        vector<int> Cn(R);
        TP res[N];

        for(auto i=first; i!=second; i++)Cn[int(*i-Min)]++;
        for(int i=1; i<Cn.size(); i++)Cn[i]+=Cn[i-1];

        for(int i=N-1; i>=0; i--)
        {
            res[int(Cn[int(*(first+i)-Min)]-1)] = *(first+i);
            Cn[int(*(first+i)-Min)]--;
        }

        for(int i=0; i<N; i++) *(first + i) = res[i];
    }
}

int main()
{
    new_set aa[] = { new_set(11,1.1,'c'),new_set(2,3.34,'x'),new_set(2,3.34,'y') };
    insertionSort(aa, aa+3);

    int a1[] = {33, 22, 11, 77, 66, 55}; insertionSort(a1,a1+3);
    char a2[] = {'d', 'c', 'a'}; countingSort<char>(a2,a2+3);
    double a3[] = {13.66, 2.2, 37.7, 7.77, 6, 5}; countingSort<double>(a3+3,a3+6);

    vector<int> b1 = {14, 22, 3, 7, 66, 25, 1000000000, -23, -266}; insertionSort(b1.begin(),b1.end());
    vector<double> b2 = {11.55, 2, 35, 7.5, 6, 5, 3.14, 2.71}; countingSort<double>(b2.begin(),b2.end());
    vector<char> b3 = {'B','A','D','C'}; countingSort<char>(b3.begin(),b3.end());

    cout << endl << " Сортировка вставками";
    cout << endl << "aa:"; for(auto i : aa) cout << " (" << i.x1 << "," << i.x2 << "," << i.x3 << ")";
    cout << endl << " Сортировка вставками";
    cout << endl << "a1:"; for(auto i : a1) cout << " " << i;
    cout << endl << " Сортировка подсчётом";
    cout << endl << "a2:"; for(auto i : a2) cout << " " << i;
    cout << endl << " Сортировка подсчётом";
    cout << endl << "a3:"; for(auto i : a3) cout << " " << i;
    cout << endl << " Сортировка вставками";
    cout << endl << "b1:"; for(auto i : b1) cout << " " << i;
    cout << endl << " Сортировка подсчётом";
    cout << endl << "b2:"; for(auto i : b2) cout << " " << i;
    cout << endl << " Сортировка подсчётом";
    cout << endl << "b3:"; for(auto i : b3) cout << " " << i;
    cout << endl;
    return 0;
}