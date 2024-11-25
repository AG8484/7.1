#include <iostream>
//#include "vector.h"
#include "vector.cpp"

using namespace std;

int main() 
{
    try 
    {
        Vector<int> v1;
        cout << "v 1 create (by default constructor): empty =   " << v1.empty() << endl;

        Vector<int> v2(5);
        cout << "v 2 create (size = 5): size=" << v2.size() << endl;

        Vector<int> v3(3, 7);
        cout << "v 3 create (size = 3, default = 7) : ";
        for (size_t i = 0; i < v3.size(); ++i)
        {
            cout << v3[i] << " " ;
        }
        cout << endl;

        for (int i = 1; i <= 10; ++i) 
        {
            v1.pushback(i);
        }
        cout << "v 1 after push back 1 to 10 : ";
        for (size_t i = 0; i < v1.size(); ++i)
        {
            cout << v1[i] << " " ;
        } 
        cout << "\ncapacity of v 1 : " << v1.capacity() << endl;

        Vector<int> v4 = v1;
        cout << "v 4 create (v 1  copy): ";
        for (size_t i = 0; i < v4.size(); ++i) 
        {
            cout << v4[i] << " ";
        }
        cout << endl;

        Vector<int> v5 = move(v4);
        cout << "v 5 create (move from v 4) : ";
        for (size_t i = 0; i < v5.size(); ++i)
        {
            cout << v5[i] << " ";
        } 
        cout << "\nv 4 size after move: " << v4.size() << endl;

        cout << "v 1 front: " << v1.front() << " , back: " << v1.back() << endl;
        cout << "v 1 at(5) : " << v1.at(5) << endl;

        try 
        {
            cout << "attempting v1.at(20): ";
            cout << v1.at(20) << endl;
        } 
        catch (const exception& e) 
        {
            cout << "exception : " << e.what() << endl;
        }

        v1.resize(15);
        cout << "v 1 resize to 15 :    size = " << v1.size() << " , elements : ";
        for (size_t i = 0; i < v1.size(); ++i)
        {
            cout << v1[i] << " ";
        }
        cout << endl;

        v1.popback();
        cout << "v 1 after pop back :      size = " << v1.size() << " , elements: ";
        for (size_t i = 0; i < v1.size(); ++i)
        {
            cout << v1[i] << " ";
        }
        cout << endl;

        v1.clear();
        cout << "v 1 after clear: empty = " << v1.empty() << endl;

        v3 += 42;
        cout << "v3 after += 42: ";
        for (size_t i = 0; i < v3.size(); ++i)
        {
            cout << v3[i] << " ";
        }
        cout << endl;

        v3 += v2;
        cout << "v 3 after += v 2: ";
        for (size_t i = 0; i < v3.size(); ++i) 
        {
            cout << v3[i] << " ";
        }
        cout << endl;

        --v3;
        cout << "pop front : v3 after --v3 : ";
        for (size_t i = 0; i < v3.size(); ++i)
        {
            cout << v3[i] << " ";
        }
        cout << endl;

        v3++;
        cout << "push back 1 : v3 after v3++ : ";
        for (size_t i = 0; i < v3.size(); ++i)
        {
            cout << v3[i] << " ";
        }
        cout << endl;

        ++v3;
        cout << "push front 1 : v3 after ++v3 : ";
        for (size_t i = 0; i < v3.size(); ++i)
        {
            cout << v3[i] << " ";
        }
        cout << endl;

        try 
        {
            Vector<int> emptyVector;
            v1 += emptyVector;
        } 
        catch (const Vector<int>::concatenate_error& e) 
        {
            cout << "concatenate error: " << e.what() << endl;
        }

    } 
    catch (const exception& e) 
    {
        cerr << "exception: " << e.what() << endl;
    }

    return 0;
}
