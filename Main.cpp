#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;

class stop_watch {
private:
    short hour, minit, second;
    bool running;

public:
    stop_watch();
    void start();
    int reset();
};

stop_watch::stop_watch() {
    hour = 0;
    minit = 0;
    second = 0;
    running = true;
}

int stop_watch :: reset()
{
    hour = 0;
    minit = 0;
    second = 0;
    running = true;
    int p;
    cout<<"If you want to start again then press 1 :: ";
    cin>>p;

    if (p==1)
    {
        start();
    }
    else
    {
        return 0;
    }
    
}

void stop_watch::start() {
    cout<<"Prease any key to stop the stop watch : "<<endl;
    while (running) {
        system("cls");

        // Display the current time in hh:mm:ss
        printf("%02d:%02d:%02d\n", hour, minit, second);

        Sleep(1000);  // Wait for 1 second
        second++;

        if (second == 60) {
            second = 0;
            minit++;
        }

        if (minit == 60) {
            minit = 0;
            hour++;
        }

        if(_kbhit())
        {
            int key = _getch();
            if (key == '0' || key == ' ' )
            running = false;
        }
    }

    cout<<"Stop watch stoped at : "<<hour <<" : "<<minit<<" : "<<second-1<<endl;
}
 
int main() {
    stop_watch st;
    st.start();
    int t=1;
    while(t)
    {
        t = st.reset();
    }
 
    return 0;
}
