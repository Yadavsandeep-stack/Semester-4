#include<iostream>
using namespace std;

typedef vector<vector<int>> Matrix;
Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}
void split(const Matrix &A, Matrix &A11, Matrix &A12,
           Matrix &A21, Matrix &A22) {
    int n = A.size();
    int mid = n / 2;

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
        }
    }
}
Matrix combine(const Matrix &C11, const Matrix &C12,
               const Matrix &C21, const Matrix &C22) {
    int mid = C11.size();
    int n = mid * 2;
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    return C;
}
Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = A.size();
    if (n == 1) {
        return Matrix{{A[0][0] * B[0][0]}};
    }
    int mid = n / 2;
    Matrix A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)),
           A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    Matrix B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)),
           B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));
    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);
    Matrix M1 = strassen(add(A11, A22), add(B11, B22));
    Matrix M2 = strassen(add(A21, A22), B11);
    Matrix M3 = strassen(A11, subtract(B12, B22));
    Matrix M4 = strassen(A22, subtract(B21, B11));
    Matrix M5 = strassen(add(A11, A12), B22);
    Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));
    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);
    return combine(C11, C12, C21, C22);
}
void printMatrix(const Matrix &A) {
    for (auto &row : A) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter size (power of 2): ";
    cin >> n;

    Matrix A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    Matrix C = strassen(A, B);

    cout << "Result matrix:\n";
    printMatrix(C);

    return 0;
}





int job(vector<pair<int,int>> vec,int n){
    sort(vec.begin(),vec.end(),[](auto& a,auto& b){
        return a.first>b.first;
    });
    int max = 0;
    for(int i=0;i<n;i++){
        if(vec[i].second>max){
            max  = vec[i].second;
        }
    }
    vector<int> slots(max,0);
    for(int i=0;i<n;i++){
        int j=vec[i].second-1;
        while(j>=0){
            if(slots[j]==0){
                slots[j] = vec[i].first;
                break;
            }
            j--;
        }
    }
    int sum=0;
    for(int i=0;i<max;i++){
        sum+= slots[i];
    }
    return sum;
}

int main(){
    
    int jobs;
    cout<<"Enter number of jobs : ";
    cin>>jobs;
    vector<pair<int,int>> vec(jobs);

    for(int i=0;i<jobs;i++){
        cout<<"Enter "<<i+1<<" job (profit,deadline) : ";
        cin>>vec[i].first>>vec[i].second;
    }
    cout<<"Result : "<<job(vec, jobs)<<endl;
}




struct Point {
    int x, y;
};
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y));
}
bool cmpX(Point a, Point b) {
    return a.x < b.x;
}
bool cmpY(Point a, Point b) {
    return a.y < b.y;
}
double brute(vector<Point>& P, int l, int r) {
    double minD = INT_MAX;
    for(int i = l; i <= r; i++) {
        for(int j = i + 1; j <= r; j++) {
            minD = min(minD, dist(P[i], P[j]));
        }
    }
    return minD;
}
double stripClosest(vector<Point>& strip, double d) {
    sort(strip.begin(), strip.end(), cmpY);
    double minD = d;
    int n = strip.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n &&
            (strip[j].y - strip[i].y) < minD; j++) {
            minD = min(minD, dist(strip[i], strip[j]));
        }
    }
    return minD;
}
double closestUtil(vector<Point>& P, int l, int r) {
    if(r - l <= 3)
        return brute(P, l, r);
    int mid = (l + r) / 2;
    Point midPoint = P[mid];
    double dl = closestUtil(P, l, mid);
    double dr = closestUtil(P, mid + 1, r);
    double d = min(dl, dr);
    vector<Point> strip;
    for(int i = l; i <= r; i++) {
        if(abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);
    }
    
    return min(d, stripClosest(strip, d));
}


double closest(vector<Point>& P) {
    sort(P.begin(), P.end(), cmpX);
    return closestUtil(P, 0, P.size() - 1);
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> P(n);

    for(int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }

    cout << "Minimum Distance: " << closest(P);
}
