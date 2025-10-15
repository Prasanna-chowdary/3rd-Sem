#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n)), b(m, vector<int>(n)), sum(m, vector<int>(n));
    
    cout << "Enter first matrix:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    
    cout << "Enter second matrix:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> b[i][j];
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            sum[i][j] = a[i][j] + b[i][j];
    
    cout << "Sum matrix:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
    return 0;
}
