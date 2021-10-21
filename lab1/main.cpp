#include "matrix.h"
#include "cstdlib"
using namespace std;

int main() {
    int n, m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/input.txt");
    fin >> m >> n;
    MATRIX M(m, n);
    fin >> M;
    int kod;
    while (true) {
        M.menu();
        cin >> kod;

        switch (kod) {
            case 1: {
                cout << "pre_inc\n";
                ++M;
                cout << M;
                cout << "post_inc\n";
                M++;
                cout << M;
                cout << "pre_dec\n";
                --M;
                cout << M;
                cout << "post_dec\n";
                M--;
                cout << M;
                cin.get();
                break;
            }
            case 2: {
                cout << "change of rows and of columns\n";
                int a, b;
                cin >> a >> b;
                M.rowscols(a, b,m,n);
                cout << M;
                break;
            }

            case 3: {
                int x, y;
                cout << "finding submatrix\n";
                cout <<"submatrix size \n";
                cin >> x >> y;
                MATRIX G(x, y);
                G = M;
                int c,z;
                cout<<"coordinate of the element with which to select the submatrix\n";
                cin>>z>>c;
                M.submatrix(G, x, y,z,c);
                cout << G;
                break;
            }
            case 4: {
                cout << "Transpose matrix\n";
                M.Transpose();
                cout << M << "\n";
                break;
            }
            case 5:{
                cout << "check matrix types\n";
                M.whyMatrix();
                break;
            }
            case 6:{
                cout<< M;
                break;
            }
            case 7: {
                return 0;
                break;
            }
        }
    }
}
