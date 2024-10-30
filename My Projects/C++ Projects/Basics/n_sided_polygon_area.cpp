#include <iostream>
using namespace std;

int main(){
    int t;
    cout << "Enter the number of sides of the given polygon : ";
    cin >> t;
    cout << "Please enter the co-ordinates of the vertices of polygon 'in order' (And re-enter the first co-ordinates as the last point).\n\n";
    
    int x[t+1];
    int y[t+1];
    
    for (int i = 0; i < t+1; i++) {
        cout << "x" << i+1 << " : ";
        cin >> x[i];
        
        cout << "y" << i+1 << " : ";
        cin >> y[i];
        
        cout << "\n";
    }
    
    int det = 0;
    
    for (int i = 0; i < t; i++) {
        det += (x[i]*y[i+1]);
        det -= (x[i+1]*y[i]);
    }
    
    cout << "Area enclosed by the polygon is : " << abs(det)*0.5;

    return 0;
}