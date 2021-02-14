#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex semaforo;

void imprimeCaractere(int n, char c){
    semaforo.lock();
    for(int i = 1; i<= n; i++){
        cout << c;
    }
    cout << endl;
    semaforo.unlock();
}

int main()
{
    thread t1(imprimeCaractere, 50, '*');
    thread t2(imprimeCaractere, 50, '$');
    thread t3(imprimeCaractere, 50, '#');
    thread t4(imprimeCaractere, 50, '@');

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
