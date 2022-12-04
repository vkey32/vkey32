#include <iostream>
using namespace std;

bool **W;
int n, m = 0;
int v, e = 0;
int x, y = 0;
int *vcolor;

bool promising (int i){
    int j = 0;
    while (++j < i){
        if ( W[i][j] && vcolor[i] == vcolor[j] )
            return false;    }
     return true;}

void m_coloring (int i){
    if (promising(i)) {
        if (i+1==n) {
            for (i=1; i<n; i++ )
                cout<<vcolor[i]<<" ";
                cout<<endl;   }
        else{
            for (int color = 1; color <= m; color++){     
                vcolor [i + 1] = color;
                m_coloring(i + 1);     }
        } } }

void initArrays(){
    for( int i = 0; i < n; i++ ){
        W[ i ] = new bool[ n ];
        vcolor[ i ] = 0;
    } }

void fillW(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            W[i][j] = false;  }  } }

void sisi(){
    cout << "Masukkan jumlah jalur : ";
    cin >> e;
    cout << endl << "Masukkan jalur: (kota_x - kota_y)" << endl;

    for( int i = 0; i < e; i++ ) {
        cin >> x >> y;
        W[x][y] = true;
        W[y][x] = true;   } }

 void specialMatrixPrint(){
    cout << endl;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            cout << W[i][j] << " ";   }
        cout << endl;    } }

void pewarnaan(int i){
    m = i;
    m_coloring( 0 ); }

void printKota (string kota[], int size) {
    for(int i = 0; i < size; i++) {
        cout << kota[i] << " ";
    }
    cout << endl;}

void printDerajat (int derajat[], int size) {
    for(int i = 0; i < size; i++) {
        cout << derajat[i] << " ";
    }
    cout << endl;}

int main(){
    cout << "Masukkan jumlah kota : " ;
    cin >> n;
    
    int warna;
    string kota[n] = {"Kudus", "Pati", "Jepara", "Blora", "Rembang"};
    int derajat[n];
    const int size = 5;

    cout << "List Kota : " << endl;
    cout << "0. Kudus " << endl;
    cout << "1. Pati " << endl;
    cout << "2. Jepara " << endl;
    cout << "3. Blora " << endl;
    cout << "4. Rembang \n" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan derajat kota " << i << " : ";
        cin >> derajat[i];
        cout << endl;    
    }

    for (int i = 0; i < size; i++)
    {
        //swap
        if (derajat[i] > derajat[i+1])
        {   
            //kota swap
            swap(kota[i], kota[i-1]);
            //derajat swap
            swap(derajat[i], derajat[i-1]);         
        }
    }
    printKota(kota, size);
    printDerajat(derajat, size);
    cout << endl;
    n += 1;

    W = new bool *[ n ];
    vcolor = new int[ n ];
    initArrays();
    fillW();
    sisi();

    cout << "Masukkan jumlah warna yang ingin digunakan : ";
    cin >> warna;

    cout << endl << "Kemungkinan warna yang dapat terjadi : " << endl;
    pewarnaan( warna ); //warna yang digunakan

    cin >> y;
    return 0;
}


/*
4 pati merah
2 kudus kuning
2 jepara biru
2 rembang kuning
2 blora biru
*/
