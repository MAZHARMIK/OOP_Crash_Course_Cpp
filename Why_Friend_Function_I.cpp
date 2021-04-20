#include <bits/stdc++.h>
using namespace std;

/*
    Friend function example-1 to show why it's required
    -When a function needs to access private data members of two or more different/independent classes and do some operation,
    and at the same time the function can't be a member function of any one class because it won't be able to access private
    members of other class, then friend function comes to rescue in this situation.
    Using friend function, a global function can access private members of some class.
*/
class Matrix;

class Vector {
    int vec_[3];
    int n_;
public:
    Vector(int n) : n_(n) {
        for(int i = 0; i<n_; i++)
            vec_[i] = i+1;
    }

    void Clear() {
        for(int i = 0; i<n_; i++)
            vec_[i] = 0;
    }

    void Show() {
        for(int i = 0; i<n_; i++)
            cout << vec_[i] << " ";
        cout << endl;
    }

    friend Vector prod(Matrix *pM, Vector* pV);
};

class Matrix {
    int mat_[3][3];
    int m_, n_;
public:
    Matrix(int m, int n) : m_(m), n_(n) {
        for(int i = 0; i<m_; i++) {
            for(int j = 0; j<n_; j++) {
                mat_[i][j] = i+j;
            }
        }
    }

    void Show() {
        for(int i = 0; i<m_; i++) {
            for(int j = 0; j<n_; j++) {
                cout << mat_[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    friend Vector prod(Matrix *pM, Vector* pV);
};

//Global function
Vector prod(Matrix *pM, Vector* pV) {
    Vector v(pM->m_);
    v.Clear();

    for(int i = 0; i< pM->m_; i++) {
        for(int j = 0; j<pM->n_; j++) {
            v.vec_[i] += pM->mat_[i][j] * pV->vec_[j];
        }
    }

    return v;
}

int main() {
    Vector V(3);
    Matrix M(2, 3);

    Vector PV = prod(&M, &V);

    M.Show();
    V.Show();
    PV.Show();

return 0;
}

